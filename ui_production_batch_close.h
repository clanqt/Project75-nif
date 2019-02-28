/********************************************************************************
** Form generated from reading UI file 'production_batch_close.ui'
**
** Created: Thu Jan 31 08:07:21 2019
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTION_BATCH_CLOSE_H
#define UI_PRODUCTION_BATCH_CLOSE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Production_batch_close
{
public:
    QGroupBox *groupBox;
    QLabel *label;

    void setupUi(QWidget *Production_batch_close)
    {
        if (Production_batch_close->objectName().isEmpty())
            Production_batch_close->setObjectName(QString::fromUtf8("Production_batch_close"));
        Production_batch_close->resize(320, 220);
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        Production_batch_close->setFont(font);
        groupBox = new QGroupBox(Production_batch_close);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 320, 220));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 320, 20));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(Production_batch_close);

        QMetaObject::connectSlotsByName(Production_batch_close);
    } // setupUi

    void retranslateUi(QWidget *Production_batch_close)
    {
        Production_batch_close->setWindowTitle(QApplication::translate("Production_batch_close", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("Production_batch_close", "Production Batch Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Production_batch_close: public Ui_Production_batch_close {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTION_BATCH_CLOSE_H
