/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created: Thu Jan 31 08:07:21 2019
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_settings_back;
    QSpacerItem *horizontalSpacer;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_config_menu;
    QPushButton *pushButton_App_name;
    QPushButton *pushButton_device_name;
    QPushButton *pushButton_user_master;
    QPushButton *pushButton_customer_master;
    QPushButton *pushButton_Bill_Title;
    QPushButton *pushButton_server_config;
    QPushButton *pushButton_device_setting;
    QPushButton *pushButton_printer_settings;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_Configuration;
    QLabel *label_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_domain_name;
    QPushButton *pushButton_save;
    QPushButton *pushButton_esc;

    void setupUi(QWidget *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QString::fromUtf8("Settings"));
        Settings->resize(320, 826);
        Settings->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 249, 249);"));
        groupBox = new QGroupBox(Settings);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 320, 501));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 320, 25));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 180, 300, 32));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_settings_back = new QPushButton(horizontalLayoutWidget);
        pushButton_settings_back->setObjectName(QString::fromUtf8("pushButton_settings_back"));
        pushButton_settings_back->setFont(font);
        pushButton_settings_back->setAutoDefault(true);
        pushButton_settings_back->setDefault(false);

        horizontalLayout->addWidget(pushButton_settings_back);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayoutWidget = new QWidget(Settings);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 30, 300, 280));
        verticalLayout_config_menu = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_config_menu->setObjectName(QString::fromUtf8("verticalLayout_config_menu"));
        verticalLayout_config_menu->setContentsMargins(50, 0, 50, 0);
        pushButton_App_name = new QPushButton(verticalLayoutWidget);
        pushButton_App_name->setObjectName(QString::fromUtf8("pushButton_App_name"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_App_name->setFont(font1);
        pushButton_App_name->setAutoDefault(true);
        pushButton_App_name->setDefault(false);

        verticalLayout_config_menu->addWidget(pushButton_App_name);

        pushButton_device_name = new QPushButton(verticalLayoutWidget);
        pushButton_device_name->setObjectName(QString::fromUtf8("pushButton_device_name"));
        pushButton_device_name->setFont(font1);
        pushButton_device_name->setAutoDefault(true);
        pushButton_device_name->setDefault(false);

        verticalLayout_config_menu->addWidget(pushButton_device_name);

        pushButton_user_master = new QPushButton(verticalLayoutWidget);
        pushButton_user_master->setObjectName(QString::fromUtf8("pushButton_user_master"));
        pushButton_user_master->setFont(font1);
        pushButton_user_master->setAutoDefault(true);
        pushButton_user_master->setDefault(false);

        verticalLayout_config_menu->addWidget(pushButton_user_master);

        pushButton_customer_master = new QPushButton(verticalLayoutWidget);
        pushButton_customer_master->setObjectName(QString::fromUtf8("pushButton_customer_master"));
        pushButton_customer_master->setFont(font1);
        pushButton_customer_master->setAutoDefault(true);
        pushButton_customer_master->setDefault(false);

        verticalLayout_config_menu->addWidget(pushButton_customer_master);

        pushButton_Bill_Title = new QPushButton(verticalLayoutWidget);
        pushButton_Bill_Title->setObjectName(QString::fromUtf8("pushButton_Bill_Title"));
        pushButton_Bill_Title->setFont(font1);
        pushButton_Bill_Title->setAutoDefault(true);
        pushButton_Bill_Title->setDefault(false);

        verticalLayout_config_menu->addWidget(pushButton_Bill_Title);

        pushButton_server_config = new QPushButton(verticalLayoutWidget);
        pushButton_server_config->setObjectName(QString::fromUtf8("pushButton_server_config"));
        pushButton_server_config->setFont(font1);
        pushButton_server_config->setAutoDefault(true);
        pushButton_server_config->setDefault(false);

        verticalLayout_config_menu->addWidget(pushButton_server_config);

        pushButton_device_setting = new QPushButton(verticalLayoutWidget);
        pushButton_device_setting->setObjectName(QString::fromUtf8("pushButton_device_setting"));
        pushButton_device_setting->setFont(font1);
        pushButton_device_setting->setAutoDefault(true);
        pushButton_device_setting->setDefault(false);

        verticalLayout_config_menu->addWidget(pushButton_device_setting);

        pushButton_printer_settings = new QPushButton(verticalLayoutWidget);
        pushButton_printer_settings->setObjectName(QString::fromUtf8("pushButton_printer_settings"));
        pushButton_printer_settings->setFont(font1);
        pushButton_printer_settings->setAutoDefault(true);
        pushButton_printer_settings->setDefault(false);

        verticalLayout_config_menu->addWidget(pushButton_printer_settings);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_config_menu->addItem(verticalSpacer);

        groupBox_Configuration = new QGroupBox(Settings);
        groupBox_Configuration->setObjectName(QString::fromUtf8("groupBox_Configuration"));
        groupBox_Configuration->setGeometry(QRect(0, 520, 320, 220));
        label_2 = new QLabel(groupBox_Configuration);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 320, 30));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget_2 = new QWidget(groupBox_Configuration);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 60, 300, 54));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        verticalLayout_2->addWidget(label_3);

        lineEdit_domain_name = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_domain_name->setObjectName(QString::fromUtf8("lineEdit_domain_name"));
        lineEdit_domain_name->setFont(font1);

        verticalLayout_2->addWidget(lineEdit_domain_name);

        pushButton_save = new QPushButton(groupBox_Configuration);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        pushButton_save->setGeometry(QRect(200, 185, 110, 30));
        pushButton_save->setFont(font1);
        pushButton_save->setAutoDefault(true);
        pushButton_save->setDefault(false);
        pushButton_esc = new QPushButton(groupBox_Configuration);
        pushButton_esc->setObjectName(QString::fromUtf8("pushButton_esc"));
        pushButton_esc->setGeometry(QRect(20, 185, 90, 30));
        pushButton_esc->setFont(font1);
        pushButton_esc->setAutoDefault(true);
        pushButton_esc->setDefault(false);
        QWidget::setTabOrder(pushButton_App_name, pushButton_device_name);
        QWidget::setTabOrder(pushButton_device_name, pushButton_user_master);
        QWidget::setTabOrder(pushButton_user_master, pushButton_customer_master);
        QWidget::setTabOrder(pushButton_customer_master, pushButton_Bill_Title);
        QWidget::setTabOrder(pushButton_Bill_Title, pushButton_server_config);
        QWidget::setTabOrder(pushButton_server_config, pushButton_device_setting);
        QWidget::setTabOrder(pushButton_device_setting, pushButton_printer_settings);
        QWidget::setTabOrder(pushButton_printer_settings, pushButton_settings_back);
        QWidget::setTabOrder(pushButton_settings_back, lineEdit_domain_name);
        QWidget::setTabOrder(lineEdit_domain_name, pushButton_save);
        QWidget::setTabOrder(pushButton_save, pushButton_esc);

        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QWidget *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("Settings", "Configuration", 0, QApplication::UnicodeUTF8));
        pushButton_settings_back->setText(QApplication::translate("Settings", "Esc-Menu", 0, QApplication::UnicodeUTF8));
        pushButton_App_name->setText(QApplication::translate("Settings", "Application Name", 0, QApplication::UnicodeUTF8));
        pushButton_device_name->setText(QApplication::translate("Settings", "Device Name", 0, QApplication::UnicodeUTF8));
        pushButton_user_master->setText(QApplication::translate("Settings", "User Master", 0, QApplication::UnicodeUTF8));
        pushButton_customer_master->setText(QApplication::translate("Settings", "Customer Master", 0, QApplication::UnicodeUTF8));
        pushButton_Bill_Title->setText(QApplication::translate("Settings", "Bill Title", 0, QApplication::UnicodeUTF8));
        pushButton_server_config->setText(QApplication::translate("Settings", "Server Config", 0, QApplication::UnicodeUTF8));
        pushButton_device_setting->setText(QApplication::translate("Settings", "Device Settings", 0, QApplication::UnicodeUTF8));
        pushButton_printer_settings->setText(QApplication::translate("Settings", "Printer Config", 0, QApplication::UnicodeUTF8));
        groupBox_Configuration->setTitle(QString());
        label_2->setText(QApplication::translate("Settings", "Configuration", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Settings", "Enter Domain Name:", 0, QApplication::UnicodeUTF8));
        pushButton_save->setText(QApplication::translate("Settings", "Enter-Save", 0, QApplication::UnicodeUTF8));
        pushButton_esc->setText(QApplication::translate("Settings", "Esc-Back", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
