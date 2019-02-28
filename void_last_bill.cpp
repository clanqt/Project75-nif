#include "void_last_bill.h"
#include "ui_void_last_bill.h"

#include <QMessageBox>
#include <QDebug>

#include <global.h>
using namespace Global;

Void_Last_BIll::Void_Last_BIll(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Void_Last_BIll)
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

Void_Last_BIll::~Void_Last_BIll()
{
    delete ui;
}

void Void_Last_BIll::call_Void_Last_BIll()
{
    ui->pushButton_home_back->setFocus();

    QSqlQuery bill_no_qur;
    QString purchase_bill,payment_bill;
    ui->pushButton_purchase->hide();
    ui->pushButton_payment->hide();

    ui->pushButton_purchase->setEnabled(true);
    ui->pushButton_payment->setEnabled(true);


    if(databaseObj->selectQuery("select * from transaction_master where rowid=(select max(rowid) from transaction_master where is_payment='0' and day_no='"+gstrday_no+"')",bill_no_qur))
    {
        if(bill_no_qur.next())
        {
            purchase_bill = bill_no_qur.value(1).toString().trimmed();
            if(bill_no_qur.value(27).toInt() == 1)
                ui->pushButton_purchase->setEnabled(false);
        }
    }

    bill_no_qur.clear();
    if(databaseObj->selectQuery("select * from transaction_master where rowid=(select max(rowid) from transaction_master where is_payment='1' and day_no='"+gstrday_no+"')",bill_no_qur))
    {
        if(bill_no_qur.next())
        {
            payment_bill = bill_no_qur.value(1).toString().trimmed();
            if(bill_no_qur.value(27).toInt() == 1)
                ui->pushButton_payment->setEnabled(false);

        }
    }

    if(!payment_bill.isEmpty() && payment_bill.toInt()>0)
    {
        ui->pushButton_payment->show();
        ui->pushButton_payment->setFocus();
        ui->pushButton_payment->setText("Payment -"+payment_bill.rightJustified(5,'0',1));
    }

    if(!purchase_bill.isEmpty() && purchase_bill.toInt()>0)
    {
        ui->pushButton_purchase->show();
        ui->pushButton_purchase->setFocus();
        ui->pushButton_purchase->setText("Purchase-"+purchase_bill.rightJustified(5,'0',1));
    }

    Home_ScreenObj->call_Home_Screen();

    ui->pushButton_home_back->setFocus();

    return;

}

