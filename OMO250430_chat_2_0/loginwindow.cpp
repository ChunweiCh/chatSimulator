#include "loginwindow.h"
#include "ui_loginwindow.h"





USER users[3] ={{1001,"123456"},
               {1002,"123456"},
               {1003,"123456"}
                      };

QList<USER> userList;


loginWindow::loginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loginWindow)
{
    ui->setupUi(this);

    for(int i=0; i <3 ; i++)
    {
        userList.append(users[i]);
    }

    this->sc = SocketConnect::getInstance();
    this->sc->CreateConnect();
    this->rt = ReadThread::getInstance();
    this->wt = WriteThread::getInstance();

    this->rt->setSocketFd(this->sc->getSocketFd());
    this->wt->setSocketFd(this->sc->getSocketFd());

    this->rt->start();
    this->wt->start();


    connect(this->rt,SIGNAL(Send2SigninWidget(int)),this,SLOT(alreadyLogin(int)),Qt::QueuedConnection);
    memset(this->buf,0,sizeof(this->buf));



}

loginWindow::~loginWindow()
{
    delete ui;
}
//login
void loginWindow::on_pushButton_2_clicked()
{
    QString userId = ui->userIdEdit->text();
    QString userPwd = ui->userPwdEdit->text();


    bool loginSuccess = false;

    QList<USER>::iterator it;
    for(it = userList.begin(); it != userList.end();++it)
    {
        if(userId == QString::number(it->name) && userPwd == it->pass )
        {
            loginSuccess = true;
            break;
        }
    }

    if(loginSuccess)
    {


        user.name = atoi(userId.toStdString().c_str());
        memset(user.pass,0,sizeof (user.pass));
        memcpy(user.pass,userPwd.toStdString().c_str(),userPwd.size());

        this->pro.bussinessType = 1;
        this->pro.bussinessLength = sizeof(this->user);

        memset(this->buf,0,sizeof(this->buf));
        memcpy(this->buf,&(this->pro),sizeof(this->pro));
        memcpy(this->buf+sizeof(this->pro),&(this->user),sizeof(this->user));


        this->wt->setData(this->buf,sizeof(this->pro)+sizeof(this->user));




    }
    else
    {
        QMessageBox::information(this,"Login Failed","UserId or Password wrong ! try again");
    }


}

//return
void loginWindow::on_pushButton_3_clicked()
{
    QMessageBox exitSystamMsgBox;
    exitSystamMsgBox.setText("Ready to exit the System.");
    exitSystamMsgBox.setInformativeText("Do you want quit the Chat2.0 System?");
    exitSystamMsgBox.setStandardButtons(QMessageBox::Yes| QMessageBox::Cancel);
    exitSystamMsgBox.setDefaultButton(QMessageBox::Yes);
    int ret = exitSystamMsgBox.exec();
    switch(ret)
    {
        case QMessageBox::Yes :
            {this->sc->Close();


                exit(0);
             break;}

        case QMessageBox::Cancel:
            exitSystamMsgBox.close();
            break;
        default:
            break;
    }


}

void loginWindow::alreadyLogin(int flag)
{
    qDebug() << "alreadyLogin flag = " << flag;
    if(flag == 1)
    {
        QMessageBox::information(this,"Login Successful !","Welcome, " + ui->userIdEdit->text() +"!");

        this->mainWin = new MainWindow();
        this->mainWin->setUserData(user.name);


        this->hide();
        mainWin->show();

    }
    else
    {
        QMessageBox::information(this,"Login failed","Already login, please use other accoount");
    }
}
