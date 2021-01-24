QMake笔记2
原创 Prosa Qt君 
我们使用QtCreator创建一个工程时，项目文件默认会创建以下代码，它们究竟是什么呢？能有什么用？

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
  上面代码的意思是，当部署项目(make install)时，如果是qnx平台则将编译输出文件复制到/tmp/$${TARGET}/bin目录下。如果不是，则再次判断，如果是unix平台集但并不是andorid平台时则将编译输出文件复制到/opt/$${TARGET}/bin目录下。

  该段代码是否可以删除？一般情况下可以删除，君君平时都是删除的。

相关
qnx是X86平台上的嵌入式实时操作系统之一。
QMake的unix:!android语句一般指的是arm平台。
QMake的INSTALLS变量描述：
https://doc.qt.io/qt-5/qmake-variable-reference.html#installs