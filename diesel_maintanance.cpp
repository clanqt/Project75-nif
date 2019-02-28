#include "diesel_maintanance.h"
#include "ui_diesel_maintanance.h"

#include <QMessageBox>

#include <global.h>
using namespace Global;

Diesel_Maintanance::Diesel_Maintanance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Diesel_Maintanance)
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
//    setFixedSize(320,240);

//    scroll = new QScrollArea(ui->groupBox);
//    scroll->setWidget(ui->gridLayoutWidget_2);
//    scroll->move(0,30);
//    scroll->setFixedSize(320,150);//160
//    scroll->setFocusPolicy(Qt::NoFocus);
//    scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
//    scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);



}

Diesel_Maintanance::~Diesel_Maintanance()
{
    delete ui;
}

void Diesel_Maintanance::call_Diesel_Maintanance()
{
    show_screen(1);

    ui->label_closing_stock_2->clear();

    ui->lineEdit_input_qty->clear();
    ui->lineEdit_meter_reading->clear();

    ui->comboBox_vehicle_number->installEventFilter(this);
    ui->lineEdit_input_qty->installEventFilter(this);
    ui->radioButton_full->installEventFilter(this);
    ui->radioButton_part->installEventFilter(this);
}

void Diesel_Maintanance::keyPressEvent(QKeyEvent *ke)
{
    if(ke->key()== Qt::Key_Escape)
    {
        if(ui->groupBox_home->isVisible())
        {
            this->close();
            menuObj->call_menu();
            menuObj->show();
            return;
        }
        if(ui->groupBox_Diesel_Purchase->isVisible() || ui->groupBox_Diesel_Usage->isVisible())
        {
            show_screen(1);
            return;
        }
        if(ui->groupBox_Diesel_Usage_Entry->isVisible())
        {
            show_screen(3);
            return;
        }
    }
}

