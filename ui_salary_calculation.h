/********************************************************************************
** Form generated from reading UI file 'salary_calculation.ui'
**
** Created: Thu Jan 31 08:07:21 2019
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALARY_CALCULATION_H
#define UI_SALARY_CALCULATION_H

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
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Salary_Calculation
{
public:
    QGroupBox *groupBox_attendance;
    QLabel *label_2;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label_hrs;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_attendance;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_close;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_save_emp_salary;
    QCheckBox *checkBox_target;
    QLineEdit *lineEdit_hrs;
    QLineEdit *lineEdit_bale_produced;
    QLabel *label;
    QComboBox *comboBox_name;
    QCheckBox *checkBox_hrs;

    void setupUi(QWidget *Salary_Calculation)
    {
        if (Salary_Calculation->objectName().isEmpty())
            Salary_Calculation->setObjectName(QString::fromUtf8("Salary_Calculation"));
        Salary_Calculation->resize(320, 660);
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font.setPointSize(12);
        Salary_Calculation->setFont(font);
        groupBox_attendance = new QGroupBox(Salary_Calculation);
        groupBox_attendance->setObjectName(QString::fromUtf8("groupBox_attendance"));
        groupBox_attendance->setGeometry(QRect(0, 0, 320, 220));
        label_2 = new QLabel(groupBox_attendance);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 320, 25));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        gridLayoutWidget = new QWidget(groupBox_attendance);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 30, 300, 180));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        label_3->setFont(font2);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font2);

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        label_hrs = new QLabel(gridLayoutWidget);
        label_hrs->setObjectName(QString::fromUtf8("label_hrs"));
        label_hrs->setFont(font2);

        gridLayout->addWidget(label_hrs, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_attendance = new QPushButton(gridLayoutWidget);
        pushButton_attendance->setObjectName(QString::fromUtf8("pushButton_attendance"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        pushButton_attendance->setFont(font3);
        pushButton_attendance->setFocusPolicy(Qt::NoFocus);
        pushButton_attendance->setStyleSheet(QString::fromUtf8("QPushButton:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        pushButton_attendance->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_attendance);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_close = new QPushButton(gridLayoutWidget);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));
        pushButton_close->setFont(font3);
        pushButton_close->setFocusPolicy(Qt::NoFocus);
        pushButton_close->setStyleSheet(QString::fromUtf8("QPushButton:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        pushButton_close->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_close);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_save_emp_salary = new QPushButton(gridLayoutWidget);
        pushButton_save_emp_salary->setObjectName(QString::fromUtf8("pushButton_save_emp_salary"));
        pushButton_save_emp_salary->setFont(font3);
        pushButton_save_emp_salary->setStyleSheet(QString::fromUtf8("QPushButton:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));
        pushButton_save_emp_salary->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_save_emp_salary);


        gridLayout->addLayout(horizontalLayout, 5, 0, 1, 3);

        checkBox_target = new QCheckBox(gridLayoutWidget);
        checkBox_target->setObjectName(QString::fromUtf8("checkBox_target"));
        checkBox_target->setFont(font3);
        checkBox_target->setStyleSheet(QString::fromUtf8("QCheckBox:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));

        gridLayout->addWidget(checkBox_target, 2, 1, 1, 1);

        lineEdit_hrs = new QLineEdit(gridLayoutWidget);
        lineEdit_hrs->setObjectName(QString::fromUtf8("lineEdit_hrs"));
        lineEdit_hrs->setFont(font2);
        lineEdit_hrs->setStyleSheet(QString::fromUtf8("QLineEdit:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));

        gridLayout->addWidget(lineEdit_hrs, 3, 1, 1, 2);

        lineEdit_bale_produced = new QLineEdit(gridLayoutWidget);
        lineEdit_bale_produced->setObjectName(QString::fromUtf8("lineEdit_bale_produced"));
        lineEdit_bale_produced->setFont(font2);

        gridLayout->addWidget(lineEdit_bale_produced, 1, 1, 1, 2);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font2);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBox_name = new QComboBox(gridLayoutWidget);
        comboBox_name->setObjectName(QString::fromUtf8("comboBox_name"));
        comboBox_name->setFont(font2);
        comboBox_name->setStyleSheet(QString::fromUtf8("QComboBox:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));

        gridLayout->addWidget(comboBox_name, 0, 1, 1, 2);

        checkBox_hrs = new QCheckBox(gridLayoutWidget);
        checkBox_hrs->setObjectName(QString::fromUtf8("checkBox_hrs"));
        checkBox_hrs->setFont(font2);
        checkBox_hrs->setStyleSheet(QString::fromUtf8("QCheckBox:focus{border:3px solid red;background-color: rgb(255, 255, 255);}"));

        gridLayout->addWidget(checkBox_hrs, 2, 2, 1, 1);

        QWidget::setTabOrder(comboBox_name, lineEdit_bale_produced);
        QWidget::setTabOrder(lineEdit_bale_produced, checkBox_target);
        QWidget::setTabOrder(checkBox_target, checkBox_hrs);
        QWidget::setTabOrder(checkBox_hrs, lineEdit_hrs);
        QWidget::setTabOrder(lineEdit_hrs, pushButton_save_emp_salary);
        QWidget::setTabOrder(pushButton_save_emp_salary, pushButton_attendance);

        retranslateUi(Salary_Calculation);

        QMetaObject::connectSlotsByName(Salary_Calculation);
    } // setupUi

    void retranslateUi(QWidget *Salary_Calculation)
    {
        Salary_Calculation->setWindowTitle(QApplication::translate("Salary_Calculation", "Form", 0, QApplication::UnicodeUTF8));
        groupBox_attendance->setTitle(QString());
        label_2->setText(QApplication::translate("Salary_Calculation", "Employee Attendance", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Salary_Calculation", "Work Mode :", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Salary_Calculation", "Total Bale:", 0, QApplication::UnicodeUTF8));
        label_hrs->setText(QApplication::translate("Salary_Calculation", "Work Hours:", 0, QApplication::UnicodeUTF8));
        pushButton_attendance->setText(QApplication::translate("Salary_Calculation", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_close->setText(QApplication::translate("Salary_Calculation", "Fn-Close", 0, QApplication::UnicodeUTF8));
        pushButton_save_emp_salary->setText(QApplication::translate("Salary_Calculation", "F1-Next", 0, QApplication::UnicodeUTF8));
        checkBox_target->setText(QApplication::translate("Salary_Calculation", "Target", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Salary_Calculation", "Name      :", 0, QApplication::UnicodeUTF8));
        checkBox_hrs->setText(QApplication::translate("Salary_Calculation", "Hourly", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Salary_Calculation: public Ui_Salary_Calculation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALARY_CALCULATION_H
