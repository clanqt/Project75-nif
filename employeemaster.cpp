#include "employeemaster.h"
#include "ui_employeemaster.h"

#include <global.h>
using namespace Global;

EmployeeMaster::EmployeeMaster(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EmployeeMaster)
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

    scroll = new QScrollArea(ui->groupBox);
    scroll->setWidget(ui->gridLayoutWidget);
    scroll->move(0,30);
    scroll->setFixedSize(320,150);//160
    scroll->setFocusPolicy(Qt::NoFocus);
    scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}

EmployeeMaster::~EmployeeMaster()
{
    delete ui;
}

void EmployeeMaster::call_employee_master()
{
    ui->lineEdit_charges->clear();
    ui->lineEdit_emp_contact->clear();
    ui->lineEdit_emp_name->clear();
    ui->lineEdit_op_balance->clear();
    ui->lineEdit_rate_pe_hour->clear();
    ui->lineEdit_target->clear();

    ui->lineEdit_emp_name->setEnabled(true);
    ui->lineEdit_emp_contact->setEnabled(true);
    ui->comboBox_gender->setEnabled(true);
    ui->comboBox_type->setEnabled(true);
    ui->lineEdit_rate_pe_hour->setEnabled(true);
    ui->lineEdit_target->setEnabled(true);
    ui->lineEdit_charges->setEnabled(true);
    ui->lineEdit_op_balance->setEnabled(true);
    ui->radioButton_advance->setEnabled(true);
    ui->radioButton_pending->setEnabled(true);
    ui->radioButton_active->setEnabled(true);
    ui->radioButton_inactive->setEnabled(true);

    ui->lineEdit_emp_name->clear();
    ui->lineEdit_emp_contact->clear();
    ui->comboBox_gender->setCurrentIndex(0);
    ui->comboBox_type->setCurrentIndex(0);
    ui->lineEdit_rate_pe_hour->clear();
    ui->lineEdit_target->clear();
    ui->lineEdit_charges->clear();
    ui->lineEdit_op_balance->clear();


    ui->lineEdit_emp_name->setFocus();

    ui->comboBox_gender->installEventFilter(this);
    ui->comboBox_type->installEventFilter(this);
    ui->radioButton_pending->installEventFilter(this);
    ui->radioButton_advance->installEventFilter(this);

    ui->radioButton_active->installEventFilter(this);
    ui->radioButton_inactive->installEventFilter(this);

    ui->comboBox_gender->setCurrentIndex(0);
    ui->comboBox_type->setCurrentIndex(0);
    ui->lineEdit_emp_name->setFocus();

    QSqlQuery employee_details;
    if(databaseObj->selectQuery("select emp_name from employee_master where is_active='1'",employee_details))
    {
        lst_emp_name.clear();
        if(employee_details.next())
        {
            lst_emp_name << employee_details.value(0).toString().trimmed();

            while(employee_details.next())
            {
                lst_emp_name << employee_details.value(0).toString().trimmed();
            }
        }
    }

    cmpter = new QCompleter(lst_emp_name,this);
    cmpter->setCaseSensitivity(Qt::CaseInsensitive);
    cmpter->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->lineEdit_emp_name->setCompleter(cmpter);


    is_edit = false;

#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
#endif

}

