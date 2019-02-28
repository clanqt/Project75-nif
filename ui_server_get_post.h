/********************************************************************************
** Form generated from reading UI file 'server_get_post.ui'
**
** Created: Thu Jan 31 08:07:21 2019
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_GET_POST_H
#define UI_SERVER_GET_POST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Server_Get_Post
{
public:

    void setupUi(QWidget *Server_Get_Post)
    {
        if (Server_Get_Post->objectName().isEmpty())
            Server_Get_Post->setObjectName(QString::fromUtf8("Server_Get_Post"));
        Server_Get_Post->resize(320, 220);
        Server_Get_Post->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 249, 249);"));

        retranslateUi(Server_Get_Post);

        QMetaObject::connectSlotsByName(Server_Get_Post);
    } // setupUi

    void retranslateUi(QWidget *Server_Get_Post)
    {
        Server_Get_Post->setWindowTitle(QApplication::translate("Server_Get_Post", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Server_Get_Post: public Ui_Server_Get_Post {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_GET_POST_H
