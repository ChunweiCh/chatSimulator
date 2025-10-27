#include "mainwindow.h"
#include <QApplication>
#include "loginwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    loginWindow l;
    l.show();
    return a.exec();
}