bool Diesel_Maintanance::eventFilter(QObject *target, QEvent *event)
{
    QKeyEvent *key = static_cast <QKeyEvent*> (event);

    if(target == ui->comboBox_vehicle_number)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->comboBox_vehicle_number->hasFocus())
                {
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                    ui->lineEdit_input_qty->setFocus();
                }
            }
        }
    }
    else if(target == ui->lineEdit_input_qty)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->lineEdit_input_qty->hasFocus())
                {
                    ui->label_closing_stock_2->setText(QString::number(initial_diesel_stock.toFloat() - ui->lineEdit_input_qty->text().toFloat()));

#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
#endif
                    ui->radioButton_full->setFocus();
                }
            }
        }
    }
    else if(target == ui->radioButton_full)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->radioButton_full->hasFocus())
                {
                    ui->radioButton_full->setChecked(true);
                    ui->radioButton_part->setChecked(false);
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                    ui->lineEdit_meter_reading->setFocus();
                }
            }
        }
    }
    else if(target == ui->radioButton_part)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->radioButton_part->hasFocus())
                {
                    ui->radioButton_full->setChecked(false);
                    ui->radioButton_part->setChecked(true);
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                    ui->lineEdit_meter_reading->setFocus();
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

void Diesel_Maintanance::show_screen(int screen_no)
{
    if(screen_no == 1)
    {
        ui->groupBox_Diesel_Purchase->hide();
        ui->groupBox_Diesel_Purchase->move(0,0);

        ui->groupBox_Diesel_Usage->hide();
        ui->groupBox_Diesel_Usage->move(0,0);

        ui->groupBox_Diesel_Usage_Entry->hide();
        ui->groupBox_Diesel_Usage_Entry->move(0,0);

        ui->groupBox_home->show();
        ui->groupBox_home->move(0,0);
        ui->groupBox_home->raise();

        ui->pushButton_purchase->setFocus();
    }
    else if(screen_no == 2)
    {
        ui->groupBox_Diesel_Purchase->show();
        ui->groupBox_Diesel_Purchase->move(0,0);
        ui->groupBox_Diesel_Purchase->raise();

        ui->groupBox_Diesel_Usage->hide();
        ui->groupBox_Diesel_Usage->move(0,0);

        ui->groupBox_Diesel_Usage_Entry->hide();
        ui->groupBox_Diesel_Usage_Entry->move(0,0);

        ui->groupBox_home->hide();
        ui->groupBox_home->move(0,0);
        ui->groupBox_home->lower();

        ui->label_opening_stock->clear();
        ui->lineEdit_today_parchase->clear();
        ui->lineEdit_bill_value->clear();
        ui->lineEdit_bunk_name->clear();
        ui->label_rate_per_liter->clear();
        ui->pushButton_save->setEnabled(false);

        QSqlQuery query;
        if(databaseObj->selectQuery("select init_diesel_reading from configuration_master",query))
        {
            if(query.next())
            {
                initial_diesel_stock = query.value(0).toString().trimmed();
            }
        }
        if(initial_diesel_stock.isEmpty())
            ui->label_opening_stock->setText("0");
        else
            ui->label_opening_stock->setText(initial_diesel_stock);

        query.clear();
        lst_bunk_name.clear();
        if(databaseObj->selectQuery("select bunk_name,id_bunk_master from bunk_master",query))
        {
            if(query.next())
            {
                lst_bunk_name << query.value(0).toString().trimmed();
                lst_bunk_id << query.value(1).toString().trimmed();
                while(query.next())
                {
                    lst_bunk_name << query.value(0).toString().trimmed();
                    lst_bunk_id << query.value(1).toString().trimmed();
                }

                cmpter = new QCompleter(lst_bunk_name,this);
                cmpter->setCaseSensitivity(Qt::CaseInsensitive);
                cmpter->setCompletionMode(QCompleter::PopupCompletion);
                ui->lineEdit_bunk_name->setCompleter(cmpter);
            }
        }

        ui->lineEdit_today_parchase->setFocus();
    }
    else if(screen_no == 3)
    {
        ui->groupBox_Diesel_Purchase->hide();
        ui->groupBox_Diesel_Purchase->move(0,0);

        ui->groupBox_Diesel_Usage->show();
        ui->groupBox_Diesel_Usage->move(0,0);
        ui->groupBox_Diesel_Usage->raise();

        ui->groupBox_Diesel_Usage_Entry->hide();
        ui->groupBox_Diesel_Usage_Entry->move(0,0);

        ui->groupBox_home->hide();
        ui->groupBox_home->move(0,0);
        ui->groupBox_home->lower();

        ui->pushButton_bull->setFocus();
    }

    else if(screen_no == 4)
    {
        //! Bull usage
        ui->groupBox_Diesel_Purchase->hide();
        ui->groupBox_Diesel_Purchase->move(0,0);

        ui->groupBox_Diesel_Usage->hide();
        ui->groupBox_Diesel_Usage->move(0,0);
        ui->groupBox_Diesel_Usage->lower();

        ui->groupBox_Diesel_Usage_Entry->show();
        ui->groupBox_Diesel_Usage_Entry->move(0,0);

        ui->groupBox_home->hide();
        ui->groupBox_home->move(0,0);
        ui->groupBox_home->lower();

        ui->label_usage_title->setText("Bull Usage");

        ui->label_cv_title->hide();
        ui->comboBox_vehicle_number->hide();

        ui->lineEdit_input_qty->setFocus();

    }

    else if(screen_no == 5)
    {
        //! Generator usage
        ui->groupBox_Diesel_Purchase->hide();
        ui->groupBox_Diesel_Purchase->move(0,0);

        ui->groupBox_Diesel_Usage->hide();
        ui->groupBox_Diesel_Usage->move(0,0);
        ui->groupBox_Diesel_Usage->lower();

        ui->groupBox_Diesel_Usage_Entry->show();
        ui->groupBox_Diesel_Usage_Entry->move(0,0);

        ui->groupBox_home->hide();
        ui->groupBox_home->move(0,0);
        ui->groupBox_home->lower();

        ui->label_usage_title->setText("Generator Usage");

        ui->label_cv_title->hide();
        ui->comboBox_vehicle_number->hide();

        ui->lineEdit_input_qty->setFocus();

    }

    else if(screen_no == 6)
    {
        //! Company Vehicle
        ui->groupBox_Diesel_Purchase->hide();
        ui->groupBox_Diesel_Purchase->move(0,0);

        ui->groupBox_Diesel_Usage->hide();
        ui->groupBox_Diesel_Usage->move(0,0);
        ui->groupBox_Diesel_Usage->lower();

        ui->groupBox_Diesel_Usage_Entry->show();
        ui->groupBox_Diesel_Usage_Entry->move(0,0);

        ui->groupBox_home->hide();
        ui->groupBox_home->move(0,0);
        ui->groupBox_home->lower();

        ui->label_usage_title->setText("Company Vehicle");

        ui->label_cv_title->show();
        ui->comboBox_vehicle_number->show();

        ui->comboBox_vehicle_number->setFocus();

    }

}

void Diesel_Maintanance::on_pushButton_purchase_clicked()
{
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
    show_screen(2);
}

void Diesel_Maintanance::on_pushButton_usage_clicked()
{
    show_screen(3);
}

void Diesel_Maintanance::on_pushButton_bull_clicked()
{
    QSqlQuery query;
    initial_diesel_stock.clear();
    if(databaseObj->selectQuery("select init_diesel_reading from configuration_master",query))
    {
        if(query.next())
        {
            initial_diesel_stock = query.value(0).toString().trimmed();
        }
    }
    if(initial_diesel_stock.isEmpty())
        ui->label_opening_stock_2->setText("0");
    else
        ui->label_opening_stock_2->setText(initial_diesel_stock);

    ui->label_closing_stock_2->clear();
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
    show_screen(4);
}

void Diesel_Maintanance::on_pushButton_generator_clicked()
{
    QSqlQuery query;
    initial_diesel_stock.clear();
    if(databaseObj->selectQuery("select init_diesel_reading from configuration_master",query))
    {
        if(query.next())
        {
            initial_diesel_stock = query.value(0).toString().trimmed();
        }
    }
    if(initial_diesel_stock.isEmpty())
        ui->label_opening_stock_2->setText("0");
    else
        ui->label_opening_stock_2->setText(initial_diesel_stock);

    ui->label_closing_stock_2->clear();
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
    show_screen(5);
}

void Diesel_Maintanance::on_pushButton_company_vehicle_clicked()
{
    QSqlQuery query;
    initial_diesel_stock.clear();
    if(databaseObj->selectQuery("select init_diesel_reading from configuration_master",query))
    {
        if(query.next())
        {
            initial_diesel_stock = query.value(0).toString().trimmed();
        }
    }
    if(initial_diesel_stock.isEmpty())
        ui->label_opening_stock_2->setText("0");
    else
        ui->label_opening_stock_2->setText(initial_diesel_stock);
    ui->label_closing_stock_2->clear();


    QSqlQuery vehicle_details;
    lst_vehicle_number.clear();
    if(databaseObj->selectQuery("select * from vehicle_registration where vehicle_owner='0'",vehicle_details))
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
    ui->comboBox_vehicle_number->clear();
    ui->comboBox_vehicle_number->addItems(lst_vehicle_number);
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
    show_screen(6);
}


void Diesel_Maintanance::on_lineEdit_today_parchase_returnPressed()
{
    if(!ui->lineEdit_today_parchase->text().trimmed().isEmpty() && ui->lineEdit_today_parchase->text().toInt() > 0)
    {
        ui->label_closing_stock->setText(QString::number(ui->lineEdit_today_parchase->text().toFloat() + initial_diesel_stock.toFloat(),'f',2));
        ui->lineEdit_bill_value->setFocus();
    }
}

void Diesel_Maintanance::on_lineEdit_bill_value_returnPressed()
{
    qDebug()<<"test 1===>>>"<<ui->lineEdit_bill_value->text();
    if((!ui->lineEdit_bill_value->text().trimmed().isEmpty()) && (ui->lineEdit_bill_value->text().toInt() > 0))
    {
        qDebug()<<"test ===>>>";
        QInputDialog inputDialog;
        QFont font;
        font.setFamily("DejaVu Sans Mono");
        font.setPointSize(14);
        inputDialog.setInputMode(QInputDialog::TextInput);
        inputDialog.setTextValue(gstrAppName);
        inputDialog.setWindowTitle("Input");
        inputDialog.setLabelText("Enter The Bill No:");
        inputDialog.setFont(font);
        inputDialog.move(25,50);
        inputDialog.setWindowFlags(Qt::FramelessWindowHint);

        bool ok;
        ok = inputDialog.exec();

        if(ok && !inputDialog.textValue().isEmpty())
        {
            bill_no = inputDialog.textValue().trimmed();
        }

        ui->label_rate_per_liter->setText(QString::number(ui->lineEdit_bill_value->text().toFloat() / ui->lineEdit_today_parchase->text().toFloat(),'f',2));
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
#endif
        ui->lineEdit_bunk_name->setFocus();


    }
}

void Diesel_Maintanance::on_lineEdit_bunk_name_returnPressed()
{
    if(!ui->lineEdit_bunk_name->text().isEmpty())
    {
        QSqlQuery query;
        if(databaseObj->selectQuery("select * from bunk_master where bunk_name='"+ui->lineEdit_bunk_name->text().trimmed()+"'",query))
        {
            if(query.next())
            {
                selected_bunk_name = ui->lineEdit_bunk_name->text().trimmed();
                ui->pushButton_save->setEnabled(true);
                ui->pushButton_save->setFocus();
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

                if(gMsg_box.information(this, "Success","Bunk Not Exists..!",QMessageBox::Ok) == QMessageBox::Ok)
                {
                    ui->lineEdit_bunk_name->clear();
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
#endif
                    ui->lineEdit_bunk_name->setFocus();
                }
#endif

#if(SDK75)
                int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"Bunk Not Exists..!",16,14);
                ui->lineEdit_bunk_name->clear();
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
#endif
                ui->lineEdit_bunk_name->setFocus();
#endif
            }
        }

    }
}

