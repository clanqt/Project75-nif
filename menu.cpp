#include "menu.h"
#include "ui_menu.h"
#include <QXmlStreamReader>
#include <QMessageBox>
#include <global.h>
#include <QFormLayout>
#include <QLabel>
#include <QDialogButtonBox>

#include "QtSvg/QSvgGenerator"
#include "QtSvg/QSvgRenderer"
#include <QPainter>
using namespace Global;

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
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
    //    move(0,0);
    setFixedSize(320,240);
    ui->label_info->hide();
    ui->label_info->lower();
    //    Current_Uploading_RowId = "";


    scroll = new QScrollArea(ui->groupBox);
    scroll->setWidget(ui->gridLayoutWidget);
    scroll->move(0,30);
    scroll->setFixedSize(320,150);//160
    scroll->setFocusPolicy(Qt::NoFocus);
    scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}

Menu::~Menu()
{
    delete ui;
}

void Menu::call_menu()
{
    ui->pushButton_device_setting->hide();
    ui->groupBox_download->hide();
    ui->label_info->hide();
    ui->label_info->lower();
    ui->groupBox->show();
    ui->groupBox->raise();

    ui->pushButton_download->hide();
    ui->pushButton_upload->hide();
    ui->pushButton_Other_batch_close->hide();
    ui->pushButton_Shift_Close->hide();

    ui->pushButton_Reports->show();
    ui->pushButton_Day_Close->show();
    ui->pushButton_diesel->show();
    ui->pushButton_batch_config->show();
    ui->pushButton_input_config->show();
    ui->pushButton_master_config->show();
    ui->pushButton_rate_config->show();
    ui->pushButton_Configuration->show();
    ui->pushButton_Day_Open->show();
    ui->pushButton_Reset_Data->show();
    ui->pushButton_device_setting->show();

    ui->pushButton_Day_Close->setEnabled(true);
    ui->pushButton_Day_Open->setEnabled(true);
    ui->pushButton_Data_transfer->show();

    ui->pushButton_Reports->setEnabled(true);
    ui->pushButton_Day_Open->setEnabled(true);
    ui->pushButton_Day_Close->setEnabled(true);
    ui->pushButton_diesel->setEnabled(true);
    ui->pushButton_batch_config->setEnabled(true);
    ui->pushButton_purchase->setEnabled(true);
    ui->pushButton_payment->setEnabled(true);
    ui->pushButton_diesel->setEnabled(true);
    ui->pushButton_Reports->setEnabled(true);
    ui->pushButton_master_config->setEnabled(true);
    ui->pushButton_input_config->setEnabled(true);
    ui->pushButton_device_setting->setEnabled(true);



    if(gstrUserName.contains("mcadmin",Qt::CaseInsensitive))
    {
        ui->pushButton_Reports->setEnabled(false);
        ui->pushButton_Day_Open->setEnabled(false);
        ui->pushButton_Day_Close->setEnabled(false);
        ui->pushButton_diesel->setEnabled(false);
        ui->pushButton_batch_config->setEnabled(false);
        ui->pushButton_purchase->setEnabled(false);
        ui->pushButton_payment->setEnabled(false);
        ui->pushButton_diesel->setEnabled(false);
        ui->pushButton_Reports->setEnabled(false);



    }


    if(gstrUserType.toInt() == 0)
    {
        ui->pushButton_input_config->hide();
        ui->pushButton_Day_Open->hide();
        ui->pushButton_Day_Close->hide();
        ui->pushButton_Configuration->hide();
        ui->pushButton_batch_config->hide();
        ui->pushButton_rate_config->hide();
        ui->pushButton_master_config->hide();
        ui->pushButton_Data_transfer->hide();
        ui->pushButton_Reset_Data->hide();
        ui->pushButton_device_setting->hide();
    }
    if(gstrUserType.toInt() == 1)
    {
        ui->pushButton_master_config->setEnabled(false);
        ui->pushButton_input_config->setEnabled(false);
        ui->pushButton_Data_transfer->hide();
        ui->pushButton_Reset_Data->hide();
        ui->pushButton_device_setting->hide();
    }
    if(gstrUserType.toInt() == 2)
    {
        ui->pushButton_Day_Close->setEnabled(false);
        ui->pushButton_Day_Close->setEnabled(false);
        ui->pushButton_Reset_Data->show();
        ui->pushButton_device_setting->show();
    }



    ui->groupBox->move(0,0);
    ui->groupBox->setDisabled(false);
    company_or_other = 9;

    //    ui->groupBox_Configuration->hide();
    //    ui->groupBox_Configuration->lower();
    //    ui->groupBox_Configuration->move(0,300);
    //    ui->groupBox_Configuration->setDisabled(true);
    //    QSqlQuery uid_qur;
    //    if(databaseObj->selectQuery("select configuration_master.uid from configuration_master",uid_qur))
    //    {
    //        if(uid_qur.next())
    //        {
    //            UdId = uid_qur.value(0).toString();
    //            qDebug()<<"UdId details ===>>>"<<UdId;
    //            gstrDeviceUdId = gstrDeviceUdId;
    //        }
    //    }


    if(gstrUserType.toInt() == 0)
        ui->pushButton_diesel->setFocus();
    if(gstrUserType.toInt() == 1)
        ui->pushButton_batch_config->setFocus();
    if(gstrUserType.toInt() == 2)
        ui->pushButton_master_config->setFocus();

    scroll->scroll(0,0);

#if(SDK75)
    //        g_ccmainObj->setKeypadModeLock(false);
#endif

}

