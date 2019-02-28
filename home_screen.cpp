#include "home_screen.h"
#include "ui_home_screen.h"

#include <QMessageBox>
#include <math.h>

#include <global.h>
using namespace Global;

Home_Screen::Home_Screen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Home_Screen)
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

Home_Screen::~Home_Screen()
{
    delete ui;
}

void Home_Screen::keyPressEvent(QKeyEvent *ke)
{
    if(ke->key()== Qt::Key_Escape)
    {
        if(!ui->lineEdit_vehicle_number->text().isEmpty())
            call_Home_Screen();
        else
        {
            this->close();
            menuObj->call_menu();
            menuObj->show();
        }
    }

    if(ke->key()== Qt::Key_F1)
    {
        this->close();
        menuObj->call_menu();
        menuObj->show();
    }
    if(ke->key()== Qt::Key_F5)
    {
        int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Information,"Do You Want\nReprint Last\nReceipt?",16,14,"YES","NO");
        if(ret==1)
        {
            QFile inputFile("/home/root/last_print.txt");
            if (inputFile.open(QIODevice::ReadOnly))
            {
               QTextStream in(&inputFile);
               CPrinter print;
               print.setFontType(CPrinter::eFontType_font2);
               print.addData("DUPLICATE COPY",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_CENTER);
               while (!in.atEnd())
               {
                   QString data = in.readLine();
                   if(data.contains("Paid Amount"))
                       print.addData(data,CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                   else if(data.contains("Excess Amt"))
                       print.addData(data,CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                   else if(data.compare("Purchase Receipt",data,Qt::CaseSensitive) == 0)
                       print.addData(data,CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_CENTER);
                   else if(data.compare("Thank You",data,Qt::CaseSensitive) == 0)
                       print.addData(data,CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_CENTER);
                   else
                       print.addData(data,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);


               }
               print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
               print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
               print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
               print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
               if(print.print(true,false))
               {

               }
               inputFile.close();
            }
        }

        ui->lineEdit_vehicle_number->setFocus();
    }
}

void Home_Screen::set_focus()
{
    ui->pushButton_next->setFocus();
}

void Home_Screen::call_Home_Screen()
{
    ui->lineEdit_vehicle_number->clear();
    ui->lineEdit_height->clear();
    ui->lineEdit_customer_name->clear();
    ui->lineEdit_customer_mobile->clear();
    ui->lineEdit_reg_length_inche->clear();
    ui->lineEdit_reg_breadth_inche->clear();
    ui->lineEdit_height_inches->clear();
    ui->lineEdit_count->clear();

    ui->lineEdit_reg_name->clear();
    ui->lineEdit_reg_breadth->clear();
    ui->lineEdit_reg_breadth_inche->clear();
    ui->lineEdit_reg_length->clear();
    ui->lineEdit_reg_length_inche->clear();

    ui->lineEdit_vehicle_number->setValidator(gAmtValidator2);

    ui->label_length->clear();

    ui->label_title_type->hide();
    ui->lineEdit_reg_type->hide();

    //    ui->label_reg_name_title->hide();
    //    ui->lineEdit_reg_name->hide();

    ui->label_title_count->hide();
    ui->lineEdit_count->hide();

    ui->lineEdit_reg_opening_balance->clear();

    ui->radioButton_reg_bal_pending->hide();
    ui->radioButton_reg_bal_advance->hide();
    ui->label_bal_type_title->hide();

    ui->label_mobile_title->hide();
    ui->lineEdit_customer_mobile->hide();




    inward_type = 0;

    lst_customer_name.clear();lst_customer_mobile.clear();lst_vehicle_number.clear();

    selected_cus_name.clear();selected_cus_mobile.clear();selected_cus_balance_type.clear();selected_cus_balance.clear();selected_cus_id.clear();

    selected_vehicle_number.clear();selected_vehicle_name.clear();selected_vehicle_length.clear();selected_vehicle_width.clear();selected_vehicle_height.clear();selected_vehicle_height_inche.clear();

    final_count.clear();total_cft.clear();estimated_amount.clear();

    RP_husk.clear();RP_cft.clear();HP_bale.clear();HP_cft.clear();

    ui->label_title->setText("Customer Selection");



    ui->radioButton_cft->installEventFilter(this);
    ui->radioButton_count->installEventFilter(this);

    ui->radioButton_reg_bal_advance->installEventFilter(this);
    ui->radioButton_reg_bal_pending->installEventFilter(this);

    ui->lineEdit_vehicle_number->installEventFilter(this);
    ui->comboBox_reg_owner->installEventFilter(this);

    ui->lineEdit_bull_reading->installEventFilter(this);
    ui->lineEdit_diesel->installEventFilter(this);
    ui->lineEdit_generator_reading->installEventFilter(this);
    ui->lineEdit_eb_reading->installEventFilter(this);

    ui->lineEdit_customer_name->installEventFilter(this);

    ui->lineEdit_height->installEventFilter(this);
    ui->lineEdit_height_inches->installEventFilter(this);

    ui->pushButton_initial_config_save->setEnabled(false);

    ui->pushButton_initial_config_back->hide();

    ui->groupBox_initial_config->move(0,0);
    ui->groupBox_initial_config->hide();

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

    cmpter = new QCompleter(lst_customer_name,this);
    cmpter->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit_customer_name->setCompleter(cmpter);

    cmpter1 = new QCompleter(lst_customer_mobile,this);
    cmpter1->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit_customer_mobile->setCompleter(cmpter1);


    QSqlQuery broker_details;
    if(databaseObj->selectQuery("select * from customer_master where cus_type='1'",broker_details))
    {
        if(broker_details.next())
        {
            lst_broker_name << broker_details.value(1).toString().trimmed();
            lst_broker_mobile << broker_details.value(2).toString().trimmed();
        }
        while(broker_details.next())
        {
            lst_broker_name << broker_details.value(1).toString().trimmed();
            lst_broker_mobile << broker_details.value(2).toString().trimmed();
        }
    }

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


//    cmpter2 = new QCompleter(lst_vehicle_number,this);
//    cmpter2->setCaseSensitivity(Qt::CaseInsensitive);
//    cmpter2->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
//    ui->lineEdit_vehicle_number->setCompleter(cmpter2);

    cmpter2 = new QCompleter(lst_vehicle_number,this);
    cmpter2->setCaseSensitivity(Qt::CaseInsensitive);
//    cmpter2->setCompletionMode(QCompleter::PopupCompletion);
//    cmpter2->setCompletionRole(Qt::DisplayRole);
    ui->lineEdit_vehicle_number->setCompleter(cmpter2);


    QSqlQuery qur;
    if(databaseObj->selectQuery("select configuration_master.husk_per_cft,configuration_master.rate_of_cft,configuration_master.husk_per_bale,configuration_master.rate_of_husk,configuration_master.auto_rate_of_cft,configuration_master.auto_rate_of_husk,configuration_master.van_rate_of_cft,configuration_master.van_rate_of_husk from configuration_master",qur))
    {
        if(qur.next())
        {
            HP_cft = qur.value(0).toString().trimmed();
            RP_cft = qur.value(1).toString().trimmed();
            HP_bale = qur.value(2).toString().trimmed();
            RP_husk = qur.value(3).toString().trimmed();

            RP_cft_auto = qur.value(4).toString().trimmed();
            RP_husk_auto = qur.value(5).toString().trimmed();

            RP_cft_van = qur.value(6).toString().trimmed();
            RP_husk_van = qur.value(7).toString().trimmed();
        }
    }

    if(gstrUserType.toInt() == 0)
    {
        QStringList lst_vtype;
        lst_vtype << "Auto" << "Van";
        ui->comboBox_reg_owner->clear();
        ui->comboBox_reg_owner->addItems(lst_vtype);
    }
    else
    {
        QStringList lst_vtype;
        lst_vtype << "Company" << "Auto" << "Van";
        ui->comboBox_reg_owner->clear();
        ui->comboBox_reg_owner->addItems(lst_vtype);
    }

    ui->groupBox->show();
    ui->lineEdit_vehicle_number->show();

#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
#endif
    ui->lineEdit_vehicle_number->clear();
    ui->lineEdit_vehicle_number->setFocus();


    qDebug()<<"HP_cft ===>>>"<<HP_cft;
    qDebug()<<"RP_cft ===>>>"<<RP_cft;
    qDebug()<<"HP_bale ===>>>"<<HP_bale;
    qDebug()<<"RP_husk ===>>>"<<RP_husk;

    qDebug()<<"RP_cft_auto ===>>>"<<RP_cft_auto;
    qDebug()<<"RP_husk_auto ===>>>"<<RP_husk_auto;

    qDebug()<<"RP_cft_van ===>>>"<<RP_cft_van;
    qDebug()<<"RP_husk_van ===>>>"<<RP_husk_van;


    //    if(!gstrUserName.contains("mcadmin",Qt::CaseSensitive))
    //    {
    //        if(!isDayOpen())
    //        {
    //            open_day(this);
    //        }
    //        if(!isShiftOpen())
    //        {
    //            open_shift(this);
    //        }
    //        if(!isShiftOpen_other())
    //        {
    //            open_shift_other(this);
    //        }
    //        if(!isShiftOpen_van())
    //        {
    //            open_shift_van(this);
    //        }
    //    }




    ui->gridLayoutWidget->setGeometry(10,50,300,160);
    ui->gridLayoutWidget->hide();
    ui->gridLayoutWidget_2->setGeometry(0,50,320,160);
    ui->gridLayoutWidget_2->hide();

    QSqlQuery is_count;

    if(databaseObj->selectQuery("select is_purchase_count from configuration_master",is_count))
    {
        if(is_count.next())
        {
            if(is_count.value(0).toInt() == 1)
            {
                ui->radioButton_count->show();
            }
            if(is_count.value(0).toInt() == 0)
            {
                ui->radioButton_count->hide();
            }
        }
    }

    if(!isDayOpen())
    {
    }
    if(!isShiftOpen())
    {
    }
    if(!isShiftOpen_other())
    {
    }

    qDebug()<<"gstrday_no ===>>>"<< gstrday_no;
    qDebug()<<"gstrday_open_date ===>>>"<< gstrday_open_date;
    qDebug()<<"gstrday_close_date ===>>>"<< gstrday_close_date;
    qDebug()<<"gstrday_open_time ===>>>"<< gstrday_open_time;
    qDebug()<<"gstrday_close_time ===>>>"<< gstrday_close_time;


    qDebug()<<"gstrshift_no ===>>>"<<gstrshift_no ;
    qDebug()<<"gstrshift_day_number ===>>>"<< gstrshift_day_number;
    qDebug()<<"gstrshift_open_date ===>>>"<<gstrshift_open_date ;
    qDebug()<<"gstrshift_close_date ===>>>"<<gstrshift_close_date ;
    qDebug()<<"gstrshift_open_time ===>>>"<<gstrshift_open_time ;
    qDebug()<<"gstrshift_close_time ===>>>"<<gstrshift_close_time ;


    qDebug()<<"gstrshift_no_other ===>>>"<<gstrshift_no_other;
    qDebug()<<"gstrshift_day_number_other ===>>>"<< gstrshift_day_number_other;
    qDebug()<<"gstrshift_open_date_other ===>>>"<<gstrshift_open_date_other;
    qDebug()<<"gstrshift_close_date_other ===>>>"<<gstrshift_close_date_other ;
    qDebug()<<"gstrshift_open_time_other ===>>>"<<gstrshift_open_time_other ;
    qDebug()<<"gstrshift_close_time_other ===>>>"<<gstrshift_close_time_other ;


}

bool Home_Screen::check_batch()
{
    if(gstrday_no.toInt() >= 1)
    {
        QSqlQuery query;

        QStringList lst_company_batch_no,lst_van_batch_no,lst_auto_batch_no;
        query.clear();
        if(databaseObj->selectQuery("select batch_no from company_batch_no where status='0' and production_status='2'",query))
        {
            if(query.next())
            {
                lst_company_batch_no.clear();
                lst_company_batch_no << query.value(0).toString().trimmed().rightJustified(3,'0').prepend("C");
                while(query.next())
                {
                    lst_company_batch_no << query.value(0).toString().trimmed().rightJustified(3,'0').prepend("C");
                }
            }

        }

        query.clear();
        if(databaseObj->selectQuery("select batch_no from other_batch_no where status='0' and production_status='2'",query))
        {
            if(query.next())
            {
                lst_auto_batch_no.clear();
                lst_auto_batch_no << query.value(0).toString().trimmed().rightJustified(3,'0').prepend("A");
                while(query.next())
                {
                    lst_auto_batch_no << query.value(0).toString().trimmed().rightJustified(3,'0').prepend("A");
                }
            }

        }

        query.clear();
        if(databaseObj->selectQuery("select batch_no from van_batch_no where status='0' and production_status='2'",query))
        {
            if(query.next())
            {
                lst_van_batch_no.clear();
                lst_van_batch_no << query.value(0).toString().trimmed().rightJustified(3,'0').prepend("V");
                while(query.next())
                {
                    lst_van_batch_no << query.value(0).toString().trimmed().rightJustified(3,'0').prepend("V");
                }
            }

        }

        if(lst_company_batch_no.size() == 0 && lst_auto_batch_no.size() == 0 && lst_van_batch_no.size() ==0 )
        {
#if(NativeCompile)
            QMessageBox gMsg_box;
            QFont gFont;
            gFont.setFamily("DejaVu Sans Mono");
            gFont.setPointSize(12);
            gMsg_box.setFont(gFont);
            gMsg_box.setParent(this);

            if(gMsg_box.information(this, "Status","Closed Batch\nNot Available..!",QMessageBox::Ok) == QMessageBox::Ok)
            {
                //                ui->pushButton_Production_open->setFocus();
                ui->lineEdit_vehicle_number->clear();
                ui->lineEdit_vehicle_number->setFocus();
            }
            else
            {

            }
#endif

#if(SDK75)
            int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"Closed Batch\nNot Available..!",16,14);
            ui->lineEdit_vehicle_number->clear();

#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
#endif
            ui->lineEdit_vehicle_number->setFocus();
#endif

            //            return;
        }



        QString str_batch_order_name,str_batch_order_no;
        if(databaseObj->selectQuery("select count(*) from production_batch_order",query))
        {
            if(query.next())
            {
                if(query.value(0).toInt() <= 2)
                {
#if(NativeCompile)
                    QMessageBox gMsg_box;
                    QFont gFont;
                    gFont.setFamily("DejaVu Sans Mono");
                    gFont.setPointSize(12);
                    gMsg_box.setFont(gFont);
                    gMsg_box.setParent(this);

                    if(gMsg_box.information(this, "Status","Production Batch\nAvailable is "+query.value(0).toString(),QMessageBox::Ok) == QMessageBox::Ok)
                    {
                        ui->lineEdit_vehicle_number->clear();
                        ui->lineEdit_vehicle_number->setFocus();
                        //                ui->pushButton_Production_close->setFocus();
                        //                return;
                    }
                    else
                    {

                    }
#endif

#if(SDK75)
                    int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"Production Batch\nAvailable is "+query.value(0).toString(),16,14);
                    ui->lineEdit_vehicle_number->clear();
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
#endif
                    ui->lineEdit_vehicle_number->setFocus();
#endif
                }
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

                if(gMsg_box.information(this, "Status","Production Batch\nNot Available..!",QMessageBox::Ok) == QMessageBox::Ok)
                {
                    ui->lineEdit_vehicle_number->clear();
                    ui->lineEdit_vehicle_number->setFocus();
                }
                else
                {

                }
#endif

#if(SDK75)
                int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"Closed Batch\nNot Available..!",16,14);
                ui->lineEdit_vehicle_number->clear();
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
#endif
                ui->lineEdit_vehicle_number->setFocus();
#endif

            }
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

            if(gMsg_box.information(this, "Status","Production Batch\nNot Available..!",QMessageBox::Ok) == QMessageBox::Ok)
            {
                ui->lineEdit_vehicle_number->clear();
                ui->lineEdit_vehicle_number->setFocus();
            }
            else
            {

            }
#endif

#if(SDK75)
            int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"Closed Batch\nNot Available..!",16,14);
            ui->lineEdit_vehicle_number->clear();
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
#endif
            ui->lineEdit_vehicle_number->setFocus();
