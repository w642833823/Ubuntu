#!/bin/bash
ip=192.168.1.
j=0
for i in `seq 10 12`
do
ping -c 3 $ip$i &> /dev/null
if [ $? -eq 0 ];then
echo 在线的主机有：$ip$i
else
let j++
echo $ip$i >> /tmp/ip.txt
date >> /tmp/ip.txt
fi
done
echo 不在线的主机台数有 $j


