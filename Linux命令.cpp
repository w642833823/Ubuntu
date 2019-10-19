重点注意X86和X64系统间的区别[x64的不能在x86中运行]


Ubuntu 18.04 下使用git
在终端下使用
下载Git项目上的代码项目 git clone +项目地址
git clone https://github.com/具体项目地址


在终端下直接显示文本文档内容
#  cat 文本.cpp

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

# cd /home                        进入 '/home' 目录
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
查看文件内容:

# cat file1                          从第一个字节开始正向查看文件的内容
# head -2 file1                   查看一个文件的前两行
# more file1                       查看一个长文件的内容
# tac file1                          从最后一行开始反向查看一个文件的内容
# tail -3 file1                      查看一个文件的最后三行

文本处理:

# grep str /tmp/test            在文件 '/tmp/test' 中查找 "str"
# grep ^str /tmp/test           在文件 '/tmp/test' 中查找以 "str" 开始的行
# grep [0-9] /tmp/test         查找 '/tmp/test' 文件中所有包含数字的行
# grep str -r /tmp/*             在目录 '/tmp' 及其子目录中查找 "str"
# diff file1 file2                   找出两个文件的不同处
# sdiff file1 file2                 以对比的方式显示两个文件的不同
查找:

# find / -name file1                                                 从 '/' 开始进入根文件系统查找文件和目录
# find / -user user1                                                查找属于用户 'user1' 的文件和目录
# find /home/user1 -name \*.bin                            在目录 '/ home/user1' 中查找以 '.bin' 结尾的文件
# find /usr/bin -type f -atime +100                         查找在过去100天内未被使用过的执行文件
# find /usr/bin -type f -mtime -10                           查找在10天内被创建或者修改过的文件
# locate \*.ps                                                         寻找以 '.ps' 结尾的文件，先运行 'updatedb' 命令
# find -name '*.[ch]' | xargs grep -E 'expr'              在当前目录及其子目录所有.c和.h文件中查找 'expr'
# find -type f -print0 | xargs -r0 grep -F 'expr'        在当前目录及其子目录的常规文件中查找 'expr'
# find -maxdepth 1 -type f | xargs grep -F 'expr'    在当前目录中查找 'expr'
压缩和解压:

# bzip2 file1                                   压缩 file1
# bunzip2 file1.bz2                        解压 file1.bz2
# gzip file1                                     压缩 file1
# gzip -9 file1                                最大程度压缩 file1
# gunzip file1.gz                            解压 file1.gz
# tar -cvf archive.tar file1               把file1打包成 archive.tar
（-c: 建立压缩档案；-v: 显示所有过程；-f: 使用档案名字，是必须的，是最后一个参数）
# tar -cvf archive.tar file1 dir1        把 file1，dir1 打包成 archive.tar
# tar -tf archive.tar                         显示一个包中的内容
# tar -xvf archive.tar                      释放一个包
# tar -xvf archive.tar -C /tmp         把压缩包释放到 /tmp目录下
# zip file1.zip file1                          创建一个zip格式的压缩包
# zip -r file1.zip file1 dir1               把文件和目录压缩成一个zip格式的压缩包
# unzip file1.zip                             解压一个zip格式的压缩包到当前目录
# unzip test.zip -d /tmp/                 解压一个zip格式的压缩包到 /tmp 目录
安装gcc
sudo apt-get install gcc 8.1
yum工具:

网络:

# ifconfig eth0                                                                       显示一个以太网卡的配置
# ifconfig eth0 192.168.1.1 netmask 255.255.255.0            配置网卡的IP地址
# ifdown eth0                                                                        禁用 'eth0' 网络设备
# ifup eth0                                                                            启用 'eth0' 网络设备
# iwconfig eth1                                                                     显示一个无线网卡的配置
# iwlist scan                                                                         显示无线网络
# ip addr show                                                                     显示网卡的IP地址

查看本地语言设置
locale
其他:


# top                                  罗列使用CPU资源最多的linux任务 （输入q退出）
# pstree                             以树状图显示程序
# man ping                        查看参考手册（例如ping 命令）
# passwd                          修改密码
# df -h                               显示磁盘的使用情况
# cal -3                             显示前一个月，当前月以及下一个月的月历
# cal 10 1988                   显示指定月，年的月历
# date --date '1970-01-01 UTC 1427888888 seconds'   把一相对于1970-01-01 00:00的秒数转换成时间
//安装录制GIF
sudo apt-get install byzanz
//录制命令
byzanz-record -d 50 -x 0 -y 0 -w 800 -h 505 ~/x.gif 
//查看窗口尺寸
xwininfo


