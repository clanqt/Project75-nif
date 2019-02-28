#include "batch_close.h"
#include "ui_batch_close.h"

#include <global.h>
#include <QMessageBox>

using namespace Global;

Batch_Close::Batch_Close(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Batch_Close)
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

Batch_Close::~Batch_Close()
{
    delete ui;
}

void Batch_Close::call_Batch_Close()
{
    this->show();
    ui->lineEdit_manuf_bale->clear();
    ui->label_batch_close_title->clear();
    ui->label_diff_bale->clear();
    ui->label_est_bale->clear();
    ui->label_exsess_husk->clear();
    ui->label_total_husk->clear();
    ui->label_used_husk->clear();

    ui->lineEdit_bull_reading->clear();
    ui->lineEdit_eb_reading->clear();
    ui->lineEdit_generator_reading->clear();
    ui->lineEdit_manuf_bale->clear();
    ui->lineEdit_odo_reading->clear();
    ui->lineEdit_vehicle_no->clear();

    ui->groupBox_closing_readings->hide();
    ui->groupBox_odo->hide();

    QSqlQuery reading_qur;
    if(databaseObj->selectQuery("select configuration_master.init_bull_reading,configuration_master.init_gen_reading,configuration_master.init_eb_reading,configuration_master.init_diesel_reading,configuration_master.husk_per_cft,configuration_master.husk_per_bale from configuration_master",reading_qur))
    {
        if(reading_qur.next())
        {
            last_bull_meter_reading = reading_qur.value(0).toString().trimmed();
            last_gen_meter_reading = reading_qur.value(1).toString().trimmed();
            last_eb_meter_reading = reading_qur.value(2).toString().trimmed();
        }
        qDebug()<< "last_bull_meter_reading ===>>>"<<last_bull_meter_reading;
        qDebug()<< "last_gen_meter_reading ===>>>"<<last_gen_meter_reading;
        qDebug()<< "last_eb_meter_reading ===>>>"<<last_eb_meter_reading;
    }

    ui->pushButton_goto_odo_reading->setEnabled(false);
    //    ui->pushButton_close_odo->setEnabled(false);

    ui->groupBox_closing_readings->move(0,0);
    ui->groupBox_odo->move(0,0);

    ui->groupBox->show();
    ui->groupBox->raise();

    //    ui->comboBox_vehicle_no->installEventFilter(this);


    //    if(from_batch_config)
    //    {
    //        goto LOOP;
    //    }


    lst_production_batch_close_name.clear();
    lst_production_batch_close_no.clear();
    lst_production_batch_close_husk.clear();

    produced_bale_available = Day_CloseObj->bale_produced.toFloat();

    QSqlQuery batch_close_query;
    if(databaseObj->selectQuery("select * from production_batch_order where CAST(batch_status AS INTEGER)==0",batch_close_query))
    {
        if(batch_close_query.next())
        {
            lst_production_batch_close_name << batch_close_query.value(1).toString().trimmed();
            lst_production_batch_close_no << batch_close_query.value(2).toString().trimmed();
            lst_production_batch_close_husk << batch_close_query.value(3).toString().trimmed();

            while(batch_close_query.next())
            {
                lst_production_batch_close_name << batch_close_query.value(1).toString().trimmed();
                lst_production_batch_close_no << batch_close_query.value(2).toString().trimmed();
                lst_production_batch_close_husk << batch_close_query.value(3).toString().trimmed();
            }

            qDebug()<<"lst_production_batch_close_name ===>>>"<<lst_production_batch_close_name;
            qDebug()<<"lst_production_batch_close_no ===>>>"<<lst_production_batch_close_no;
            qDebug()<<"lst_production_batch_close_husk ===>>>"<<lst_production_batch_close_husk;
        }
    }

    if(lst_production_batch_close_name.size() > 0)
    {
        QSqlQuery previous_produced;

        lst_produced_bale.clear();
        for(int i=0;i<lst_production_batch_close_name.size();i++)
        {
            ui->lineEdit_manuf_bale->clear();
            ui->label_batch_close_title->clear();
            ui->label_diff_bale->clear();
            ui->label_est_bale->clear();
            ui->label_exsess_husk->clear();
            ui->label_total_husk->clear();
            ui->label_used_husk->clear();
            if(databaseObj->selectQuery("select sum(bale_produced) from day_close where batch_type='"+lst_production_batch_close_name.at(i)+"' and batch_no='"+lst_production_batch_close_no.at(i)+"'",previous_produced))
            {
                lst_produced_bale.clear();

                Day_CloseObj->batch_no = lst_production_batch_close_no.at(i);
                Day_CloseObj->batch_type = lst_production_batch_close_name.at(i);
                Day_CloseObj->husk_available = lst_production_batch_close_husk.at(i);

                qDebug()<<"batch_type ===>>>"<<Day_CloseObj->batch_type;
                qDebug()<<"batch_no ===>>>"<<Day_CloseObj->batch_no;
                qDebug()<<"husk_available ===>>>"<<Day_CloseObj->husk_available;



                if(lst_production_batch_close_name.at(i).contains("company",Qt::CaseInsensitive))
                    Day_CloseObj->company_or_other = 0;
                if(lst_production_batch_close_name.at(i).contains("auto",Qt::CaseInsensitive))
                    Day_CloseObj->company_or_other = 1;
                if(lst_production_batch_close_name.at(i).contains("van",Qt::CaseInsensitive))
                    Day_CloseObj->company_or_other = 2;

                QString batch_type,inward_to,batch_number,stock;
                QString msg_text;
                if(Day_CloseObj->company_or_other == 0)
                {
                    ui->label_batch_close_title->setText("Close Company Batch: "+Day_CloseObj->batch_no);
                    batch_type = "0";
                    batch_number = Day_CloseObj->batch_no;
                    inward_to = "company_batch_no";
                    msg_text = "Enter Bale Produced\nCompany Batch: "+Day_CloseObj->batch_no;
                }
                if(Day_CloseObj->company_or_other == 1)
                {
                    ui->label_batch_close_title->setText("Close Auto Batch: "+Day_CloseObj->batch_no);
                    batch_number = Day_CloseObj->batch_no;
                    inward_to = "other_batch_no";
                    msg_text = "Enter Bale Produced\nAuto Batch: "+Day_CloseObj->batch_no;
                }
                if(Day_CloseObj->company_or_other == 2)
                {
                    ui->label_batch_close_title->setText("Close Van Batch: "+Day_CloseObj->batch_no);
                    batch_number = Day_CloseObj->batch_no;
                    inward_to = "van_batch_no";
                    msg_text = "Enter Bale Produced\nVan Batch: "+Day_CloseObj->batch_no;
                }

                QSqlQuery qur;
                if(databaseObj->selectQuery("select inward_stock from "+inward_to+" where batch_no='"+batch_number+"' and status='0'",qur))
                {
                    if(qur.next())
                    {

                        stock = qur.value(0).toString().trimmed();
                    }
                }

                total_husk = QString::number(stock.toFloat() * Home_ScreenObj->HP_cft.toFloat(),'f',2);
                est_husk = QString::number(total_husk.toFloat() / Home_ScreenObj->HP_bale.toFloat(),'f',2);

                ui->label_total_husk->setText(total_husk);
                ui->label_est_bale->setText(est_husk);

                qDebug()<<"total_husk ===>>>"<<total_husk;
                qDebug()<<"est_husk ===>>>"<<est_husk;
                if(!ui->groupBox_closing_readings->isVisible())
                    ui->lineEdit_manuf_bale->setFocus();


                if(previous_produced.next())
                {
                    lst_produced_bale << previous_produced.value(0).toString().trimmed();
                }
                else
                {
                    lst_produced_bale << "0";
                }
                qDebug()<<"lst_produced_bale ===>>>"<<lst_produced_bale;
            }


            ui->label_2->hide();
            ui->label_3->hide();
            ui->label_5->hide();
            ui->label_6->hide();

            ui->label_total_husk->hide();
            ui->label_est_bale->hide();
            ui->label_diff_bale->hide();
            ui->label_used_husk->hide();
            ui->label_exsess_husk->hide();
            ui->label_excess_title->hide();


            ui->groupBox->show();
            ui->groupBox->raise();
            qApp->processEvents();
            qApp->processEvents();

            //! wait for next
            qDebug()<<"QEventLoop before ===>>>";
            QEventLoop loop;
            QObject::connect(this, SIGNAL(goto_next_batch()), &loop, SLOT(quit()));
            loop.exec();

            qDebug()<<"QEventLoop after ===>>>";
        }

        ui->lineEdit_manuf_bale->clear();
        ui->label_batch_close_title->clear();
        ui->label_diff_bale->clear();
        ui->label_est_bale->clear();
        ui->label_exsess_husk->clear();
        ui->label_total_husk->clear();
        ui->label_used_husk->clear();

        batch_close_query.clear();
        lst_production_batch_close_name.clear();
        lst_production_batch_close_no.clear();
        lst_production_batch_close_husk.clear();
        if(databaseObj->selectQuery("select * from production_batch_order where CAST(batch_status AS INTEGER)==2 limit 1",batch_close_query))
        {
            if(batch_close_query.next())
            {
                lst_production_batch_close_name << batch_close_query.value(1).toString().trimmed();
                lst_production_batch_close_no << batch_close_query.value(2).toString().trimmed();
                lst_production_batch_close_husk << batch_close_query.value(3).toString().trimmed();

                qDebug()<<"lst_production_batch_close_name ===>>>"<<lst_production_batch_close_name;
                qDebug()<<"lst_production_batch_close_no ===>>>"<<lst_production_batch_close_no;
                qDebug()<<"lst_production_batch_close_husk ===>>>"<<lst_production_batch_close_husk;


                Day_CloseObj->batch_no = lst_production_batch_close_no.at(0);
                Day_CloseObj->batch_type = lst_production_batch_close_name.at(0);
                Day_CloseObj->husk_available = lst_production_batch_close_husk.at(0);

                qDebug()<<"batch_type ===>>>"<<Day_CloseObj->batch_type;
                qDebug()<<"batch_no ===>>>"<<Day_CloseObj->batch_no;
                qDebug()<<"husk_available ===>>>"<<Day_CloseObj->husk_available;



                if(lst_production_batch_close_name.at(0).contains("company",Qt::CaseInsensitive))
                    Day_CloseObj->company_or_other = 0;
                if(lst_production_batch_close_name.at(0).contains("auto",Qt::CaseInsensitive))
                    Day_CloseObj->company_or_other = 1;
                if(lst_production_batch_close_name.at(0).contains("van",Qt::CaseInsensitive))
                    Day_CloseObj->company_or_other = 2;

                QString batch_type,inward_to,batch_number,stock;
                QString msg_text;
                if(Day_CloseObj->company_or_other == 0)
                {
                    ui->label_batch_close_title->setText("Close Company Batch: "+Day_CloseObj->batch_no);
                    batch_type = "0";
                    batch_number = Day_CloseObj->batch_no;
                    inward_to = "company_batch_no";
                    msg_text = "Bale Produced\nCompany Batch: "+Day_CloseObj->batch_no;
                }
                if(Day_CloseObj->company_or_other == 1)
                {
                    ui->label_batch_close_title->setText("Close Auto Batch: "+Day_CloseObj->batch_no);
                    batch_number = Day_CloseObj->batch_no;
                    inward_to = "other_batch_no";
                    msg_text = "Bale Produced\nAuto Batch: "+Day_CloseObj->batch_no;
                }
                if(Day_CloseObj->company_or_other == 2)
                {
                    ui->label_batch_close_title->setText("Close Van Batch: "+Day_CloseObj->batch_no);
                    batch_number = Day_CloseObj->batch_no;
                    inward_to = "van_batch_no";
                    msg_text = "Bale Produced\nVan Batch: "+Day_CloseObj->batch_no;
                }

                int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Critical,msg_text+"\n"+QString::number(produced_bale_available)+" Bales",16,14);
                QString current_batch_bale;
                current_batch_bale = QString::number(produced_bale_available);

//LOOP:                QInputDialog inputDialog;
//                QFont font;
//                font.setFamily("DejaVu Sans Mono");
//                font.setPointSize(14);
//                inputDialog.setInputMode(QInputDialog::TextInput);
//                inputDialog.setTextValue(gstrAppName);
//                inputDialog.setWindowTitle("Input");
//                inputDialog.setLabelText(msg_text);
//                inputDialog.setTextValue(QString::number(produced_bale_available));
//                inputDialog.setFont(font);
//                inputDialog.move(25,50);
//                inputDialog.setWindowFlags(Qt::FramelessWindowHint);

//                //            inputDialog.setTextValue(Home_ScreenObj->HP_cft);

//                bool ok;
//                ok = inputDialog.exec();

//                QString current_batch_bale;

//                if(ok && !inputDialog.textValue().isEmpty())
//                {
//                    current_batch_bale = inputDialog.textValue().trimmed();
//                }
//                else
//                {
//                    goto LOOP;
//                    return;
//                }


                QString remaining_husk;
                remaining_husk = QString::number(lst_production_batch_close_husk.at(0).toFloat() - (current_batch_bale.toFloat() * Home_ScreenObj->HP_bale.toFloat()),'f',2);

                if(databaseObj->executeCommand("update production_batch_order set husk_available='"+QString::number(remaining_husk.toFloat(),'f',2)+"'  where batch_no='"+Day_CloseObj->batch_no+"' and batch_type='"+Day_CloseObj->batch_type+"'"))
                {
                    qDebug()<<"production_batch_order last update ===>>>";

                    if(databaseObj->executeCommand("insert into day_close (batch_type,batch_no,bale_produced,batch_status,bale_dispatched,bale_dispatched_to,closing_balance,day_no) values ('"+Day_CloseObj->batch_type+"','"+Day_CloseObj->batch_no+"','"+QString::number(produced_bale_available)+"','1','"+Day_CloseObj->bale_dispatched+"','"+Day_CloseObj->dispatched_to+"','"+Day_CloseObj->closing_bale+"','"+gstrday_no+"')"))
                    {
                        qDebug()<<"insert into day_close success ===>>>";
                    }

                    Home_ScreenObj->close_day(this);
                    qApp->processEvents();

                    ui->groupBox->hide();
                    ui->groupBox_closing_readings->show();
                    ui->groupBox_closing_readings->raise();


                    ui->lineEdit_bull_reading->setFocus();
                    qApp->processEvents();

                    return;
                }

            }
            else
                Home_ScreenObj->close_day(this);
        }
        else
            Home_ScreenObj->close_day(this);

        ui->groupBox->hide();
        ui->groupBox_closing_readings->show();
        ui->groupBox_closing_readings->raise();


        ui->lineEdit_bull_reading->setFocus();
        qApp->processEvents();

        return;
    }
    if(lst_production_batch_close_name.size() == 0)
    {


        ui->lineEdit_manuf_bale->clear();
        ui->label_batch_close_title->clear();
        ui->label_diff_bale->clear();
        ui->label_est_bale->clear();
        ui->label_exsess_husk->clear();
        ui->label_total_husk->clear();
        ui->label_used_husk->clear();


        batch_close_query.clear();
        if(databaseObj->selectQuery("select * from production_batch_order where CAST(batch_status AS INTEGER)==2 limit 1",batch_close_query))
        {
            if(batch_close_query.next())
            {
                lst_production_batch_close_name << batch_close_query.value(1).toString().trimmed();
                lst_production_batch_close_no << batch_close_query.value(2).toString().trimmed();
                lst_production_batch_close_husk << batch_close_query.value(3).toString().trimmed();

                qDebug()<<"lst_production_batch_close_name ===>>>"<<lst_production_batch_close_name;
                qDebug()<<"lst_production_batch_close_no ===>>>"<<lst_production_batch_close_no;
                qDebug()<<"lst_production_batch_close_husk ===>>>"<<lst_production_batch_close_husk;


                Day_CloseObj->batch_no = lst_production_batch_close_no.at(0);
                Day_CloseObj->batch_type = lst_production_batch_close_name.at(0);
                Day_CloseObj->husk_available = lst_production_batch_close_husk.at(0);

                qDebug()<<"batch_type ===>>>"<<Day_CloseObj->batch_type;
                qDebug()<<"batch_no ===>>>"<<Day_CloseObj->batch_no;
                qDebug()<<"husk_available ===>>>"<<Day_CloseObj->husk_available;



                if(lst_production_batch_close_name.at(0).contains("company",Qt::CaseInsensitive))
                    Day_CloseObj->company_or_other = 0;
                if(lst_production_batch_close_name.at(0).contains("auto",Qt::CaseInsensitive))
                    Day_CloseObj->company_or_other = 1;
                if(lst_production_batch_close_name.at(0).contains("van",Qt::CaseInsensitive))
                    Day_CloseObj->company_or_other = 2;

                QString remaining_husk;

                remaining_husk = QString::number(lst_production_batch_close_husk.at(0).toFloat() - (Day_CloseObj->bale_produced.toFloat()*Home_ScreenObj->HP_bale.toFloat()),'f',2);

                if(databaseObj->executeCommand("update production_batch_order set husk_available='"+QString::number(remaining_husk.toFloat(),'f',2)+"'  where batch_no='"+Day_CloseObj->batch_no+"' and batch_type='"+Day_CloseObj->batch_type+"'"))
                {
                    qDebug()<<"production_batch_order last update ===>>>";

                    if(databaseObj->executeCommand("insert into day_close (batch_type,batch_no,bale_produced,batch_status,bale_dispatched,bale_dispatched_to,closing_balance,day_no) values ('"+Day_CloseObj->batch_type+"','"+Day_CloseObj->batch_no+"','"+Day_CloseObj->bale_produced+"','1','"+Day_CloseObj->bale_dispatched+"','"+Day_CloseObj->dispatched_to+"','"+Day_CloseObj->closing_bale+"','"+gstrday_no+"')"))
                    {
                        qDebug()<<"insert into day_close success ===>>>";
                    }

                    Home_ScreenObj->close_day(this);
                    qApp->processEvents();

                    ui->groupBox->hide();
                    ui->groupBox_closing_readings->show();
                    ui->groupBox_closing_readings->raise();


                    ui->lineEdit_bull_reading->setFocus();
                    qApp->processEvents();

                }


            }
            else
            {
                Home_ScreenObj->close_day(this);
                qApp->processEvents();

                ui->groupBox->hide();
                ui->groupBox_closing_readings->show();
                ui->groupBox_closing_readings->raise();


                ui->lineEdit_bull_reading->setFocus();
                qApp->processEvents();
            }
        }

        ui->groupBox->hide();
        ui->groupBox_closing_readings->show();
        ui->groupBox_closing_readings->raise();

        ui->lineEdit_bull_reading->setFocus();
        qApp->processEvents();

        return;
    }

    {

        //    if(!Day_CloseObj->lst_batch_no.isEmpty())
        //    {
        //        qDebug()<<"Day_Close test 5 ===>>>"<<Day_CloseObj->bale_produced<<Day_CloseObj->bale_dispatched<<Day_CloseObj->lst_husk_to_bale.at(0);



        //        if(Day_CloseObj->bale_produced.toFloat() >= Day_CloseObj->lst_husk_to_bale.at(0).toFloat())
        //        {
        //            qDebug()<<"Day_Close test 6 ===>>>";
        //            qDebug()<<"Day_CloseObj->lst_husk_to_bale ===>>>"<<Day_CloseObj->lst_husk_to_bale;


        //            remaining_bale = QString::number(Day_CloseObj->bale_produced.toFloat() - Day_CloseObj->lst_husk_to_bale.at(0).toFloat(),'f',2);
        //            produced_bale_this = Day_CloseObj->lst_husk_to_bale.at(0);


        //            qDebug()<<"Day_CloseObj->bale_produced ===>>>"<<Day_CloseObj->bale_produced;
        //            //! current batch need to closed

        //            Day_CloseObj->batch_no = Day_CloseObj->lst_batch_no.at(0);
        //            Day_CloseObj->batch_type = Day_CloseObj->lst_batch_type.at(0);
        //            Day_CloseObj->husk_available = Day_CloseObj->lst_husk_to_bale.at(0);

        //            qDebug()<<"batch_type ===>>>"<<Day_CloseObj->batch_type;
        //            qDebug()<<"batch_no ===>>>"<<Day_CloseObj->batch_no;
        //            qDebug()<<"husk_available ===>>>"<<Day_CloseObj->husk_available;

        //            if(Day_CloseObj->lst_batch_type.at(0).contains("company",Qt::CaseInsensitive))
        //                Day_CloseObj->company_or_other = 0;
        //            if(Day_CloseObj->lst_batch_type.at(0).contains("auto",Qt::CaseInsensitive))
        //                Day_CloseObj->company_or_other = 1;
        //            if(Day_CloseObj->lst_batch_type.at(0).contains("van",Qt::CaseInsensitive))
        //                Day_CloseObj->company_or_other = 2;

        //            //            ui->lineEdit_manuf_bale->setFocus();
        //            //            return;

        //            //            this->hide();
        //            //            Batch_CloseObj->call_Batch_Close();
        //            //            Batch_CloseObj->show();

        //            qDebug()<<"after call ===>>>";
        //        }
        //        else if(Day_CloseObj->bale_produced.toFloat() <= Day_CloseObj->lst_husk_to_bale.at(0).toFloat())
        //        {

        //            qDebug()<<"Day_Close test 7 ===>>>";
        //            qDebug()<<"Day_CloseObj->lst_husk_to_bale ===>>>"<<Day_CloseObj->lst_husk_to_bale;
        //            remaining_bale = QString::number(Day_CloseObj->lst_husk_to_bale.at(0).toFloat() - Day_CloseObj->bale_produced.toFloat(),'f',2);
        //            produced_bale_this = Day_CloseObj->bale_produced.toFloat();

        //            qDebug()<<"remaining_bale produced_bale_this ===>>>"<<remaining_bale,produced_bale_this;

        //            Day_CloseObj->batch_no = Day_CloseObj->lst_batch_no.at(0);
        //            Day_CloseObj->batch_type = Day_CloseObj->lst_batch_type.at(0);
        //            Day_CloseObj->husk_available = Day_CloseObj->lst_husk_to_bale.at(0);

        //            qDebug()<<"batch_type ===>>>"<<Day_CloseObj->batch_type;
        //            qDebug()<<"batch_no ===>>>"<<Day_CloseObj->batch_no;
        //            qDebug()<<"husk_available ===>>>"<<Day_CloseObj->husk_available;

        //            if(Day_CloseObj->lst_batch_type.at(0).contains("company",Qt::CaseInsensitive))
        //                Day_CloseObj->company_or_other = 0;
        //            if(Day_CloseObj->lst_batch_type.at(0).contains("auto",Qt::CaseInsensitive))
        //                Day_CloseObj->company_or_other = 1;
        //            if(Day_CloseObj->lst_batch_type.at(0).contains("van",Qt::CaseInsensitive))
        //                Day_CloseObj->company_or_other = 2;

        ////            if(databaseObj->executeCommand("update production_batch_order set husk_available=(select husk_available from production_batch_order where batch_no='"+Day_CloseObj->batch_no+"' and batch_type='"+Day_CloseObj->batch_type+"')-"+QString::number(produced_bale_this.toFloat()*Home_ScreenObj->HP_bale.toFloat(),'f',2)+" where batch_no='"+Day_CloseObj->batch_no+"' and batch_type='"+Day_CloseObj->batch_type+"'"))

        //            if(databaseObj->executeCommand("update production_batch_order set husk_available='"+QString::number(remaining_bale.toFloat()*Home_ScreenObj->HP_bale.toFloat(),'f',2)+"'  where batch_no='"+Day_CloseObj->batch_no+"' and batch_type='"+Day_CloseObj->batch_type+"'"))
        //            {
        //                qDebug()<<"production_batch_order last update ===>>>";

        //                if(databaseObj->executeCommand("insert into day_close (batch_type,batch_no,bale_produced,batch_status,bale_dispatched,bale_dispatched_to,closing_balance,day_no) values ('"+Day_CloseObj->batch_type+"','"+Day_CloseObj->batch_no+"','"+Day_CloseObj->bale_produced+"','1','"+Day_CloseObj->bale_dispatched+"','"+Day_CloseObj->dispatched_to+"','"+Day_CloseObj->closing_bale+"','"+gstrday_no+"')"))
        //                {
        //                    qDebug()<<"insert into day_close success ===>>>";
        //                }

        //                Home_ScreenObj->close_day(this);
        //                qApp->processEvents();

        //                ui->groupBox->hide();
        //                ui->groupBox_closing_readings->show();
        //                ui->groupBox_closing_readings->raise();


        //                ui->lineEdit_bull_reading->setFocus();
        //                qApp->processEvents();



        //                //                this->close();
        //                //                menuObj->call_menu();
        //                //                menuObj->show();
        //            }

        //        }
        //        else
        //        {

        //        }
        //    }
        //    else
        //    {
        //        this->close();
        //        menuObj->call_menu();
        //        menuObj->show();
        //    }



        //    QString batch_type,inward_to,batch_number,stock;
        //    if(Day_CloseObj->company_or_other == 0)
        //    {
        //        ui->label_batch_close_title->setText("Close Company Batch: "+Day_CloseObj->batch_no);
        //        batch_type = "0";
        //        batch_number = Day_CloseObj->batch_no;
        //        inward_to = "company_batch_no";
        //    }
        //    if(Day_CloseObj->company_or_other == 1)
        //    {
        //        ui->label_batch_close_title->setText("Close Auto Batch: "+Day_CloseObj->batch_no);
        //        batch_number = Day_CloseObj->batch_no;
        //        inward_to = "other_batch_no";
        //    }
        //    if(Day_CloseObj->company_or_other == 2)
        //    {
        //        ui->label_batch_close_title->setText("Close Van Batch: "+Day_CloseObj->batch_no);
        //        batch_number = Day_CloseObj->batch_no;
        //        inward_to = "van_batch_no";
        //    }

        //    QSqlQuery qur;
        //    if(databaseObj->selectQuery("select inward_stock from "+inward_to+" where batch_no='"+batch_number+"' and status='0'",qur))
        //    {
        //        if(qur.next())
        //        {

        //            stock = qur.value(0).toString().trimmed();
        //        }
        //    }

        //    total_husk = QString::number(stock.toFloat() * Home_ScreenObj->HP_cft.toFloat(),'f',2);
        //    est_husk = QString::number(total_husk.toFloat() / Home_ScreenObj->HP_bale.toFloat(),'f',2);

        //    ui->label_total_husk->setText(total_husk);
        //    ui->label_est_bale->setText(est_husk);

        //    qDebug()<<"total_husk ===>>>"<<total_husk;
        //    qDebug()<<"est_husk ===>>>"<<est_husk;
        //    if(!ui->groupBox_closing_readings->isVisible())
        //        ui->lineEdit_manuf_bale->setFocus();
    }
}

