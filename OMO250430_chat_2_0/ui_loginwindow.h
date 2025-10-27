/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginWindow
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLineEdit *userIdEdit;
    QLineEdit *userPwdEdit;

    void setupUi(QWidget *loginWindow)
    {
        if (loginWindow->objectName().isEmpty())
            loginWindow->setObjectName(QStringLiteral("loginWindow"));
        loginWindow->resize(400, 300);
        label = new QLabel(loginWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 100, 67, 17));
        label_2 = new QLabel(loginWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 170, 67, 17));
        pushButton = new QPushButton(loginWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 240, 89, 25));
        pushButton_2 = new QPushButton(loginWindow);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(140, 240, 89, 25));
        pushButton_3 = new QPushButton(loginWindow);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(250, 240, 89, 25));
        userIdEdit = new QLineEdit(loginWindow);
        userIdEdit->setObjectName(QStringLiteral("userIdEdit"));
        userIdEdit->setGeometry(QRect(100, 100, 211, 31));
        userPwdEdit = new QLineEdit(loginWindow);
        userPwdEdit->setObjectName(QStringLiteral("userPwdEdit"));
        userPwdEdit->setGeometry(QRect(100, 170, 211, 25));

        retranslateUi(loginWindow);

        QMetaObject::connectSlotsByName(loginWindow);
    } // setupUi

    void retranslateUi(QWidget *loginWindow)
    {
        loginWindow->setWindowTitle(QApplication::translate("loginWindow", "loginWin", Q_NULLPTR));
        label->setText(QApplication::translate("loginWindow", "\350\264\246 \345\217\267", Q_NULLPTR));
        label_2->setText(QApplication::translate("loginWindow", "\345\257\206 \347\240\201", Q_NULLPTR));
        pushButton->setText(QApplication::translate("loginWindow", "\346\263\250 \345\206\214", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("loginWindow", "\347\231\273 \345\275\225", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("loginWindow", "\350\277\224 \345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class loginWindow: public Ui_loginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
