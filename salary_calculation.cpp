#include "salary_calculation.h"
#include "ui_salary_calculation.h"

#include <QMessageBox>
#include <math.h>
#include <global.h>
using namespace Global;

Salary_Calculation::Salary_Calculation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Salary_Calculation)
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

    //    scroll = new QScrollArea(ui->groupBox_salary);
    //    scroll->setWidget(ui->gridLayoutWidget);
    //    scroll->move(0,30);
    //    scroll->setFixedSize(320,150);//160
    //    scroll->setFocusPolicy(Qt::NoFocus);
    //    scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    //    scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


}

Salary_Calculation::~Salary_Calculation()
{
    delete ui;
}

void Salary_Calculation::call_Salary_Calculation()
{
    ui->groupBox_attendance->move(0,0);

    ui->groupBox_attendance->show();

    lst_selected_emp_name.clear();
    lst_selected_emp_gender.clear();
    lst_selected_emp_daily_wages.clear();
    lst_selected_emp_target.clear();
    lst_selected_emp_target_charge.clear();
    lst_selected_emp_balance.clear();
    lst_selected_emp_balance_type.clear();
    lst_selected_emp_pending_bale.clear();
    lst_selected_emp_pending_bale_amount.clear();

    ui->comboBox_name->installEventFilter(this);
    ui->lineEdit_bale_produced->installEventFilter(this);
    ui->lineEdit_hrs->installEventFilter(this);
    ui->checkBox_hrs->installEventFilter(this);
    ui->checkBox_target->installEventFilter(this);

    ui->checkBox_hrs->setChecked(false);
    ui->checkBox_target->setChecked(false);

    lst_emp_availble.clear();
    lst_selected_items.clear();

    ui->lineEdit_hrs->clear();

    ui->lineEdit_bale_produced->setText(Day_CloseObj->bale_produced);


    estimated_salary = "0";
    hrs_salary = "0";
    worked_hrs = "0";


    QSqlQuery query;
    lst_emp_availble.clear();
    if(databaseObj->selectQuery("select emp_name from employee_master where emp_type='Labour' and is_active='1'",query))
    {
        if(query.next())
        {
            lst_emp_availble << query.value(0).toString().trimmed();
            while(query.next())
            {
                lst_emp_availble << query.value(0).toString().trimmed();
            }

            qDebug()<<"lst_emp_availble ===>>>"<<lst_emp_availble;
        }
    }

    ui->comboBox_name->clear();
    ui->comboBox_name->addItems(lst_emp_availble);

    ui->pushButton_save_emp_salary->setEnabled(false);


    QSqlQuery is_count;

    if(databaseObj->selectQuery("select is_hrs from configuration_master",is_count))
    {
        if(is_count.next())
        {
            if(is_count.value(0).toInt() == 1)
            {
                ui->checkBox_hrs->show();
            }
            if(is_count.value(0).toInt() == 0)
            {
                ui->checkBox_hrs->hide();
            }
        }
    }
#if(SDK75)
                g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif



    ui->comboBox_name->setFocus();


}


