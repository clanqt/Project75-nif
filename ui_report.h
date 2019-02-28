/********************************************************************************
** Form generated from reading UI file 'report.ui'
**
** Created: Thu Jan 31 08:07:21 2019
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORT_H
#define UI_REPORT_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QGridLayout>
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

class Ui_Report
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_esc;
    QSpacerItem *horizontalSpacer;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_day_close;
    QPushButton *pushButton_batch_close;
    QPushButton *pushButton_stock_status;
    QPushButton *pushButton_supplier;
    QPushButton *pushButton_supplier_batch_wise;
    QPushButton *pushButton_payable;
    QPushButton *pushButton_receipt_payment;
    QPushButton *pushButton_bunk_report;
    QPushButton *pushButton_diesel;
    QPushButton *pushButton_bale;
    QPushButton *pushButton_Employee_Report;
    QPushButton *pushButton_Expense_report;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_batch_report;
    QLabel *label_2;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_esc_2;
    QSpacerItem *horizontalSpacer_2;
    QDateEdit *dateEdit_from;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QComboBox *comboBox_batch;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_7;
    QDateEdit *dateEdit_to;
    QGroupBox *groupBox_batch_supplier;
    QLabel *label_8;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_esc_3;
    QSpacerItem *horizontalSpacer_3;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_15;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *lineEdit_batch_supplier;
    QGroupBox *groupBox_supplier_report;
    QLabel *label_11;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_esc_4;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_print_supplier_report;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_18;
    QLineEdit *lineEdit_supplier_vno;
    QLabel *label_name;
    QLineEdit *lineEdit_supplier_name;
    QLabel *label_name_balance_title;
    QLabel *label_name_balance_amt;
    QLabel *label_12;
    QLabel *label_13;
    QDateEdit *dateEdit_from_supplier;
    QDateEdit *dateEdit_to_supplier;
    QGroupBox *groupBox_day_close;
    QLabel *label_14;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_esc_5;
    QSpacerItem *horizontalSpacer_5;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_4;
    QLineEdit *lineEdit_day_no;
    QLabel *label_20;
    QSpacerItem *verticalSpacer_4;
    QGroupBox *groupBox_bale_production;
    QLabel *label_21;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_esc_6;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_print_bale_production;
    QLabel *label_23;
    QLabel *label_24;
    QDateEdit *dateEdit_from_bale_production;
    QDateEdit *dateEdit_to_bale_production;
    QGroupBox *groupBox_Employee_Report;
    QLabel *label_22;
    QWidget *horizontalLayoutWidget_7;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_esc_7;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton_print_Employee_Report;
    QLabel *label_25;
    QLabel *label_26;
    QDateEdit *dateEdit_from_Employee_Report;
    QDateEdit *dateEdit_to_Employee_Report;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_5;
    QLineEdit *lineEdit_name_Employee_Report;
    QLabel *label_27;
    QSpacerItem *verticalSpacer_5;
    QGroupBox *groupBox_Expense_Report;
    QLabel *label_28;
    QWidget *horizontalLayoutWidget_8;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton_esc_8;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton_print_Expense_Report;
    QLabel *label_29;
    QLabel *label_30;
    QDateEdit *dateEdit_from_Expense_Report;
    QDateEdit *dateEdit_to_Expense_Report;
    QWidget *gridLayoutWidget_6;
    QGridLayout *gridLayout_6;
    QLineEdit *lineEdit_name_Expense_Report;
    QLabel *label_31;
    QSpacerItem *verticalSpacer_6;
    QGroupBox *groupBox_Receipt_Payment_Report;
    QLabel *label_32;
    QWidget *horizontalLayoutWidget_9;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButton_esc_9;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButton_print_Receipt_Payment_Report;
    QLabel *label_33;
    QLabel *label_34;
    QDateEdit *dateEdit_from_Receipt_Payment_Report;
    QDateEdit *dateEdit_to_Receipt_Payment_Report;
    QGroupBox *groupBox_bunk_report;
    QLabel *label_35;
    QWidget *horizontalLayoutWidget_10;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton_esc_10;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *pushButton_print_bunk_report;
    QLabel *label_36;
    QLabel *label_37;
    QDateEdit *dateEdit_from_bunk;
    QDateEdit *dateEdit_to_bunk;
    QWidget *gridLayoutWidget_7;
    QGridLayout *gridLayout_7;
    QLineEdit *lineEdit_bunk_name;
    QLabel *label_38;
    QSpacerItem *verticalSpacer_8;
    QGroupBox *groupBox_diesel_consumption;
    QLabel *label_39;
    QWidget *horizontalLayoutWidget_11;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *pushButton_esc_11;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *pushButton_print_diesel;
    QLabel *label_40;
    QLabel *label_41;
    QDateEdit *dateEdit_from_diesel;
    QDateEdit *dateEdit_to_diesel;

    void setupUi(QWidget *Report)
    {
        if (Report->objectName().isEmpty())
            Report->setObjectName(QString::fromUtf8("Report"));
        Report->resize(320, 2500);
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font.setPointSize(12);
        Report->setFont(font);
        groupBox = new QGroupBox(Report);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 320, 280));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 320, 20));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 180, 320, 30));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 0, 5, 0);
        pushButton_esc = new QPushButton(horizontalLayoutWidget);
        pushButton_esc->setObjectName(QString::fromUtf8("pushButton_esc"));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        pushButton_esc->setFont(font2);
        pushButton_esc->setFocusPolicy(Qt::NoFocus);
        pushButton_esc->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_esc);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayoutWidget = new QWidget(groupBox);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, -40, 300, 374));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(35, 0, 35, 0);
        pushButton_day_close = new QPushButton(verticalLayoutWidget);
        pushButton_day_close->setObjectName(QString::fromUtf8("pushButton_day_close"));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        pushButton_day_close->setFont(font3);
        pushButton_day_close->setStyleSheet(QString::fromUtf8("QPushButton:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        pushButton_day_close->setAutoDefault(true);

        verticalLayout->addWidget(pushButton_day_close);

        pushButton_batch_close = new QPushButton(verticalLayoutWidget);
        pushButton_batch_close->setObjectName(QString::fromUtf8("pushButton_batch_close"));
        pushButton_batch_close->setFont(font3);
        pushButton_batch_close->setStyleSheet(QString::fromUtf8("QPushButton:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        pushButton_batch_close->setAutoDefault(true);

        verticalLayout->addWidget(pushButton_batch_close);

        pushButton_stock_status = new QPushButton(verticalLayoutWidget);
        pushButton_stock_status->setObjectName(QString::fromUtf8("pushButton_stock_status"));
        pushButton_stock_status->setFont(font3);
        pushButton_stock_status->setStyleSheet(QString::fromUtf8("QPushButton:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        pushButton_stock_status->setAutoDefault(true);

        verticalLayout->addWidget(pushButton_stock_status);

        pushButton_supplier = new QPushButton(verticalLayoutWidget);
        pushButton_supplier->setObjectName(QString::fromUtf8("pushButton_supplier"));
        pushButton_supplier->setFont(font3);
        pushButton_supplier->setStyleSheet(QString::fromUtf8("QPushButton:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        pushButton_supplier->setAutoDefault(true);

        verticalLayout->addWidget(pushButton_supplier);

        pushButton_supplier_batch_wise = new QPushButton(verticalLayoutWidget);
        pushButton_supplier_batch_wise->setObjectName(QString::fromUtf8("pushButton_supplier_batch_wise"));
        pushButton_supplier_batch_wise->setFont(font3);
        pushButton_supplier_batch_wise->setStyleSheet(QString::fromUtf8("QPushButton:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        pushButton_supplier_batch_wise->setAutoDefault(true);

        verticalLayout->addWidget(pushButton_supplier_batch_wise);

        pushButton_payable = new QPushButton(verticalLayoutWidget);
        pushButton_payable->setObjectName(QString::fromUtf8("pushButton_payable"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        pushButton_payable->setFont(font4);
        pushButton_payable->setStyleSheet(QString::fromUtf8("QPushButton:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        pushButton_payable->setAutoDefault(true);

        verticalLayout->addWidget(pushButton_payable);

        pushButton_receipt_payment = new QPushButton(verticalLayoutWidget);
        pushButton_receipt_payment->setObjectName(QString::fromUtf8("pushButton_receipt_payment"));
        pushButton_receipt_payment->setFont(font3);
        pushButton_receipt_payment->setStyleSheet(QString::fromUtf8("QPushButton:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        pushButton_receipt_payment->setAutoDefault(true);

        verticalLayout->addWidget(pushButton_receipt_payment);

        pushButton_bunk_report = new QPushButton(verticalLayoutWidget);
        pushButton_bunk_report->setObjectName(QString::fromUtf8("pushButton_bunk_report"));
        pushButton_bunk_report->setFont(font3);
        pushButton_bunk_report->setStyleSheet(QString::fromUtf8("QPushButton:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        pushButton_bunk_report->setAutoDefault(true);

        verticalLayout->addWidget(pushButton_bunk_report);

        pushButton_diesel = new QPushButton(verticalLayoutWidget);
        pushButton_diesel->setObjectName(QString::fromUtf8("pushButton_diesel"));
        pushButton_diesel->setFont(font3);
        pushButton_diesel->setStyleSheet(QString::fromUtf8("QPushButton:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        pushButton_diesel->setAutoDefault(true);

        verticalLayout->addWidget(pushButton_diesel);

        pushButton_bale = new QPushButton(verticalLayoutWidget);
        pushButton_bale->setObjectName(QString::fromUtf8("pushButton_bale"));
        pushButton_bale->setFont(font3);
        pushButton_bale->setStyleSheet(QString::fromUtf8("QPushButton:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        pushButton_bale->setAutoDefault(true);

        verticalLayout->addWidget(pushButton_bale);

        pushButton_Employee_Report = new QPushButton(verticalLayoutWidget);
        pushButton_Employee_Report->setObjectName(QString::fromUtf8("pushButton_Employee_Report"));
        pushButton_Employee_Report->setFont(font3);
        pushButton_Employee_Report->setStyleSheet(QString::fromUtf8("QPushButton:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        pushButton_Employee_Report->setAutoDefault(true);

        verticalLayout->addWidget(pushButton_Employee_Report);

        pushButton_Expense_report = new QPushButton(verticalLayoutWidget);
        pushButton_Expense_report->setObjectName(QString::fromUtf8("pushButton_Expense_report"));
        pushButton_Expense_report->setFont(font3);
        pushButton_Expense_report->setStyleSheet(QString::fromUtf8("QPushButton:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        pushButton_Expense_report->setAutoDefault(true);

        verticalLayout->addWidget(pushButton_Expense_report);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton_payable->raise();
        pushButton_day_close->raise();
        pushButton_batch_close->raise();
        pushButton_stock_status->raise();
        pushButton_supplier->raise();
        pushButton_supplier_batch_wise->raise();
        pushButton_diesel->raise();
        pushButton_bale->raise();
        pushButton_Employee_Report->raise();
        pushButton_Expense_report->raise();
        pushButton_receipt_payment->raise();
        pushButton_bunk_report->raise();
        groupBox_batch_report = new QGroupBox(Report);
        groupBox_batch_report->setObjectName(QString::fromUtf8("groupBox_batch_report"));
        groupBox_batch_report->setGeometry(QRect(0, 280, 320, 220));
        label_2 = new QLabel(groupBox_batch_report);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 320, 20));
        label_2->setFont(font3);
        label_2->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget_2 = new QWidget(groupBox_batch_report);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 190, 300, 30));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(5, 0, 5, 0);
        pushButton_esc_2 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_esc_2->setObjectName(QString::fromUtf8("pushButton_esc_2"));
        pushButton_esc_2->setFont(font2);
        pushButton_esc_2->setFocusPolicy(Qt::NoFocus);
        pushButton_esc_2->setAutoDefault(true);

        horizontalLayout_2->addWidget(pushButton_esc_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        dateEdit_from = new QDateEdit(groupBox_batch_report);
        dateEdit_from->setObjectName(QString::fromUtf8("dateEdit_from"));
        dateEdit_from->setGeometry(QRect(60, 20, 110, 30));
        dateEdit_from->setMinimumDate(QDate(2018, 1, 1));
        label_3 = new QLabel(groupBox_batch_report);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 20, 49, 30));
        label_4 = new QLabel(groupBox_batch_report);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(180, 20, 29, 30));
        gridLayoutWidget = new QWidget(groupBox_batch_report);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 60, 300, 120));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        comboBox_batch = new QComboBox(gridLayoutWidget);
        comboBox_batch->setObjectName(QString::fromUtf8("comboBox_batch"));

        gridLayout->addWidget(comboBox_batch, 0, 1, 1, 2);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font2);

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_7, 1, 0, 1, 1);

        dateEdit_to = new QDateEdit(groupBox_batch_report);
        dateEdit_to->setObjectName(QString::fromUtf8("dateEdit_to"));
        dateEdit_to->setGeometry(QRect(210, 20, 101, 30));
        dateEdit_to->setMinimumDate(QDate(2018, 1, 1));
        groupBox_batch_supplier = new QGroupBox(Report);
        groupBox_batch_supplier->setObjectName(QString::fromUtf8("groupBox_batch_supplier"));
        groupBox_batch_supplier->setGeometry(QRect(0, 500, 320, 220));
        label_8 = new QLabel(groupBox_batch_supplier);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(0, 0, 320, 20));
        label_8->setFont(font3);
        label_8->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget_3 = new QWidget(groupBox_batch_supplier);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 180, 300, 30));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(5, 0, 5, 0);
        pushButton_esc_3 = new QPushButton(horizontalLayoutWidget_3);
        pushButton_esc_3->setObjectName(QString::fromUtf8("pushButton_esc_3"));
        pushButton_esc_3->setFont(font2);
        pushButton_esc_3->setFocusPolicy(Qt::NoFocus);
        pushButton_esc_3->setAutoDefault(true);

        horizontalLayout_3->addWidget(pushButton_esc_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        gridLayoutWidget_2 = new QWidget(groupBox_batch_supplier);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 30, 300, 140));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_15 = new QLabel(gridLayoutWidget_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font2);

        gridLayout_2->addWidget(label_15, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 1, 0, 1, 1);

        lineEdit_batch_supplier = new QLineEdit(gridLayoutWidget_2);
        lineEdit_batch_supplier->setObjectName(QString::fromUtf8("lineEdit_batch_supplier"));

        gridLayout_2->addWidget(lineEdit_batch_supplier, 0, 1, 1, 1);

        groupBox_supplier_report = new QGroupBox(Report);
        groupBox_supplier_report->setObjectName(QString::fromUtf8("groupBox_supplier_report"));
        groupBox_supplier_report->setGeometry(QRect(0, 720, 320, 220));
        label_11 = new QLabel(groupBox_supplier_report);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(0, 0, 320, 20));
        label_11->setFont(font3);
        label_11->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget_4 = new QWidget(groupBox_supplier_report);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(10, 180, 300, 30));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(5, 0, 5, 0);
        pushButton_esc_4 = new QPushButton(horizontalLayoutWidget_4);
        pushButton_esc_4->setObjectName(QString::fromUtf8("pushButton_esc_4"));
        pushButton_esc_4->setFont(font2);
        pushButton_esc_4->setFocusPolicy(Qt::NoFocus);
        pushButton_esc_4->setAutoDefault(true);

        horizontalLayout_4->addWidget(pushButton_esc_4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        pushButton_print_supplier_report = new QPushButton(horizontalLayoutWidget_4);
        pushButton_print_supplier_report->setObjectName(QString::fromUtf8("pushButton_print_supplier_report"));
        pushButton_print_supplier_report->setFont(font2);
        pushButton_print_supplier_report->setAutoDefault(true);

        horizontalLayout_4->addWidget(pushButton_print_supplier_report);

        gridLayoutWidget_3 = new QWidget(groupBox_supplier_report);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(10, 60, 300, 110));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 3, 0, 1, 1);

        label_18 = new QLabel(gridLayoutWidget_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setFont(font2);

        gridLayout_3->addWidget(label_18, 0, 0, 1, 1);

        lineEdit_supplier_vno = new QLineEdit(gridLayoutWidget_3);
        lineEdit_supplier_vno->setObjectName(QString::fromUtf8("lineEdit_supplier_vno"));

        gridLayout_3->addWidget(lineEdit_supplier_vno, 0, 1, 1, 1);

        label_name = new QLabel(gridLayoutWidget_3);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setFont(font2);

        gridLayout_3->addWidget(label_name, 1, 0, 1, 1);

        lineEdit_supplier_name = new QLineEdit(gridLayoutWidget_3);
        lineEdit_supplier_name->setObjectName(QString::fromUtf8("lineEdit_supplier_name"));

        gridLayout_3->addWidget(lineEdit_supplier_name, 1, 1, 1, 1);

        label_name_balance_title = new QLabel(gridLayoutWidget_3);
        label_name_balance_title->setObjectName(QString::fromUtf8("label_name_balance_title"));
        label_name_balance_title->setFont(font2);

        gridLayout_3->addWidget(label_name_balance_title, 2, 0, 1, 1);

        label_name_balance_amt = new QLabel(gridLayoutWidget_3);
        label_name_balance_amt->setObjectName(QString::fromUtf8("label_name_balance_amt"));
        label_name_balance_amt->setFont(font2);

        gridLayout_3->addWidget(label_name_balance_amt, 2, 1, 1, 1);

        label_12 = new QLabel(groupBox_supplier_report);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(180, 20, 29, 30));
        label_13 = new QLabel(groupBox_supplier_report);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 20, 49, 30));
        dateEdit_from_supplier = new QDateEdit(groupBox_supplier_report);
        dateEdit_from_supplier->setObjectName(QString::fromUtf8("dateEdit_from_supplier"));
        dateEdit_from_supplier->setGeometry(QRect(60, 20, 110, 30));
        dateEdit_from_supplier->setMinimumDate(QDate(2018, 1, 1));
        dateEdit_to_supplier = new QDateEdit(groupBox_supplier_report);
        dateEdit_to_supplier->setObjectName(QString::fromUtf8("dateEdit_to_supplier"));
        dateEdit_to_supplier->setGeometry(QRect(210, 20, 101, 30));
        dateEdit_to_supplier->setMinimumDate(QDate(2018, 1, 1));
        groupBox_day_close = new QGroupBox(Report);
        groupBox_day_close->setObjectName(QString::fromUtf8("groupBox_day_close"));
        groupBox_day_close->setGeometry(QRect(0, 940, 320, 220));
        label_14 = new QLabel(groupBox_day_close);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(0, 0, 320, 20));
        label_14->setFont(font3);
        label_14->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget_5 = new QWidget(groupBox_day_close);
        horizontalLayoutWidget_5->setObjectName(QString::fromUtf8("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(10, 180, 300, 30));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(5, 0, 5, 0);
        pushButton_esc_5 = new QPushButton(horizontalLayoutWidget_5);
        pushButton_esc_5->setObjectName(QString::fromUtf8("pushButton_esc_5"));
        pushButton_esc_5->setFont(font2);
        pushButton_esc_5->setFocusPolicy(Qt::NoFocus);
        pushButton_esc_5->setAutoDefault(true);

        horizontalLayout_5->addWidget(pushButton_esc_5);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        gridLayoutWidget_4 = new QWidget(groupBox_day_close);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(10, 30, 300, 140));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        lineEdit_day_no = new QLineEdit(gridLayoutWidget_4);
        lineEdit_day_no->setObjectName(QString::fromUtf8("lineEdit_day_no"));

        gridLayout_4->addWidget(lineEdit_day_no, 0, 1, 1, 1);

        label_20 = new QLabel(gridLayoutWidget_4);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_4->addWidget(label_20, 0, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_4, 1, 0, 1, 1);

        groupBox_bale_production = new QGroupBox(Report);
        groupBox_bale_production->setObjectName(QString::fromUtf8("groupBox_bale_production"));
        groupBox_bale_production->setGeometry(QRect(0, 1160, 320, 220));
        label_21 = new QLabel(groupBox_bale_production);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(0, 0, 320, 20));
        label_21->setFont(font3);
        label_21->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget_6 = new QWidget(groupBox_bale_production);
        horizontalLayoutWidget_6->setObjectName(QString::fromUtf8("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(10, 180, 300, 30));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(5, 0, 5, 0);
        pushButton_esc_6 = new QPushButton(horizontalLayoutWidget_6);
        pushButton_esc_6->setObjectName(QString::fromUtf8("pushButton_esc_6"));
        pushButton_esc_6->setFont(font2);
        pushButton_esc_6->setFocusPolicy(Qt::NoFocus);
        pushButton_esc_6->setAutoDefault(true);

        horizontalLayout_6->addWidget(pushButton_esc_6);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        pushButton_print_bale_production = new QPushButton(horizontalLayoutWidget_6);
        pushButton_print_bale_production->setObjectName(QString::fromUtf8("pushButton_print_bale_production"));
        pushButton_print_bale_production->setFont(font2);
        pushButton_print_bale_production->setAutoDefault(true);

        horizontalLayout_6->addWidget(pushButton_print_bale_production);

        label_23 = new QLabel(groupBox_bale_production);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(180, 40, 29, 30));
        label_24 = new QLabel(groupBox_bale_production);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(10, 40, 49, 30));
        dateEdit_from_bale_production = new QDateEdit(groupBox_bale_production);
        dateEdit_from_bale_production->setObjectName(QString::fromUtf8("dateEdit_from_bale_production"));
        dateEdit_from_bale_production->setGeometry(QRect(60, 40, 110, 30));
        dateEdit_from_bale_production->setMinimumDate(QDate(2018, 1, 1));
        dateEdit_to_bale_production = new QDateEdit(groupBox_bale_production);
        dateEdit_to_bale_production->setObjectName(QString::fromUtf8("dateEdit_to_bale_production"));
        dateEdit_to_bale_production->setGeometry(QRect(210, 40, 101, 30));
        dateEdit_to_bale_production->setMinimumDate(QDate(2018, 1, 1));
        groupBox_Employee_Report = new QGroupBox(Report);
        groupBox_Employee_Report->setObjectName(QString::fromUtf8("groupBox_Employee_Report"));
        groupBox_Employee_Report->setGeometry(QRect(0, 1380, 320, 220));
        label_22 = new QLabel(groupBox_Employee_Report);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(0, 0, 320, 20));
        label_22->setFont(font3);
        label_22->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget_7 = new QWidget(groupBox_Employee_Report);
        horizontalLayoutWidget_7->setObjectName(QString::fromUtf8("horizontalLayoutWidget_7"));
        horizontalLayoutWidget_7->setGeometry(QRect(10, 180, 300, 30));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget_7);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(5, 0, 5, 0);
        pushButton_esc_7 = new QPushButton(horizontalLayoutWidget_7);
        pushButton_esc_7->setObjectName(QString::fromUtf8("pushButton_esc_7"));
        pushButton_esc_7->setFont(font2);
        pushButton_esc_7->setFocusPolicy(Qt::NoFocus);
        pushButton_esc_7->setAutoDefault(true);

        horizontalLayout_7->addWidget(pushButton_esc_7);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        pushButton_print_Employee_Report = new QPushButton(horizontalLayoutWidget_7);
        pushButton_print_Employee_Report->setObjectName(QString::fromUtf8("pushButton_print_Employee_Report"));
        pushButton_print_Employee_Report->setFont(font2);
        pushButton_print_Employee_Report->setAutoDefault(true);

        horizontalLayout_7->addWidget(pushButton_print_Employee_Report);

        label_25 = new QLabel(groupBox_Employee_Report);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(180, 30, 29, 30));
        label_26 = new QLabel(groupBox_Employee_Report);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(10, 30, 49, 30));
        dateEdit_from_Employee_Report = new QDateEdit(groupBox_Employee_Report);
        dateEdit_from_Employee_Report->setObjectName(QString::fromUtf8("dateEdit_from_Employee_Report"));
        dateEdit_from_Employee_Report->setGeometry(QRect(60, 30, 110, 30));
        dateEdit_from_Employee_Report->setMinimumDate(QDate(2018, 1, 1));
        dateEdit_to_Employee_Report = new QDateEdit(groupBox_Employee_Report);
        dateEdit_to_Employee_Report->setObjectName(QString::fromUtf8("dateEdit_to_Employee_Report"));
        dateEdit_to_Employee_Report->setGeometry(QRect(210, 30, 101, 30));
        dateEdit_to_Employee_Report->setMinimumDate(QDate(2018, 1, 1));
        gridLayoutWidget_5 = new QWidget(groupBox_Employee_Report);
        gridLayoutWidget_5->setObjectName(QString::fromUtf8("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(10, 70, 300, 90));
        gridLayout_5 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        lineEdit_name_Employee_Report = new QLineEdit(gridLayoutWidget_5);
        lineEdit_name_Employee_Report->setObjectName(QString::fromUtf8("lineEdit_name_Employee_Report"));

        gridLayout_5->addWidget(lineEdit_name_Employee_Report, 0, 1, 1, 1);

        label_27 = new QLabel(gridLayoutWidget_5);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        gridLayout_5->addWidget(label_27, 0, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_5, 1, 0, 1, 1);

        groupBox_Expense_Report = new QGroupBox(Report);
        groupBox_Expense_Report->setObjectName(QString::fromUtf8("groupBox_Expense_Report"));
        groupBox_Expense_Report->setGeometry(QRect(0, 1600, 320, 220));
        label_28 = new QLabel(groupBox_Expense_Report);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(0, 0, 320, 20));
        label_28->setFont(font3);
        label_28->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget_8 = new QWidget(groupBox_Expense_Report);
        horizontalLayoutWidget_8->setObjectName(QString::fromUtf8("horizontalLayoutWidget_8"));
        horizontalLayoutWidget_8->setGeometry(QRect(10, 180, 300, 30));
        horizontalLayout_8 = new QHBoxLayout(horizontalLayoutWidget_8);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(5, 0, 5, 0);
        pushButton_esc_8 = new QPushButton(horizontalLayoutWidget_8);
        pushButton_esc_8->setObjectName(QString::fromUtf8("pushButton_esc_8"));
        pushButton_esc_8->setFont(font2);
        pushButton_esc_8->setFocusPolicy(Qt::NoFocus);
        pushButton_esc_8->setAutoDefault(true);

        horizontalLayout_8->addWidget(pushButton_esc_8);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);

        pushButton_print_Expense_Report = new QPushButton(horizontalLayoutWidget_8);
        pushButton_print_Expense_Report->setObjectName(QString::fromUtf8("pushButton_print_Expense_Report"));
        pushButton_print_Expense_Report->setFont(font2);
        pushButton_print_Expense_Report->setAutoDefault(true);

        horizontalLayout_8->addWidget(pushButton_print_Expense_Report);

        label_29 = new QLabel(groupBox_Expense_Report);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(180, 30, 29, 30));
        label_30 = new QLabel(groupBox_Expense_Report);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(10, 30, 49, 30));
        dateEdit_from_Expense_Report = new QDateEdit(groupBox_Expense_Report);
        dateEdit_from_Expense_Report->setObjectName(QString::fromUtf8("dateEdit_from_Expense_Report"));
        dateEdit_from_Expense_Report->setGeometry(QRect(60, 30, 110, 30));
        dateEdit_from_Expense_Report->setMinimumDate(QDate(2018, 1, 1));
        dateEdit_to_Expense_Report = new QDateEdit(groupBox_Expense_Report);
        dateEdit_to_Expense_Report->setObjectName(QString::fromUtf8("dateEdit_to_Expense_Report"));
        dateEdit_to_Expense_Report->setGeometry(QRect(210, 30, 101, 30));
        dateEdit_to_Expense_Report->setMinimumDate(QDate(2018, 1, 1));
        gridLayoutWidget_6 = new QWidget(groupBox_Expense_Report);
        gridLayoutWidget_6->setObjectName(QString::fromUtf8("gridLayoutWidget_6"));
        gridLayoutWidget_6->setGeometry(QRect(10, 70, 300, 90));
        gridLayout_6 = new QGridLayout(gridLayoutWidget_6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        lineEdit_name_Expense_Report = new QLineEdit(gridLayoutWidget_6);
        lineEdit_name_Expense_Report->setObjectName(QString::fromUtf8("lineEdit_name_Expense_Report"));

        gridLayout_6->addWidget(lineEdit_name_Expense_Report, 0, 1, 1, 1);

        label_31 = new QLabel(gridLayoutWidget_6);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        gridLayout_6->addWidget(label_31, 0, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_6, 1, 0, 1, 1);

        groupBox_Receipt_Payment_Report = new QGroupBox(Report);
        groupBox_Receipt_Payment_Report->setObjectName(QString::fromUtf8("groupBox_Receipt_Payment_Report"));
        groupBox_Receipt_Payment_Report->setGeometry(QRect(0, 1820, 320, 220));
        label_32 = new QLabel(groupBox_Receipt_Payment_Report);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(0, 0, 320, 20));
        label_32->setFont(font3);
        label_32->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget_9 = new QWidget(groupBox_Receipt_Payment_Report);
        horizontalLayoutWidget_9->setObjectName(QString::fromUtf8("horizontalLayoutWidget_9"));
        horizontalLayoutWidget_9->setGeometry(QRect(10, 180, 300, 30));
        horizontalLayout_9 = new QHBoxLayout(horizontalLayoutWidget_9);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(5, 0, 5, 0);
        pushButton_esc_9 = new QPushButton(horizontalLayoutWidget_9);
        pushButton_esc_9->setObjectName(QString::fromUtf8("pushButton_esc_9"));
        pushButton_esc_9->setFont(font2);
        pushButton_esc_9->setFocusPolicy(Qt::NoFocus);
        pushButton_esc_9->setAutoDefault(true);

        horizontalLayout_9->addWidget(pushButton_esc_9);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_9);

        pushButton_print_Receipt_Payment_Report = new QPushButton(horizontalLayoutWidget_9);
        pushButton_print_Receipt_Payment_Report->setObjectName(QString::fromUtf8("pushButton_print_Receipt_Payment_Report"));
        pushButton_print_Receipt_Payment_Report->setFont(font2);
        pushButton_print_Receipt_Payment_Report->setAutoDefault(true);

        horizontalLayout_9->addWidget(pushButton_print_Receipt_Payment_Report);

        label_33 = new QLabel(groupBox_Receipt_Payment_Report);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(180, 40, 29, 30));
        label_34 = new QLabel(groupBox_Receipt_Payment_Report);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(10, 40, 49, 30));
        dateEdit_from_Receipt_Payment_Report = new QDateEdit(groupBox_Receipt_Payment_Report);
        dateEdit_from_Receipt_Payment_Report->setObjectName(QString::fromUtf8("dateEdit_from_Receipt_Payment_Report"));
        dateEdit_from_Receipt_Payment_Report->setGeometry(QRect(60, 40, 110, 30));
        dateEdit_from_Receipt_Payment_Report->setMinimumDate(QDate(2018, 1, 1));
        dateEdit_to_Receipt_Payment_Report = new QDateEdit(groupBox_Receipt_Payment_Report);
        dateEdit_to_Receipt_Payment_Report->setObjectName(QString::fromUtf8("dateEdit_to_Receipt_Payment_Report"));
        dateEdit_to_Receipt_Payment_Report->setGeometry(QRect(210, 40, 101, 30));
        dateEdit_to_Receipt_Payment_Report->setMinimumDate(QDate(2018, 1, 1));
        groupBox_bunk_report = new QGroupBox(Report);
        groupBox_bunk_report->setObjectName(QString::fromUtf8("groupBox_bunk_report"));
        groupBox_bunk_report->setGeometry(QRect(0, 2040, 320, 220));
        label_35 = new QLabel(groupBox_bunk_report);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(0, 0, 320, 20));
        label_35->setFont(font3);
        label_35->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget_10 = new QWidget(groupBox_bunk_report);
        horizontalLayoutWidget_10->setObjectName(QString::fromUtf8("horizontalLayoutWidget_10"));
        horizontalLayoutWidget_10->setGeometry(QRect(10, 180, 300, 30));
        horizontalLayout_10 = new QHBoxLayout(horizontalLayoutWidget_10);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(5, 0, 5, 0);
        pushButton_esc_10 = new QPushButton(horizontalLayoutWidget_10);
        pushButton_esc_10->setObjectName(QString::fromUtf8("pushButton_esc_10"));
        pushButton_esc_10->setFont(font2);
        pushButton_esc_10->setFocusPolicy(Qt::NoFocus);
        pushButton_esc_10->setAutoDefault(true);

        horizontalLayout_10->addWidget(pushButton_esc_10);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_10);

        pushButton_print_bunk_report = new QPushButton(horizontalLayoutWidget_10);
        pushButton_print_bunk_report->setObjectName(QString::fromUtf8("pushButton_print_bunk_report"));
        pushButton_print_bunk_report->setFont(font2);
        pushButton_print_bunk_report->setAutoDefault(true);

        horizontalLayout_10->addWidget(pushButton_print_bunk_report);

        label_36 = new QLabel(groupBox_bunk_report);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(180, 30, 29, 30));
        label_36->setFont(font2);
        label_37 = new QLabel(groupBox_bunk_report);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(10, 30, 49, 30));
        label_37->setFont(font2);
        dateEdit_from_bunk = new QDateEdit(groupBox_bunk_report);
        dateEdit_from_bunk->setObjectName(QString::fromUtf8("dateEdit_from_bunk"));
        dateEdit_from_bunk->setGeometry(QRect(60, 30, 110, 30));
        dateEdit_from_bunk->setMinimumDate(QDate(2018, 1, 1));
        dateEdit_to_bunk = new QDateEdit(groupBox_bunk_report);
        dateEdit_to_bunk->setObjectName(QString::fromUtf8("dateEdit_to_bunk"));
        dateEdit_to_bunk->setGeometry(QRect(210, 30, 101, 30));
        dateEdit_to_bunk->setMinimumDate(QDate(2018, 1, 1));
        gridLayoutWidget_7 = new QWidget(groupBox_bunk_report);
        gridLayoutWidget_7->setObjectName(QString::fromUtf8("gridLayoutWidget_7"));
        gridLayoutWidget_7->setGeometry(QRect(9, 70, 300, 90));
        gridLayout_7 = new QGridLayout(gridLayoutWidget_7);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        lineEdit_bunk_name = new QLineEdit(gridLayoutWidget_7);
        lineEdit_bunk_name->setObjectName(QString::fromUtf8("lineEdit_bunk_name"));

        gridLayout_7->addWidget(lineEdit_bunk_name, 0, 1, 1, 1);

        label_38 = new QLabel(gridLayoutWidget_7);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setFont(font2);

        gridLayout_7->addWidget(label_38, 0, 0, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_8, 1, 0, 1, 1);

        groupBox_diesel_consumption = new QGroupBox(Report);
        groupBox_diesel_consumption->setObjectName(QString::fromUtf8("groupBox_diesel_consumption"));
        groupBox_diesel_consumption->setGeometry(QRect(0, 2260, 320, 220));
        label_39 = new QLabel(groupBox_diesel_consumption);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(0, 0, 320, 20));
        label_39->setFont(font3);
        label_39->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget_11 = new QWidget(groupBox_diesel_consumption);
        horizontalLayoutWidget_11->setObjectName(QString::fromUtf8("horizontalLayoutWidget_11"));
        horizontalLayoutWidget_11->setGeometry(QRect(10, 180, 300, 30));
        horizontalLayout_11 = new QHBoxLayout(horizontalLayoutWidget_11);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(5, 0, 5, 0);
        pushButton_esc_11 = new QPushButton(horizontalLayoutWidget_11);
        pushButton_esc_11->setObjectName(QString::fromUtf8("pushButton_esc_11"));
        pushButton_esc_11->setFont(font2);
        pushButton_esc_11->setFocusPolicy(Qt::NoFocus);
        pushButton_esc_11->setAutoDefault(true);

        horizontalLayout_11->addWidget(pushButton_esc_11);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_11);

        pushButton_print_diesel = new QPushButton(horizontalLayoutWidget_11);
        pushButton_print_diesel->setObjectName(QString::fromUtf8("pushButton_print_diesel"));
        pushButton_print_diesel->setFont(font2);
        pushButton_print_diesel->setAutoDefault(true);

        horizontalLayout_11->addWidget(pushButton_print_diesel);

        label_40 = new QLabel(groupBox_diesel_consumption);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setGeometry(QRect(180, 40, 29, 30));
        label_41 = new QLabel(groupBox_diesel_consumption);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(10, 40, 49, 30));
        dateEdit_from_diesel = new QDateEdit(groupBox_diesel_consumption);
        dateEdit_from_diesel->setObjectName(QString::fromUtf8("dateEdit_from_diesel"));
        dateEdit_from_diesel->setGeometry(QRect(60, 40, 110, 30));
        dateEdit_from_diesel->setMinimumDate(QDate(2018, 1, 1));
        dateEdit_to_diesel = new QDateEdit(groupBox_diesel_consumption);
        dateEdit_to_diesel->setObjectName(QString::fromUtf8("dateEdit_to_diesel"));
        dateEdit_to_diesel->setGeometry(QRect(210, 40, 101, 30));
        dateEdit_to_diesel->setMinimumDate(QDate(2018, 1, 1));
        QWidget::setTabOrder(pushButton_day_close, pushButton_batch_close);
        QWidget::setTabOrder(pushButton_batch_close, pushButton_stock_status);
        QWidget::setTabOrder(pushButton_stock_status, pushButton_supplier);
        QWidget::setTabOrder(pushButton_supplier, pushButton_supplier_batch_wise);
        QWidget::setTabOrder(pushButton_supplier_batch_wise, pushButton_payable);
        QWidget::setTabOrder(pushButton_payable, pushButton_receipt_payment);
        QWidget::setTabOrder(pushButton_receipt_payment, pushButton_bunk_report);
        QWidget::setTabOrder(pushButton_bunk_report, pushButton_diesel);
        QWidget::setTabOrder(pushButton_diesel, pushButton_bale);
        QWidget::setTabOrder(pushButton_bale, pushButton_Employee_Report);
        QWidget::setTabOrder(pushButton_Employee_Report, pushButton_Expense_report);
        QWidget::setTabOrder(pushButton_Expense_report, dateEdit_from);
        QWidget::setTabOrder(dateEdit_from, dateEdit_to);
        QWidget::setTabOrder(dateEdit_to, comboBox_batch);
        QWidget::setTabOrder(comboBox_batch, lineEdit_batch_supplier);
        QWidget::setTabOrder(lineEdit_batch_supplier, dateEdit_from_supplier);
        QWidget::setTabOrder(dateEdit_from_supplier, dateEdit_to_supplier);
        QWidget::setTabOrder(dateEdit_to_supplier, lineEdit_supplier_vno);
        QWidget::setTabOrder(lineEdit_supplier_vno, lineEdit_supplier_name);
        QWidget::setTabOrder(lineEdit_supplier_name, pushButton_print_supplier_report);
        QWidget::setTabOrder(pushButton_print_supplier_report, lineEdit_day_no);
        QWidget::setTabOrder(lineEdit_day_no, dateEdit_from_bale_production);
        QWidget::setTabOrder(dateEdit_from_bale_production, dateEdit_to_bale_production);
        QWidget::setTabOrder(dateEdit_to_bale_production, pushButton_print_bale_production);
        QWidget::setTabOrder(pushButton_print_bale_production, dateEdit_from_Employee_Report);
        QWidget::setTabOrder(dateEdit_from_Employee_Report, dateEdit_to_Employee_Report);
        QWidget::setTabOrder(dateEdit_to_Employee_Report, lineEdit_name_Employee_Report);
        QWidget::setTabOrder(lineEdit_name_Employee_Report, pushButton_print_Employee_Report);
        QWidget::setTabOrder(pushButton_print_Employee_Report, dateEdit_from_Expense_Report);
        QWidget::setTabOrder(dateEdit_from_Expense_Report, dateEdit_to_Expense_Report);
        QWidget::setTabOrder(dateEdit_to_Expense_Report, lineEdit_name_Expense_Report);
        QWidget::setTabOrder(lineEdit_name_Expense_Report, pushButton_print_Expense_Report);
        QWidget::setTabOrder(pushButton_print_Expense_Report, dateEdit_from_Receipt_Payment_Report);
        QWidget::setTabOrder(dateEdit_from_Receipt_Payment_Report, dateEdit_to_Receipt_Payment_Report);
        QWidget::setTabOrder(dateEdit_to_Receipt_Payment_Report, pushButton_print_Receipt_Payment_Report);
        QWidget::setTabOrder(pushButton_print_Receipt_Payment_Report, dateEdit_from_bunk);
        QWidget::setTabOrder(dateEdit_from_bunk, dateEdit_to_bunk);
        QWidget::setTabOrder(dateEdit_to_bunk, pushButton_print_bunk_report);
        QWidget::setTabOrder(pushButton_print_bunk_report, lineEdit_bunk_name);

        retranslateUi(Report);

        QMetaObject::connectSlotsByName(Report);
    } // setupUi

    void retranslateUi(QWidget *Report)
    {
        Report->setWindowTitle(QApplication::translate("Report", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("Report", "Reports", 0, QApplication::UnicodeUTF8));
        pushButton_esc->setText(QApplication::translate("Report", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_day_close->setText(QApplication::translate("Report", "Day Close", 0, QApplication::UnicodeUTF8));
        pushButton_batch_close->setText(QApplication::translate("Report", "Batch Close", 0, QApplication::UnicodeUTF8));
        pushButton_stock_status->setText(QApplication::translate("Report", "Stock Status", 0, QApplication::UnicodeUTF8));
        pushButton_supplier->setText(QApplication::translate("Report", "Supplier", 0, QApplication::UnicodeUTF8));
        pushButton_supplier_batch_wise->setText(QApplication::translate("Report", "Batch Supplier Wise", 0, QApplication::UnicodeUTF8));
        pushButton_payable->setText(QApplication::translate("Report", "Ledger Report", 0, QApplication::UnicodeUTF8));
        pushButton_receipt_payment->setText(QApplication::translate("Report", "Receipts/Payment", 0, QApplication::UnicodeUTF8));
        pushButton_bunk_report->setText(QApplication::translate("Report", "Bunk Report", 0, QApplication::UnicodeUTF8));
        pushButton_diesel->setText(QApplication::translate("Report", "Diesel Consumption", 0, QApplication::UnicodeUTF8));
        pushButton_bale->setText(QApplication::translate("Report", "Bale Production/Supply", 0, QApplication::UnicodeUTF8));
        pushButton_Employee_Report->setText(QApplication::translate("Report", "Employee Report", 0, QApplication::UnicodeUTF8));
        pushButton_Expense_report->setText(QApplication::translate("Report", "Expense Report", 0, QApplication::UnicodeUTF8));
        groupBox_batch_report->setTitle(QString());
        label_2->setText(QApplication::translate("Report", "Batch Close Report", 0, QApplication::UnicodeUTF8));
        pushButton_esc_2->setText(QApplication::translate("Report", "Esc-Back", 0, QApplication::UnicodeUTF8));
        dateEdit_from->setDisplayFormat(QApplication::translate("Report", "dd/MM/yy", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Report", "From:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Report", "To:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Report", "Batch       :", 0, QApplication::UnicodeUTF8));
        dateEdit_to->setDisplayFormat(QApplication::translate("Report", "dd/MM/yy", 0, QApplication::UnicodeUTF8));
        groupBox_batch_supplier->setTitle(QString());
        label_8->setText(QApplication::translate("Report", "Batch Supplier Wise", 0, QApplication::UnicodeUTF8));
        pushButton_esc_3->setText(QApplication::translate("Report", "Esc-Back", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("Report", "Batch No:", 0, QApplication::UnicodeUTF8));
        groupBox_supplier_report->setTitle(QString());
        label_11->setText(QApplication::translate("Report", "Supplier Report", 0, QApplication::UnicodeUTF8));
        pushButton_esc_4->setText(QApplication::translate("Report", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_print_supplier_report->setText(QApplication::translate("Report", "Print", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("Report", "Vehicle No:", 0, QApplication::UnicodeUTF8));
        label_name->setText(QApplication::translate("Report", "Name      :", 0, QApplication::UnicodeUTF8));
        label_name_balance_title->setText(QApplication::translate("Report", "Balance   :", 0, QApplication::UnicodeUTF8));
        label_name_balance_amt->setText(QString());
        label_12->setText(QApplication::translate("Report", "To:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("Report", "From:", 0, QApplication::UnicodeUTF8));
        dateEdit_from_supplier->setDisplayFormat(QApplication::translate("Report", "dd/MM/yy", 0, QApplication::UnicodeUTF8));
        dateEdit_to_supplier->setDisplayFormat(QApplication::translate("Report", "dd/MM/yy", 0, QApplication::UnicodeUTF8));
        groupBox_day_close->setTitle(QString());
        label_14->setText(QApplication::translate("Report", "Day Close", 0, QApplication::UnicodeUTF8));
        pushButton_esc_5->setText(QApplication::translate("Report", "Esc-Back", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("Report", "Day No:", 0, QApplication::UnicodeUTF8));
        groupBox_bale_production->setTitle(QString());
        label_21->setText(QApplication::translate("Report", "Bale Production/Supply", 0, QApplication::UnicodeUTF8));
        pushButton_esc_6->setText(QApplication::translate("Report", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_print_bale_production->setText(QApplication::translate("Report", "Print", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("Report", "To:", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("Report", "From:", 0, QApplication::UnicodeUTF8));
        dateEdit_from_bale_production->setDisplayFormat(QApplication::translate("Report", "dd/MM/yy", 0, QApplication::UnicodeUTF8));
        dateEdit_to_bale_production->setDisplayFormat(QApplication::translate("Report", "dd/MM/yy", 0, QApplication::UnicodeUTF8));
        groupBox_Employee_Report->setTitle(QString());
        label_22->setText(QApplication::translate("Report", "Employee Report", 0, QApplication::UnicodeUTF8));
        pushButton_esc_7->setText(QApplication::translate("Report", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_print_Employee_Report->setText(QApplication::translate("Report", "Print", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("Report", "To:", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("Report", "From:", 0, QApplication::UnicodeUTF8));
        dateEdit_from_Employee_Report->setDisplayFormat(QApplication::translate("Report", "dd/MM/yy", 0, QApplication::UnicodeUTF8));
        dateEdit_to_Employee_Report->setDisplayFormat(QApplication::translate("Report", "dd/MM/yy", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("Report", "Emp Name:", 0, QApplication::UnicodeUTF8));
        groupBox_Expense_Report->setTitle(QString());
        label_28->setText(QApplication::translate("Report", "Expense_Report", 0, QApplication::UnicodeUTF8));
        pushButton_esc_8->setText(QApplication::translate("Report", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_print_Expense_Report->setText(QApplication::translate("Report", "Print", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("Report", "To:", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("Report", "From:", 0, QApplication::UnicodeUTF8));
        dateEdit_from_Expense_Report->setDisplayFormat(QApplication::translate("Report", "dd/MM/yy", 0, QApplication::UnicodeUTF8));
        dateEdit_to_Expense_Report->setDisplayFormat(QApplication::translate("Report", "dd/MM/yy", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("Report", "Expense:", 0, QApplication::UnicodeUTF8));
        groupBox_Receipt_Payment_Report->setTitle(QString());
        label_32->setText(QApplication::translate("Report", "Receipt & Payment Report", 0, QApplication::UnicodeUTF8));
        pushButton_esc_9->setText(QApplication::translate("Report", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_print_Receipt_Payment_Report->setText(QApplication::translate("Report", "Print", 0, QApplication::UnicodeUTF8));
        label_33->setText(QApplication::translate("Report", "To:", 0, QApplication::UnicodeUTF8));
        label_34->setText(QApplication::translate("Report", "From:", 0, QApplication::UnicodeUTF8));
        dateEdit_from_Receipt_Payment_Report->setDisplayFormat(QApplication::translate("Report", "dd/MM/yy", 0, QApplication::UnicodeUTF8));
        dateEdit_to_Receipt_Payment_Report->setDisplayFormat(QApplication::translate("Report", "dd/MM/yy", 0, QApplication::UnicodeUTF8));
        groupBox_bunk_report->setTitle(QString());
        label_35->setText(QApplication::translate("Report", "Bunk Report", 0, QApplication::UnicodeUTF8));
        pushButton_esc_10->setText(QApplication::translate("Report", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_print_bunk_report->setText(QApplication::translate("Report", "Print", 0, QApplication::UnicodeUTF8));
        label_36->setText(QApplication::translate("Report", "To:", 0, QApplication::UnicodeUTF8));
        label_37->setText(QApplication::translate("Report", "From:", 0, QApplication::UnicodeUTF8));
        dateEdit_from_bunk->setDisplayFormat(QApplication::translate("Report", "dd/MM/yy", 0, QApplication::UnicodeUTF8));
        dateEdit_to_bunk->setDisplayFormat(QApplication::translate("Report", "dd/MM/yy", 0, QApplication::UnicodeUTF8));
        label_38->setText(QApplication::translate("Report", "Bunk Name:", 0, QApplication::UnicodeUTF8));
        groupBox_diesel_consumption->setTitle(QString());
        label_39->setText(QApplication::translate("Report", "Diesel Consumption Report", 0, QApplication::UnicodeUTF8));
        pushButton_esc_11->setText(QApplication::translate("Report", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_print_diesel->setText(QApplication::translate("Report", "Print", 0, QApplication::UnicodeUTF8));
        label_40->setText(QApplication::translate("Report", "To:", 0, QApplication::UnicodeUTF8));
        label_41->setText(QApplication::translate("Report", "From:", 0, QApplication::UnicodeUTF8));
        dateEdit_from_diesel->setDisplayFormat(QApplication::translate("Report", "dd/MM/yy", 0, QApplication::UnicodeUTF8));
        dateEdit_to_diesel->setDisplayFormat(QApplication::translate("Report", "dd/MM/yy", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Report: public Ui_Report {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORT_H