void EmployeeMaster::keyPressEvent(QKeyEvent *ke)
{
    if(ke->key()== Qt::Key_Escape)
    {
        if(!ui->lineEdit_emp_name->text().isEmpty() || is_edit)
        {
            is_edit = false;
            ui->lineEdit_emp_name->setEnabled(true);
            ui->lineEdit_emp_contact->setEnabled(true);
            ui->comboBox_gender->setEnabled(true);
            ui->comboBox_type->setEnabled(true);
            ui->lineEdit_rate_pe_hour->setEnabled(true);
            ui->lineEdit_target->setEnabled(true);
            ui->lineEdit_charges->setEnabled(true);
            ui->lineEdit_op_balance->setEnabled(true);
            ui->radioButton_advance->setEnabled(true);
            ui->radioButton_pending->setEnabled(true);
            ui->radioButton_active->setEnabled(true);
            ui->radioButton_inactive->setEnabled(true);

            ui->lineEdit_emp_name->clear();
            ui->lineEdit_emp_contact->clear();
            ui->comboBox_gender->setCurrentIndex(0);
            ui->comboBox_type->setCurrentIndex(0);
            ui->lineEdit_rate_pe_hour->clear();
            ui->lineEdit_target->clear();
            ui->lineEdit_charges->clear();
            ui->lineEdit_op_balance->clear();


            ui->lineEdit_emp_name->setFocus();
#if(SDK75)
            g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
#endif

        }
        else
        {
            this->close();
            Master_Config_MenuObj->call_Master_Config_Menu();
            Master_Config_MenuObj->show();
        }
    }
    if(ke->key()== Qt::Key_F2)
    {
        qDebug()<<"F2 keyPressEvent ===>>>";

        ui->lineEdit_emp_name->setEnabled(false);

        ui->lineEdit_emp_name->setEnabled(true);
        ui->lineEdit_emp_contact->setEnabled(true);
        ui->comboBox_gender->setEnabled(true);
        ui->comboBox_type->setEnabled(true);
        ui->lineEdit_rate_pe_hour->setEnabled(true);
        ui->lineEdit_target->setEnabled(true);
        ui->lineEdit_charges->setEnabled(true);
        ui->lineEdit_op_balance->setEnabled(true);
        ui->radioButton_advance->setEnabled(true);
        ui->radioButton_pending->setEnabled(true);
        ui->radioButton_active->setEnabled(true);
        ui->radioButton_inactive->setEnabled(true);

#if(SDK75)
        g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
        ui->lineEdit_emp_contact->setFocus();

    }
}

