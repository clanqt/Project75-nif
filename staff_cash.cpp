#include "staff_cash.h"
#include "ui_staff_cash.h"

#include <qdebug.h>
#include <QMessageBox>

#include <global.h>
using namespace Global;

Staff_Cash::Staff_Cash(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Staff_Cash)
{
    ui->setupUi(this);

#if(NativeCompile)
    setParent(mdi,Qt::Dialog);
#endif

#if(SDK75)
    setParent(MdiArea,Qt::Dialog);
#endif
    setWindowFlags(Qt::FramelessWindowHint);
    setFocusPolicy(Qt::NoFocus);
    setFixedSize(320,240);

}

Staff_Cash::~Staff_Cash()
{
    delete ui;
}

void Staff_Cash::call_Staff_Cash()
{
    ui->groupBox_from->move(0,0);
    ui->groupBox_to->move(0,0);
    ui->groupBox_home->move(0,0);

    ui->groupBox_from->hide();
    ui->groupBox_to->hide();

//    from_day_open = false;

    ui->lineEdit_from_hand_cash->clear();
    ui->comboBox_from_cash_from->clear();
    ui->lineEdit_from_cash_recv->clear();
    ui->lineEdit_from_aval_cash->clear();

    ui->lineEdit_from_hand_cash_2->clear();
    ui->comboBox_from_cash_from_2->clear();
    ui->lineEdit_from_cash_recv_2->clear();
    ui->lineEdit_from_aval_cash_2->clear();

    ui->pushButton_from_save->setEnabled(false);
    ui->pushButton_from_save_2->setEnabled(false);

//    ui->lineEdit_from_hand_cash->installEventFilter(this);
    ui->comboBox_from_cash_from->installEventFilter(this);
    ui->lineEdit_from_cash_recv->installEventFilter(this);

//    ui->lineEdit_from_hand_cash_2->installEventFilter(this);
    ui->comboBox_from_cash_from_2->installEventFilter(this);
    ui->lineEdit_from_cash_recv_2->installEventFilter(this);


    ui->groupBox_home->show();
    ui->groupBox_home->raise();

    if(from_day_open)
    {
        ui->pushButton_back->hide();
        ui->pushButton_back_2->hide();
    }

    if(gstrUserType.toInt() == 0)
    {
        ui->pushButton_to->hide();
    }


    ui->pushButton_from->setFocus();

}

void Staff_Cash::keyPressEvent(QKeyEvent *ke)
{
    if(ke->key()== Qt::Key_Escape)
    {

        if(ui->groupBox_from->isVisible())
        {
            this->close();
            menuObj->call_menu();
            menuObj->show();
            return;
        }
        if(ui->groupBox_to->isVisible())
        {
            this->close();
//            PaymentObj->is_payment = false;
            PaymentObj->call_Payment();
            PaymentObj->show();
            return;
        }


//        if(!from_day_open)
//        {
//            if(ui->groupBox_from->isVisible() || ui->groupBox_to->isVisible())
//            {
//                call_Staff_Cash();
//            }
//        }
//        if(ui->groupBox_home->isVisible())
//        {
//            this->close();
////            PaymentObj->is_payment = false;
//            PaymentObj->call_Payment();
//            PaymentObj->show();
//        }
    }
}

bool Staff_Cash::eventFilter(QObject *target, QEvent *event)
{
    QKeyEvent *key = static_cast <QKeyEvent*> (event);

    if(target == ui->comboBox_from_cash_from)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->comboBox_from_cash_from->hasFocus())
                {
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                    ui->lineEdit_from_cash_recv->setFocus();
                    return true;
                }
            }
        }
    }
    else if(target == ui->comboBox_from_cash_from_2)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->comboBox_from_cash_from_2->hasFocus())
                {
                    if(!ui->comboBox_from_cash_from_2->currentText().isEmpty())
                    {
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                        ui->lineEdit_from_cash_recv_2->setFocus();
                    }
                    else
                    {
                        //! operator not available
                    }
                    return true;
                }
            }
        }
    }
    else if(target == ui->lineEdit_from_cash_recv)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->lineEdit_from_cash_recv->hasFocus())
                {
                    if(!ui->lineEdit_from_cash_recv->text().trimmed().isEmpty())
                    {
                        ui->lineEdit_from_aval_cash->setText(QString::number(ui->lineEdit_from_hand_cash->text().toFloat() + ui->lineEdit_from_cash_recv->text().toFloat(),'f',2));
                        ui->pushButton_from_save->setEnabled(true);
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                        ui->pushButton_from_save->setFocus();
                    }
                    else
                    {

                    }
                    return true;
                }
            }
        }
    }
    else if(target == ui->lineEdit_from_cash_recv_2)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->lineEdit_from_cash_recv_2->hasFocus())
                {
                    if(ui->lineEdit_from_cash_recv_2->text().toFloat() <= ui->lineEdit_from_hand_cash_2->text().toFloat())
                    {
                        ui->lineEdit_from_aval_cash_2->setText(QString::number(ui->lineEdit_from_hand_cash_2->text().toFloat() - ui->lineEdit_from_cash_recv_2->text().toFloat(),'f',2));
                        ui->pushButton_from_save_2->setEnabled(true);
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                        ui->pushButton_from_save_2->setFocus();
                    }
                    else
                    {

                    }
                    return true;
                }
            }
        }
    }
    else
    {
        return false;
    }
    return false;
}

