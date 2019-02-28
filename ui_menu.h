/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created: Thu Jan 31 08:07:21 2019
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_21;
    QSpacerItem *horizontalSpacer;
    QLabel *label_22;
    QLabel *label_info;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_payment;
    QPushButton *pushButton_Other_batch_close;
    QPushButton *pushButton_Configuration;
    QPushButton *pushButton_upload;
    QPushButton *pushButton_Day_Open;
    QPushButton *pushButton_download;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_Reset_Data;
    QPushButton *pushButton_Day_Close;
    QPushButton *pushButton_diesel;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_Shift_Close;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_Reports;
    QPushButton *pushButton_batch_config;
    QPushButton *pushButton_Data_transfer;
    QPushButton *pushButton_Receipt;
    QPushButton *pushButton_master_config;
    QPushButton *pushButton_purchase;
    QPushButton *pushButton_rate_config;
    QPushButton *pushButton_input_config;
    QPushButton *pushButton_device_setting;
    QPushButton *pushButton_Void_Last_Bill;
    QGroupBox *groupBox_download;
    QLabel *label_name;
    QProgressBar *progressBar;
    QPushButton *pushButton;

    void setupUi(QWidget *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QString::fromUtf8("Menu"));
        Menu->resize(320, 1388);
        Menu->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 249, 249);"));
        groupBox = new QGroupBox(Menu);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 320, 1361));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 320, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 190, 300, 30));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 0, 5, 0);
        label_21 = new QLabel(horizontalLayoutWidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label_21->setFont(font1);
        label_21->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_21);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_22 = new QLabel(horizontalLayoutWidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setFont(font1);
        label_22->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_22);

        label_info = new QLabel(groupBox);
        label_info->setObjectName(QString::fromUtf8("label_info"));
        label_info->setGeometry(QRect(10, 40, 303, 130));
        label_info->setFont(font1);
        label_info->setStyleSheet(QString::fromUtf8("background-color: rgb(183, 255, 251);\n"
"color: rgb(177, 19, 66);"));
        label_info->setAlignment(Qt::AlignCenter);
        label_info->setWordWrap(true);
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 30, 300, 1302));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_payment = new QPushButton(gridLayoutWidget);
        pushButton_payment->setObjectName(QString::fromUtf8("pushButton_payment"));
        pushButton_payment->setFont(font);
        pushButton_payment->setFocusPolicy(Qt::StrongFocus);
        pushButton_payment->setStyleSheet(QString::fromUtf8("Text-align:left"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/payment.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_payment->setIcon(icon);
        pushButton_payment->setIconSize(QSize(60, 60));
        pushButton_payment->setAutoDefault(true);

        gridLayout->addWidget(pushButton_payment, 6, 1, 1, 1);

        pushButton_Other_batch_close = new QPushButton(gridLayoutWidget);
        pushButton_Other_batch_close->setObjectName(QString::fromUtf8("pushButton_Other_batch_close"));
        pushButton_Other_batch_close->setFont(font);
        pushButton_Other_batch_close->setAutoDefault(true);
        pushButton_Other_batch_close->setDefault(false);

        gridLayout->addWidget(pushButton_Other_batch_close, 14, 1, 1, 1);

        pushButton_Configuration = new QPushButton(gridLayoutWidget);
        pushButton_Configuration->setObjectName(QString::fromUtf8("pushButton_Configuration"));
        pushButton_Configuration->setFont(font);
        pushButton_Configuration->setStyleSheet(QString::fromUtf8("Text-align:left"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/system_settings.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Configuration->setIcon(icon1);
        pushButton_Configuration->setIconSize(QSize(60, 60));
        pushButton_Configuration->setAutoDefault(true);
        pushButton_Configuration->setDefault(false);

        gridLayout->addWidget(pushButton_Configuration, 21, 1, 1, 1);

        pushButton_upload = new QPushButton(gridLayoutWidget);
        pushButton_upload->setObjectName(QString::fromUtf8("pushButton_upload"));
        pushButton_upload->setFont(font);
        pushButton_upload->setAutoDefault(true);
        pushButton_upload->setDefault(false);

        gridLayout->addWidget(pushButton_upload, 18, 1, 1, 1);

        pushButton_Day_Open = new QPushButton(gridLayoutWidget);
        pushButton_Day_Open->setObjectName(QString::fromUtf8("pushButton_Day_Open"));
        pushButton_Day_Open->setFont(font);
        pushButton_Day_Open->setStyleSheet(QString::fromUtf8("Text-align:left"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/day_open.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Day_Open->setIcon(icon2);
        pushButton_Day_Open->setIconSize(QSize(60, 60));
        pushButton_Day_Open->setAutoDefault(true);
        pushButton_Day_Open->setDefault(false);

        gridLayout->addWidget(pushButton_Day_Open, 8, 1, 1, 1);

        pushButton_download = new QPushButton(gridLayoutWidget);
        pushButton_download->setObjectName(QString::fromUtf8("pushButton_download"));
        pushButton_download->setFont(font);
        pushButton_download->setAutoDefault(true);
        pushButton_download->setDefault(false);

        gridLayout->addWidget(pushButton_download, 17, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 24, 1, 1, 1);

        pushButton_Reset_Data = new QPushButton(gridLayoutWidget);
        pushButton_Reset_Data->setObjectName(QString::fromUtf8("pushButton_Reset_Data"));
        pushButton_Reset_Data->setFont(font);
        pushButton_Reset_Data->setStyleSheet(QString::fromUtf8("Text-align:left"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/Refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Reset_Data->setIcon(icon3);
        pushButton_Reset_Data->setIconSize(QSize(60, 60));
        pushButton_Reset_Data->setAutoDefault(true);
        pushButton_Reset_Data->setDefault(false);

        gridLayout->addWidget(pushButton_Reset_Data, 23, 1, 1, 1);

        pushButton_Day_Close = new QPushButton(gridLayoutWidget);
        pushButton_Day_Close->setObjectName(QString::fromUtf8("pushButton_Day_Close"));
        pushButton_Day_Close->setFont(font);
        pushButton_Day_Close->setStyleSheet(QString::fromUtf8("Text-align:left"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/day_close.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Day_Close->setIcon(icon4);
        pushButton_Day_Close->setIconSize(QSize(60, 60));
        pushButton_Day_Close->setAutoDefault(true);
        pushButton_Day_Close->setDefault(false);

        gridLayout->addWidget(pushButton_Day_Close, 9, 1, 1, 1);

        pushButton_diesel = new QPushButton(gridLayoutWidget);
        pushButton_diesel->setObjectName(QString::fromUtf8("pushButton_diesel"));
        pushButton_diesel->setFont(font);
        pushButton_diesel->setStyleSheet(QString::fromUtf8("Text-align:left"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/bunk.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_diesel->setIcon(icon5);
        pushButton_diesel->setIconSize(QSize(60, 60));
        pushButton_diesel->setAutoDefault(true);
        pushButton_diesel->setDefault(false);

        gridLayout->addWidget(pushButton_diesel, 4, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        pushButton_Shift_Close = new QPushButton(gridLayoutWidget);
        pushButton_Shift_Close->setObjectName(QString::fromUtf8("pushButton_Shift_Close"));
        pushButton_Shift_Close->setFont(font);
        pushButton_Shift_Close->setAutoDefault(true);
        pushButton_Shift_Close->setDefault(false);

        gridLayout->addWidget(pushButton_Shift_Close, 13, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        pushButton_Reports = new QPushButton(gridLayoutWidget);
        pushButton_Reports->setObjectName(QString::fromUtf8("pushButton_Reports"));
        pushButton_Reports->setFont(font);
        pushButton_Reports->setStyleSheet(QString::fromUtf8("Text-align:left"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/report_edit.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Reports->setIcon(icon6);
        pushButton_Reports->setIconSize(QSize(60, 60));
        pushButton_Reports->setAutoDefault(true);
        pushButton_Reports->setDefault(false);

        gridLayout->addWidget(pushButton_Reports, 10, 1, 1, 1);

        pushButton_batch_config = new QPushButton(gridLayoutWidget);
        pushButton_batch_config->setObjectName(QString::fromUtf8("pushButton_batch_config"));
        pushButton_batch_config->setFont(font);
        pushButton_batch_config->setStyleSheet(QString::fromUtf8("Text-align:left;"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/batch.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_batch_config->setIcon(icon7);
        pushButton_batch_config->setIconSize(QSize(60, 60));
        pushButton_batch_config->setAutoDefault(true);
        pushButton_batch_config->setDefault(false);

        gridLayout->addWidget(pushButton_batch_config, 1, 1, 1, 1);

        pushButton_Data_transfer = new QPushButton(gridLayoutWidget);
        pushButton_Data_transfer->setObjectName(QString::fromUtf8("pushButton_Data_transfer"));
        pushButton_Data_transfer->setFont(font);
        pushButton_Data_transfer->setStyleSheet(QString::fromUtf8("Text-align:left"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/data_transfer.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Data_transfer->setIcon(icon8);
        pushButton_Data_transfer->setIconSize(QSize(60, 60));
        pushButton_Data_transfer->setAutoDefault(true);
        pushButton_Data_transfer->setDefault(false);

        gridLayout->addWidget(pushButton_Data_transfer, 22, 1, 1, 1);

        pushButton_Receipt = new QPushButton(gridLayoutWidget);
        pushButton_Receipt->setObjectName(QString::fromUtf8("pushButton_Receipt"));
        pushButton_Receipt->setFont(font);
        pushButton_Receipt->setFocusPolicy(Qt::StrongFocus);
        pushButton_Receipt->setStyleSheet(QString::fromUtf8("Text-align:left"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons/cash_in.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Receipt->setIcon(icon9);
        pushButton_Receipt->setIconSize(QSize(60, 60));
        pushButton_Receipt->setAutoDefault(true);

        gridLayout->addWidget(pushButton_Receipt, 7, 1, 1, 1);

        pushButton_master_config = new QPushButton(gridLayoutWidget);
        pushButton_master_config->setObjectName(QString::fromUtf8("pushButton_master_config"));
        pushButton_master_config->setFont(font);
        pushButton_master_config->setStyleSheet(QString::fromUtf8("Text-align:left;"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icons/master_config.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_master_config->setIcon(icon10);
        pushButton_master_config->setIconSize(QSize(60, 60));
        pushButton_master_config->setAutoDefault(true);
        pushButton_master_config->setDefault(false);

        gridLayout->addWidget(pushButton_master_config, 0, 1, 1, 1);

        pushButton_purchase = new QPushButton(gridLayoutWidget);
        pushButton_purchase->setObjectName(QString::fromUtf8("pushButton_purchase"));
        pushButton_purchase->setFont(font);
        pushButton_purchase->setFocusPolicy(Qt::StrongFocus);
        pushButton_purchase->setStyleSheet(QString::fromUtf8("Text-align:left"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icons/coconut.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_purchase->setIcon(icon11);
        pushButton_purchase->setIconSize(QSize(60, 60));
        pushButton_purchase->setAutoDefault(true);

        gridLayout->addWidget(pushButton_purchase, 5, 1, 1, 1);

        pushButton_rate_config = new QPushButton(gridLayoutWidget);
        pushButton_rate_config->setObjectName(QString::fromUtf8("pushButton_rate_config"));
        pushButton_rate_config->setFont(font);
        pushButton_rate_config->setStyleSheet(QString::fromUtf8("Text-align:left"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/icons/rate_settings.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_rate_config->setIcon(icon12);
        pushButton_rate_config->setIconSize(QSize(60, 60));
        pushButton_rate_config->setAutoDefault(true);
        pushButton_rate_config->setDefault(false);

        gridLayout->addWidget(pushButton_rate_config, 3, 1, 1, 1);

        pushButton_input_config = new QPushButton(gridLayoutWidget);
        pushButton_input_config->setObjectName(QString::fromUtf8("pushButton_input_config"));
        pushButton_input_config->setFont(font);
        pushButton_input_config->setStyleSheet(QString::fromUtf8("Text-align:left"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/icons/input.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_input_config->setIcon(icon13);
        pushButton_input_config->setIconSize(QSize(60, 60));
        pushButton_input_config->setAutoDefault(true);
        pushButton_input_config->setDefault(false);

        gridLayout->addWidget(pushButton_input_config, 2, 1, 1, 1);

        pushButton_device_setting = new QPushButton(gridLayoutWidget);
        pushButton_device_setting->setObjectName(QString::fromUtf8("pushButton_device_setting"));
        pushButton_device_setting->setFont(font);
        pushButton_device_setting->setStyleSheet(QString::fromUtf8("Text-align:left"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/icons/system_settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_device_setting->setIcon(icon14);
        pushButton_device_setting->setIconSize(QSize(60, 60));
        pushButton_device_setting->setAutoDefault(true);
        pushButton_device_setting->setDefault(false);

        gridLayout->addWidget(pushButton_device_setting, 20, 1, 1, 1);

        pushButton_Void_Last_Bill = new QPushButton(gridLayoutWidget);
        pushButton_Void_Last_Bill->setObjectName(QString::fromUtf8("pushButton_Void_Last_Bill"));
        pushButton_Void_Last_Bill->setFont(font);
        pushButton_Void_Last_Bill->setStyleSheet(QString::fromUtf8("Text-align:left"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/icons/void_bill.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Void_Last_Bill->setIcon(icon15);
        pushButton_Void_Last_Bill->setIconSize(QSize(60, 60));
        pushButton_Void_Last_Bill->setAutoDefault(true);
        pushButton_Void_Last_Bill->setDefault(false);

        gridLayout->addWidget(pushButton_Void_Last_Bill, 19, 1, 1, 1);

        label_info->raise();
        label->raise();
        horizontalLayoutWidget->raise();
        gridLayoutWidget->raise();
        groupBox_download = new QGroupBox(Menu);
        groupBox_download->setObjectName(QString::fromUtf8("groupBox_download"));
        groupBox_download->setGeometry(QRect(10, 30, 301, 160));
        groupBox_download->setFont(font);
        groupBox_download->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_name = new QLabel(groupBox_download);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(10, 30, 281, 61));
        label_name->setFont(font1);
        label_name->setAlignment(Qt::AlignCenter);
        label_name->setWordWrap(true);
        progressBar = new QProgressBar(groupBox_download);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(10, 90, 281, 28));
        progressBar->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        progressBar->setValue(0);
        pushButton = new QPushButton(groupBox_download);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(180, 120, 111, 31));
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton->setAutoDefault(true);
        groupBox_download->raise();
        groupBox->raise();
        QWidget::setTabOrder(pushButton_master_config, pushButton_batch_config);
        QWidget::setTabOrder(pushButton_batch_config, pushButton_input_config);
        QWidget::setTabOrder(pushButton_input_config, pushButton_rate_config);
        QWidget::setTabOrder(pushButton_rate_config, pushButton_diesel);
        QWidget::setTabOrder(pushButton_diesel, pushButton_purchase);
        QWidget::setTabOrder(pushButton_purchase, pushButton_payment);
        QWidget::setTabOrder(pushButton_payment, pushButton_Receipt);
        QWidget::setTabOrder(pushButton_Receipt, pushButton_Day_Open);
        QWidget::setTabOrder(pushButton_Day_Open, pushButton_Day_Close);
        QWidget::setTabOrder(pushButton_Day_Close, pushButton_Reports);
        QWidget::setTabOrder(pushButton_Reports, pushButton_Shift_Close);
        QWidget::setTabOrder(pushButton_Shift_Close, pushButton_Other_batch_close);
        QWidget::setTabOrder(pushButton_Other_batch_close, pushButton_download);
        QWidget::setTabOrder(pushButton_download, pushButton_upload);
        QWidget::setTabOrder(pushButton_upload, pushButton_Void_Last_Bill);
        QWidget::setTabOrder(pushButton_Void_Last_Bill, pushButton_device_setting);
        QWidget::setTabOrder(pushButton_device_setting, pushButton_Configuration);
        QWidget::setTabOrder(pushButton_Configuration, pushButton_Data_transfer);
        QWidget::setTabOrder(pushButton_Data_transfer, pushButton_Reset_Data);
        QWidget::setTabOrder(pushButton_Reset_Data, pushButton);

        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QWidget *Menu)
    {
        Menu->setWindowTitle(QApplication::translate("Menu", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("Menu", "Menu", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("Menu", "Esc-Logout", 0, QApplication::UnicodeUTF8));
        label_22->setText(QString());
        label_info->setText(QApplication::translate("Menu", "Downloading Database...", 0, QApplication::UnicodeUTF8));
        pushButton_payment->setText(QApplication::translate("Menu", "Payment", 0, QApplication::UnicodeUTF8));
        pushButton_Other_batch_close->setText(QApplication::translate("Menu", "Other Batch Close", 0, QApplication::UnicodeUTF8));
        pushButton_Configuration->setText(QApplication::translate("Menu", "Configuration", 0, QApplication::UnicodeUTF8));
        pushButton_upload->setText(QApplication::translate("Menu", "Upload", 0, QApplication::UnicodeUTF8));
        pushButton_Day_Open->setText(QApplication::translate("Menu", "Day Open", 0, QApplication::UnicodeUTF8));
        pushButton_download->setText(QApplication::translate("Menu", "Download", 0, QApplication::UnicodeUTF8));
        pushButton_Reset_Data->setText(QApplication::translate("Menu", "Reset Transactions", 0, QApplication::UnicodeUTF8));
        pushButton_Day_Close->setText(QApplication::translate("Menu", "Day Close", 0, QApplication::UnicodeUTF8));
        pushButton_diesel->setText(QApplication::translate("Menu", "Diesel Maintenance", 0, QApplication::UnicodeUTF8));
        pushButton_Shift_Close->setText(QApplication::translate("Menu", "Company Batch Close", 0, QApplication::UnicodeUTF8));
        pushButton_Reports->setText(QApplication::translate("Menu", "Reports", 0, QApplication::UnicodeUTF8));
        pushButton_batch_config->setText(QApplication::translate("Menu", "Batch Config", 0, QApplication::UnicodeUTF8));
        pushButton_Data_transfer->setText(QApplication::translate("Menu", "Data Transfer", 0, QApplication::UnicodeUTF8));
        pushButton_Receipt->setText(QApplication::translate("Menu", "Receipt", 0, QApplication::UnicodeUTF8));
        pushButton_master_config->setText(QApplication::translate("Menu", "Master Config", 0, QApplication::UnicodeUTF8));
        pushButton_purchase->setText(QApplication::translate("Menu", "Purchase", 0, QApplication::UnicodeUTF8));
        pushButton_rate_config->setText(QApplication::translate("Menu", "Rate Config", 0, QApplication::UnicodeUTF8));
        pushButton_input_config->setText(QApplication::translate("Menu", "Input Config", 0, QApplication::UnicodeUTF8));
        pushButton_device_setting->setText(QApplication::translate("Menu", "Device Setting", 0, QApplication::UnicodeUTF8));
        pushButton_Void_Last_Bill->setText(QApplication::translate("Menu", "Void Last Bill", 0, QApplication::UnicodeUTF8));
        groupBox_download->setTitle(QApplication::translate("Menu", "Downloading", 0, QApplication::UnicodeUTF8));
        label_name->setText(QApplication::translate("Menu", "Downloading Header...", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Menu", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
