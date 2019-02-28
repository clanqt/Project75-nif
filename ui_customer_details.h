/********************************************************************************
** Form generated from reading UI file 'customer_details.ui'
**
** Created: Thu Jan 31 08:07:21 2019
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMER_DETAILS_H
#define UI_CUSTOMER_DETAILS_H

#include <QtCore/QLocale>
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

class Ui_Customer_Details
{
public:
    QGroupBox *groupBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_unit;
    QLabel *label_previous_balance;
    QLineEdit *lineEdit_paid;
    QLabel *label_7;
    QLabel *label_count_totle;
    QLabel *label_est_amt;
    QLabel *label_balance_title;
    QLabel *label_9;
    QLabel *label_excess_title;
    QLabel *label_excess_paid;
    QLabel *label_5;
    QLineEdit *lineEdit_Excess;
    QLabel *label_balance_type;
    QLabel *label_Payable;
    QLabel *label_est_amt_title;
    QLabel *label_final_balance;
    QLabel *label_unit_2;
    QLabel *label_unit_3;
    QLabel *label_unit_4;
    QLabel *label_unit_5;
    QLabel *label_unit_6;
    QLabel *label_count;
    QLabel *label_unit_7;
    QLabel *label_unit_8;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_print_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_print;
    QLabel *label_kms;
    QLabel *label_info;
    QGroupBox *groupBox_preview;
    QLabel *label;
    QTextEdit *textEdit;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_print_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_print_4;
    QLabel *label_info_2;

    void setupUi(QWidget *Customer_Details)
    {
        if (Customer_Details->objectName().isEmpty())
            Customer_Details->setObjectName(QString::fromUtf8("Customer_Details"));
        Customer_Details->resize(320, 660);
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font.setPointSize(12);
        Customer_Details->setFont(font);
        Customer_Details->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 249, 249);"));
        groupBox = new QGroupBox(Customer_Details);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 320, 220));
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 300, 180));
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        gridLayoutWidget->setFont(font1);
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_unit = new QLabel(gridLayoutWidget);
        label_unit->setObjectName(QString::fromUtf8("label_unit"));
        label_unit->setFont(font1);
        label_unit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_unit, 0, 1, 1, 1);

        label_previous_balance = new QLabel(gridLayoutWidget);
        label_previous_balance->setObjectName(QString::fromUtf8("label_previous_balance"));
        label_previous_balance->setFont(font1);
        label_previous_balance->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_previous_balance, 0, 2, 1, 1);

        lineEdit_paid = new QLineEdit(gridLayoutWidget);
        lineEdit_paid->setObjectName(QString::fromUtf8("lineEdit_paid"));
        lineEdit_paid->setFont(font1);
        lineEdit_paid->setStyleSheet(QString::fromUtf8("QLineEdit:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));

        gridLayout->addWidget(lineEdit_paid, 6, 2, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        label_7->setFont(font2);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        label_count_totle = new QLabel(gridLayoutWidget);
        label_count_totle->setObjectName(QString::fromUtf8("label_count_totle"));
        label_count_totle->setFont(font2);
        label_count_totle->setStyleSheet(QString::fromUtf8(""));
        label_count_totle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_count_totle, 1, 0, 1, 1);

        label_est_amt = new QLabel(gridLayoutWidget);
        label_est_amt->setObjectName(QString::fromUtf8("label_est_amt"));
        label_est_amt->setFont(font1);
        label_est_amt->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_est_amt, 2, 2, 1, 1);

        label_balance_title = new QLabel(gridLayoutWidget);
        label_balance_title->setObjectName(QString::fromUtf8("label_balance_title"));
        label_balance_title->setFont(font2);
        label_balance_title->setStyleSheet(QString::fromUtf8(""));
        label_balance_title->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_balance_title, 7, 0, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font2);
        label_9->setStyleSheet(QString::fromUtf8(""));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_9, 5, 0, 1, 1);

        label_excess_title = new QLabel(gridLayoutWidget);
        label_excess_title->setObjectName(QString::fromUtf8("label_excess_title"));
        QFont font3;
        font3.setPointSize(13);
        font3.setBold(true);
        font3.setWeight(75);
        label_excess_title->setFont(font3);
        label_excess_title->setLocale(QLocale(QLocale::English, QLocale::India));
        label_excess_title->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_excess_title, 4, 0, 1, 1);

        label_excess_paid = new QLabel(gridLayoutWidget);
        label_excess_paid->setObjectName(QString::fromUtf8("label_excess_paid"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font4.setPointSize(13);
        font4.setBold(true);
        font4.setWeight(75);
        label_excess_paid->setFont(font4);
        label_excess_paid->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_excess_paid, 4, 2, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font2);
        label_5->setStyleSheet(QString::fromUtf8(""));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        lineEdit_Excess = new QLineEdit(gridLayoutWidget);
        lineEdit_Excess->setObjectName(QString::fromUtf8("lineEdit_Excess"));
        lineEdit_Excess->setFont(font1);
        lineEdit_Excess->setStyleSheet(QString::fromUtf8("QLineEdit:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));

        gridLayout->addWidget(lineEdit_Excess, 3, 2, 1, 1);

        label_balance_type = new QLabel(gridLayoutWidget);
        label_balance_type->setObjectName(QString::fromUtf8("label_balance_type"));
        label_balance_type->setFont(font2);
        label_balance_type->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_balance_type, 0, 0, 1, 1);

        label_Payable = new QLabel(gridLayoutWidget);
        label_Payable->setObjectName(QString::fromUtf8("label_Payable"));
        label_Payable->setFont(font1);
        label_Payable->setStyleSheet(QString::fromUtf8(""));
        label_Payable->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_Payable, 5, 2, 1, 1);

        label_est_amt_title = new QLabel(gridLayoutWidget);
        label_est_amt_title->setObjectName(QString::fromUtf8("label_est_amt_title"));
        label_est_amt_title->setFont(font2);
        label_est_amt_title->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_est_amt_title, 2, 0, 1, 1);

        label_final_balance = new QLabel(gridLayoutWidget);
        label_final_balance->setObjectName(QString::fromUtf8("label_final_balance"));
        label_final_balance->setFont(font2);
        label_final_balance->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(label_final_balance, 7, 2, 1, 1);

        label_unit_2 = new QLabel(gridLayoutWidget);
        label_unit_2->setObjectName(QString::fromUtf8("label_unit_2"));
        label_unit_2->setFont(font1);
        label_unit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_unit_2, 1, 3, 1, 1);

        label_unit_3 = new QLabel(gridLayoutWidget);
        label_unit_3->setObjectName(QString::fromUtf8("label_unit_3"));
        label_unit_3->setFont(font1);
        label_unit_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_unit_3, 2, 1, 1, 1);

        label_unit_4 = new QLabel(gridLayoutWidget);
        label_unit_4->setObjectName(QString::fromUtf8("label_unit_4"));
        label_unit_4->setFont(font1);
        label_unit_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_unit_4, 3, 1, 1, 1);

        label_unit_5 = new QLabel(gridLayoutWidget);
        label_unit_5->setObjectName(QString::fromUtf8("label_unit_5"));
        label_unit_5->setFont(font2);
        label_unit_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_unit_5, 4, 1, 1, 1);

        label_unit_6 = new QLabel(gridLayoutWidget);
        label_unit_6->setObjectName(QString::fromUtf8("label_unit_6"));
        label_unit_6->setFont(font1);
        label_unit_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_unit_6, 5, 1, 1, 1);

        label_count = new QLabel(gridLayoutWidget);
        label_count->setObjectName(QString::fromUtf8("label_count"));
        label_count->setFont(font1);
        label_count->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(label_count, 1, 1, 1, 2);

        label_unit_7 = new QLabel(gridLayoutWidget);
        label_unit_7->setObjectName(QString::fromUtf8("label_unit_7"));
        label_unit_7->setFont(font1);
        label_unit_7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_unit_7, 6, 1, 1, 1);

        label_unit_8 = new QLabel(gridLayoutWidget);
        label_unit_8->setObjectName(QString::fromUtf8("label_unit_8"));
        label_unit_8->setFont(font2);
        label_unit_8->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_unit_8, 7, 1, 1, 1);

        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 190, 300, 29));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_print_2 = new QPushButton(horizontalLayoutWidget);
        pushButton_print_2->setObjectName(QString::fromUtf8("pushButton_print_2"));
        pushButton_print_2->setFont(font2);
        pushButton_print_2->setFocusPolicy(Qt::NoFocus);
        pushButton_print_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_print_2->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_print_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_print = new QPushButton(horizontalLayoutWidget);
        pushButton_print->setObjectName(QString::fromUtf8("pushButton_print"));
        pushButton_print->setFont(font2);
        pushButton_print->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_print->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_print);

        label_kms = new QLabel(groupBox);
        label_kms->setObjectName(QString::fromUtf8("label_kms"));
        label_kms->setGeometry(QRect(270, -2, 56, 20));
        label_kms->setFont(font2);
        label_info = new QLabel(groupBox);
        label_info->setObjectName(QString::fromUtf8("label_info"));
        label_info->setGeometry(QRect(10, 60, 300, 90));
        QFont font5;
        font5.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font5.setPointSize(14);
        font5.setBold(true);
        font5.setWeight(75);
        label_info->setFont(font5);
        label_info->setStyleSheet(QString::fromUtf8("background-color: rgb(183, 255, 251);\n"
"color: rgb(177, 19, 66);"));
        label_info->setAlignment(Qt::AlignCenter);
        label_info->setWordWrap(true);
        label_info->raise();
        gridLayoutWidget->raise();
        horizontalLayoutWidget->raise();
        label_kms->raise();
        groupBox_preview = new QGroupBox(Customer_Details);
        groupBox_preview->setObjectName(QString::fromUtf8("groupBox_preview"));
        groupBox_preview->setGeometry(QRect(0, 220, 320, 220));
        groupBox_preview->setFont(font2);
        label = new QLabel(groupBox_preview);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 320, 20));
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);
        textEdit = new QTextEdit(groupBox_preview);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(0, 20, 320, 150));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Monospace"));
        textEdit->setFont(font6);
        textEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        textEdit->setReadOnly(true);
        horizontalLayoutWidget_2 = new QWidget(groupBox_preview);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 180, 300, 30));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_print_3 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_print_3->setObjectName(QString::fromUtf8("pushButton_print_3"));
        pushButton_print_3->setFont(font2);
        pushButton_print_3->setFocusPolicy(Qt::NoFocus);
        pushButton_print_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_print_3->setAutoDefault(true);

        horizontalLayout_2->addWidget(pushButton_print_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_print_4 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_print_4->setObjectName(QString::fromUtf8("pushButton_print_4"));
        pushButton_print_4->setFont(font2);
        pushButton_print_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_print_4->setAutoDefault(true);

        horizontalLayout_2->addWidget(pushButton_print_4);

        label_info_2 = new QLabel(groupBox_preview);
        label_info_2->setObjectName(QString::fromUtf8("label_info_2"));
        label_info_2->setGeometry(QRect(10, 50, 300, 90));
        QFont font7;
        font7.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font7.setPointSize(18);
        font7.setBold(true);
        font7.setWeight(75);
        label_info_2->setFont(font7);
        label_info_2->setStyleSheet(QString::fromUtf8("background-color: rgb(183, 255, 251);\n"
"color: rgb(177, 19, 66);"));
        label_info_2->setAlignment(Qt::AlignCenter);
        label_info_2->setWordWrap(true);
        label_info_2->raise();
        label->raise();
        textEdit->raise();
        horizontalLayoutWidget_2->raise();
        QWidget::setTabOrder(lineEdit_Excess, lineEdit_paid);
        QWidget::setTabOrder(lineEdit_paid, pushButton_print);

        retranslateUi(Customer_Details);

        QMetaObject::connectSlotsByName(Customer_Details);
    } // setupUi

    void retranslateUi(QWidget *Customer_Details)
    {
        Customer_Details->setWindowTitle(QApplication::translate("Customer_Details", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label_unit->setText(QApplication::translate("Customer_Details", "Rs.", 0, QApplication::UnicodeUTF8));
        label_previous_balance->setText(QApplication::translate("Customer_Details", "999.99", 0, QApplication::UnicodeUTF8));
        lineEdit_paid->setText(QApplication::translate("Customer_Details", "9999.99", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Customer_Details", "Paid       :", 0, QApplication::UnicodeUTF8));
        label_count_totle->setText(QApplication::translate("Customer_Details", "Numbers    :", 0, QApplication::UnicodeUTF8));
        label_est_amt->setText(QApplication::translate("Customer_Details", "9999.99", 0, QApplication::UnicodeUTF8));
        label_balance_title->setText(QApplication::translate("Customer_Details", "Balance    :", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Customer_Details", "Payable    :", 0, QApplication::UnicodeUTF8));
        label_excess_title->setText(QApplication::translate("Customer_Details", "Excess Paid:", 0, QApplication::UnicodeUTF8));
        label_excess_paid->setText(QApplication::translate("Customer_Details", "9999.99", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Customer_Details", "Approve.Amt:", 0, QApplication::UnicodeUTF8));
        lineEdit_Excess->setText(QApplication::translate("Customer_Details", "999", 0, QApplication::UnicodeUTF8));
        label_balance_type->setText(QApplication::translate("Customer_Details", "Advance.Amt:", 0, QApplication::UnicodeUTF8));
        label_Payable->setText(QApplication::translate("Customer_Details", "999.99", 0, QApplication::UnicodeUTF8));
        label_est_amt_title->setText(QApplication::translate("Customer_Details", "Calc.Amt   :", 0, QApplication::UnicodeUTF8));
        label_final_balance->setText(QApplication::translate("Customer_Details", "9999.99", 0, QApplication::UnicodeUTF8));
        label_unit_2->setText(QApplication::translate("Customer_Details", "Nos", 0, QApplication::UnicodeUTF8));
        label_unit_3->setText(QApplication::translate("Customer_Details", "Rs.", 0, QApplication::UnicodeUTF8));
        label_unit_4->setText(QApplication::translate("Customer_Details", "Rs.", 0, QApplication::UnicodeUTF8));
        label_unit_5->setText(QApplication::translate("Customer_Details", "Rs.", 0, QApplication::UnicodeUTF8));
        label_unit_6->setText(QApplication::translate("Customer_Details", "Rs.", 0, QApplication::UnicodeUTF8));
        label_count->setText(QApplication::translate("Customer_Details", "999", 0, QApplication::UnicodeUTF8));
        label_unit_7->setText(QApplication::translate("Customer_Details", "Rs.", 0, QApplication::UnicodeUTF8));
        label_unit_8->setText(QApplication::translate("Customer_Details", "Rs.", 0, QApplication::UnicodeUTF8));
        pushButton_print_2->setText(QApplication::translate("Customer_Details", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_print->setText(QApplication::translate("Customer_Details", "Preview", 0, QApplication::UnicodeUTF8));
        label_kms->setText(QApplication::translate("Customer_Details", "999Km", 0, QApplication::UnicodeUTF8));
        label_info->setText(QApplication::translate("Customer_Details", "Generating Purchase Preview...", 0, QApplication::UnicodeUTF8));
        groupBox_preview->setTitle(QString());
        label->setText(QApplication::translate("Customer_Details", "Purchase Preview", 0, QApplication::UnicodeUTF8));
        pushButton_print_3->setText(QApplication::translate("Customer_Details", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_print_4->setText(QApplication::translate("Customer_Details", "F1-Print", 0, QApplication::UnicodeUTF8));
        label_info_2->setText(QApplication::translate("Customer_Details", "Printing ...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Customer_Details: public Ui_Customer_Details {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMER_DETAILS_H
