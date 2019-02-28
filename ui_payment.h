/********************************************************************************
** Form generated from reading UI file 'payment.ui'
**
** Created: Thu Jan 31 08:07:21 2019
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAYMENT_H
#define UI_PAYMENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Payment
{
public:
    QGroupBox *groupBox_home;
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_Husk;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_labour;
    QPushButton *pushButton_other;
    QPushButton *pushButton_Diesel;
    QPushButton *pushButton_staff;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_back;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_save;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_Husk;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_vehicle_number;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_vihecleType_title;
    QLabel *label_Total;
    QLabel *label_4;
    QLabel *label_balance_title;
    QLabel *label_7;
    QLineEdit *lineEdit_customer;
    QLineEdit *lineEdit_paid_amt;
    QLabel *label_Total_title;
    QLabel *label_vihecleType;
    QLabel *label_balance;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_back_2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_husk_payment_save;
    QLabel *label_info;
    QGroupBox *groupBox_diesel_payment;
    QLabel *label_5;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QLineEdit *lineEdit_diesel_amount;
    QLabel *label_diesel_pending;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_back_deisel;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_payment_diesel_save;
    QLabel *label_6;
    QLineEdit *lineEdit_diesel_bunk_name;
    QLabel *label_9;
    QLabel *label_diesel_balance_title;
    QLabel *label_diesel_balance_amt;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_labour_payment;
    QLabel *label_10;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_4;
    QLineEdit *lineEdit_labour_amount;
    QLabel *label_labour_pending;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_labour_deisel;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_payment_labour_save;
    QLabel *label_12;
    QLineEdit *lineEdit_labour_name;
    QLabel *label_13;
    QLabel *label_labour_balance_title;
    QLabel *label_labour_balance_amt;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *groupBox_preview;
    QLabel *label_14;
    QTextEdit *textEdit;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_print_3;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton_print_4;
    QLabel *label_info_2;

    void setupUi(QWidget *Payment)
    {
        if (Payment->objectName().isEmpty())
            Payment->setObjectName(QString::fromUtf8("Payment"));
        Payment->resize(320, 1195);
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font.setPointSize(12);
        Payment->setFont(font);
        groupBox_home = new QGroupBox(Payment);
        groupBox_home->setObjectName(QString::fromUtf8("groupBox_home"));
        groupBox_home->setGeometry(QRect(0, 0, 320, 220));
        label = new QLabel(groupBox_home);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 320, 20));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        gridLayoutWidget = new QWidget(groupBox_home);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 300, 190));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 2, 1, 1);

        pushButton_Husk = new QPushButton(gridLayoutWidget);
        pushButton_Husk->setObjectName(QString::fromUtf8("pushButton_Husk"));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        pushButton_Husk->setFont(font2);
        pushButton_Husk->setAutoDefault(true);

        gridLayout->addWidget(pushButton_Husk, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 0, 1, 1);

        pushButton_labour = new QPushButton(gridLayoutWidget);
        pushButton_labour->setObjectName(QString::fromUtf8("pushButton_labour"));
        pushButton_labour->setFont(font2);
        pushButton_labour->setAutoDefault(true);

        gridLayout->addWidget(pushButton_labour, 3, 1, 1, 1);

        pushButton_other = new QPushButton(gridLayoutWidget);
        pushButton_other->setObjectName(QString::fromUtf8("pushButton_other"));
        pushButton_other->setFont(font2);
        pushButton_other->setAutoDefault(true);

        gridLayout->addWidget(pushButton_other, 4, 1, 1, 1);

        pushButton_Diesel = new QPushButton(gridLayoutWidget);
        pushButton_Diesel->setObjectName(QString::fromUtf8("pushButton_Diesel"));
        pushButton_Diesel->setFont(font2);
        pushButton_Diesel->setAutoDefault(true);

        gridLayout->addWidget(pushButton_Diesel, 2, 1, 1, 1);

        pushButton_staff = new QPushButton(gridLayoutWidget);
        pushButton_staff->setObjectName(QString::fromUtf8("pushButton_staff"));
        pushButton_staff->setFont(font2);
        pushButton_staff->setAutoDefault(true);

        gridLayout->addWidget(pushButton_staff, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_back = new QPushButton(gridLayoutWidget);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        pushButton_back->setFont(font3);
        pushButton_back->setFocusPolicy(Qt::NoFocus);
        pushButton_back->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_back->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_back);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_save = new QPushButton(gridLayoutWidget);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        pushButton_save->setFont(font3);
        pushButton_save->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_save->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_save);


        gridLayout->addLayout(horizontalLayout, 6, 0, 1, 3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 1, 1, 1);

        groupBox_Husk = new QGroupBox(Payment);
        groupBox_Husk->setObjectName(QString::fromUtf8("groupBox_Husk"));
        groupBox_Husk->setGeometry(QRect(0, 220, 320, 220));
        label_2 = new QLabel(groupBox_Husk);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 320, 20));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(groupBox_Husk);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(8, 18, 110, 24));
        label_3->setFont(font3);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_vehicle_number = new QLineEdit(groupBox_Husk);
        lineEdit_vehicle_number->setObjectName(QString::fromUtf8("lineEdit_vehicle_number"));
        lineEdit_vehicle_number->setGeometry(QRect(120, 20, 186, 24));
        lineEdit_vehicle_number->setFont(font);
        lineEdit_vehicle_number->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        gridLayoutWidget_2 = new QWidget(groupBox_Husk);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 50, 300, 170));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_vihecleType_title = new QLabel(gridLayoutWidget_2);
        label_vihecleType_title->setObjectName(QString::fromUtf8("label_vihecleType_title"));
        label_vihecleType_title->setFont(font2);
        label_vihecleType_title->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_vihecleType_title, 0, 0, 1, 1);

        label_Total = new QLabel(gridLayoutWidget_2);
        label_Total->setObjectName(QString::fromUtf8("label_Total"));

        gridLayout_2->addWidget(label_Total, 4, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        label_balance_title = new QLabel(gridLayoutWidget_2);
        label_balance_title->setObjectName(QString::fromUtf8("label_balance_title"));
        label_balance_title->setFont(font2);
        label_balance_title->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_balance_title, 2, 0, 1, 1);

        label_7 = new QLabel(gridLayoutWidget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font2);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_7, 3, 0, 1, 1);

        lineEdit_customer = new QLineEdit(gridLayoutWidget_2);
        lineEdit_customer->setObjectName(QString::fromUtf8("lineEdit_customer"));

        gridLayout_2->addWidget(lineEdit_customer, 1, 1, 1, 1);

        lineEdit_paid_amt = new QLineEdit(gridLayoutWidget_2);
        lineEdit_paid_amt->setObjectName(QString::fromUtf8("lineEdit_paid_amt"));

        gridLayout_2->addWidget(lineEdit_paid_amt, 3, 1, 1, 1);

        label_Total_title = new QLabel(gridLayoutWidget_2);
        label_Total_title->setObjectName(QString::fromUtf8("label_Total_title"));
        label_Total_title->setFont(font2);
        label_Total_title->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_Total_title, 4, 0, 1, 1);

        label_vihecleType = new QLabel(gridLayoutWidget_2);
        label_vihecleType->setObjectName(QString::fromUtf8("label_vihecleType"));

        gridLayout_2->addWidget(label_vihecleType, 0, 1, 1, 1);

        label_balance = new QLabel(gridLayoutWidget_2);
        label_balance->setObjectName(QString::fromUtf8("label_balance"));

        gridLayout_2->addWidget(label_balance, 2, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_back_2 = new QPushButton(gridLayoutWidget_2);
        pushButton_back_2->setObjectName(QString::fromUtf8("pushButton_back_2"));
        pushButton_back_2->setFont(font3);
        pushButton_back_2->setFocusPolicy(Qt::NoFocus);
        pushButton_back_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_back_2->setAutoDefault(true);

        horizontalLayout_2->addWidget(pushButton_back_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        pushButton_husk_payment_save = new QPushButton(gridLayoutWidget_2);
        pushButton_husk_payment_save->setObjectName(QString::fromUtf8("pushButton_husk_payment_save"));
        pushButton_husk_payment_save->setFont(font3);
        pushButton_husk_payment_save->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_husk_payment_save->setAutoDefault(true);

        horizontalLayout_2->addWidget(pushButton_husk_payment_save);


        gridLayout_2->addLayout(horizontalLayout_2, 5, 0, 1, 2);

        label_info = new QLabel(groupBox_Husk);
        label_info->setObjectName(QString::fromUtf8("label_info"));
        label_info->setGeometry(QRect(10, 80, 300, 90));
        QFont font4;
        font4.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font4.setPointSize(16);
        font4.setBold(true);
        font4.setWeight(75);
        label_info->setFont(font4);
        label_info->setStyleSheet(QString::fromUtf8("background-color: rgb(183, 255, 251);\n"
"color: rgb(177, 19, 66);"));
        label_info->setAlignment(Qt::AlignCenter);
        label_info->setWordWrap(true);
        label_info->raise();
        label_2->raise();
        label_3->raise();
        lineEdit_vehicle_number->raise();
        gridLayoutWidget_2->raise();
        groupBox_diesel_payment = new QGroupBox(Payment);
        groupBox_diesel_payment->setObjectName(QString::fromUtf8("groupBox_diesel_payment"));
        groupBox_diesel_payment->setGeometry(QRect(0, 440, 320, 220));
        label_5 = new QLabel(groupBox_diesel_payment);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 0, 320, 20));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);
        gridLayoutWidget_3 = new QWidget(groupBox_diesel_payment);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(10, 30, 300, 180));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        lineEdit_diesel_amount = new QLineEdit(gridLayoutWidget_3);
        lineEdit_diesel_amount->setObjectName(QString::fromUtf8("lineEdit_diesel_amount"));

        gridLayout_3->addWidget(lineEdit_diesel_amount, 2, 1, 1, 1);

        label_diesel_pending = new QLabel(gridLayoutWidget_3);
        label_diesel_pending->setObjectName(QString::fromUtf8("label_diesel_pending"));

        gridLayout_3->addWidget(label_diesel_pending, 1, 1, 1, 1);

        label_8 = new QLabel(gridLayoutWidget_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font2);

        gridLayout_3->addWidget(label_8, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_back_deisel = new QPushButton(gridLayoutWidget_3);
        pushButton_back_deisel->setObjectName(QString::fromUtf8("pushButton_back_deisel"));
        pushButton_back_deisel->setFont(font3);
        pushButton_back_deisel->setFocusPolicy(Qt::NoFocus);
        pushButton_back_deisel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_back_deisel->setAutoDefault(true);

        horizontalLayout_3->addWidget(pushButton_back_deisel);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        pushButton_payment_diesel_save = new QPushButton(gridLayoutWidget_3);
        pushButton_payment_diesel_save->setObjectName(QString::fromUtf8("pushButton_payment_diesel_save"));
        pushButton_payment_diesel_save->setFont(font3);
        pushButton_payment_diesel_save->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_payment_diesel_save->setAutoDefault(true);

        horizontalLayout_3->addWidget(pushButton_payment_diesel_save);


        gridLayout_3->addLayout(horizontalLayout_3, 5, 0, 1, 2);

        label_6 = new QLabel(gridLayoutWidget_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font2);

        gridLayout_3->addWidget(label_6, 0, 0, 1, 1);

        lineEdit_diesel_bunk_name = new QLineEdit(gridLayoutWidget_3);
        lineEdit_diesel_bunk_name->setObjectName(QString::fromUtf8("lineEdit_diesel_bunk_name"));

        gridLayout_3->addWidget(lineEdit_diesel_bunk_name, 0, 1, 1, 1);

        label_9 = new QLabel(gridLayoutWidget_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font2);

        gridLayout_3->addWidget(label_9, 2, 0, 1, 1);

        label_diesel_balance_title = new QLabel(gridLayoutWidget_3);
        label_diesel_balance_title->setObjectName(QString::fromUtf8("label_diesel_balance_title"));
        label_diesel_balance_title->setFont(font2);

        gridLayout_3->addWidget(label_diesel_balance_title, 3, 0, 1, 1);

        label_diesel_balance_amt = new QLabel(gridLayoutWidget_3);
        label_diesel_balance_amt->setObjectName(QString::fromUtf8("label_diesel_balance_amt"));

        gridLayout_3->addWidget(label_diesel_balance_amt, 3, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 4, 0, 1, 1);

        groupBox_labour_payment = new QGroupBox(Payment);
        groupBox_labour_payment->setObjectName(QString::fromUtf8("groupBox_labour_payment"));
        groupBox_labour_payment->setGeometry(QRect(0, 660, 320, 220));
        label_10 = new QLabel(groupBox_labour_payment);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(0, 0, 320, 20));
        label_10->setFont(font1);
        label_10->setAlignment(Qt::AlignCenter);
        gridLayoutWidget_4 = new QWidget(groupBox_labour_payment);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(10, 30, 300, 180));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        lineEdit_labour_amount = new QLineEdit(gridLayoutWidget_4);
        lineEdit_labour_amount->setObjectName(QString::fromUtf8("lineEdit_labour_amount"));

        gridLayout_4->addWidget(lineEdit_labour_amount, 2, 1, 1, 1);

        label_labour_pending = new QLabel(gridLayoutWidget_4);
        label_labour_pending->setObjectName(QString::fromUtf8("label_labour_pending"));

        gridLayout_4->addWidget(label_labour_pending, 1, 1, 1, 1);

        label_11 = new QLabel(gridLayoutWidget_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font2);

        gridLayout_4->addWidget(label_11, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_labour_deisel = new QPushButton(gridLayoutWidget_4);
        pushButton_labour_deisel->setObjectName(QString::fromUtf8("pushButton_labour_deisel"));
        pushButton_labour_deisel->setFont(font3);
        pushButton_labour_deisel->setFocusPolicy(Qt::NoFocus);
        pushButton_labour_deisel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_labour_deisel->setAutoDefault(true);

        horizontalLayout_4->addWidget(pushButton_labour_deisel);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        pushButton_payment_labour_save = new QPushButton(gridLayoutWidget_4);
        pushButton_payment_labour_save->setObjectName(QString::fromUtf8("pushButton_payment_labour_save"));
        pushButton_payment_labour_save->setFont(font3);
        pushButton_payment_labour_save->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_payment_labour_save->setAutoDefault(true);

        horizontalLayout_4->addWidget(pushButton_payment_labour_save);


        gridLayout_4->addLayout(horizontalLayout_4, 5, 0, 1, 2);

        label_12 = new QLabel(gridLayoutWidget_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font2);

        gridLayout_4->addWidget(label_12, 0, 0, 1, 1);

        lineEdit_labour_name = new QLineEdit(gridLayoutWidget_4);
        lineEdit_labour_name->setObjectName(QString::fromUtf8("lineEdit_labour_name"));

        gridLayout_4->addWidget(lineEdit_labour_name, 0, 1, 1, 1);

        label_13 = new QLabel(gridLayoutWidget_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font2);

        gridLayout_4->addWidget(label_13, 2, 0, 1, 1);

        label_labour_balance_title = new QLabel(gridLayoutWidget_4);
        label_labour_balance_title->setObjectName(QString::fromUtf8("label_labour_balance_title"));
        label_labour_balance_title->setFont(font2);

        gridLayout_4->addWidget(label_labour_balance_title, 3, 0, 1, 1);

        label_labour_balance_amt = new QLabel(gridLayoutWidget_4);
        label_labour_balance_amt->setObjectName(QString::fromUtf8("label_labour_balance_amt"));

        gridLayout_4->addWidget(label_labour_balance_amt, 3, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_3, 4, 0, 1, 1);

        groupBox_preview = new QGroupBox(Payment);
        groupBox_preview->setObjectName(QString::fromUtf8("groupBox_preview"));
        groupBox_preview->setGeometry(QRect(0, 880, 320, 220));
        groupBox_preview->setFont(font3);
        label_14 = new QLabel(groupBox_preview);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(0, 0, 320, 20));
        label_14->setFont(font3);
        label_14->setAlignment(Qt::AlignCenter);
        textEdit = new QTextEdit(groupBox_preview);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(0, 20, 320, 150));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Monospace"));
        textEdit->setFont(font5);
        textEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        textEdit->setReadOnly(true);
        horizontalLayoutWidget_2 = new QWidget(groupBox_preview);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 180, 300, 30));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        pushButton_print_3 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_print_3->setObjectName(QString::fromUtf8("pushButton_print_3"));
        pushButton_print_3->setFont(font3);
        pushButton_print_3->setFocusPolicy(Qt::NoFocus);
        pushButton_print_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_print_3->setAutoDefault(true);

        horizontalLayout_5->addWidget(pushButton_print_3);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        pushButton_print_4 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_print_4->setObjectName(QString::fromUtf8("pushButton_print_4"));
        pushButton_print_4->setFont(font3);
        pushButton_print_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_print_4->setAutoDefault(true);

        horizontalLayout_5->addWidget(pushButton_print_4);

        label_info_2 = new QLabel(groupBox_preview);
        label_info_2->setObjectName(QString::fromUtf8("label_info_2"));
        label_info_2->setGeometry(QRect(10, 50, 300, 90));
        QFont font6;
        font6.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font6.setPointSize(18);
        font6.setBold(true);
        font6.setWeight(75);
        label_info_2->setFont(font6);
        label_info_2->setStyleSheet(QString::fromUtf8("background-color: rgb(183, 255, 251);\n"
"color: rgb(177, 19, 66);"));
        label_info_2->setAlignment(Qt::AlignCenter);
        label_info_2->setWordWrap(true);
        QWidget::setTabOrder(pushButton_staff, pushButton_Husk);
        QWidget::setTabOrder(pushButton_Husk, pushButton_Diesel);
        QWidget::setTabOrder(pushButton_Diesel, pushButton_labour);
        QWidget::setTabOrder(pushButton_labour, pushButton_other);
        QWidget::setTabOrder(pushButton_other, pushButton_save);
        QWidget::setTabOrder(pushButton_save, lineEdit_vehicle_number);
        QWidget::setTabOrder(lineEdit_vehicle_number, lineEdit_customer);
        QWidget::setTabOrder(lineEdit_customer, lineEdit_paid_amt);
        QWidget::setTabOrder(lineEdit_paid_amt, pushButton_husk_payment_save);

        retranslateUi(Payment);

        QMetaObject::connectSlotsByName(Payment);
    } // setupUi

    void retranslateUi(QWidget *Payment)
    {
        Payment->setWindowTitle(QApplication::translate("Payment", "Form", 0, QApplication::UnicodeUTF8));
        groupBox_home->setTitle(QString());
        label->setText(QApplication::translate("Payment", "Payments", 0, QApplication::UnicodeUTF8));
        pushButton_Husk->setText(QApplication::translate("Payment", "Husk Payment", 0, QApplication::UnicodeUTF8));
        pushButton_labour->setText(QApplication::translate("Payment", "Labour Payment", 0, QApplication::UnicodeUTF8));
        pushButton_other->setText(QApplication::translate("Payment", "Other Payments", 0, QApplication::UnicodeUTF8));
        pushButton_Diesel->setText(QApplication::translate("Payment", "  Diesel Payment  ", 0, QApplication::UnicodeUTF8));
        pushButton_staff->setText(QApplication::translate("Payment", "Staff Payment", 0, QApplication::UnicodeUTF8));
        pushButton_back->setText(QApplication::translate("Payment", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_save->setText(QApplication::translate("Payment", "Save", 0, QApplication::UnicodeUTF8));
        groupBox_Husk->setTitle(QString());
        label_2->setText(QApplication::translate("Payment", "Husk Payment", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Payment", "Vehicle No:", 0, QApplication::UnicodeUTF8));
        lineEdit_vehicle_number->setText(QString());
        label_vihecleType_title->setText(QApplication::translate("Payment", "Type:", 0, QApplication::UnicodeUTF8));
        label_Total->setText(QApplication::translate("Payment", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Payment", "Customer:", 0, QApplication::UnicodeUTF8));
        label_balance_title->setText(QApplication::translate("Payment", "Balance:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Payment", "Paid:", 0, QApplication::UnicodeUTF8));
        label_Total_title->setText(QApplication::translate("Payment", "Total:", 0, QApplication::UnicodeUTF8));
        label_vihecleType->setText(QApplication::translate("Payment", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_balance->setText(QApplication::translate("Payment", "TextLabel", 0, QApplication::UnicodeUTF8));
        pushButton_back_2->setText(QApplication::translate("Payment", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_husk_payment_save->setText(QApplication::translate("Payment", "Preview", 0, QApplication::UnicodeUTF8));
        label_info->setText(QApplication::translate("Payment", "Generating Purchase Preview...", 0, QApplication::UnicodeUTF8));
        groupBox_diesel_payment->setTitle(QString());
        label_5->setText(QApplication::translate("Payment", "Diesel Payment", 0, QApplication::UnicodeUTF8));
        label_diesel_pending->setText(QString());
        label_8->setText(QApplication::translate("Payment", "Advance    :", 0, QApplication::UnicodeUTF8));
        pushButton_back_deisel->setText(QApplication::translate("Payment", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_payment_diesel_save->setText(QApplication::translate("Payment", "Save", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Payment", "Bunk Name  :", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Payment", "Amount     :", 0, QApplication::UnicodeUTF8));
        label_diesel_balance_title->setText(QApplication::translate("Payment", "Advance Amt:", 0, QApplication::UnicodeUTF8));
        label_diesel_balance_amt->setText(QString());
        groupBox_labour_payment->setTitle(QString());
        label_10->setText(QApplication::translate("Payment", "Labour Payment", 0, QApplication::UnicodeUTF8));
        label_labour_pending->setText(QString());
        label_11->setText(QApplication::translate("Payment", "Advance    :", 0, QApplication::UnicodeUTF8));
        pushButton_labour_deisel->setText(QApplication::translate("Payment", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_payment_labour_save->setText(QApplication::translate("Payment", "Save", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Payment", "Labour Name:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("Payment", "Amount     :", 0, QApplication::UnicodeUTF8));
        label_labour_balance_title->setText(QApplication::translate("Payment", "Advance Amt:", 0, QApplication::UnicodeUTF8));
        label_labour_balance_amt->setText(QString());
        groupBox_preview->setTitle(QString());
        label_14->setText(QApplication::translate("Payment", "Purchase Preview", 0, QApplication::UnicodeUTF8));
        pushButton_print_3->setText(QApplication::translate("Payment", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_print_4->setText(QApplication::translate("Payment", "F1-Print", 0, QApplication::UnicodeUTF8));
        label_info_2->setText(QApplication::translate("Payment", "Printing ...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Payment: public Ui_Payment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAYMENT_H