void Void_Last_BIll::on_pushButton_purchase_clicked()
{
    int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Information,"Do You Want To\nCancel Bill?",16,14,"YES","NO");
    if(ret==1)
    {
        //!yes
        QInputDialog inputDialog;
        QFont font;
        font.setFamily("DejaVu Sans Mono");
        font.setPointSize(14);
        inputDialog.setInputMode(QInputDialog::TextInput);
        inputDialog.setWindowTitle("Input");
        inputDialog.setTextEchoMode(QLineEdit::Password);
        inputDialog.setLabelText("Enter Pasword.");
        inputDialog.setFont(font);
        inputDialog.move(25,50);
        inputDialog.setWindowFlags(Qt::FramelessWindowHint);


        bool ok;
        ok = inputDialog.exec();
        if(ok && !inputDialog.textValue().isEmpty())
        {
            QSqlQuery pass_qur;
            if(databaseObj->selectQuery("select * from user_master where user_master.user_name='"+gstrUserName+"'",pass_qur))
            {
                if(pass_qur.next())
                {
                    if(pass_qur.value(3).toInt() == inputDialog.textValue().toInt())
                    {
                        //! void bill
                        QString v_number,v_name,op_bal,op_bal_type,bill_no,odo_meter_reading,v_type,inward_husk,inward_cft,v_kms,paid,batch_no,batch_type;
                        QSqlQuery void_bill_qur;
                        if(databaseObj->selectQuery("select sum(last_bill_no) from configuration_master",void_bill_qur))
                        {
                            if(void_bill_qur.next())
                            {
                                bill_no = void_bill_qur.value(0).toString().trimmed();
                                void_bill_qur.clear();
                                if(databaseObj->selectQuery("select * from transaction_master where bill_no='"+bill_no+"' and is_payment='0'",void_bill_qur))
                                {
                                    if(void_bill_qur.next())
                                    {
                                        v_name = void_bill_qur.value(3).toString().trimmed();
                                        v_number = void_bill_qur.value(5).toString().trimmed();
                                        op_bal = void_bill_qur.value(8).toString().trimmed();
                                        op_bal_type = void_bill_qur.value(26).toString().trimmed();
                                        inward_husk = void_bill_qur.value(21).toString().trimmed();
                                        inward_cft = void_bill_qur.value(20).toString().trimmed();
                                        v_kms = void_bill_qur.value(19).toString().trimmed();
                                        paid = void_bill_qur.value(12).toString().trimmed();
                                        batch_type = void_bill_qur.value(17).toString().trimmed();
                                        batch_no = void_bill_qur.value(18).toString().trimmed();

                                        update_user_cash(paid,"+",gstrUserName);

                                        qDebug()<<"void bill details bill no===>>>"<<bill_no;
                                        qDebug()<<"void bill details v_name ===>>>"<<v_name;
                                        qDebug()<<"void bill details v_number ===>>>"<<v_number;
                                        qDebug()<<"void bill details op_bal ===>>>"<<op_bal;
                                        qDebug()<<"void bill details op_bal_type ===>>>"<<op_bal_type;
                                        qDebug()<<"void bill details v_kms ===>>>"<<v_kms;
                                        qDebug()<<"void bill details inward_husk ===>>>"<<inward_husk;
                                        qDebug()<<"void bill details inward_cft ===>>>"<<inward_cft;
                                        qDebug()<<"void bill details paid ===>>>"<<paid;
                                        qDebug()<<"void bill details batch_type ===>>>"<<batch_type;
                                        qDebug()<<"void bill details batch_no ===>>>"<<batch_no;

                                        void_bill_qur.clear();
                                        if(databaseObj->selectQuery("select * from vehicle_registration where vehicle_no='"+v_number+"'",void_bill_qur))
                                        {
                                            if(void_bill_qur.next())
                                            {
                                                v_type = void_bill_qur.value(7).toString().trimmed();
                                                odo_meter_reading = void_bill_qur.value(9).toString().trimmed();
                                            }
                                        }
                                        qDebug()<<"void bill details v_type ===>>>"<<v_type;
                                        qDebug()<<"void bill details odo_meter_reading ===>>>"<<odo_meter_reading;


                                        QString batch_type,inward_to,batch_number,odometer_name;
                                        if(v_type.toInt() == 0)
                                        {
                                            batch_type = "0";
                                            batch_number = batch_no;
                                            inward_to = "company_batch_no";
                                            odometer_name = ",odometer_reading";

                                            int kms = odo_meter_reading.toInt() - v_kms.toInt();
                                            if(databaseObj->executeCommand("update vehicle_registration set odometer_reading='"+QString::number(kms)+"' where vehicle_no='"+v_number+"'"))
                                            {
                                                qDebug()<<"void v_kms success ===>>>";
                                            }
                                        }
                                        if(v_type.toInt() == 1)
                                        {
                                            batch_type = "1";
                                            batch_number = batch_no;
                                            inward_to = "other_batch_no";
                                        }
                                        if(v_type.toInt() == 2)
                                        {
                                            batch_type = "2";
                                            batch_number = batch_no;
                                            inward_to = "van_batch_no";
                                        }


                                        if(databaseObj->executeCommand("update "+inward_to+" set inward_stock=(select "+inward_to+".inward_stock from "+inward_to+"  where batch_no='"+batch_number+"' and status='1' )-'"+inward_cft+"' where batch_no='"+batch_number+"' and status='1' "))
                                        {
                                            if(databaseObj->executeCommand("update "+inward_to+" set total_husk_produced=(select "+inward_to+".total_husk_produced from "+inward_to+"  where batch_no='"+batch_number+"' and status='1' )-'"+inward_husk+"' where batch_no='"+batch_number+"' and status='1' "))
                                            {
                                                qDebug()<<"void inward update success ===>>>";
                                            }

                                        }

                                        if(databaseObj->executeCommand("update customer_master set balance='"+op_bal+"',balance_type='"+op_bal_type+"' where cus_name='"+v_name+"'"))
                                        {
                                            qDebug()<<"previous balance updated ===>>>";
                                            if(databaseObj->executeCommand("update transaction_master set is_void='1' where bill_no='"+bill_no+"'"))
                                            {
                                                qDebug()<<"bill void completed ===>>>";
                                                databaseObj->con.commit();
                                                int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"Purchase\nBill No:"+bill_no+"\nis canceled",16,14);
                                                this->close();
                                                menuObj->call_menu();
                                                menuObj->show();
                                                return;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Error,"No Bill Found.",16,14);
                                        ui->pushButton_purchase->setFocus();
                                        return;
                                    }
                                }
                            }
                        }

                    }
                    else
                    {
                        int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Error,"Wrong Password..!",16,14);
                        ui->pushButton_purchase->setFocus();
                        return;
                    }
                }
                else
                {
                    ui->pushButton_purchase->setFocus();
                    return;
                }
            }
            else
            {
                ui->pushButton_purchase->setFocus();
                return;
            }
        }
    }
}