void Batch_Close::set_focus()
{
    ui->lineEdit_bull_reading->setFocus();
}

void Batch_Close::on_lineEdit_manuf_bale_returnPressed()
{
    QString last_manuf;

    if(ui->lineEdit_manuf_bale->text().toFloat() > Day_CloseObj->bale_produced.toFloat())
    {
        int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Error,"Enter Vaild\nBale Count.",16,14);
        ui->lineEdit_manuf_bale->selectAll();
        ui->lineEdit_manuf_bale->setFocus();
        return;
    }

    if(!ui->lineEdit_manuf_bale->text().isEmpty())
    {
        last_manuf = QString::number(lst_produced_bale.at(0).toFloat()+ui->lineEdit_manuf_bale->text().trimmed().toFloat(),'f',2);
        manuf_bale = last_manuf;//ui->lineEdit_manuf_bale->text().trimmed();

        diff_bale = QString::number(est_husk.toFloat() - manuf_bale.toFloat(),'f',2);
        ui->label_diff_bale->setText(diff_bale);

        used_husk = QString::number(manuf_bale.toFloat() * Home_ScreenObj->HP_bale.toFloat(),'f',2);
        ui->label_used_husk->setText(used_husk);

        qDebug()<<"manuf_bale ===>>>"<<manuf_bale;
        qDebug()<<"diff_bale ===>>>"<<diff_bale;
        qDebug()<<"used_husk ===>>>"<<used_husk;


        if(diff_bale.toFloat() >= 0)
        {
            excess_husk = QString::number(total_husk.toFloat() - used_husk.toFloat(),'f',2);
            ui->label_exsess_husk->setText(excess_husk);
            ui->label_excess_title->setText("Balance Husk:");
            qDebug()<<"Balance Husk ===>>>"<<excess_husk;
        }
        if(diff_bale.toFloat() <= 0)
        {
            excess_husk = QString::number(used_husk.toFloat() - total_husk.toFloat(),'f',2);
            ui->label_exsess_husk->setText(excess_husk);
            ui->label_excess_title->setText("Excess Husk:");
            qDebug()<<"excess_husk ===>>>"<<excess_husk;
        }


        ui->pushButton_close->setFocus();
    }
}

