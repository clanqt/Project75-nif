/********************************************************************************
** Form generated from reading UI file 'add_user.ui'
**
** Created: Thu Jan 31 08:07:21 2019
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_USER_H
#define UI_ADD_USER_H

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

class Ui_Add_User
{
public:
    QGroupBox *groupBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_7;
    QLineEdit *lineEdit_designation;
    QLabel *label_2;
    QLabel *label_8;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *lineEdit_user_id;
    QLabel *label_6;
    QLineEdit *lineEdit_modile;
    QComboBox *comboBox_type;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_password;
    QRadioButton *radioButton_inactive;
    QRadioButton *radioButton_active;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_back;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_edit;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_save;

    void setupUi(QWidget *Add_User)
    {
        if (Add_User->objectName().isEmpty())
            Add_User->setObjectName(QString::fromUtf8("Add_User"));
        Add_User->resize(320, 660);
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font.setPointSize(12);
        Add_User->setFont(font);
        groupBox = new QGroupBox(Add_User);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 320, 220));
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 23, 300, 176));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_7, 5, 0, 1, 1);

        lineEdit_designation = new QLineEdit(gridLayoutWidget);
        lineEdit_designation->setObjectName(QString::fromUtf8("lineEdit_designation"));
        QFont font2;
        font2.setPointSize(11);
        lineEdit_designation->setFont(font2);

        gridLayout->addWidget(lineEdit_designation, 4, 1, 1, 2);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font1);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_8, 6, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        lineEdit_user_id = new QLineEdit(gridLayoutWidget);
        lineEdit_user_id->setObjectName(QString::fromUtf8("lineEdit_user_id"));
        lineEdit_user_id->setFont(font2);

        gridLayout->addWidget(lineEdit_user_id, 1, 1, 1, 2);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        lineEdit_modile = new QLineEdit(gridLayoutWidget);
        lineEdit_modile->setObjectName(QString::fromUtf8("lineEdit_modile"));
        lineEdit_modile->setFont(font2);

        gridLayout->addWidget(lineEdit_modile, 2, 1, 1, 2);

        comboBox_type = new QComboBox(gridLayoutWidget);
        comboBox_type->setObjectName(QString::fromUtf8("comboBox_type"));
        comboBox_type->setFont(font2);

        gridLayout->addWidget(comboBox_type, 3, 1, 1, 2);

        lineEdit_name = new QLineEdit(gridLayoutWidget);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setFont(font2);

        gridLayout->addWidget(lineEdit_name, 0, 1, 1, 2);

        lineEdit_password = new QLineEdit(gridLayoutWidget);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setFont(font2);
        lineEdit_password->setMaxLength(4);
        lineEdit_password->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        gridLayout->addWidget(lineEdit_password, 5, 1, 1, 2);

        radioButton_inactive = new QRadioButton(gridLayoutWidget);
        radioButton_inactive->setObjectName(QString::fromUtf8("radioButton_inactive"));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        radioButton_inactive->setFont(font3);

        gridLayout->addWidget(radioButton_inactive, 6, 2, 1, 1);

        radioButton_active = new QRadioButton(gridLayoutWidget);
        radioButton_active->setObjectName(QString::fromUtf8("radioButton_active"));
        radioButton_active->setFont(font3);
        radioButton_active->setChecked(true);

        gridLayout->addWidget(radioButton_active, 6, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 320, 20));
        QFont font4;
        font4.setPointSize(14);
        font4.setBold(true);
        font4.setWeight(75);
        label->setFont(font4);
        label->setAlignment(Qt::AlignCenter);
        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 200, 300, 20));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_back = new QPushButton(widget);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));
        QFont font5;
        font5.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font5.setPointSize(12);
        font5.setBold(true);
        font5.setWeight(75);
        pushButton_back->setFont(font5);
        pushButton_back->setFocusPolicy(Qt::NoFocus);
        pushButton_back->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_back->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_back);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_edit = new QPushButton(widget);
        pushButton_edit->setObjectName(QString::fromUtf8("pushButton_edit"));
        pushButton_edit->setFont(font5);
        pushButton_edit->setFocusPolicy(Qt::NoFocus);
        pushButton_edit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_edit->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_edit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_save = new QPushButton(widget);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        pushButton_save->setFont(font5);
        pushButton_save->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_save->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_save);

        QWidget::setTabOrder(lineEdit_name, lineEdit_user_id);
        QWidget::setTabOrder(lineEdit_user_id, lineEdit_modile);
        QWidget::setTabOrder(lineEdit_modile, comboBox_type);
        QWidget::setTabOrder(comboBox_type, lineEdit_designation);
        QWidget::setTabOrder(lineEdit_designation, lineEdit_password);
        QWidget::setTabOrder(lineEdit_password, pushButton_save);

        retranslateUi(Add_User);

        QMetaObject::connectSlotsByName(Add_User);
    } // setupUi

    void retranslateUi(QWidget *Add_User)
    {
        Add_User->setWindowTitle(QApplication::translate("Add_User", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label_7->setText(QApplication::translate("Add_User", "Password:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Add_User", "Name:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Add_User", "Status:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Add_User", "Mobile:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Add_User", "Type:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Add_User", "User ID:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Add_User", "Desig:", 0, QApplication::UnicodeUTF8));
        comboBox_type->clear();
        comboBox_type->insertItems(0, QStringList()
         << QApplication::translate("Add_User", "Operater", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Add_User", "Manager", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Add_User", "Owner", 0, QApplication::UnicodeUTF8)
        );
        radioButton_inactive->setText(QApplication::translate("Add_User", "InActice", 0, QApplication::UnicodeUTF8));
        radioButton_active->setText(QApplication::translate("Add_User", "Active", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Add_User", "User Configuration", 0, QApplication::UnicodeUTF8));
        pushButton_back->setText(QApplication::translate("Add_User", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_edit->setText(QApplication::translate("Add_User", "F2-Edit", 0, QApplication::UnicodeUTF8));
        pushButton_save->setText(QApplication::translate("Add_User", "Save", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Add_User: public Ui_Add_User {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_USER_H
