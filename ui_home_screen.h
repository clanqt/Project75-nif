/********************************************************************************
** Form generated from reading UI file 'home_screen.ui'
**
** Created: Thu Jan 31 08:07:21 2019
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOME_SCREEN_H
#define UI_HOME_SCREEN_H

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

class Ui_Home_Screen
{
public:
    QGroupBox *groupBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_registered_vehicle;
    QLabel *label_lbh;
    QLabel *label_7;
    QLabel *label_vehicle_type;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_menu;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_next;
    QRadioButton *radioButton_cft;
    QLabel *label_11;
    QLabel *label_title_count;
    QLineEdit *lineEdit_height_inches;
    QLabel *label_length;
    QLineEdit *lineEdit_height;
    QRadioButton *radioButton_count;
    QLineEdit *lineEdit_count;
    QLabel *label_cus_title;
    QLineEdit *lineEdit_customer_name;
    QLabel *label_mobile_title;
    QLineEdit *lineEdit_customer_mobile;
    QLabel *label_title;
    QLabel *label;
    QLineEdit *lineEdit_vehicle_number;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_vehicle_registration;
    QLineEdit *lineEdit_reg_name;
    QLabel *label_15;
    QLineEdit *lineEdit_reg_length_inche;
    QLabel *label_17;
    QLineEdit *lineEdit_reg_breadth;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_reg_back;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_reg_save;
    QLineEdit *lineEdit_reg_breadth_inche;
    QLineEdit *lineEdit_reg_length;
    QLineEdit *lineEdit_reg_type;
    QLabel *label_bal_type_title;
    QLabel *label_title_type;
    QLabel *label_16;
    QLabel *label_18;
    QLabel *label_reg_name_title;
    QRadioButton *radioButton_reg_bal_advance;
    QRadioButton *radioButton_reg_bal_pending;
    QComboBox *comboBox_reg_owner;
    QLineEdit *lineEdit_reg_opening_balance;
    QGroupBox *groupBox_initial_config;
    QLabel *label_3;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *label_5;
    QLabel *label_6;
    QSpacerItem *verticalSpacer;
    QLineEdit *lineEdit_bull_reading;
    QLineEdit *lineEdit_generator_reading;
    QLineEdit *lineEdit_eb_reading;
    QLineEdit *lineEdit_diesel;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_initial_config_back;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_initial_config_save;

    void setupUi(QWidget *Home_Screen)
    {
        if (Home_Screen->objectName().isEmpty())
            Home_Screen->setObjectName(QString::fromUtf8("Home_Screen"));
        Home_Screen->resize(320, 652);
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font.setPointSize(12);
        Home_Screen->setFont(font);
        groupBox = new QGroupBox(Home_Screen);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 320, 430));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 249, 249);"));
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 50, 300, 180));
        gridLayout_registered_vehicle = new QGridLayout(gridLayoutWidget);
        gridLayout_registered_vehicle->setObjectName(QString::fromUtf8("gridLayout_registered_vehicle"));
        gridLayout_registered_vehicle->setContentsMargins(0, 0, 0, 0);
        label_lbh = new QLabel(gridLayoutWidget);
        label_lbh->setObjectName(QString::fromUtf8("label_lbh"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label_lbh->setFont(font1);
        label_lbh->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_registered_vehicle->addWidget(label_lbh, 5, 0, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_registered_vehicle->addWidget(label_7, 0, 0, 1, 1);

        label_vehicle_type = new QLabel(gridLayoutWidget);
        label_vehicle_type->setObjectName(QString::fromUtf8("label_vehicle_type"));
        label_vehicle_type->setFont(font);
        label_vehicle_type->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_vehicle_type->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_registered_vehicle->addWidget(label_vehicle_type, 0, 1, 1, 5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_menu = new QPushButton(gridLayoutWidget);
        pushButton_menu->setObjectName(QString::fromUtf8("pushButton_menu"));
        pushButton_menu->setFont(font1);
        pushButton_menu->setFocusPolicy(Qt::NoFocus);
        pushButton_menu->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_menu->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_menu);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_next = new QPushButton(gridLayoutWidget);
        pushButton_next->setObjectName(QString::fromUtf8("pushButton_next"));
        pushButton_next->setFont(font1);
        pushButton_next->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_next->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_next);


        gridLayout_registered_vehicle->addLayout(horizontalLayout, 8, 0, 1, 6);

        radioButton_cft = new QRadioButton(gridLayoutWidget);
        radioButton_cft->setObjectName(QString::fromUtf8("radioButton_cft"));
        radioButton_cft->setFont(font);
        radioButton_cft->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout_registered_vehicle->addWidget(radioButton_cft, 3, 1, 1, 2);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font1);
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_registered_vehicle->addWidget(label_11, 3, 0, 1, 1);

        label_title_count = new QLabel(gridLayoutWidget);
        label_title_count->setObjectName(QString::fromUtf8("label_title_count"));
        label_title_count->setFont(font1);
        label_title_count->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_registered_vehicle->addWidget(label_title_count, 4, 0, 1, 1);

        lineEdit_height_inches = new QLineEdit(gridLayoutWidget);
        lineEdit_height_inches->setObjectName(QString::fromUtf8("lineEdit_height_inches"));
        lineEdit_height_inches->setFont(font);
        lineEdit_height_inches->setStyleSheet(QString::fromUtf8("QLineEdit:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        lineEdit_height_inches->setMaxLength(12);
        lineEdit_height_inches->setAlignment(Qt::AlignCenter);

        gridLayout_registered_vehicle->addWidget(lineEdit_height_inches, 5, 5, 1, 1);

        label_length = new QLabel(gridLayoutWidget);
        label_length->setObjectName(QString::fromUtf8("label_length"));
        label_length->setFont(font);
        label_length->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_length->setAlignment(Qt::AlignCenter);

        gridLayout_registered_vehicle->addWidget(label_length, 5, 1, 1, 3);

        lineEdit_height = new QLineEdit(gridLayoutWidget);
        lineEdit_height->setObjectName(QString::fromUtf8("lineEdit_height"));
        lineEdit_height->setFont(font);
        lineEdit_height->setStyleSheet(QString::fromUtf8("QLineEdit:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        lineEdit_height->setMaxLength(12);
        lineEdit_height->setAlignment(Qt::AlignCenter);

        gridLayout_registered_vehicle->addWidget(lineEdit_height, 5, 4, 1, 1);

        radioButton_count = new QRadioButton(gridLayoutWidget);
        radioButton_count->setObjectName(QString::fromUtf8("radioButton_count"));
        radioButton_count->setFont(font);
        radioButton_count->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout_registered_vehicle->addWidget(radioButton_count, 3, 3, 1, 1);

        lineEdit_count = new QLineEdit(gridLayoutWidget);
        lineEdit_count->setObjectName(QString::fromUtf8("lineEdit_count"));
        lineEdit_count->setFont(font);
        lineEdit_count->setStyleSheet(QString::fromUtf8("QLineEdit:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));

        gridLayout_registered_vehicle->addWidget(lineEdit_count, 4, 1, 1, 3);

        label_cus_title = new QLabel(gridLayoutWidget);
        label_cus_title->setObjectName(QString::fromUtf8("label_cus_title"));
        label_cus_title->setFont(font1);
        label_cus_title->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_registered_vehicle->addWidget(label_cus_title, 1, 0, 1, 1);

        lineEdit_customer_name = new QLineEdit(gridLayoutWidget);
        lineEdit_customer_name->setObjectName(QString::fromUtf8("lineEdit_customer_name"));
        lineEdit_customer_name->setFont(font);
        lineEdit_customer_name->setFocusPolicy(Qt::NoFocus);
        lineEdit_customer_name->setStyleSheet(QString::fromUtf8("QLineEdit:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        lineEdit_customer_name->setReadOnly(true);

        gridLayout_registered_vehicle->addWidget(lineEdit_customer_name, 1, 1, 1, 5);

        label_mobile_title = new QLabel(gridLayoutWidget);
        label_mobile_title->setObjectName(QString::fromUtf8("label_mobile_title"));
        label_mobile_title->setFont(font1);
        label_mobile_title->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_registered_vehicle->addWidget(label_mobile_title, 2, 0, 1, 1);

        lineEdit_customer_mobile = new QLineEdit(gridLayoutWidget);
        lineEdit_customer_mobile->setObjectName(QString::fromUtf8("lineEdit_customer_mobile"));
        lineEdit_customer_mobile->setFont(font);
        lineEdit_customer_mobile->setFocusPolicy(Qt::NoFocus);
        lineEdit_customer_mobile->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineEdit_customer_mobile->setReadOnly(true);

        gridLayout_registered_vehicle->addWidget(lineEdit_customer_mobile, 2, 1, 1, 5);

        label_title = new QLabel(groupBox);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setGeometry(QRect(0, 0, 320, 20));
        label_title->setFont(font1);
        label_title->setAlignment(Qt::AlignCenter);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 110, 24));
        label->setFont(font1);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_vehicle_number = new QLineEdit(groupBox);
        lineEdit_vehicle_number->setObjectName(QString::fromUtf8("lineEdit_vehicle_number"));
        lineEdit_vehicle_number->setGeometry(QRect(122, 22, 186, 24));
        lineEdit_vehicle_number->setFont(font);
        lineEdit_vehicle_number->setStyleSheet(QString::fromUtf8("QLineEdit:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        gridLayoutWidget_2 = new QWidget(groupBox);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(0, 230, 334, 227));
        gridLayout_vehicle_registration = new QGridLayout(gridLayoutWidget_2);
        gridLayout_vehicle_registration->setObjectName(QString::fromUtf8("gridLayout_vehicle_registration"));
        gridLayout_vehicle_registration->setContentsMargins(0, 0, 0, 0);
        lineEdit_reg_name = new QLineEdit(gridLayoutWidget_2);
        lineEdit_reg_name->setObjectName(QString::fromUtf8("lineEdit_reg_name"));
        lineEdit_reg_name->setFont(font);
        lineEdit_reg_name->setStyleSheet(QString::fromUtf8("QLineEdit:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));

        gridLayout_vehicle_registration->addWidget(lineEdit_reg_name, 1, 1, 1, 5);

        label_15 = new QLabel(gridLayoutWidget_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font1);
        label_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_vehicle_registration->addWidget(label_15, 3, 0, 1, 1);

        lineEdit_reg_length_inche = new QLineEdit(gridLayoutWidget_2);
        lineEdit_reg_length_inche->setObjectName(QString::fromUtf8("lineEdit_reg_length_inche"));
        lineEdit_reg_length_inche->setFont(font);
        lineEdit_reg_length_inche->setStyleSheet(QString::fromUtf8("QLineEdit:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        lineEdit_reg_length_inche->setAlignment(Qt::AlignCenter);

        gridLayout_vehicle_registration->addWidget(lineEdit_reg_length_inche, 3, 2, 1, 1);

        label_17 = new QLabel(gridLayoutWidget_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_vehicle_registration->addWidget(label_17, 3, 3, 1, 1);

        lineEdit_reg_breadth = new QLineEdit(gridLayoutWidget_2);
        lineEdit_reg_breadth->setObjectName(QString::fromUtf8("lineEdit_reg_breadth"));
        lineEdit_reg_breadth->setFont(font);
        lineEdit_reg_breadth->setStyleSheet(QString::fromUtf8("QLineEdit:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        lineEdit_reg_breadth->setAlignment(Qt::AlignCenter);

        gridLayout_vehicle_registration->addWidget(lineEdit_reg_breadth, 3, 4, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_reg_back = new QPushButton(gridLayoutWidget_2);
        pushButton_reg_back->setObjectName(QString::fromUtf8("pushButton_reg_back"));
        pushButton_reg_back->setFont(font1);
        pushButton_reg_back->setFocusPolicy(Qt::NoFocus);
        pushButton_reg_back->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_reg_back->setAutoDefault(true);

        horizontalLayout_2->addWidget(pushButton_reg_back);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_reg_save = new QPushButton(gridLayoutWidget_2);
        pushButton_reg_save->setObjectName(QString::fromUtf8("pushButton_reg_save"));
        pushButton_reg_save->setFont(font1);
        pushButton_reg_save->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_reg_save->setAutoDefault(true);

        horizontalLayout_2->addWidget(pushButton_reg_save);


        gridLayout_vehicle_registration->addLayout(horizontalLayout_2, 6, 0, 1, 6);

        lineEdit_reg_breadth_inche = new QLineEdit(gridLayoutWidget_2);
        lineEdit_reg_breadth_inche->setObjectName(QString::fromUtf8("lineEdit_reg_breadth_inche"));
        lineEdit_reg_breadth_inche->setFont(font);
        lineEdit_reg_breadth_inche->setStyleSheet(QString::fromUtf8("QLineEdit:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        lineEdit_reg_breadth_inche->setAlignment(Qt::AlignCenter);

        gridLayout_vehicle_registration->addWidget(lineEdit_reg_breadth_inche, 3, 5, 1, 1);

        lineEdit_reg_length = new QLineEdit(gridLayoutWidget_2);
        lineEdit_reg_length->setObjectName(QString::fromUtf8("lineEdit_reg_length"));
        lineEdit_reg_length->setFont(font);
        lineEdit_reg_length->setStyleSheet(QString::fromUtf8("QLineEdit:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        lineEdit_reg_length->setAlignment(Qt::AlignCenter);

        gridLayout_vehicle_registration->addWidget(lineEdit_reg_length, 3, 1, 1, 1);

        lineEdit_reg_type = new QLineEdit(gridLayoutWidget_2);
        lineEdit_reg_type->setObjectName(QString::fromUtf8("lineEdit_reg_type"));
        lineEdit_reg_type->setFont(font);
        lineEdit_reg_type->setStyleSheet(QString::fromUtf8("QLineEdit:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));

        gridLayout_vehicle_registration->addWidget(lineEdit_reg_type, 2, 1, 1, 5);

        label_bal_type_title = new QLabel(gridLayoutWidget_2);
        label_bal_type_title->setObjectName(QString::fromUtf8("label_bal_type_title"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        label_bal_type_title->setFont(font2);
        label_bal_type_title->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_vehicle_registration->addWidget(label_bal_type_title, 5, 0, 1, 1);

        label_title_type = new QLabel(gridLayoutWidget_2);
        label_title_type->setObjectName(QString::fromUtf8("label_title_type"));
        label_title_type->setFont(font1);
        label_title_type->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_vehicle_registration->addWidget(label_title_type, 2, 0, 1, 1);

        label_16 = new QLabel(gridLayoutWidget_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font1);
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_vehicle_registration->addWidget(label_16, 0, 0, 1, 1);

        label_18 = new QLabel(gridLayoutWidget_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font3.setPointSize(11);
        font3.setBold(true);
        font3.setWeight(75);
        label_18->setFont(font3);
        label_18->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_vehicle_registration->addWidget(label_18, 4, 0, 1, 1);

        label_reg_name_title = new QLabel(gridLayoutWidget_2);
        label_reg_name_title->setObjectName(QString::fromUtf8("label_reg_name_title"));
        label_reg_name_title->setFont(font1);
        label_reg_name_title->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_vehicle_registration->addWidget(label_reg_name_title, 1, 0, 1, 1);

        radioButton_reg_bal_advance = new QRadioButton(gridLayoutWidget_2);
        radioButton_reg_bal_advance->setObjectName(QString::fromUtf8("radioButton_reg_bal_advance"));
        radioButton_reg_bal_advance->setFont(font1);
        radioButton_reg_bal_advance->setStyleSheet(QString::fromUtf8("QRadioButton:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));

        gridLayout_vehicle_registration->addWidget(radioButton_reg_bal_advance, 5, 4, 1, 2);

        radioButton_reg_bal_pending = new QRadioButton(gridLayoutWidget_2);
        radioButton_reg_bal_pending->setObjectName(QString::fromUtf8("radioButton_reg_bal_pending"));
        radioButton_reg_bal_pending->setFont(font3);
        radioButton_reg_bal_pending->setStyleSheet(QString::fromUtf8("QRadioButton:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));

        gridLayout_vehicle_registration->addWidget(radioButton_reg_bal_pending, 5, 1, 1, 3);

        comboBox_reg_owner = new QComboBox(gridLayoutWidget_2);
        comboBox_reg_owner->setObjectName(QString::fromUtf8("comboBox_reg_owner"));
        comboBox_reg_owner->setFont(font);
        comboBox_reg_owner->setStyleSheet(QString::fromUtf8("QComboBox:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));

        gridLayout_vehicle_registration->addWidget(comboBox_reg_owner, 0, 1, 1, 3);

        lineEdit_reg_opening_balance = new QLineEdit(gridLayoutWidget_2);
        lineEdit_reg_opening_balance->setObjectName(QString::fromUtf8("lineEdit_reg_opening_balance"));
        lineEdit_reg_opening_balance->setFont(font);
        lineEdit_reg_opening_balance->setStyleSheet(QString::fromUtf8("QLineEdit:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        lineEdit_reg_opening_balance->setMaxLength(6);

        gridLayout_vehicle_registration->addWidget(lineEdit_reg_opening_balance, 4, 1, 1, 3);

        gridLayout_vehicle_registration->setColumnStretch(0, 2);
        groupBox_initial_config = new QGroupBox(Home_Screen);
        groupBox_initial_config->setObjectName(QString::fromUtf8("groupBox_initial_config"));
        groupBox_initial_config->setGeometry(QRect(0, 430, 320, 220));
        groupBox_initial_config->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 249, 249);"));
        label_3 = new QLabel(groupBox_initial_config);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 0, 320, 25));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);
        gridLayoutWidget_3 = new QWidget(groupBox_initial_config);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(11, 23, 300, 190));
        gridLayout = new QGridLayout(gridLayoutWidget_3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(gridLayoutWidget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font1);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_8, 0, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 1, 1, 1);

        lineEdit_bull_reading = new QLineEdit(gridLayoutWidget_3);
        lineEdit_bull_reading->setObjectName(QString::fromUtf8("lineEdit_bull_reading"));
        lineEdit_bull_reading->setFont(font1);
        lineEdit_bull_reading->setStyleSheet(QString::fromUtf8("QLineEdit:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        lineEdit_bull_reading->setMaxLength(6);

        gridLayout->addWidget(lineEdit_bull_reading, 0, 1, 1, 1);

        lineEdit_generator_reading = new QLineEdit(gridLayoutWidget_3);
        lineEdit_generator_reading->setObjectName(QString::fromUtf8("lineEdit_generator_reading"));
        lineEdit_generator_reading->setFont(font1);
        lineEdit_generator_reading->setStyleSheet(QString::fromUtf8("QLineEdit:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        lineEdit_generator_reading->setMaxLength(6);

        gridLayout->addWidget(lineEdit_generator_reading, 1, 1, 1, 1);

        lineEdit_eb_reading = new QLineEdit(gridLayoutWidget_3);
        lineEdit_eb_reading->setObjectName(QString::fromUtf8("lineEdit_eb_reading"));
        lineEdit_eb_reading->setFont(font1);
        lineEdit_eb_reading->setStyleSheet(QString::fromUtf8("QLineEdit:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        lineEdit_eb_reading->setMaxLength(6);

        gridLayout->addWidget(lineEdit_eb_reading, 2, 1, 1, 1);

        lineEdit_diesel = new QLineEdit(gridLayoutWidget_3);
        lineEdit_diesel->setObjectName(QString::fromUtf8("lineEdit_diesel"));
        lineEdit_diesel->setFont(font1);
        lineEdit_diesel->setStyleSheet(QString::fromUtf8("QLineEdit:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        lineEdit_diesel->setMaxLength(6);

        gridLayout->addWidget(lineEdit_diesel, 3, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_initial_config_back = new QPushButton(gridLayoutWidget_3);
        pushButton_initial_config_back->setObjectName(QString::fromUtf8("pushButton_initial_config_back"));
        pushButton_initial_config_back->setFont(font1);
        pushButton_initial_config_back->setFocusPolicy(Qt::NoFocus);
        pushButton_initial_config_back->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_initial_config_back->setAutoDefault(true);

        horizontalLayout_3->addWidget(pushButton_initial_config_back);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButton_initial_config_save = new QPushButton(gridLayoutWidget_3);
        pushButton_initial_config_save->setObjectName(QString::fromUtf8("pushButton_initial_config_save"));
        pushButton_initial_config_save->setFont(font1);
        pushButton_initial_config_save->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_initial_config_save->setAutoDefault(true);

        horizontalLayout_3->addWidget(pushButton_initial_config_save);


        gridLayout->addLayout(horizontalLayout_3, 5, 0, 1, 2);

        QWidget::setTabOrder(lineEdit_vehicle_number, lineEdit_customer_name);
        QWidget::setTabOrder(lineEdit_customer_name, lineEdit_customer_mobile);
        QWidget::setTabOrder(lineEdit_customer_mobile, radioButton_cft);
        QWidget::setTabOrder(radioButton_cft, radioButton_count);
        QWidget::setTabOrder(radioButton_count, lineEdit_count);
        QWidget::setTabOrder(lineEdit_count, lineEdit_height);
        QWidget::setTabOrder(lineEdit_height, lineEdit_height_inches);
        QWidget::setTabOrder(lineEdit_height_inches, pushButton_next);
        QWidget::setTabOrder(pushButton_next, comboBox_reg_owner);
        QWidget::setTabOrder(comboBox_reg_owner, lineEdit_reg_name);
        QWidget::setTabOrder(lineEdit_reg_name, lineEdit_reg_type);
        QWidget::setTabOrder(lineEdit_reg_type, lineEdit_reg_length);
        QWidget::setTabOrder(lineEdit_reg_length, lineEdit_reg_length_inche);
        QWidget::setTabOrder(lineEdit_reg_length_inche, lineEdit_reg_breadth);
        QWidget::setTabOrder(lineEdit_reg_breadth, lineEdit_reg_breadth_inche);
        QWidget::setTabOrder(lineEdit_reg_breadth_inche, lineEdit_reg_opening_balance);
        QWidget::setTabOrder(lineEdit_reg_opening_balance, radioButton_reg_bal_pending);
        QWidget::setTabOrder(radioButton_reg_bal_pending, radioButton_reg_bal_advance);
        QWidget::setTabOrder(radioButton_reg_bal_advance, pushButton_reg_save);

        retranslateUi(Home_Screen);

        QMetaObject::connectSlotsByName(Home_Screen);
    } // setupUi

    void retranslateUi(QWidget *Home_Screen)
    {
        Home_Screen->setWindowTitle(QApplication::translate("Home_Screen", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label_lbh->setText(QApplication::translate("Home_Screen", "LxBxH:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Home_Screen", "Type:", 0, QApplication::UnicodeUTF8));
        label_vehicle_type->setText(QString());
        pushButton_menu->setText(QApplication::translate("Home_Screen", "F1-Menu", 0, QApplication::UnicodeUTF8));
        pushButton_next->setText(QApplication::translate("Home_Screen", "Enter-Select", 0, QApplication::UnicodeUTF8));
        radioButton_cft->setText(QApplication::translate("Home_Screen", "CFT", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Home_Screen", "Inward:", 0, QApplication::UnicodeUTF8));
        label_title_count->setText(QApplication::translate("Home_Screen", "Count:", 0, QApplication::UnicodeUTF8));
        lineEdit_height_inches->setText(QApplication::translate("Home_Screen", "12", 0, QApplication::UnicodeUTF8));
        label_length->setText(QApplication::translate("Home_Screen", "99.99x99.99", 0, QApplication::UnicodeUTF8));
        lineEdit_height->setText(QApplication::translate("Home_Screen", "99", 0, QApplication::UnicodeUTF8));
        radioButton_count->setText(QApplication::translate("Home_Screen", "Count", 0, QApplication::UnicodeUTF8));
        label_cus_title->setText(QApplication::translate("Home_Screen", "Customer:", 0, QApplication::UnicodeUTF8));
        lineEdit_customer_name->setText(QApplication::translate("Home_Screen", "25", 0, QApplication::UnicodeUTF8));
        label_mobile_title->setText(QApplication::translate("Home_Screen", "Mobile:", 0, QApplication::UnicodeUTF8));
        lineEdit_customer_mobile->setText(QApplication::translate("Home_Screen", "9047087157", 0, QApplication::UnicodeUTF8));
        label_title->setText(QApplication::translate("Home_Screen", "Customer Selection", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Home_Screen", "Vehicle No:", 0, QApplication::UnicodeUTF8));
        lineEdit_vehicle_number->setText(QString());
        lineEdit_reg_name->setText(QApplication::translate("Home_Screen", "jagan", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("Home_Screen", "LxB:", 0, QApplication::UnicodeUTF8));
        lineEdit_reg_length_inche->setText(QApplication::translate("Home_Screen", "99", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("Home_Screen", "x", 0, QApplication::UnicodeUTF8));
        lineEdit_reg_breadth->setText(QApplication::translate("Home_Screen", "99", 0, QApplication::UnicodeUTF8));
        pushButton_reg_back->setText(QApplication::translate("Home_Screen", "Ecs-Back", 0, QApplication::UnicodeUTF8));
        pushButton_reg_save->setText(QApplication::translate("Home_Screen", "Save", 0, QApplication::UnicodeUTF8));
        lineEdit_reg_breadth_inche->setText(QApplication::translate("Home_Screen", "99", 0, QApplication::UnicodeUTF8));
        lineEdit_reg_length->setText(QApplication::translate("Home_Screen", "99", 0, QApplication::UnicodeUTF8));
        label_bal_type_title->setText(QApplication::translate("Home_Screen", "Bal.Type", 0, QApplication::UnicodeUTF8));
        label_title_type->setText(QApplication::translate("Home_Screen", "Type:", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("Home_Screen", "  Owner:", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("Home_Screen", "Balance", 0, QApplication::UnicodeUTF8));
        label_reg_name_title->setText(QApplication::translate("Home_Screen", "Name:", 0, QApplication::UnicodeUTF8));
        radioButton_reg_bal_advance->setText(QApplication::translate("Home_Screen", "Advance(+)", 0, QApplication::UnicodeUTF8));
        radioButton_reg_bal_pending->setText(QApplication::translate("Home_Screen", "Pending(-)", 0, QApplication::UnicodeUTF8));
        comboBox_reg_owner->clear();
        comboBox_reg_owner->insertItems(0, QStringList()
         << QApplication::translate("Home_Screen", "Company", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Home_Screen", "Auto", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Home_Screen", "Van", 0, QApplication::UnicodeUTF8)
        );
        lineEdit_reg_opening_balance->setText(QApplication::translate("Home_Screen", "jagan", 0, QApplication::UnicodeUTF8));
        groupBox_initial_config->setTitle(QString());
        label_3->setText(QApplication::translate("Home_Screen", "Day Opening Readings", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Home_Screen", "Diesel    :", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Home_Screen", "Bull Meter:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Home_Screen", "EB Meter  :", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Home_Screen", "Generator :", 0, QApplication::UnicodeUTF8));
        pushButton_initial_config_back->setText(QApplication::translate("Home_Screen", "Ecs-Back", 0, QApplication::UnicodeUTF8));
        pushButton_initial_config_save->setText(QApplication::translate("Home_Screen", "Open Day", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Home_Screen: public Ui_Home_Screen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOME_SCREEN_H
