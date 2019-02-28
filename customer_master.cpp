#include "customer_master.h"
#include "ui_customer_master.h"

#include <qdebug.h>
#include <QMessageBox>

#include <global.h>
using namespace Global;

Customer_Master::Customer_Master(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Customer_Master)
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

Customer_Master::~Customer_Master()
{
    delete ui;
}

void Customer_Master::call_Customer_Master()
{
    ui->lineEdit_vehicle_number->clear();
    ui->comboBox_reg_owner->setCurrentIndex(0);

    ui->lineEdit_vehicle_number->setValidator(gAmtValidator2);

    ui->lineEdit_reg_name->clear();

    ui->lineEdit_mobile->clear();
//    ui->lineEdit_mobile->hide();
//    ui->lineEdit_mobile->hide();

    ui->lineEdit_reg_breadth->clear();
    ui->lineEdit_reg_breadth_inche->clear();
    ui->lineEdit_reg_length->clear();
    ui->lineEdit_reg_length_inche->clear();

    ui->lineEdit_reg_opening_balance->clear();

    ui->radioButton_reg_bal_pending->hide();
    ui->radioButton_reg_bal_advance->hide();
    ui->label_bal_type_title->hide();
    ui->groupBox_customer->hide();

    ui->lineEdit_mobile->hide();

    ui->label_mobile_title->hide();

    ui->pushButton_edit->show();

    ui->pushButton_vehicle_save->setEnabled(false);

    ui->lineEdit_vehicle_number->setReadOnly(false);

    ui->radioButton_reg_bal_advance->installEventFilter(this);
    ui->radioButton_reg_bal_pending->installEventFilter(this);
    ui->comboBox_reg_owner->installEventFilter(this);

//    ui->pushButton_edit->hide();


    ui->groupBox_vehicle->move(0,0);
    ui->groupBox_vehicle->show();


//    ui->gridLayoutWidget_2->setGeometry(10,50,300,160);
    ui->gridLayoutWidget_2->hide();
    ui->gridLayoutWidget->hide();

    lst_vehicle_number.clear();
    QSqlQuery vehicle_details;
    if(databaseObj->selectQuery("select * from vehicle_registration",vehicle_details))
    {
        if(vehicle_details.next())
        {
            lst_vehicle_number << vehicle_details.value(1).toString().trimmed();
        }
        while(vehicle_details.next())
        {
            lst_vehicle_number << vehicle_details.value(1).toString().trimmed();
        }
    }
    qDebug()<<"lst_vehicle_number ===>>>"<<lst_vehicle_number;

    cmpter = new QCompleter(lst_vehicle_number,this);
    cmpter->setCaseSensitivity(Qt::CaseInsensitive);
    cmpter->setCompletionMode(QCompleter::PopupCompletion);
    ui->lineEdit_vehicle_number->setCompleter(cmpter);

    lst_customer_name.clear();
    lst_customer_mobile.clear();
    QSqlQuery customer_details;
    if(databaseObj->selectQuery("select * from customer_master where cus_type=1",customer_details))
    {
        if(customer_details.next())
        {
            lst_customer_name << customer_details.value(1).toString().trimmed();
            lst_customer_mobile << customer_details.value(2).toString().trimmed();
        }
        while(customer_details.next())
        {
            lst_customer_name << customer_details.value(1).toString().trimmed();
            lst_customer_mobile << customer_details.value(2).toString().trimmed();
        }
    }

    cmpter1 = new QCompleter(lst_customer_name,this);
    cmpter1->setCaseSensitivity(Qt::CaseInsensitive);
    cmpter1->setCompletionMode(QCompleter::PopupCompletion);
    ui->lineEdit_reg_name->setCompleter(cmpter1);

#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
#endif
    is_new_customer = false;
    ui->lineEdit_vehicle_number->setFocus();

}

void Customer_Master::on_lineEdit_vehicle_number_returnPressed()
{
    search_vehicle();
}

