#include "settings.h"
#include "ui_settings.h"

#include <QDebug>
#include <QInputDialog>

#include <global.h>
using namespace Global;

Settings::Settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Settings)
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

    scroll=new QScrollArea(ui->groupBox);
    scroll->setWidget(ui->verticalLayoutWidget);
    scroll->move(10,30);
    scroll->setFixedSize(300,150);//160
    scroll->setFocusPolicy(Qt::NoFocus);
    scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

Settings::~Settings()
{
    delete ui;
}

void Settings::call_settings()
{
    ui->pushButton_App_name->hide();
    ui->pushButton_Bill_Title->hide();
    ui->pushButton_device_name->hide();
    ui->pushButton_server_config->hide();
//    ui->pushButton_user_master->hide();
    scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    ui->groupBox->show();
    ui->groupBox->raise();
    ui->groupBox_Configuration->hide();

    ui->pushButton_user_master->hide();
    ui->pushButton_customer_master->hide();

    ui->pushButton_device_setting->setFocus();

    if(isDefaultAdmin)
    {
        //! device name
        QSqlQuery query;
        if(databaseObj->selectQuery("select device_name from configuration_master",query))
        {
            if(query.next())
            {
                gstrDeviceName = query.value(0).toString();
                qDebug()<<"gstrDeviceName ===>>>"<<gstrDeviceName;
            }
            //! ----------------- Device Name ---------------------
            if(ui->pushButton_device_name->isVisible())
            {
                if(gstrDeviceName.isEmpty())
                {
                    QInputDialog inputDialog;
                    QFont font;
                    font.setFamily("DejaVu Sans Mono");
                    font.setPointSize(14);
                    //            inputDialog.setTextValue();
                    inputDialog.setInputMode(QInputDialog::TextInput);
                    inputDialog.setWindowTitle("Input");
                    //                inputDialog.set
                    inputDialog.setLabelText("Enter The Device Name:");
                    inputDialog.setFont(font);
                    inputDialog.move(25,50);
                    inputDialog.setWindowFlags(Qt::FramelessWindowHint);
                    bool ok;
                    ui->verticalLayoutWidget->hide();
                    scroll->hide();
                    ok = inputDialog.exec();

                    if(ok && !inputDialog.textValue().isEmpty())
                    {
                        if(databaseObj->executeCommand("UPDATE configuration_master set device_name='"+inputDialog.textValue()+"';"))
                        {
                            databaseObj->con.commit();
                            ui->verticalLayoutWidget->show();
                            scroll->show();
                        }
                        ui->pushButton_App_name->setFocus();
                    }
                    else
                    {
                        this->hide();
                        loginObj->show();
                        loginObj->call_login();
                        return;
                    }
                }
            }
        }

        //! app name
        query.clear();
        if(ui->pushButton_App_name->isVisible())
        {
        if(databaseObj->selectQuery("select app_name from configuration_master",query))
            {
                if(query.next())
                {
                    gstrAppName = query.value(0).toString();
                    qDebug()<<"gstrAppName ===>>>"<<gstrAppName;
                }
                if(gstrAppName.isEmpty())
                {
                    QInputDialog inputDialog;
                    QFont font;
                    font.setFamily("DejaVu Sans Mono");
                    font.setPointSize(14);
                    inputDialog.setInputMode(QInputDialog::TextInput);
                    inputDialog.setWindowTitle("Input");
                    inputDialog.setLabelText("Enter The App Name:");
                    inputDialog.setFont(font);
                    inputDialog.move(25,50);
                    inputDialog.setWindowFlags(Qt::FramelessWindowHint);
                    bool ok;
                    ui->verticalLayoutWidget->hide();
                    scroll->hide();
                    ok = inputDialog.exec();

                    if(ok && !inputDialog.textValue().isEmpty())
                    {
                        if(databaseObj->executeCommand("UPDATE configuration_master set app_name='"+inputDialog.textValue()+"';"))
                        {
                            databaseObj->con.commit();
                            ui->verticalLayoutWidget->show();
                            scroll->show();
                        }
                        ui->pushButton_App_name->setFocus();
                    }
                    else
                    {
                        this->hide();
                        loginObj->show();
                        loginObj->call_login();
                        return;
                    }
                }
            }
        }
    }

}