bool EmployeeMaster::eventFilter(QObject *target, QEvent *event)
{
    QKeyEvent *key = static_cast <QKeyEvent*> (event);


    //    if(event->type() == QEvent::KeyPress)
    //    {
    //        if(key->key() == Qt::Key_Tab)
    //        {
    //            qDebug()<<"Tab pressed ===>>>";
    //            return true;
    //        }
    //    }

    if(target == ui->comboBox_gender)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->comboBox_gender->hasFocus())
                {
                    ui->comboBox_type->setFocus();
                    return true;
                }
            }
        }
    }
    else if(target == ui->comboBox_type)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->comboBox_type->hasFocus())
                {
                    ui->lineEdit_rate_pe_hour->setFocus();
                    return true;
                }
            }
        }
    }
    else if(target == ui->radioButton_pending)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->radioButton_pending->hasFocus())
                {
                    ui->radioButton_pending->setChecked(true);
                    ui->radioButton_advance->setChecked(false);

                    ui->radioButton_active->setFocus();
                    return true;
                }
            }
        }
    }
    else if(target == ui->radioButton_advance)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->radioButton_advance->hasFocus())
                {
                    ui->radioButton_advance->setChecked(true);
                    ui->radioButton_pending->setChecked(false);

                    ui->radioButton_active->setFocus();
                    return true;
                }
            }
        }
    }
    else if(target == ui->radioButton_active)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->radioButton_active->hasFocus())
                {
                    ui->radioButton_active->setChecked(true);
                    ui->radioButton_inactive->setChecked(false);

                    ui->pushButton_purchase_save->setEnabled(true);
                    ui->pushButton_purchase_save->setFocus();
                    return true;
                }
            }
        }
    }
    else if(target == ui->radioButton_inactive)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->radioButton_inactive->hasFocus())
                {
                    ui->radioButton_inactive->setChecked(true);
                    ui->radioButton_active->setChecked(false);

                    ui->pushButton_purchase_save->setEnabled(true);
                    ui->pushButton_purchase_save->setFocus();
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

void EmployeeMaster::on_lineEdit_emp_name_returnPressed()
{
    ui->lineEdit_emp_name->setEnabled(true);
    ui->lineEdit_emp_contact->setEnabled(true);
    ui->comboBox_gender->setEnabled(true);
    ui->comboBox_type->setEnabled(true);
    ui->lineEdit_rate_pe_hour->setEnabled(true);
    ui->lineEdit_target->setEnabled(true);
    ui->lineEdit_charges->setEnabled(true);
    ui->lineEdit_op_balance->setEnabled(true);
    ui->radioButton_advance->setEnabled(true);
    ui->radioButton_pending->setEnabled(true);
    ui->pushButton_purchase_save->setEnabled(false);

    if(!ui->lineEdit_emp_name->text().isEmpty())
    {
        QSqlQuery emp_qur;
        QString emp_name,emp_contact,emp_gender,emp_type,emp_daily_wages,emp_target,emp_target_charge,emp_balance,emp_balance_type,emp_bale,emp_balance_bale_rate,emp_active;
        if(databaseObj->selectQuery("select * from employee_master where employee_master.emp_name='"+ui->lineEdit_emp_name->text().trimmed()+"' COLLATE NOCASE and is_active='1'",emp_qur))
        {
            if(emp_qur.next())
            {
                emp_name = emp_qur.value(1).toString().trimmed();
                emp_contact = emp_qur.value(2).toString().trimmed();
                emp_gender = emp_qur.value(3).toString().trimmed();
                emp_type = emp_qur.value(4).toString().trimmed();
                emp_daily_wages = emp_qur.value(5).toString().trimmed();
                emp_target = emp_qur.value(6).toString().trimmed();
                emp_target_charge = emp_qur.value(7).toString().trimmed();
                emp_balance = emp_qur.value(8).toString().trimmed();
                emp_balance_type = emp_qur.value(9).toString().trimmed();
                emp_bale = emp_qur.value(10).toString().trimmed();
                emp_balance_bale_rate = emp_qur.value(11).toString().trimmed();
                emp_active = emp_qur.value(12).toString().trimmed();

                ui->lineEdit_emp_name->setText(emp_name);
                ui->lineEdit_emp_contact->setText(emp_contact);
                ui->comboBox_gender->setCurrentIndex(ui->comboBox_gender->findText(emp_gender,Qt::MatchCaseSensitive));
                ui->comboBox_type->setCurrentIndex(ui->comboBox_type->findText(emp_type,Qt::MatchCaseSensitive));
                ui->lineEdit_rate_pe_hour->setText(emp_daily_wages);
                ui->lineEdit_target->setText(emp_target);
                ui->lineEdit_charges->setText(emp_target_charge);

                if(emp_type.contains("labour",Qt::CaseInsensitive))
                {
                    ui->lineEdit_op_balance->setText(emp_balance_bale_rate);
                    if(emp_balance_type.contains("0",Qt::CaseInsensitive))
                        ui->radioButton_advance->setChecked(true);
                    if(emp_balance_type.contains("1",Qt::CaseInsensitive))
                        ui->radioButton_pending->setChecked(true);
                }
                else
                {
                    ui->lineEdit_op_balance->setText(emp_balance);
                    if(emp_balance_type.contains("0",Qt::CaseInsensitive))
                        ui->radioButton_advance->setChecked(true);
                    if(emp_balance_type.contains("1",Qt::CaseInsensitive))
                        ui->radioButton_pending->setChecked(true);
                }
                if(emp_active.toInt() == 1)
                    ui->radioButton_active->setChecked(true);
                if(emp_active.toInt() == 0)
                    ui->radioButton_inactive->setChecked(true);


                ui->lineEdit_emp_contact->setEnabled(false);
                ui->comboBox_gender->setEnabled(false);
                ui->comboBox_type->setEnabled(false);
                ui->lineEdit_rate_pe_hour->setEnabled(false);
                ui->lineEdit_target->setEnabled(false);
                ui->lineEdit_charges->setEnabled(false);
                ui->lineEdit_op_balance->setEnabled(false);
                ui->radioButton_advance->setEnabled(false);
                ui->radioButton_pending->setEnabled(false);
                ui->radioButton_active->setEnabled(false);
                ui->radioButton_inactive->setEnabled(false);
                is_edit = true;
                return;
            }
        }


#if(SDK75)
        g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
        ui->lineEdit_emp_contact->setFocus();
    }
}

void EmployeeMaster::on_lineEdit_emp_contact_returnPressed()
{
    if(!ui->lineEdit_emp_contact->text().isEmpty())
    {
#if(SDK75)
        g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
        ui->comboBox_gender->setFocus();
    }
}

void EmployeeMaster::on_lineEdit_rate_pe_hour_returnPressed()
{
    if(!ui->lineEdit_rate_pe_hour->text().isEmpty())
    {
#if(SDK75)
        g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
        ui->lineEdit_target->setFocus();
    }
}

void EmployeeMaster::on_lineEdit_target_returnPressed()
{
    if(!ui->lineEdit_target->text().isEmpty())
    {
        if(ui->comboBox_type->currentText().contains("labour",Qt::CaseInsensitive))
        {
            if(ui->lineEdit_target->text().toFloat() > 0)
            {
#if(SDK75)
                g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                ui->lineEdit_charges->setFocus();
                return;
            }

        }
    }
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
    ui->lineEdit_charges->setFocus();
}

void EmployeeMaster::on_lineEdit_charges_returnPressed()
{
    if(!ui->lineEdit_charges->text().isEmpty())
    {

        if(ui->comboBox_type->currentText().contains("labour",Qt::CaseInsensitive))
        {
            if(ui->lineEdit_charges->text().toFloat() > 0)
            {
#if(SDK75)
                g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                ui->lineEdit_op_balance->setFocus();
                return;
            }
        }
#if(SDK75)
        g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
        ui->lineEdit_op_balance->setFocus();
    }
}

void EmployeeMaster::on_lineEdit_op_balance_returnPressed()
{
    if(!ui->lineEdit_op_balance->text().isEmpty())
    {
#if(SDK75)
        g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
        ui->radioButton_pending->setFocus();
    }
}

void EmployeeMaster::on_pushButton_purchase_save_clicked()
{

    if(is_edit)
    {
        if((!ui->lineEdit_emp_name->text().isEmpty()) &&
                (!ui->lineEdit_emp_contact->text().isEmpty()) &&
                (!ui->lineEdit_rate_pe_hour->text().isEmpty()) &&
                (!ui->lineEdit_target->text().isEmpty()) &&
                (!ui->lineEdit_charges->text().isEmpty()) &&
                (!ui->lineEdit_op_balance->text().isEmpty()))
        {
            qDebug()<<"lineEdit_emp_name ===>>>"<< ui->lineEdit_emp_name->text();
            qDebug()<<"lineEdit_emp_contact ===>>>"<< ui->lineEdit_emp_contact->text();
            qDebug()<<"lineEdit_rate_pe_hour ===>>>"<< ui->lineEdit_rate_pe_hour->text();
            qDebug()<<"lineEdit_target ===>>>"<< ui->lineEdit_target->text();
            qDebug()<<"lineEdit_charges ===>>>"<< ui->lineEdit_charges->text();
            qDebug()<<"lineEdit_op_balance ===>>>"<< ui->lineEdit_op_balance->text();

            QString balance_type;
            if(ui->radioButton_advance->isChecked())
            {
                balance_type = "0";
            }
            else if(ui->radioButton_pending->isChecked())
            {
                balance_type = "1";
            }
            else
            {
                balance_type = "1";
            }
            QString balance_name = "emp_balance";
            if(ui->comboBox_type->currentText().contains("labour",Qt::CaseInsensitive))
            {
                balance_name = "emp_balance_bale_rate";
            }
            else
            {
                balance_name = "emp_balance";
            }
            QString is_emp_active = "";
            if(ui->radioButton_active->isChecked())
                is_emp_active = "1";
            if(ui->radioButton_inactive->isChecked())
                is_emp_active = "0";

            if(databaseObj->executeCommand("update employee_master set emp_contact='"+ui->lineEdit_emp_contact->text().trimmed()+"' , emp_gender='"+ui->comboBox_gender->currentText()+"' , emp_type='"+ui->comboBox_type->currentText()+"' , daily_wages='"+ui->lineEdit_rate_pe_hour->text().trimmed()+"' , emp_target='"+ui->lineEdit_target->text().trimmed()+"' , emp_target_charge='"+ui->lineEdit_charges->text().trimmed()+"' , emp_balance_type='"+balance_type+"' , "+balance_name+"='"+ui->lineEdit_op_balance->text().trimmed()+"',is_active='"+is_emp_active+"' where emp_name='"+ui->lineEdit_emp_name->text().trimmed()+"'"))
            {
                int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"Update Success..!",16,14);
                call_employee_master();
            }

            return;
        }
    }


    if((!ui->lineEdit_emp_name->text().isEmpty()) &&
            (!ui->lineEdit_emp_contact->text().isEmpty()) &&
            (!ui->lineEdit_rate_pe_hour->text().isEmpty()) &&
            (!ui->lineEdit_target->text().isEmpty()) &&
            (!ui->lineEdit_charges->text().isEmpty()) &&
            (!ui->lineEdit_op_balance->text().isEmpty()))
    {

        qDebug()<<"lineEdit_emp_name ===>>>"<< ui->lineEdit_emp_name->text();
        qDebug()<<"lineEdit_emp_contact ===>>>"<< ui->lineEdit_emp_contact->text();
        qDebug()<<"lineEdit_rate_pe_hour ===>>>"<< ui->lineEdit_rate_pe_hour->text();
        qDebug()<<"lineEdit_target ===>>>"<< ui->lineEdit_target->text();
        qDebug()<<"lineEdit_charges ===>>>"<< ui->lineEdit_charges->text();
        qDebug()<<"lineEdit_op_balance ===>>>"<< ui->lineEdit_op_balance->text();

        QString balance_type;
        if(ui->radioButton_advance->isChecked())
        {
            balance_type = "0";
        }
        else if(ui->radioButton_pending->isChecked())
        {
            balance_type = "1";
        }
        else
        {
            balance_type = "1";
        }
        QString balance_name = "emp_balance";
        if(ui->comboBox_type->currentText().contains("labour",Qt::CaseInsensitive))
        {
            balance_name = "emp_balance_bale_rate";
        }
        else
        {
            balance_name = "emp_balance";
        }
        QString is_emp_active = "";
        if(ui->radioButton_active->isChecked())
            is_emp_active = "1";
        if(ui->radioButton_inactive->isChecked())
            is_emp_active = "0";
        if(databaseObj->executeCommand("insert into employee_master (emp_name,emp_contact,emp_gender,emp_type,daily_wages,emp_target,emp_target_charge,"+balance_name+",emp_balance_type,is_active) values ('"+ui->lineEdit_emp_name->text().trimmed()+"','"+ui->lineEdit_emp_contact->text().trimmed()+"','"+ui->comboBox_gender->currentText().trimmed()+"','"+ui->comboBox_type->currentText().trimmed()+"','"+ui->lineEdit_rate_pe_hour->text().trimmed()+"','"+ui->lineEdit_target->text().trimmed()+"','"+ui->lineEdit_charges->text().trimmed()+"','"+ui->lineEdit_op_balance->text().trimmed()+"','"+balance_type+"','"+is_emp_active+"')"))
        {
            qDebug()<<"data saved in employee_master ===>>>";
            call_employee_master();
        }
    }
}
