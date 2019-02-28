#include "expense_master.h"
#include "ui_expense_master.h"

#include <QMessageBox>

#include <global.h>
using namespace Global;

Expense_Master::Expense_Master(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Expense_Master)
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

Expense_Master::~Expense_Master()
{
    delete ui;
}

void Expense_Master::call_Expense_Master()
{
    expense_entry = false;

    ui->comboBox_expense->installEventFilter(this);
    ui->lineEdit_amount->installEventFilter(this);
    ui->lineEdit_bill_no->installEventFilter(this);

    show_screen(1);
}

void Expense_Master::keyPressEvent(QKeyEvent *ke)
{
    if(ke->key()== Qt::Key_Escape)
    {
        if(ui->groupBox_expense_master_add->isVisible())
        {
            this->close();
            Master_Config_MenuObj->call_Master_Config_Menu();
            Master_Config_MenuObj->show();
        }
        if(ui->groupBox_Expense_entry->isVisible())
        {
            if(from_payments)
            {
                this->close();
//                PaymentObj = new Payment;

                PaymentObj->is_payment = true;
                PaymentObj->call_Payment();
                PaymentObj->show();
                return;
            }
            this->close();
            PaymentObj->is_payment = true;
            PaymentObj->call_Payment();
            PaymentObj->show();
        }
    }
}

bool Expense_Master::eventFilter(QObject *target, QEvent *event)
{
    QKeyEvent *key = static_cast <QKeyEvent*> (event);

    if(target == ui->comboBox_expense)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->comboBox_expense->hasFocus())
                {
#if(SDK75)
                    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                    ui->lineEdit_bill_no->setFocus();
                    return true;
                }
            }
        }
    }
    else if(target == ui->lineEdit_bill_no)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->lineEdit_bill_no->hasFocus())
                {
#if(SDK75)
                    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                    ui->lineEdit_amount->setFocus();
                    return true;
                }
            }
        }
    }
    else if(target == ui->lineEdit_amount)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->lineEdit_amount->hasFocus())
                {
                    ui->pushButton_save->setEnabled(true);
#if(SDK75)
                    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                    ui->pushButton_save->setFocus();
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

void Expense_Master::show_screen(int screen_no)
{
    if(screen_no == 1)
    {
        ui->groupBox_expense_master_add->show();
        ui->groupBox_expense_master_add->move(0,0);
        ui->groupBox_expense_master_add->raise();

        ui->groupBox_Expense_entry->hide();
        ui->groupBox_Expense_entry->move(0,0);

        expense_entry = false;

        ui->lineEdit_expense_name->clear();
#if(SDK75)
        g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
#endif
        ui->lineEdit_expense_name->setFocus();
    }
    else if(screen_no ==2)
    {
        ui->pushButton_save->setEnabled(false);
        ui->groupBox_expense_master_add->hide();
        ui->groupBox_expense_master_add->move(0,0);

        ui->groupBox_Expense_entry->show();
        ui->groupBox_Expense_entry->move(0,0);
        ui->groupBox_Expense_entry->raise();

        ui->lineEdit_amount->clear();
        ui->lineEdit_bill_no->clear();
        ui->lineEdit_expense_name->clear();

        expense_entry = true;

        lst_expense_name.clear();
        lst_expense_id.clear();
        QSqlQuery query;
        if(databaseObj->selectQuery("select * from expense_master",query))
        {
            if(query.next())
            {
                lst_expense_id << query.value(0).toString().trimmed();
                lst_expense_name << query.value(1).toString().trimmed();
                while(query.next())
                {
                    lst_expense_id << query.value(0).toString().trimmed();
                    lst_expense_name << query.value(1).toString().trimmed();
                }

                //                cmpter = new QCompleter(lst_expense_name,this);
                //                cmpter->setCaseSensitivity(Qt::CaseInsensitive);
                //                cmpter->setCompletionMode(QCompleter::PopupCompletion);
                //                ui->lineEdit_expense_name->setCompleter(cmpter);

                ui->comboBox_expense->clear();
                ui->comboBox_expense->addItems(lst_expense_name);

            }
        }

#if(SDK75)
        g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
        ui->comboBox_expense->setFocus();
    }
}

void Expense_Master::on_pushButton_add_clicked()
{
    //! add new expense
    if(!expense_entry && !ui->lineEdit_expense_name->text().trimmed().isEmpty())
    {
        if(databaseObj->executeCommand("insert into expense_master (expense_name) values ('"+ui->lineEdit_expense_name->text().trimmed()+"')"))
        {
            qDebug()<<"expense_master name saved===>>>";
#if(NativeCompile)
            QMessageBox gMsg_box;
            QFont gFont;
            gFont.setFamily("DejaVu Sans Mono");
            gFont.setPointSize(12);
            gMsg_box.setFont(gFont);
            gMsg_box.setParent(this);

            if(gMsg_box.information(this, "Success","Expense Saved Successfully..!",QMessageBox::Ok) == QMessageBox::Ok)
            {
                show_screen(1);
            }
#endif

#if(SDK75)
            int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"Expense Saved Successfully..!",16,14);
            show_screen(1);
#endif

        }
    }
}

void Expense_Master::on_pushButton_save_clicked()
{
    //! expense entry
    QString available_cash = get_cash_available(gstrUserName);
    if(available_cash.toFloat() >= ui->lineEdit_amount->text().trimmed().toFloat())
    {

    }
    else
    {
#if(NativeCompile)
        QMessageBox gMsg_box;
        QFont gFont;
        gFont.setFamily("DejaVu Sans Mono");
        gFont.setPointSize(12);
        gMsg_box.setFont(gFont);
        gMsg_box.setParent(this);

        //        if(gMsg_box.information(this, "Cash Available: Rs"+QString::number(available_cash.toFloat(),QMessageBox::Ok) == QMessageBox::Ok)
        //        {

        //    }
#endif

#if(SDK75)
        int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"Cash Available: \nRs"+QString::number(available_cash.toFloat(),'f',2),16,14);
        ui->lineEdit_amount->setFocus();
        return;
#endif

    }
    if(!ui->lineEdit_amount->text().trimmed().isEmpty())
    {
        if(databaseObj->executeCommand("insert into expense_transaction (expense_transaction_id,expense_name,bill_no,amount,day_no,user_id) values ('"+QString::number(ui->comboBox_expense->currentIndex())+"','"+ui->comboBox_expense->currentText().trimmed()+"','"+ui->lineEdit_bill_no->text().trimmed()+"','"+ui->lineEdit_amount->text().trimmed()+"','"+gstrday_no+"','"+gstrUserName+"')"));
        {
            qDebug()<<"cash update before ===>>>"<<get_cash_available(gstrUserName);
            if(update_user_cash(ui->lineEdit_amount->text().trimmed(),"-",gstrUserName))
            {
                qDebug()<<"cash update after ===>>>"<<get_cash_available(gstrUserName);
            }

            if(from_payments)
            {
                this->close();
//                PaymentObj = new Payment;
                PaymentObj->is_payment = true;
                PaymentObj->call_Payment();
                PaymentObj->show();
                return;
            }

            call_Expense_Master();
            show_screen(2);

        }
    }

}

void Expense_Master::on_lineEdit_expense_name_returnPressed()
{
    if(!ui->lineEdit_expense_name->text().trimmed().isEmpty())
    {
#if(SDK75)
        g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
        ui->pushButton_add->setFocus();
    }
}
