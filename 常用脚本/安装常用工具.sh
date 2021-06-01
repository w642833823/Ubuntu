
####!/bin/bash   ##指定解释器：由哪个程序来执行脚本内容；#!表示幻数

###注意:#!/bin/bash必须写在第一行,否则会被认为是注释
#!/bin/sh
#sudo chmod +x update_QT.sh
#sudo chmod 777 ./update_QT.sh
#sudo sudo ./update_QT.sh
echo "\n"
echo "\n\033[31;35m 安装Wireshark \n \033[0m\n"
sudo add-apt-repository universe
sudo apt update
sudo apt install wireshark
echo "\n"
echo "\033[31;49m apt-get update  检查已安装软件包的可用更新......\033[0m \n"
apt-get update
echo "\n"

echo "\n\033[31;35m 添加cmake 官方的key \n \033[0m\n"
wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null | gpg --dearmor - | sudo tee /etc/apt/trusted.gpg.d/kitware.gpg >/dev/null
echo "\n\033[31;35m 添加主仓库 \n \033[0m\n"
sudo apt-add-repository 'deb https://apt.kitware.com/ubuntu/ focal main'
sudo apt-get update

echo "\n\033[31;35m 添加候选版本仓库(可选) \n \033[0m\n"
sudo apt-add-repository 'deb https://apt.kitware.com/ubuntu/ focal-rc main'
sudo apt-get update


echo "\n\033[31;35m 自动更新仓库的key(可选,推荐!!) \n \033[0m\n"
sudo apt-get install kitware-archive-keyring
sudo rm /etc/apt/trusted.gpg.d/kitware.gpg

echo "\n\033[31;35m 现在开始安装CMake \n \033[0m\n"
sudo apt install cmake
echo "\n"
echo "\033[31;49m apt-get update  检查已安装软件包的可用更新......\033[0m \n"
apt-get update
echo "\n"

echo "\n"
echo "\n\033[31;35m安装文本对比软件 \n \033[0m\n"
sudo apt update
sudo apt-get install meld
echo "\n"

