/********************************************************************************
** Form generated from reading UI file 'datatransfer.ui'
**
** Created: Thu Jan 31 08:07:21 2019
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATATRANSFER_H
#define UI_DATATRANSFER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataTransfer
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QPushButton *pushButton_cancel;
    QLabel *label_status;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_upload;
    QPushButton *pushButton_download;
    QPushButton *pushButton_backup;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton_PC;
    QRadioButton *radioButton_USB;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_select;
    QComboBox *comboBox_db_csv;
    QPushButton *pushButton;
    QLabel *label_db_csv;
    QComboBox *comboBox_select;
    QLabel *label_Export_Import;
    QLabel *label_2;

    void setupUi(QDialog *DataTransfer)
    {
        if (DataTransfer->objectName().isEmpty())
            DataTransfer->setObjectName(QString::fromUtf8("DataTransfer"));
        DataTransfer->resize(320, 857);
        DataTransfer->setStyleSheet(QString::fromUtf8(""));
        groupBox = new QGroupBox(DataTransfer);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 320, 821));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        groupBox->setFont(font);
        groupBox->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 320, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setUnderline(false);
        font1.setWeight(75);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);
        pushButton_cancel = new QPushButton(groupBox);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(20, 190, 110, 30));
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        pushButton_cancel->setFont(font2);
        pushButton_cancel->setAutoDefault(false);
        pushButton_cancel->setDefault(false);
        label_status = new QLabel(groupBox);
        label_status->setObjectName(QString::fromUtf8("label_status"));
        label_status->setGeometry(QRect(0, 150, 320, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font3.setPointSize(18);
        font3.setBold(true);
        font3.setWeight(75);
        label_status->setFont(font3);
        label_status->setStyleSheet(QString::fromUtf8(""));
        label_status->setAlignment(Qt::AlignCenter);
        label_status->setWordWrap(true);
        verticalLayoutWidget = new QWidget(groupBox);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 50, 320, 104));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(100, 0, 100, 0);
        pushButton_upload = new QPushButton(verticalLayoutWidget);
        pushButton_upload->setObjectName(QString::fromUtf8("pushButton_upload"));
        pushButton_upload->setFont(font2);

        verticalLayout->addWidget(pushButton_upload);

        pushButton_download = new QPushButton(verticalLayoutWidget);
        pushButton_download->setObjectName(QString::fromUtf8("pushButton_download"));
        pushButton_download->setFont(font2);

        verticalLayout->addWidget(pushButton_download);

        pushButton_backup = new QPushButton(verticalLayoutWidget);
        pushButton_backup->setObjectName(QString::fromUtf8("pushButton_backup"));
        pushButton_backup->setFont(font2);

        verticalLayout->addWidget(pushButton_backup);

        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(1, 20, 319, 30));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(25, 0, 25, 0);
        radioButton_PC = new QRadioButton(horizontalLayoutWidget);
        radioButton_PC->setObjectName(QString::fromUtf8("radioButton_PC"));
        radioButton_PC->setFont(font2);

        horizontalLayout_2->addWidget(radioButton_PC);

        radioButton_USB = new QRadioButton(horizontalLayoutWidget);
        radioButton_USB->setObjectName(QString::fromUtf8("radioButton_USB"));
        radioButton_USB->setFont(font2);

        horizontalLayout_2->addWidget(radioButton_USB);

        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 50, 320, 104));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(10, 0, 20, 0);
        label_select = new QLabel(gridLayoutWidget);
        label_select->setObjectName(QString::fromUtf8("label_select"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        label_select->setFont(font4);
        label_select->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_select, 1, 0, 1, 1);

        comboBox_db_csv = new QComboBox(gridLayoutWidget);
        comboBox_db_csv->setObjectName(QString::fromUtf8("comboBox_db_csv"));
        QFont font5;
        font5.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font5.setPointSize(14);
        comboBox_db_csv->setFont(font5);

        gridLayout->addWidget(comboBox_db_csv, 0, 1, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font2);

        gridLayout->addWidget(pushButton, 2, 1, 1, 1);

        label_db_csv = new QLabel(gridLayoutWidget);
        label_db_csv->setObjectName(QString::fromUtf8("label_db_csv"));
        label_db_csv->setFont(font4);
        label_db_csv->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_db_csv, 0, 0, 1, 1);

        comboBox_select = new QComboBox(gridLayoutWidget);
        comboBox_select->setObjectName(QString::fromUtf8("comboBox_select"));
        comboBox_select->setFont(font5);

        gridLayout->addWidget(comboBox_select, 1, 1, 1, 1);

        gridLayout->setColumnStretch(1, 1);
        label_Export_Import = new QLabel(groupBox);
        label_Export_Import->setObjectName(QString::fromUtf8("label_Export_Import"));
        label_Export_Import->setGeometry(QRect(0, 20, 110, 20));
        QFont font6;
        font6.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font6.setPointSize(14);
        font6.setBold(true);
        font6.setUnderline(true);
        font6.setWeight(75);
        label_Export_Import->setFont(font6);
        label_Export_Import->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, -10, 320, 691));
        label_Export_Import->raise();
        label_2->raise();
        label->raise();
        verticalLayoutWidget->raise();
        horizontalLayoutWidget->raise();
        gridLayoutWidget->raise();
        label_status->raise();
        pushButton_cancel->raise();
        QWidget::setTabOrder(radioButton_PC, radioButton_USB);
        QWidget::setTabOrder(radioButton_USB, pushButton_upload);
        QWidget::setTabOrder(pushButton_upload, pushButton_download);
        QWidget::setTabOrder(pushButton_download, pushButton_backup);
        QWidget::setTabOrder(pushButton_backup, comboBox_db_csv);
        QWidget::setTabOrder(comboBox_db_csv, comboBox_select);
        QWidget::setTabOrder(comboBox_select, pushButton);
        QWidget::setTabOrder(pushButton, pushButton_cancel);

        retranslateUi(DataTransfer);

        QMetaObject::connectSlotsByName(DataTransfer);
    } // setupUi

    void retranslateUi(QDialog *DataTransfer)
    {
        DataTransfer->setWindowTitle(QApplication::translate("DataTransfer", "DataTransfer", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("DataTransfer", "Data Transfer", 0, QApplication::UnicodeUTF8));
        pushButton_cancel->setText(QApplication::translate("DataTransfer", "Esc-Back", 0, QApplication::UnicodeUTF8));
        label_status->setText(QString());
        pushButton_upload->setText(QApplication::translate("DataTransfer", "Export", 0, QApplication::UnicodeUTF8));
        pushButton_download->setText(QApplication::translate("DataTransfer", "Import", 0, QApplication::UnicodeUTF8));
        pushButton_backup->setText(QApplication::translate("DataTransfer", "Backup", 0, QApplication::UnicodeUTF8));
        radioButton_PC->setText(QApplication::translate("DataTransfer", "PC", 0, QApplication::UnicodeUTF8));
        radioButton_USB->setText(QApplication::translate("DataTransfer", "ThumbDrive", 0, QApplication::UnicodeUTF8));
        label_select->setText(QApplication::translate("DataTransfer", "Table:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("DataTransfer", "Export", 0, QApplication::UnicodeUTF8));
        label_db_csv->setText(QApplication::translate("DataTransfer", "Export As:", 0, QApplication::UnicodeUTF8));
        label_Export_Import->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DataTransfer: public Ui_DataTransfer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATATRANSFER_H