void Customer_Master::keyPressEvent(QKeyEvent *ke)
{
    if(ke->key()== Qt::Key_Escape)
    {
        if(ui->lineEdit_vehicle_number->text().isEmpty())
        {
            this->close();
            Master_Config_MenuObj->call_Master_Config_Menu();
            Master_Config_MenuObj->show();
            return;
        }
        else
        {
            call_Customer_Master();
        }
    }
    if(ke->key()== Qt::Key_F2)
    {
        ui->radioButton_reg_bal_advance->setEnabled(true);
        ui->radioButton_reg_bal_pending->setEnabled(true);

        ui->pushButton_edit->hide();

        ui->pushButton_vehicle_save->setEnabled(true);
    }
}

void Customer_Master::search_vehicle()
{
    if(!ui->lineEdit_vehicle_number->text().isEmpty())
    {
        QSqlQuery query;
        if(databaseObj->selectQuery("select * from vehicle_registration where vehicle_registration.vehicle_no='"+ui->lineEdit_vehicle_number->text().trimmed()+"'",query))
        {
            if(query.next())
            {
                selected_vehicle_number_id = query.value(0).toString().trimmed();
                selected_vehicle_number = query.value(1).toString().trimmed();
                selected_vehicle_name = query.value(2).toString().trimmed();

                selected_vehicle_length = query.value(3).toString().trimmed();
                selected_vehicle_length_inch = query.value(4).toString().trimmed();
                selected_vehicle_width = query.value(5).toString().trimmed();
                selected_vehicle_width_inch = query.value(6).toString().trimmed();
                selected_vehicle_type = query.value(7).toString().trimmed();

    //                ui->label_length->setText(selected_vehicle_length+"\'"+selected_vehicle_length_inch+"\""+"x"+selected_vehicle_width+"\'"+selected_vehicle_width_inch+"\"");
//                ui->label_vehicle_type->setText(selected_vehicle_name);

                qDebug()<<"new ===>>>";
                ui->lineEdit_reg_length->setText(selected_vehicle_length);
                ui->lineEdit_reg_length_inche->setText(selected_vehicle_length_inch);

                ui->lineEdit_reg_breadth->setText(selected_vehicle_width);
                ui->lineEdit_reg_breadth_inche->setText(selected_vehicle_width_inch);

                ui->lineEdit_reg_opening_balance->setText(selected_cus_balance);

                ui->comboBox_reg_owner->setFocus();

                ui->gridLayoutWidget_2->show();


                if(selected_vehicle_type.toInt() == 0){
                    ui->comboBox_reg_owner->setCurrentIndex(selected_vehicle_type.toInt());
                    selected_vehicle_type_name = "Company";
                    ui->label_reg_name_title->setText("Broker:");


                    ui->lineEdit_reg_name->clear();
                    ui->lineEdit_reg_name->setReadOnly(false);
                    ui->lineEdit_reg_name->clear();

                    ui->gridLayoutWidget->show();
                    ui->gridLayoutWidget->setGeometry(10,50,300,160);

//                    ui->gridLayoutWidget_2->hide();

                    cmpter1 = new QCompleter(lst_customer_name,this);
                    cmpter1->setCaseSensitivity(Qt::CaseInsensitive);
                    cmpter1->setCompletionMode(QCompleter::PopupCompletion);
                    ui->lineEdit_reg_name->setCompleter(cmpter1);

#if(SDK75)
                    g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
#endif

                    ui->lineEdit_reg_name->setFocus();

                    return;


                }
                if(selected_vehicle_type.toInt() == 1){
                    ui->comboBox_reg_owner->setCurrentIndex(selected_vehicle_type.toInt());
                    selected_vehicle_type_name = "Auto";
                    ui->label_reg_name_title->setText("Name:");
                }
                if(selected_vehicle_type.toInt() == 2){
                    ui->comboBox_reg_owner->setCurrentIndex(selected_vehicle_type.toInt());
                    selected_vehicle_type_name = "Van";
                    ui->label_reg_name_title->setText("Name:");
                }

                query.clear();
                if(databaseObj->selectQuery("select * from customer_master where id_vehicle_registration='"+selected_vehicle_number_id+"'",query))
                {
                    if(query.next())
                    {
                        selected_cus_id = query.value(0).toString().trimmed();
                        selected_cus_name = query.value(1).toString().trimmed();
                        selected_cus_mobile = query.value(2).toString().trimmed();
                        selected_cus_balance = query.value(3).toString().trimmed();
                        selected_cus_balance_type = query.value(4).toString().trimmed();
                    }
                }

                ui->lineEdit_reg_name->setText(selected_cus_name);
                ui->lineEdit_mobile->setText(selected_cus_mobile);

                ui->lineEdit_reg_length->setText(selected_vehicle_length);
                ui->lineEdit_reg_length_inche->setText(selected_vehicle_length_inch);

                ui->lineEdit_reg_breadth->setText(selected_vehicle_width);
                ui->lineEdit_reg_breadth_inche->setText(selected_vehicle_width_inch);

                ui->lineEdit_reg_opening_balance->setText(selected_cus_balance);

                ui->label_bal_type_title->show();
                ui->radioButton_reg_bal_advance->show();
                ui->radioButton_reg_bal_pending->show();

                if(selected_cus_balance_type.toInt() == 0)
                {
                    ui->radioButton_reg_bal_advance->setChecked(true);
                    ui->radioButton_reg_bal_advance->setEnabled(true);

                    ui->radioButton_reg_bal_pending->setChecked(false);
                    ui->radioButton_reg_bal_pending->setEnabled(false);
                }
                if(selected_cus_balance_type.toInt() == 1)
                {
                    ui->radioButton_reg_bal_advance->setChecked(false);
                    ui->radioButton_reg_bal_advance->setEnabled(false);

                    ui->radioButton_reg_bal_pending->setChecked(true);
                    ui->radioButton_reg_bal_pending->setEnabled(true);
                }

                ui->lineEdit_vehicle_number->setReadOnly(true);

                ui->comboBox_reg_owner->setFocus();

                ui->gridLayoutWidget_2->show();


            }
            else
            {
                //! vehicle not available
                //! msg for want to reg

                ui->gridLayoutWidget->setGeometry(10,50,300,160);
                ui->gridLayoutWidget->hide();

                ui->gridLayoutWidget_2->setGeometry(0,50,320,160);
                ui->gridLayoutWidget_2->show();
                ui->pushButton_edit->hide();
                is_new_customer = true;
                ui->comboBox_reg_owner->setFocus();


            }
        }
    }
}

