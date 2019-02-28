/********************************************************************************
** Form generated from reading UI file 'staff_cash.ui'
**
** Created: Thu Jan 31 08:07:21 2019
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STAFF_CASH_H
#define UI_STAFF_CASH_H

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

class Ui_Staff_Cash
{
public:
    QGroupBox *groupBox_home;
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_from;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_to;
    QPushButton *pushButton_home_back;
    QGroupBox *groupBox_from;
    QLabel *label_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_from_hand_cash;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *label_6;
    QLabel *label_5;
    QComboBox *comboBox_from_cash_from;
    QLineEdit *lineEdit_from_cash_recv;
    QLineEdit *lineEdit_from_aval_cash;
    QLabel *label_9;
    QLabel *label_7;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_back;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_from_save;
    QGroupBox *groupBox_to;
    QLabel *label_10;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QLineEdit *lineEdit_from_hand_cash_2;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QComboBox *comboBox_from_cash_from_2;
    QLineEdit *lineEdit_from_cash_recv_2;
    QLineEdit *lineEdit_from_aval_cash_2;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_back_2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_from_save_2;

    void setupUi(QWidget *Staff_Cash)
    {
        if (Staff_Cash->objectName().isEmpty())
            Staff_Cash->setObjectName(QString::fromUtf8("Staff_Cash"));
        Staff_Cash->resize(320, 660);
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        Staff_Cash->setFont(font);
        groupBox_home = new QGroupBox(Staff_Cash);
        groupBox_home->setObjectName(QString::fromUtf8("groupBox_home"));
        groupBox_home->setGeometry(QRect(0, 0, 320, 220));
        label = new QLabel(groupBox_home);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 320, 20));
        QFont font1;
        font1.setPointSize(14);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        gridLayoutWidget = new QWidget(groupBox_home);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 30, 300, 180));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_from = new QPushButton(gridLayoutWidget);
        pushButton_from->setObjectName(QString::fromUtf8("pushButton_from"));
        pushButton_from->setAutoDefault(true);

        gridLayout->addWidget(pushButton_from, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        pushButton_to = new QPushButton(gridLayoutWidget);
        pushButton_to->setObjectName(QString::fromUtf8("pushButton_to"));
        pushButton_to->setAutoDefault(true);

        gridLayout->addWidget(pushButton_to, 1, 1, 1, 1);

        pushButton_home_back = new QPushButton(gridLayoutWidget);
        pushButton_home_back->setObjectName(QString::fromUtf8("pushButton_home_back"));
        pushButton_home_back->setAutoDefault(true);

        gridLayout->addWidget(pushButton_home_back, 3, 0, 1, 1);

        groupBox_from = new QGroupBox(Staff_Cash);
        groupBox_from->setObjectName(QString::fromUtf8("groupBox_from"));
        groupBox_from->setGeometry(QRect(0, 220, 320, 220));
        label_2 = new QLabel(groupBox_from);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 320, 20));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        gridLayoutWidget_2 = new QWidget(groupBox_from);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 20, 300, 190));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_from_hand_cash = new QLineEdit(gridLayoutWidget_2);
        lineEdit_from_hand_cash->setObjectName(QString::fromUtf8("lineEdit_from_hand_cash"));
        lineEdit_from_hand_cash->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(lineEdit_from_hand_cash, 0, 2, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_8, 2, 1, 1, 1);

        label_6 = new QLabel(gridLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_6, 3, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        comboBox_from_cash_from = new QComboBox(gridLayoutWidget_2);
        comboBox_from_cash_from->setObjectName(QString::fromUtf8("comboBox_from_cash_from"));

        gridLayout_2->addWidget(comboBox_from_cash_from, 1, 1, 1, 2);

        lineEdit_from_cash_recv = new QLineEdit(gridLayoutWidget_2);
        lineEdit_from_cash_recv->setObjectName(QString::fromUtf8("lineEdit_from_cash_recv"));

        gridLayout_2->addWidget(lineEdit_from_cash_recv, 2, 2, 1, 1);

        lineEdit_from_aval_cash = new QLineEdit(gridLayoutWidget_2);
        lineEdit_from_aval_cash->setObjectName(QString::fromUtf8("lineEdit_from_aval_cash"));
        lineEdit_from_aval_cash->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(lineEdit_from_aval_cash, 3, 2, 1, 1);

        label_9 = new QLabel(gridLayoutWidget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_9, 3, 1, 1, 1);

        label_7 = new QLabel(gridLayoutWidget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_7, 0, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_back = new QPushButton(gridLayoutWidget_2);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));
        pushButton_back->setFont(font);
        pushButton_back->setFocusPolicy(Qt::NoFocus);
        pushButton_back->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_back->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_back);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pushButton_from_save = new QPushButton(gridLayoutWidget_2);
        pushButton_from_save->setObjectName(QString::fromUtf8("pushButton_from_save"));
        pushButton_from_save->setFont(font);
        pushButton_from_save->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_from_save->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_from_save);


        gridLayout_2->addLayout(horizontalLayout, 5, 0, 1, 3);

        groupBox_to = new QGroupBox(Staff_Cash);
        groupBox_to->setObjectName(QString::fromUtf8("groupBox_to"));
        groupBox_to->setGeometry(QRect(0, 440, 320, 220));
        label_10 = new QLabel(groupBox_to);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(0, 0, 320, 20));
        label_10->setFont(font1);
        label_10->setAlignment(Qt::AlignCenter);
        gridLayoutWidget_3 = new QWidget(groupBox_to);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(10, 20, 300, 190));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        lineEdit_from_hand_cash_2 = new QLineEdit(gridLayoutWidget_3);
        lineEdit_from_hand_cash_2->setObjectName(QString::fromUtf8("lineEdit_from_hand_cash_2"));
        lineEdit_from_hand_cash_2->setFocusPolicy(Qt::NoFocus);

        gridLayout_3->addWidget(lineEdit_from_hand_cash_2, 0, 2, 1, 1);

        label_11 = new QLabel(gridLayoutWidget_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_11, 1, 0, 1, 1);

        label_12 = new QLabel(gridLayoutWidget_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_12, 2, 1, 1, 1);

        label_13 = new QLabel(gridLayoutWidget_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_13, 3, 0, 1, 1);

        label_14 = new QLabel(gridLayoutWidget_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_14, 2, 0, 1, 1);

        comboBox_from_cash_from_2 = new QComboBox(gridLayoutWidget_3);
        comboBox_from_cash_from_2->setObjectName(QString::fromUtf8("comboBox_from_cash_from_2"));

        gridLayout_3->addWidget(comboBox_from_cash_from_2, 1, 1, 1, 2);

        lineEdit_from_cash_recv_2 = new QLineEdit(gridLayoutWidget_3);
        lineEdit_from_cash_recv_2->setObjectName(QString::fromUtf8("lineEdit_from_cash_recv_2"));

        gridLayout_3->addWidget(lineEdit_from_cash_recv_2, 2, 2, 1, 1);

        lineEdit_from_aval_cash_2 = new QLineEdit(gridLayoutWidget_3);
        lineEdit_from_aval_cash_2->setObjectName(QString::fromUtf8("lineEdit_from_aval_cash_2"));
        lineEdit_from_aval_cash_2->setFocusPolicy(Qt::NoFocus);

        gridLayout_3->addWidget(lineEdit_from_aval_cash_2, 3, 2, 1, 1);

        label_15 = new QLabel(gridLayoutWidget_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_15, 3, 1, 1, 1);

        label_16 = new QLabel(gridLayoutWidget_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_16, 0, 1, 1, 1);

        label_17 = new QLabel(gridLayoutWidget_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_17, 0, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 4, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_back_2 = new QPushButton(gridLayoutWidget_3);
        pushButton_back_2->setObjectName(QString::fromUtf8("pushButton_back_2"));
        pushButton_back_2->setFont(font);
        pushButton_back_2->setFocusPolicy(Qt::NoFocus);
        pushButton_back_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_back_2->setAutoDefault(true);

        horizontalLayout_2->addWidget(pushButton_back_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        pushButton_from_save_2 = new QPushButton(gridLayoutWidget_3);
        pushButton_from_save_2->setObjectName(QString::fromUtf8("pushButton_from_save_2"));
        pushButton_from_save_2->setFont(font);
        pushButton_from_save_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_from_save_2->setAutoDefault(true);

        horizontalLayout_2->addWidget(pushButton_from_save_2);


        gridLayout_3->addLayout(horizontalLayout_2, 5, 0, 1, 3);

        QWidget::setTabOrder(pushButton_from, pushButton_to);
        QWidget::setTabOrder(pushButton_to, pushButton_home_back);
        QWidget::setTabOrder(pushButton_home_back, lineEdit_from_hand_cash);
        QWidget::setTabOrder(lineEdit_from_hand_cash, comboBox_from_cash_from);
        QWidget::setTabOrder(comboBox_from_cash_from, lineEdit_from_cash_recv);
        QWidget::setTabOrder(lineEdit_from_cash_recv, lineEdit_from_aval_cash);
        QWidget::setTabOrder(lineEdit_from_aval_cash, pushButton_from_save);
        QWidget::setTabOrder(pushButton_from_save, lineEdit_from_hand_cash_2);
        QWidget::setTabOrder(lineEdit_from_hand_cash_2, comboBox_from_cash_from_2);
        QWidget::setTabOrder(comboBox_from_cash_from_2, lineEdit_from_cash_recv_2);
        QWidget::setTabOrder(lineEdit_from_cash_recv_2, lineEdit_from_aval_cash_2);
        QWidget::setTabOrder(lineEdit_from_aval_cash_2, pushButton_from_save_2);

        retranslateUi(Staff_Cash);

        QMetaObject::connectSlotsByName(Staff_Cash);
    } // setupUi

    void retranslateUi(QWidget *Staff_Cash)
    {
        Staff_Cash->setWindowTitle(QApplication::translate("Staff_Cash", "Form", 0, QApplication::UnicodeUTF8));
        groupBox_home->setTitle(QString());
        label->setText(QApplication::translate("Staff_Cash", "Staff Payment", 0, QApplication::UnicodeUTF8));
        pushButton_from->setText(QApplication::translate("Staff_Cash", "Cash From", 0, QApplication::UnicodeUTF8));
        pushButton_to->setText(QApplication::translate("Staff_Cash", "Cash TO", 0, QApplication::UnicodeUTF8));
        pushButton_home_back->setText(QApplication::translate("Staff_Cash", "Esc-Back", 0, QApplication::UnicodeUTF8));
        groupBox_from->setTitle(QString());
        label_2->setText(QApplication::translate("Staff_Cash", "Cash From", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Staff_Cash", "Cash From:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Staff_Cash", "Rs.", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Staff_Cash", "Aval.Cash:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Staff_Cash", "Cash Recv:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Staff_Cash", "Rs.", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Staff_Cash", "Rs.", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Staff_Cash", "Hand Cash:", 0, QApplication::UnicodeUTF8));
        pushButton_back->setText(QApplication::translate("Staff_Cash", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_from_save->setText(QApplication::translate("Staff_Cash", "Save", 0, QApplication::UnicodeUTF8));
        groupBox_to->setTitle(QString());
        label_10->setText(QApplication::translate("Staff_Cash", "Cash To", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Staff_Cash", "Cash To:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Staff_Cash", "Rs.", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("Staff_Cash", "Aval.Cash:", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("Staff_Cash", "Cash Given:", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("Staff_Cash", "Rs.", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("Staff_Cash", "Rs.", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("Staff_Cash", "Hand Cash:", 0, QApplication::UnicodeUTF8));
        pushButton_back_2->setText(QApplication::translate("Staff_Cash", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_from_save_2->setText(QApplication::translate("Staff_Cash", "Save", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Staff_Cash: public Ui_Staff_Cash {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STAFF_CASH_H