void Batch_Close::on_pushButton_close_clicked()
{

    if(ui->lineEdit_manuf_bale->text().toFloat() > Day_CloseObj->bale_produced.toFloat())
    {
        int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Error,"Enter Vaild\nBale Count.",16,14);
        ui->lineEdit_manuf_bale->selectAll();
        ui->lineEdit_manuf_bale->setFocus();
        return;
    }


    QString batch_type,inward_to,batch_number,stock;
    if(Day_CloseObj->company_or_other == 0)
    {
        inward_to = "company_batch_no";
    }
    if(Day_CloseObj->company_or_other == 1)
    {
        inward_to = "other_batch_no";
    }
    if(Day_CloseObj->company_or_other == 2)
    {
        inward_to = "van_batch_no";
    }

    qDebug()<<"produced_bale_available before ===>>>"<<QString::number(produced_bale_available);
    produced_bale_available -= ui->lineEdit_manuf_bale->text().trimmed().toFloat();
    qDebug()<<"produced_bale_available after ===>>>"<<QString::number(produced_bale_available);

    if(databaseObj->executeCommand("update "+inward_to+" set production_day_no_close='"+gstrday_no+"', production_status='0' where batch_no='"+Day_CloseObj->batch_no+"'"))
    {
        qDebug()<<"production_day_no_close update success ===>>>";
        if(databaseObj->executeCommand("delete from production_batch_order where rowid=(select rowid from production_batch_order limit 1)"))
        {

            if(databaseObj->executeCommand("insert into day_close (batch_type,batch_no,bale_produced,batch_status,bale_dispatched,bale_dispatched_to,closing_balance,day_no) values ('"+Day_CloseObj->batch_type+"','"+Day_CloseObj->batch_no+"','"+ui->lineEdit_manuf_bale->text().trimmed()+"','0','"+Day_CloseObj->bale_dispatched+"','"+Day_CloseObj->dispatched_to+"','"+Day_CloseObj->closing_bale+"','"+gstrday_no+"')"))
            {
                qDebug()<<"insert into day_close success ===>>>";
                if(databaseObj->executeCommand("update "+inward_to+" set manu_bale='"+manuf_bale+"',diff_bale='"+diff_bale+"',used_husk='"+used_husk+"',excess_husk='"+excess_husk+"',est_bale='"+est_husk+"' where batch_no='"+Day_CloseObj->batch_no+"'"))
                {
                    qDebug()<<"update into "<< inward_to << "success ===>>>";
                }
            }

            qDebug()<<"delete production_batch_order rowid 1 success ===>>>";
            //            if(!from_batch_config)
            {
                //                Day_CloseObj->lst_batch_no.removeFirst();
                //                Day_CloseObj->lst_batch_type.removeFirst();
                //                Day_CloseObj->lst_husk_to_bale.removeFirst();
                //                Day_CloseObj->lst_husk_available.removeFirst();


                //                if(Day_CloseObj->lst_batch_no.isEmpty())
                //                {
                //                    qApp->processEvents();

                //                    ui->groupBox->hide();
                //                    ui->groupBox_closing_readings->show();
                //                    ui->groupBox_closing_readings->raise();


                //                    ui->lineEdit_bull_reading->setFocus();
                //                    qApp->processEvents();
                //                    return;
                //                }

                //                Day_CloseObj->bale_produced = remaining_bale;
                //                call_Batch_Close();

                emit goto_next_batch();
                return;
            }
            //            if(from_batch_config)
            //            {
            //                this->close();
            //                from_batch_config = false;
            //                Batch_ConfigurationObj->call_Batch_Configuration();
            //                Batch_ConfigurationObj->show();

            //            }
        }
    }



    //    if(Batch_ConfigurationObj->company_or_other == 0)
    //    {
    //        if(Home_ScreenObj->close_shift(this))
    //        {
    //            this->close();
    //            menuObj->call_menu();
    //            menuObj->show();
    //            return;
    //        }
    //        ui->pushButton_close->setFocus();
    //    }
    //    if(Batch_ConfigurationObj->company_or_other == 1)
    //    {

    //        if(Home_ScreenObj->close_shift_other(this))
    //        {
    //            this->close();
    //            menuObj->call_menu();
    //            menuObj->show();
    //            return;
    //        }
    //        ui->pushButton_close->setFocus();
    //    }
    //    if(Batch_ConfigurationObj->company_or_other == 2)
    //    {

    //        if(Home_ScreenObj->close_shift_van(this))
    //        {
    //            this->close();
    //            menuObj->call_menu();
    //            menuObj->show();
    //            return;
    //        }
    //        ui->pushButton_close->setFocus();
    //    }
}

