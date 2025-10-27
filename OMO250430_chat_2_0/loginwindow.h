#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include "mainwindow.h"
#include <stdio.h>
#include <QList>
#include <QString>
#include <iostream>

#include <QMessageBox>
#include "writethread.h"
#include "readthread.h"
#include "protocol.h"
#include "socketconnect.h"
#include <iostream>
using namespace std;
namespace Ui {
class loginWindow;
}

class loginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit loginWindow(QWidget *parent = nullptr);
    ~loginWindow();



private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();



private:
    Ui::loginWindow *ui;
    MainWindow *mainWin;
    SocketConnect *sc;
    ReadThread *rt;
    WriteThread *wt;
    HEAD pro;
    USER user;
    char buf[500];

public slots:
    void alreadyLogin(int flag);


};

#endif // LOGINWINDOW_H
