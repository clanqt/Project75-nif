/********************************************************************************
** Form generated from reading UI file 'expense_master.ui'
**
** Created: Thu Jan 31 08:07:21 2019
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPENSE_MASTER_H
#define UI_EXPENSE_MASTER_H

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
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Expense_Master
{
public:
    QGroupBox *groupBox_expense_master_add;
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_expense_name;
    QSpacerItem *verticalSpacer;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_back;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton_add;
    QGroupBox *groupBox_Expense_entry;
    QLabel *label_3;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_bill_no;
    QLabel *label_4;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_2;
    QComboBox *comboBox_expense;
    QLabel *label_6;
    QLineEdit *lineEdit_amount;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_expense_entry_back;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButton_save;

    void setupUi(QWidget *Expense_Master)
    {
        if (Expense_Master->objectName().isEmpty())
            Expense_Master->setObjectName(QString::fromUtf8("Expense_Master"));
        Expense_Master->resize(320, 660);
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font.setPointSize(12);
        Expense_Master->setFont(font);
        groupBox_expense_master_add = new QGroupBox(Expense_Master);
        groupBox_expense_master_add->setObjectName(QString::fromUtf8("groupBox_expense_master_add"));
        groupBox_expense_master_add->setGeometry(QRect(0, 0, 320, 220));
        label = new QLabel(groupBox_expense_master_add);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 320, 20));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        gridLayoutWidget = new QWidget(groupBox_expense_master_add);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 30, 300, 140));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lineEdit_expense_name = new QLineEdit(gridLayoutWidget);
        lineEdit_expense_name->setObjectName(QString::fromUtf8("lineEdit_expense_name"));

        gridLayout->addWidget(lineEdit_expense_name, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        layoutWidget = new QWidget(groupBox_expense_master_add);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 180, 300, 29));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton_back = new QPushButton(layoutWidget);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        pushButton_back->setFont(font2);
        pushButton_back->setFocusPolicy(Qt::NoFocus);
        pushButton_back->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_back->setAutoDefault(true);

        horizontalLayout_4->addWidget(pushButton_back);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        pushButton_add = new QPushButton(layoutWidget);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));
        pushButton_add->setFont(font2);
        pushButton_add->setFocusPolicy(Qt::StrongFocus);
        pushButton_add->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_add->setAutoDefault(true);

        horizontalLayout_4->addWidget(pushButton_add);

        groupBox_Expense_entry = new QGroupBox(Expense_Master);
        groupBox_Expense_entry->setObjectName(QString::fromUtf8("groupBox_Expense_entry"));
        groupBox_Expense_entry->setGeometry(QRect(0, 220, 320, 220));
        label_3 = new QLabel(groupBox_Expense_entry);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 0, 320, 20));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);
        gridLayoutWidget_2 = new QWidget(groupBox_Expense_entry);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 30, 300, 140));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_bill_no = new QLineEdit(gridLayoutWidget_2);
        lineEdit_bill_no->setObjectName(QString::fromUtf8("lineEdit_bill_no"));

        gridLayout_2->addWidget(lineEdit_bill_no, 1, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 3, 0, 1, 1);

        comboBox_expense = new QComboBox(gridLayoutWidget_2);
        comboBox_expense->setObjectName(QString::fromUtf8("comboBox_expense"));

        gridLayout_2->addWidget(comboBox_expense, 0, 1, 1, 1);

        label_6 = new QLabel(gridLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_6, 2, 0, 1, 1);

        lineEdit_amount = new QLineEdit(gridLayoutWidget_2);
        lineEdit_amount->setObjectName(QString::fromUtf8("lineEdit_amount"));

        gridLayout_2->addWidget(lineEdit_amount, 2, 1, 1, 1);

        layoutWidget_2 = new QWidget(groupBox_Expense_entry);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 180, 300, 29));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        pushButton_expense_entry_back = new QPushButton(layoutWidget_2);
        pushButton_expense_entry_back->setObjectName(QString::fromUtf8("pushButton_expense_entry_back"));
        pushButton_expense_entry_back->setFont(font2);
        pushButton_expense_entry_back->setFocusPolicy(Qt::NoFocus);
        pushButton_expense_entry_back->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_expense_entry_back->setAutoDefault(true);

        horizontalLayout_5->addWidget(pushButton_expense_entry_back);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);

        pushButton_save = new QPushButton(layoutWidget_2);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        pushButton_save->setFont(font2);
        pushButton_save->setFocusPolicy(Qt::StrongFocus);
        pushButton_save->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_save->setAutoDefault(true);

        horizontalLayout_5->addWidget(pushButton_save);


        retranslateUi(Expense_Master);

        QMetaObject::connectSlotsByName(Expense_Master);
    } // setupUi

    void retranslateUi(QWidget *Expense_Master)
    {
        Expense_Master->setWindowTitle(QApplication::translate("Expense_Master", "Form", 0, QApplication::UnicodeUTF8));
        groupBox_expense_master_add->setTitle(QString());
        label->setText(QApplication::translate("Expense_Master", "Expense Master", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Expense_Master", "Expense\n"
"Name:", 0, QApplication::UnicodeUTF8));
        pushButton_back->setText(QApplication::translate("Expense_Master", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_add->setText(QApplication::translate("Expense_Master", "Add", 0, QApplication::UnicodeUTF8));
        groupBox_Expense_entry->setTitle(QString());
        label_3->setText(QApplication::translate("Expense_Master", "Expense", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Expense_Master", "Expense:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Expense_Master", "Bill No:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Expense_Master", "Amount:", 0, QApplication::UnicodeUTF8));
        pushButton_expense_entry_back->setText(QApplication::translate("Expense_Master", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_save->setText(QApplication::translate("Expense_Master", "Save", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Expense_Master: public Ui_Expense_Master {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPENSE_MASTER_H