void Void_Last_BIll::on_pushButton_payment_clicked()
{
    int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Information,"Do You Want To\nCancel Bill?",16,14,"YES","NO");
    if(ret==1)
    {
        //!yes
        QInputDialog inputDialog;
        QFont font;
        font.setFamily("DejaVu Sans Mono");
        font.setPointSize(14);
        inputDialog.setInputMode(QInputDialog::TextInput);
        inputDialog.setWindowTitle("Input");
        inputDialog.setTextEchoMode(QLineEdit::Password);
        inputDialog.setLabelText("Enter Pasword.");
        inputDialog.setFont(font);
        inputDialog.move(25,50);
        inputDialog.setWindowFlags(Qt::FramelessWindowHint);


        bool ok;
        ok = inputDialog.exec();
        if(ok && !inputDialog.textValue().isEmpty())
        {
            QSqlQuery pass_qur;
            if(databaseObj->selectQuery("select * from user_master where user_master.user_name='"+gstrUserName+"'",pass_qur))
            {
                if(pass_qur.next())
                {
                    if(pass_qur.value(3).toInt() == inputDialog.textValue().toInt())
                    {
                        //! void bill
                        QString v_number,v_name,op_bal,op_bal_type,bill_no,v_type,inward_husk,paid;
                        QSqlQuery void_bill_qur;
                        if(databaseObj->selectQuery("select sum(payment_bill_no) from configuration_master",void_bill_qur))
                        {
                            if(void_bill_qur.next())
                            {
                                bill_no = void_bill_qur.value(0).toString().trimmed();
                                void_bill_qur.clear();
                                if(databaseObj->selectQuery("select * from transaction_master where bill_no='"+bill_no+"' and is_payment='1'",void_bill_qur))
                                {
                                    if(void_bill_qur.next())
                                    {
                                        v_name = void_bill_qur.value(3).toString().trimmed();
                                        v_number = void_bill_qur.value(5).toString().trimmed();
                                        op_bal = void_bill_qur.value(8).toString().trimmed();
                                        op_bal_type = void_bill_qur.value(26).toString().trimmed();
                                        inward_husk = void_bill_qur.value(21).toString().trimmed();
                                        paid = void_bill_qur.value(12).toString().trimmed();

                                        update_user_cash(paid,"+",gstrUserName);

                                        qDebug()<<"payment void bill details bill no===>>>"<<bill_no;
                                        qDebug()<<"payment void bill details v_name ===>>>"<<v_name;
                                        qDebug()<<"payment void bill details v_number ===>>>"<<v_number;
                                        qDebug()<<"payment void bill details op_bal ===>>>"<<op_bal;
                                        qDebug()<<"payment void bill details op_bal_type ===>>>"<<op_bal_type;
                                        qDebug()<<"payment void bill details paid ===>>>"<<paid;

                                        if(databaseObj->executeCommand("update customer_master set balance='"+op_bal+"',balance_type='"+op_bal_type+"' where cus_name='"+v_name+"'"))
                                        {
                                            qDebug()<<"payment previous balance updated ===>>>";
                                            if(databaseObj->executeCommand("update transaction_master set is_void='1' where bill_no='"+bill_no+"'"))
                                            {
                                                qDebug()<<"payment bill void completed ===>>>";
                                                databaseObj->con.commit();
                                                int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"Payment\nBill No:"+bill_no+"\nis canceled",16,14);
                                                this->close();
                                                menuObj->call_menu();
                                                menuObj->show();
                                                return;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Error,"No Bill Found.",16,14);
                                        ui->pushButton_payment->setFocus();
                                        return;
                                    }
                                }
                            }
                        }

                    }
                    else
                    {
                        int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Error,"Wrong Password..!",16,14);
                        ui->pushButton_payment->setFocus();
                        return;
                    }
                }
                else
                {
                    ui->pushButton_payment->setFocus();
                    return;
                }
            }
            else
            {
                ui->pushButton_payment->setFocus();
                return;
            }
        }
    }
}

void Void_Last_BIll::keyPressEvent(QKeyEvent *ke)
{
    if(ke->key()== Qt::Key_Escape)
    {
        if(ui->groupBox->isVisible())
        {
            this->close();
            menuObj->call_menu();
            menuObj->show();
            return;
        }
    }
}