void Batch_Close::keyPressEvent(QKeyEvent *ke)
{
    if(ke->key()== Qt::Key_Escape)
    {
        if(ui->groupBox_odo->isVisible())
        {
//            ui->groupBox->hide();
//            ui->groupBox_odo->hide();

//            ui->groupBox_closing_readings->show();
//            ui->groupBox_closing_readings->raise();

//            ui->lineEdit_bull_reading->setFocus();
            return;
        }
        if(ui->groupBox_closing_readings->isVisible())
        {
            return;
        }
        this->close();
        Day_CloseObj->call_Day_Close();
        Day_CloseObj->show();
    }
    if(ke->key()== Qt::Key_F1)
    {
        on_pushButton_close_odo_clicked();
    }
}

void Batch_Close::on_lineEdit_bull_reading_returnPressed()
{
    if(ui->lineEdit_bull_reading->text().toFloat() >= last_bull_meter_reading.toFloat())
    {

    }
    else
    {
        ui->lineEdit_bull_reading->selectAll();
        ui->lineEdit_bull_reading->setFocus();
        return;
    }
    if(!ui->lineEdit_bull_reading->text().isEmpty() && ui->lineEdit_bull_reading->text().toFloat() > 0 && ui->lineEdit_bull_reading->text().toFloat() >= last_bull_meter_reading.toFloat())
    {
        ui->lineEdit_generator_reading->setFocus();
    }
}