void Salary_Calculation::keyPressEvent(QKeyEvent *ke)
{
    //    if(ke->key()== Qt::Key_Escape)
    //    {
    //        ui->groupBox_attendance->hide();

    //        this->close();
    //        PaymentObj->call_Payment();
    //        PaymentObj->show();
    //    }
    if(ke->key()== Qt::Key_F5)
    {





#if(NativeCompile)
        QMessageBox gMsg_box;
        QFont gFont;
        gFont.setFamily("DejaVu Sans Mono");
        gFont.setPointSize(12);
        gMsg_box.setFont(gFont);
        gMsg_box.setParent(this);

        if(gMsg_box.information(this, "Success","Day Closed Successfully.",QMessageBox::Ok) == QMessageBox::Ok)
        {
        }
#endif

#if(SDK75)
        int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"Day Closed\nSuccessfully.",16,14);
#endif

        ReportObj = new Report;
        ReportObj->hide();
        ReportObj->day_close_report();


        this->close();
        menuObj->call_menu();
        menuObj->show();

    }

    if(ke->key()== Qt::Key_F1)
    {
        on_pushButton_save_emp_salary_clicked();
    }


    if(ke->key()== Qt::Key_Enter || ke->key()== Qt::Key_Return)
    {
        if(ui->comboBox_name->hasFocus())
        {
            QSqlQuery query;
            lst_selected_emp_name.clear();
            lst_selected_emp_gender.clear();
            salary_per_hour.clear();
            lst_selected_emp_target.clear();
            lst_selected_emp_target_charge.clear();
            lst_selected_emp_balance.clear();
            lst_selected_emp_balance_type.clear();
            lst_selected_emp_pending_bale_amount.clear();



            if(databaseObj->selectQuery("select * from employee_master where emp_type='Labour' and is_active='1' and emp_name='"+ui->comboBox_name->currentText().trimmed()+"'",query))
            {
                if(query.next())
                {
                    lst_selected_emp_name << query.value(1).toString().trimmed();
                    lst_selected_emp_gender << query.value(3).toString().trimmed();
                    salary_per_hour = query.value(5).toString().trimmed();
                    lst_selected_emp_target << query.value(6).toString().trimmed();
                    lst_selected_emp_target_charge << query.value(7).toString().trimmed();
                    lst_selected_emp_balance << query.value(8).toString().trimmed();
                    lst_selected_emp_balance_type << query.value(9).toString().trimmed();

                    lst_selected_emp_pending_bale << query.value(10).toString().trimmed();
                    lst_selected_emp_pending_bale_amount << query.value(11).toString().trimmed();

                    qDebug()<<"lst_selected_emp_name ===>>>"<<lst_selected_emp_name;
                    qDebug()<<"lst_selected_emp_gender ===>>>"<<lst_selected_emp_gender;
                    qDebug()<<"salary_per_hour ===>>>"<<salary_per_hour;
                    qDebug()<<"lst_selected_emp_target ===>>>"<<lst_selected_emp_target;
                    qDebug()<<"lst_selected_emp_target_charge ===>>>"<<lst_selected_emp_target_charge;
                    qDebug()<<"lst_selected_emp_balance ===>>>"<<lst_selected_emp_balance;
                    qDebug()<<"lst_selected_emp_pending_bale ===>>>"<<lst_selected_emp_pending_bale;
                    qDebug()<<"lst_selected_emp_pending_bale_amount ===>>>"<<lst_selected_emp_pending_bale_amount;

                    charge_per_bale = lst_selected_emp_target_charge.at(0).toFloat()/lst_selected_emp_target.at(0).toFloat();

                    qDebug()<<"charge_per_bale ===>>>"<<charge_per_bale;

#if(SDK75)
                    g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
#endif

                    ui->checkBox_target->setFocus();
                }
            }
        }

    }
}


//void Salary_Calculation::on_pushButton_save_salary_clicked()
//{
//    qDebug()<<"on_pushButton_save_salary_clicked ===>>>";

//    QString str_pending_bale="",str_pending_salary="";
//    QString str_unpaid_bale_value="",str_pending_salary_value="";


//    if(ui->lineEdit_unpaid_bale->isVisible() && !ui->lineEdit_unpaid_bale->text().trimmed().isEmpty())
//    {
//        str_pending_bale = ",pending_bale";
//        str_unpaid_bale_value = ","+QString("'"+ui->lineEdit_unpaid_bale->text().trimmed()+"'");
//        qDebug()<<"str_unpaid_bale_value_value ===>>>"<<str_unpaid_bale_value;
//    }

//    if(ui->lineEdit_pending_salary->isVisible() && !ui->lineEdit_pending_salary->text().trimmed().isEmpty())
//    {
//        str_pending_salary = ",pending_salary";
//        str_pending_salary_value = ","+QString("'"+ui->lineEdit_pending_salary->text().trimmed()+"'");
//        qDebug()<<"str_pending_salary_value ===>>>"<<str_pending_salary_value;
//    }


