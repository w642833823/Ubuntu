//使用nmap工具扫描局域网下的IP地址
sudo apt-get install nmap
进行扫描
用nmap对局域网扫描一遍，然后查看arp缓存表就可以知道局域内ip对应的mac了。nmap比较强大也可以直接扫描mac地址和端口。执行扫描之后就可以 cat /proc/net/arp查看arp缓存表了。

进行ping扫描，打印出对扫描做出响应的主机：　　

$ nmap -sP 192.168.1.0/24　　


仅列出指定网络上的每台主机，不发送任何报文到目标主机：　

$ nmap -sL 192.168.1.0/24　　（要打印到txt中 >扫描结果.txt）


探测目标主机开放的端口，可以指定一个以逗号分隔的端口列表(如-PS 22，23，25，80)：　　

$ nmap -PS 192.168.1.234　　


使用UDP ping探测主机：

$ nmap -PU 192.168.1.0/24　　


使用频率最高的扫描选项（SYN扫描,又称为半开放扫描），它不打开一个完全的TCP连接，执行得很快：　

$ nmap -sS 192.168.1.0/24