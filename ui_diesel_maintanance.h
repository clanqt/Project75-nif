/********************************************************************************
** Form generated from reading UI file 'diesel_maintanance.ui'
**
** Created: Thu Jan 31 08:07:21 2019
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIESEL_MAINTANANCE_H
#define UI_DIESEL_MAINTANANCE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Diesel_Maintanance
{
public:
    QGroupBox *groupBox_home;
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_purchase;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_usage;
    QSpacerItem *horizontalSpacer_3;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_Diesel_Purchase;
    QLabel *label_3;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_16;
    QLabel *label_6;
    QLabel *label_5;
    QLineEdit *lineEdit_bill_value;
    QLabel *label_4;
    QLineEdit *lineEdit_today_parchase;
    QLabel *label_9;
    QLabel *label_rate_per_liter;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_8;
    QLabel *label_opening_stock;
    QLineEdit *lineEdit_bunk_name;
    QLabel *label_13;
    QLabel *label_15;
    QLabel *label_7;
    QLabel *label_11;
    QLabel *label_closing_stock;
    QLabel *label_18;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_back;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton_save;
    QGroupBox *groupBox_Diesel_Usage;
    QLabel *label_12;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_7;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_bull;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButton_generator;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *pushButton_company_vehicle;
    QGroupBox *groupBox_Diesel_Usage_Entry;
    QLabel *label_usage_title;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_6;
    QLabel *label_17;
    QLabel *label_21;
    QRadioButton *radioButton_full;
    QRadioButton *radioButton_part;
    QLabel *label_cv_title;
    QLabel *label_22;
    QComboBox *comboBox_vehicle_number;
    QLabel *label_20;
    QSpacerItem *verticalSpacer_6;
    QLineEdit *lineEdit_input_qty;
    QLabel *label_23;
    QLabel *label_opening_stock_2;
    QLineEdit *lineEdit_meter_reading;
    QLabel *label_10;
    QLabel *label_19;
    QLabel *label_closing_stock_2;
    QLabel *label_24;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_back_2;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *pushButton_save_usage;

    void setupUi(QWidget *Diesel_Maintanance)
    {
        if (Diesel_Maintanance->objectName().isEmpty())
            Diesel_Maintanance->setObjectName(QString::fromUtf8("Diesel_Maintanance"));
        Diesel_Maintanance->resize(320, 906);
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font.setPointSize(12);
        Diesel_Maintanance->setFont(font);
        groupBox_home = new QGroupBox(Diesel_Maintanance);
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
        gridLayoutWidget->setGeometry(QRect(10, 30, 300, 140));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_purchase = new QPushButton(gridLayoutWidget);
        pushButton_purchase->setObjectName(QString::fromUtf8("pushButton_purchase"));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        pushButton_purchase->setFont(font2);
        pushButton_purchase->setAutoDefault(true);

        gridLayout->addWidget(pushButton_purchase, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        pushButton_usage = new QPushButton(gridLayoutWidget);
        pushButton_usage->setObjectName(QString::fromUtf8("pushButton_usage"));
        pushButton_usage->setFont(font2);
        pushButton_usage->setAutoDefault(true);

        gridLayout->addWidget(pushButton_usage, 1, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        horizontalLayoutWidget = new QWidget(groupBox_home);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 180, 300, 30));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font3;
        font3.setBold(true);
        font3.setWeight(75);
        label_2->setFont(font3);

        horizontalLayout->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        groupBox_Diesel_Purchase = new QGroupBox(Diesel_Maintanance);
        groupBox_Diesel_Purchase->setObjectName(QString::fromUtf8("groupBox_Diesel_Purchase"));
        groupBox_Diesel_Purchase->setGeometry(QRect(0, 220, 320, 220));
        label_3 = new QLabel(groupBox_Diesel_Purchase);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 0, 320, 20));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);
        gridLayoutWidget_2 = new QWidget(groupBox_Diesel_Purchase);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 20, 300, 170));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_16 = new QLabel(gridLayoutWidget_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_2->addWidget(label_16, 2, 3, 1, 1);

        label_6 = new QLabel(gridLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 1, 3, 1, 1);

        lineEdit_bill_value = new QLineEdit(gridLayoutWidget_2);
        lineEdit_bill_value->setObjectName(QString::fromUtf8("lineEdit_bill_value"));

        gridLayout_2->addWidget(lineEdit_bill_value, 2, 1, 1, 2);

        label_4 = new QLabel(gridLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        lineEdit_today_parchase = new QLineEdit(gridLayoutWidget_2);
        lineEdit_today_parchase->setObjectName(QString::fromUtf8("lineEdit_today_parchase"));

        gridLayout_2->addWidget(lineEdit_today_parchase, 1, 1, 1, 2);

        label_9 = new QLabel(gridLayoutWidget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_2->addWidget(label_9, 3, 0, 1, 1);

        label_rate_per_liter = new QLabel(gridLayoutWidget_2);
        label_rate_per_liter->setObjectName(QString::fromUtf8("label_rate_per_liter"));

        gridLayout_2->addWidget(label_rate_per_liter, 3, 1, 1, 2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 6, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 4, 0, 1, 1);

        label_opening_stock = new QLabel(gridLayoutWidget_2);
        label_opening_stock->setObjectName(QString::fromUtf8("label_opening_stock"));

        gridLayout_2->addWidget(label_opening_stock, 0, 1, 1, 2);

        lineEdit_bunk_name = new QLineEdit(gridLayoutWidget_2);
        lineEdit_bunk_name->setObjectName(QString::fromUtf8("lineEdit_bunk_name"));

        gridLayout_2->addWidget(lineEdit_bunk_name, 4, 1, 1, 3);

        label_13 = new QLabel(gridLayoutWidget_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_2->addWidget(label_13, 0, 3, 1, 1);

        label_15 = new QLabel(gridLayoutWidget_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_2->addWidget(label_15, 3, 3, 1, 1);

        label_7 = new QLabel(gridLayoutWidget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 2, 0, 1, 1);

        label_11 = new QLabel(gridLayoutWidget_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_2->addWidget(label_11, 5, 0, 1, 1);

        label_closing_stock = new QLabel(gridLayoutWidget_2);
        label_closing_stock->setObjectName(QString::fromUtf8("label_closing_stock"));

        gridLayout_2->addWidget(label_closing_stock, 5, 1, 1, 2);

        label_18 = new QLabel(gridLayoutWidget_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_2->addWidget(label_18, 5, 3, 1, 1);

        layoutWidget = new QWidget(groupBox_Diesel_Purchase);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 190, 300, 29));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton_back = new QPushButton(layoutWidget);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        pushButton_back->setFont(font4);
        pushButton_back->setFocusPolicy(Qt::NoFocus);
        pushButton_back->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_back->setAutoDefault(true);

        horizontalLayout_4->addWidget(pushButton_back);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        pushButton_save = new QPushButton(layoutWidget);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        pushButton_save->setFont(font4);
        pushButton_save->setFocusPolicy(Qt::StrongFocus);
        pushButton_save->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_save->setAutoDefault(true);

        horizontalLayout_4->addWidget(pushButton_save);

        groupBox_Diesel_Usage = new QGroupBox(Diesel_Maintanance);
        groupBox_Diesel_Usage->setObjectName(QString::fromUtf8("groupBox_Diesel_Usage"));
        groupBox_Diesel_Usage->setGeometry(QRect(0, 440, 320, 220));
        label_12 = new QLabel(groupBox_Diesel_Usage);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(0, 0, 320, 20));
        label_12->setFont(font1);
        label_12->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget_2 = new QWidget(groupBox_Diesel_Usage);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 180, 300, 30));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(horizontalLayoutWidget_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font3);

        horizontalLayout_3->addWidget(label_14);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        gridLayoutWidget_3 = new QWidget(groupBox_Diesel_Usage);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(10, 30, 300, 140));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton_bull = new QPushButton(gridLayoutWidget_3);
        pushButton_bull->setObjectName(QString::fromUtf8("pushButton_bull"));
        pushButton_bull->setFont(font2);
        pushButton_bull->setAutoDefault(true);

        gridLayout_4->addWidget(pushButton_bull, 0, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_4, 3, 1, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_9, 0, 0, 1, 1);

        pushButton_generator = new QPushButton(gridLayoutWidget_3);
        pushButton_generator->setObjectName(QString::fromUtf8("pushButton_generator"));
        pushButton_generator->setFont(font2);
        pushButton_generator->setAutoDefault(true);

        gridLayout_4->addWidget(pushButton_generator, 1, 1, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_10, 0, 2, 1, 1);

        pushButton_company_vehicle = new QPushButton(gridLayoutWidget_3);
        pushButton_company_vehicle->setObjectName(QString::fromUtf8("pushButton_company_vehicle"));
        pushButton_company_vehicle->setFont(font2);
        pushButton_company_vehicle->setAutoDefault(true);

        gridLayout_4->addWidget(pushButton_company_vehicle, 2, 1, 1, 1);

        groupBox_Diesel_Usage_Entry = new QGroupBox(Diesel_Maintanance);
        groupBox_Diesel_Usage_Entry->setObjectName(QString::fromUtf8("groupBox_Diesel_Usage_Entry"));
        groupBox_Diesel_Usage_Entry->setGeometry(QRect(0, 660, 320, 220));
        label_usage_title = new QLabel(groupBox_Diesel_Usage_Entry);
        label_usage_title->setObjectName(QString::fromUtf8("label_usage_title"));
        label_usage_title->setGeometry(QRect(0, 0, 320, 20));
        label_usage_title->setFont(font1);
        label_usage_title->setAlignment(Qt::AlignCenter);
        gridLayoutWidget_5 = new QWidget(groupBox_Diesel_Usage_Entry);
        gridLayoutWidget_5->setObjectName(QString::fromUtf8("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(10, 30, 304, 182));
        gridLayout_6 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        label_17 = new QLabel(gridLayoutWidget_5);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_6->addWidget(label_17, 0, 2, 1, 1);

        label_21 = new QLabel(gridLayoutWidget_5);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setFont(font3);

        gridLayout_6->addWidget(label_21, 3, 0, 1, 1);

        radioButton_full = new QRadioButton(gridLayoutWidget_5);
        radioButton_full->setObjectName(QString::fromUtf8("radioButton_full"));

        gridLayout_6->addWidget(radioButton_full, 3, 1, 1, 1);

        radioButton_part = new QRadioButton(gridLayoutWidget_5);
        radioButton_part->setObjectName(QString::fromUtf8("radioButton_part"));

        gridLayout_6->addWidget(radioButton_part, 3, 2, 1, 1);

        label_cv_title = new QLabel(gridLayoutWidget_5);
        label_cv_title->setObjectName(QString::fromUtf8("label_cv_title"));
        label_cv_title->setFont(font3);

        gridLayout_6->addWidget(label_cv_title, 1, 0, 1, 1);

        label_22 = new QLabel(gridLayoutWidget_5);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setFont(font3);

        gridLayout_6->addWidget(label_22, 4, 0, 1, 1);

        comboBox_vehicle_number = new QComboBox(gridLayoutWidget_5);
        comboBox_vehicle_number->setObjectName(QString::fromUtf8("comboBox_vehicle_number"));

        gridLayout_6->addWidget(comboBox_vehicle_number, 1, 1, 1, 2);

        label_20 = new QLabel(gridLayoutWidget_5);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setFont(font3);

        gridLayout_6->addWidget(label_20, 2, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_6, 6, 0, 1, 1);

        lineEdit_input_qty = new QLineEdit(gridLayoutWidget_5);
        lineEdit_input_qty->setObjectName(QString::fromUtf8("lineEdit_input_qty"));

        gridLayout_6->addWidget(lineEdit_input_qty, 2, 1, 1, 1);

        label_23 = new QLabel(gridLayoutWidget_5);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_6->addWidget(label_23, 2, 2, 1, 1);

        label_opening_stock_2 = new QLabel(gridLayoutWidget_5);
        label_opening_stock_2->setObjectName(QString::fromUtf8("label_opening_stock_2"));

        gridLayout_6->addWidget(label_opening_stock_2, 0, 1, 1, 1);

        lineEdit_meter_reading = new QLineEdit(gridLayoutWidget_5);
        lineEdit_meter_reading->setObjectName(QString::fromUtf8("lineEdit_meter_reading"));

        gridLayout_6->addWidget(lineEdit_meter_reading, 4, 1, 1, 2);

        label_10 = new QLabel(gridLayoutWidget_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font3);

        gridLayout_6->addWidget(label_10, 0, 0, 1, 1);

        label_19 = new QLabel(gridLayoutWidget_5);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setFont(font3);

        gridLayout_6->addWidget(label_19, 5, 0, 1, 1);

        label_closing_stock_2 = new QLabel(gridLayoutWidget_5);
        label_closing_stock_2->setObjectName(QString::fromUtf8("label_closing_stock_2"));

        gridLayout_6->addWidget(label_closing_stock_2, 5, 1, 1, 1);

        label_24 = new QLabel(gridLayoutWidget_5);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_6->addWidget(label_24, 5, 2, 1, 1);

        layoutWidget_2 = new QWidget(groupBox_Diesel_Usage_Entry);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 180, 300, 29));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        pushButton_back_2 = new QPushButton(layoutWidget_2);
        pushButton_back_2->setObjectName(QString::fromUtf8("pushButton_back_2"));
        pushButton_back_2->setFont(font4);
        pushButton_back_2->setFocusPolicy(Qt::NoFocus);
        pushButton_back_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_back_2->setAutoDefault(true);

        horizontalLayout_6->addWidget(pushButton_back_2);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_14);

        pushButton_save_usage = new QPushButton(layoutWidget_2);
        pushButton_save_usage->setObjectName(QString::fromUtf8("pushButton_save_usage"));
        pushButton_save_usage->setFont(font4);
        pushButton_save_usage->setFocusPolicy(Qt::StrongFocus);
        pushButton_save_usage->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_save_usage->setAutoDefault(true);

        horizontalLayout_6->addWidget(pushButton_save_usage);

        QWidget::setTabOrder(pushButton_purchase, pushButton_usage);
        QWidget::setTabOrder(pushButton_usage, lineEdit_today_parchase);
        QWidget::setTabOrder(lineEdit_today_parchase, lineEdit_bill_value);
        QWidget::setTabOrder(lineEdit_bill_value, lineEdit_bunk_name);
        QWidget::setTabOrder(lineEdit_bunk_name, pushButton_save);
        QWidget::setTabOrder(pushButton_save, pushButton_bull);
        QWidget::setTabOrder(pushButton_bull, pushButton_generator);
        QWidget::setTabOrder(pushButton_generator, pushButton_company_vehicle);
        QWidget::setTabOrder(pushButton_company_vehicle, comboBox_vehicle_number);
        QWidget::setTabOrder(comboBox_vehicle_number, lineEdit_input_qty);
        QWidget::setTabOrder(lineEdit_input_qty, radioButton_full);
        QWidget::setTabOrder(radioButton_full, radioButton_part);
        QWidget::setTabOrder(radioButton_part, lineEdit_meter_reading);
        QWidget::setTabOrder(lineEdit_meter_reading, pushButton_save_usage);

        retranslateUi(Diesel_Maintanance);

        QMetaObject::connectSlotsByName(Diesel_Maintanance);
    } // setupUi

    void retranslateUi(QWidget *Diesel_Maintanance)
    {
        Diesel_Maintanance->setWindowTitle(QApplication::translate("Diesel_Maintanance", "Form", 0, QApplication::UnicodeUTF8));
        groupBox_home->setTitle(QString());
        label->setText(QApplication::translate("Diesel_Maintanance", "Diesel Maintanance", 0, QApplication::UnicodeUTF8));
        pushButton_purchase->setText(QApplication::translate("Diesel_Maintanance", "Diesel Purchase", 0, QApplication::UnicodeUTF8));
        pushButton_usage->setText(QApplication::translate("Diesel_Maintanance", "Diesel Usage", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Diesel_Maintanance", "Esc-Back", 0, QApplication::UnicodeUTF8));
        groupBox_Diesel_Purchase->setTitle(QString());
        label_3->setText(QApplication::translate("Diesel_Maintanance", "Diesel Purchase", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("Diesel_Maintanance", "Rs", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Diesel_Maintanance", "Today Purchase:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Diesel_Maintanance", "lts", 0, QApplication::UnicodeUTF8));
        lineEdit_bill_value->setText(QApplication::translate("Diesel_Maintanance", "7474", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Diesel_Maintanance", "Opening Stock :", 0, QApplication::UnicodeUTF8));
        lineEdit_today_parchase->setText(QApplication::translate("Diesel_Maintanance", "455645", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Diesel_Maintanance", "Rate Per Liter:", 0, QApplication::UnicodeUTF8));
        label_rate_per_liter->setText(QApplication::translate("Diesel_Maintanance", "4563", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Diesel_Maintanance", "Bunk Name     :", 0, QApplication::UnicodeUTF8));
        label_opening_stock->setText(QApplication::translate("Diesel_Maintanance", "45656", 0, QApplication::UnicodeUTF8));
        lineEdit_bunk_name->setText(QApplication::translate("Diesel_Maintanance", "dfbs", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("Diesel_Maintanance", "lts", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("Diesel_Maintanance", "lts", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Diesel_Maintanance", "Bill Amount   :", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Diesel_Maintanance", "Closing Stock :", 0, QApplication::UnicodeUTF8));
        label_closing_stock->setText(QApplication::translate("Diesel_Maintanance", "45656", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("Diesel_Maintanance", "lts", 0, QApplication::UnicodeUTF8));
        pushButton_back->setText(QApplication::translate("Diesel_Maintanance", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_save->setText(QApplication::translate("Diesel_Maintanance", "Save", 0, QApplication::UnicodeUTF8));
        groupBox_Diesel_Usage->setTitle(QString());
        label_12->setText(QApplication::translate("Diesel_Maintanance", "Diesel Usage", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("Diesel_Maintanance", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_bull->setText(QApplication::translate("Diesel_Maintanance", "Bull Usage", 0, QApplication::UnicodeUTF8));
        pushButton_generator->setText(QApplication::translate("Diesel_Maintanance", "Generator Usage", 0, QApplication::UnicodeUTF8));
        pushButton_company_vehicle->setText(QApplication::translate("Diesel_Maintanance", "Company Vehicle", 0, QApplication::UnicodeUTF8));
        groupBox_Diesel_Usage_Entry->setTitle(QString());
        label_usage_title->setText(QApplication::translate("Diesel_Maintanance", "Bull Usage", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("Diesel_Maintanance", "lts", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("Diesel_Maintanance", "Quantity Filled:", 0, QApplication::UnicodeUTF8));
        radioButton_full->setText(QApplication::translate("Diesel_Maintanance", "Full", 0, QApplication::UnicodeUTF8));
        radioButton_part->setText(QApplication::translate("Diesel_Maintanance", "Part", 0, QApplication::UnicodeUTF8));
        label_cv_title->setText(QApplication::translate("Diesel_Maintanance", "Company Vehicle:", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("Diesel_Maintanance", "Meter Reading  :", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("Diesel_Maintanance", "Diesel Loaded  :", 0, QApplication::UnicodeUTF8));
        lineEdit_input_qty->setText(QString());
        label_23->setText(QApplication::translate("Diesel_Maintanance", "lts", 0, QApplication::UnicodeUTF8));
        label_opening_stock_2->setText(QApplication::translate("Diesel_Maintanance", "45656", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Diesel_Maintanance", "Opening Stock :", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("Diesel_Maintanance", "Closing Stock  :", 0, QApplication::UnicodeUTF8));
        label_closing_stock_2->setText(QApplication::translate("Diesel_Maintanance", "45656", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("Diesel_Maintanance", "lts", 0, QApplication::UnicodeUTF8));
        pushButton_back_2->setText(QApplication::translate("Diesel_Maintanance", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_save_usage->setText(QApplication::translate("Diesel_Maintanance", "Save", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Diesel_Maintanance: public Ui_Diesel_Maintanance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIESEL_MAINTANANCE_H