//    if(databaseObj->executeCommand("insert into employee_transaction (emp_name,day_no,produced_bale,calc_salary,paid_salary"+str_pending_bale+str_pending_salary+") values ('"+ui->lineEdit_emp_name->text().trimmed()+"','"+gstrday_no+"','"+
//                                   ui->lineEdit_produced_bale->text().trimmed()+"','"+ui->lineEdit_salary->text().trimmed()+"','"+ui->lineEdit_paid_salary->text().trimmed()+"'"+str_unpaid_bale_value+str_pending_salary_value+")"))
//    {
//        qDebug()<<"employee_transaction insert emp_name ===>>>"<<ui->lineEdit_emp_name->text().trimmed();
//        if(ui->lineEdit_unpaid_bale->isVisible() && !ui->lineEdit_unpaid_bale->text().trimmed().isEmpty())
//        {
//            str_pending_bale = "emp_balance_bale";
//            str_unpaid_bale_value = "="+QString("'"+ui->lineEdit_unpaid_bale->text().trimmed()+"'");
//            qDebug()<<"str_unpaid_bale_value_value ===>>>"<<str_unpaid_bale_value;
//        }
//        if(ui->lineEdit_pending_salary->isVisible() && !ui->lineEdit_pending_salary->text().trimmed().isEmpty())
//        {
//            if(!str_unpaid_bale_value.isEmpty())
//                str_pending_salary = ",emp_balance_bale_rate";
//            else
//                str_pending_salary = "emp_balance_bale_rate";

//            str_pending_salary_value = "="+QString("'"+ui->lineEdit_pending_salary->text().trimmed()+"'");
//            qDebug()<<"str_pending_salary_value ===>>>"<<str_pending_salary_value;
//        }
//        if(!str_pending_salary_value.isEmpty() || !str_unpaid_bale_value.isEmpty())
//        {
//            if(databaseObj->executeCommand("update employee_master set "+str_pending_bale+str_unpaid_bale_value+str_pending_salary+str_pending_salary_value+" where emp_name='"+ui->lineEdit_emp_name->text().trimmed()+"'"))
//            {
//                qDebug()<<"emploayee_master update success ===>>>";
//            }
//        }
//    }


//    //    if(databaseObj->executeCommand("update employee_master set  where emp_name='"+ui->lineEdit_emp_name->text().trimmed()+"'"))


//    emit goto_next_employee();
//}

void Salary_Calculation::on_comboBox_name_currentIndexChanged(const QString &arg1)
{
    ui->checkBox_hrs->setChecked(false);
    ui->checkBox_target->setChecked(false);

    ui->lineEdit_hrs->hide();

    ui->label_hrs->hide();
}

void Salary_Calculation::on_checkBox_target_clicked(bool checked)
{
    qDebug()<<"on_checkBox_target_clicked ===>>>"<<checked;

    if(checked)
    {
        estimated_salary = QString::number(ceil(charge_per_bale* ui->lineEdit_bale_produced->text().trimmed().toFloat()));
    }
    else
    {
        estimated_salary.clear();
    }
}

void Salary_Calculation::on_checkBox_hrs_clicked(bool checked)
{
    qDebug()<<"on_checkBox_hrs_clicked ===>>>"<<checked;

    if(checked)
    {
        ui->label_hrs->show();
        ui->lineEdit_hrs->show();
    }
    else
    {
        ui->label_hrs->hide();
        ui->lineEdit_hrs->hide();
    }
}

void Salary_Calculation::on_lineEdit_target_returnPressed()
{
    //    if(ui->checkBox_target->isChecked())
    //    {
    //        hrs_salary = QString::number(ceil(ui->lineEdit_hrs->text().trimmed().toFloat() * ui->lineEdit_hrs->text().trimmed().toFloat()));

    //        ui->pushButton_save_emp_salary->setFocus();
    //        //! save employee salary

    //    }
    //    else
    //    {
    //        hrs_salary.clear();
    //    }
}

void Salary_Calculation::on_lineEdit_hrs_returnPressed()
{
    //    if(ui->checkBox_hrs->isChecked())
    //    {
    //        hrs_salary = QString::number(ceil(ui->lineEdit_hrs->text().trimmed().toFloat() * ui->lineEdit_hrs->text().trimmed().toFloat()));

    //        qDebug()<<"hrs_salary ===>>>";
    //        ui->pushButton_save_emp_salary->setFocus();
    //        //! save employee salary

    //    }
    //    else
    //    {
    //        hrs_salary.clear();
    //    }
}

