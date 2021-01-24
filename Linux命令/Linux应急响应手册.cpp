Linux应急响应手册
admin2020-9-4 07:2866人围观Linux相关
一个企业的信息安全建设,最基本的无非是要做好三件事:第一件是事前的安全基线，从源头尽可能保证新上线系统的安全性；第二件是建立事中的监控能力，各种多维度的入侵检测和防御，做到有针对性、及时的救火；第三件是做好事后的应急响应能力，让应急的时间成本更短，溯源和根因分析的能力更强。可见在企业信息安全建设中,应急响应是很关键的一个环节。基本上每个安全从业者都经历过安全应急响应，有些没有专职安全人员的企业，应急响应一般落在运维或研发的身上。本文从实战出发，归纳总结在Linux环境下，当服务器遭受入侵时的常用的应急响应流程和方法。      业界有个应急响应参考模型，叫做PDCERF方法，它把应急响应体系分为六个阶段来处理，这六个阶段分别是准备(Perparation)、检测(Detection)、遏制(Containment)、根除(Eradication)、恢复(Recovery)、跟踪(Follow-up)。方法论的东西，看看就好，其实我们做的，也基本都是根据这几个步骤来的。应急响应讲求的是快、准、稳。在最短的时间内定位安全问题，排查安全问题，保障业务系统的稳定性和安全性。

0x00 安全审计命令

last：查看系统的成功登录、关机、重启等情况；这个命令就是将/var/log/wtmp文件格式化输出。

lastb：查看登录失败的情况；这个命令就是将/var/log/btmp文件格式化输出。

lastlog：查看用户上一次的登录情况；这个命令就是将/var/log/lastlog文件格式化输出。

who：查看当前登录系统的情况；这个命令就是将/var/log/utmp文件格式化输出。

w：与who命令一致。

grep 'Accepted' /var/log/secure | awk '{print $11}' | sort | uniq -c | sort -nr    查看登录成功信息

grep 'Failed' /var/log/secure | awk '{print $11}' | sort | uniq -c | sort -nr  查看登录失败信息


0x01 日志和history查看

cat /var/log/secure

cat /var/log/messages

cat /var/log/maillog

默认的history输出格式不便于查看,可以做一下输出格式的定制化,以下给出一个很简单的格式参考:


编辑 /etc/bashrcHISTFILESIZE=10000     //定义保存命令的记录总数HISTSIZE=5000              //定义history命令输出的记录总数HISTTIMEFORMAT='%F %T' //定义时间显示格式export HISTTIMEFORMAT    //作为history的时间变量

0x02 用户查看

less /etc/passwd：查看是否有新增用户

grep :0 /etc/passwd：查看是否有特权用户

ll  -l /etc/passwd：查看敏感文件最后修改时间

awk -F: '$3==0 {print $5}' /etc/passwd：查看是否存在特权用户

awk -F: 'length($2)==0 {print $1}' /etc/shadow：查看是否存在空口令用户


0x03 进程查看

ps aux：查看进程

lsof -p pid：检查可疑进程

检查隐藏进程

            ps -ef|awk ‘{print }’|sort -n|uniq >1

            ls /porc |sort -n|uniq >2

            diff 1 2

0x04.  检查网络

netstat -antlp | grep ESTABLISHED 查看已建立的网络连接账中是否存在异常

netstat -antlp | grep LISTEN           查看已监听端口中是否存在异常

ip link | grep PROMISC          正常网卡不该在promisc模式，可能存在sniffer

lsof –i

arp –a 查看arp记录是否正常


0x05 检查文件

md5sum 文件名        md5校验  

find / -uid 0 -perm -4000 -o -perm -2000 -print      查找具有setUID（-perm -4000）或者具有setGID（-perm -2000）权限的命令

rpm -qf /bin/ls：检查文件的完整性（还有其它/bin目录下的文件）

find ./ -mtime 0 -name "*.jsp"            //查找24h内被修改的jsp文件

find ./ -mtime -7 -name "*.jsp"           //查找7天内被修改的jsp文件

重点关注一下 /tmp、/var/tmp、/dev/shm目录,这些目录下所有用户具备可读可写可执行权限.


0x06 检查后门&rootkit

crontab  -l

cat /etc/crontab

ls /etc/cron.*

ls /var/spool/cron/


注：一般用户级别的crontab，位于/var/spool/cron下；系统级别的crontab，位于/etc/crontab；另外还有：/etc/cron.hourly、 /etc/cron.daily、/etc/cron.weekly、/etc/cron.monthly、/etc/anacrontab 等周期性执行脚本的目录。


cat /etc/rc.d/rc.local

ls /etc/rc.d

ls /etc/rc3.d

cat /etc/inittab

vim $HOME/.ssh/authorized_keys  查看ssh链接文件

lsmod     检查内核模块

chkconfig --list 检查自启服务


0x07 webshell&rookit检测

webshell检测：shellpub    http://www.shellpub.com/

rookit检测：rkhunter         http://rkhunter.sourceforge.net/

rookit检测：chkrootkit       http://www.chkrootkit.org/


0x08. other

 iptraf      观察UDP包是否大量发包，如果是，可能被安装后门

查看ssh后门


①对比ssh版本信息  ssh -V②查看ssh配置文件是否被篡改以及/usr/sbin/sshd时间：stat /usr/sbin/sshd③strings查看/usr/sbin/sshd 看是否有可疑的邮箱信息④利用strace找出sshd后门,以下给个示例：有些做的比较好的sshd后门会将账户密码记录到文件中,可以通过strace进行跟踪判断。
首先确认sshd服务的pid, ps aux|grep sshd用strace跟踪pid为83815的sshd进行: strace -o aa -ff -p 83815
会生成以下strace输出文件
grep这些strace输出文件,过滤错误信息和/dev/null信息,以及denied信息,查找以读写模式(WR)打开的信息,如果有异常,会很容易辨别出异常文件.grep open aa* | grep -v -e No -e null -e denied| grep WR