void Menu::keyPressEvent(QKeyEvent *ke)
{
    if(ke->key()== Qt::Key_Escape)
    {
        if(ui->groupBox->isVisible())
        {

#if(NativeCompile)
            QMessageBox gMsg_box;
            QFont gFont;
            gFont.setFamily("DejaVu Sans Mono");
            gFont.setPointSize(12);
            gMsg_box.setFont(gFont);
            gMsg_box.setParent(this);

            if(gMsg_box.question(this, "Status","Do You Want\nTo Logout?",QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes)
            {
                qDebug()<<"logout ===>>>";

                if(databaseObj->executeCommand("update device_login_master set logout_time='"+QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss")+"', upload_logout='0' where id_user='"+gstr_Users_server_id+"'and user_name='"+gstrUserName+"'"))
                {
                    qDebug()<<"device_login_master logout saved ===>>>";
                }

                this->close();
                loginObj->show();
                loginObj->call_login();
            }
            else
            {
                qDebug()<<"stay login ===>>>";
                if(gstrUserType.toInt() != 0)
                    ui->pushButton_master_config->setFocus();
                else
                    ui->pushButton_batch_config->setFocus();
            }
#endif


#if(SDK75)
            int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Error,"Do You Want\nTo Logout?",16,14,"YES","NO");
            if(ret==1)
            {
                if(databaseObj->executeCommand("update device_login_master set logout_time='"+QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss")+"', upload_logout='0' where id_user='"+gstr_Users_server_id+"'and user_name='"+gstrUserName+"'"))
                {
                    qDebug()<<"device_login_master logout saved ===>>>";
                }
                this->close();
                loginObj->show();
                loginObj->call_login();
            }
            else
            {
                if(gstrUserType.toInt() != 0)
                    ui->pushButton_master_config->setFocus();
                else
                    ui->pushButton_batch_config->setFocus();
            }
#endif
        }
    }
    if(ke->key()== Qt::Key_F1)
    {
        //        if(gstrUserName.contains("mcadmin"))
        //        {

        //        }
        //        else
        //        {
        //            this->close();
        //            Process_SelectionObj->call_Process_Selection();
        //            Process_SelectionObj->show();
        //        }
    }
}

void Menu::on_pushButton_device_setting_clicked()
{
#if(SDK75)
//    this->hide();
//    Device_Menu *Device_Menu_Obj1 = new Device_Menu;
//    Device_Menu_Obj1->show();
//    QObject::connect(Device_Menu_Obj1,SIGNAL(Device_Menu_Exit()),this,SLOT(callMenu()));
//    Device_Menu_Obj1->call_Device_Settings(this);

    ui->groupBox->setDisabled(true);
    QEventLoop loop;
    QProcess process;
    process.setProcessChannelMode(QProcess::MergedChannels);
    QObject::connect(&process, SIGNAL(finished(int,QProcess::ExitStatus)),&loop,SLOT(quit()));
    QObject::connect(&process, SIGNAL(finished(int)),&loop,SLOT(quit()));
    QObject::connect(&process,SIGNAL(error(QProcess::ProcessError)),&loop,SLOT(quit()));
    QString processname = "/usr/bin/App_Settings";
    qDebug()<<"processname"<<processname;
    process.start(processname);
    loop.exec();
    if (process.state() == QProcess::Running )
    {
        process.kill();
    }
    else
    {
    }
    QString r_strOutput = process.readAllStandardOutput();
    qDebug()<<"output"<<r_strOutput;
    process.reset();
    process.close();
    ui->groupBox->setDisabled(false);
    ui->pushButton_device_setting->setFocus();
#endif

}

void Menu::on_pushButton_download_clicked()
{
    qDebug()<<"gstrServerName 1===>>>"<<gstrServerName;
    if(gstrServerName.isEmpty())
    {
#if(SDK75)
        g_ccmainObj->messagebox(this,"Status",eMessageType_Error,"Server Domain\nNot Configured.");
        ui->pushButton_download->setFocus();
        return;
#endif
    }




    //#if(SDK75)
    //gprs:
    //    if(g_ccmainObj->isGprs() || isNetwork())
    //    {
    //    }
    //    else
    //    {
    //        ui->label_info->hide();
    //        int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Error,"Network Error",16,14,"Retry","Quit");
    //        if(ret==1)
    //            goto gprs;
    //        else if(ret==2)
    //        {
    //            return;
    //            ui->pushButton_download->setFocus();
    //        }
    //    }
    //#endif

    //    qDebug()<<"gstrServerName ===>>>"<<gstrServerName;

    //    convert_header = false,convert_footer = false;

    //    Download_in_Process = Device_Status;

    //    ui->label_info->setText("Downloading Devide Status...");
    //    ui->label_info->show();
    //    ui->label_info->raise();
    //    Server_Get_PostObj->http_get_requester(gstrServerName+"status/uid/"+gstrmachineId);

}

void Menu::http_get_server_reply(QString rpy)
{
    qDebug()<<"http_get_server_reply in menu ===>>>"<<rpy;
}

void Menu::callMenu()
{
    call_menu();
    if(gstrDeviceUdId.isEmpty())
    {
#if(SDK75)
        g_ccmainObj->messagebox(this,"Status",eMessageType_Information,"Device Details\nNot Availabe.!");
        ui->pushButton_download->setFocus();
        //        show();
        return;
#endif
    }
    show();
    ui->pushButton_download->setFocus();
}

void Menu::on_pushButton_Configuration_clicked()
{
    this->hide();
    SettingsObj = new Settings;
    SettingsObj->show();
    SettingsObj->call_settings();
}

void Menu::on_pushButton_rate_config_clicked()
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
    if(last_bull_meter_reading.isEmpty() || last_gen_meter_reading.isEmpty() || last_eb_meter_reading.isEmpty() || last_deisel_reading.isEmpty() || last_husk_per_cft.isEmpty() || last_husk_per_bale.isEmpty())
    {
#if(SDK75)
        g_ccmainObj->messagebox(this,"Day close",eMessageType_Information,"Input Configuration\nNot Completed",14);
        ui->pushButton_rate_config->setFocus();
        return;
#endif
    }



    if(!Home_ScreenObj->isDayOpen())
    {
        this->close();
#if(SDK75)
        g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
        Rate_ConfigObj = new Rate_Config;
        Rate_ConfigObj->call_Rate_Config();
        Rate_ConfigObj->show();
    }
    else
    {
#if(SDK75)
        g_ccmainObj->messagebox(this,"Day close",eMessageType_Information,"Day Not Closed.");
#endif
        ui->pushButton_rate_config->setFocus();
    }
}

void Menu::on_pushButton_Day_Close_clicked()
{
    qDebug()<<"on_pushButton_Day_Close_clicked ===>>>";
    if(isDay_Open)
    {
        qDebug()<<"on_pushButton_Day_Close_clicked 1 ===>>>";
        QSqlQuery query;
        QString str_batch_order_name,str_batch_order_no;
        if(databaseObj->selectQuery("select count(*) from production_batch_order",query))
        {
            if(query.next())
            {
                if(query.value(0).toInt() >= 0)
                {
                    this->close();
                    Day_CloseObj->call_Day_Close();
                    Day_CloseObj->show();
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
                        ui->pushButton_Day_Close->setFocus();
                        return;
                    }
                    else
                    {

                    }
#endif

#if(SDK75)
                    int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"Production Batch\nNot Available.",16,14);
                    ui->pushButton_Day_Close->setFocus();
#endif

                }
            }
        }

        //        Home_ScreenObj->close_day(this);
        //        ui->pushButton_Day_Close->setFocus();
    }
    else
    {
#if(SDK75)

        g_ccmainObj->messagebox(this,"Day close",eMessageType_Information,"Day already closed.");
#endif
        ui->pushButton_Day_Close->setFocus();
    }
}

void Menu::on_pushButton_Shift_Close_clicked()
{
    if(isShift_Open)
    {

        company_or_other = 0;

        this->close();
        //        Batch_CloseObj = new Batch_Close;
        Batch_CloseObj->call_Batch_Close();
        Batch_CloseObj->show();

        //        Home_ScreenObj->close_shift(this);
        //        ui->pushButton_Shift_Close->setFocus();

    }
    else
    {
#if(SDK75)

        g_ccmainObj->messagebox(this,"Shift close",eMessageType_Information,"Company Batch already closed.");
#endif
        ui->pushButton_Shift_Close->setFocus();
    }
}

void Menu::on_pushButton_Other_batch_close_clicked()
{
    if(isShift_Open_other)
    {
        company_or_other = 1;

        this->close();
        Batch_CloseObj = new Batch_Close;
        Batch_CloseObj->call_Batch_Close();
        Batch_CloseObj->show();


        //        Home_ScreenObj->close_shift_other(this);
        //        ui->pushButton_Other_batch_close->setFocus();
    }
    else
    {
#if(SDK75)

        g_ccmainObj->messagebox(this,"Shift close",eMessageType_Information,"Other Batch already closed.");
#endif
        ui->pushButton_Other_batch_close->setFocus();
    }
}

void Menu::on_pushButton_batch_config_clicked()
{
    if(Home_ScreenObj->isDayOpen())
    {
        this->close();
        Batch_ConfigurationObj->from_home_screen = false;
        Batch_ConfigurationObj->call_Batch_Configuration();
        Batch_ConfigurationObj->show();
    }
    else
    {
#if(SDK75)
        g_ccmainObj->messagebox(this,"Day close",eMessageType_Information,"Day Is Closed");
#endif
        ui->pushButton_batch_config->setFocus();
    }
}

void Menu::on_pushButton_master_config_clicked()
{
    this->close();
    Master_Config_MenuObj = new Master_Config_Menu;
    Master_Config_MenuObj->call_Master_Config_Menu();
    Master_Config_MenuObj->show();
}

void Menu::on_pushButton_input_config_clicked()
{
    QSqlQuery check_user;
    if(databaseObj->selectQuery("select count(*) from user_master where user_master.user_type='1'",check_user))
    {
        if(check_user.next())
        {
            if(check_user.value(0).toInt() > 0)
            {

            }
            else
            {
#if(SDK75)
                g_ccmainObj->messagebox(this,"Day close",eMessageType_Information,"Manager Is\nnot Created");
                ui->pushButton_input_config->setFocus();
#endif
            }
        }
    }

    if(!Home_ScreenObj->isDayOpen())
    {
        this->close();
#if(SDK75)
        g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
        Input_ConfigObj = new Input_Config;
        Input_ConfigObj->call_Input_Config();
        Input_ConfigObj->show();
    }
    else
    {
#if(SDK75)
        g_ccmainObj->messagebox(this,"Day close",eMessageType_Information,"Day Not Closed");
        ui->pushButton_input_config->setFocus();
#endif
    }

}

void Menu::on_pushButton_diesel_clicked()
{
    if(!gstrUserName.contains("mcadmin",Qt::CaseInsensitive))
    {
        if(Home_ScreenObj->isDayOpen())
        {
            this->close();
            Diesel_MaintananceObj = new Diesel_Maintanance;
            Diesel_MaintananceObj->call_Diesel_Maintanance();
            Diesel_MaintananceObj->show();
        }
        else
        {
#if(SDK75)
            g_ccmainObj->messagebox(this,"Day close",eMessageType_Information,"Day Is Closed");
#endif
            ui->pushButton_diesel->setFocus();
        }
    }
}

void Menu::on_pushButton_Reports_clicked()
{
    this->close();
    ReportObj = new Report;
    ReportObj->call_Report();
    ReportObj->show();
}

void Menu::on_pushButton_purchase_clicked()
{
    //    if(gstrUserType.toInt() == 0 || gstrUserType.toInt() == 2)
    //    {
    if(!Home_ScreenObj->isDayOpen())
    {
#if(NativeCompile)
        QMessageBox gMsg_box;
        QFont gFont;
        gFont.setFamily("DejaVu Sans Mono");
        gFont.setPointSize(12);
        gMsg_box.setFont(gFont);
        gMsg_box.setParent(this);

        if(gMsg_box.information(this, "Success","Day Not Opened.",QMessageBox::Ok) == QMessageBox::Ok)
        {
            return;
        }
#endif

#if(SDK75)
        int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Information,"Day Not Opened.",16,14);
        ui->pushButton_purchase->setFocus();
        return;
#endif


    }
    else
    {
        this->close();
        Home_ScreenObj->call_Home_Screen();
//        Home_ScreenObj->check_batch();
        Home_ScreenObj->day_shift();
        Home_ScreenObj->show();
    }
    //    }


}