void Settings::keyPressEvent(QKeyEvent *ke)
{
    if(ke->key()== Qt::Key_F1)
    {
        on_pushButton_settings_back_clicked();
    }
    if(ke->key() == Qt::Key_Escape)
    {
        if(ui->groupBox_Configuration->isVisible())
        {
            ui->groupBox_Configuration->hide();
            ui->groupBox->show();
            ui->groupBox->raise();
            ui->pushButton_server_config->setFocus();
            return;
        }
        on_pushButton_settings_back_clicked();
    }
}

void Settings::on_pushButton_server_config_clicked()
{
    QString tmpstrservername;
    QSqlQuery qry;
    if(databaseObj->selectQuery("select domain_name from configuration_master",qry))
    {
        if(qry.next())
        {
            if(qry.value(0).toString().trimmed().isEmpty())
                tmpstrservername="http://";
            else
                tmpstrservername=qry.value(0).toString();
        }
        else
            tmpstrservername="http://";
    }

    ui->lineEdit_domain_name->setText(tmpstrservername);
    ui->lineEdit_domain_name->setFocus();

    ui->groupBox->hide();
    ui->groupBox_Configuration->show();
    ui->groupBox_Configuration->raise();
    ui->groupBox_Configuration->move(0,0);
    ui->lineEdit_domain_name->setFocus();

}

void Settings::on_lineEdit_domain_name_returnPressed()
{
    if(!ui->lineEdit_domain_name->text().isEmpty())
    {
        gstrServerName=ui->lineEdit_domain_name->text().trimmed();
        if(databaseObj->executeCommand("update configuration_master set domain_name='"+ui->lineEdit_domain_name->text().trimmed()+"'"))
        {
            qDebug()<<"saved for configuration_master last_bill_no ===>>>";
            databaseObj->con.commit();

#if(SDK75)
            int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"Saved Successfully",16,14);
#endif

        }
        call_settings();
    }
}

void Settings::on_pushButton_settings_back_clicked()
{
    this->hide();
    menuObj->show();
    menuObj->call_menu();
}

void Settings::on_pushButton_App_name_clicked()
{

    //! app name
    QSqlQuery query;
    query.clear();
    if(databaseObj->selectQuery("select app_name from configuration_master",query))
    {
        if(query.next())
        {
            gstrAppName = query.value(0).toString();
            qDebug()<<"gstrAppName ===>>>"<<gstrAppName;
        }
        //        if(gstrAppName.isEmpty())
        {
            QInputDialog inputDialog;
            QFont font;
            font.setFamily("DejaVu Sans Mono");
            font.setPointSize(14);
            inputDialog.setInputMode(QInputDialog::TextInput);
            inputDialog.setTextValue(gstrAppName);
            inputDialog.setWindowTitle("Input");
            inputDialog.setLabelText("Enter The App Name:");
            inputDialog.setFont(font);
            inputDialog.move(25,50);
            inputDialog.setWindowFlags(Qt::FramelessWindowHint);
            bool ok;
            ui->verticalLayoutWidget->hide();
            scroll->hide();
            ok = inputDialog.exec();

            if(ok && !inputDialog.textValue().isEmpty())
            {
                if(databaseObj->executeCommand("UPDATE configuration_master set app_name='"+inputDialog.textValue()+"';"))
                {
                    databaseObj->con.commit();
                    ui->verticalLayoutWidget->show();
                    scroll->show();
                }
                ui->pushButton_App_name->setFocus();
            }
            ui->verticalLayoutWidget->show();
            scroll->show();
            //            else
            //            {
            //                this->hide();
            //                loginObj->show();
            //                loginObj->call_login();
            //                return;
            //            }
        }
    }



}

