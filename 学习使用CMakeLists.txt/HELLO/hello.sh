#!/bin/bash
#author: sky
#desc 选项 cmake clean
#desc 默认为 make
#desc 先创建build文件夹，之后执行cmake ..;如果没有错误则会执行make,之后回到本目>录并执行
#eg ./mycmake.sh  make ./main
#eg ./mycmake.sh cmake 先cmake 然后make 然后执行
#eg ./mycmake.sh clean 清楚build

if [ $# == 1 ] && [ $1 == "clean" ]; then
        if [ -e build ]; then

               rm -r build
                echo "remove build dir success"
                exit 0
        fi
fi

#不存在则创建且必须转为cmake
if [ ! -e build ]; then
echo "正在创建build目录"

        mkdir build;
#占不执行   $1 = "cmake"
fi
#进入创建的build目录中
echo "正在进入build目录"

cd build
echo "以经进入build目录中"
$1 = "cmake .."
#存在一个参数并且值为cmake
if [ $# -eq 1 ] && [ $1 == "cmake" ]; then
echo "开始执行cmake .."

        cmake ..
fi
#检测make是否执行完成
if [ $? ]; then
echo "检测make执行情况"
        make && cd .. &&./main || exit 1
fi