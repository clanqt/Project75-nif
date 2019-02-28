/********************************************************************************
** Form generated from reading UI file 'batch_close.ui'
**
** Created: Thu Jan 31 08:07:21 2019
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BATCH_CLOSE_H
#define UI_BATCH_CLOSE_H

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

class Ui_Batch_Close
{
public:
    QGroupBox *groupBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_manuf_bale;
    QLabel *label_total_husk;
    QLabel *label_exsess_husk;
    QLabel *label_diff_bale;
    QLabel *label_est_bale;
    QLabel *label_used_husk;
    QLabel *label_excess_title;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_back;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_close;
    QLabel *label_batch_close_title;
    QGroupBox *groupBox_closing_readings;
    QLabel *label_batch_close_title_2;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_generator_reading;
    QSpacerItem *verticalSpacer;
    QLineEdit *lineEdit_bull_reading;
    QLabel *label_10;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_back_reading;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_goto_odo_reading;
    QLabel *label_9;
    QLineEdit *lineEdit_eb_reading;
    QGroupBox *groupBox_odo;
    QLabel *label_batch_close_title_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_back_odo;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_odo_save;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_3;
    QLabel *label_7;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *lineEdit_vehicle_no;
    QLineEdit *lineEdit_odo_reading;

    void setupUi(QWidget *Batch_Close)
    {
        if (Batch_Close->objectName().isEmpty())
            Batch_Close->setObjectName(QString::fromUtf8("Batch_Close"));
        Batch_Close->resize(320, 660);
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font.setPointSize(12);
        Batch_Close->setFont(font);
        groupBox = new QGroupBox(Batch_Close);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 320, 220));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 249, 249);"));
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 30, 300, 184));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_manuf_bale = new QLineEdit(gridLayoutWidget);
        lineEdit_manuf_bale->setObjectName(QString::fromUtf8("lineEdit_manuf_bale"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        lineEdit_manuf_bale->setFont(font1);
        lineEdit_manuf_bale->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(lineEdit_manuf_bale, 2, 1, 1, 1);

        label_total_husk = new QLabel(gridLayoutWidget);
        label_total_husk->setObjectName(QString::fromUtf8("label_total_husk"));
        label_total_husk->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_total_husk, 0, 1, 1, 1);

        label_exsess_husk = new QLabel(gridLayoutWidget);
        label_exsess_husk->setObjectName(QString::fromUtf8("label_exsess_husk"));
        label_exsess_husk->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_exsess_husk, 5, 1, 1, 1);

        label_diff_bale = new QLabel(gridLayoutWidget);
        label_diff_bale->setObjectName(QString::fromUtf8("label_diff_bale"));
        label_diff_bale->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_diff_bale, 3, 1, 1, 1);

        label_est_bale = new QLabel(gridLayoutWidget);
        label_est_bale->setObjectName(QString::fromUtf8("label_est_bale"));
        label_est_bale->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_est_bale, 1, 1, 1, 1);

        label_used_husk = new QLabel(gridLayoutWidget);
        label_used_husk->setObjectName(QString::fromUtf8("label_used_husk"));
        label_used_husk->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_used_husk, 4, 1, 1, 1);

        label_excess_title = new QLabel(gridLayoutWidget);
        label_excess_title->setObjectName(QString::fromUtf8("label_excess_title"));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        label_excess_title->setFont(font2);
        label_excess_title->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_excess_title, 5, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 4, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font2);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font2);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_back = new QPushButton(gridLayoutWidget);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));
        pushButton_back->setFont(font1);
        pushButton_back->setFocusPolicy(Qt::NoFocus);
        pushButton_back->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_back->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_back);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_close = new QPushButton(gridLayoutWidget);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));
        pushButton_close->setFont(font1);
        pushButton_close->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_close->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_close);


        gridLayout->addLayout(horizontalLayout, 6, 0, 1, 2);

        label_batch_close_title = new QLabel(groupBox);
        label_batch_close_title->setObjectName(QString::fromUtf8("label_batch_close_title"));
        label_batch_close_title->setGeometry(QRect(0, 0, 320, 25));
        label_batch_close_title->setFont(font1);
        label_batch_close_title->setAlignment(Qt::AlignCenter);
        groupBox_closing_readings = new QGroupBox(Batch_Close);
        groupBox_closing_readings->setObjectName(QString::fromUtf8("groupBox_closing_readings"));
        groupBox_closing_readings->setGeometry(QRect(0, 220, 320, 220));
        label_batch_close_title_2 = new QLabel(groupBox_closing_readings);
        label_batch_close_title_2->setObjectName(QString::fromUtf8("label_batch_close_title_2"));
        label_batch_close_title_2->setGeometry(QRect(0, 0, 320, 25));
        label_batch_close_title_2->setFont(font2);
        label_batch_close_title_2->setAlignment(Qt::AlignCenter);
        gridLayoutWidget_3 = new QWidget(groupBox_closing_readings);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(10, 30, 307, 180));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_generator_reading = new QLineEdit(gridLayoutWidget_3);
        lineEdit_generator_reading->setObjectName(QString::fromUtf8("lineEdit_generator_reading"));
        lineEdit_generator_reading->setFont(font1);
        lineEdit_generator_reading->setMaxLength(6);

        gridLayout_2->addWidget(lineEdit_generator_reading, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 3, 1, 1, 1);

        lineEdit_bull_reading = new QLineEdit(gridLayoutWidget_3);
        lineEdit_bull_reading->setObjectName(QString::fromUtf8("lineEdit_bull_reading"));
        lineEdit_bull_reading->setFont(font1);
        lineEdit_bull_reading->setMaxLength(6);

        gridLayout_2->addWidget(lineEdit_bull_reading, 0, 1, 1, 1);

        label_10 = new QLabel(gridLayoutWidget_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font1);
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_10, 1, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font1);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_8, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_back_reading = new QPushButton(gridLayoutWidget_3);
        pushButton_back_reading->setObjectName(QString::fromUtf8("pushButton_back_reading"));
        pushButton_back_reading->setFont(font1);
        pushButton_back_reading->setFocusPolicy(Qt::NoFocus);
        pushButton_back_reading->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_back_reading->setAutoDefault(true);

        horizontalLayout_3->addWidget(pushButton_back_reading);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pushButton_goto_odo_reading = new QPushButton(gridLayoutWidget_3);
        pushButton_goto_odo_reading->setObjectName(QString::fromUtf8("pushButton_goto_odo_reading"));
        pushButton_goto_odo_reading->setFont(font1);
        pushButton_goto_odo_reading->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_goto_odo_reading->setAutoDefault(true);

        horizontalLayout_3->addWidget(pushButton_goto_odo_reading);


        gridLayout_2->addLayout(horizontalLayout_3, 4, 0, 1, 2);

        label_9 = new QLabel(gridLayoutWidget_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font1);
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_9, 2, 0, 1, 1);

        lineEdit_eb_reading = new QLineEdit(gridLayoutWidget_3);
        lineEdit_eb_reading->setObjectName(QString::fromUtf8("lineEdit_eb_reading"));
        lineEdit_eb_reading->setFont(font1);
        lineEdit_eb_reading->setMaxLength(6);

        gridLayout_2->addWidget(lineEdit_eb_reading, 2, 1, 1, 1);

        groupBox_odo = new QGroupBox(Batch_Close);
        groupBox_odo->setObjectName(QString::fromUtf8("groupBox_odo"));
        groupBox_odo->setGeometry(QRect(0, 440, 320, 220));
        label_batch_close_title_3 = new QLabel(groupBox_odo);
        label_batch_close_title_3->setObjectName(QString::fromUtf8("label_batch_close_title_3"));
        label_batch_close_title_3->setGeometry(QRect(0, 0, 320, 25));
        label_batch_close_title_3->setFont(font2);
        label_batch_close_title_3->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(groupBox_odo);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 180, 300, 29));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_back_odo = new QPushButton(layoutWidget);
        pushButton_back_odo->setObjectName(QString::fromUtf8("pushButton_back_odo"));
        pushButton_back_odo->setFont(font1);
        pushButton_back_odo->setFocusPolicy(Qt::NoFocus);
        pushButton_back_odo->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_back_odo->setAutoDefault(true);

        horizontalLayout_2->addWidget(pushButton_back_odo);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pushButton_odo_save = new QPushButton(layoutWidget);
        pushButton_odo_save->setObjectName(QString::fromUtf8("pushButton_odo_save"));
        pushButton_odo_save->setFont(font1);
        pushButton_odo_save->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_odo_save->setAutoDefault(true);

        horizontalLayout_2->addWidget(pushButton_odo_save);

        gridLayoutWidget_2 = new QWidget(groupBox_odo);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 30, 300, 140));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(gridLayoutWidget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 1, 0, 1, 1);

        label = new QLabel(gridLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 2, 0, 1, 1);

        lineEdit_vehicle_no = new QLineEdit(gridLayoutWidget_2);
        lineEdit_vehicle_no->setObjectName(QString::fromUtf8("lineEdit_vehicle_no"));

        gridLayout_3->addWidget(lineEdit_vehicle_no, 0, 1, 1, 1);

        lineEdit_odo_reading = new QLineEdit(gridLayoutWidget_2);
        lineEdit_odo_reading->setObjectName(QString::fromUtf8("lineEdit_odo_reading"));

        gridLayout_3->addWidget(lineEdit_odo_reading, 1, 1, 1, 1);

        QWidget::setTabOrder(lineEdit_manuf_bale, pushButton_close);
        QWidget::setTabOrder(pushButton_close, lineEdit_bull_reading);
        QWidget::setTabOrder(lineEdit_bull_reading, lineEdit_generator_reading);
        QWidget::setTabOrder(lineEdit_generator_reading, lineEdit_eb_reading);
        QWidget::setTabOrder(lineEdit_eb_reading, pushButton_goto_odo_reading);
        QWidget::setTabOrder(pushButton_goto_odo_reading, lineEdit_vehicle_no);
        QWidget::setTabOrder(lineEdit_vehicle_no, lineEdit_odo_reading);
        QWidget::setTabOrder(lineEdit_odo_reading, pushButton_odo_save);

        retranslateUi(Batch_Close);

        QMetaObject::connectSlotsByName(Batch_Close);
    } // setupUi

    void retranslateUi(QWidget *Batch_Close)
    {
        Batch_Close->setWindowTitle(QApplication::translate("Batch_Close", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label_total_husk->setText(QString());
        label_exsess_husk->setText(QString());
        label_diff_bale->setText(QString());
        label_est_bale->setText(QString());
        label_used_husk->setText(QString());
        label_excess_title->setText(QApplication::translate("Batch_Close", "Excess Husk:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Batch_Close", "Used Husk:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Batch_Close", "Est.Bale:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Batch_Close", "Diff.Bale:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Batch_Close", "Bale Produced:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Batch_Close", "Total Husk:", 0, QApplication::UnicodeUTF8));
        pushButton_back->setText(QApplication::translate("Batch_Close", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_close->setText(QApplication::translate("Batch_Close", "Close", 0, QApplication::UnicodeUTF8));
        label_batch_close_title->setText(QApplication::translate("Batch_Close", "TextLabel", 0, QApplication::UnicodeUTF8));
        groupBox_closing_readings->setTitle(QString());
        label_batch_close_title_2->setText(QApplication::translate("Batch_Close", "Day Close Reading", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Batch_Close", "Generator :", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Batch_Close", "Bull Meter:", 0, QApplication::UnicodeUTF8));
        pushButton_back_reading->setText(QApplication::translate("Batch_Close", "Ecs-Back", 0, QApplication::UnicodeUTF8));
        pushButton_goto_odo_reading->setText(QApplication::translate("Batch_Close", "Odameter", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Batch_Close", "EB Meter  :", 0, QApplication::UnicodeUTF8));
        groupBox_odo->setTitle(QString());
        label_batch_close_title_3->setText(QApplication::translate("Batch_Close", "Odometer Reading", 0, QApplication::UnicodeUTF8));
        pushButton_back_odo->setText(QApplication::translate("Batch_Close", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_odo_save->setText(QApplication::translate("Batch_Close", "Save-Next", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Batch_Close", "Odometer\n"
"Reading:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Batch_Close", "Vehicle No:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Batch_Close: public Ui_Batch_Close {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATCH_CLOSE_H