void Customer_Master::on_pushButton_vehicle_save_clicked()
{
#if(NativeCompile)
            QMessageBox gMsg_box;
            QFont gFont;
            gFont.setFamily("DejaVu Sans Mono");
            gFont.setPointSize(12);
            gMsg_box.setFont(gFont);
            gMsg_box.setParent(this);

            if(gMsg_box.question(this, "Status","Do You Want\nTo Update?",QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes)
            {
                qDebug()<<"logout ===>>>";
                if(!ui->lineEdit_reg_name->text().isEmpty() && (ui->lineEdit_reg_length->text().toFloat() > 0) && (ui->lineEdit_reg_breadth->text().toFloat() > 0))
                {

                    QString v_type,company_odometer="";
                    if(ui->comboBox_reg_owner->currentText().contains("company",Qt::CaseInsensitive))
                        v_type = "0";
                    if(ui->comboBox_reg_owner->currentText().contains("auto",Qt::CaseInsensitive))
                        v_type = "1";
                    if(ui->comboBox_reg_owner->currentText().contains("van",Qt::CaseInsensitive))
                        v_type = "2";

                    qDebug()<<"v_type ===>>>"<<v_type;
                    company_odometer.clear();

                    if(v_type.toInt() == 0)
                    {
                        QInputDialog inputDialog;
                        QFont font;
                        font.setFamily("DejaVu Sans Mono");
                        font.setPointSize(14);
                        inputDialog.setInputMode(QInputDialog::TextInput);
                        inputDialog.setTextValue(gstrAppName);
                        inputDialog.setWindowTitle("Input");
                        inputDialog.setLabelText("Enter OdoMeter\nReading:");
                        inputDialog.setFont(font);
                        inputDialog.move(25,50);
                        inputDialog.setWindowFlags(Qt::FramelessWindowHint);

            //            inputDialog.setTextValue(Home_ScreenObj->HP_cft);

                        bool ok;
                        ok = inputDialog.exec();

                        if(ok && !inputDialog.textValue().isEmpty())
                        {
                            company_odometer = inputDialog.textValue().trimmed();
                        }
                        else
                        {
                            ui->pushButton_save->setFocus();
                            return;
                        }
                    }



                    if(databaseObj->executeCommand("update vehicle_registration set vehicle_length='"+ui->lineEdit_reg_length->text().trimmed()+"',vehicle_length_inch='"+ui->lineEdit_reg_length_inche->text().trimmed()+"',vehicle_width='"+ui->lineEdit_reg_breadth->text().trimmed()+"',vehicle_width_inch='"+ui->lineEdit_reg_breadth_inche->text().trimmed()+"',vehicle_owner='"+v_type+"',odometer_reading='"+company_odometer+"' where  vehicle_no='"+ui->lineEdit_vehicle_number->text().trimmed()+"'"))
                    {

                        QSqlQuery qur;
                        QString id_vehicle_registration;
                        if(databaseObj->selectQuery("select id_vehicle_registration from vehicle_registration where vehicle_no='"+ui->lineEdit_vehicle_number->text().trimmed()+"'",qur))
                        {
                            if(qur.next())
                            {
                                id_vehicle_registration = qur.value(0).toString();
                            }
                        }

                        QString op_balance,op_balance_type="";
                        QString Customer_Type;
                        if(!ui->lineEdit_reg_opening_balance->text().isEmpty())
                        {
                            op_balance = ui->lineEdit_reg_opening_balance->text().trimmed();
                            if(ui->radioButton_reg_bal_advance->isChecked())
                            {
                                op_balance_type = "0";
                            }
                            if(ui->radioButton_reg_bal_pending->isChecked())
                            {
                                op_balance_type = "1";
                            }
                        }
                        if(ui->comboBox_reg_owner->currentText().contains("company",Qt::CaseInsensitive))
                        {
                            Customer_Type = "1";
                        }
                        else
                        {
                            Customer_Type = "0";
                        }


                        if(databaseObj->executeCommand("update customer_master set balance='"+op_balance+"',balance_type='"+op_balance_type+"',id_vehicle_registration='"+id_vehicle_registration+"',cus_type='"+Customer_Type+"' where cus_name='"+selected_cus_name+"'"))
                        {
                            call_Customer_Master();
                        }
                    }
                }
            }
#endif


#if(SDK75)

            if(is_new_customer)
            {
                qDebug()<<"on_pushButton_reg_save_clicked ===>>>";
                if(!ui->lineEdit_vehicle_number->text().isEmpty())
                {
                    qDebug()<<"on_pushButton_reg_save_clicked 2 ===>>>";
                    if(!ui->lineEdit_reg_name->text().isEmpty() && (ui->lineEdit_reg_length->text().toFloat() > 0) && (ui->lineEdit_reg_breadth->text().toFloat() > 0))
                    {
                        qDebug()<<"on_pushButton_reg_save_clicked 3 ===>>>";
                        float len = ui->lineEdit_reg_length->text().trimmed().toInt() + (ui->lineEdit_reg_length_inche->text().trimmed().toInt()/12);
                        float bre = ui->lineEdit_reg_breadth->text().trimmed().toInt() + (ui->lineEdit_reg_breadth_inche->text().trimmed().toInt()/12);

                        QString v_type;
                        if(ui->comboBox_reg_owner->currentText().contains("company",Qt::CaseInsensitive))
                            v_type = "0";
                        if(ui->comboBox_reg_owner->currentText().contains("auto",Qt::CaseInsensitive))
                            v_type = "1";
                        if(ui->comboBox_reg_owner->currentText().contains("van",Qt::CaseInsensitive))
                            v_type = "2";

                        qDebug()<<"v_type ===>>>"<<v_type;

                        QString company_odometer;


                        if(v_type.toInt() == 0)
                        {
                            QInputDialog inputDialog;
                            QFont font;
                            font.setFamily("DejaVu Sans Mono");
                            font.setPointSize(14);
                            inputDialog.setInputMode(QInputDialog::TextInput);
                            inputDialog.setTextValue(gstrAppName);
                            inputDialog.setWindowTitle("Input");
                            inputDialog.setLabelText("Enter OdoMeter\nReading:");
                            inputDialog.setFont(font);
                            inputDialog.move(25,50);
                            inputDialog.setWindowFlags(Qt::FramelessWindowHint);

                //            inputDialog.setTextValue(Home_ScreenObj->HP_cft);

                            bool ok;
                            ok = inputDialog.exec();

                            if(ok && !inputDialog.textValue().isEmpty())
                            {
                                company_odometer = inputDialog.textValue().trimmed();
                            }
                            else
                            {
                                ui->pushButton_vehicle_save->setFocus();
                                return;
                            }
                        }

                        if(databaseObj->executeCommand("insert into vehicle_registration (vehicle_no,vehicle_name,vehicle_length,vehicle_length_inch,vehicle_width,vehicle_width_inch,vehicle_owner,odometer_reading) values ('"+ui->lineEdit_vehicle_number->text()+"','"+ui->lineEdit_reg_name->text()+"','"+ui->lineEdit_reg_length->text().trimmed()+"','"+ui->lineEdit_reg_length_inche->text().trimmed()+"','"+ui->lineEdit_reg_breadth->text().trimmed()+"','"+ui->lineEdit_reg_breadth_inche->text().trimmed()+"','"+v_type+"','"+company_odometer+"')"))
                        {
                            qDebug()<<"on_pushButton_reg_save_clicked 4 ===>>>";
                            databaseObj->con.commit();

                            QSqlQuery qur;
                            QString id_vehicle_registration;
                            if(databaseObj->selectQuery("select id_vehicle_registration from vehicle_registration where vehicle_no='"+ui->lineEdit_vehicle_number->text().trimmed()+"'",qur))
                            {
                                if(qur.next())
                                {
                                    id_vehicle_registration = qur.value(0).toString();
                                }
                            }


                            QString op_balance,op_balance_type="";
                            QString Customer_Type;
                            if(!ui->lineEdit_reg_opening_balance->text().isEmpty())
                            {
                                op_balance = ui->lineEdit_reg_opening_balance->text().trimmed();
                                if(ui->radioButton_reg_bal_advance->isChecked())
                                {
                                    op_balance_type = "0";
                                }
                                if(ui->radioButton_reg_bal_pending->isChecked())
                                {
                                    op_balance_type = "1";
                                }
                            }
                            if(ui->comboBox_reg_owner->currentText().contains("company",Qt::CaseInsensitive))
                            {
                                Customer_Type = "1";
                            }
                            else
                            {
                                Customer_Type = "0";
                            }
                            if(databaseObj->executeCommand("insert into customer_master (cus_name,balance,balance_type,id_vehicle_registration,cus_type) values ('"+ui->lineEdit_reg_name->text().trimmed()+"','"+op_balance+"','"+op_balance_type+"','"+id_vehicle_registration+"','"+Customer_Type+"')"))
                            {
                                call_Customer_Master();
                            }
                        }
                    }
                }
                return;
            }
            int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Error,"Do You Want\nTo Update?",16,14,"YES","NO");
            if(ret==1)
            {
                qDebug()<<"logout ===>>>";
                if(!ui->lineEdit_reg_name->text().isEmpty() && (ui->lineEdit_reg_length->text().toFloat() > 0) && (ui->lineEdit_reg_breadth->text().toFloat() > 0))
                {

                    QString v_type,company_odometer="";
                    if(ui->comboBox_reg_owner->currentText().contains("company",Qt::CaseInsensitive))
                        v_type = "0";
                    if(ui->comboBox_reg_owner->currentText().contains("auto",Qt::CaseInsensitive))
                        v_type = "1";
                    if(ui->comboBox_reg_owner->currentText().contains("van",Qt::CaseInsensitive))
                        v_type = "2";

                    qDebug()<<"v_type ===>>>"<<v_type;
                    company_odometer.clear();

                    if(v_type.toInt() == 0)
                    {
                        QInputDialog inputDialog;
                        QFont font;
                        font.setFamily("DejaVu Sans Mono");
                        font.setPointSize(14);
                        inputDialog.setInputMode(QInputDialog::TextInput);
                        inputDialog.setTextValue(gstrAppName);
                        inputDialog.setWindowTitle("Input");
                        inputDialog.setLabelText("Enter OdoMeter\nReading:");
                        inputDialog.setFont(font);
                        inputDialog.move(25,50);
                        inputDialog.setWindowFlags(Qt::FramelessWindowHint);

            //            inputDialog.setTextValue(Home_ScreenObj->HP_cft);

                        bool ok;
                        ok = inputDialog.exec();

                        if(ok && !inputDialog.textValue().isEmpty())
                        {
                            company_odometer = inputDialog.textValue().trimmed();
                        }
                        else
                        {
                            ui->pushButton_save->setFocus();
                            return;
                        }
                    }



                    if(databaseObj->executeCommand("update vehicle_registration set vehicle_length='"+ui->lineEdit_reg_length->text().trimmed()+"',vehicle_length_inch='"+ui->lineEdit_reg_length_inche->text().trimmed()+"',vehicle_width='"+ui->lineEdit_reg_breadth->text().trimmed()+"',vehicle_width_inch='"+ui->lineEdit_reg_breadth_inche->text().trimmed()+"',vehicle_owner='"+v_type+"',odometer_reading='"+company_odometer+"' where  vehicle_no='"+ui->lineEdit_vehicle_number->text().trimmed()+"'"))
                    {

                        QSqlQuery qur;
                        QString id_vehicle_registration;
                        if(databaseObj->selectQuery("select id_vehicle_registration from vehicle_registration where vehicle_no='"+ui->lineEdit_vehicle_number->text().trimmed()+"'",qur))
                        {
                            if(qur.next())
                            {
                                id_vehicle_registration = qur.value(0).toString();
                            }
                        }

                        QString op_balance,op_balance_type="";
                        QString Customer_Type;
                        if(!ui->lineEdit_reg_opening_balance->text().isEmpty())
                        {
                            op_balance = ui->lineEdit_reg_opening_balance->text().trimmed();
                            if(ui->radioButton_reg_bal_advance->isChecked())
                            {
                                op_balance_type = "0";
                            }
                            if(ui->radioButton_reg_bal_pending->isChecked())
                            {
                                op_balance_type = "1";
                            }
                        }
                        if(ui->comboBox_reg_owner->currentText().contains("company",Qt::CaseInsensitive))
                        {
                            Customer_Type = "1";
                        }
                        else
                        {
                            Customer_Type = "0";
                        }


                        if(databaseObj->executeCommand("update customer_master set balance='"+op_balance+"',balance_type='"+op_balance_type+"',id_vehicle_registration='"+id_vehicle_registration+"',cus_type='"+Customer_Type+"' where cus_name='"+selected_cus_name+"'"))
                        {
                            call_Customer_Master();
                        }
                    }
                }
            }
            else
            {
                ui->lineEdit_reg_length->setFocus();
            }
#endif
}

