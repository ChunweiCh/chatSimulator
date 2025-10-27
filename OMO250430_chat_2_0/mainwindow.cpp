#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->showInfoWin->setFocusPolicy(Qt::NoFocus);
    //Icon size
    ui->listWidget->setIconSize(QSize(40,40));

    this->wt = WriteThread::getInstance();
    this->rt = ReadThread::getInstance();

    memset(this->buf,0,sizeof(this->buf));
    //connecting signal Send2UI showing other user's message
    connect(this->rt,SIGNAL(Send2UI(CHATMSG*)),this,SLOT(showInfoUI(CHATMSG*)));
    connect(ui->listWidget->horizontalScrollBar(),&QScrollBar::sliderMoved,this,&MainWindow::on_horizontalScrollBar_sliderMoved);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUserData(int userName)
{
    this->userName = userName;
}

//ListWidget clicked choosing contect user
void MainWindow::on_listWidget_clicked(const QModelIndex &index)
{
    qDebug() << "Choosing " << index.data() << endl;


}

void MainWindow::showInfoUI(CHATMSG *msg)
{
    if(msg->sendId == this->userName)
    {
        QString sender = "I said: ";
        QString contecter = QString(msg->content);
        sender += contecter;
        qDebug() << "............" << sender << ".........." << endl;

        ui->showInfoWin->append(sender);

    }
    else if(msg->recvId == this->userName)
    {
        QString sender = QString(msg->sendId);
        QString midPos = "said to me: ";
        QString context = QString(msg->content);
        sender += midPos;
        sender+= context;
        ui->showInfoWin->append(sender);
    }
    update();

}
//sending message
void MainWindow::on_pushButton_2_clicked()
{

    const char *arr = ui->listWidget->currentItem()->text().toStdString().c_str();
    QString text = ui->textEdit->document()->toPlainText();

    msg.recvId = atoi(arr);
    qDebug() << "msg,recipient = " << msg.recvId;
    msg.sendId = this->userName;

    qDebug() << "msg.sendId = " << msg.sendId;
    memcpy(msg.content,text.toStdString().c_str(),sizeof(msg.content));
    qDebug() << "msg.content = " << msg.content;

    this->head.bussinessType = 3;
    this->head.bussinessLength = sizeof(this->msg);

    memcpy(this->buf,&(this->head),sizeof(this->head));
    memcpy(this->buf+sizeof(this->head),&(this->msg),sizeof(this->msg));

    this->wt->setData(this->buf,sizeof(this->head)+sizeof(this->msg));

    ui->textEdit->setPlainText("");





}

void MainWindow::on_horizontalScrollBar_sliderMoved(int position)
{

}