void Staff_Cash::on_pushButton_from_clicked()
{
    ui->groupBox_home->hide();
    ui->groupBox_to->hide();

    ui->lineEdit_from_hand_cash->clear();
    ui->comboBox_from_cash_from->clear();
    ui->lineEdit_from_cash_recv->clear();
    ui->lineEdit_from_aval_cash->clear();

    ui->groupBox_from->show();
    ui->groupBox_from->raise();

    QSqlQuery query;
    if(databaseObj->selectQuery("select aval_cash from user_master where user_name='"+gstrUserName+"'",query))
    {
        if(query.next())
        {
            ui->lineEdit_from_hand_cash->setText(query.value(0).toString().trimmed());
        }
    }

    if(gstrUserType.toInt() == 0)
    {
        lst_from.clear();
        lst_from << "Manager" << "Company";
        ui->comboBox_from_cash_from->addItems(lst_from);
    }
    if(gstrUserType.toInt() == 1)
    {
        lst_from.clear();
        lst_from << "Company";
        ui->comboBox_from_cash_from->addItems(lst_from);
    }
    if(gstrUserType.toInt() == 2)
    {

    }
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif

    ui->comboBox_from_cash_from->setFocus();

}

void Staff_Cash::on_pushButton_to_clicked()
{
    ui->groupBox_home->hide();
    ui->groupBox_from->hide();

    ui->lineEdit_from_hand_cash_2->clear();
    ui->comboBox_from_cash_from_2->clear();
    ui->lineEdit_from_cash_recv_2->clear();
    ui->lineEdit_from_aval_cash_2->clear();

    ui->groupBox_to->show();
    ui->groupBox_to->raise();

    QSqlQuery query;
    if(databaseObj->selectQuery("select aval_cash from user_master where user_name='"+gstrUserName+"'",query))
    {
        if(query.next())
        {
            ui->lineEdit_from_hand_cash_2->setText(query.value(0).toString().trimmed());
        }
    }


    if(gstrUserType.toInt() == 0)
    {

    }
    if(gstrUserType.toInt() == 1)
    {
        QSqlQuery query;
        ui->comboBox_from_cash_from_2->clear();
        lst_operator.clear();
        if(databaseObj->selectQuery("select user_name,name from user_master where user_type='0'",query))
        {
            if(query.next())
            {
                lst_operator << query.value(0).toString().trimmed();
            }
        }
        ui->comboBox_from_cash_from_2->addItems(lst_operator);
    }
    if(gstrUserType.toInt() == 2)
    {

    }

    if(from_day_open)
    {
        ui->pushButton_from_save_2->setText("Submit Open");
    }
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
    ui->comboBox_from_cash_from_2->setFocus();

}

void Staff_Cash::on_pushButton_from_save_clicked()
{
    if(databaseObj->executeCommand("insert into cash_from_transaction (user_name,user_type,avail_cash,cash_from,cash_recv,total_aval_cash,date_time,day_no) values ('"+gstrUserName+"','"+gstrUserType+"','"+ui->lineEdit_from_hand_cash->text().trimmed()+"','"+ui->comboBox_from_cash_from->currentText().trimmed()+"','"+ui->lineEdit_from_cash_recv->text().trimmed()+"','"+ui->lineEdit_from_aval_cash->text().trimmed()+"','"+QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss")+"','"+gstrday_no+"')" ))
    {
        if(update_user_cash(ui->lineEdit_from_cash_recv->text().trimmed(),"+",gstrUserName))
        {
//            if(from_day_open)
//            {
//                on_pushButton_to_clicked();
//                return;
//            }
//            call_Staff_Cash();
            this->close();
            menuObj->call_menu();
            menuObj->show();
        }
    }
}

void Staff_Cash::on_pushButton_from_save_2_clicked()
{
    if(databaseObj->executeCommand("insert into cash_to_transaction (user_name,user_type,avail_cash,cash_to_operator,cash_given,total_aval_cash,date_time,day_no) values ('"+gstrUserName+"','"+gstrUserType+"','"+ui->lineEdit_from_hand_cash_2->text().trimmed()+"','"+ui->comboBox_from_cash_from_2->currentText().trimmed()+"','"+ui->lineEdit_from_cash_recv_2->text().trimmed()+"','"+ui->lineEdit_from_aval_cash_2->text().trimmed()+"','"+QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss")+"','"+gstrday_no+"')" ))
    {
        if(update_user_cash(ui->lineEdit_from_cash_recv_2->text().trimmed(),"-",gstrUserName))
        {
            if(update_user_cash(ui->lineEdit_from_cash_recv_2->text().trimmed(),"+",ui->comboBox_from_cash_from_2->currentText()))
            {
                if(from_day_open)
                {
                    ui->pushButton_from_save_2->setText("Save");

//                    this->close();
//                    Home_ScreenObj->call_Home_Screen();
//                    Home_ScreenObj->day_shift();
//                    Home_ScreenObj->check_batch();
//                    Home_ScreenObj->show();

                    this->close();
                    menuObj->call_menu();
                    menuObj->show();

                    return;
                }

                call_Staff_Cash();
            }
        }
    }
}