void Diesel_Maintanance::on_lineEdit_bunk_name_textEdited(const QString &arg1)
{
    selected_bunk_name.clear();
}

void Diesel_Maintanance::on_pushButton_save_clicked()
{
    qDebug()<<"test 2===>>>"<<selected_bunk_name;
    for(int i=0;i<lst_bunk_name.size();i++)
    {
        qDebug()<<"test 3===>>>";
        if(lst_bunk_name.at(i).compare(selected_bunk_name,Qt::CaseSensitive) == 0)
        {
            qDebug()<<"test 4===>>>";

            QSqlQuery bunk_qur;
            QString bunk_op_balance,bunk_op_balance_type;
            if(databaseObj->selectQuery("select * from bunk_master where bunk_master.id_bunk_master='"+QString::number(i+1)+"'",bunk_qur))
            {
                if(bunk_qur.next())
                {
                    bunk_op_balance = bunk_qur.value(3).toString();
                    bunk_op_balance_type = bunk_qur.value(4).toString();


                    if(bunk_op_balance_type.toInt() == 0 || bunk_op_balance_type.toInt() == 2)
                    {
                        if(ui->lineEdit_bill_value->text().toFloat() > bunk_op_balance.toFloat())
                        {
                            float total = ui->lineEdit_bill_value->text().toFloat() - bunk_op_balance.toFloat();
                            if(databaseObj->executeCommand("update bunk_master set bunk_opening_balance='"+QString::number(total)+"' , bunk_opening_balance_type='1' where id_bunk_master='"+QString::number(i+1)+"'"))
                            {

                            }
                        }
                        else if(ui->lineEdit_bill_value->text().toFloat() <= bunk_op_balance.toFloat())
                        {
                            float total = bunk_op_balance.toFloat() - ui->lineEdit_bill_value->text().toFloat();
                            if(databaseObj->executeCommand("update bunk_master set bunk_opening_balance='"+QString::number(total)+"' , bunk_opening_balance_type='0' where id_bunk_master='"+QString::number(i+1)+"'"))
                            {

                            }
                        }
                    }
                    if(bunk_op_balance_type.toInt() == 1)
                    {
                        float total = ui->lineEdit_bill_value->text().toFloat() + bunk_op_balance.toFloat();
                        if(databaseObj->executeCommand("update bunk_master set bunk_opening_balance='"+QString::number(total)+"' , bunk_opening_balance_type='1' where id_bunk_master='"+QString::number(i+1)+"'"))
                        {

                        }
                    }
                }
            }
            databaseObj->con.commit();


            if(databaseObj->executeCommand("insert into diesel_transaction (bunk_id,quantity,amount,day_no,user_id,is_payment,opening_balance,opening_balance_type,closing_balance,closing_balance_type) values ('"+QString::number(i+1)+"','"+ui->lineEdit_today_parchase->text()+"','"+ui->lineEdit_bill_value->text().trimmed()+"','"+gstrday_no+"','"+gstrUserName+"','0','"+bunk_op_balance+"','"+bunk_op_balance_type+"',(select bunk_master.bunk_opening_balance from bunk_master where bunk_master.id_bunk_master='"+QString::number(i+1)+"'),(select bunk_master.bunk_opening_balance_type from bunk_master where bunk_master.id_bunk_master='"+QString::number(i+1)+"'))"))
            {
                qDebug()<<"test 5===>>>";
                if(databaseObj->executeCommand("update configuration_master set init_diesel_reading=(select configuration_master.init_diesel_reading from configuration_master limit 1)+"+ui->lineEdit_today_parchase->text().trimmed()))
                {
//                    update_user_cash(ui->lineEdit_bill_value->text().trimmed(),"-",gstrUserName);
                    qDebug()<<"diesel_transaction saved ===>>>";
#if(NativeCompile)
                QMessageBox gMsg_box;
                QFont gFont;
                gFont.setFamily("DejaVu Sans Mono");
                gFont.setPointSize(12);
                gMsg_box.setFont(gFont);
                gMsg_box.setParent(this);

                if(gMsg_box.information(this, "Success","DieselPurchase\nSaved Successfully..!",QMessageBox::Ok) == QMessageBox::Ok)
                {
                    call_Diesel_Maintanance();
                }
#endif

#if(SDK75)
                int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"DieselPurchase\nSaved Successfully.",16,14);
                call_Diesel_Maintanance();
#endif
                }
            }
        }
    }
}

