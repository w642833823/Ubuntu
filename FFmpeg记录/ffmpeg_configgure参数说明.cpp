

root@web ffmpeg]# ./configure --help
Usage: configure [options]
Options: [defaults in brackets after descriptions]

Standard options: 基本选项参数
--help                   显示此帮助信息|print this message
--log[=FILE|yes|no]      记录测试并输出到config.err文件|log tests and output to FILE [config.err]
--prefix=PREFIX          安装程序到指定目录（默认/usr/local）|install in PREFIX [/usr/local]
--libdir=DIR             安装库到指定目录（默认prefix/lib）|install libs in DIR [PREFIX/lib]
--shlibdir=DIR           指定共享库路径（默认prefix/lib）|install shared libs in DIR [PREFIX/lib]
--incdir=DIR             指定includes路径（默认prefix/include/ffmpeg）|install includes in DIR[PREFIX/include/ffmpeg]
--mandir=DIR             指定man page路径（默认prefix/man）install man page in DIR [PREFIX/man]
--enable-mp3lame         启用mp3编码libmp3lame（默认关闭）enable MP3 encoding via libmp3lame[default=no]
--enable-libogg          启用ogg支持libogg（默认关闭）enable Ogg support via libogg [default=no]
--enable-vorbis          启用Vorbis支持libvorbis（默认关闭）enable Vorbis support via libvorbis [default=no]
--enable-faad            启用faad支持libfaad（默认关闭）enable FAAD support via libfaad [default=no]
--enable-faadbin         启用faad运行时链接支持（默认关闭）build FAAD support with runtime linking[default=no]
--enable-faac            启用faac支持libfaac（默认关闭）enable FAAC support via libfaac [default=no]
--enable-libgsm          启用GSM支持libgsm（默认关闭）enable GSM support via libgsm [default=no]
--enable-xvid            启用xvid支持xvidcore（默认关闭）enable XviD support via xvidcore [default=no]
--enable-x264            启用H.264编码（默认关闭）enable H.264 encoding via x264 [default=no]
--enable-mingw32         启用MinGW本地/交叉win环境编译|enable MinGW native/cross Windows compile
--enable-mingwce         启用MinGW本地/交叉winCE环境编译enable MinGW native/cross WinCE compile
--enable-a52             启用A52支持（默认关闭）enable GPLed A52 support [default=no]
--enable-a52bin          启用运行时打开liba52.so.0（默认关闭）open liba52.so.0 at runtime [default=no]
--enable-dts             启用DTS支持（默认关闭）enable GPLed DTS support [default=no]
--enable-pp              启用后加工支持（默认关闭）enable GPLed postprocessing support [default=no]
--enable-static          构建静态库（默认启用）build static libraries [default=yes]
--disable-static         禁止构建静态库（默认关闭）do not build static libraries [default=no]
--enable-shared          构建共享库（默认关闭）build shared libraries [default=no]
--disable-shared         禁止构建共享库（默认启用）do not build shared libraries [default=yes]
--enable-amr_nb          启用amr_nb float音频编解码器|enable amr_nb float audio codec
--enable-amr_nb-fixed    启用fixed amr_nb codec | use fixed point for amr-nb codec
--enable-amr_wb          启用amr_wb float音频编解码器|enable amr_wb float audio codec
--enable-amr_if2         启用amr_wb IF2音频编解码器|enable amr_wb IF2 audio codec
--enable-sunmlib         启用Sun medialib（默认关闭） | use Sun medialib [default=no]
--enable-pthreads        启用pthreads（多线程）（默认关闭）use pthreads [default=no]
--enable-dc1394          启用libdc1394、libraw1394抓取IIDC-1394（默认关闭）enable IIDC-1394 grabbing using libdc1394 and libraw1394 [default=no]
--enable-swscaler        启用计数器支持？（默认关闭）software scaler support [default=no]
--enable-avisynth        允许读取AVISynth脚本本件（默认关闭）allow reading AVISynth script files [default=no]
--enable-gpl             允许使用GPL（默认关闭）allow use of GPL code, the resulting libav* and ffmpeg will be under GPL [default=no]

