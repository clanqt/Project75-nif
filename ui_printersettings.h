/********************************************************************************
** Form generated from reading UI file 'printersettings.ui'
**
** Created: Thu Jan 31 08:07:21 2019
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINTERSETTINGS_H
#define UI_PRINTERSETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
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
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PrinterSettings
{
public:
    QGroupBox *groupBox_Header;
    QLabel *label_2;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLabel *label_header_char_info;
    QRadioButton *radioButton_H_small;
    QLabel *label_6;
    QPushButton *pushButton_H_on;
    QRadioButton *radioButton_H_big;
    QCheckBox *checkBox_H_bold;
    QRadioButton *radioButton_H_medium;
    QLineEdit *lineEdit_header;
    QPushButton *pushButton_H_off;
    QComboBox *comboBox_heade_line;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_H_back;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_H_save;
    QGroupBox *groupBox_footer;
    QLabel *label_4;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_F_on;
    QLabel *label_7;
    QPushButton *pushButton_F_off;
    QRadioButton *radioButton_F_big;
    QLabel *label_8;
    QSpacerItem *verticalSpacer_3;
    QRadioButton *radioButton_F_small;
    QRadioButton *radioButton_F_medium;
    QCheckBox *checkBox_F_bold;
    QComboBox *comboBox_F_line;
    QLineEdit *lineEdit_footer;
    QLabel *label_footer_char_info;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_F_back;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_F_save;
    QGroupBox *groupBox_menu;
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_header_setting;
    QPushButton *pushButton_footer_setting;
    QPushButton *pushButton_font_type;
    QSpacerItem *verticalSpacer;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_printer_settings_back;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *PrinterSettings)
    {
        if (PrinterSettings->objectName().isEmpty())
            PrinterSettings->setObjectName(QString::fromUtf8("PrinterSettings"));
        PrinterSettings->resize(320, 686);
        PrinterSettings->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 249, 249);"));
        groupBox_Header = new QGroupBox(PrinterSettings);
        groupBox_Header->setObjectName(QString::fromUtf8("groupBox_Header"));
        groupBox_Header->setGeometry(QRect(0, 230, 320, 220));
        label_2 = new QLabel(groupBox_Header);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 320, 25));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        gridLayoutWidget = new QWidget(groupBox_Header);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 30, 300, 157));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label_5->setFont(font1);

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        label_header_char_info = new QLabel(gridLayoutWidget);
        label_header_char_info->setObjectName(QString::fromUtf8("label_header_char_info"));
        label_header_char_info->setFont(font1);
        label_header_char_info->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_header_char_info, 5, 2, 1, 1);

        radioButton_H_small = new QRadioButton(gridLayoutWidget);
        radioButton_H_small->setObjectName(QString::fromUtf8("radioButton_H_small"));
        radioButton_H_small->setFont(font1);
        radioButton_H_small->setChecked(true);

        gridLayout->addWidget(radioButton_H_small, 3, 1, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        pushButton_H_on = new QPushButton(gridLayoutWidget);
        pushButton_H_on->setObjectName(QString::fromUtf8("pushButton_H_on"));
        pushButton_H_on->setFont(font1);
        pushButton_H_on->setAutoDefault(true);

        gridLayout->addWidget(pushButton_H_on, 0, 1, 1, 1);

        radioButton_H_big = new QRadioButton(gridLayoutWidget);
        radioButton_H_big->setObjectName(QString::fromUtf8("radioButton_H_big"));
        radioButton_H_big->setFont(font1);

        gridLayout->addWidget(radioButton_H_big, 4, 1, 1, 1);

        checkBox_H_bold = new QCheckBox(gridLayoutWidget);
        checkBox_H_bold->setObjectName(QString::fromUtf8("checkBox_H_bold"));
        checkBox_H_bold->setFont(font1);

        gridLayout->addWidget(checkBox_H_bold, 4, 2, 1, 1);

        radioButton_H_medium = new QRadioButton(gridLayoutWidget);
        radioButton_H_medium->setObjectName(QString::fromUtf8("radioButton_H_medium"));
        radioButton_H_medium->setFont(font1);

        gridLayout->addWidget(radioButton_H_medium, 3, 2, 1, 1);

        lineEdit_header = new QLineEdit(gridLayoutWidget);
        lineEdit_header->setObjectName(QString::fromUtf8("lineEdit_header"));
        lineEdit_header->setFont(font1);
        lineEdit_header->setMaxLength(38);

        gridLayout->addWidget(lineEdit_header, 5, 0, 1, 2);

        pushButton_H_off = new QPushButton(gridLayoutWidget);
        pushButton_H_off->setObjectName(QString::fromUtf8("pushButton_H_off"));
        pushButton_H_off->setFont(font1);
        pushButton_H_off->setAutoDefault(true);

        gridLayout->addWidget(pushButton_H_off, 0, 2, 1, 1);

        comboBox_heade_line = new QComboBox(gridLayoutWidget);
        comboBox_heade_line->setObjectName(QString::fromUtf8("comboBox_heade_line"));
        comboBox_heade_line->setFont(font1);

        gridLayout->addWidget(comboBox_heade_line, 1, 1, 1, 2);

        horizontalLayoutWidget_2 = new QWidget(groupBox_Header);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 180, 300, 30));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_H_back = new QPushButton(horizontalLayoutWidget_2);
        pushButton_H_back->setObjectName(QString::fromUtf8("pushButton_H_back"));
        pushButton_H_back->setFont(font1);
        pushButton_H_back->setAutoDefault(true);

        horizontalLayout_2->addWidget(pushButton_H_back);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_H_save = new QPushButton(horizontalLayoutWidget_2);
        pushButton_H_save->setObjectName(QString::fromUtf8("pushButton_H_save"));
        pushButton_H_save->setFont(font1);
        pushButton_H_save->setAutoDefault(true);

        horizontalLayout_2->addWidget(pushButton_H_save);

        groupBox_footer = new QGroupBox(PrinterSettings);
        groupBox_footer->setObjectName(QString::fromUtf8("groupBox_footer"));
        groupBox_footer->setGeometry(QRect(0, 450, 320, 220));
        label_4 = new QLabel(groupBox_footer);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 0, 320, 25));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);
        gridLayoutWidget_2 = new QWidget(groupBox_footer);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 30, 300, 163));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_F_on = new QPushButton(gridLayoutWidget_2);
        pushButton_F_on->setObjectName(QString::fromUtf8("pushButton_F_on"));
        pushButton_F_on->setFont(font1);
        pushButton_F_on->setAutoDefault(true);

        gridLayout_2->addWidget(pushButton_F_on, 0, 1, 1, 1);

        label_7 = new QLabel(gridLayoutWidget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);

        gridLayout_2->addWidget(label_7, 2, 0, 1, 1);

        pushButton_F_off = new QPushButton(gridLayoutWidget_2);
        pushButton_F_off->setObjectName(QString::fromUtf8("pushButton_F_off"));
        pushButton_F_off->setFont(font1);
        pushButton_F_off->setAutoDefault(true);

        gridLayout_2->addWidget(pushButton_F_off, 0, 2, 1, 1);

        radioButton_F_big = new QRadioButton(gridLayoutWidget_2);
        radioButton_F_big->setObjectName(QString::fromUtf8("radioButton_F_big"));
        radioButton_F_big->setFont(font1);

        gridLayout_2->addWidget(radioButton_F_big, 3, 1, 1, 1);

        label_8 = new QLabel(gridLayoutWidget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font1);

        gridLayout_2->addWidget(label_8, 0, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 5, 0, 1, 1);

        radioButton_F_small = new QRadioButton(gridLayoutWidget_2);
        radioButton_F_small->setObjectName(QString::fromUtf8("radioButton_F_small"));
        radioButton_F_small->setFont(font1);
        radioButton_F_small->setChecked(true);

        gridLayout_2->addWidget(radioButton_F_small, 2, 1, 1, 1);

        radioButton_F_medium = new QRadioButton(gridLayoutWidget_2);
        radioButton_F_medium->setObjectName(QString::fromUtf8("radioButton_F_medium"));
        radioButton_F_medium->setFont(font1);

        gridLayout_2->addWidget(radioButton_F_medium, 2, 2, 1, 1);

        checkBox_F_bold = new QCheckBox(gridLayoutWidget_2);
        checkBox_F_bold->setObjectName(QString::fromUtf8("checkBox_F_bold"));
        checkBox_F_bold->setFont(font1);

        gridLayout_2->addWidget(checkBox_F_bold, 3, 2, 1, 1);

        comboBox_F_line = new QComboBox(gridLayoutWidget_2);
        comboBox_F_line->setObjectName(QString::fromUtf8("comboBox_F_line"));
        comboBox_F_line->setFont(font1);

        gridLayout_2->addWidget(comboBox_F_line, 1, 1, 1, 2);

        lineEdit_footer = new QLineEdit(gridLayoutWidget_2);
        lineEdit_footer->setObjectName(QString::fromUtf8("lineEdit_footer"));
        lineEdit_footer->setFont(font1);
        lineEdit_footer->setMaxLength(38);

        gridLayout_2->addWidget(lineEdit_footer, 4, 0, 1, 2);

        label_footer_char_info = new QLabel(gridLayoutWidget_2);
        label_footer_char_info->setObjectName(QString::fromUtf8("label_footer_char_info"));
        label_footer_char_info->setFont(font1);
        label_footer_char_info->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_footer_char_info, 4, 2, 1, 1);

        horizontalLayoutWidget_3 = new QWidget(groupBox_footer);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 180, 300, 30));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_F_back = new QPushButton(horizontalLayoutWidget_3);
        pushButton_F_back->setObjectName(QString::fromUtf8("pushButton_F_back"));
        pushButton_F_back->setFont(font1);
        pushButton_F_back->setAutoDefault(true);

        horizontalLayout_3->addWidget(pushButton_F_back);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButton_F_save = new QPushButton(horizontalLayoutWidget_3);
        pushButton_F_save->setObjectName(QString::fromUtf8("pushButton_F_save"));
        pushButton_F_save->setFont(font1);
        pushButton_F_save->setAutoDefault(true);

        horizontalLayout_3->addWidget(pushButton_F_save);

        groupBox_menu = new QGroupBox(PrinterSettings);
        groupBox_menu->setObjectName(QString::fromUtf8("groupBox_menu"));
        groupBox_menu->setGeometry(QRect(0, 0, 320, 220));
        label = new QLabel(groupBox_menu);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 320, 25));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget = new QWidget(groupBox_menu);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 30, 300, 150));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(75, 0, 75, 0);
        pushButton_header_setting = new QPushButton(verticalLayoutWidget);
        pushButton_header_setting->setObjectName(QString::fromUtf8("pushButton_header_setting"));
        pushButton_header_setting->setFont(font1);
        pushButton_header_setting->setAutoDefault(true);

        verticalLayout->addWidget(pushButton_header_setting);

        pushButton_footer_setting = new QPushButton(verticalLayoutWidget);
        pushButton_footer_setting->setObjectName(QString::fromUtf8("pushButton_footer_setting"));
        pushButton_footer_setting->setFont(font1);
        pushButton_footer_setting->setAutoDefault(true);

        verticalLayout->addWidget(pushButton_footer_setting);

        pushButton_font_type = new QPushButton(verticalLayoutWidget);
        pushButton_font_type->setObjectName(QString::fromUtf8("pushButton_font_type"));
        pushButton_font_type->setFont(font1);
        pushButton_font_type->setAutoDefault(true);

        verticalLayout->addWidget(pushButton_font_type);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayoutWidget = new QWidget(groupBox_menu);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 180, 300, 30));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_printer_settings_back = new QPushButton(horizontalLayoutWidget);
        pushButton_printer_settings_back->setObjectName(QString::fromUtf8("pushButton_printer_settings_back"));
        pushButton_printer_settings_back->setFont(font1);
        pushButton_printer_settings_back->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_printer_settings_back);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        QWidget::setTabOrder(pushButton_header_setting, pushButton_footer_setting);
        QWidget::setTabOrder(pushButton_footer_setting, pushButton_font_type);
        QWidget::setTabOrder(pushButton_font_type, pushButton_printer_settings_back);
        QWidget::setTabOrder(pushButton_printer_settings_back, pushButton_H_on);
        QWidget::setTabOrder(pushButton_H_on, pushButton_H_off);
        QWidget::setTabOrder(pushButton_H_off, comboBox_heade_line);
        QWidget::setTabOrder(comboBox_heade_line, radioButton_H_small);
        QWidget::setTabOrder(radioButton_H_small, radioButton_H_medium);
        QWidget::setTabOrder(radioButton_H_medium, radioButton_H_big);
        QWidget::setTabOrder(radioButton_H_big, checkBox_H_bold);
        QWidget::setTabOrder(checkBox_H_bold, lineEdit_header);
        QWidget::setTabOrder(lineEdit_header, pushButton_H_save);
        QWidget::setTabOrder(pushButton_H_save, pushButton_H_back);
        QWidget::setTabOrder(pushButton_H_back, pushButton_F_on);
        QWidget::setTabOrder(pushButton_F_on, pushButton_F_off);
        QWidget::setTabOrder(pushButton_F_off, comboBox_F_line);
        QWidget::setTabOrder(comboBox_F_line, radioButton_F_small);
        QWidget::setTabOrder(radioButton_F_small, radioButton_F_medium);
        QWidget::setTabOrder(radioButton_F_medium, radioButton_F_big);
        QWidget::setTabOrder(radioButton_F_big, checkBox_F_bold);
        QWidget::setTabOrder(checkBox_F_bold, lineEdit_footer);
        QWidget::setTabOrder(lineEdit_footer, pushButton_F_save);
        QWidget::setTabOrder(pushButton_F_save, pushButton_F_back);

        retranslateUi(PrinterSettings);

        QMetaObject::connectSlotsByName(PrinterSettings);
    } // setupUi

    void retranslateUi(QWidget *PrinterSettings)
    {
        PrinterSettings->setWindowTitle(QApplication::translate("PrinterSettings", "Form", 0, QApplication::UnicodeUTF8));
        groupBox_Header->setTitle(QString());
        label_2->setText(QApplication::translate("PrinterSettings", "Header Settings", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("PrinterSettings", "Header:", 0, QApplication::UnicodeUTF8));
        label_header_char_info->setText(QApplication::translate("PrinterSettings", "(38 char)", 0, QApplication::UnicodeUTF8));
        radioButton_H_small->setText(QApplication::translate("PrinterSettings", "Small", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("PrinterSettings", "Font size:", 0, QApplication::UnicodeUTF8));
        pushButton_H_on->setText(QApplication::translate("PrinterSettings", "ON", 0, QApplication::UnicodeUTF8));
        radioButton_H_big->setText(QApplication::translate("PrinterSettings", "Big", 0, QApplication::UnicodeUTF8));
        checkBox_H_bold->setText(QApplication::translate("PrinterSettings", "Bold", 0, QApplication::UnicodeUTF8));
        radioButton_H_medium->setText(QApplication::translate("PrinterSettings", "Medium", 0, QApplication::UnicodeUTF8));
        pushButton_H_off->setText(QApplication::translate("PrinterSettings", "OFF", 0, QApplication::UnicodeUTF8));
        comboBox_heade_line->clear();
        comboBox_heade_line->insertItems(0, QStringList()
         << QApplication::translate("PrinterSettings", "Header 1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PrinterSettings", "Header 2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PrinterSettings", "Header 3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PrinterSettings", "Header 4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PrinterSettings", "Header 5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PrinterSettings", "Header 6", 0, QApplication::UnicodeUTF8)
        );
        pushButton_H_back->setText(QApplication::translate("PrinterSettings", "Back", 0, QApplication::UnicodeUTF8));
        pushButton_H_save->setText(QApplication::translate("PrinterSettings", "Save", 0, QApplication::UnicodeUTF8));
        groupBox_footer->setTitle(QString());
        label_4->setText(QApplication::translate("PrinterSettings", "Footer Settings", 0, QApplication::UnicodeUTF8));
        pushButton_F_on->setText(QApplication::translate("PrinterSettings", "ON", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("PrinterSettings", "Font size:", 0, QApplication::UnicodeUTF8));
        pushButton_F_off->setText(QApplication::translate("PrinterSettings", "OFF", 0, QApplication::UnicodeUTF8));
        radioButton_F_big->setText(QApplication::translate("PrinterSettings", "Big", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("PrinterSettings", "Footer:", 0, QApplication::UnicodeUTF8));
        radioButton_F_small->setText(QApplication::translate("PrinterSettings", "Small", 0, QApplication::UnicodeUTF8));
        radioButton_F_medium->setText(QApplication::translate("PrinterSettings", "Medium", 0, QApplication::UnicodeUTF8));
        checkBox_F_bold->setText(QApplication::translate("PrinterSettings", "Bold", 0, QApplication::UnicodeUTF8));
        comboBox_F_line->clear();
        comboBox_F_line->insertItems(0, QStringList()
         << QApplication::translate("PrinterSettings", "Footer 1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PrinterSettings", "Footer 2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PrinterSettings", "Footer 3", 0, QApplication::UnicodeUTF8)
        );
        label_footer_char_info->setText(QApplication::translate("PrinterSettings", "(38 char)", 0, QApplication::UnicodeUTF8));
        pushButton_F_back->setText(QApplication::translate("PrinterSettings", "Back", 0, QApplication::UnicodeUTF8));
        pushButton_F_save->setText(QApplication::translate("PrinterSettings", "Save", 0, QApplication::UnicodeUTF8));
        groupBox_menu->setTitle(QString());
        label->setText(QApplication::translate("PrinterSettings", "Printer Settings", 0, QApplication::UnicodeUTF8));
        pushButton_header_setting->setText(QApplication::translate("PrinterSettings", "Header", 0, QApplication::UnicodeUTF8));
        pushButton_footer_setting->setText(QApplication::translate("PrinterSettings", "Footer", 0, QApplication::UnicodeUTF8));
        pushButton_font_type->setText(QApplication::translate("PrinterSettings", "Font Type", 0, QApplication::UnicodeUTF8));
        pushButton_printer_settings_back->setText(QApplication::translate("PrinterSettings", "Back", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PrinterSettings: public Ui_PrinterSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINTERSETTINGS_H