void Salary_Calculation::on_pushButton_next_clicked()
{

}

void Salary_Calculation::on_pushButton_save_emp_salary_clicked()
{
    qDebug()<<"in on_pushButton_save_emp_salary_clicked ===>>>"<<lst_selected_emp_balance_type<<lst_selected_emp_pending_bale_amount;
    if(lst_selected_emp_name.size() > 0)
    {
        if(lst_selected_emp_balance_type.at(0).toInt() == 0)
        {
            qDebug()<<"in adv ===>>>";
            QString emp_balance,total;
            QSqlQuery emp_qur;
            if(databaseObj->selectQuery("select sum(emp_balance_bale_rate) from employee_master where emp_name='"+ui->comboBox_name->currentText().trimmed()+"' and is_active='1'",emp_qur))
            {
                if(emp_qur.next())
                {
                    emp_balance = emp_qur.value(0).toString().trimmed();
                }
            }
            total = QString::number(ceil(estimated_salary.toFloat() + hrs_salary.toFloat()) ,'f',2);

            QString hrs_msg;
            if(ui->checkBox_hrs->isChecked() && ui->lineEdit_hrs->text().toInt()>0)
            {
                hrs_msg = "\nHrs:"+ui->lineEdit_hrs->text()+"\nSalary:"+QString::number(ceil(hrs_salary.toFloat()) ,'f',2);
            }
            QString pop_up = ui->comboBox_name->currentText()+"\nBale:"+ui->lineEdit_bale_produced->text()+"\nSalary:"+QString::number(ceil(estimated_salary.toFloat()),'f',2)+hrs_msg;
            int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Error,pop_up,12,14,"YES","NO");
            if(ret==1)
            {

            }
            else
            {
                ui->lineEdit_hrs->hide();
                ui->lineEdit_hrs->clear();

                ui->checkBox_hrs->setChecked(false);
                ui->checkBox_target->setChecked(false);

                ui->comboBox_name->setFocus();
                return;
            }


            if(total.toFloat() <= emp_balance.toFloat())
            {
                qDebug()<<"total is less ===>>>";
                if(databaseObj->executeCommand("update employee_master set emp_balance_type='0', emp_balance_bale_rate=(select sum(emp_balance_bale_rate)-"+total+" from employee_master where emp_name='"+ui->comboBox_name->currentText()+"' and is_active='1') where emp_name='"+ui->comboBox_name->currentText()+"' and is_active='1'"))
                {

                    databaseObj->con.commit();
                    if(databaseObj->executeCommand("insert into employee_transaction (emp_name,day_no,produced_bale,calc_salary,working_hrs,working_hrs_salary,is_payment,opening_balance,opening_balance_type,pending_salary,emp_balance_type) values ('"+ui->comboBox_name->currentText().trimmed()+"','"+gstrday_no+"','"+Day_CloseObj->bale_produced+"','"+QString::number(estimated_salary.toFloat() + hrs_salary.toFloat(),'f',2)+"','"+worked_hrs+"','"+hrs_salary+"','0','"+lst_selected_emp_pending_bale_amount.at(0)+"','"+lst_selected_emp_balance_type.at(0)+"',(select sum(emp_balance_bale_rate) from employee_master where emp_name='"+ui->comboBox_name->currentText()+"' and is_active='1'),(select emp_balance_type from employee_master where emp_name='"+ui->comboBox_name->currentText()+"' and is_active='1'))"))
                    {

                    }

                    estimated_salary = "0";
                    hrs_salary = "0";
                    worked_hrs = "0";

                    lst_emp_availble.removeAt(ui->comboBox_name->currentIndex());

                    if(lst_emp_availble.size() == 0)
                    {

    #if(NativeCompile)
                        QMessageBox gMsg_box;
                        QFont gFont;
                        gFont.setFamily("DejaVu Sans Mono");
                        gFont.setPointSize(12);
                        gMsg_box.setFont(gFont);
                        gMsg_box.setParent(this);

                        if(gMsg_box.information(this, "Success","Day Closed Successfully.",QMessageBox::Ok) == QMessageBox::Ok)
                        {
                        }
    #endif

    #if(SDK75)
                        int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"Day Closed Successfully.",16,14);
    #endif

                        ReportObj = new Report;
                        ReportObj->hide();
                        ReportObj->day_close_report();

                        this->close();
                        menuObj->call_menu();
                        menuObj->show();
                        return;
                    }


                    ui->comboBox_name->clear();

                    ui->checkBox_hrs->setChecked(false);
                    ui->checkBox_target->setChecked(false);

                    ui->lineEdit_hrs->clear();

                    ui->comboBox_name->addItems(lst_emp_availble);

#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                ui->comboBox_name->setFocus();

                    return;
                }
            }
            if(total.toFloat() >= emp_balance.toFloat())
            {
                qDebug()<<"total is great ===>>>";
                if(databaseObj->executeCommand("update employee_master set emp_balance_type='1',emp_balance_bale_rate=(select "+total+"-sum(emp_balance_bale_rate) from employee_master where emp_name='"+ui->comboBox_name->currentText()+"' and is_active='1') where emp_name='"+ui->comboBox_name->currentText()+"' and is_active='1'"))
                {

                    databaseObj->con.commit();
                    if(databaseObj->executeCommand("insert into employee_transaction (emp_name,day_no,produced_bale,calc_salary,working_hrs,working_hrs_salary,is_payment,opening_balance,opening_balance_type,pending_salary,emp_balance_type) values ('"+ui->comboBox_name->currentText().trimmed()+"','"+gstrday_no+"','"+Day_CloseObj->bale_produced+"','"+QString::number(estimated_salary.toFloat() + hrs_salary.toFloat(),'f',2)+"','"+worked_hrs+"','"+hrs_salary+"','0','"+lst_selected_emp_pending_bale_amount.at(0)+"','"+lst_selected_emp_balance_type.at(0)+"',(select sum(emp_balance_bale_rate) from employee_master where emp_name='"+ui->comboBox_name->currentText()+"' and is_active='1'),(select emp_balance_type from employee_master where emp_name='"+ui->comboBox_name->currentText()+"' and is_active='1'))"))
                    {

                    }
                    estimated_salary = "0";
                    hrs_salary = "0";
                    worked_hrs = "0";

                    lst_emp_availble.removeAt(ui->comboBox_name->currentIndex());


                    if(lst_emp_availble.size() == 0)
                    {

    #if(NativeCompile)
                        QMessageBox gMsg_box;
                        QFont gFont;
                        gFont.setFamily("DejaVu Sans Mono");
                        gFont.setPointSize(12);
                        gMsg_box.setFont(gFont);
                        gMsg_box.setParent(this);

                        if(gMsg_box.information(this, "Success","Day Closed Successfully.",QMessageBox::Ok) == QMessageBox::Ok)
                        {
                        }
    #endif

    #if(SDK75)
                        int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"Day Closed Successfully.",16,14);
    #endif

                        ReportObj = new Report;
                        ReportObj->hide();
                        ReportObj->day_close_report();


                        this->close();
                        menuObj->call_menu();
                        menuObj->show();
                        return;
                    }


                    ui->comboBox_name->clear();

                    ui->checkBox_hrs->setChecked(false);
                    ui->checkBox_target->setChecked(false);

                    ui->lineEdit_hrs->clear();


                    ui->comboBox_name->addItems(lst_emp_availble);

#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                ui->comboBox_name->setFocus();
                    return;
                }
            }



        }
        if(lst_selected_emp_balance_type.at(0).toInt() == 1)
        {
            qDebug()<<"in pending ===>>>";

            QString hrs_msg;
            if(ui->checkBox_hrs->isChecked() && ui->lineEdit_hrs->text().toInt()>0)
            {
                hrs_msg = "\nHrs:"+ui->lineEdit_hrs->text()+"\nSalary:"+QString::number(ceil(hrs_salary.toFloat()) ,'f',2);
            }
            QString pop_up = ui->comboBox_name->currentText()+"\nBale:"+ui->lineEdit_bale_produced->text()+"\nSalary:"+QString::number(ceil(estimated_salary.toFloat()),'f',2)+hrs_msg;
            int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Question,pop_up,12,14,"YES","NO");
            if(ret==1)
            {

            }
            else
            {
                ui->lineEdit_hrs->hide();
                ui->lineEdit_hrs->clear();

                ui->checkBox_hrs->setChecked(false);
                ui->checkBox_target->setChecked(false);

                ui->comboBox_name->setFocus();
                return;
            }


            if(databaseObj->executeCommand("update employee_master set emp_balance_type='1', emp_balance_bale_rate=(select sum(emp_balance_bale_rate)+"+estimated_salary+"+"+hrs_salary+" from employee_master where emp_name='"+ui->comboBox_name->currentText()+"' and is_active='1') where emp_name='"+ui->comboBox_name->currentText()+"' and is_active='1'"))
            {
                databaseObj->con.commit();
                if(databaseObj->executeCommand("insert into employee_transaction (emp_name,day_no,produced_bale,calc_salary,working_hrs,working_hrs_salary,is_payment,opening_balance,opening_balance_type,pending_salary,emp_balance_type) values ('"+ui->comboBox_name->currentText().trimmed()+"','"+gstrday_no+"','"+Day_CloseObj->bale_produced+"','"+QString::number(estimated_salary.toFloat() + hrs_salary.toFloat(),'f',2)+"','"+worked_hrs+"','"+hrs_salary+"','0','"+lst_selected_emp_pending_bale_amount.at(0)+"','"+lst_selected_emp_balance_type.at(0)+"',(select sum(emp_balance_bale_rate) from employee_master where emp_name='"+ui->comboBox_name->currentText()+"' and is_active='1'),(select emp_balance_type from employee_master where emp_name='"+ui->comboBox_name->currentText()+"' and is_active='1'))"))
                {

                }
                estimated_salary = "0";
                hrs_salary = "0";

                lst_emp_availble.removeAt(ui->comboBox_name->currentIndex());

                if(lst_emp_availble.size() == 0)
                {

#if(NativeCompile)
                    QMessageBox gMsg_box;
                    QFont gFont;
                    gFont.setFamily("DejaVu Sans Mono");
                    gFont.setPointSize(12);
                    gMsg_box.setFont(gFont);
                    gMsg_box.setParent(this);

                    if(gMsg_box.information(this, "Success","Day Closed Successfully.",QMessageBox::Ok) == QMessageBox::Ok)
                    {
                    }
#endif

#if(SDK75)
                    int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"Day Closed Successfully.",16,14);
#endif

                    ReportObj = new Report;
                    ReportObj->hide();
                    ReportObj->day_close_report();


                    this->close();
                    menuObj->call_menu();
                    menuObj->show();
                    return;
                }

                ui->comboBox_name->clear();
                ui->checkBox_hrs->setChecked(false);
                ui->checkBox_target->setChecked(false);

                ui->lineEdit_hrs->clear();
                ui->comboBox_name->addItems(lst_emp_availble);


                ui->checkBox_hrs->setChecked(false);
                ui->checkBox_target->setChecked(false);
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                ui->comboBox_name->setFocus();
                return;
            }
        }
    }
}

