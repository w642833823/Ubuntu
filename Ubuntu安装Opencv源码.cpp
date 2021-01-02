1、cmake安装，这里我用的是cmake3.15，在安装cmake之前可以先尝试看下cmake版本,输入命令，如果要安装高版本的cmake，请务必卸载低版本的cmake，不然安装会报错。

//查看版本
cmake --version
//卸载低版本cmake
sudo apt-get autoremove cmake
//下载cmake
wget https://cmake.org/files/v3.15/cmake-3.15.5.tar.gz
//解压
tar xzvf cmake-3.15.5.tar.gz
//安装gcc等程序包(安装过则忽略)
yum install gcc-c++

cd cmake-3.15.5
./bootstrap
gmake
make install
//查看cmake版本
cmake --version

2、opencv安装
opencv3.3.0下载链接：http://opencv.org/releases.html
linux命令行输入以下命令安装：
//安装必要的库，如果出现版本较高的保存，则需要降低版本参考链接：https://blog.csdn.net/qq_41904635/article/details/89305472
sudo apt-get install build-essential
sudo apt-get install libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
sudo apt-get install libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev
//安装opencv
sudo ant-get install unzip
unzip opencv-3.3.0.zip
cd opencv-3.3.0.zip
mkdir opencv-build
cd opencv-build
cmake ../
make
make install