void Batch_Close::on_lineEdit_generator_reading_returnPressed()
{

    if(ui->lineEdit_generator_reading->text().toFloat() >= last_gen_meter_reading.toFloat())
    {

    }
    else
    {
        ui->lineEdit_generator_reading->selectAll();
        ui->lineEdit_generator_reading->setFocus();
        return;
    }

    if(!ui->lineEdit_generator_reading->text().isEmpty() && ui->lineEdit_generator_reading->text().toFloat() > 0  && ui->lineEdit_generator_reading->text().toFloat() >= last_gen_meter_reading.toFloat())
    {
        ui->lineEdit_eb_reading->setFocus();
    }
}

void Batch_Close::on_lineEdit_eb_reading_returnPressed()
{
    if(ui->lineEdit_eb_reading->text().toFloat() >= last_eb_meter_reading.toFloat())
    {

    }
    else
    {
        ui->lineEdit_eb_reading->selectAll();
        ui->lineEdit_eb_reading->setFocus();
        return;
    }


    if(!ui->lineEdit_eb_reading->text().isEmpty() && ui->lineEdit_eb_reading->text().toFloat() > 0)
    {
        ui->pushButton_goto_odo_reading->setEnabled(true);
        ui->pushButton_goto_odo_reading->setFocus();
    }
}