#endif

        }
    }


    if(isDayOpen())
    {
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
#endif
        ui->lineEdit_vehicle_number->setFocus();
    }


    qDebug()<<"test msg 1 ===>>>";
    QFont gFont;
    gFont.setFamily("DejaVu Sans Mono");

    qDebug()<<"test msg 1 ===>>>";
    QMessageBox gMsg_box1;
    gMsg_box1.setFont(gFont);
    qDebug()<<"test msg 1 ===>>>";

    QSqlQuery query;
    QStringList lst_batch_type,lst_batch_no,lst_husk_available;
    if(databaseObj->selectQuery("select batch_type,batch_no,husk_available from production_batch_order",query))
    {
        if(query.next())
        {
            lst_batch_type << query.value(0).toString().trimmed();
            QString bale = QString::number(query.value(2).toString().trimmed().toFloat()/Home_ScreenObj->HP_bale.toFloat(),'f',2);
            QString cft = QString::number(query.value(2).toString().trimmed().toFloat()/Home_ScreenObj->HP_cft.toFloat(),'f',2);
            lst_batch_no << query.value(1).toString().trimmed().rightJustified(4,'0').prepend(query.value(0).toString().trimmed().toUpper()+" ").append(" = ").append(query.value(2).toString().trimmed().append(" Nos;")).append("CFT: ")+cft.append("; Bale: ").append(bale);
//                    lst_husk_available << query.value(2).toString().trimmed();

            while(query.next())
            {
                lst_batch_type << query.value(0).toString().trimmed();

                QString bale = QString::number(query.value(2).toString().trimmed().toFloat()/Home_ScreenObj->HP_bale.toFloat(),'f',2);
                QString cft = QString::number(query.value(2).toString().trimmed().toFloat()/Home_ScreenObj->HP_cft.toFloat(),'f',2);
                lst_batch_no << query.value(1).toString().trimmed().rightJustified(4,'0').prepend(query.value(0).toString().trimmed().toUpper()+" ").append(" = ").append(query.value(2).toString().trimmed().append(" Nos;")).append("CFT: ")+cft.append("; Bale: ").append(bale);

//                lst_batch_no << query.value(1).toString().trimmed().rightJustified(4,'0').prepend(query.value(0).toString().trimmed().toUpper()+" ").append(" = ").append(query.value(2).toString().trimmed().append(" Nos"));

//                        lst_husk_available <<
            }

            QString msg1,msg2,msg3;
            if(lst_batch_no.size() > 0)
            {
                for(int i=0;i<lst_batch_type.size();i++)
                {
                    if(i == 0)
                        msg1 = lst_batch_no.at(0);
                    if(i == 1)
                        msg2 = lst_batch_no.at(1);
                    if(i == 2)
                        msg3 = lst_batch_no.at(2);
                }
                gMsg_box1.setText("<p>Batch Details.</p><p><font size = 3 color=red >"+msg1+"</font></p><p><font size = 3 color=green >"+msg2+"</font></p><p><font size = 3 color=black >"+msg3+"</font></p>");
                gMsg_box1.setWindowFlags(Qt::FramelessWindowHint);
                gMsg_box1.addButton("Continue",QMessageBox::NoRole);
                gMsg_box1.addButton("Batch Config",QMessageBox::YesRole);

                gMsg_box1.move(10,40);


                int status = gMsg_box1.exec();
                qDebug()<<"status ===>>>"<<QString::number(status);

                if(status == 0)
                {
                    //! Continue
//                    ui->lineEdit_vehicle_number->setFocus();
                    return true;
                }
                else if(status == 1)
                {
                    ui->groupBox->hide();
//                    this->close();
//                    menuObj->hide();
//                    Batch_ConfigurationObj->from_home_screen = true;
//                    Batch_ConfigurationObj->call_Batch_Configuration();
//                    Batch_ConfigurationObj->show();
//                    Batch_ConfigurationObj->on_pushButton_Production_open_clicked();
                    return false;

                }
            }
            return true;
        }
        return true;
    }
    return true;
}

void Home_Screen::day_shift()
{
    if(!gstrUserName.contains("mcadmin",Qt::CaseSensitive))
    {
        if(!isDayOpen())
        {
            open_day(this);
        }
        if(!isShiftOpen())
        {
            open_shift(this);
        }
        if(!isShiftOpen_other())
        {
            open_shift_other(this);
        }
        if(!isShiftOpen_van())
        {
            open_shift_van(this);
        }

        if(!isDayOpen())
        {
        }
        if(!isShiftOpen())
        {
        }
        if(!isShiftOpen_other())
        {
        }
    }
}

