/********************************************************************************
** Form generated from reading UI file 'process_selection.ui'
**
** Created: Thu Jan 31 08:07:21 2019
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESS_SELECTION_H
#define UI_PROCESS_SELECTION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Process_Selection
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_purchase;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_payment;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_menu;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *Process_Selection)
    {
        if (Process_Selection->objectName().isEmpty())
            Process_Selection->setObjectName(QString::fromUtf8("Process_Selection"));
        Process_Selection->resize(320, 220);
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        Process_Selection->setFont(font);
        groupBox = new QGroupBox(Process_Selection);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 320, 220));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 320, 25));
        label->setAlignment(Qt::AlignCenter);
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 30, 300, 180));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_purchase = new QPushButton(gridLayoutWidget);
        pushButton_purchase->setObjectName(QString::fromUtf8("pushButton_purchase"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_purchase->setFont(font1);
        pushButton_purchase->setFocusPolicy(Qt::StrongFocus);
        pushButton_purchase->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_purchase->setAutoDefault(true);

        gridLayout->addWidget(pushButton_purchase, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        pushButton_payment = new QPushButton(gridLayoutWidget);
        pushButton_payment->setObjectName(QString::fromUtf8("pushButton_payment"));
        pushButton_payment->setFont(font1);
        pushButton_payment->setFocusPolicy(Qt::StrongFocus);
        pushButton_payment->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_payment->setAutoDefault(true);

        gridLayout->addWidget(pushButton_payment, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_menu = new QPushButton(gridLayoutWidget);
        pushButton_menu->setObjectName(QString::fromUtf8("pushButton_menu"));
        pushButton_menu->setFont(font);
        pushButton_menu->setFocusPolicy(Qt::NoFocus);
        pushButton_menu->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_menu->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_menu);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 3);


        retranslateUi(Process_Selection);

        QMetaObject::connectSlotsByName(Process_Selection);
    } // setupUi

    void retranslateUi(QWidget *Process_Selection)
    {
        Process_Selection->setWindowTitle(QApplication::translate("Process_Selection", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("Process_Selection", "Process Selection", 0, QApplication::UnicodeUTF8));
        pushButton_purchase->setText(QApplication::translate("Process_Selection", "   Purchase   ", 0, QApplication::UnicodeUTF8));
        pushButton_payment->setText(QApplication::translate("Process_Selection", "Payment", 0, QApplication::UnicodeUTF8));
        pushButton_menu->setText(QApplication::translate("Process_Selection", "F1-Menu", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Process_Selection: public Ui_Process_Selection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESS_SELECTION_H
