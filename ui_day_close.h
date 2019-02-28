/********************************************************************************
** Form generated from reading UI file 'day_close.ui'
**
** Created: Thu Jan 31 08:07:21 2019
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DAY_CLOSE_H
#define UI_DAY_CLOSE_H

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
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Day_Close
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_back;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_close;
    QLineEdit *lineEdit_closing_bale;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *lineEdit_bale_dispatched;
    QLineEdit *lineEdit_bale_produced;
    QLabel *label_6;
    QLineEdit *lineEdit_op_bale;
    QLabel *label_5;
    QRadioButton *radioButton_vcp;
    QRadioButton *radioButton_nif;
    QLabel *label_info;

    void setupUi(QWidget *Day_Close)
    {
        if (Day_Close->objectName().isEmpty())
            Day_Close->setObjectName(QString::fromUtf8("Day_Close"));
        Day_Close->resize(320, 220);
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font.setPointSize(12);
        Day_Close->setFont(font);
        groupBox = new QGroupBox(Day_Close);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 320, 220));
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 320, 20));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 23, 301, 194));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_back = new QPushButton(gridLayoutWidget);
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

        horizontalLayout->addWidget(pushButton_back);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_close = new QPushButton(gridLayoutWidget);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));
        pushButton_close->setFont(font2);
        pushButton_close->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_close->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_close);


        gridLayout->addLayout(horizontalLayout, 5, 0, 1, 3);

        lineEdit_closing_bale = new QLineEdit(gridLayoutWidget);
        lineEdit_closing_bale->setObjectName(QString::fromUtf8("lineEdit_closing_bale"));
        lineEdit_closing_bale->setFocusPolicy(Qt::NoFocus);
        lineEdit_closing_bale->setReadOnly(true);

        gridLayout->addWidget(lineEdit_closing_bale, 4, 1, 1, 2);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font3;
        font3.setBold(true);
        font3.setWeight(75);
        label_2->setFont(font3);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font3);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font3);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        lineEdit_bale_dispatched = new QLineEdit(gridLayoutWidget);
        lineEdit_bale_dispatched->setObjectName(QString::fromUtf8("lineEdit_bale_dispatched"));

        gridLayout->addWidget(lineEdit_bale_dispatched, 2, 1, 1, 2);

        lineEdit_bale_produced = new QLineEdit(gridLayoutWidget);
        lineEdit_bale_produced->setObjectName(QString::fromUtf8("lineEdit_bale_produced"));

        gridLayout->addWidget(lineEdit_bale_produced, 1, 1, 1, 2);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font3);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        lineEdit_op_bale = new QLineEdit(gridLayoutWidget);
        lineEdit_op_bale->setObjectName(QString::fromUtf8("lineEdit_op_bale"));
        lineEdit_op_bale->setFocusPolicy(Qt::NoFocus);
        lineEdit_op_bale->setReadOnly(true);

        gridLayout->addWidget(lineEdit_op_bale, 0, 1, 1, 2);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font3);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        radioButton_vcp = new QRadioButton(gridLayoutWidget);
        radioButton_vcp->setObjectName(QString::fromUtf8("radioButton_vcp"));

        gridLayout->addWidget(radioButton_vcp, 3, 1, 1, 1);

        radioButton_nif = new QRadioButton(gridLayoutWidget);
        radioButton_nif->setObjectName(QString::fromUtf8("radioButton_nif"));

        gridLayout->addWidget(radioButton_nif, 3, 2, 1, 1);

        label_info = new QLabel(groupBox);
        label_info->setObjectName(QString::fromUtf8("label_info"));
        label_info->setGeometry(QRect(10, 80, 300, 60));
        QFont font4;
        font4.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font4.setPointSize(14);
        font4.setBold(true);
        font4.setWeight(75);
        label_info->setFont(font4);
        label_info->setStyleSheet(QString::fromUtf8("background-color: rgb(183, 255, 251);\n"
"color: rgb(177, 19, 66);"));
        label_info->setAlignment(Qt::AlignCenter);
        label_info->setWordWrap(true);
        label_info->raise();
        label->raise();
        gridLayoutWidget->raise();
        QWidget::setTabOrder(lineEdit_bale_produced, lineEdit_bale_dispatched);
        QWidget::setTabOrder(lineEdit_bale_dispatched, radioButton_vcp);
        QWidget::setTabOrder(radioButton_vcp, radioButton_nif);
        QWidget::setTabOrder(radioButton_nif, pushButton_close);

        retranslateUi(Day_Close);

        QMetaObject::connectSlotsByName(Day_Close);
    } // setupUi

    void retranslateUi(QWidget *Day_Close)
    {
        Day_Close->setWindowTitle(QApplication::translate("Day_Close", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("Day_Close", "Day Close", 0, QApplication::UnicodeUTF8));
        pushButton_back->setText(QApplication::translate("Day_Close", "Esc-Back", 0, QApplication::UnicodeUTF8));
        pushButton_close->setText(QApplication::translate("Day_Close", "Save", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Day_Close", "Bale Dispatched:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Day_Close", "Bale Produced:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Day_Close", "Opening Bale:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Day_Close", "Closing Bale:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Day_Close", "Dispatched To:", 0, QApplication::UnicodeUTF8));
        radioButton_vcp->setText(QApplication::translate("Day_Close", "VCP", 0, QApplication::UnicodeUTF8));
        radioButton_nif->setText(QApplication::translate("Day_Close", "NIF", 0, QApplication::UnicodeUTF8));
        label_info->setText(QApplication::translate("Day_Close", "Sending Text Message...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Day_Close: public Ui_Day_Close {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DAY_CLOSE_H