void Menu::on_pushButton_payment_clicked()
{
    if(Home_ScreenObj->isDayOpen())
    {
        this->close();
//        PaymentObj = new Payment;
        PaymentObj->is_payment = true;
        PaymentObj->call_Payment();
        PaymentObj->show();
    }
    else
    {
#if(SDK75)
        g_ccmainObj->messagebox(this,"Day close",eMessageType_Information,"Day Is Closed");
#endif
        ui->pushButton_payment->setFocus();
    }
}

void Menu::on_pushButton_Day_Open_clicked()
{
    QSqlQuery check_user;
    if(databaseObj->selectQuery("select count(*) from user_master where user_master.user_type='1'",check_user))
    {
        if(check_user.next())
        {
            if(check_user.value(0).toInt() > 0)
            {

            }
            else
            {
#if(SDK75)
                g_ccmainObj->messagebox(this,"Day close",eMessageType_Information,"Manager Is\nnot Created");
                ui->pushButton_Day_Open->setFocus();
                return;
#endif
            }
        }
    }

    check_user.clear();
    if(databaseObj->selectQuery("select count(*) from user_master where user_master.user_type='0'",check_user))
    {
        if(check_user.next())
        {
            if(check_user.value(0).toInt() > 0)
            {

            }
            else
            {
#if(SDK75)
                g_ccmainObj->messagebox(this,"Day close",eMessageType_Information,"Operator Is\nnot Created");
                ui->pushButton_Day_Open->setFocus();
                return;
#endif
            }
        }
    }

    check_user.clear();
    if(databaseObj->selectQuery("select count(*) from user_master where user_master.user_type='2'",check_user))
    {
        if(check_user.next())
        {
            if(check_user.value(0).toInt() > 0)
            {

            }
            else
            {
#if(SDK75)
                g_ccmainObj->messagebox(this,"Day close",eMessageType_Information,"Owner Is\nnot Created");
                ui->pushButton_Day_Open->setFocus();
                return;
#endif
            }
        }
    }
    //*********************************************************************************
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

    if(last_bull_meter_reading.isEmpty() || last_gen_meter_reading.isEmpty() || last_eb_meter_reading.isEmpty() || last_deisel_reading.isEmpty() || last_husk_per_cft.isEmpty() || last_husk_per_bale.isEmpty())
    {
#if(SDK75)
        g_ccmainObj->messagebox(this,"Day close",eMessageType_Information,"Input Configuration\nNot Completed",14);
        ui->pushButton_Day_Open->setFocus();
        return;
#endif
    }
    //************************************************************************************
    QSqlQuery qur;
    if(databaseObj->selectQuery("select configuration_master.husk_per_cft,configuration_master.rate_of_cft,configuration_master.husk_per_bale,configuration_master.rate_of_husk,configuration_master.auto_rate_of_cft,configuration_master.auto_rate_of_husk,configuration_master.van_rate_of_cft,configuration_master.van_rate_of_husk from configuration_master",qur))
    {
        if(qur.next())
        {
            if(qur.value(0).toString().trimmed().isEmpty() || qur.value(1).toString().trimmed().isEmpty() || qur.value(2).toString().trimmed().isEmpty() || qur.value(3).toString().trimmed().isEmpty() || qur.value(4).toString().trimmed().isEmpty() || qur.value(5).toString().trimmed().isEmpty() || qur.value(6).toString().trimmed().isEmpty() || qur.value(7).toString().trimmed().isEmpty())
            {
#if(SDK75)
        g_ccmainObj->messagebox(this,"Day close",eMessageType_Information,"Rate Configuration\nNot Completed");
        ui->pushButton_Day_Open->setFocus();
        return;
#endif

            }
        }
    }
    //! #########################################

//#if(SDK75)
//            int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Critical,"Do You Want\nTo Open Day?",14,14,"YES","NO");
//            if(ret==1)
//            {

//            }
//            else
//            {
//                ui->pushButton_Day_Open->setFocus();
//                return;
//            }
//#endif



    if(!Home_ScreenObj->isDayOpen())
    {
        this->close();
        Home_ScreenObj->call_Home_Screen();
        if(Home_ScreenObj->check_batch())
        {
            Home_ScreenObj->day_shift();
            Home_ScreenObj->show();
        }
        else
        {

            this->close();
            Home_ScreenObj->hide();
            Batch_ConfigurationObj->from_home_screen = false;
            Batch_ConfigurationObj->call_Batch_Configuration();
            Batch_ConfigurationObj->show();
            Batch_ConfigurationObj->on_pushButton_Production_open_clicked();
        }
    }
    else
    {
#if(SDK75)
        g_ccmainObj->messagebox(this,"Day close",eMessageType_Information,"Day already\nOpened.");
        ui->pushButton_Day_Open->setFocus();
#endif
    }
}

