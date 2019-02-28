/********************************************************************************
** Form generated from reading UI file 'customer_master.ui'
**
** Created: Thu Jan 31 08:07:21 2019
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMER_MASTER_H
#define UI_CUSTOMER_MASTER_H

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

class Ui_Customer_Master
{
public:
    QGroupBox *groupBox_customer;
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_back;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_save_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_save;
    QLabel *label_customer_type;
    QLabel *label_balance;
    QGroupBox *groupBox_vehicle;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_vehicle_registration;
    QLineEdit *lineEdit_reg_breadth_inche;
    QLabel *label_mobile_title;
    QLabel *label_reg_name_title;
    QLabel *label_22;
    QLineEdit *lineEdit_reg_name;
    QComboBox *comboBox_reg_owner;
    QRadioButton *radioButton_reg_bal_advance;
    QLineEdit *lineEdit_reg_length_inche;
    QLabel *label_bal_type_title;
    QLabel *label_21;
    QLineEdit *lineEdit_reg_breadth;
    QRadioButton *radioButton_reg_bal_pending;
    QLineEdit *lineEdit_reg_length;
    QLabel *label_20;
    QLabel *label_19;
    QLineEdit *lineEdit_reg_opening_balance;
    QLineEdit *lineEdit_mobile;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_vehicle_esc;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_edit;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_vehicle_save;
    QLineEdit *lineEdit_vehicle_number;
    QLabel *label_7;
    QLabel *label_8;

    void setupUi(QWidget *Customer_Master)
    {
        if (Customer_Master->objectName().isEmpty())
            Customer_Master->setObjectName(QString::fromUtf8("Customer_Master"));
        Customer_Master->resize(320, 660);
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font.setPointSize(12);
        Customer_Master->setFont(font);
        groupBox_customer = new QGroupBox(Customer_Master);
        groupBox_customer->setObjectName(QString::fromUtf8("groupBox_customer"));
        groupBox_customer->setGeometry(QRect(0, 0, 320, 220));
        groupBox_customer->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 249, 249);"));
        label = new QLabel(groupBox_customer);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 320, 20));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        gridLayoutWidget = new QWidget(groupBox_customer);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 30, 300, 180));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lineEdit = new QLineEdit(gridLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setFont(font);

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_back = new QPushButton(gridLayoutWidget);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));
        pushButton_back->setFont(font2);
        pushButton_back->setFocusPolicy(Qt::NoFocus);
        pushButton_back->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_back->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_back);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_save_2 = new QPushButton(gridLayoutWidget);
        pushButton_save_2->setObjectName(QString::fromUtf8("pushButton_save_2"));
        pushButton_save_2->setFont(font2);
        pushButton_save_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_save_2->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_save_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_save = new QPushButton(gridLayoutWidget);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        pushButton_save->setFont(font2);
        pushButton_save->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_save->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_save);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 2);

        label_customer_type = new QLabel(gridLayoutWidget);
        label_customer_type->setObjectName(QString::fromUtf8("label_customer_type"));
        label_customer_type->setFont(font);

        gridLayout->addWidget(label_customer_type, 1, 1, 1, 1);

        label_balance = new QLabel(gridLayoutWidget);
        label_balance->setObjectName(QString::fromUtf8("label_balance"));
        label_balance->setFont(font);

        gridLayout->addWidget(label_balance, 2, 1, 1, 1);

        groupBox_vehicle = new QGroupBox(Customer_Master);
        groupBox_vehicle->setObjectName(QString::fromUtf8("groupBox_vehicle"));
        groupBox_vehicle->setGeometry(QRect(0, 220, 320, 220));
        groupBox_vehicle->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 249, 249);"));
        gridLayoutWidget_2 = new QWidget(groupBox_vehicle);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(0, 43, 320, 170));
        gridLayout_vehicle_registration = new QGridLayout(gridLayoutWidget_2);
        gridLayout_vehicle_registration->setObjectName(QString::fromUtf8("gridLayout_vehicle_registration"));
        gridLayout_vehicle_registration->setContentsMargins(0, 0, 0, 0);
        lineEdit_reg_breadth_inche = new QLineEdit(gridLayoutWidget_2);
        lineEdit_reg_breadth_inche->setObjectName(QString::fromUtf8("lineEdit_reg_breadth_inche"));
        lineEdit_reg_breadth_inche->setFont(font);
        lineEdit_reg_breadth_inche->setStyleSheet(QString::fromUtf8("QLineEdit:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        lineEdit_reg_breadth_inche->setAlignment(Qt::AlignCenter);

        gridLayout_vehicle_registration->addWidget(lineEdit_reg_breadth_inche, 3, 5, 1, 1);

        label_mobile_title = new QLabel(gridLayoutWidget_2);
        label_mobile_title->setObjectName(QString::fromUtf8("label_mobile_title"));
        label_mobile_title->setFont(font2);
        label_mobile_title->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_vehicle_registration->addWidget(label_mobile_title, 2, 0, 1, 1);

        label_reg_name_title = new QLabel(gridLayoutWidget_2);
        label_reg_name_title->setObjectName(QString::fromUtf8("label_reg_name_title"));
        label_reg_name_title->setFont(font2);
        label_reg_name_title->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_vehicle_registration->addWidget(label_reg_name_title, 1, 0, 1, 1);

        label_22 = new QLabel(gridLayoutWidget_2);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font3.setPointSize(11);
        font3.setBold(true);
        font3.setWeight(75);
        label_22->setFont(font3);
        label_22->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_vehicle_registration->addWidget(label_22, 4, 0, 1, 1);

        lineEdit_reg_name = new QLineEdit(gridLayoutWidget_2);
        lineEdit_reg_name->setObjectName(QString::fromUtf8("lineEdit_reg_name"));
        lineEdit_reg_name->setFont(font);
        lineEdit_reg_name->setStyleSheet(QString::fromUtf8("QLineEdit:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));

        gridLayout_vehicle_registration->addWidget(lineEdit_reg_name, 1, 1, 1, 5);

        comboBox_reg_owner = new QComboBox(gridLayoutWidget_2);
        comboBox_reg_owner->setObjectName(QString::fromUtf8("comboBox_reg_owner"));
        comboBox_reg_owner->setFont(font);
        comboBox_reg_owner->setStyleSheet(QString::fromUtf8("QComboBox:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));

        gridLayout_vehicle_registration->addWidget(comboBox_reg_owner, 0, 1, 1, 3);

        radioButton_reg_bal_advance = new QRadioButton(gridLayoutWidget_2);
        radioButton_reg_bal_advance->setObjectName(QString::fromUtf8("radioButton_reg_bal_advance"));
        radioButton_reg_bal_advance->setFont(font2);
        radioButton_reg_bal_advance->setStyleSheet(QString::fromUtf8("QRadioButton:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));

        gridLayout_vehicle_registration->addWidget(radioButton_reg_bal_advance, 5, 4, 1, 2);

        lineEdit_reg_length_inche = new QLineEdit(gridLayoutWidget_2);
        lineEdit_reg_length_inche->setObjectName(QString::fromUtf8("lineEdit_reg_length_inche"));
        lineEdit_reg_length_inche->setFont(font);
        lineEdit_reg_length_inche->setStyleSheet(QString::fromUtf8("QLineEdit:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        lineEdit_reg_length_inche->setAlignment(Qt::AlignCenter);

        gridLayout_vehicle_registration->addWidget(lineEdit_reg_length_inche, 3, 2, 1, 1);

        label_bal_type_title = new QLabel(gridLayoutWidget_2);
        label_bal_type_title->setObjectName(QString::fromUtf8("label_bal_type_title"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setWeight(75);
        label_bal_type_title->setFont(font4);
        label_bal_type_title->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_vehicle_registration->addWidget(label_bal_type_title, 5, 0, 1, 1);

        label_21 = new QLabel(gridLayoutWidget_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setFont(font2);
        label_21->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_vehicle_registration->addWidget(label_21, 0, 0, 1, 1);

        lineEdit_reg_breadth = new QLineEdit(gridLayoutWidget_2);
        lineEdit_reg_breadth->setObjectName(QString::fromUtf8("lineEdit_reg_breadth"));
        lineEdit_reg_breadth->setFont(font);
        lineEdit_reg_breadth->setStyleSheet(QString::fromUtf8("QLineEdit:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        lineEdit_reg_breadth->setAlignment(Qt::AlignCenter);

        gridLayout_vehicle_registration->addWidget(lineEdit_reg_breadth, 3, 4, 1, 1);

        radioButton_reg_bal_pending = new QRadioButton(gridLayoutWidget_2);
        radioButton_reg_bal_pending->setObjectName(QString::fromUtf8("radioButton_reg_bal_pending"));
        radioButton_reg_bal_pending->setFont(font3);
        radioButton_reg_bal_pending->setStyleSheet(QString::fromUtf8("QRadioButton:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));

        gridLayout_vehicle_registration->addWidget(radioButton_reg_bal_pending, 5, 1, 1, 3);

        lineEdit_reg_length = new QLineEdit(gridLayoutWidget_2);
        lineEdit_reg_length->setObjectName(QString::fromUtf8("lineEdit_reg_length"));
        lineEdit_reg_length->setFont(font);
        lineEdit_reg_length->setStyleSheet(QString::fromUtf8("QLineEdit:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        lineEdit_reg_length->setAlignment(Qt::AlignCenter);

        gridLayout_vehicle_registration->addWidget(lineEdit_reg_length, 3, 1, 1, 1);

        label_20 = new QLabel(gridLayoutWidget_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_vehicle_registration->addWidget(label_20, 3, 3, 1, 1);

        label_19 = new QLabel(gridLayoutWidget_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setFont(font2);
        label_19->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_vehicle_registration->addWidget(label_19, 3, 0, 1, 1);

        lineEdit_reg_opening_balance = new QLineEdit(gridLayoutWidget_2);
        lineEdit_reg_opening_balance->setObjectName(QString::fromUtf8("lineEdit_reg_opening_balance"));
        lineEdit_reg_opening_balance->setFont(font);
        lineEdit_reg_opening_balance->setStyleSheet(QString::fromUtf8("QLineEdit:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        lineEdit_reg_opening_balance->setMaxLength(6);

        gridLayout_vehicle_registration->addWidget(lineEdit_reg_opening_balance, 4, 1, 1, 3);

        lineEdit_mobile = new QLineEdit(gridLayoutWidget_2);
        lineEdit_mobile->setObjectName(QString::fromUtf8("lineEdit_mobile"));
        lineEdit_mobile->setFont(font);
        lineEdit_mobile->setStyleSheet(QString::fromUtf8("QLineEdit:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        lineEdit_mobile->setMaxLength(15);

        gridLayout_vehicle_registration->addWidget(lineEdit_mobile, 2, 1, 1, 5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_vehicle_esc = new QPushButton(gridLayoutWidget_2);
        pushButton_vehicle_esc->setObjectName(QString::fromUtf8("pushButton_vehicle_esc"));
        pushButton_vehicle_esc->setFont(font2);
        pushButton_vehicle_esc->setFocusPolicy(Qt::NoFocus);
        pushButton_vehicle_esc->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_vehicle_esc->setAutoDefault(true);

        horizontalLayout_3->addWidget(pushButton_vehicle_esc);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        pushButton_edit = new QPushButton(gridLayoutWidget_2);
        pushButton_edit->setObjectName(QString::fromUtf8("pushButton_edit"));
        pushButton_edit->setFont(font2);
        pushButton_edit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_edit->setAutoDefault(true);

        horizontalLayout_3->addWidget(pushButton_edit);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        pushButton_vehicle_save = new QPushButton(gridLayoutWidget_2);
        pushButton_vehicle_save->setObjectName(QString::fromUtf8("pushButton_vehicle_save"));
        pushButton_vehicle_save->setFont(font2);
        pushButton_vehicle_save->setStyleSheet(QString::fromUtf8("QLineEdit:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        pushButton_vehicle_save->setAutoDefault(true);

        horizontalLayout_3->addWidget(pushButton_vehicle_save);


        gridLayout_vehicle_registration->addLayout(horizontalLayout_3, 6, 0, 1, 6);

        gridLayout_vehicle_registration->setColumnStretch(0, 2);
        lineEdit_vehicle_number = new QLineEdit(groupBox_vehicle);
        lineEdit_vehicle_number->setObjectName(QString::fromUtf8("lineEdit_vehicle_number"));
        lineEdit_vehicle_number->setGeometry(QRect(122, 20, 186, 20));
        lineEdit_vehicle_number->setFont(font);
        lineEdit_vehicle_number->setStyleSheet(QString::fromUtf8("QLineEdit:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        label_7 = new QLabel(groupBox_vehicle);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 18, 110, 20));
        label_7->setFont(font2);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_8 = new QLabel(groupBox_vehicle);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(0, 0, 320, 15));
        QFont font5;
        font5.setPointSize(12);
        font5.setBold(true);
        font5.setWeight(75);
        label_8->setFont(font5);
        label_8->setAlignment(Qt::AlignCenter);
        QWidget::setTabOrder(lineEdit, pushButton_save_2);
        QWidget::setTabOrder(pushButton_save_2, pushButton_save);
        QWidget::setTabOrder(pushButton_save, lineEdit_vehicle_number);
        QWidget::setTabOrder(lineEdit_vehicle_number, comboBox_reg_owner);
        QWidget::setTabOrder(comboBox_reg_owner, lineEdit_reg_name);
        QWidget::setTabOrder(lineEdit_reg_name, lineEdit_mobile);
        QWidget::setTabOrder(lineEdit_mobile, lineEdit_reg_length);
        QWidget::setTabOrder(lineEdit_reg_length, lineEdit_reg_length_inche);
        QWidget::setTabOrder(lineEdit_reg_length_inche, lineEdit_reg_breadth);
        QWidget::setTabOrder(lineEdit_reg_breadth, lineEdit_reg_breadth_inche);
        QWidget::setTabOrder(lineEdit_reg_breadth_inche, lineEdit_reg_opening_balance);
        QWidget::setTabOrder(lineEdit_reg_opening_balance, radioButton_reg_bal_pending);
        QWidget::setTabOrder(radioButton_reg_bal_pending, radioButton_reg_bal_advance);
        QWidget::setTabOrder(radioButton_reg_bal_advance, pushButton_edit);
        QWidget::setTabOrder(pushButton_edit, pushButton_vehicle_save);

        retranslateUi(Customer_Master);

        QMetaObject::connectSlotsByName(Customer_Master);
    } // setupUi

    void retranslateUi(QWidget *Customer_Master)
    {
        Customer_Master->setWindowTitle(QApplication::translate("Customer_Master", "Form", 0, QApplication::UnicodeUTF8));
        groupBox_customer->setTitle(QString());
        label->setText(QApplication::translate("Customer_Master", "Customer Master", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Customer_Master", "Type:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Customer_Master", "Balance:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Customer_Master", "Name:", 0, QApplication::UnicodeUTF8));
        pushButton_back->setText(QApplication::translate("Customer_Master", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_save_2->setText(QApplication::translate("Customer_Master", "F2-Edit", 0, QApplication::UnicodeUTF8));
        pushButton_save->setText(QApplication::translate("Customer_Master", "Save", 0, QApplication::UnicodeUTF8));
        label_customer_type->setText(QString());
        label_balance->setText(QString());
        groupBox_vehicle->setTitle(QString());
        lineEdit_reg_breadth_inche->setText(QApplication::translate("Customer_Master", "99", 0, QApplication::UnicodeUTF8));
        label_mobile_title->setText(QApplication::translate("Customer_Master", "Mobile:", 0, QApplication::UnicodeUTF8));
        label_reg_name_title->setText(QApplication::translate("Customer_Master", "Name:", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("Customer_Master", "Balance", 0, QApplication::UnicodeUTF8));
        lineEdit_reg_name->setText(QApplication::translate("Customer_Master", "jagan", 0, QApplication::UnicodeUTF8));
        comboBox_reg_owner->clear();
        comboBox_reg_owner->insertItems(0, QStringList()
         << QApplication::translate("Customer_Master", "Company", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Customer_Master", "Auto", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Customer_Master", "Van", 0, QApplication::UnicodeUTF8)
        );
        radioButton_reg_bal_advance->setText(QApplication::translate("Customer_Master", "Advance(+)", 0, QApplication::UnicodeUTF8));
        lineEdit_reg_length_inche->setText(QApplication::translate("Customer_Master", "99", 0, QApplication::UnicodeUTF8));
        label_bal_type_title->setText(QApplication::translate("Customer_Master", "Bal.Type", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("Customer_Master", "  Owner:", 0, QApplication::UnicodeUTF8));
        lineEdit_reg_breadth->setText(QApplication::translate("Customer_Master", "99", 0, QApplication::UnicodeUTF8));
        radioButton_reg_bal_pending->setText(QApplication::translate("Customer_Master", "Pending(-)", 0, QApplication::UnicodeUTF8));
        lineEdit_reg_length->setText(QApplication::translate("Customer_Master", "99", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("Customer_Master", "x", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("Customer_Master", "LxB:", 0, QApplication::UnicodeUTF8));
        lineEdit_reg_opening_balance->setText(QString());
        pushButton_vehicle_esc->setText(QApplication::translate("Customer_Master", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_edit->setText(QApplication::translate("Customer_Master", "F2-Edit", 0, QApplication::UnicodeUTF8));
        pushButton_vehicle_save->setText(QApplication::translate("Customer_Master", "Save", 0, QApplication::UnicodeUTF8));
        lineEdit_vehicle_number->setText(QString());
        label_7->setText(QApplication::translate("Customer_Master", "Vehicle No:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Customer_Master", "Vehicle Master", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Customer_Master: public Ui_Customer_Master {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMER_MASTER_H