void Batch_Close::on_pushButton_goto_odo_reading_clicked()
{

    if(databaseObj->executeCommand("update day_master set close_bull_reading='"+ui->lineEdit_bull_reading->text().trimmed()+"',close_gen_reading='"+ui->lineEdit_generator_reading->text().trimmed()+"',close_eb_reading='"+ui->lineEdit_eb_reading->text().trimmed()+"' where rowid=(select max(rowid) from day_master where status='0')"))
    {
        if(databaseObj->executeCommand("update configuration_master set init_bull_reading='"+ui->lineEdit_bull_reading->text().trimmed()+"',init_gen_reading='"+ui->lineEdit_generator_reading->text().trimmed()+"',init_eb_reading='"+ui->lineEdit_eb_reading->text().trimmed()+"'"))
        {

        }
    }

    //    ui->comboBox_vehicle_no->setFocus();


    QSqlQuery query;
    if(databaseObj->selectQuery("select vehicle_no from vehicle_registration where vehicle_owner='0'",query))
    {
        lst_vehicle_no.clear();
        if(query.next())
        {
            lst_vehicle_no << query.value(0).toString().trimmed();
            while(query.next())
            {
                lst_vehicle_no << query.value(0).toString().trimmed();
            }
        }
        qDebug()<<"lst_vehicle_no ===>>>"<<lst_vehicle_no;
        if(lst_vehicle_no.size() > 0)
        {

            ui->groupBox_closing_readings->hide();
            ui->groupBox->hide();

            ui->groupBox_odo->show();
            ui->groupBox_odo->raise();


            for(int i=0;i<lst_vehicle_no.size();i++)
            {

                ui->pushButton_odo_save->setEnabled(false);
                ui->lineEdit_vehicle_no->setText(lst_vehicle_no.at(i));
                ui->lineEdit_vehicle_no->setEnabled(true);

                ui->lineEdit_odo_reading->setFocus();



                qDebug()<<"QEventLoop before ===>>>";
                QEventLoop loop;
                QObject::connect(this, SIGNAL(goto_next_vihecle()), &loop, SLOT(quit()));
                loop.exec();

                qDebug()<<"QEventLoop after ===>>>";
            }

            this->close();
            Salary_CalculationObj->call_Salary_Calculation();
            Salary_CalculationObj->show();


        }
    }

}