bool Salary_Calculation::eventFilter(QObject *target, QEvent *event)
{
    QKeyEvent *key = static_cast <QKeyEvent*> (event);

    if(target == ui->comboBox_name)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->comboBox_name->hasFocus())
                {
                    QSqlQuery query;
                    lst_selected_emp_name.clear();
                    lst_selected_emp_gender.clear();
                    salary_per_hour.clear();
                    lst_selected_emp_target.clear();
                    lst_selected_emp_target_charge.clear();
                    lst_selected_emp_balance.clear();
                    lst_selected_emp_balance_type.clear();
                    lst_selected_emp_pending_bale_amount.clear();
                    if(databaseObj->selectQuery("select * from employee_master where emp_type='Labour' and emp_name='"+ui->comboBox_name->currentText().trimmed()+"' and is_active='1'",query))
                    {
                        if(query.next())
                        {
                            lst_selected_emp_name << query.value(1).toString().trimmed();
                            lst_selected_emp_gender << query.value(3).toString().trimmed();
                            salary_per_hour = query.value(5).toString().trimmed();
                            lst_selected_emp_target << query.value(6).toString().trimmed();
                            lst_selected_emp_target_charge << query.value(7).toString().trimmed();
                            lst_selected_emp_balance << query.value(8).toString().trimmed();
                            lst_selected_emp_balance_type << query.value(9).toString().trimmed();

                            lst_selected_emp_pending_bale << query.value(10).toString().trimmed();
                            lst_selected_emp_pending_bale_amount << query.value(11).toString().trimmed();

                            qDebug()<<"lst_selected_emp_name ===>>>"<<lst_selected_emp_name;
                            qDebug()<<"lst_selected_emp_gender ===>>>"<<lst_selected_emp_gender;
                            qDebug()<<"salary_per_hour ===>>>"<<salary_per_hour;
                            qDebug()<<"lst_selected_emp_target ===>>>"<<lst_selected_emp_target;
                            qDebug()<<"lst_selected_emp_target_charge ===>>>"<<lst_selected_emp_target_charge;
                            qDebug()<<"lst_selected_emp_balance ===>>>"<<lst_selected_emp_balance;
                            qDebug()<<"lst_selected_emp_pending_bale ===>>>"<<lst_selected_emp_pending_bale;
                            qDebug()<<"lst_selected_emp_pending_bale_amount ===>>>"<<lst_selected_emp_pending_bale_amount;

                            charge_per_bale = lst_selected_emp_target_charge.at(0).toFloat()/lst_selected_emp_target.at(0).toFloat();

                            qDebug()<<"charge_per_bale ===>>>"<<charge_per_bale;

#if(SDK75)
                            g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
#endif

                            ui->checkBox_hrs->setChecked(false);
                            ui->checkBox_target->setChecked(false);

                            ui->lineEdit_hrs->clear();

                            ui->checkBox_target->setFocus();
                        }
                    }
                }