void Diesel_Maintanance::on_pushButton_save_usage_clicked()
{
    QString diesel_filling;
    if(ui->radioButton_full->isChecked())
        diesel_filling = "1";
    else
        diesel_filling = "0";
    QString usage_type = ui->label_usage_title->text().trimmed();
    if(usage_type.contains("bull",Qt::CaseInsensitive))
    {
        if(databaseObj->executeCommand("insert into diesel_usage (vehicle_no,quantity,fill_type,reading,day_no,user_id) values ('bull','"+ui->lineEdit_input_qty->text().trimmed()+"','"+diesel_filling+"','"+ui->lineEdit_meter_reading->text().trimmed()+"','"+gstrday_no+"','"+gstrUserName+"')"))
        {
            qDebug()<<"diesel_usage bull ===>>>";

            if(databaseObj->executeCommand("update configuration_master set init_diesel_reading=(select configuration_master.init_diesel_reading from configuration_master limit 1)-'"+ui->lineEdit_input_qty->text().trimmed()+"'"))
            {

            }

            call_Diesel_Maintanance();
            show_screen(3);
        }
        return;
    }
    if(usage_type.contains("generator",Qt::CaseInsensitive))
    {
        if(databaseObj->executeCommand("insert into diesel_usage (vehicle_no,quantity,fill_type,reading,day_no,user_id) values ('generator','"+ui->lineEdit_input_qty->text().trimmed()+"','"+diesel_filling+"','"+ui->lineEdit_meter_reading->text().trimmed()+"','"+gstrday_no+"','"+gstrUserName+"')"))
        {
            qDebug()<<"diesel_usage generator ===>>>";
            if(databaseObj->executeCommand("update configuration_master set init_diesel_reading=(select configuration_master.init_diesel_reading from configuration_master limit 1)-'"+ui->lineEdit_input_qty->text().trimmed()+"'"))
            {

            }
            call_Diesel_Maintanance();
            show_screen(3);
        }
        return;
    }
    if(usage_type.contains("Company Vehicle",Qt::CaseInsensitive))
    {
        if(databaseObj->executeCommand("insert into diesel_usage (vehicle_no,quantity,fill_type,reading,day_no,user_id,day_no,user_id) values ('"+ui->comboBox_vehicle_number->currentText().trimmed()+"','"+ui->lineEdit_input_qty->text().trimmed()+"','"+diesel_filling+"','"+ui->lineEdit_meter_reading->text().trimmed()+"','"+gstrday_no+"','"+gstrUserName+"','"+gstrday_no+"','"+gstrUserName+"')"))
        {
            qDebug()<<"diesel_usage company vehicle ===>>>";
            if(databaseObj->executeCommand("update configuration_master set init_diesel_reading=(select configuration_master.init_diesel_reading from configuration_master limit 1)-'"+ui->lineEdit_input_qty->text().trimmed()+"'"))
            {

            }
            call_Diesel_Maintanance();
            show_screen(3);
        }
        return;
    }
}