void Batch_Close::odo_reading_slot()
{
    ui->pushButton_odo_save->setEnabled(true);
    ui->pushButton_odo_save->setFocus();
}

void Batch_Close::on_lineEdit_odo_reading_returnPressed()
{


    QSqlQuery diesel_qur;
    if(databaseObj->selectQuery("select vehicle_registration.odometer_reading from vehicle_registration where vehicle_registration.vehicle_no='"+ui->lineEdit_odo_reading->text().trimmed()+"'",diesel_qur))
    {
        if(diesel_qur.next())
        {
            if(ui->lineEdit_odo_reading->text().toInt() >= diesel_qur.value(0).toInt())
            {

            }
            else
            {
                ui->lineEdit_odo_reading->setFocus();
                ui->lineEdit_odo_reading->selectAll();
                return;
            }
        }
    }

    if(!ui->lineEdit_vehicle_no->text().isEmpty())
    {
        QSqlQuery diesel_qur;
        if(databaseObj->selectQuery("select vehicle_registration.odometer_reading from vehicle_registration where vehicle_registration.vehicle_no='"+ui->lineEdit_vehicle_no->text().trimmed()+"'",diesel_qur))
        {
            if(diesel_qur.next())
            {
                if(ui->lineEdit_odo_reading->text().toInt() >= diesel_qur.value(0).toInt())
                {
                    ui->pushButton_odo_save->setEnabled(true);
                }
                else
                {
                    ui->pushButton_odo_save->setEnabled(false);
                    ui->lineEdit_odo_reading->setFocus();
                    ui->lineEdit_odo_reading->selectAll();
                    return;
                }
            }
        }

        if(!ui->lineEdit_odo_reading->text().trimmed().isEmpty())
        {
            ui->pushButton_odo_save->setFocus();
        }
    }

    //    if(!ui->lineEdit_odo_reading->text().isEmpty() && ui->lineEdit_odo_reading->text().toFloat() > 0)
    //    {
    //        ui->pushButton_close_odo->setEnabled(true);
    //        ui->pushButton_close_odo->setFocus();
    //    }
}