bool Home_Screen::eventFilter(QObject *target, QEvent *event)
{

    QKeyEvent *key = static_cast <QKeyEvent*> (event);

    if(target == ui->radioButton_cft)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->radioButton_cft->hasFocus())
                {
                    inward_type = 0;

                    ui->radioButton_cft->setChecked(true);
                    ui->radioButton_count->setChecked(false);



                    ui->label_lbh->show();
                    ui->label_length->show();
                    ui->lineEdit_height_inches->show();
                    //                    ui->label_length_2->show();
                    //                    ui->label_length_3->show();
                    ui->lineEdit_height->show();
                    //                    ui->label_breadth->show();


                    ui->label_title_count->hide();
                    ui->lineEdit_count->hide();
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                    ui->lineEdit_height->setFocus();
                    //                    ui->lineEdit_customer_name->setFocus();
                    return true;
                }
            }
        }
    }
    else if(target == ui->radioButton_count)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->radioButton_count->hasFocus())
                {

                    inward_type = 1;

                    ui->lineEdit_count->clear();

                    ui->radioButton_count->setChecked(true);
                    ui->radioButton_cft->setChecked(false);

                    ui->label_title_count->show();
                    ui->lineEdit_count->show();

                    ui->label_lbh->hide();
                    ui->label_length->hide();
                    ui->lineEdit_height_inches->hide();
                    //                    ui->label_length_2->hide();
                    //                    ui->label_length_3->hide();
                    ui->lineEdit_height->hide();
                    //                    ui->label_breadth->hide();
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                    ui->lineEdit_count->setFocus();
                    return true;
                }
            }
        }
    }
    else if(target == ui->radioButton_reg_bal_advance)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->radioButton_reg_bal_advance->hasFocus())
                {
                    ui->radioButton_reg_bal_advance->setChecked(true);
                    ui->radioButton_reg_bal_pending->setChecked(false);
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                    ui->pushButton_reg_save->setFocus();
                    return true;
                }
            }
        }
    }
    else if(target == ui->radioButton_reg_bal_pending)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->radioButton_reg_bal_pending->hasFocus())
                {
                    ui->radioButton_reg_bal_pending->setChecked(true);
                    ui->radioButton_reg_bal_advance->setChecked(false);
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                    ui->pushButton_reg_save->setFocus();
                    return true;
                }
            }
        }
    }
    else if(target == ui->lineEdit_vehicle_number)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->lineEdit_vehicle_number->hasFocus())
                {
                    search_vehicle();

                    return true;
                }
            }
        }
//        else if(event->type() == QEvent::FocusIn)
//        {
//            qDebug()<<"setKeypadModeLock lineEdit_vehicle_number ===>>>";
//            g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
//            ui->lineEdit_vehicle_number->setCursor(Qt::IBeamCursor);
////            ui->lineEdit_vehicle_number->selectAll();
//            return true;
//        }
    }

    else if(target == ui->lineEdit_bull_reading)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->lineEdit_bull_reading->hasFocus())
                {
                    if(!ui->lineEdit_bull_reading->text().trimmed().isEmpty())
                    {
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                        ui->lineEdit_generator_reading->setFocus();
                    }
                    return true;
                }
            }
        }
//        if(event->type() == QEvent::FocusIn)
//        {
//            qDebug()<<"setKeypadModeLock lineEdit_bull_reading ===>>>";
//            g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
//            ui->lineEdit_vehicle_number->setCursor(Qt::IBeamCursor);
//            ui->lineEdit_vehicle_number->selectAll();
//            ui->lineEdit_vehicle_number->deselect();
//            return true;
//        }
    }

    else if(target == ui->lineEdit_generator_reading)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->lineEdit_generator_reading->hasFocus())
                {
                    if(!ui->lineEdit_generator_reading->text().trimmed().isEmpty())
                    {
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                        ui->lineEdit_eb_reading->setFocus();
                    }
                    return true;
                }
            }
        }
//        if(event->type() == QEvent::FocusIn)
//        {
//            qDebug()<<"setKeypadModeLock lineEdit_generator_reading ===>>>";
//            g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
//            ui->lineEdit_vehicle_number->setCursor(Qt::IBeamCursor);
//            ui->lineEdit_vehicle_number->selectAll();
//            ui->lineEdit_vehicle_number->deselect();
//            return true;
//        }
    }

    else if(target == ui->lineEdit_eb_reading)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->lineEdit_eb_reading->hasFocus())
                {
                    if(!ui->lineEdit_eb_reading->text().trimmed().isEmpty())
                    {
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                        ui->lineEdit_diesel->setFocus();
                    }
                    return true;
                }
            }
        }
//        if(event->type() == QEvent::FocusIn)
//        {
//            qDebug()<<"setKeypadModeLock lineEdit_eb_reading ===>>>";
//            g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
//            ui->lineEdit_vehicle_number->setCursor(Qt::IBeamCursor);
//            ui->lineEdit_vehicle_number->selectAll();
//            ui->lineEdit_vehicle_number->deselect();
//            return true;
//        }
    }

    else if(target == ui->lineEdit_diesel)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->lineEdit_diesel->hasFocus())
                {
                    if(!ui->lineEdit_diesel->text().trimmed().isEmpty())
                    {
                        if(!ui->lineEdit_diesel->text().trimmed().isEmpty() && !ui->lineEdit_eb_reading->text().trimmed().isEmpty() && !ui->lineEdit_generator_reading->text().trimmed().isEmpty() && !ui->lineEdit_bull_reading->text().trimmed().isEmpty())
                        {
                            ui->pushButton_initial_config_save->setEnabled(true);
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                            ui->pushButton_initial_config_save->setFocus();
                        }
                    }
                    return true;
                }
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

void Home_Screen::on_lineEdit_vehicle_number_returnPressed()
{

}

void Home_Screen::search_vehicle()
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

                ui->label_length->setText(selected_vehicle_length+"\'"+selected_vehicle_length_inch+"\""+"x"+selected_vehicle_width+"\'"+selected_vehicle_width_inch+"\"");
                ui->label_vehicle_type->setText(selected_vehicle_name);

                if(selected_vehicle_type.toInt() == 0){
                    ui->label_vehicle_type->setText("Company");
                    ui->label_cus_title->setText("Broker:");
                    selected_vehicle_type_name = "Company";

                    ui->lineEdit_customer_name->clear();
                    ui->lineEdit_customer_name->setReadOnly(false);
                    ui->lineEdit_customer_mobile->clear();

                    ui->gridLayoutWidget->show();
                    ui->gridLayoutWidget->setGeometry(10,50,300,160);
                    ui->radioButton_cft->setChecked(true);

                    ui->gridLayoutWidget_2->hide();

//                    cmpter = new QCompleter(lst_customer_name,this);
//                    cmpter->setCaseSensitivity(Qt::CaseInsensitive);
//                    ui->lineEdit_customer_name->setCompleter(cmpter);

#if(SDK75)
                    g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
#endif

                    ui->lineEdit_customer_name->setFocus();

                    return;
                }
                if(selected_vehicle_type.toInt() == 1){
                    ui->label_vehicle_type->setText("Auto");
                    ui->label_cus_title->setText("Customer");
                    selected_vehicle_type_name = "Auto";
                }
                if(selected_vehicle_type.toInt() == 2){
                    ui->label_vehicle_type->setText("Van");
                    ui->label_cus_title->setText("Customer");
                    selected_vehicle_type_name = "Van";
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



                ui->lineEdit_customer_name->setText(selected_cus_name);

#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                ui->radioButton_cft->setFocus();
                ui->gridLayoutWidget->show();
                ui->gridLayoutWidget->setGeometry(10,50,300,160);
                ui->radioButton_cft->setChecked(true);

                ui->gridLayoutWidget_2->hide();
            }
            else
            {
                //! vehicle not available
                //! msg for want to reg

                ui->gridLayoutWidget->setGeometry(10,50,300,160);
                ui->gridLayoutWidget->hide();

                ui->gridLayoutWidget_2->setGeometry(0,50,320,160);
                ui->gridLayoutWidget_2->show();
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                ui->comboBox_reg_owner->setFocus();


            }
        }
    }
}

void Home_Screen::on_lineEdit_height_returnPressed()
{
    if(!ui->lineEdit_height->text().isEmpty())
    {
        selected_vehicle_height = ui->lineEdit_height->text();
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
        ui->lineEdit_height_inches->setFocus();
        //        ui->radioButton_cft->setFocus();
        //        ui->radioButton_cft->setChecked(true);

    }
}

