重点注意X86和X64系统间的区别[x64的不能在x86中运行]


Ubuntu 18.04 下使用git
在终端下使用
处于编辑时vi
新建文本
vi 文件名.txt

#进入编辑模式
shift+s或者a  退出编辑模式 esc
#保存并退出(输入法必须处在英文模式下才有用)
shift+:wq

下载Git项目上的代码项目 git clone +项目地址
git clone https://github.com/具体项目地址


在终端下直接显示文本文档内容
#  cat 文本.cpp
查看文件内容:

#查看boot分区信息和其他分区内存大小
df -h /boot

#查看目前系统中安装的内核镜像
dpkg --get-selections |grep linux-image
#卸载内核镜像
 sudo apt-get remove linux-image-4.8.0-56-generic

#对文件名重命名
mv 123.txt 546.txt
#移动文件到指定目录
mv 123.txt /home/具体位置

# sudo su -                               切换到root权限（与su有区别）

# shutdown -h now  或者 halt         关机
# shutdown -r now            重启
快捷启动命令行方式
Ctrl+Alt+t
移出软件remove
1、移除libdpkg-perl这个软件：

# sudo apt-get remove libdpkg-perl

2、再安装libdpkg-perl：

# sudo apt-get install libdpkg-perl

3、再安装build-essential就可以正常安装了：

#sudo apt-get install build-essential

#关机
halt
//更新源
1. sudo apt-get update
//更新已安装的软件包
2. sudo apt-get upgrade
//系统sources.list的位置
cd /etc/apt
查看版本代码
sudo lsb_release -a
Linux下zip文件密码破解Fcrackzip
sudo apt-get install fcrackzip
//查看程序包的安装路径
which git

常用Linux命令:
打开文本文件
sudo gedit /etc/apt/sources.list
安装QT
apt install qtcreator
删除音乐播放器remove
sudo apt remove --auto-remove deadbeef
卸载全景照片拼接器remove
sudo apt-get remove--auto-hugin hugin-tools
第一次编译，出错
cannot find -lGL
需安装
sudo apt-get install libgl1 -mesa-dev
1，非常有用的清理命令：
sudo apt-get autoclean --清理旧版本的软件缓存 OK(已经卸载掉的软件包)
sudo apt-get clean--清理所有软件缓存 OK(电脑上存储的安装包)
sudo apt-get autoremove--删除系统不再使用的孤立软件 OK
(已经卸载了，但是一些只有它依赖而别的软件包都不需要的软件包)

卸载QT5程序
#sudo apt-get remove qt5-default qtcreator 程序名
#卸载QT4
sudo apt-get autoremove --purge libqt4-[a-z]*
创建文件夹
#sudo mkdir /usr/local/java
删除文件夹
#sudo rmdir /usr/local/java
复制文件
cp 文件名 目的位置
#cp jdk-8u25-linux-x64.tar.gz /usr/local/java
复制文件夹
cp 文件夹名 目的位置
#cp -r jdk   /home/usr/local/java
解压文件1
#sudo tar xvf jdk-8u25-linux-x64.tar.gz
解压文件2-ZIP
unzip  gffd.zip
删除文件
#sudo rm jdk-8u25-linux-x64.tar.gz
删除非空目录
#sudo rm -rf java
安装G++
#sudo apt-get install g++
安装软件
sudo apt-get install unrar
卸载程序
sudo apt-get remove unrar

查找文件位置
sudo find   / -name libpulse.so
进入指定目录位置
cd '/home/hzw/user/local/lib/hadoop-1.2.1'
安装QQ
sudo apt-get install wine
##重点安装C++编译器，调试器，make程序等开发工具
sudo apt-get install build-essential libgl1-mesa-dev
定位libGL库的位置
locate libGL.so
打开终端，使用下面的命令安装JRE :

sudo apt-get install default-jre
环境变量
sudo gedit /etc/environment
查看Linux是32位还是64
getconf LONG_BIT
//ubuntu 应用程序默认安装位置
/usr/share/applicatio
快捷键开启终端
ctrl+alt+t
清屏命令
快捷键 ctrl  +l

安装Root
sudo apt install root-system-bin
安装QT
sudo apt-get install qtcreator
//设置QT环境变量
sudo su
sudo su gedit /etc/profile

文件和目录:

# cd '/home '                      进入 '/home' 目录
# cd ..                                返回上一级目录
# cd ../..                             返回上两级目录
# cd -                                 返回上次所在目录
# cp file1 file2                    将file1复制为file2
# cp -a dir1 dir2                 复制一个目录
# cp -a /tmp/dir1 .              复制一个目录到当前工作目录（.代表当前目录）
# ls                                    查看目录中的文件
# ls -a                                显示隐藏文件
# ls -l                                 显示详细信息
# ls -lrt                               按时间显示文件（l表示详细列表，r表示反向排序，t表示按时间排序）

# pwd                                显示当前所在路径

# mkdir dir1                       创建 'dir1' 目录
# mkdir dir1 dir2                同时创建两个目录
# mkdir -p /tmp/dir1/dir2    创建一个目录树
# mv dir1 dir2                    移动/重命名一个目录
# rm -f file1                        删除 'file1'
# rm -rf dir1                       删除 'dir1' 目录及其子目录内容


文本处理:


查找:

# find / -name file1                                                 从 '/' 开始进入根文件系统查找文件和目录



安装gcc
sudo apt-get install gcc 8.1
yum工具:

网络:


查看本地语言设置
locale
其他:


//安装录制GIF
sudo apt-get install byzanz
//录制命令
byzanz-record -d 50 -x 0 -y 0 -w 800 -h 505 ~/x.gif 
//查看窗口尺寸
xwininfo