void Settings::on_pushButton_device_name_clicked()
{

    //! device name

    QSqlQuery query;
    if(databaseObj->selectQuery("select device_name from configuration_master",query))
    {
        if(query.next())
        {
            gstrDeviceName = query.value(0).toString();
            qDebug()<<"gstrDeviceName ===>>>"<<gstrDeviceName;
        }
        //        if(gstrDeviceName.isEmpty())
        {
            QInputDialog inputDialog;
            QFont font;
            font.setFamily("DejaVu Sans Mono");
            font.setPointSize(14);
            inputDialog.setTextValue(gstrDeviceName);
            inputDialog.setInputMode(QInputDialog::TextInput);
            inputDialog.setWindowTitle("Input");
            inputDialog.setLabelText("Enter The Device Name:");
            inputDialog.setFont(font);
            inputDialog.move(25,50);
            inputDialog.setWindowFlags(Qt::FramelessWindowHint);
            bool ok;
            ui->verticalLayoutWidget->hide();
            scroll->hide();
            ok = inputDialog.exec();

            if(ok && !inputDialog.textValue().isEmpty())
            {
                if(databaseObj->executeCommand("UPDATE configuration_master set device_name='"+inputDialog.textValue()+"';"))
                {
                    databaseObj->con.commit();
                    ui->verticalLayoutWidget->show();
                    scroll->show();
                }
                ui->pushButton_device_name->setFocus();
            }
            ui->verticalLayoutWidget->show();
            scroll->show();
            //            else
            //            {
            //                this->hide();
            //                loginObj->show();
            //                loginObj->call_login();
            //                return;
            //            }
        }
    }
}

void Settings::on_pushButton_Bill_Title_clicked()
{
    //! bill name
    QSqlQuery query;
    if(databaseObj->selectQuery("select bill_type from configuration_master",query))
    {
        if(query.next())
        {
            gstrBillName = query.value(0).toString();
            qDebug()<<"gstrBillName ===>>>"<<gstrBillName;
        }
        //        if(gstrDeviceName.isEmpty())
        {
            //            QInputDialog inputDialog;
            QFont font;
            font.setFamily("DejaVu Sans Mono");
            font.setPointSize(14);

            inputDialog_bill_title.setInputMode(QInputDialog::TextInput);
            inputDialog_bill_title.setTextValue(gstrBillName);
            inputDialog_bill_title.setWindowTitle("Input");
            inputDialog_bill_title.setLabelText("Enter The Bill Title:");
            inputDialog_bill_title.setFont(font);
            //            inputDialog_bill_title.setStyleSheet("background-color: rgb(183, 255, 251);");
            inputDialog_bill_title.move(25,50);
            QObject::connect(&inputDialog_bill_title,SIGNAL(textValueChanged(QString)),this,SLOT(bill_title_entry(QString)));
            inputDialog_bill_title.setWindowFlags(Qt::FramelessWindowHint);
            bool ok;
            ok = inputDialog_bill_title.exec();

            if(ok && !inputDialog_bill_title.textValue().isEmpty())
            {
                if(databaseObj->executeCommand("UPDATE configuration_master set bill_type='"+inputDialog_bill_title.textValue()+"';"))
                {
                    databaseObj->con.commit();
                }
                ui->pushButton_device_name->setFocus();
            }
            //            else
            //            {
            //                this->hide();
            //                loginObj->show();
            //                loginObj->call_login();
            //                return;
            //            }
        }
    }
}

void Settings::bill_title_entry(QString str)
{
    qDebug()<<"bill_title_entry ===>>>"<< str;
    if(str.size() > 5)
    {
        inputDialog_bill_title.setTextValue(str.left(5));
    }
}

void Settings::on_pushButton_printer_settings_clicked()
{
    this->hide();
    PrinterSettingsObj = new PrinterSettings;
    PrinterSettingsObj->show();
    PrinterSettingsObj->call_PrinterSettings();
}

void Settings::on_pushButton_device_setting_clicked()
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
#endif
}

void Settings::callMenu()
{
    if(gstrDeviceUdId.isEmpty())
    {
#if(SDK75)
        g_ccmainObj->messagebox(this,"Status",eMessageType_Information,"Device Details\nNot Availabe.!");
        ui->pushButton_device_setting->setFocus();
//        show();
        return;
#endif
    }
    show();
    ui->pushButton_device_setting->setFocus();
}


void Settings::on_pushButton_save_clicked()
{
    on_lineEdit_domain_name_returnPressed();
}

void Settings::on_pushButton_user_master_clicked()
{
    this->close();
    Add_UserObj = new Add_User;
    Add_UserObj->call_Add_User();
    Add_UserObj->show();
}

void Settings::on_pushButton_customer_master_clicked()
{
    this->close();
    Customer_MasterObj = new Customer_Master;
    Customer_MasterObj->call_Customer_Master();
    Customer_MasterObj->show();
}
