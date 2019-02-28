/********************************************************************************
** Form generated from reading UI file 'batch_configuration.ui'
**
** Created: Thu Jan 31 08:07:21 2019
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BATCH_CONFIGURATION_H
#define UI_BATCH_CONFIGURATION_H

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
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Batch_Configuration
{
public:
    QGroupBox *groupBox_batch_home;
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_purchase;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_Production_open;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_esc;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Production_close;
    QLabel *label_info;
    QGroupBox *groupBox_purchase;
    QLabel *label_batch_close_title;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_Company;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_purchase_back;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_auto;
    QPushButton *pushButton_van;
    QGroupBox *groupBox_Production;
    QLabel *label_3;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_2;
    QComboBox *comboBox_batch_1;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_purchase_back_2;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton_purchase_save;
    QComboBox *comboBox_batch_1_no;
    QComboBox *comboBox_batch_2;
    QComboBox *comboBox_batch_3;
    QComboBox *comboBox_batch_2_no;
    QComboBox *comboBox_batch_3_no;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *Batch_Configuration)
    {
        if (Batch_Configuration->objectName().isEmpty())
            Batch_Configuration->setObjectName(QString::fromUtf8("Batch_Configuration"));
        Batch_Configuration->resize(320, 660);
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        Batch_Configuration->setFont(font);
        groupBox_batch_home = new QGroupBox(Batch_Configuration);
        groupBox_batch_home->setObjectName(QString::fromUtf8("groupBox_batch_home"));
        groupBox_batch_home->setGeometry(QRect(0, 0, 320, 220));
        label = new QLabel(groupBox_batch_home);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 320, 25));
        QFont font1;
        font1.setPointSize(14);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        gridLayoutWidget = new QWidget(groupBox_batch_home);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 30, 300, 180));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_purchase = new QPushButton(gridLayoutWidget);
        pushButton_purchase->setObjectName(QString::fromUtf8("pushButton_purchase"));
        pushButton_purchase->setFont(font);
        pushButton_purchase->setFocusPolicy(Qt::StrongFocus);
        pushButton_purchase->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_purchase->setAutoDefault(true);

        gridLayout->addWidget(pushButton_purchase, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 1, 1, 1);

        pushButton_Production_open = new QPushButton(gridLayoutWidget);
        pushButton_Production_open->setObjectName(QString::fromUtf8("pushButton_Production_open"));
        pushButton_Production_open->setFont(font);
        pushButton_Production_open->setFocusPolicy(Qt::StrongFocus);
        pushButton_Production_open->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_Production_open->setAutoDefault(true);

        gridLayout->addWidget(pushButton_Production_open, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_esc = new QPushButton(gridLayoutWidget);
        pushButton_esc->setObjectName(QString::fromUtf8("pushButton_esc"));
        pushButton_esc->setFont(font);
        pushButton_esc->setFocusPolicy(Qt::NoFocus);
        pushButton_esc->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_esc->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_esc);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 3);

        pushButton_Production_close = new QPushButton(gridLayoutWidget);
        pushButton_Production_close->setObjectName(QString::fromUtf8("pushButton_Production_close"));
        pushButton_Production_close->setFont(font);
        pushButton_Production_close->setFocusPolicy(Qt::StrongFocus);
        pushButton_Production_close->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_Production_close->setAutoDefault(true);

        gridLayout->addWidget(pushButton_Production_close, 2, 1, 1, 1);

        pushButton_purchase->raise();
        pushButton_Production_close->raise();
        pushButton_Production_open->raise();
        label_info = new QLabel(groupBox_batch_home);
        label_info->setObjectName(QString::fromUtf8("label_info"));
        label_info->setGeometry(QRect(10, 70, 300, 60));
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        label_info->setFont(font2);
        label_info->setStyleSheet(QString::fromUtf8("background-color: rgb(183, 255, 251);\n"
"color: rgb(177, 19, 66);"));
        label_info->setAlignment(Qt::AlignCenter);
        label_info->setWordWrap(true);
        groupBox_purchase = new QGroupBox(Batch_Configuration);
        groupBox_purchase->setObjectName(QString::fromUtf8("groupBox_purchase"));
        groupBox_purchase->setGeometry(QRect(0, 220, 320, 220));
        label_batch_close_title = new QLabel(groupBox_purchase);
        label_batch_close_title->setObjectName(QString::fromUtf8("label_batch_close_title"));
        label_batch_close_title->setGeometry(QRect(0, 0, 320, 25));
        label_batch_close_title->setFont(font1);
        label_batch_close_title->setAlignment(Qt::AlignCenter);
        gridLayoutWidget_2 = new QWidget(groupBox_purchase);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 30, 300, 180));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_Company = new QPushButton(gridLayoutWidget_2);
        pushButton_Company->setObjectName(QString::fromUtf8("pushButton_Company"));
        pushButton_Company->setFont(font);
        pushButton_Company->setFocusPolicy(Qt::StrongFocus);
        pushButton_Company->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_Company->setAutoDefault(true);

        gridLayout_3->addWidget(pushButton_Company, 0, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 3, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_purchase_back = new QPushButton(gridLayoutWidget_2);
        pushButton_purchase_back->setObjectName(QString::fromUtf8("pushButton_purchase_back"));
        pushButton_purchase_back->setFont(font);
        pushButton_purchase_back->setFocusPolicy(Qt::NoFocus);
        pushButton_purchase_back->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_purchase_back->setAutoDefault(true);

        horizontalLayout_3->addWidget(pushButton_purchase_back);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);


        gridLayout_3->addLayout(horizontalLayout_3, 4, 0, 1, 3);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_6, 1, 2, 1, 1);

        pushButton_auto = new QPushButton(gridLayoutWidget_2);
        pushButton_auto->setObjectName(QString::fromUtf8("pushButton_auto"));
        pushButton_auto->setFont(font);
        pushButton_auto->setFocusPolicy(Qt::StrongFocus);
        pushButton_auto->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_auto->setAutoDefault(true);

        gridLayout_3->addWidget(pushButton_auto, 1, 1, 1, 1);

        pushButton_van = new QPushButton(gridLayoutWidget_2);
        pushButton_van->setObjectName(QString::fromUtf8("pushButton_van"));
        pushButton_van->setFont(font);
        pushButton_van->setFocusPolicy(Qt::StrongFocus);
        pushButton_van->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_van->setAutoDefault(true);

        gridLayout_3->addWidget(pushButton_van, 2, 1, 1, 1);

        groupBox_Production = new QGroupBox(Batch_Configuration);
        groupBox_Production->setObjectName(QString::fromUtf8("groupBox_Production"));
        groupBox_Production->setGeometry(QRect(0, 440, 320, 220));
        label_3 = new QLabel(groupBox_Production);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 0, 320, 25));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);
        gridLayoutWidget_3 = new QWidget(groupBox_Production);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(10, 30, 300, 180));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        comboBox_batch_1 = new QComboBox(gridLayoutWidget_3);
        comboBox_batch_1->setObjectName(QString::fromUtf8("comboBox_batch_1"));
        comboBox_batch_1->setStyleSheet(QString::fromUtf8("QComboBox:focus{background-color: rgb(255, 255, 255);}"));

        gridLayout_2->addWidget(comboBox_batch_1, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_purchase_back_2 = new QPushButton(gridLayoutWidget_3);
        pushButton_purchase_back_2->setObjectName(QString::fromUtf8("pushButton_purchase_back_2"));
        pushButton_purchase_back_2->setFont(font);
        pushButton_purchase_back_2->setFocusPolicy(Qt::NoFocus);
        pushButton_purchase_back_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_purchase_back_2->setAutoDefault(true);

        horizontalLayout_4->addWidget(pushButton_purchase_back_2);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        pushButton_purchase_save = new QPushButton(gridLayoutWidget_3);
        pushButton_purchase_save->setObjectName(QString::fromUtf8("pushButton_purchase_save"));
        pushButton_purchase_save->setFont(font);
        pushButton_purchase_save->setFocusPolicy(Qt::StrongFocus);
        pushButton_purchase_save->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_purchase_save->setAutoDefault(true);

        horizontalLayout_4->addWidget(pushButton_purchase_save);


        gridLayout_2->addLayout(horizontalLayout_4, 4, 0, 1, 2);

        comboBox_batch_1_no = new QComboBox(gridLayoutWidget_3);
        comboBox_batch_1_no->setObjectName(QString::fromUtf8("comboBox_batch_1_no"));
        comboBox_batch_1_no->setStyleSheet(QString::fromUtf8("QComboBox:focus{background-color: rgb(255, 255, 255);}"));

        gridLayout_2->addWidget(comboBox_batch_1_no, 0, 1, 1, 1);

        comboBox_batch_2 = new QComboBox(gridLayoutWidget_3);
        comboBox_batch_2->setObjectName(QString::fromUtf8("comboBox_batch_2"));
        comboBox_batch_2->setStyleSheet(QString::fromUtf8("QComboBox:focus{background-color: rgb(255, 255, 255);}"));

        gridLayout_2->addWidget(comboBox_batch_2, 1, 0, 1, 1);

        comboBox_batch_3 = new QComboBox(gridLayoutWidget_3);
        comboBox_batch_3->setObjectName(QString::fromUtf8("comboBox_batch_3"));
        comboBox_batch_3->setStyleSheet(QString::fromUtf8("QComboBox:focus{background-color: rgb(255, 255, 255);}"));

        gridLayout_2->addWidget(comboBox_batch_3, 2, 0, 1, 1);

        comboBox_batch_2_no = new QComboBox(gridLayoutWidget_3);
        comboBox_batch_2_no->setObjectName(QString::fromUtf8("comboBox_batch_2_no"));
        comboBox_batch_2_no->setStyleSheet(QString::fromUtf8("QComboBox:focus{background-color: rgb(255, 255, 255);}"));

        gridLayout_2->addWidget(comboBox_batch_2_no, 1, 1, 1, 1);

        comboBox_batch_3_no = new QComboBox(gridLayoutWidget_3);
        comboBox_batch_3_no->setObjectName(QString::fromUtf8("comboBox_batch_3_no"));
        comboBox_batch_3_no->setStyleSheet(QString::fromUtf8("QComboBox:focus{background-color: rgb(255, 255, 255);}"));

        gridLayout_2->addWidget(comboBox_batch_3_no, 2, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 3, 0, 1, 1);

        QWidget::setTabOrder(pushButton_purchase, pushButton_Production_open);
        QWidget::setTabOrder(pushButton_Production_open, pushButton_Production_close);
        QWidget::setTabOrder(pushButton_Production_close, pushButton_Company);
        QWidget::setTabOrder(pushButton_Company, pushButton_auto);
        QWidget::setTabOrder(pushButton_auto, pushButton_van);
        QWidget::setTabOrder(pushButton_van, comboBox_batch_1);
        QWidget::setTabOrder(comboBox_batch_1, comboBox_batch_1_no);
        QWidget::setTabOrder(comboBox_batch_1_no, comboBox_batch_2);
        QWidget::setTabOrder(comboBox_batch_2, comboBox_batch_2_no);
        QWidget::setTabOrder(comboBox_batch_2_no, comboBox_batch_3);
        QWidget::setTabOrder(comboBox_batch_3, comboBox_batch_3_no);
        QWidget::setTabOrder(comboBox_batch_3_no, pushButton_purchase_save);

        retranslateUi(Batch_Configuration);

        QMetaObject::connectSlotsByName(Batch_Configuration);
    } // setupUi

    void retranslateUi(QWidget *Batch_Configuration)
    {
        Batch_Configuration->setWindowTitle(QApplication::translate("Batch_Configuration", "Form", 0, QApplication::UnicodeUTF8));
        groupBox_batch_home->setTitle(QString());
        label->setText(QApplication::translate("Batch_Configuration", "Batch Configuration", 0, QApplication::UnicodeUTF8));
        pushButton_purchase->setText(QApplication::translate("Batch_Configuration", "   Purchase   ", 0, QApplication::UnicodeUTF8));
        pushButton_Production_open->setText(QApplication::translate("Batch_Configuration", "Production Open", 0, QApplication::UnicodeUTF8));
        pushButton_esc->setText(QApplication::translate("Batch_Configuration", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_Production_close->setText(QApplication::translate("Batch_Configuration", "Production Close", 0, QApplication::UnicodeUTF8));
        label_info->setText(QApplication::translate("Batch_Configuration", "Sending Text Message...", 0, QApplication::UnicodeUTF8));
        groupBox_purchase->setTitle(QString());
        label_batch_close_title->setText(QApplication::translate("Batch_Configuration", "Purchase Batch Config", 0, QApplication::UnicodeUTF8));
        pushButton_Company->setText(QApplication::translate("Batch_Configuration", "Company Batch Close", 0, QApplication::UnicodeUTF8));
        pushButton_purchase_back->setText(QApplication::translate("Batch_Configuration", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_auto->setText(QApplication::translate("Batch_Configuration", "Auto Batch Close", 0, QApplication::UnicodeUTF8));
        pushButton_van->setText(QApplication::translate("Batch_Configuration", "Van Batch Close", 0, QApplication::UnicodeUTF8));
        groupBox_Production->setTitle(QString());
        label_3->setText(QApplication::translate("Batch_Configuration", "Production Batch Config", 0, QApplication::UnicodeUTF8));
        pushButton_purchase_back_2->setText(QApplication::translate("Batch_Configuration", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_purchase_save->setText(QApplication::translate("Batch_Configuration", "F1-Save", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Batch_Configuration: public Ui_Batch_Configuration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATCH_CONFIGURATION_H
