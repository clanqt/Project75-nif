/********************************************************************************
** Form generated from reading UI file 'master_config_menu.ui'
**
** Created: Thu Jan 31 08:07:21 2019
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MASTER_CONFIG_MENU_H
#define UI_MASTER_CONFIG_MENU_H

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
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Master_Config_Menu
{
public:
    QGroupBox *groupBox_master_config_menu;
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_fuel;
    QPushButton *pushButton_Employee;
    QPushButton *pushButton_user_master;
    QPushButton *pushButton_expense;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_Customer;
    QPushButton *pushButton_app_config;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_back;
    QSpacerItem *horizontalSpacer_9;
    QGroupBox *groupBox_bunk_master;
    QLabel *label_2;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_back_2;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *pushButton_save;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QRadioButton *radioButton_pending;
    QLabel *label_4;
    QLabel *label_21;
    QLabel *label_5;
    QRadioButton *radioButton_advance;
    QLineEdit *lineEdit_opening_balance;
    QLineEdit *lineEdit_bunk_contact;
    QLineEdit *lineEdit_bunk_name;
    QGroupBox *groupBox_app_config;
    QLabel *label_6;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_2;
    QRadioButton *radioButton_hrs_on;
    QRadioButton *radioButton_hrs_off;
    QLabel *label_7;
    QGroupBox *groupBox;
    QRadioButton *radioButton_count_on;
    QRadioButton *radioButton_count_off;
    QLabel *label_8;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_back_app_config;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *pushButton_save_app_config;

    void setupUi(QWidget *Master_Config_Menu)
    {
        if (Master_Config_Menu->objectName().isEmpty())
            Master_Config_Menu->setObjectName(QString::fromUtf8("Master_Config_Menu"));
        Master_Config_Menu->resize(320, 660);
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font.setPointSize(12);
        Master_Config_Menu->setFont(font);
        groupBox_master_config_menu = new QGroupBox(Master_Config_Menu);
        groupBox_master_config_menu->setObjectName(QString::fromUtf8("groupBox_master_config_menu"));
        groupBox_master_config_menu->setGeometry(QRect(0, 0, 320, 220));
        label = new QLabel(groupBox_master_config_menu);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 320, 20));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        gridLayoutWidget = new QWidget(groupBox_master_config_menu);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 300, 176));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(50, 0, 50, 0);
        pushButton_fuel = new QPushButton(gridLayoutWidget);
        pushButton_fuel->setObjectName(QString::fromUtf8("pushButton_fuel"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        pushButton_fuel->setFont(font2);
        pushButton_fuel->setFocusPolicy(Qt::StrongFocus);
        pushButton_fuel->setStyleSheet(QString::fromUtf8("QPushButton:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        pushButton_fuel->setAutoDefault(true);

        gridLayout->addWidget(pushButton_fuel, 3, 0, 1, 1);

        pushButton_Employee = new QPushButton(gridLayoutWidget);
        pushButton_Employee->setObjectName(QString::fromUtf8("pushButton_Employee"));
        pushButton_Employee->setFont(font2);
        pushButton_Employee->setFocusPolicy(Qt::StrongFocus);
        pushButton_Employee->setStyleSheet(QString::fromUtf8("QPushButton:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        pushButton_Employee->setAutoDefault(true);

        gridLayout->addWidget(pushButton_Employee, 1, 0, 1, 1);

        pushButton_user_master = new QPushButton(gridLayoutWidget);
        pushButton_user_master->setObjectName(QString::fromUtf8("pushButton_user_master"));
        pushButton_user_master->setFont(font2);
        pushButton_user_master->setStyleSheet(QString::fromUtf8("QPushButton:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        pushButton_user_master->setAutoDefault(true);
        pushButton_user_master->setDefault(false);

        gridLayout->addWidget(pushButton_user_master, 2, 0, 1, 1);

        pushButton_expense = new QPushButton(gridLayoutWidget);
        pushButton_expense->setObjectName(QString::fromUtf8("pushButton_expense"));
        pushButton_expense->setFont(font2);
        pushButton_expense->setFocusPolicy(Qt::StrongFocus);
        pushButton_expense->setStyleSheet(QString::fromUtf8("QPushButton:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        pushButton_expense->setAutoDefault(true);

        gridLayout->addWidget(pushButton_expense, 4, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 6, 0, 1, 1);

        pushButton_Customer = new QPushButton(gridLayoutWidget);
        pushButton_Customer->setObjectName(QString::fromUtf8("pushButton_Customer"));
        pushButton_Customer->setFont(font2);
        pushButton_Customer->setFocusPolicy(Qt::StrongFocus);
        pushButton_Customer->setStyleSheet(QString::fromUtf8("QPushButton:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        pushButton_Customer->setAutoDefault(true);

        gridLayout->addWidget(pushButton_Customer, 0, 0, 1, 1);

        pushButton_app_config = new QPushButton(gridLayoutWidget);
        pushButton_app_config->setObjectName(QString::fromUtf8("pushButton_app_config"));
        pushButton_app_config->setFont(font2);
        pushButton_app_config->setFocusPolicy(Qt::StrongFocus);
        pushButton_app_config->setStyleSheet(QString::fromUtf8("QPushButton:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        pushButton_app_config->setAutoDefault(true);

        gridLayout->addWidget(pushButton_app_config, 5, 0, 1, 1);

        layoutWidget = new QWidget(groupBox_master_config_menu);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 191, 300, 29));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        pushButton_back = new QPushButton(layoutWidget);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));
        pushButton_back->setFont(font2);
        pushButton_back->setFocusPolicy(Qt::NoFocus);
        pushButton_back->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_back->setAutoDefault(true);

        horizontalLayout_5->addWidget(pushButton_back);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);

        groupBox_bunk_master = new QGroupBox(Master_Config_Menu);
        groupBox_bunk_master->setObjectName(QString::fromUtf8("groupBox_bunk_master"));
        groupBox_bunk_master->setGeometry(QRect(0, 220, 320, 220));
        label_2 = new QLabel(groupBox_bunk_master);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 320, 30));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        layoutWidget_2 = new QWidget(groupBox_bunk_master);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 180, 300, 29));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        pushButton_back_2 = new QPushButton(layoutWidget_2);
        pushButton_back_2->setObjectName(QString::fromUtf8("pushButton_back_2"));
        pushButton_back_2->setFont(font2);
        pushButton_back_2->setFocusPolicy(Qt::NoFocus);
        pushButton_back_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_back_2->setAutoDefault(true);

        horizontalLayout_6->addWidget(pushButton_back_2);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_10);

        pushButton_save = new QPushButton(layoutWidget_2);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        pushButton_save->setFont(font2);
        pushButton_save->setFocusPolicy(Qt::StrongFocus);
        pushButton_save->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_save->setAutoDefault(true);

        horizontalLayout_6->addWidget(pushButton_save);

        gridLayoutWidget_2 = new QWidget(groupBox_bunk_master);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 30, 300, 150));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(gridLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font3;
        font3.setBold(true);
        font3.setWeight(75);
        label_3->setFont(font3);

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 4, 0, 1, 1);

        radioButton_pending = new QRadioButton(gridLayoutWidget_2);
        radioButton_pending->setObjectName(QString::fromUtf8("radioButton_pending"));

        gridLayout_2->addWidget(radioButton_pending, 3, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font3);

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        label_21 = new QLabel(gridLayoutWidget_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setFont(font3);

        gridLayout_2->addWidget(label_21, 3, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font4;
        font4.setPointSize(11);
        font4.setBold(true);
        font4.setWeight(75);
        label_5->setFont(font4);

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        radioButton_advance = new QRadioButton(gridLayoutWidget_2);
        radioButton_advance->setObjectName(QString::fromUtf8("radioButton_advance"));

        gridLayout_2->addWidget(radioButton_advance, 3, 2, 1, 1);

        lineEdit_opening_balance = new QLineEdit(gridLayoutWidget_2);
        lineEdit_opening_balance->setObjectName(QString::fromUtf8("lineEdit_opening_balance"));
        lineEdit_opening_balance->setFont(font3);

        gridLayout_2->addWidget(lineEdit_opening_balance, 2, 1, 1, 2);

        lineEdit_bunk_contact = new QLineEdit(gridLayoutWidget_2);
        lineEdit_bunk_contact->setObjectName(QString::fromUtf8("lineEdit_bunk_contact"));

        gridLayout_2->addWidget(lineEdit_bunk_contact, 1, 1, 1, 2);

        lineEdit_bunk_name = new QLineEdit(gridLayoutWidget_2);
        lineEdit_bunk_name->setObjectName(QString::fromUtf8("lineEdit_bunk_name"));

        gridLayout_2->addWidget(lineEdit_bunk_name, 0, 1, 1, 2);

        groupBox_app_config = new QGroupBox(Master_Config_Menu);
        groupBox_app_config->setObjectName(QString::fromUtf8("groupBox_app_config"));
        groupBox_app_config->setGeometry(QRect(0, 440, 320, 220));
        label_6 = new QLabel(groupBox_app_config);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(0, 0, 320, 30));
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignCenter);
        gridLayoutWidget_3 = new QWidget(groupBox_app_config);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(10, 30, 300, 106));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        groupBox_2 = new QGroupBox(gridLayoutWidget_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QFont font5;
        font5.setPointSize(14);
        groupBox_2->setFont(font5);
        groupBox_2->setStyleSheet(QString::fromUtf8(""));
        radioButton_hrs_on = new QRadioButton(groupBox_2);
        radioButton_hrs_on->setObjectName(QString::fromUtf8("radioButton_hrs_on"));
        radioButton_hrs_on->setGeometry(QRect(0, 10, 51, 25));
        radioButton_hrs_on->setFont(font);
        radioButton_hrs_on->setChecked(true);
        radioButton_hrs_off = new QRadioButton(groupBox_2);
        radioButton_hrs_off->setObjectName(QString::fromUtf8("radioButton_hrs_off"));
        radioButton_hrs_off->setGeometry(QRect(60, 10, 50, 25));
        radioButton_hrs_off->setFont(font);

        gridLayout_3->addWidget(groupBox_2, 1, 1, 1, 1);

        label_7 = new QLabel(gridLayoutWidget_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font3);

        gridLayout_3->addWidget(label_7, 0, 0, 1, 1);

        groupBox = new QGroupBox(gridLayoutWidget_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setFont(font5);
        groupBox->setStyleSheet(QString::fromUtf8(""));
        radioButton_count_on = new QRadioButton(groupBox);
        radioButton_count_on->setObjectName(QString::fromUtf8("radioButton_count_on"));
        radioButton_count_on->setGeometry(QRect(0, 10, 51, 25));
        radioButton_count_on->setFont(font);
        radioButton_count_on->setChecked(true);
        radioButton_count_off = new QRadioButton(groupBox);
        radioButton_count_off->setObjectName(QString::fromUtf8("radioButton_count_off"));
        radioButton_count_off->setGeometry(QRect(60, 10, 50, 25));
        radioButton_count_off->setFont(font);

        gridLayout_3->addWidget(groupBox, 0, 1, 1, 1);

        label_8 = new QLabel(gridLayoutWidget_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font3);

        gridLayout_3->addWidget(label_8, 1, 0, 1, 1);

        layoutWidget_3 = new QWidget(groupBox_app_config);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 180, 300, 29));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        pushButton_back_app_config = new QPushButton(layoutWidget_3);
        pushButton_back_app_config->setObjectName(QString::fromUtf8("pushButton_back_app_config"));
        pushButton_back_app_config->setFont(font2);
        pushButton_back_app_config->setFocusPolicy(Qt::NoFocus);
        pushButton_back_app_config->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_back_app_config->setAutoDefault(true);

        horizontalLayout_7->addWidget(pushButton_back_app_config);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_11);

        pushButton_save_app_config = new QPushButton(layoutWidget_3);
        pushButton_save_app_config->setObjectName(QString::fromUtf8("pushButton_save_app_config"));
        pushButton_save_app_config->setFont(font2);
        pushButton_save_app_config->setFocusPolicy(Qt::StrongFocus);
        pushButton_save_app_config->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_save_app_config->setAutoDefault(true);

        horizontalLayout_7->addWidget(pushButton_save_app_config);

        QWidget::setTabOrder(pushButton_Customer, pushButton_Employee);
        QWidget::setTabOrder(pushButton_Employee, pushButton_user_master);
        QWidget::setTabOrder(pushButton_user_master, pushButton_fuel);
        QWidget::setTabOrder(pushButton_fuel, pushButton_expense);
        QWidget::setTabOrder(pushButton_expense, pushButton_app_config);
        QWidget::setTabOrder(pushButton_app_config, lineEdit_bunk_name);
        QWidget::setTabOrder(lineEdit_bunk_name, lineEdit_bunk_contact);
        QWidget::setTabOrder(lineEdit_bunk_contact, lineEdit_opening_balance);
        QWidget::setTabOrder(lineEdit_opening_balance, radioButton_pending);
        QWidget::setTabOrder(radioButton_pending, radioButton_advance);
        QWidget::setTabOrder(radioButton_advance, pushButton_save);
        QWidget::setTabOrder(pushButton_save, pushButton_save_app_config);

        retranslateUi(Master_Config_Menu);

        QMetaObject::connectSlotsByName(Master_Config_Menu);
    } // setupUi

    void retranslateUi(QWidget *Master_Config_Menu)
    {
        Master_Config_Menu->setWindowTitle(QApplication::translate("Master_Config_Menu", "Form", 0, QApplication::UnicodeUTF8));
        groupBox_master_config_menu->setTitle(QString());
        label->setText(QApplication::translate("Master_Config_Menu", "Master Configuration", 0, QApplication::UnicodeUTF8));
        pushButton_fuel->setText(QApplication::translate("Master_Config_Menu", "Bunk Master", 0, QApplication::UnicodeUTF8));
        pushButton_Employee->setText(QApplication::translate("Master_Config_Menu", "Employee Master", 0, QApplication::UnicodeUTF8));
        pushButton_user_master->setText(QApplication::translate("Master_Config_Menu", "User Master", 0, QApplication::UnicodeUTF8));
        pushButton_expense->setText(QApplication::translate("Master_Config_Menu", "Expense Master", 0, QApplication::UnicodeUTF8));
        pushButton_Customer->setText(QApplication::translate("Master_Config_Menu", "Supplier Master", 0, QApplication::UnicodeUTF8));
        pushButton_app_config->setText(QApplication::translate("Master_Config_Menu", "Application Config", 0, QApplication::UnicodeUTF8));
        pushButton_back->setText(QApplication::translate("Master_Config_Menu", "Esc-Back", 0, QApplication::UnicodeUTF8));
        groupBox_bunk_master->setTitle(QString());
        label_2->setText(QApplication::translate("Master_Config_Menu", "Bunk Master", 0, QApplication::UnicodeUTF8));
        pushButton_back_2->setText(QApplication::translate("Master_Config_Menu", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_save->setText(QApplication::translate("Master_Config_Menu", "Save", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Master_Config_Menu", "Bunk Name :", 0, QApplication::UnicodeUTF8));
        radioButton_pending->setText(QApplication::translate("Master_Config_Menu", "Pending", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Master_Config_Menu", "Contact   :", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("Master_Config_Menu", "Type:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Master_Config_Menu", "Op.Balance:", 0, QApplication::UnicodeUTF8));
        radioButton_advance->setText(QApplication::translate("Master_Config_Menu", "Advance", 0, QApplication::UnicodeUTF8));
        groupBox_app_config->setTitle(QString());
        label_6->setText(QApplication::translate("Master_Config_Menu", "Application Config", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QString());
        radioButton_hrs_on->setText(QApplication::translate("Master_Config_Menu", "ON", 0, QApplication::UnicodeUTF8));
        radioButton_hrs_off->setText(QApplication::translate("Master_Config_Menu", "OFF", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Master_Config_Menu", "Purchase In Count:", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        radioButton_count_on->setText(QApplication::translate("Master_Config_Menu", "ON", 0, QApplication::UnicodeUTF8));
        radioButton_count_off->setText(QApplication::translate("Master_Config_Menu", "OFF", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Master_Config_Menu", "Salary in Hrs    :", 0, QApplication::UnicodeUTF8));
        pushButton_back_app_config->setText(QApplication::translate("Master_Config_Menu", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_save_app_config->setText(QApplication::translate("Master_Config_Menu", "F1-Save", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Master_Config_Menu: public Ui_Master_Config_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MASTER_CONFIG_MENU_H
