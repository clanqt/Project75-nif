/********************************************************************************
** Form generated from reading UI file 'rate_config.ui'
**
** Created: Thu Jan 31 08:07:21 2019
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RATE_CONFIG_H
#define UI_RATE_CONFIG_H

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
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Rate_Config
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_HP_cft;
    QPushButton *pushButton_HP_bale;
    QPushButton *pushButton_RP_cft;
    QPushButton *pushButton_RP_husk;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_8;
    QLineEdit *lineEdit_auto_cft;
    QLineEdit *lineEdit_auto_count;
    QLineEdit *lineEdit_company_cft;
    QLineEdit *lineEdit_van_count;
    QLineEdit *lineEdit_van_rate;
    QLineEdit *lineEdit_company_count;
    QLabel *label_info;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_back;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton_save;

    void setupUi(QWidget *Rate_Config)
    {
        if (Rate_Config->objectName().isEmpty())
            Rate_Config->setObjectName(QString::fromUtf8("Rate_Config"));
        Rate_Config->resize(320, 660);
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font.setPointSize(12);
        Rate_Config->setFont(font);
        Rate_Config->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 249, 249);"));
        groupBox = new QGroupBox(Rate_Config);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 320, 220));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 320, 20));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget = new QWidget(groupBox);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 430, 300, 156));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(50, 0, 50, 0);
        pushButton_HP_cft = new QPushButton(verticalLayoutWidget);
        pushButton_HP_cft->setObjectName(QString::fromUtf8("pushButton_HP_cft"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        pushButton_HP_cft->setFont(font2);
        pushButton_HP_cft->setAutoDefault(true);

        verticalLayout->addWidget(pushButton_HP_cft);

        pushButton_HP_bale = new QPushButton(verticalLayoutWidget);
        pushButton_HP_bale->setObjectName(QString::fromUtf8("pushButton_HP_bale"));
        pushButton_HP_bale->setFont(font2);
        pushButton_HP_bale->setAutoDefault(true);

        verticalLayout->addWidget(pushButton_HP_bale);

        pushButton_RP_cft = new QPushButton(verticalLayoutWidget);
        pushButton_RP_cft->setObjectName(QString::fromUtf8("pushButton_RP_cft"));
        pushButton_RP_cft->setFont(font2);
        pushButton_RP_cft->setAutoDefault(true);

        verticalLayout->addWidget(pushButton_RP_cft);

        pushButton_RP_husk = new QPushButton(verticalLayoutWidget);
        pushButton_RP_husk->setObjectName(QString::fromUtf8("pushButton_RP_husk"));
        pushButton_RP_husk->setFont(font2);
        pushButton_RP_husk->setAutoDefault(true);

        verticalLayout->addWidget(pushButton_RP_husk);

        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 300, 160));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 5, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        gridLayout->addWidget(label_8, 1, 0, 1, 1);

        lineEdit_auto_cft = new QLineEdit(gridLayoutWidget);
        lineEdit_auto_cft->setObjectName(QString::fromUtf8("lineEdit_auto_cft"));
        lineEdit_auto_cft->setMaxLength(6);

        gridLayout->addWidget(lineEdit_auto_cft, 0, 1, 1, 1);

        lineEdit_auto_count = new QLineEdit(gridLayoutWidget);
        lineEdit_auto_count->setObjectName(QString::fromUtf8("lineEdit_auto_count"));
        lineEdit_auto_count->setMaxLength(6);

        gridLayout->addWidget(lineEdit_auto_count, 1, 1, 1, 1);

        lineEdit_company_cft = new QLineEdit(gridLayoutWidget);
        lineEdit_company_cft->setObjectName(QString::fromUtf8("lineEdit_company_cft"));
        lineEdit_company_cft->setMaxLength(6);

        gridLayout->addWidget(lineEdit_company_cft, 2, 1, 1, 1);

        lineEdit_van_count = new QLineEdit(gridLayoutWidget);
        lineEdit_van_count->setObjectName(QString::fromUtf8("lineEdit_van_count"));
        lineEdit_van_count->setMaxLength(6);

        gridLayout->addWidget(lineEdit_van_count, 5, 1, 1, 1);

        lineEdit_van_rate = new QLineEdit(gridLayoutWidget);
        lineEdit_van_rate->setObjectName(QString::fromUtf8("lineEdit_van_rate"));
        lineEdit_van_rate->setMaxLength(6);

        gridLayout->addWidget(lineEdit_van_rate, 4, 1, 1, 1);

        lineEdit_company_count = new QLineEdit(gridLayoutWidget);
        lineEdit_company_count->setObjectName(QString::fromUtf8("lineEdit_company_count"));
        lineEdit_company_count->setMaxLength(6);

        gridLayout->addWidget(lineEdit_company_count, 3, 1, 1, 1);

        label_info = new QLabel(groupBox);
        label_info->setObjectName(QString::fromUtf8("label_info"));
        label_info->setGeometry(QRect(10, 80, 300, 60));
        QFont font3;
        font3.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        label_info->setFont(font3);
        label_info->setStyleSheet(QString::fromUtf8("background-color: rgb(183, 255, 251);\n"
"color: rgb(177, 19, 66);"));
        label_info->setAlignment(Qt::AlignCenter);
        label_info->setWordWrap(true);
        layoutWidget = new QWidget(Rate_Config);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 180, 300, 29));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton_back = new QPushButton(layoutWidget);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));
        pushButton_back->setFont(font2);
        pushButton_back->setFocusPolicy(Qt::NoFocus);
        pushButton_back->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_back->setAutoDefault(true);

        horizontalLayout_4->addWidget(pushButton_back);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        pushButton_save = new QPushButton(layoutWidget);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        pushButton_save->setFont(font2);
        pushButton_save->setFocusPolicy(Qt::StrongFocus);
        pushButton_save->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_save->setAutoDefault(true);

        horizontalLayout_4->addWidget(pushButton_save);

        QWidget::setTabOrder(lineEdit_auto_cft, lineEdit_auto_count);
        QWidget::setTabOrder(lineEdit_auto_count, lineEdit_company_cft);
        QWidget::setTabOrder(lineEdit_company_cft, lineEdit_company_count);
        QWidget::setTabOrder(lineEdit_company_count, lineEdit_van_rate);
        QWidget::setTabOrder(lineEdit_van_rate, lineEdit_van_count);
        QWidget::setTabOrder(lineEdit_van_count, pushButton_HP_cft);
        QWidget::setTabOrder(pushButton_HP_cft, pushButton_HP_bale);
        QWidget::setTabOrder(pushButton_HP_bale, pushButton_RP_cft);
        QWidget::setTabOrder(pushButton_RP_cft, pushButton_RP_husk);

        retranslateUi(Rate_Config);

        QMetaObject::connectSlotsByName(Rate_Config);
    } // setupUi

    void retranslateUi(QWidget *Rate_Config)
    {
        Rate_Config->setWindowTitle(QApplication::translate("Rate_Config", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("Rate_Config", "Rate Configuration", 0, QApplication::UnicodeUTF8));
        pushButton_HP_cft->setText(QApplication::translate("Rate_Config", "Husk Per CFT", 0, QApplication::UnicodeUTF8));
        pushButton_HP_bale->setText(QApplication::translate("Rate_Config", "Husk Per Bale", 0, QApplication::UnicodeUTF8));
        pushButton_RP_cft->setText(QApplication::translate("Rate_Config", "Rate Per CFT", 0, QApplication::UnicodeUTF8));
        pushButton_RP_husk->setText(QApplication::translate("Rate_Config", "Rate Per Hush", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Rate_Config", "Van Count Rate    :", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Rate_Config", "Auto CFT Rate     :", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Rate_Config", "Company CFT Rate  :", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Rate_Config", "Van CFT Rate      :", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Rate_Config", "Company Count Rate:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Rate_Config", "Auto Count Rate   :", 0, QApplication::UnicodeUTF8));
        label_info->setText(QApplication::translate("Rate_Config", "Sending Text Message...", 0, QApplication::UnicodeUTF8));
        pushButton_back->setText(QApplication::translate("Rate_Config", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_save->setText(QApplication::translate("Rate_Config", "Save", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Rate_Config: public Ui_Rate_Config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RATE_CONFIG_H