void Home_Screen::on_lineEdit_customer_name_returnPressed()
{
    if(!ui->lineEdit_customer_name->text().isEmpty())
    {
        QSqlQuery query;
        if(databaseObj->selectQuery("select * from customer_master where cus_name='"+ui->lineEdit_customer_name->text().trimmed()+"'",query))
        {
            if(query.next())
            {
                selected_cus_id = query.value(0).toString().trimmed();
                selected_cus_name = query.value(1).toString().trimmed();
                selected_cus_mobile = query.value(2).toString().trimmed();
                selected_cus_balance = query.value(3).toString().trimmed();
                selected_cus_balance_type = query.value(4).toString().trimmed();

                ui->lineEdit_customer_mobile->setText(selected_cus_mobile);
#if(SDK75)
                g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                ui->radioButton_cft->setFocus();
            }
            else
            {
                //! invalid customer
                //! msg before add
                if(gstrUserType.toInt() != 0)
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
                        if(databaseObj->executeCommand("insert into customer_master (cus_name,balance,balance_type,id_vehicle_registration,cus_type) values ('"+ui->lineEdit_customer_name->text().trimmed()+"','0','0','"+selected_vehicle_number_id+"','1')"))
                        {
                            selected_cus_name = ui->lineEdit_customer_name->text().trimmed();
                            selected_cus_balance = "0";
                            selected_cus_balance_type = "0";
                            ui->radioButton_cft->setFocus();

                            query.clear();
                            if(databaseObj->selectQuery("select * from customer_master where cus_name='"+ui->lineEdit_customer_name->text().trimmed()+"'",query))
                            {
                                if(query.next())
                                {
                                    selected_cus_id = query.value(0).toString().trimmed();
                                    selected_cus_name = query.value(1).toString().trimmed();
                                    selected_cus_mobile = query.value(2).toString().trimmed();
                                    selected_cus_balance = query.value(3).toString().trimmed();
                                    selected_cus_balance_type = query.value(4).toString().trimmed();

                                    ui->lineEdit_customer_mobile->setText(selected_cus_mobile);
                                    ui->radioButton_cft->setFocus();
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
                        ui->lineEdit_customer_name->setFocus();
                    }
#endif
#if(SDK75)
                    int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Error,"Invalid Customer..!\nAdd As New\nCustomer?",16,14,"YES","NO");
                    if(ret==1)
                    {
                        qDebug()<<"Invalid Customer Add as new yes ===>>>";
                        if(databaseObj->executeCommand("insert into customer_master (cus_name,balance,balance_type,id_vehicle_registration,cus_type) values ('"+ui->lineEdit_customer_name->text().trimmed()+"','0','0','"+selected_vehicle_number_id+"','1')"))
                        {
                            selected_cus_name = ui->lineEdit_customer_name->text().trimmed();
                            selected_cus_balance = "0";
                            selected_cus_balance_type = "0";
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                            ui->radioButton_cft->setFocus();

                            query.clear();
                            if(databaseObj->selectQuery("select * from customer_master where cus_name='"+ui->lineEdit_customer_name->text().trimmed()+"'",query))
                            {
                                if(query.next())
                                {
                                    selected_cus_id = query.value(0).toString().trimmed();
                                    selected_cus_name = query.value(1).toString().trimmed();
                                    selected_cus_mobile = query.value(2).toString().trimmed();
                                    selected_cus_balance = query.value(3).toString().trimmed();
                                    selected_cus_balance_type = query.value(4).toString().trimmed();

                                    ui->lineEdit_customer_mobile->setText(selected_cus_mobile);
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                                    ui->radioButton_cft->setFocus();
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
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
#endif
                        ui->lineEdit_customer_name->setFocus();
                    }
#endif

                }

#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                ui->lineEdit_customer_mobile->setFocus();
            }
        }
    }
}

void Home_Screen::on_lineEdit_customer_mobile_returnPressed()
{
    QSqlQuery query;
    if(databaseObj->selectQuery("select * from customer_master where cus_mobile='"+ui->lineEdit_customer_mobile->text().trimmed()+"'",query))
    {
        if(query.next())
        {
            selected_cus_id = query.value(0).toString().trimmed();
            selected_cus_name = query.value(1).toString().trimmed();
            selected_cus_mobile = query.value(2).toString().trimmed();
            selected_cus_balance = query.value(3).toString().trimmed();

            ui->lineEdit_customer_name->setText(selected_cus_name);
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
#endif
            ui->pushButton_next->setFocus();
        }
        else
        {
            //! invalid customer
            if(databaseObj->selectQuery("select * from customer_master where cus_mobile='"+ui->lineEdit_customer_mobile->text().trimmed()+"' and cus_name='"+ui->lineEdit_customer_name->text().trimmed()+"'",query))
            {
                if(query.next())
                {

                }
                else
                {
                    if(databaseObj->executeCommand("insert into customer_master (cus_name,cus_mobile) values ('"+ui->lineEdit_customer_name->text().trimmed()+"','"+ui->lineEdit_customer_mobile->text().trimmed()+"')"))
                    {
                        databaseObj->con.commit();
                        qDebug()<<"new customer added ===>>>";
                        query.clear();
                        if(databaseObj->selectQuery("select * from customer_master where cus_mobile='"+ui->lineEdit_customer_mobile->text().trimmed()+"'",query))
                        {
                            selected_cus_id = query.value(0).toString().trimmed();
                            selected_cus_name = query.value(1).toString().trimmed();
                            selected_cus_mobile = query.value(2).toString().trimmed();
                            selected_cus_balance = query.value(3).toString().trimmed();

                            ui->lineEdit_customer_name->setText(selected_cus_name);
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
#endif
                            ui->pushButton_next->setFocus();
                        }
                    }
                }
            }
        }
    }
}

void Home_Screen::on_pushButton_next_clicked()
{
    if(!selected_cus_id.isEmpty())
    {

        if(selected_vehicle_type.toInt() == 0)
        {
            odometer_reading.clear();
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

                QSqlQuery diesel_qur;
                if(databaseObj->selectQuery("select vehicle_registration.odometer_reading from vehicle_registration where vehicle_registration.vehicle_no='"+ui->lineEdit_vehicle_number->text().trimmed()+"'",diesel_qur))
                {
                    if(diesel_qur.next())
                    {
                        odometer_reading_old = diesel_qur.value(0).toString();
                        qDebug()<<"odometer_reading_old ===>>>"<<odometer_reading_old;
                        if(inputDialog.textValue().toInt() >= odometer_reading_old.toInt())
                        {
                            odometer_reading = inputDialog.textValue().trimmed();
                            distaance_covered = QString::number(odometer_reading.toInt() - odometer_reading_old.toInt());
                            qDebug()<<"distaance_covered ===>>>"<<distaance_covered;
                        }
                        else
                        {
                            ui->pushButton_next->setFocus();
                            return;
                        }
                    }
                }

                //            if(databaseObj->executeCommand("UPDATE configuration_master set husk_per_cft='"+inputDialog.textValue()+"';"))
                //            {
                //                databaseObj->con.commit();
                //            }
            }
            else
            {
                return;
            }
        }

        if(ui->radioButton_cft->isChecked())
        {
            ui->label_title->setText("Payment Details");

            float len = selected_vehicle_length.toFloat() + (selected_vehicle_length_inch.toFloat()/12);
            float bre = selected_vehicle_width.toFloat() + (selected_vehicle_width_inch.toFloat()/12);


            selected_vehicle_length_ft = QString::number(len,'f',2);
            selected_vehicle_width_ft = QString::number(bre,'f',2);


            total_cft = QString::number(/*ceil*/(len * bre * selected_vehicle_height.toFloat()),'f',2);

            final_count = QString::number(/*ceil*/(HP_cft.toFloat()*total_cft.toFloat()),'f',0);


            qDebug()<<"total_cft ===>>>"<<QString(total_cft);
            qDebug()<<"final_count ===>>>"<<QString(final_count);

            if(selected_vehicle_type.toInt() == 0)
            {
                estimated_amount = QString::number(total_cft.toFloat()*RP_cft.toFloat(),'f',0);
                qDebug()<<"estimated_amount company ===>>>"<<QString(estimated_amount);
            }
            if(selected_vehicle_type.toInt() == 1)
            {
                estimated_amount = QString::number(total_cft.toFloat()*RP_cft_auto.toFloat(),'f',0);
                qDebug()<<"estimated_amount auto ===>>>"<<QString(estimated_amount);
            }
            if(selected_vehicle_type.toInt() == 2)
            {
                estimated_amount = QString::number(total_cft.toFloat()*RP_cft_van.toFloat(),'f',0);
                qDebug()<<"estimated_amount van ===>>>"<<QString(estimated_amount);
            }
        }
        if(ui->radioButton_count->isChecked())
        {
            final_count = QString::number(ui->lineEdit_count->text().toFloat(),'f',2);
            total_cft = QString::number(/*ceil*/(final_count.toFloat()/HP_cft.toFloat()),'f',2);
            if(selected_vehicle_type.toInt() == 0)
            {
                estimated_amount = QString::number(/*ceil*/(final_count.toFloat()*RP_husk.toFloat()),'f',0);
            }
            if(selected_vehicle_type.toInt() == 1)
            {
                estimated_amount = QString::number(/*ceil*/(final_count.toFloat()*RP_husk_auto.toFloat()),'f',0);
            }
            if(selected_vehicle_type.toInt() == 2)
            {
                estimated_amount = QString::number(/*ceil*/(final_count.toFloat()*RP_husk_van.toFloat()),'f',0);
            }
            qDebug()<<"total_cft radioButton_count ===>>>"<<QString(total_cft);
            qDebug()<<"final_count radioButton_count ===>>>"<<QString(final_count);
            qDebug()<<"estimated_amount radioButton_count ===>>>"<<final_count<<RP_husk<<estimated_amount;
        }


        this->hide();
        Customer_DetailsObj->call_Customer_Details();
        Customer_DetailsObj->show();
    }
}

void Home_Screen::on_lineEdit_customer_name_textEdited(const QString &arg1)
{
    selected_cus_balance.clear();
    selected_cus_id.clear();
    selected_cus_mobile.clear();
    selected_cus_name.clear();
}

void Home_Screen::on_lineEdit_customer_mobile_textEdited(const QString &arg1)
{
    selected_cus_balance.clear();
    selected_cus_id.clear();
    selected_cus_mobile.clear();
    selected_cus_name.clear();
}

void Home_Screen::on_lineEdit_count_returnPressed()
{
    if(!ui->lineEdit_count->text().isEmpty() && ui->radioButton_count->isChecked())
    {
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
        ui->pushButton_next->setFocus();
    }
}

void Home_Screen::on_lineEdit_reg_name_returnPressed()
{
    if(!ui->lineEdit_reg_name->text().isEmpty())
    {
#if(SDK75)
        g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
        ui->lineEdit_reg_length->setFocus();
    }
}

void Home_Screen::on_lineEdit_reg_length_returnPressed()
{
    if(!ui->lineEdit_reg_length->text().isEmpty())
    {
#if(SDK75)
        g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
        ui->lineEdit_reg_length_inche->setFocus();
    }
}

void Home_Screen::on_lineEdit_reg_breadth_returnPressed()
{
    if(!ui->lineEdit_reg_breadth->text().isEmpty())
    {
#if(SDK75)
        g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
        ui->lineEdit_reg_breadth_inche->setFocus();
    }
}

void Home_Screen::on_pushButton_reg_save_clicked()
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
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                    ui->pushButton_reg_save->setFocus();
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

                }
            }
        }
    }

    call_Home_Screen();
}

void Home_Screen::on_radioButton_count_clicked(bool checked)
{
    inward_type = 1;

    ui->radioButton_count->setChecked(true);
    ui->radioButton_cft->setChecked(false);

    ui->label_title_count->show();
    ui->lineEdit_count->show();

    ui->label_lbh->hide();
    ui->label_length->hide();
    ui->lineEdit_height_inches->hide();
    //    ui->label_length_2->hide();
    //    ui->label_length_3->hide();
    ui->lineEdit_height->hide();
    //    ui->label_breadth->hide();
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
    ui->lineEdit_count->setFocus();
}

void Home_Screen::on_radioButton_cft_clicked(bool checked)
{
    inward_type = 0;

    ui->radioButton_cft->setChecked(true);
    ui->radioButton_count->setChecked(false);



    ui->label_lbh->show();
    ui->label_length->show();
    ui->lineEdit_height_inches->show();
    //    ui->label_length_2->show();
    //    ui->label_length_3->show();
    ui->lineEdit_height->show();
    //    ui->label_breadth->show();


    ui->label_title_count->hide();
    ui->lineEdit_count->hide();
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
    ui->lineEdit_height->setFocus();
}


/** ----------------------------  DAY/BATCH open close  ---------------------------------------- **/


bool Home_Screen::isDayOpen()
{
    QSqlQuery day_master;
    int row_count = 0;
    if(databaseObj->selectQuery("SELECT day_no,status,open_date,close_date,open_time,close_time,open_bull_reading,open_gen_reading,open_eb_reading,open_diesel_reading,opening_bale_balance FROM day_master WHERE id_day= (SELECT MAX(id_day) FROM day_master)",day_master))
    {
        if(day_master.next())
        {
            gstrday_no = day_master.value(0).toString();
            gstrday_open_date = day_master.value(2).toString();
            gstrday_close_date = day_master.value(3).toString();
            gstrday_open_time = day_master.value(4).toString();
            gstrday_close_time = day_master.value(5).toString();
            gstrday_open_bale =  day_master.value(10).toString();
            qDebug()<<"isDay_Open gstrday_open_bale ===>>>"<<gstrday_open_bale;
            if(day_master.value(1).toInt() == 1)
            {
//                QSqlQuery query;
//                if(databaseObj->selectQuery("select max(opening_bale_balance) from day_master where status='0'",query))
//                {
//                    if(query.next())
//                        gstrday_open_bale = query.value(0).toString();
//                    else
//                        gstrday_open_bale = "0";
//                }
                isDay_Open = true;
                return true;
            }
            else
            {
                isDay_Open = false;
                return false;
            }
        }
        else
        {
            isDay_Open = false;
            return false;
        }
    }
}

