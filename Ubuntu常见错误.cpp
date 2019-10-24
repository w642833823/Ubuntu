



#检测到系统程序出现问题的提示框，解决方法
打开并修改一下
sudo nano /etc/default/apport
enabled =0  将这个enabled设为0

#解决应双系统下扩展分区后启动位置被改变而无法启动之解决方法

#error: unknown filesystem
#grub rescue >_

#因为我的电脑是Ubuntu的，开机用的是grub引导，而grub就放在Ubuntu里的/boot/grub下。由于我多分出了一个区，导致grub找不到原先的Ubuntu所在分区，自然就找不到/boot/grub了，因此解决这个问题很简单，只要把grub和/boot/grub对应上就可以了。


第一步输入ls
grub rescue > ls
第二步输入 set
grub rescue > set
输出如下:
(hd0)    (hd0,msdos10)  (hd0,msdos9)  (hd0,msdos8)  (hd0,msdos7)  (hd0,msdos6)  (hd0,msdos5)  (hd0,msdos4)  (hd0,msdos3)  (hd0,msdos2)  (hd0,msdos1) 

cmdpath=(hd0)
frefix=(hd0,modos7)
root=hd0,msdos7

以上为原先位置，要修改一下（因为我们新增分区一个）

开始修改如下:
grub rescue > set root=hd0,msdos8

#其中/grub在不同系统里可能有所不同（/root/grub）
grub rescue > set frefix=(hd0,msdos8)/grub

grub rescue > insmod normal

grub rescue > normal

现在就可以正常进入系统了