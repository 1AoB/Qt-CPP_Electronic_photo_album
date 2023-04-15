#include "widget.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setFixedSize(841,610);

    //设计样式
    QFile file("F:\\QT_code\\1study\\flushbonading_Curriculum_design\\study/style.qss");
    file.open(QFile::ReadOnly);
    QByteArray arr = file.readAll();
    a.setStyleSheet(arr);//a指的是整个应用程序,给a设置样式就是给全部设置
    file.close();

    w.show();
    return a.exec();
}