bool Home_Screen::isShiftOpen()
{
    qDebug()<<"isShiftOpen 1 ===>>>";
    QSqlQuery shift_master;
    int row_count = 0;
    if(databaseObj->selectQuery("SELECT batch_no,status,day_no,open_date,close_date,open_time,close_time FROM company_batch_no WHERE id_company_batch_no=(SELECT MAX(id_company_batch_no) FROM company_batch_no)",shift_master))
    {
        if(shift_master.next())
        {
            qDebug()<<"isShiftOpen 2 ===>>>";
            gstrshift_no = shift_master.value(0).toString();

            gstrshift_day_number = shift_master.value(2).toString();

            gstrshift_open_date = shift_master.value(3).toString();
            gstrshift_close_date = shift_master.value(4).toString();
            gstrshift_open_time = shift_master.value(5).toString();
            gstrshift_close_time = shift_master.value(6).toString();

            qDebug()<<"in shift close isShiftOpen ===>>>"<<gstrshift_open_date<<gstrshift_day_number<<gstrshift_no;

            qDebug()<<"isShiftOpen 2.1 ===>>>"<<gstrshift_no<<"&"<<shift_master.value(1).toString();
            if(shift_master.value(1).toInt() == 1)
            {
                qDebug()<<"isShiftOpen 3 ===>>>";
                isShift_Open = true;
                return true;
            }
            else
            {
                qDebug()<<"isShiftOpen 4 ===>>>";
                isShift_Open = false;
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        qDebug()<<"isShiftOpen 5 ===>>>";
        isShift_Open = false;
        return false;
    }
}

void Home_Screen::open_day(QWidget *w)
{


    QSqlQuery batch_open;
    QString batch_count;
    if(databaseObj->selectQuery("select count(*) from production_batch_order",batch_open))
    {
        if(batch_open.next())
        {
            batch_count = batch_open.value(0).toString().trimmed();
        }
    }
    if(batch_count.toInt() > 0)
    {
        batch_open.clear();
        if(databaseObj->selectQuery("select * from production_batch_order",batch_open))
        {
            if(batch_open.next())
            {
                batch_count = batch_open.value(0).toString().trimmed();
            }
        }
    }


#if(SDK75)

    if(g_ccmainObj->messagebox(w,"Day Open",eMessageType_Information,"Do you want\nOpen Day?",16,14,"YES","NO") == 1)
#endif
#if(NativeCompile)
        QMessageBox m_box;
    QFont font;
    font.setFamily("DejaVu Sans Mono");
    font.setPointSize(12);
    m_box.setFont(font);
    m_box.setParent(this);
    if(m_box.question(this, "Day Open","Do you want\nOpen Day?","No","Yes"))
#endif
    {
        QSqlQuery day_master;
        int row_count = 0;
        //    SELECT count(*) FROM day_master WHERE id_day= (SELECT MAX(id_day) FROM day_master)
        if(databaseObj->selectQuery("SELECT count(*) FROM day_master",day_master))
        {
            if(day_master.next())
            {
                row_count = day_master.value(0).toInt();
            }
            if(row_count == 0)
            {
                gstrday_no = "1";


                //! input config


                qDebug()<<"day 1 opening ===>>>";
//                ui->groupBox->hide();
//                ui->groupBox_initial_config->setParent(w);
//                ui->groupBox_initial_config->show();
//#if(SDK75)
//    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
//#endif
//                ui->lineEdit_bull_reading->setFocus();



                QSqlQuery reading_qur;
                QString last_bull_meter_reading,last_gen_meter_reading,last_eb_meter_reading,last_deisel_reading,last_husk_per_cft,last_husk_per_bale;
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




                gstropen_bull_reading = last_bull_meter_reading;
                gstropen_diesel_reading = last_deisel_reading;
                gstropen_eb_reading = last_eb_meter_reading;
                gstropen_gen_reading = last_gen_meter_reading;

                QString closing_bale="0";

                if(gstrday_no.toInt() == 1)
                {
                    closing_bale = "0";
                    gstrday_open_bale = "0";
                }
                else
                {
                    QSqlQuery query;
                    if(databaseObj->selectQuery("select max(closing_bale_balance) from day_master where status='0'",query))
                    {
                        if(query.next())
                            closing_bale = query.value(0).toString();
                        else
                            closing_bale = "0";
                    }
                    qDebug()<<"closing_bale_balance ===>>>"<<closing_bale;

                }

                qDebug()<<"closing_bale_balance ===>>>"<<closing_bale;
                qDebug()<<"gstrday_open_bale ===>>>"<<gstrday_open_bale;

                if(databaseObj->executeCommand("INSERT INTO day_master(day_no,open_date,open_time,status,open_user_id,open_bull_reading,open_gen_reading,open_eb_reading,open_diesel_reading,opening_bale_balance,closing_bale_balance,opening_cash) VALUES ('"+gstrday_no+"','"+QDate::currentDate().toString("dd-MM-yyyy")+"','"+QTime::currentTime().toString("hh:mm:ss")+"','1','"+gstr_Users_server_id+"','"+gstropen_bull_reading+"','"+gstropen_gen_reading+"','"+gstropen_eb_reading+"','"+gstropen_diesel_reading+"','"+gstrday_open_bale+"','0',(select sum(user_master.aval_cash) from user_master))"))
                {
//                    ui->groupBox_initial_config->hide();
//                    ui->groupBox_initial_config->lower();
//                    //        call_Home_Screen();
//                    ui->lineEdit_vehicle_number->setFocus();
                    ui->groupBox->hide();
                    day_shift();

//                    this->close();

//                    Staff_CashObj->from_day_open = true;
//                    Staff_CashObj->call_Staff_Cash();
//                    Staff_CashObj->on_pushButton_from_clicked();
//                    Staff_CashObj->show();

                    this->close();
                    menuObj->call_menu();
                    menuObj->show();

                    isDay_Open = true;
                    return;
                }



                return;
                //                if(databaseObj->executeCommand("INSERT INTO day_master(day_no,open_date,open_time,status,open_user_id) VALUES ('"+gstrday_no+"','"+QDate::currentDate().toString("dd-MM-yyyy")+"','"+QTime::currentTime().toString("hh:mm:ss")+"','1','"+gstr_Users_server_id+"')"))
                //                {
                //                    isDay_Open = true;
                //                    return;
                //                }
            }
            if(row_count > 0)
            {
                day_master.clear();
                if(databaseObj->selectQuery("SELECT day_no,status,open_date,close_date,open_time,close_time FROM day_master WHERE id_day= (SELECT MAX(id_day) FROM day_master)",day_master))
                {
                    if(day_master.next())
                    {
                        gstrday_no = day_master.value(0).toString();

                        gstrday_open_date = day_master.value(2).toString();
                        gstrday_close_date = day_master.value(3).toString();
                        gstrday_open_time = day_master.value(4).toString();
                        gstrday_close_time = day_master.value(5).toString();

                        if(day_master.value(1).toInt() == 1)
                            isDay_Open = true;
                        else
                            isDay_Open = false;
                    }
                    if(!isDay_Open)
                    {


                        gstrday_no = QString::number(gstrday_no.toInt() + 1);

                        if(databaseObj->executeCommand("INSERT INTO day_master(day_no,open_date,open_time,status,open_user_id,open_bull_reading,open_gen_reading,open_eb_reading,open_diesel_reading,opening_bale_balance,opening_cash) VALUES ('"+gstrday_no+"','"+QDate::currentDate().toString("dd-MM-yyyy")+"','"+QTime::currentTime().toString("hh:mm:ss")+"','1','"+gstr_Users_server_id+"',(select close_bull_reading from day_master where status=0 and rowid=(select max(rowid) from day_master where status=0 )),(select close_gen_reading from day_master where status=0 and rowid=(select max(rowid) from day_master where status=0 )),(select close_eb_reading from day_master where status=0 and rowid=(select max(rowid) from day_master where status=0 )),(select close_diesel_reading from day_master where status=0 and rowid=(select max(rowid) from day_master where status=0 )),(select closing_bale_balance from day_master where status=0 and rowid=(select max(rowid) from day_master where status=0 )),(select sum(user_master.aval_cash) from user_master))"))
                        {
                            isDay_Open = true;

                            gstrday_no = gstrday_no;
                            gstrday_open_date = QDate::currentDate().toString("dd-MM-yyyy");

                            ui->groupBox->hide();
                            ui->groupBox_initial_config->hide();

//                            this->close();
//                            Staff_CashObj->from_day_open = true;
//                            Staff_CashObj->call_Staff_Cash();
//                            Staff_CashObj->on_pushButton_from_clicked();
//                            Staff_CashObj->show();

                            this->close();
                            menuObj->call_menu();
                            menuObj->show();

                            return;
                        }
                    }
                }
            }
        }
    }
#if(NativeCompile)
    else
    {
        this->close();
        ui->groupBox->hide();
        menuObj->show();
        menuObj->call_menu();
        return;
    }
#endif

#if(SDK75)

    else
    {
        this->close();
        ui->groupBox->hide();
        menuObj->call_menu();
        menuObj->show();
        return;
    }
#endif
}

void Home_Screen::close_day(QWidget *w)
{
    //    if(!isShiftOpen())
    //    {
    if(isDayOpen())
    {


        if(databaseObj->executeCommand("update day_master set close_date='"+QDate::currentDate().toString("dd-MM-yyyy")+"', close_time='"+QTime::currentTime().toString("hh:mm:ss")+"',status='0',close_user_id='"+gstr_Users_server_id+"',closing_bale_balance='"+Day_CloseObj->closing_bale+"',closing_cash=(select sum(user_master.aval_cash) from user_master),close_diesel_reading=(select init_diesel_reading from configuration_master) where day_no='"+gstrday_no+"'"))
        {
            qDebug()<<"in day close ===>>>"<<gstrday_open_date<<gstrday_no;
            //                    ReportsObj->daywise_report(gstrday_open_date,gstrday_no);
            isDay_Open = false;
            Batch_CloseObj->set_focus();
        }

        //#if(SDK75)

        //        if(g_ccmainObj->messagebox(w,"Day Close",eMessageType_Information,"Do you want\nClose Day?",16,14,"YES","NO") == 1)
        //#endif
        //#if(NativeCompile)
        //            QMessageBox m_box;
        //        QFont font;
        //        font.setFamily("DejaVu Sans Mono");
        //        font.setPointSize(12);
        //        m_box.setFont(font);
        //        m_box.setParent(this);
        //        if(m_box.question(this, "Day Close","Do you want\nClose Day?","No","Yes"))
        //#endif
        //        {
        //            if(databaseObj->executeCommand("update day_master set close_date='"+QDate::currentDate().toString("dd-MM-yyyy")+"', close_time='"+QTime::currentTime().toString("hh:mm:ss")+"',status='0',close_user_id='"+gstr_Users_server_id+"' where day_no='"+gstrday_no+"'"))
        //            {
        //                qDebug()<<"in day close ===>>>"<<gstrday_open_date<<gstrday_no;
        //                //                    ReportsObj->daywise_report(gstrday_open_date,gstrday_no);
        //                isDay_Open = false;
        //            }
        //        }
    }
    //    else
    //    {
    //#if(SDK75)

    //        g_ccmainObj->messagebox(w,"Shift close",eMessageType_Information,"Shift is not\nClosed.");
    //#endif
    //#if(NativeCompile)
    //        QMessageBox m_box;
    //        QFont font;
    //        font.setFamily("DejaVu Sans Mono");
    //        font.setPointSize(12);
    //        m_box.setFont(font);
    //        m_box.setParent(this);
    //        if(m_box.information(this, "Shift close","Shift is not\nClosed.",QMessageBox::Ok))
    //        {
    //            qDebug()<<"ok ===>>>";
    //        }
    //        else
    //        {
    //            qDebug()<<"reset ===>>>";
    //        }
    //#endif

    //    }
}

void Home_Screen::open_shift(QWidget *w)
{
    QSqlQuery shift_master;
    int row_count = 0;
    if(isDay_Open && !isShift_Open)
    {
#if(SDK75)

        //        if(g_ccmainObj->messagebox(w,"Shift Open",eMessageType_Information,"Do you want Open\nCompany Batch",16,14,"YES","NO") == 1)
#endif

#if(NativeCompile)
        QMessageBox m_box;
        QFont font;
        font.setFamily("DejaVu Sans Mono");
        font.setPointSize(12);
        m_box.setFont(font);
        m_box.setParent(this);
        //        if(m_box.question(this, "Shift Open","Do you want\nOpen Company Batch","No","Yes"))
        //        {

        //        }
#endif
        {
            if(databaseObj->selectQuery("SELECT count(*) FROM company_batch_no",shift_master))
            {
                if(shift_master.next())
                {
                    row_count = shift_master.value(0).toInt();
                }
                if(row_count == 0)
                {
                    gstrshift_no = "1";
                    if(databaseObj->executeCommand("INSERT INTO company_batch_no(batch_no,day_no,open_date,open_time,status,open_user_id,inward_stock,total_husk_produced) VALUES ('"+gstrshift_no+"','"+gstrday_no+"','"+QDate::currentDate().toString("dd-MM-yyyy")+"','"+QTime::currentTime().toString("hh:mm:ss")+"','1','"+gstr_Users_server_id+"','','')"))
                    {
                        isShift_Open = true;
                        return;
                    }
                }
                if(row_count > 0)
                {
                    shift_master.clear();
                    if(databaseObj->selectQuery("SELECT batch_no,status,day_no,day_no,open_date,close_date,open_time,close_time FROM company_batch_no WHERE id_company_batch_no= (SELECT MAX(id_company_batch_no) FROM company_batch_no)",shift_master))
                    {
                        if(shift_master.next())
                        {
                            gstrshift_no = shift_master.value(0).toString();
                            gstrshift_day_number = shift_master.value(2).toString();

                            gstrshift_open_date = shift_master.value(3).toString();
                            gstrshift_close_date = shift_master.value(4).toString();
                            gstrshift_open_time = shift_master.value(5).toString();
                            gstrshift_close_time = shift_master.value(6).toString();

                            if(shift_master.value(1).toInt() == 1)
                                isShift_Open = true;
                            else
                                isShift_Open = false;
                            if(!isShift_Open)
                            {
                                gstrshift_no = QString::number(gstrshift_no.toInt() + 1);
                                if(databaseObj->executeCommand("INSERT INTO company_batch_no(batch_no,day_no,open_date,open_time,status,open_user_id,inward_stock,total_husk_produced) VALUES ('"+gstrshift_no+"','"+gstrday_no+"','"+QDate::currentDate().toString("dd-MM-yyyy")+"','"+QTime::currentTime().toString("hh:mm:ss")+"','1','"+gstr_Users_server_id+"','','')"))
                                {
                                    isShift_Open = true;
                                    gstrshift_no = gstrshift_no;

                                    gstrshift_open_date = QDate::currentDate().toString("dd-MM-yyyy");


                                    return;
                                }
                            }
                        }
                        else
                        {
                            if(!isShift_Open)
                            {
                                gstrshift_no = "1";
                                if(databaseObj->executeCommand("INSERT INTO company_batch_no(batch_no,day_no,open_date,open_time,status,open_user_id,inward_stock,total_husk_produced) VALUES ('"+gstrshift_no+"','"+gstrday_no+"','"+QDate::currentDate().toString("dd-MM-yyyy")+"','"+QTime::currentTime().toString("hh:mm:ss")+"','1','"+gstr_Users_server_id+"','','')"))
                                {
                                    isShift_Open = true;
                                    return;
                                }
                            }
                        }
                    }
                }
            }
        }
#if(NativeCompile)
        //        else
        //        {
        //            w->close();
        //            ui->groupBox->hide();
        //            menuObj->show();
        //            menuObj->call_menu();
        //            return;
        //        }
#endif
#if(SDK75)

        //        else
        //        {
        //            w->close();
        //            ui->groupBox->hide();
        //            menuObj->show();
        //            menuObj->call_menu();
        //        }
#endif
    }
}

bool Home_Screen::close_shift(QWidget *w)
{
#if(SDK75)

    QString cft_msg = "\nCFT:"+QString::number(Batch_ConfigurationObj->available_stock_company.toFloat()/Home_ScreenObj->HP_cft.toFloat())+" Nos";
    QString bale_msg = "\nBale:"+QString::number(Batch_ConfigurationObj->available_stock_company.toFloat()/Home_ScreenObj->HP_bale.toFloat())+" Nos";
    if(g_ccmainObj->messagebox(w,"Shift Close",eMessageType_Information,"Husk:"+Batch_ConfigurationObj->available_stock_company+" Nos"+cft_msg+bale_msg+"\nDo you want Close\nCompany Batch?",14,14,"YES","NO") == 1)
#endif

#if(NativeCompile)
        QMessageBox m_box;
    QFont font;
    font.setFamily("DejaVu Sans Mono");
    font.setPointSize(12);
    m_box.setFont(font);
    m_box.setParent(this);
    if(m_box.question(this, "Shift Close","Do you want Close\nCompany Batch?","No","Yes"))
#endif
    {

        total_husk.clear();est_husk.clear();
        QSqlQuery qur;
        QString stock;
        if(databaseObj->selectQuery("select inward_stock from company_batch_no where day_no='"+gstrday_no+"' and batch_no='"+gstrshift_no+"' and status='1'",qur))
        {
            if(qur.next())
            {

                stock = qur.value(0).toString().trimmed();
            }
        }

        total_husk = QString::number(stock.toFloat() * Home_ScreenObj->HP_cft.toFloat(),'f',2);
        est_husk = QString::number(total_husk.toFloat() / Home_ScreenObj->HP_bale.toFloat(),'f',2);

        qDebug()<<"total_husk ===>>>"<<total_husk;
        qDebug()<<"est_husk ===>>>"<<est_husk;


        //        if(databaseObj->executeCommand("update company_batch_no set close_date='"+QDate::currentDate().toString("dd-MM-yyyy")+"', close_time='"+QTime::currentTime().toString("hh:mm:ss")+"',status='0',production_status='2',close_user_id='"+gstr_Users_server_id+"',day_no_close='"+gstrday_no+"',manu_bale='"+Batch_CloseObj->manuf_bale+"',diff_bale='"+Batch_CloseObj->diff_bale+"',used_husk='"+Batch_CloseObj->used_husk+"',excess_husk='"+Batch_CloseObj->excess_husk+"',est_bale='"+Batch_CloseObj->est_husk+"' where batch_no='"+gstrshift_no+"'"))
        //        ,total_husk_produced='"+total_husk+"'
        if(databaseObj->executeCommand("update company_batch_no set close_date='"+QDate::currentDate().toString("dd-MM-yyyy")+"', close_time='"+QTime::currentTime().toString("hh:mm:ss")+"',status='0',production_status='2',close_user_id='"+gstr_Users_server_id+"',day_no_close='"+gstrday_no+"' where batch_no='"+gstrshift_no+"'"))
        {

            qDebug()<<"in shift close ===>>>"<<gstrshift_open_date<<gstrshift_day_number<<gstrshift_no;
            //            ReportsObj->shiftwise_report(gstrshift_open_date,gstrshift_day_number,gstrshift_no);

            isShift_Open = false;
            return true;
        }
    }
    return false;
}

void Home_Screen::open_shift_other(QWidget *w)
{
    qDebug()<<"in open_shift_other ===>>>";
    QSqlQuery shift_master;
    int row_count = 0;
    if(isDay_Open && !isShift_Open_other)
    {
#if(SDK75)

        //        if(g_ccmainObj->messagebox(w,"Shift Open",eMessageType_Information,"Do you want\nOpen Other Batch",16,14,"YES","NO") == 1)
#endif

#if(NativeCompile)
        QMessageBox m_box;
        QFont font;
        font.setFamily("DejaVu Sans Mono");
        font.setPointSize(12);
        m_box.setFont(font);
        m_box.setParent(this);
        //        if(m_box.question(this, "Shift Open","Do you want\nOpen Other Batch","No","Yes"))
#endif
        {
            if(databaseObj->selectQuery("SELECT count(*) FROM other_batch_no",shift_master))
            {
                if(shift_master.next())
                {
                    row_count = shift_master.value(0).toInt();
                }
                if(row_count == 0)
                {
                    gstrshift_no_other = "1";
                    if(databaseObj->executeCommand("INSERT INTO other_batch_no(batch_no,day_no,open_date,open_time,status,open_user_id,inward_stock,total_husk_produced) VALUES ('"+gstrshift_no_other+"','"+gstrday_no+"','"+QDate::currentDate().toString("dd-MM-yyyy")+"','"+QTime::currentTime().toString("hh:mm:ss")+"','1','"+gstr_Users_server_id+"','','')"))
                    {
                        isShift_Open_other = true;
                        return;
                    }
                }
                if(row_count > 0)
                {
                    shift_master.clear();
                    if(databaseObj->selectQuery("SELECT batch_no,status,day_no,day_no,open_date,close_date,open_time,close_time FROM other_batch_no WHERE id_other_batch_no= (SELECT MAX(id_other_batch_no) FROM other_batch_no)",shift_master))
                    {
                        if(shift_master.next())
                        {
                            gstrshift_no_other = shift_master.value(0).toString();
                            gstrshift_day_number_other = shift_master.value(2).toString();

                            gstrshift_open_date_other = shift_master.value(3).toString();
                            gstrshift_close_date_other = shift_master.value(4).toString();
                            gstrshift_open_time_other = shift_master.value(5).toString();
                            gstrshift_close_time_other = shift_master.value(6).toString();

                            if(shift_master.value(1).toInt() == 1)
                                isShift_Open_other = true;
                            else
                                isShift_Open_other = false;
                            if(!isShift_Open_other)
                            {
                                gstrshift_no_other = QString::number(gstrshift_no_other.toInt() + 1);

                                if(databaseObj->executeCommand("INSERT INTO other_batch_no(batch_no,day_no,open_date,open_time,status,open_user_id,inward_stock,total_husk_produced) VALUES ('"+gstrshift_no_other+"','"+gstrday_no+"','"+QDate::currentDate().toString("dd-MM-yyyy")+"','"+QTime::currentTime().toString("hh:mm:ss")+"','1','"+gstr_Users_server_id+"','','')"))
                                {
                                    isShift_Open_other = true;
                                    gstrshift_no_other = gstrshift_no;

                                    gstrshift_open_date_other = QDate::currentDate().toString("dd-MM-yyyy");


                                    return;
                                }
                            }
                        }
                        else
                        {
                            if(!isShift_Open_other)
                            {
                                gstrshift_no = "1";
                                if(databaseObj->executeCommand("INSERT INTO other_batch_no(batch_no,day_no,open_date,open_time,status,open_user_id,inward_stock,total_husk_produced) VALUES ('"+gstrshift_no_other+"','"+gstrday_no+"','"+QDate::currentDate().toString("dd-MM-yyyy")+"','"+QTime::currentTime().toString("hh:mm:ss")+"','1','"+gstr_Users_server_id+"','','')"))
                                {
                                    isShift_Open_other = true;
                                    return;
                                }
                            }
                        }
                    }
                }
            }
        }
#if(NativeCompile)
        //        else
        //        {
        //            w->close();
        //            ui->groupBox->hide();
        //            menuObj->show();
        //            menuObj->call_menu();
        //            return;
        //        }
#endif
#if(SDK75)

        //        else
        //        {
        //            w->close();
        //            menuObj->show();
        //            menuObj->call_menu();
        //        }
#endif
    }
}

void Home_Screen::open_shift_van(QWidget *w)
{
    qDebug()<<"in open_shift_van ===>>>";
    QSqlQuery shift_master;
    int row_count = 0;
    if(isDay_Open && !isShift_Open_van)
    {
#if(SDK75)

        //        if(g_ccmainObj->messagebox(w,"Shift Open",eMessageType_Information,"Do you want\nOpen van Batch",16,14,"YES","NO") == 1)
#endif

#if(NativeCompile)
        QMessageBox m_box;
        QFont font;
        font.setFamily("DejaVu Sans Mono");
        font.setPointSize(12);
        m_box.setFont(font);
        m_box.setParent(this);
        //        if(m_box.question(this, "Shift Open","Do you want\nOpen van Batch","No","Yes"))
#endif
        {
            if(databaseObj->selectQuery("SELECT count(*) FROM van_batch_no",shift_master))
            {
                if(shift_master.next())
                {
                    row_count = shift_master.value(0).toInt();
                }
                if(row_count == 0)
                {
                    gstrshift_no_van = "1";
                    if(databaseObj->executeCommand("INSERT INTO van_batch_no(batch_no,day_no,open_date,open_time,status,open_user_id,inward_stock,total_husk_produced) VALUES ('"+gstrshift_no_van+"','"+gstrday_no+"','"+QDate::currentDate().toString("dd-MM-yyyy")+"','"+QTime::currentTime().toString("hh:mm:ss")+"','1','"+gstr_Users_server_id+"','','')"))
                    {
                        isShift_Open_van = true;
                        return;
                    }
                }
                if(row_count > 0)
                {
                    shift_master.clear();
                    if(databaseObj->selectQuery("SELECT batch_no,status,day_no,day_no,open_date,close_date,open_time,close_time FROM van_batch_no WHERE id_van_batch_no= (SELECT MAX(id_van_batch_no) FROM van_batch_no)",shift_master))
                    {
                        if(shift_master.next())
                        {
                            gstrshift_no_van = shift_master.value(0).toString();
                            gstrshift_day_number_van = shift_master.value(2).toString();

                            gstrshift_open_date_van = shift_master.value(3).toString();
                            gstrshift_close_date_van = shift_master.value(4).toString();
                            gstrshift_open_time_van = shift_master.value(5).toString();
                            gstrshift_close_time_van = shift_master.value(6).toString();

                            if(shift_master.value(1).toInt() == 1)
                                isShift_Open_van = true;
                            else
                                isShift_Open_van = false;
                            if(!isShift_Open_van)
                            {
                                gstrshift_no_van = QString::number(gstrshift_no_van.toInt() + 1);

                                if(databaseObj->executeCommand("INSERT INTO van_batch_no(batch_no,day_no,open_date,open_time,status,open_user_id,inward_stock,total_husk_produced) VALUES ('"+gstrshift_no_van+"','"+gstrday_no+"','"+QDate::currentDate().toString("dd-MM-yyyy")+"','"+QTime::currentTime().toString("hh:mm:ss")+"','1','"+gstr_Users_server_id+"','','')"))
                                {
                                    isShift_Open_van = true;
                                    gstrshift_no_van = gstrshift_no;

                                    gstrshift_open_date_van = QDate::currentDate().toString("dd-MM-yyyy");


                                    return;
                                }
                            }
                        }
                        else
                        {
                            if(!isShift_Open_van)
                            {
                                gstrshift_no = "1";
                                if(databaseObj->executeCommand("INSERT INTO van_batch_no(batch_no,day_no,open_date,open_time,status,open_user_id,inward_stock,total_husk_produced) VALUES ('"+gstrshift_no_van+"','"+gstrday_no+"','"+QDate::currentDate().toString("dd-MM-yyyy")+"','"+QTime::currentTime().toString("hh:mm:ss")+"','1','"+gstr_Users_server_id+"','','')"))
                                {
                                    isShift_Open_van = true;
                                    return;
                                }
                            }
                        }
                    }
                }
            }
        }
#if(NativeCompile)
        //        else
        //        {
        //            w->close();
        //            ui->groupBox->hide();
        //            menuObj->show();
        //            menuObj->call_menu();
        //            return;
        //        }
#endif
#if(SDK75)

        //        else
        //        {
        //            w->close();
        //            menuObj->show();
        //            menuObj->call_menu();
        //        }
#endif
    }
}

bool Home_Screen::isShiftOpen_other()
{
    qDebug()<<"isShiftOpen_other 1 ===>>>";
    QSqlQuery shift_master;
    int row_count = 0;
    if(databaseObj->selectQuery("SELECT batch_no,status,day_no,open_date,close_date,open_time,close_time FROM other_batch_no WHERE id_other_batch_no=(SELECT MAX(id_other_batch_no) FROM other_batch_no)",shift_master))
    {
        if(shift_master.next())
        {
            qDebug()<<"isShiftOpen_other 2 ===>>>";
            gstrshift_no_other = shift_master.value(0).toString();

            gstrshift_day_number_other = shift_master.value(2).toString();

            gstrshift_open_date_other = shift_master.value(3).toString();
            gstrshift_close_date_other = shift_master.value(4).toString();
            gstrshift_open_time_other = shift_master.value(5).toString();
            gstrshift_close_time_other = shift_master.value(6).toString();

            qDebug()<<"in isShiftOpen_other close isShiftOpen ===>>>"<<gstrshift_open_date_other<<gstrshift_day_number_other<<gstrshift_no_other;

            qDebug()<<"isShiftOpen 2.1 ===>>>"<<gstrshift_no_other<<"&"<<shift_master.value(1).toString();
            if(shift_master.value(1).toInt() == 1)
            {
                qDebug()<<"isShiftOpen_other 3 ===>>>";
                isShift_Open_other = true;
                return true;
            }
            else
            {
                qDebug()<<"isShiftOpen_other 4 ===>>>";
                isShift_Open_other = false;
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        qDebug()<<"isShiftOpen_other 5 ===>>>";
        isShift_Open_other = false;
        return false;
    }
}

bool Home_Screen::isShiftOpen_van()
{
    qDebug()<<"isShiftOpen_van 1 ===>>>";
    QSqlQuery shift_master;
    int row_count = 0;
    if(databaseObj->selectQuery("SELECT batch_no,status,day_no,open_date,close_date,open_time,close_time FROM van_batch_no WHERE id_van_batch_no=(SELECT MAX(id_van_batch_no) FROM van_batch_no)",shift_master))
    {
        if(shift_master.next())
        {
            qDebug()<<"isShiftOpen_van 2 ===>>>";
            gstrshift_no_van = shift_master.value(0).toString();

            gstrshift_day_number_van = shift_master.value(2).toString();

            gstrshift_open_date_van = shift_master.value(3).toString();
            gstrshift_close_date_van = shift_master.value(4).toString();
            gstrshift_open_time_van = shift_master.value(5).toString();
            gstrshift_close_time_van = shift_master.value(6).toString();

            qDebug()<<"in isShiftOpen_van close isShiftOpen ===>>>"<<gstrshift_open_date_van<<gstrshift_day_number_van<<gstrshift_no_van;

            qDebug()<<"isShiftOpen 2.1 ===>>>"<<gstrshift_no_van<<"&"<<shift_master.value(1).toString();
            if(shift_master.value(1).toInt() == 1)
            {
                qDebug()<<"isShiftOpen_van 3 ===>>>";
                isShift_Open_van = true;
                return true;
            }
            else
            {
                qDebug()<<"isShiftOpen_van 4 ===>>>";
                isShift_Open_van = false;
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        qDebug()<<"isShiftOpen_van 5 ===>>>";
        isShift_Open_van = false;
        return false;
    }
}

bool Home_Screen::close_shift_other(QWidget *w)
{
#if(SDK75)

    QString cft_msg = "\nCFT:"+QString::number(Batch_ConfigurationObj->available_stock_auto.toFloat()/Home_ScreenObj->HP_cft.toFloat())+" Nos";
    QString bale_msg = "\nBale:"+QString::number(Batch_ConfigurationObj->available_stock_auto.toFloat()/Home_ScreenObj->HP_bale.toFloat())+" Nos";
    if(g_ccmainObj->messagebox(w,"Shift Close",eMessageType_Information,"Husk:"+Batch_ConfigurationObj->available_stock_auto+" Nos"+cft_msg+bale_msg+"\nDo you want Close\nAuto Batch?",16,14,"YES","NO") == 1)
#endif

#if(NativeCompile)
        QMessageBox m_box;
    QFont font;
    font.setFamily("DejaVu Sans Mono");
    font.setPointSize(12);
    m_box.setFont(font);
    m_box.setParent(this);
    if(m_box.question(this, "Shift Close","Do you want Close\nAuto Batch?","No","Yes"))
#endif

    {
        total_husk.clear();est_husk.clear();
        QSqlQuery qur;
        QString stock;
        if(databaseObj->selectQuery("select inward_stock from other_batch_no where day_no='"+gstrday_no+"' and batch_no='"+gstrshift_no_other+"' and status='1'",qur))
        {
            if(qur.next())
            {

                stock = qur.value(0).toString().trimmed();
            }
        }

        total_husk = QString::number(stock.toFloat() * Home_ScreenObj->HP_cft.toFloat(),'f',2);
        est_husk = QString::number(total_husk.toFloat() / Home_ScreenObj->HP_bale.toFloat(),'f',2);

        qDebug()<<"total_husk ===>>>"<<total_husk;
        qDebug()<<"est_husk ===>>>"<<est_husk;

        //        if(databaseObj->executeCommand("update other_batch_no set close_date='"+QDate::currentDate().toString("dd-MM-yyyy")+"', close_time='"+QTime::currentTime().toString("hh:mm:ss")+"',status='0',production_status='2',close_user_id='"+gstr_Users_server_id+"',day_no_close='"+gstrday_no+"',manu_bale='"+Batch_CloseObj->manuf_bale+"',diff_bale='"+Batch_CloseObj->diff_bale+"',used_husk='"+Batch_CloseObj->used_husk+"',excess_husk='"+Batch_CloseObj->excess_husk+"',est_bale='"+Batch_CloseObj->est_husk+"' where batch_no='"+gstrshift_no_other+"'"))
        if(databaseObj->executeCommand("update other_batch_no set close_date='"+QDate::currentDate().toString("dd-MM-yyyy")+"', close_time='"+QTime::currentTime().toString("hh:mm:ss")+"',status='0',production_status='2',close_user_id='"+gstr_Users_server_id+"',day_no_close='"+gstrday_no+"' where batch_no='"+gstrshift_no_other+"'"))
        {

            qDebug()<<"in shift close ===>>>"<<gstrshift_open_date_other<<gstrshift_day_number_other<<gstrshift_no_other;
            //            ReportsObj->shiftwise_report(gstrshift_open_date,gstrshift_day_number,gstrshift_no_other);


            isShift_Open_other = false;
            return true;
        }
    }
    return false;
}

bool Home_Screen::close_shift_van(QWidget *w)
{
#if(SDK75)

    QString cft_msg = "\nCFT:"+QString::number(Batch_ConfigurationObj->available_stock_van.toFloat()/Home_ScreenObj->HP_cft.toFloat())+" Nos";
    QString bale_msg = "\nBale:"+QString::number(Batch_ConfigurationObj->available_stock_van.toFloat()/Home_ScreenObj->HP_bale.toFloat())+" Nos";
    if(g_ccmainObj->messagebox(w,"Shift Close",eMessageType_Information,"Husk:"+Batch_ConfigurationObj->available_stock_van+" Nos"+cft_msg+bale_msg+"\nDo you want Close\nVans Batch?",16,14,"YES","NO") == 1)
#endif

#if(NativeCompile)
        QMessageBox m_box;
    QFont font;
    font.setFamily("DejaVu Sans Mono");
    font.setPointSize(12);
    m_box.setFont(font);
    m_box.setParent(this);
    if(m_box.question(this, "Shift Close","Do you want Close\nvans Batch?","No","Yes"))
#endif

    {
        total_husk.clear();est_husk.clear();
        QSqlQuery qur;
        QString stock;
        if(databaseObj->selectQuery("select inward_stock from van_batch_no where day_no='"+gstrday_no+"' and batch_no='"+gstrshift_no_van+"' and status='1'",qur))
        {
            if(qur.next())
            {

                stock = qur.value(0).toString().trimmed();
            }
        }

        total_husk = QString::number(stock.toFloat() * Home_ScreenObj->HP_cft.toFloat(),'f',2);
        est_husk = QString::number(total_husk.toFloat() / Home_ScreenObj->HP_bale.toFloat(),'f',2);

        qDebug()<<"total_husk ===>>>"<<total_husk;
        qDebug()<<"est_husk ===>>>"<<est_husk;

        //        if(databaseObj->executeCommand("update van_batch_no set close_date='"+QDate::currentDate().toString("dd-MM-yyyy")+"', close_time='"+QTime::currentTime().toString("hh:mm:ss")+"',status='0',production_status='2',close_user_id='"+gstr_Users_server_id+"',day_no_close='"+gstrday_no+"',manu_bale='"+Batch_CloseObj->manuf_bale+"',diff_bale='"+Batch_CloseObj->diff_bale+"',used_husk='"+Batch_CloseObj->used_husk+"',excess_husk='"+Batch_CloseObj->excess_husk+"',est_bale='"+Batch_CloseObj->est_husk+"' where batch_no='"+gstrshift_no_van+"'"))
        //        ,total_husk_produced='"+Batch_CloseObj->total_husk+"'
        if(databaseObj->executeCommand("update van_batch_no set close_date='"+QDate::currentDate().toString("dd-MM-yyyy")+"', close_time='"+QTime::currentTime().toString("hh:mm:ss")+"',status='0',production_status='2',close_user_id='"+gstr_Users_server_id+"',day_no_close='"+gstrday_no+"' where batch_no='"+gstrshift_no_van+"'"))
        {

            qDebug()<<"in shift close ===>>>"<<gstrshift_open_date_van<<gstrshift_day_number_van<<gstrshift_no_van;
            //            ReportsObj->shiftwise_report(gstrshift_open_date,gstrshift_day_number,gstrshift_no_van);


            isShift_Open_van = false;
            return true;
        }
    }
    return false;
}

void Home_Screen::on_lineEdit_height_inches_returnPressed()
{
    if(!ui->lineEdit_height_inches->text().isEmpty() && ui->lineEdit_height_inches->text().toInt() >= 0)
    {
        selected_vehicle_height = ui->lineEdit_height->text().trimmed();
        qDebug()<<"selected_vehicle_height ===>>>"<<selected_vehicle_height;

        selected_vehicle_height_inche = ui->lineEdit_height_inches->text().trimmed();
        qDebug()<<"selected_vehicle_height_inche ===>>>"<<selected_vehicle_height_inche;


        selected_vehicle_height = QString::number(selected_vehicle_height.toFloat() + (selected_vehicle_height_inche.toFloat()/12),'f',2 );

        qDebug()<<"selected_vehicle_height ===>>>"<<selected_vehicle_height;



        ui->pushButton_next->setFocus();
    }
}

void Home_Screen::on_lineEdit_height_inches_textEdited(const QString &arg1)
{
    if(ui->lineEdit_height_inches->text().trimmed().toInt() <= 12)
    {

    }
    else
    {
        ui->lineEdit_height_inches->clear();
    }
}

void Home_Screen::on_lineEdit_reg_type_returnPressed()
{

}

void Home_Screen::on_lineEdit_reg_breadth_inche_returnPressed()
{
    //    ui->comboBox_reg_owner->setFocus();
    ui->lineEdit_reg_opening_balance->setFocus();
}

void Home_Screen::on_lineEdit_reg_length_inche_returnPressed()
{
    ui->lineEdit_reg_breadth->setFocus();
}

void Home_Screen::on_lineEdit_reg_opening_balance_returnPressed()
{
    if(ui->lineEdit_reg_opening_balance->text().toInt() >= 0)
    {
        ui->radioButton_reg_bal_pending->show();
        ui->radioButton_reg_bal_advance->show();
        ui->label_bal_type_title->show();

        ui->radioButton_reg_bal_pending->setFocus();
    }
}

void Home_Screen::on_pushButton_initial_config_save_clicked()
{

    gstropen_bull_reading = ui->lineEdit_bull_reading->text().trimmed();
    gstropen_diesel_reading = ui->lineEdit_diesel->text().trimmed();
    gstropen_eb_reading = ui->lineEdit_eb_reading->text().trimmed();
    gstropen_gen_reading = ui->lineEdit_generator_reading->text().trimmed();

    QString closing_bale="0";

    if(gstrday_no.toInt() == 1)
    {
        closing_bale = "0";
        gstrday_open_bale = "0";
    }
    else
    {
        QSqlQuery query;
        if(databaseObj->selectQuery("select max(closing_bale_balance) from day_master where status='0'",query))
        {
            if(query.next())
                closing_bale = query.value(0).toString();
            else
                closing_bale = "0";
        }
        qDebug()<<"closing_bale_balance ===>>>"<<closing_bale;

    }

    qDebug()<<"closing_bale_balance ===>>>"<<closing_bale;
    qDebug()<<"gstrday_open_bale ===>>>"<<gstrday_open_bale;

    if(databaseObj->executeCommand("INSERT INTO day_master(day_no,open_date,open_time,status,open_user_id,open_bull_reading,open_gen_reading,open_eb_reading,open_diesel_reading,opening_bale_balance,closing_bale_balance) VALUES ('"+gstrday_no+"','"+QDate::currentDate().toString("dd-MM-yyyy")+"','"+QTime::currentTime().toString("hh:mm:ss")+"','1','"+gstr_Users_server_id+"','"+gstropen_bull_reading+"','"+gstropen_gen_reading+"','"+gstropen_eb_reading+"','"+gstropen_diesel_reading+"','"+gstrday_open_bale+"','0')"))
    {
        ui->groupBox_initial_config->hide();
        ui->groupBox_initial_config->lower();
        //        call_Home_Screen();
        ui->lineEdit_vehicle_number->setFocus();
        day_shift();

        this->close();

        Staff_CashObj->from_day_open = true;
        Staff_CashObj->call_Staff_Cash();
        Staff_CashObj->on_pushButton_from_clicked();
        Staff_CashObj->show();


//        Staff_CashObj->from_day_open = true;
//        Staff_CashObj->call_Staff_Cash();
//        Staff_CashObj->show();

        isDay_Open = true;
        //        return;
    }

}

void Home_Screen::on_lineEdit_vehicle_number_textEdited(const QString &arg1)
{
    ui->lineEdit_vehicle_number->setText(arg1.toUpper());
//    if(ui->lineEdit_vehicle_number->text().size()==0)
//    {
//#if(SDK75)
//        g_ccmainObj->setKeypadMode(ClanCor::eKeypadMode_ALPHABETS_CAPS);
//        g_ccmainObj->setKeypadModeLock(false);
//#endif
//    }

//    if(ui->lineEdit_vehicle_number->text().size()==2)
//    {
//#if(SDK75)
//        g_ccmainObj->setKeypadMode(ClanCor::eKeypadMode_NUMERIC);
//        g_ccmainObj->setKeypadModeLock(false);
//#endif
//    }

//    if(ui->lineEdit_vehicle_number->text().size()==4)
//    {
//#if(SDK75)
//        g_ccmainObj->setKeypadMode(ClanCor::eKeypadMode_ALPHABETS_CAPS);
//        g_ccmainObj->setKeypadModeLock(false);
//#endif
//    }

//    if(ui->lineEdit_vehicle_number->text().size()==6)
//    {
//#if(SDK75)
//        g_ccmainObj->setKeypadMode(ClanCor::eKeypadMode_NUMERIC);
//        g_ccmainObj->setKeypadModeLock(false);
//#endif
//    }
}

void Home_Screen::on_lineEdit_height_textEdited(const QString &arg1)
{
    if(ui->lineEdit_height->text().trimmed().toInt() <= 12)
    {

    }
    else
    {
        ui->lineEdit_height->clear();
    }
}
