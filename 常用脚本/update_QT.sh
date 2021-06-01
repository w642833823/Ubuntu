
####!/bin/bash   ##指定解释器：由哪个程序来执行脚本内容；#!表示幻数

###注意:#!/bin/bash必须写在第一行,否则会被认为是注释
#!/bin/sh
#sudo chmod +x update_QT.sh
#sudo chmod 777 ./update_QT.sh
#sudo sudo ./update_QT.sh
echo "\n"
echo "\n\033[31;35m 安装ffmepg \n \033[0m\n"
sudo add-apt-repository ppa:djcj/hybrid
sudo apt update
sudo apt install ffmpeg
echo "\n"
echo "\033[31;49m apt-get update  检查已安装软件包的可用更新......\033[0m \n"
apt-get update
echo "\n"
echo "\033[31;49m 安装vim......\033[0m \n"
apt-get install vim
echo "\n"

echo "\n 安装Install g++\n"
sudo apt-get install build-essential
sudo apt-get install libfontconfig1

sudo apt-get install mesa-common-dev

sudo apt-get install libglu1-mesa-dev -y
echo "\n error: GL/gl.h: No such file or directory \n"
sudo apt-get install build-essential

sudo apt-get install mesa-common-dev
echo "\033[31;33m 安装CMake  \e[0m \n"
sudo apt-get install cmake

echo "\e[31;34m解决QQ音乐网页版在Ubuntu Firefox下无法播放的问题\033[0m"
sudo apt-get install ubuntu-restricted-extras
echo "\e[31;33m安装 adobe Flash player插件\033[0m"
sudo apt-get install flashplugin-installer

echo "\n"
echo "\033[31;49m apt-get update  检查已安装软件包的可用更新......\033[0m \n"
apt-get update
echo "\n"

echo "\033[31;49m \n apt list --upgradable  可用更新列表...... \033[0m \n"
apt list --upgradable

echo "\033[31;49m \n 按「 Enter 」键继续...... \033[0m "
read anykey

echo "\033[31;49m \n apt-get upgrade -y  安装可用更新......\033[0m \n"
apt-get upgrade -y

echo "\033[31;49m \n apt-get autoremove  卸载不再使用的包......\033[0m \n"
apt-get autoremove

echo "\033[31;49m \n apt-get autoclean cleann 清理系统 ......\033[0m \n"
apt-get autoclean clean
echo "\n"


