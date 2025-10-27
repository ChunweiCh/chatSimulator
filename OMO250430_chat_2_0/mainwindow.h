#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "readthread.h"
#include "writethread.h"
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setUserData(int userName);

private slots:
    void on_listWidget_clicked(const QModelIndex &index);
    
    void on_pushButton_2_clicked();

    void on_horizontalScrollBar_sliderMoved(int position);

private:
    Ui::MainWindow *ui;

    //Thread
    WriteThread * wt;
    ReadThread *rt;
    CHATMSG msg;
    HEAD head;
    char buf[500];
    int userName;
public slots:
    void showInfoUI(CHATMSG *msg);



};

#endif // MAINWINDOW_H