void Menu::on_pushButton_Data_transfer_clicked()
{
    if(gstrUserType.toInt() == 2 || gstrUserName.contains("mcadmin",Qt::CaseInsensitive))
    {
        this->close();
        DataTransferObj = new DataTransfer;
        DataTransferObj->call_DataTransfer();
        DataTransferObj->show();
    }
}

void Menu::check_init_config()
{
    QSqlQuery qur;
    if(databaseObj->selectQuery("",qur))
    {

    }
}

void Menu::on_pushButton_Receipt_clicked()
{
    if(Home_ScreenObj->isDayOpen())
    {
//        this->close();
////        PaymentObj = new Payment;
//        PaymentObj->is_payment = false;
//        PaymentObj->call_Payment();
//        PaymentObj->show();
        this->close();
        Staff_CashObj->call_Staff_Cash();
        Staff_CashObj->on_pushButton_from_clicked();
        Staff_CashObj->show();
    }
    else
    {
#if(SDK75)
        g_ccmainObj->messagebox(this,"Day close",eMessageType_Information,"Day Is Closed");
#endif
        ui->pushButton_payment->setFocus();
    }
}

void Menu::on_pushButton_Reset_Data_clicked()
{
#if(SDK75)
    int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Error,"Do You Want To\nReset All\n Transactions?",16,14,"YES","NO");
    if(ret==1)
    {
        //!yes
        QInputDialog inputDialog;
        QFont font;
        font.setFamily("DejaVu Sans Mono");
        font.setPointSize(14);
        inputDialog.setInputMode(QInputDialog::TextInput);
//        inputDialog.setTextValue(gstrAppName);
        inputDialog.setWindowTitle("Input");
        inputDialog.setTextEchoMode(QLineEdit::Password);
        inputDialog.setLabelText("Enter Owner Pasword.");
        inputDialog.setFont(font);
        inputDialog.move(25,50);
        inputDialog.setWindowFlags(Qt::FramelessWindowHint);


        bool ok;
        ok = inputDialog.exec();

        if(ok && !inputDialog.textValue().isEmpty())
        {
            QSqlQuery pass_qur;
            if(databaseObj->selectQuery("select * from user_master where user_master.user_name='"+gstrUserName+"' and user_master.user_type='2'",pass_qur))
            {
                if(pass_qur.next())
                {
                    if(pass_qur.value(3).toInt() == inputDialog.textValue().toInt())
                    {
                        //! delete data if password matches

                        QStringList delete_table_list;
                        delete_table_list << "cash_from_transaction" << "cash_to_transaction" << "company_batch_no" << "day_close" << "day_master" << "device_login_master" << "diesel_transaction" << "diesel_usage" << "employee_transaction" << "expense_transaction" << "other_batch_no" << "printer_master" << "production_batch_order" << "sqlite_sequence" << "transaction_master" << "van_batch_no";

                        qDebug()<<"table list to delete ===>>>"<<delete_table_list;

                        for(int i=0;i<delete_table_list.size();i++)
                        {
                            if(databaseObj->executeCommand("delete from "+delete_table_list.at(i)))
                            {
                                qDebug()<<delete_table_list.at(i)<<" is deleted ===>>>";
                            }
                        }

                        if(databaseObj->executeCommand("update user_master set aval_cash='0'"))
                        {
                            qDebug()<<"user avail cash made zero ===>>>";
                        }
                        if(databaseObj->executeCommand("update customer_master set balance='0', balance_type='0'"))
                        {
                            qDebug()<<"customer cash made zero ===>>>";
                        }
                        if(databaseObj->executeCommand("update employee_master set emp_balance='0', emp_balance_bale_rate='0', emp_balance_type='0'"))
                        {
                            qDebug()<<"customer cash made zero ===>>>";
                        }

                        if(databaseObj->executeCommand("update bunk_master set bunk_opening_balance='0', bunk_opening_balance_type='0'"))
                        {
                            qDebug()<<"bunk_master cash made zero ===>>>";
                        }

                        if(databaseObj->executeCommand("update configuration_master set last_bill_no='0', init_bull_reading='0', init_diesel_reading='0', init_eb_reading='0', init_gen_reading='0'"))
                        {
                            qDebug()<<"configuration_master bill_no";
                        }
                        int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"Transactions\nDeleted\nSuccessfully..!",16,14);
                        ui->label_info->show();
                        ui->label_info->raise();
                        ui->label_info->setText("Shuting Down Device..!");
                        g_ccmainObj->setBeep(eBeepType_LONG_BEEP);
                        system("poweroff");
                        ui->pushButton_Reset_Data->setFocus();
                    }
                    else
                    {
                        int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Error,"Wrong Password..!",16,14);
                        ui->pushButton_Reset_Data->setFocus();
                        return;
                    }
                }
            }
        }
        else
        {
            ui->pushButton_Reset_Data->setFocus();
            return;
        }

    }
    else
    {
        ui->pushButton_Reset_Data->setFocus();
    }
    ui->pushButton_Reset_Data->setFocus();
#endif

}

void Menu::on_pushButton_Void_Last_Bill_clicked()
{
    if(Home_ScreenObj->isDayOpen())
    {
        this->close();
        Void_Last_BIllObj = new Void_Last_BIll;
        Void_Last_BIllObj->call_Void_Last_BIll();
        Void_Last_BIllObj->show();
    }
    else
    {
#if(SDK75)
        g_ccmainObj->messagebox(this,"Day close",eMessageType_Information,"Day Is Closed");
#endif
        ui->pushButton_Void_Last_Bill->setFocus();
    }
}
