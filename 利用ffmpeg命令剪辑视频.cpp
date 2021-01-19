
ffmpeg -ss 00:00:30 -t 600 -i src.mp4  -codec copy out.mp4
这条命令可以从源文件src.mp4中剪切出一个视频片段，并存储成out.mp4

-ss表示  起始时间戳

-t表示    持续时间，单位为秒

-i表示    源文件名字，这里是src.mp4

-codec copy 表示沿用原来的编码格式，out.mp4为目标文件的文件名


#ffmpeg -i test.mp4 %05d.jpg
这条命令可以将test.mp4文件抽帧，抽出来的图片帧在当前目录下，名字为"帧号.jpg",不足5位则补0,如00001.jpg