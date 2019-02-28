/********************************************************************************
** Form generated from reading UI file 'void_last_bill.ui'
**
** Created: Thu Jan 31 08:07:21 2019
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VOID_LAST_BILL_H
#define UI_VOID_LAST_BILL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Void_Last_BIll
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QPushButton *pushButton_home_back;
    QPushButton *pushButton_payment;
    QPushButton *pushButton_purchase;

    void setupUi(QWidget *Void_Last_BIll)
    {
        if (Void_Last_BIll->objectName().isEmpty())
            Void_Last_BIll->setObjectName(QString::fromUtf8("Void_Last_BIll"));
        Void_Last_BIll->resize(320, 220);
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        Void_Last_BIll->setFont(font);
        groupBox = new QGroupBox(Void_Last_BIll);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 320, 220));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 320, 20));
        QFont font1;
        font1.setPointSize(14);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        pushButton_home_back = new QPushButton(Void_Last_BIll);
        pushButton_home_back->setObjectName(QString::fromUtf8("pushButton_home_back"));
        pushButton_home_back->setGeometry(QRect(10, 180, 88, 27));
        pushButton_home_back->setAutoDefault(true);
        pushButton_payment = new QPushButton(Void_Last_BIll);
        pushButton_payment->setObjectName(QString::fromUtf8("pushButton_payment"));
        pushButton_payment->setGeometry(QRect(80, 70, 160, 27));
        pushButton_payment->setStyleSheet(QString::fromUtf8("QPushButton:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        pushButton_payment->setAutoDefault(true);
        pushButton_purchase = new QPushButton(Void_Last_BIll);
        pushButton_purchase->setObjectName(QString::fromUtf8("pushButton_purchase"));
        pushButton_purchase->setGeometry(QRect(80, 37, 160, 27));
        pushButton_purchase->setStyleSheet(QString::fromUtf8("QPushButton:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        pushButton_purchase->setAutoDefault(true);

        retranslateUi(Void_Last_BIll);

        QMetaObject::connectSlotsByName(Void_Last_BIll);
    } // setupUi

    void retranslateUi(QWidget *Void_Last_BIll)
    {
        Void_Last_BIll->setWindowTitle(QApplication::translate("Void_Last_BIll", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("Void_Last_BIll", "Void Bill", 0, QApplication::UnicodeUTF8));
        pushButton_home_back->setText(QApplication::translate("Void_Last_BIll", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_payment->setText(QApplication::translate("Void_Last_BIll", "Payment -00001", 0, QApplication::UnicodeUTF8));
        pushButton_purchase->setText(QApplication::translate("Void_Last_BIll", "Purchase-00001", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Void_Last_BIll: public Ui_Void_Last_BIll {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOID_LAST_BILL_H
