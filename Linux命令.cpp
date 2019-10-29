重点注意X86和X64系统间的区别[x64的不能在x86中运行]

//更新源
1. sudo apt-get update
//更新已安装的软件包
2. sudo apt-get upgrade

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
打开终端，使用下面的命令安装JRE :

sudo apt-get install default-jre
#设置环境变量
sudo vi /etc/profile
使环境变量立马生效
source /etc/profile
查看环境变量是否已经生效

查看Linux是32位还是64
getconf LONG_BIT
//ubuntu 应用程序默认安装位置
/usr/share/applicatio
快捷键开启终端
ctrl+alt+t
清屏命令
快捷键 ctrl  +l
#查看目前系统中安装的内核镜像
dpkg --get-selections |grep linux-image
#卸载内核镜像
 sudo apt-get remove linux-image-4.8.0-56-generic

#对文件名重命名
mv 123.txt 546.txt
#移动文件到指定目录
mv 123.txt /home/具体位置
#移动文件到上一级目录
mv 123.txt '../'

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

查看版本代码
sudo lsb_release -a
Linux下zip文件密码破解Fcrackzip
sudo apt-get install fcrackzip
//查看程序包的安装路径1
which git
#查找动态库位置2
locate libGL
#查找安装包的位置3
find  /usr -name libGL
常用Linux命令:
打开文本文件
sudo gedit /etc/apt/sources.list
安装QT
apt install qtcreator
删除音乐播放器remove
sudo apt remove --auto-remove deadbeef
sudo apt remove rpm
卸载全景照片拼接器remove
sudo apt-get remove--auto-hugin hugin-tools
第一次编译，出错
cannot find -lGL
需安装
sudo apt-get install libgl1 -mesa-dev
1，非常有用的清理命令：
sudo apt-get autoclean --清理旧版本的软件缓存 OK(已经卸载掉的软件包)
sudo apt-get clean--清理所有软件缓存 OK(电脑上存储的安装包)
sudo apt autoremove   卸载不需要的软件

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

# pwd                                显示当前所在路径




文本处理:


查找:

# find / -name file1                                                 从 '/' 开始进入根文件系统查找文件和目录
查找安装包的位置
whereis git



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