#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                ui->checkBox_target->setFocus();
                return true;
            }
        }
    }
    else if(target == ui->lineEdit_hrs)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {

                if(ui->checkBox_hrs->isChecked())
                {
                    hrs_salary = QString::number(ceil(ui->lineEdit_hrs->text().trimmed().toFloat() * salary_per_hour.trimmed().toFloat()));
                    worked_hrs = ui->lineEdit_hrs->text().trimmed();

                    qDebug()<<"hrs_salary ===>>>"<<hrs_salary;
                    qDebug()<<"worked_hrs ===>>>"<<worked_hrs;
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                    ui->pushButton_save_emp_salary->setFocus();
                    //! save employee salary

                }
                else
                {
                    hrs_salary.clear();
                    worked_hrs.clear();
                }

                return true;
            }
        }
    }
    else if(target == ui->checkBox_hrs)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(!ui->checkBox_hrs->isChecked())
                {
                    ui->pushButton_save_emp_salary->setEnabled(true);
                    ui->label_hrs->show();
                    ui->lineEdit_hrs->show();

                    ui->checkBox_hrs->setChecked(true);
                    return true;
                }
                if(ui->checkBox_hrs->isChecked())
                {

                    if(!ui->checkBox_target->isChecked())
                        ui->pushButton_save_emp_salary->setEnabled(false);

                    ui->checkBox_hrs->setChecked(false);

                    ui->label_hrs->hide();
                    ui->lineEdit_hrs->hide();
                    return true;
                }
                return true;
            }
        }
    }
    else if(target == ui->checkBox_target)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {

                if(!ui->checkBox_target->isChecked())
                {
                    ui->pushButton_save_emp_salary->setEnabled(true);
                    ui->checkBox_target->setChecked(true);
                    estimated_salary = QString::number(ceil(charge_per_bale* ui->lineEdit_bale_produced->text().trimmed().toFloat()));
                    return true;

                }
                if(ui->checkBox_target->isChecked())
                {
                    if(!ui->checkBox_hrs->isChecked())
                        ui->pushButton_save_emp_salary->setEnabled(false);

                    ui->checkBox_target->setChecked(false);
                    estimated_salary.clear();
                    return true;
                }

                return true;
            }
        }
    }

    else
    {
        return false;
    }
    return false;
}