void Customer_Master::on_lineEdit_reg_name_returnPressed()
{
    if(ui->comboBox_reg_owner->currentText().contains("company",Qt::CaseInsensitive))
    {
        if(!ui->lineEdit_reg_name->text().isEmpty())
        {
            QSqlQuery query;
            if(databaseObj->selectQuery("select * from customer_master where cus_name='"+ui->lineEdit_reg_name->text().trimmed()+"'",query))
            {
                if(query.next())
                {
                    selected_cus_id = query.value(0).toString().trimmed();
                    selected_cus_name = query.value(1).toString().trimmed();
                    selected_cus_mobile = query.value(2).toString().trimmed();
                    selected_cus_balance = query.value(3).toString().trimmed();
                    selected_cus_balance_type = query.value(4).toString().trimmed();

                    ui->lineEdit_reg_name->setText(selected_cus_name);

                    ui->lineEdit_reg_opening_balance->setText(selected_cus_balance);

                    ui->label_bal_type_title->show();
                    ui->radioButton_reg_bal_advance->show();
                    ui->radioButton_reg_bal_pending->show();

                    if(selected_cus_balance_type.toInt() == 0)
                    {
                        ui->radioButton_reg_bal_advance->setChecked(true);
                        ui->radioButton_reg_bal_advance->setEnabled(true);

                        ui->radioButton_reg_bal_pending->setChecked(false);
                        ui->radioButton_reg_bal_pending->setEnabled(false);
                    }
                    if(selected_cus_balance_type.toInt() == 1)
                    {
                        ui->radioButton_reg_bal_advance->setChecked(false);
                        ui->radioButton_reg_bal_advance->setEnabled(false);

                        ui->radioButton_reg_bal_pending->setChecked(true);
                        ui->radioButton_reg_bal_pending->setEnabled(true);
                    }

                    ui->lineEdit_vehicle_number->setReadOnly(true);



#if(SDK75)
                    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                    ui->lineEdit_reg_length->setFocus();
                }
                else
                {
                    //! invalid customer
                    //! msg before add
                    if(gstrUserType.toInt() != 0)
                    {
                        if(!is_new_customer)
                        {
#if(NativeCompile)
                            QMessageBox gMsg_box;
                            QFont gFont;
                            gFont.setFamily("DejaVu Sans Mono");
                            gFont.setPointSize(12);
                            gMsg_box.setFont(gFont);
                            gMsg_box.setParent(this);

                            if(gMsg_box.question(this, "Status","Invalid Customer..!\nAdd As New\nCustomer?",QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes)
                            {
                                qDebug()<<"Invalid Customer Add as new yes ===>>>";
                                if(databaseObj->executeCommand("insert into customer_master (cus_name,balance,balance_type,id_vehicle_registration,cus_type) values ('"+ui->lineEdit_reg_name->text().trimmed()+"','','','"+selected_vehicle_number_id+"','1')"))
                                {
                                    selected_cus_name = ui->lineEdit_reg_name->text().trimmed();
                                    selected_cus_balance = "0";
                                    selected_cus_balance_type = "0";
                                    ui->lineEdit_reg_length->setFocus();

                                    query.clear();
                                    if(databaseObj->selectQuery("select * from customer_master where cus_name='"+ui->lineEdit_reg_name->text().trimmed()+"'",query))
                                    {
                                        if(query.next())
                                        {
                                            selected_cus_id = query.value(0).toString().trimmed();
                                            selected_cus_name = query.value(1).toString().trimmed();
                                            selected_cus_mobile = query.value(2).toString().trimmed();
                                            selected_cus_balance = query.value(3).toString().trimmed();
                                            selected_cus_balance_type = query.value(4).toString().trimmed();

                                            ui->lineEdit_reg_length->setFocus();
                                        }
                                    }
                                }
                                else
                                {

                                }
                            }
                            else
                            {
                                qDebug()<<"Invalid Customer Add as new no ===>>>";
                                ui->lineEdit_reg_name->setFocus();
                            }
#endif
#if(SDK75)
                            int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Error,"Invalid Customer..!\nAdd As New\nCustomer?",16,14,"YES","NO");
                            if(ret==1)
                            {
                                qDebug()<<"Invalid Customer Add as new yes ===>>>";
                                //                        if(databaseObj->executeCommand("insert into customer_master (cus_name,balance,balance_type,id_vehicle_registration,cus_type) values ('"+ui->lineEdit_customer_name->text().trimmed()+"','','','"+selected_vehicle_number_id+"','1')"))
                                //                        {
                                //                            selected_cus_name = ui->lineEdit_customer_name->text().trimmed();
                                //                            selected_cus_balance = "0";
                                //                            selected_cus_balance_type = "0";
                                //                            ui->radioButton_cft->setFocus();

                                //                            query.clear();
                                //                            if(databaseObj->selectQuery("select * from customer_master where cus_name='"+ui->lineEdit_customer_name->text().trimmed()+"'",query))
                                //                            {
                                //                                if(query.next())
                                //                                {
                                //                                    selected_cus_id = query.value(0).toString().trimmed();
                                //                                    selected_cus_name = query.value(1).toString().trimmed();
                                //                                    selected_cus_mobile = query.value(2).toString().trimmed();
                                //                                    selected_cus_balance = query.value(3).toString().trimmed();
                                //                                    selected_cus_balance_type = query.value(4).toString().trimmed();

                                //                                    ui->lineEdit_customer_mobile->setText(selected_cus_mobile);
                                //                                    ui->radioButton_cft->setFocus();
                                //                                }
                                //                            }

                                //                        }
                                //                        else
                                //                        {

                                //                        }
                                qDebug()<<"is_new_customer ===>>>"<<is_new_customer;
                                if(databaseObj->executeCommand("insert into customer_master (cus_name,balance,balance_type,id_vehicle_registration,cus_type) values ('"+ui->lineEdit_reg_name->text().trimmed()+"','','','"+selected_vehicle_number_id+"','1')"))
                                {
                                    selected_cus_name = ui->lineEdit_reg_name->text().trimmed();
                                    selected_cus_balance = "0";
                                    selected_cus_balance_type = "0";
                                    ui->lineEdit_reg_length->setFocus();

                                    query.clear();
                                    if(databaseObj->selectQuery("select * from customer_master where cus_name='"+ui->lineEdit_reg_name->text().trimmed()+"'",query))
                                    {
                                        if(query.next())
                                        {
                                            selected_cus_id = query.value(0).toString().trimmed();
                                            selected_cus_name = query.value(1).toString().trimmed();
                                            selected_cus_mobile = query.value(2).toString().trimmed();
                                            selected_cus_balance = query.value(3).toString().trimmed();
                                            selected_cus_balance_type = query.value(4).toString().trimmed();

                                            ui->lineEdit_reg_length->setFocus();
                                        }
                                    }
                                }
                                else
                                {

                                }

                            }
                            else
                            {
                                qDebug()<<"Invalid Customer Add as new no ===>>>";
                                ui->lineEdit_reg_name->setFocus();
                            }
#endif


                        }
                        else
                        {
                            ui->lineEdit_reg_length->setFocus();
                        }
                    }


                    //                ui->lineEdit_customer_mobile->setFocus();
                }
            }
        }
    }
    else
    {
        if(!ui->lineEdit_reg_name->text().isEmpty())
        {
    #if(SDK75)
            g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
    #endif
            ui->lineEdit_reg_length->setFocus();
        }
    }
}