Advanced options (experts only): 高级选项参数（供专业人员使用）
--source-path=PATH       源码的路径（当前为/root/flv/ffmpeg）| path to source code [/root/flv/ffmpeg]
--cross-prefix=PREFIX    为编译工具指定路径 | use PREFIX for compilation tools []
--cross-compile          假定使用了交叉编译 | assume a cross-compiler is used
--cc=CC                  指定使用何种C编译器（默认gcc）use C compiler CC [gcc]
--make=MAKE              使用特定的make | use specified make [make]
--extra-cflags=ECFLAGS   添加ECFLAGS到CFLAGS | add ECFLAGS to CFLAGS []
--extra-ldflags=ELDFLAGS 添加ELDFLAGS到LDFLAGS（默认-Wl，--as-needed）| add ELDFLAGS to LDFLAGS [ -Wl,--as-needed]
--extra-libs=ELIBS       添加ELIBS | add ELIBS []
--build-suffix=SUFFIX    为专用程序添加后缀 | suffix for application specific build []
--arch=ARCH              选择机器架构（默认x86）select architecture [x86]
--cpu=CPU                选用最低的cpu（影响指令的选择，可以在老CPU上出错） | selects the minimum cpu required (affects instruction selection, may crash on older CPUs)
--powerpc-perf-enable    启用PPC上面的性能报告（需要启用PMC）enable performance report on PPC
                           (requires enabling PMC)
--disable-mmx            禁用MMX | disable MMX usage
--disable-armv5te        禁用armv5te | disable armv5te usage
--disable-iwmmxt         禁用iwmmxt | disable iwmmxt usage
--disable-altivec        禁用AltiVec | disable AltiVec usage
--disable-audio-oss      禁用OSS音频支持（默认启用）disable OSS audio support [default=no]
--disable-audio-beos     禁用BeOS音频支持（默认启用）disable BeOS audio support [default=no]
--disable-v4l            禁用video4linux提取（默认启用）disable video4linux grabbing [default=no]
--disable-v4l2           禁用video4linux2提取（默认启用）disable video4linux2 grabbing [default=no]
--disable-bktr           禁用bktr视频提取（默认启用）disable bktr video grabbing [default=no]
--disable-dv1394         禁用DV1394提取（默认启用）disable DV1394 grabbing [default=no]
--disable-network        禁用网络支持（默认支持）disable network support [default=no]
--disable-ipv6           禁用ipv6支持（默认支持）disable ipv6 support [default=no]
--disable-zlib           禁用zlib（默认支持）disable zlib [default=no]
--disable-simple_idct    禁用simple IDCT例程（默认启用）disable simple IDCT routines [default=no]
--disable-vhook          禁用video hooking支持 | disable video hooking support
--enable-gprof           enable profiling with gprof [no]
--disable-debug          禁用调试符号 | disable debugging symbols
--disable-opts           禁用编译器最优化 | disable compiler optimizations
--disable-mpegaudio-hp   启用更快的解码MPEG音频（但精确度较低）（默认禁用）faster (but less accurate) MPEG audio decoding [default=no]
--disable-protocols      禁用 I/O 协议支持（默认启用）disable I/O protocols support [default=no]
--disable-ffserver       禁用生成ffserver | disable ffserver build
--disable-ffplay         禁用生成ffplay | disable ffplay build
--enable-small           启用优化文件尺寸大小（牺牲速度）optimize for size instead of speed
--enable-memalign-hack   启用模拟内存排列，由内存调试器干涉？ | emulate memalign, interferes with memory debuggers
--disable-strip          禁用剥离可执行程序和共享库 | disable stripping of executables and shared libraries
--disable-encoder=NAME   禁用XX编码器 | disables encoder NAME
--enable-encoder=NAME    启用XX编码器 | enables encoder NAME
--disable-decoder=NAME   禁用XX解码器 | disables decoder NAME
--enable-decoder=NAME    启用XX解码器 | enables decoder NAME
--disable-encoders       禁用所有编码器 | disables all encoders
--disable-decoders       禁用所有解码器 | disables all decoders
--disable-muxer=NAME     禁用XX混音器 | disables muxer NAME
--enable-muxer=NAME      启用XX混音器 | enables muxer NAME
--disable-muxers         禁用所有混音器 | disables all muxers
--disable-demuxer=NAME   禁用XX解轨器 | disables demuxer NAME
--enable-demuxer=NAME    启用XX解轨器 | enables demuxer NAME
--disable-demuxers       禁用所有解轨器 | disables all demuxers
--enable-parser=NAME     启用XX剖析器 | enables parser NAME
--disable-parser=NAME    禁用XX剖析器 | disables parser NAME
--disable-parsers        禁用所有剖析器 | disables all parsers

