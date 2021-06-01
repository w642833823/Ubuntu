Ubuntu QT for Android完整搭建过程


#这句不可少
 export PATH="/home/w642833823/Qt5.14.2/Tools/QtCreator/bin:$PATH"
 export PATH="/home/w642833823/Qt5.14.2/5.14.2/gcc_64/bin:$PATH"


在~/.bashrc中增加以下环境变量：
//在/usr/local/下存放Android所需文件并设置环境变量
export JAVA_HOME=/usr/local/android/jdk1.8.0_92
export CLASSPATH=.:$JAVA_HOME/lib:$JAVA_HOME/jre/lib
export PATH=$PATH:$JAVA_HOME/bin:$JAVA_HOME/jre/bin

NDK_PATH=/usr/local/android/android-ndk-r12b
export PATH=$PATH:$NDK_PATH

export SDK_HOME=/usr/local/android/android-sdk
export PATH=$PATH:${SDK_HOME}/tools:${SDK_HOME}/platform-tools
六、安装ANT
export ANT_HOME=/usr/local/android/apache-ant-1.9.7
export PATH=$PATH:${ANT_HOME}/bin