void Customer_Master::on_lineEdit_reg_length_returnPressed()
{
    if(!ui->lineEdit_reg_length->text().isEmpty())
    {
#if(SDK75)
        g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
        ui->lineEdit_reg_length_inche->setFocus();
    }
}

void Customer_Master::on_lineEdit_reg_length_inche_returnPressed()
{
    ui->lineEdit_reg_breadth->setFocus();
}

void Customer_Master::on_lineEdit_reg_breadth_returnPressed()
{
    if(!ui->lineEdit_reg_breadth->text().isEmpty())
    {
#if(SDK75)
        g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
        ui->lineEdit_reg_breadth_inche->setFocus();
    }
}

void Customer_Master::on_lineEdit_reg_breadth_inche_returnPressed()
{
    ui->lineEdit_reg_opening_balance->setFocus();
}

void Customer_Master::on_lineEdit_reg_opening_balance_returnPressed()
{
    if(ui->lineEdit_reg_opening_balance->text().toInt() >= 0)
    {
        ui->radioButton_reg_bal_pending->show();
        ui->radioButton_reg_bal_advance->show();
        ui->label_bal_type_title->show();

        ui->pushButton_vehicle_save->setEnabled(true);

        ui->radioButton_reg_bal_pending->setFocus();
    }
}

