#!/bin/bash

#输入不同字符完成不同巡检内容

#打印提示符

HINT(){
        read -p "请按回车继续："
}

#查看CPU信息

CPU_INFO(){

        echo

        echo -e "\033[4;31mPrint the CPU info:\033[0m"

        cat /proc/cpuinfo | awk 'BEGIN {FS=":"} /model name/{print "CPU Model:" $2 }'

        cat /proc/cpuinfo | awk 'BEGIN {FS=":"} /cpu MHz/{print "CPU Speed:" $2"MHz"}'

        grep -Eq 'svm|vmx' /proc/cpuinfo && echo "Virtualization: Support" || \

        echo "Virtualization: No Support"

        echo

}

#查看系统负载

LOAD_INFO(){

        echo -e "\033[4;31mPrint the system load:\033[0m"

        uptime | awk 'BEGIN{FS=":"} {print $5}' | awk 'BEGIN{FS=","}\

        {print "Last 1 minutes system load:"$1"\n""Last 5 minutes system load:"$2"\n"\

        "Last 15 minutes system load:"$3}'

echo

}

#查看内存与交换分区信息

MEM_INFO(){

        echo

        echo -e "\033[4;31mPrint the Memory and Swap info:\033[0m"

        free | grep Mem | awk '{print "Mem free: "$5" Bytes"}'

        free | grep Swap | awk '{print "Swap free: "$4" Bytes"}'

        echo

}

#查看磁盘挂载信息

DISK_INFO(){

        echo

        echo -e "\033[4;31mPrint system disk space usage:\033[0m"

        df -h

        echo

}

while true
do
        clear
        echo "------------------------------------------------------"

        echo "1. 查看CPU信息"

        echo "2. 查看系统负载"

        echo "3. 查看内存与交换分区信息"

        echo "4. 查看磁盘挂载信息"

        echo "5. 退出系统"
        echo "-------------------------------------------------------"
        read -p "请选择1-4选项：" U_SELECT
        #通过调用函数名称调用函数
        case $U_SELECT in
                1)
                CPU_INFO
                HINT
                ;;
                2)
                LOAD_INFO
                HINT
                ;;
                3)
                MEM_INFO
                HINT
                ;;
                4)
                DISK_INFO
                HINT
                ;;
                5)
                exit
                ;;
                *)
                read -p "请选择1-4选项，输入回车继续："
                ;;
        esac
done