//bool Batch_Close::eventFilter(QObject *target, QEvent *event)
//{
//    QKeyEvent *key = static_cast <QKeyEvent*> (event);

//    if(target == ui->comboBox_vehicle_no)
//    {
//        if(event->type() == QEvent::KeyPress)
//        {
//            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
//            {
//                if(ui->comboBox_vehicle_no->hasFocus())
//                {
//                    ui->lineEdit_odo_reading->setFocus();
//                    return true;
//                }
//            }
//        }
//    }
//    else
//    {
//        return false;
//    }
//    return false;
//}

void Batch_Close::on_pushButton_close_odo_clicked()
{
    this->close();
    menuObj->call_menu();
    menuObj->show();
}

void Batch_Close::on_pushButton_odo_save_clicked()
{
    if(!ui->lineEdit_vehicle_no->text().trimmed().isEmpty() && !ui->lineEdit_odo_reading->text().trimmed().isEmpty())
    {

        if(databaseObj->executeCommand("update vehicle_registration set odometer_reading='"+ui->lineEdit_odo_reading->text().trimmed()+"' where vehicle_no='"+ui->lineEdit_vehicle_no->text().trimmed()+"'"))
        {
            qDebug()<<"update odometer_reading success for ===>>>"<<ui->lineEdit_vehicle_no->text();
        }

        emit goto_next_vihecle();
    }
}