void Diesel_Maintanance::on_lineEdit_meter_reading_returnPressed()
{
    QString last_bull_meter_reading,last_gen_meter_reading,last_eb_meter_reading,last_deisel_reading,last_husk_per_cft,last_husk_per_bale;
    QSqlQuery reading_qur;
    if(databaseObj->selectQuery("select configuration_master.init_bull_reading,configuration_master.init_gen_reading,configuration_master.init_eb_reading,configuration_master.init_diesel_reading,configuration_master.husk_per_cft,configuration_master.husk_per_bale from configuration_master",reading_qur))
    {
        if(reading_qur.next())
        {
            last_bull_meter_reading = reading_qur.value(0).toString().trimmed();
            last_gen_meter_reading = reading_qur.value(1).toString().trimmed();
            last_eb_meter_reading = reading_qur.value(2).toString().trimmed();
            last_deisel_reading = reading_qur.value(3).toString().trimmed();
            last_husk_per_cft = reading_qur.value(4).toString().trimmed();
            last_husk_per_bale = reading_qur.value(5).toString().trimmed();
        }
        qDebug()<< "last_bull_meter_reading Input_ConfigObj ===>>>"<<last_bull_meter_reading;
        qDebug()<< "last_gen_meter_reading Input_ConfigObj ===>>>"<<last_gen_meter_reading;
        qDebug()<< "last_eb_meter_reading Input_ConfigObj ===>>>"<<last_eb_meter_reading;
        qDebug()<< "last_deisel_reading Input_ConfigObj ===>>>"<<last_deisel_reading;
        qDebug()<< "last_husk_per_cft Input_ConfigObj ===>>>"<<last_husk_per_cft;
        qDebug()<< "last_husk_per_bale Input_ConfigObj ===>>>"<<last_husk_per_bale;
    }
    QString usage_type = ui->label_usage_title->text().trimmed();
    if(usage_type.contains("bull",Qt::CaseInsensitive))
    {
        if(ui->lineEdit_meter_reading->text().toInt() >= last_bull_meter_reading.toInt())
        {
            if(!ui->lineEdit_meter_reading->text().isEmpty())
            {
                ui->pushButton_save_usage->setFocus();
            }
        }
        else
        {
            ui->lineEdit_meter_reading->setFocus();
            ui->lineEdit_meter_reading->selectAll();
            return;
        }
    }
    if(usage_type.contains("generator",Qt::CaseInsensitive))
    {
        if(ui->lineEdit_meter_reading->text().toInt() >= last_gen_meter_reading.toInt())
        {
            if(!ui->lineEdit_meter_reading->text().isEmpty())
            {
                ui->pushButton_save_usage->setFocus();
            }
        }
        else
        {
            ui->lineEdit_meter_reading->setFocus();
            ui->lineEdit_meter_reading->selectAll();
            return;
        }
    }
    if(usage_type.contains("Company Vehicle",Qt::CaseInsensitive))
    {
        QSqlQuery diesel_qur;
        if(databaseObj->selectQuery("select vehicle_registration.odometer_reading from vehicle_registration where vehicle_registration.vehicle_no='"+ui->comboBox_vehicle_number->currentText().trimmed()+"'",diesel_qur))
        {
            if(diesel_qur.next())
            {
                int odo = diesel_qur.value(0).toInt();
                qDebug()<<"odo ===>>>"<<QString::number(odo);
                if(ui->lineEdit_meter_reading->text().toInt() >= odo)
                {
                    if(!ui->lineEdit_meter_reading->text().isEmpty())
                    {
                        ui->pushButton_save_usage->setFocus();
                    }
                }
                else
                {
                    ui->lineEdit_meter_reading->setFocus();
                    ui->lineEdit_meter_reading->selectAll();
                    return;
                }
            }
        }
    }
}

void Diesel_Maintanance::on_lineEdit_today_parchase_textChanged(const QString &arg1)
{
    ui->label_closing_stock->clear();
}
