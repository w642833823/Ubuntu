
第十一章:ffmpeg和QT开发播放器之项目移植到Ubuntu
kuensan 2018-05-06 22:58:05 745 收藏 1
分类专栏： ffmpeg和QT开发播放器学习笔记 ffmpeg和QT开发播放器学习笔记 文章标签： ffmpeg
版权

写在前面：  
    将前面十章节的代码移植到linux中，注意，这里是移植到ubuntu中，之后我还会想办法移植到开发板中去，不过还是有点难度就是了。移植好的代码路径：https://download.csdn.net/download/tainjau/10396395
1、下载安装QT5.8
       在http://ffmpeg.club/qt_download.html中，使用百度云下载，文件大小700M，要提前下，要不然最近百度网盘速度不咋地，得等好一阵子。
                                       
2、下载编译ffmpeg

        第一步：还是在老师提供的网址http://ffmpeg.club/ffmpeg_download.html下载FFmpeg源码，这里我下载的是3.4.1版本的。将其拷贝进ubuntu中，使用tar -jxvf ffmpeg-3.4.1.tar.bz2解压。
        第二步：安装编译依赖环境

    sudo apt-get update
    sudo apt-get -y install autoconf automake build-essential \
    libass-dev libfreetype6-dev libsdl2-dev libtheora-dev \
    libtool libva-dev libvdpau-dev libvorbis-dev libxcb1-dev \
    libxcb-shm0-dev libxcb-xfixes0-dev pkg-config texinfo zlib1g-dev
    sudo apt-get install yasm		//这个是编译源码所需要的工具

       如果有出现安装不了的，就使用sudo aptitude install libsdl2-dev

       注：虚拟机里面最好还是记得先快照一下，以免出现问题。
       第三步安装可选依赖库

       X264 安装

       sudo apt-get install libx264-dev

       注：如果选择编译要添加 --enable-gpl --enable-libx264
       如果安装失败可以选择源码安装
       wget http://download.videolan.org/pub/x264/snapshots/last_x264.tar.bz2
       tar xjvf last_x264.tar.bz2
       cd x264-snapshot*
       PATH="$HOME/bin:$PATH" ./configure --prefix="$HOME/ffmpeg_build" --bindir="$HOME/bin" --enable-static -- disable-opencl
       PATH="$HOME/bin:$PATH" make
       make install

       AAC安装
       sudo apt-get install libfdk-aac-dev
       如果选择编译添加 --enable-libfdk-aac
       如果加了 --enable-gpl  需要加 --enable-nonfree

       MP3
       sudo apt-get install libmp3lame-dev
       如果选择编译添加 --enable-libmp3lame

       opus
       sudo apt-get install libopus-dev
       如果选择编译添加 --enable-libopus
       VPX  VP8 Video Encoding Guide

       sudo apt-get install libvpx-dev
       如果选择编译添加 --enable-libvpx

       第四步编译为静态库
       在ffmpeg源码中，通过执行命令./configure生成makefile
       ./configure --enable-shared --prefix=/usr/local/ffmpeg 
       其中 --enable-shared 表示编译为动态库， --prefix 表示安装的路径
       然后执行make -j4
       make install

       编译完成后就可以看到 /usr/local/ffmpeg 目录中有头文件和动态链接库文件。如果为了项目编译运行方

便，可以直接把动态链接库复制到 /usr/lib 目录下，这样运行就不用指定库路径了。

       编译项目时候要注意，库路径要设置到 /usr/lib  防止有老版本冲突，很多软件安装的时候会把 ffmpeg 安装

进去，比如安装 opencv 也会把 ffmpeg 安装进去，有可能造成版本冲突。
       之后将整个工程放在linux中，使用QT creadt去打开.pro文件，并查看pro文件，这里我对pro文件进行了初步修改，以后缺少啥就添加啥进去。

    TEMPLATE = app
     
    #如果是win32平台下
    win32{
    TARGET = Xplay
    DESTDIR = ../bin
    QT += core multimedia widgets gui
    CONFIG += debug console
    DEFINES += WIN64 QT_DLL QT_MULTIMEDIA_LIB QT_WIDGETS_LIB
    INCLUDEPATH += ./GeneratedFiles \
        . \
        ./GeneratedFiles/Debug \
        ../../lib \
        ../../include
    LIBS += -L"../../lib"
    DEPENDPATH += .
    MOC_DIR += ./GeneratedFiles/debug
    OBJECTS_DIR += debug
    UI_DIR += ./GeneratedFiles
    RCC_DIR += ./GeneratedFiles
    include(Xplay.pri)
    win32:RC_FILE = Xplay.rc
    }
    #如果是linux平台下
    linux{
    message("linux");
    LIBS += -L/usr/local/ffmpeg/lib -lavcodec -lavutil -lresam
     
    INCLUDEPATH += /usr/local/ffmpeg/include    \
                    ./GeneratedFiles
     
    include(Xplay.pri)
    }
    QT += core multimedia widgets gui
    DEFINES += QT_MULTIMEDIA_LIB QT_WIDGETS_LIB

       接下来的错误是锁有问题，因为linux和win编程还是有区别的，所以要稍作更改。添加上头文件#include <QMutex>
       追加lib库的内容LIBS += -L/usr/local/ffmpeg/lib -lavcodec -lavutil -lswresample \
       编译完成后，还是没办法正常使用，按老师的分析是因为win和linux的音频处理是有所不同的，在win中，音频播放时候只要缓冲有数据，就会播放，而linux有的版本则需要音频满了才会播放。

       下载完成之后，直接将文件放入ubuntu后，在命令行中执行./qt-opensource-linux-x64-5.8.0.run 即可，然后直接下一步下一步安装。

