/********************************************************************************
** Form generated from reading UI file 'employeemaster.ui'
**
** Created: Thu Jan 31 08:07:21 2019
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEEMASTER_H
#define UI_EMPLOYEEMASTER_H

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

class Ui_EmployeeMaster
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QLabel *label_21;
    QLineEdit *lineEdit_charges;
    QLineEdit *lineEdit_emp_name;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit_rate_pe_hour;
    QLabel *label_20;
    QLabel *label_18;
    QLabel *label_16;
    QLabel *label_14;
    QLabel *label_11;
    QLabel *label_15;
    QLineEdit *lineEdit_emp_contact;
    QLabel *label_13;
    QLabel *label_2;
    QLineEdit *lineEdit_target;
    QLabel *label_17;
    QLabel *label_12;
    QLineEdit *lineEdit_op_balance;
    QLabel *label_3;
    QComboBox *comboBox_gender;
    QLabel *label_19;
    QComboBox *comboBox_type;
    QLabel *label_22;
    QGroupBox *groupBox_3;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_pending;
    QRadioButton *radioButton_advance;
    QGroupBox *groupBox_2;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton_active;
    QRadioButton *radioButton_inactive;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_purchase_back_2;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton_edit_enable;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_purchase_save;

    void setupUi(QWidget *EmployeeMaster)
    {
        if (EmployeeMaster->objectName().isEmpty())
            EmployeeMaster->setObjectName(QString::fromUtf8("EmployeeMaster"));
        EmployeeMaster->resize(320, 440);
        groupBox = new QGroupBox(EmployeeMaster);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 320, 440));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        groupBox->setFont(font);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 320, 30));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 30, 309, 370));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_21 = new QLabel(gridLayoutWidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        label_21->setFont(font2);

        gridLayout_2->addWidget(label_21, 8, 0, 1, 1);

        lineEdit_charges = new QLineEdit(gridLayoutWidget);
        lineEdit_charges->setObjectName(QString::fromUtf8("lineEdit_charges"));

        gridLayout_2->addWidget(lineEdit_charges, 6, 3, 1, 1);

        lineEdit_emp_name = new QLineEdit(gridLayoutWidget);
        lineEdit_emp_name->setObjectName(QString::fromUtf8("lineEdit_emp_name"));

        gridLayout_2->addWidget(lineEdit_emp_name, 0, 1, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 4, 4, 1, 1);

        lineEdit_rate_pe_hour = new QLineEdit(gridLayoutWidget);
        lineEdit_rate_pe_hour->setObjectName(QString::fromUtf8("lineEdit_rate_pe_hour"));

        gridLayout_2->addWidget(lineEdit_rate_pe_hour, 4, 2, 1, 1);

        label_20 = new QLabel(gridLayoutWidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_2->addWidget(label_20, 2, 3, 1, 1);

        label_18 = new QLabel(gridLayoutWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setFont(font2);

        gridLayout_2->addWidget(label_18, 6, 0, 1, 1);

        label_16 = new QLabel(gridLayoutWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font2);

        gridLayout_2->addWidget(label_16, 3, 0, 1, 1);

        label_14 = new QLabel(gridLayoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font2);

        gridLayout_2->addWidget(label_14, 0, 0, 1, 1);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_2->addWidget(label_11, 4, 3, 1, 1);

        label_15 = new QLabel(gridLayoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font2);

        gridLayout_2->addWidget(label_15, 2, 0, 1, 1);

        lineEdit_emp_contact = new QLineEdit(gridLayoutWidget);
        lineEdit_emp_contact->setObjectName(QString::fromUtf8("lineEdit_emp_contact"));
        lineEdit_emp_contact->setMaxLength(15);

        gridLayout_2->addWidget(lineEdit_emp_contact, 1, 1, 1, 3);

        label_13 = new QLabel(gridLayoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font2);

        gridLayout_2->addWidget(label_13, 1, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout_2->addWidget(label_2, 5, 1, 1, 2);

        lineEdit_target = new QLineEdit(gridLayoutWidget);
        lineEdit_target->setObjectName(QString::fromUtf8("lineEdit_target"));

        gridLayout_2->addWidget(lineEdit_target, 6, 1, 1, 2);

        label_17 = new QLabel(gridLayoutWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_2->addWidget(label_17, 4, 1, 1, 1);

        label_12 = new QLabel(gridLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font2);

        gridLayout_2->addWidget(label_12, 4, 0, 1, 1);

        lineEdit_op_balance = new QLineEdit(gridLayoutWidget);
        lineEdit_op_balance->setObjectName(QString::fromUtf8("lineEdit_op_balance"));

        gridLayout_2->addWidget(lineEdit_op_balance, 7, 1, 1, 2);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout_2->addWidget(label_3, 5, 3, 1, 1);

        comboBox_gender = new QComboBox(gridLayoutWidget);
        comboBox_gender->setObjectName(QString::fromUtf8("comboBox_gender"));

        gridLayout_2->addWidget(comboBox_gender, 2, 1, 1, 2);

        label_19 = new QLabel(gridLayoutWidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setFont(font2);

        gridLayout_2->addWidget(label_19, 7, 0, 1, 1);

        comboBox_type = new QComboBox(gridLayoutWidget);
        comboBox_type->setObjectName(QString::fromUtf8("comboBox_type"));

        gridLayout_2->addWidget(comboBox_type, 3, 1, 1, 2);

        label_22 = new QLabel(gridLayoutWidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setFont(font2);

        gridLayout_2->addWidget(label_22, 9, 0, 1, 1);

        groupBox_3 = new QGroupBox(gridLayoutWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setStyleSheet(QString::fromUtf8(""));
        horizontalLayoutWidget = new QWidget(groupBox_3);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 221, 27));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_pending = new QRadioButton(horizontalLayoutWidget);
        radioButton_pending->setObjectName(QString::fromUtf8("radioButton_pending"));

        horizontalLayout->addWidget(radioButton_pending);

        radioButton_advance = new QRadioButton(horizontalLayoutWidget);
        radioButton_advance->setObjectName(QString::fromUtf8("radioButton_advance"));
        radioButton_advance->setChecked(true);

        horizontalLayout->addWidget(radioButton_advance);


        gridLayout_2->addWidget(groupBox_3, 8, 1, 1, 3);

        groupBox_2 = new QGroupBox(gridLayoutWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setStyleSheet(QString::fromUtf8(""));
        horizontalLayoutWidget_2 = new QWidget(groupBox_2);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(0, 0, 212, 27));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        radioButton_active = new QRadioButton(horizontalLayoutWidget_2);
        radioButton_active->setObjectName(QString::fromUtf8("radioButton_active"));

        horizontalLayout_2->addWidget(radioButton_active);

        radioButton_inactive = new QRadioButton(horizontalLayoutWidget_2);
        radioButton_inactive->setObjectName(QString::fromUtf8("radioButton_inactive"));
        radioButton_inactive->setChecked(true);

        horizontalLayout_2->addWidget(radioButton_inactive);


        gridLayout_2->addWidget(groupBox_2, 9, 1, 1, 3);

        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 190, 300, 29));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton_purchase_back_2 = new QPushButton(layoutWidget);
        pushButton_purchase_back_2->setObjectName(QString::fromUtf8("pushButton_purchase_back_2"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        pushButton_purchase_back_2->setFont(font3);
        pushButton_purchase_back_2->setFocusPolicy(Qt::NoFocus);
        pushButton_purchase_back_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_purchase_back_2->setAutoDefault(true);

        horizontalLayout_4->addWidget(pushButton_purchase_back_2);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        pushButton_edit_enable = new QPushButton(layoutWidget);
        pushButton_edit_enable->setObjectName(QString::fromUtf8("pushButton_edit_enable"));
        pushButton_edit_enable->setFont(font3);
        pushButton_edit_enable->setFocusPolicy(Qt::NoFocus);
        pushButton_edit_enable->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_edit_enable->setAutoDefault(true);

        horizontalLayout_4->addWidget(pushButton_edit_enable);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        pushButton_purchase_save = new QPushButton(layoutWidget);
        pushButton_purchase_save->setObjectName(QString::fromUtf8("pushButton_purchase_save"));
        pushButton_purchase_save->setFont(font3);
        pushButton_purchase_save->setFocusPolicy(Qt::StrongFocus);
        pushButton_purchase_save->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_purchase_save->setAutoDefault(true);

        horizontalLayout_4->addWidget(pushButton_purchase_save);

        QWidget::setTabOrder(lineEdit_emp_name, lineEdit_emp_contact);
        QWidget::setTabOrder(lineEdit_emp_contact, comboBox_gender);
        QWidget::setTabOrder(comboBox_gender, comboBox_type);
        QWidget::setTabOrder(comboBox_type, pushButton_edit_enable);
        QWidget::setTabOrder(pushButton_edit_enable, lineEdit_target);
        QWidget::setTabOrder(lineEdit_target, lineEdit_charges);
        QWidget::setTabOrder(lineEdit_charges, lineEdit_op_balance);
        QWidget::setTabOrder(lineEdit_op_balance, radioButton_pending);
        QWidget::setTabOrder(radioButton_pending, radioButton_advance);
        QWidget::setTabOrder(radioButton_advance, radioButton_active);
        QWidget::setTabOrder(radioButton_active, radioButton_inactive);
        QWidget::setTabOrder(radioButton_inactive, pushButton_purchase_save);
        QWidget::setTabOrder(pushButton_purchase_save, lineEdit_rate_pe_hour);

        retranslateUi(EmployeeMaster);

        QMetaObject::connectSlotsByName(EmployeeMaster);
    } // setupUi

    void retranslateUi(QWidget *EmployeeMaster)
    {
        EmployeeMaster->setWindowTitle(QApplication::translate("EmployeeMaster", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("EmployeeMaster", "Employee Master", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("EmployeeMaster", "Type:", 0, QApplication::UnicodeUTF8));
        label_20->setText(QString());
        label_18->setText(QApplication::translate("EmployeeMaster", "Rate Pre\n"
"Load:", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("EmployeeMaster", "Type:", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("EmployeeMaster", "Name:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("EmployeeMaster", "/Hr", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("EmployeeMaster", "Gender:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("EmployeeMaster", "Contact:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("EmployeeMaster", "Target", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("EmployeeMaster", "Rs.", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("EmployeeMaster", "Daily\n"
"Wages:", 0, QApplication::UnicodeUTF8));
        lineEdit_op_balance->setText(QString());
        label_3->setText(QApplication::translate("EmployeeMaster", "  Charges   ", 0, QApplication::UnicodeUTF8));
        comboBox_gender->clear();
        comboBox_gender->insertItems(0, QStringList()
         << QApplication::translate("EmployeeMaster", "Male", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EmployeeMaster", "Female", 0, QApplication::UnicodeUTF8)
        );
        label_19->setText(QApplication::translate("EmployeeMaster", "Opening\n"
"Balance:", 0, QApplication::UnicodeUTF8));
        comboBox_type->clear();
        comboBox_type->insertItems(0, QStringList()
         << QApplication::translate("EmployeeMaster", "Labour", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EmployeeMaster", "Driver", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EmployeeMaster", "Staff", 0, QApplication::UnicodeUTF8)
        );
        label_22->setText(QApplication::translate("EmployeeMaster", "Status:", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QString());
        radioButton_pending->setText(QApplication::translate("EmployeeMaster", "Pending", 0, QApplication::UnicodeUTF8));
        radioButton_advance->setText(QApplication::translate("EmployeeMaster", "Advance", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QString());
        radioButton_active->setText(QApplication::translate("EmployeeMaster", "Active", 0, QApplication::UnicodeUTF8));
        radioButton_inactive->setText(QApplication::translate("EmployeeMaster", "InActive", 0, QApplication::UnicodeUTF8));
        pushButton_purchase_back_2->setText(QApplication::translate("EmployeeMaster", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_edit_enable->setText(QApplication::translate("EmployeeMaster", "F2-Edit", 0, QApplication::UnicodeUTF8));
        pushButton_purchase_save->setText(QApplication::translate("EmployeeMaster", "Save", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EmployeeMaster: public Ui_EmployeeMaster {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEEMASTER_H
