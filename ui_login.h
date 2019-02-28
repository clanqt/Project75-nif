/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created: Thu Jan 31 08:07:21 2019
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QGroupBox *groupBox;
    QLabel *label_logo;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_pwd;
    QLabel *label_user_details;
    QPushButton *pushButton_froget_password;
    QLabel *label;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(320, 240);
        groupBox = new QGroupBox(Login);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 320, 240));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 249, 249);"));
        groupBox->setFlat(false);
        label_logo = new QLabel(groupBox);
        label_logo->setObjectName(QString::fromUtf8("label_logo"));
        label_logo->setGeometry(QRect(0, 0, 320, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label_logo->setFont(font);
        label_logo->setStyleSheet(QString::fromUtf8(""));
        label_logo->setScaledContents(true);
        label_logo->setAlignment(Qt::AlignCenter);
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 70, 300, 129));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        lineEdit_pwd = new QLineEdit(gridLayoutWidget);
        lineEdit_pwd->setObjectName(QString::fromUtf8("lineEdit_pwd"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        lineEdit_pwd->setFont(font2);
        lineEdit_pwd->setMaxLength(4);
        lineEdit_pwd->setEchoMode(QLineEdit::Password);
        lineEdit_pwd->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_pwd, 1, 0, 1, 1);

        label_user_details = new QLabel(gridLayoutWidget);
        label_user_details->setObjectName(QString::fromUtf8("label_user_details"));
        label_user_details->setFont(font1);
        label_user_details->setStyleSheet(QString::fromUtf8("color: rgb(177, 19, 66);"));
        label_user_details->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_user_details, 2, 0, 1, 1);

        pushButton_froget_password = new QPushButton(groupBox);
        pushButton_froget_password->setObjectName(QString::fromUtf8("pushButton_froget_password"));
        pushButton_froget_password->setGeometry(QRect(120, 199, 190, 20));
        QFont font3;
        font3.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font3.setPointSize(11);
        font3.setBold(true);
        font3.setUnderline(true);
        font3.setWeight(75);
        pushButton_froget_password->setFont(font3);
        pushButton_froget_password->setStyleSheet(QString::fromUtf8("color: rgb(85, 85, 255);"));
        pushButton_froget_password->setAutoDefault(true);
        pushButton_froget_password->setDefault(true);
        pushButton_froget_password->setFlat(true);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(230, 50, 90, 20));
        label->setFont(font2);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        QWidget::setTabOrder(lineEdit_pwd, pushButton_froget_password);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label_logo->setText(QApplication::translate("Login", "NIF", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Login", "Enter 4digit Pin:", 0, QApplication::UnicodeUTF8));
        label_user_details->setText(QApplication::translate("Login", "U_Name:Yaswant\n"
"Desg  :User\n"
"Mobile:9750034594", 0, QApplication::UnicodeUTF8));
        pushButton_froget_password->setText(QApplication::translate("Login", "F4 - Forget Password", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Login", "V1.0.1", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
