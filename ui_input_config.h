/********************************************************************************
** Form generated from reading UI file 'input_config.ui'
**
** Created: Thu Jan 31 08:07:21 2019
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUT_CONFIG_H
#define UI_INPUT_CONFIG_H

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
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Input_Config
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_husk_per_cft;
    QLabel *label_6;
    QLabel *label_5;
    QLineEdit *lineEdit_bull;
    QLineEdit *lineEdit_diesel;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_generator;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_husk_per_bale;
    QLineEdit *lineEdit_cash;
    QLabel *label_site_site_title;
    QLineEdit *lineEdit_eb;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_unit_rs;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_back;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton_save;

    void setupUi(QWidget *Input_Config)
    {
        if (Input_Config->objectName().isEmpty())
            Input_Config->setObjectName(QString::fromUtf8("Input_Config"));
        Input_Config->resize(320, 440);
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font.setPointSize(12);
        Input_Config->setFont(font);
        groupBox = new QGroupBox(Input_Config);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 320, 220));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 249, 249);"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 320, 20));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 300, 200));
        gridLayoutWidget->setFont(font);
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_husk_per_cft = new QLineEdit(gridLayoutWidget);
        lineEdit_husk_per_cft->setObjectName(QString::fromUtf8("lineEdit_husk_per_cft"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        lineEdit_husk_per_cft->setFont(font2);
        lineEdit_husk_per_cft->setMaxLength(6);

        gridLayout->addWidget(lineEdit_husk_per_cft, 0, 1, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font2);

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font2);

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        lineEdit_bull = new QLineEdit(gridLayoutWidget);
        lineEdit_bull->setObjectName(QString::fromUtf8("lineEdit_bull"));
        lineEdit_bull->setFont(font2);
        lineEdit_bull->setMaxLength(6);

        gridLayout->addWidget(lineEdit_bull, 2, 1, 1, 1);

        lineEdit_diesel = new QLineEdit(gridLayoutWidget);
        lineEdit_diesel->setObjectName(QString::fromUtf8("lineEdit_diesel"));
        lineEdit_diesel->setFont(font2);
        lineEdit_diesel->setMaxLength(6);

        gridLayout->addWidget(lineEdit_diesel, 5, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font2);

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        lineEdit_generator = new QLineEdit(gridLayoutWidget);
        lineEdit_generator->setObjectName(QString::fromUtf8("lineEdit_generator"));
        lineEdit_generator->setFont(font2);
        lineEdit_generator->setMaxLength(6);

        gridLayout->addWidget(lineEdit_generator, 3, 1, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font2);

        gridLayout->addWidget(label_7, 3, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font2);

        gridLayout->addWidget(label_8, 4, 0, 1, 1);

        lineEdit_husk_per_bale = new QLineEdit(gridLayoutWidget);
        lineEdit_husk_per_bale->setObjectName(QString::fromUtf8("lineEdit_husk_per_bale"));
        lineEdit_husk_per_bale->setFont(font2);
        lineEdit_husk_per_bale->setMaxLength(6);

        gridLayout->addWidget(lineEdit_husk_per_bale, 1, 1, 1, 1);

        lineEdit_cash = new QLineEdit(gridLayoutWidget);
        lineEdit_cash->setObjectName(QString::fromUtf8("lineEdit_cash"));
        lineEdit_cash->setFont(font2);
        lineEdit_cash->setMaxLength(6);

        gridLayout->addWidget(lineEdit_cash, 6, 1, 1, 1);

        label_site_site_title = new QLabel(gridLayoutWidget);
        label_site_site_title->setObjectName(QString::fromUtf8("label_site_site_title"));
        label_site_site_title->setFont(font2);

        gridLayout->addWidget(label_site_site_title, 6, 0, 1, 1);

        lineEdit_eb = new QLineEdit(gridLayoutWidget);
        lineEdit_eb->setObjectName(QString::fromUtf8("lineEdit_eb"));
        lineEdit_eb->setFont(font2);
        lineEdit_eb->setMaxLength(6);

        gridLayout->addWidget(lineEdit_eb, 4, 1, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font2);

        gridLayout->addWidget(label_9, 0, 2, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font2);

        gridLayout->addWidget(label_10, 1, 2, 1, 1);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font2);

        gridLayout->addWidget(label_11, 2, 2, 1, 1);

        label_12 = new QLabel(gridLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font2);

        gridLayout->addWidget(label_12, 3, 2, 1, 1);

        label_13 = new QLabel(gridLayoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font2);

        gridLayout->addWidget(label_13, 4, 2, 1, 1);

        label_14 = new QLabel(gridLayoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font2);

        gridLayout->addWidget(label_14, 5, 2, 1, 1);

        label_unit_rs = new QLabel(gridLayoutWidget);
        label_unit_rs->setObjectName(QString::fromUtf8("label_unit_rs"));
        label_unit_rs->setFont(font2);

        gridLayout->addWidget(label_unit_rs, 6, 2, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_back = new QPushButton(gridLayoutWidget);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        pushButton_back->setFont(font3);
        pushButton_back->setFocusPolicy(Qt::NoFocus);
        pushButton_back->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_back->setAutoDefault(true);

        horizontalLayout_4->addWidget(pushButton_back);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        pushButton_save = new QPushButton(gridLayoutWidget);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        pushButton_save->setFont(font3);
        pushButton_save->setFocusPolicy(Qt::StrongFocus);
        pushButton_save->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_save->setAutoDefault(true);

        horizontalLayout_4->addWidget(pushButton_save);


        gridLayout->addLayout(horizontalLayout_4, 7, 0, 1, 3);

        QWidget::setTabOrder(lineEdit_husk_per_cft, lineEdit_husk_per_bale);
        QWidget::setTabOrder(lineEdit_husk_per_bale, lineEdit_bull);
        QWidget::setTabOrder(lineEdit_bull, lineEdit_generator);
        QWidget::setTabOrder(lineEdit_generator, lineEdit_eb);
        QWidget::setTabOrder(lineEdit_eb, lineEdit_diesel);
        QWidget::setTabOrder(lineEdit_diesel, lineEdit_cash);
        QWidget::setTabOrder(lineEdit_cash, pushButton_save);

        retranslateUi(Input_Config);

        QMetaObject::connectSlotsByName(Input_Config);
    } // setupUi

    void retranslateUi(QWidget *Input_Config)
    {
        Input_Config->setWindowTitle(QApplication::translate("Input_Config", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("Input_Config", "Input Configuration", 0, QApplication::UnicodeUTF8));
        lineEdit_husk_per_cft->setText(QString());
        label_6->setText(QApplication::translate("Input_Config", "OP Bull Reading:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Input_Config", "OP Diesel Stock:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Input_Config", "Husk Per CFT   :", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Input_Config", "Husk Per Bale  :", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Input_Config", "OP Generator   :", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Input_Config", "OP EB Reading  :", 0, QApplication::UnicodeUTF8));
        lineEdit_cash->setText(QString());
        label_site_site_title->setText(QApplication::translate("Input_Config", "OP Cash at Site:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Input_Config", "Nos", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Input_Config", "Nos", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Input_Config", "Hrs", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Input_Config", "Hrs", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("Input_Config", "U", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("Input_Config", "lts", 0, QApplication::UnicodeUTF8));
        label_unit_rs->setText(QApplication::translate("Input_Config", "Rs", 0, QApplication::UnicodeUTF8));
        pushButton_back->setText(QApplication::translate("Input_Config", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_save->setText(QApplication::translate("Input_Config", "Save", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Input_Config: public Ui_Input_Config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUT_CONFIG_H