bool Customer_Master::eventFilter(QObject *target, QEvent *event)
{

    QKeyEvent *key = static_cast <QKeyEvent*> (event);

    if(target == ui->radioButton_reg_bal_advance)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                ui->radioButton_reg_bal_advance->setChecked(true);
                ui->radioButton_reg_bal_pending->setChecked(false);

                ui->pushButton_vehicle_save->setFocus();
                return true;
            }
        }
    }
    else if(target == ui->radioButton_reg_bal_pending)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                ui->radioButton_reg_bal_pending->setChecked(true);
                ui->radioButton_reg_bal_advance->setChecked(false);

                ui->pushButton_vehicle_save->setFocus();
                return true;
            }
        }
    }
    else if(target == ui->comboBox_reg_owner)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->comboBox_reg_owner->hasFocus())
                {
                    if(ui->comboBox_reg_owner->currentText().contains("Company"))
                        ui->label_reg_name_title->setText("Broker:");
                    else
                        ui->label_reg_name_title->setText("Name:");

#if(SDK75)
                    g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
#endif
                    ui->lineEdit_reg_name->setFocus();

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

void Customer_Master::on_lineEdit_vehicle_number_textEdited(const QString &arg1)
{
    ui->lineEdit_vehicle_number->setText(arg1.toUpper());
}
