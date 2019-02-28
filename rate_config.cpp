#include "rate_config.h"
#include "ui_rate_config.h"

#include <QMessageBox>

#include <global.h>
using namespace Global;

Rate_Config::Rate_Config(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Rate_Config)
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

Rate_Config::~Rate_Config()
{
    delete ui;
}

void Rate_Config::call_Rate_Config()
{
//    ui->pushButton_RP_husk->hide();
//    ui->pushButton_HP_cft->setFocus();

    ui->verticalLayoutWidget->hide();
    ui->label_info->hide();

    ui->lineEdit_auto_cft->setEnabled(true);
    ui->lineEdit_auto_count->setEnabled(false);
    ui->lineEdit_company_cft->setEnabled(false);
    ui->lineEdit_company_count->setEnabled(false);
    ui->lineEdit_van_count->setEnabled(false);
    ui->lineEdit_van_rate->setEnabled(false);
    ui->pushButton_save->setEnabled(false);

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

    qDebug()<<"HP_cft ===>>>"<<HP_cft;
    qDebug()<<"HP_bale ===>>>"<<HP_bale;

    qDebug()<<"RP_cft ===>>>"<<RP_cft;
    qDebug()<<"RP_husk ===>>>"<<RP_husk;

    qDebug()<<"RP_cft_auto ===>>>"<<RP_cft_auto;
    qDebug()<<"RP_husk_auto ===>>>"<<RP_husk_auto;

    qDebug()<<"RP_cft_van ===>>>"<<RP_cft_van;
    qDebug()<<"RP_husk_van ===>>>"<<RP_husk_van;

    ui->lineEdit_company_cft->setText(RP_cft);
    ui->lineEdit_company_count->setText(RP_husk);

    ui->lineEdit_auto_cft->setText(RP_cft_auto);
    ui->lineEdit_auto_count->setText(RP_husk_auto);

    ui->lineEdit_van_rate->setText(RP_cft_van);
    ui->lineEdit_van_count->setText(RP_husk_van);


    ui->lineEdit_auto_cft->setFocus();





}

void Rate_Config::keyPressEvent(QKeyEvent *ke)
{
    if(ke->key()== Qt::Key_Escape)
    {
        on_pushButton_back_clicked();
    }
    if(ke->key()== Qt::Key_F5)
    {
        QInputDialog inputDialog;
        QFont font;
        font.setFamily("DejaVu Sans Mono");
        font.setPointSize(14);
        inputDialog.setInputMode(QInputDialog::TextInput);
        inputDialog.setTextValue(gstrAppName);
        inputDialog.setWindowTitle("Input");
        inputDialog.setLabelText("Enter SMS\nMobile Number:");
        inputDialog.setFont(font);
        inputDialog.move(25,50);
        inputDialog.setWindowFlags(Qt::FramelessWindowHint);

//            inputDialog.setTextValue(Home_ScreenObj->HP_cft);

        bool ok;
        ok = inputDialog.exec();

        if(ok && !inputDialog.textValue().isEmpty())
        {
            system(QString("echo "+inputDialog.textValue().trimmed()+" > /home/root/sms").toLatin1());
        }
        else
        {
            return;
        }
    }
}

void Rate_Config::on_pushButton_HP_cft_clicked()
{
    QInputDialog inputDialog;
    QFont font;
    font.setFamily("DejaVu Sans Mono");
    font.setPointSize(14);
    inputDialog.setInputMode(QInputDialog::TextInput);
    inputDialog.setTextValue(gstrAppName);
    inputDialog.setWindowTitle("Input");
    inputDialog.setLabelText("Enter The Husk_Per_CFT:");
    inputDialog.setFont(font);
    inputDialog.move(25,50);
    inputDialog.setWindowFlags(Qt::FramelessWindowHint);

    inputDialog.setTextValue(Home_ScreenObj->HP_cft);

    bool ok;
    ok = inputDialog.exec();

    if(ok && !inputDialog.textValue().isEmpty())
    {
        if(databaseObj->executeCommand("UPDATE configuration_master set husk_per_cft='"+inputDialog.textValue()+"';"))
        {
            databaseObj->con.commit();
        }
    }
}

void Rate_Config::on_pushButton_HP_bale_clicked()
{
    QInputDialog inputDialog;
    QFont font;
    font.setFamily("DejaVu Sans Mono");
    font.setPointSize(14);
    inputDialog.setInputMode(QInputDialog::TextInput);
    inputDialog.setTextValue(gstrAppName);
    inputDialog.setWindowTitle("Input");
    inputDialog.setLabelText("Enter The Husk_Per_Bale:");
    inputDialog.setFont(font);
    inputDialog.move(25,50);
    inputDialog.setWindowFlags(Qt::FramelessWindowHint);

    inputDialog.setTextValue(Home_ScreenObj->HP_bale);

    bool ok;
    ok = inputDialog.exec();

    if(ok && !inputDialog.textValue().isEmpty())
    {
        if(databaseObj->executeCommand("UPDATE configuration_master set husk_per_bale='"+inputDialog.textValue()+"';"))
        {
            databaseObj->con.commit();
        }
    }
}

void Rate_Config::on_pushButton_RP_cft_clicked()
{
    QInputDialog inputDialog;
    QFont font;
    font.setFamily("DejaVu Sans Mono");
    font.setPointSize(14);
    inputDialog.setInputMode(QInputDialog::TextInput);
    inputDialog.setTextValue(gstrAppName);
    inputDialog.setWindowTitle("Input");
    inputDialog.setLabelText("Enter The Rate_Per_CFT:");
    inputDialog.setFont(font);
    inputDialog.move(25,50);
    inputDialog.setWindowFlags(Qt::FramelessWindowHint);

    inputDialog.setTextValue(Home_ScreenObj->RP_cft);

    bool ok;
    ok = inputDialog.exec();

    if(ok && !inputDialog.textValue().isEmpty())
    {
        if(databaseObj->executeCommand("UPDATE configuration_master set rate_of_cft='"+inputDialog.textValue()+"';"))
        {
            databaseObj->con.commit();
        }
    }
}

void Rate_Config::on_pushButton_RP_husk_clicked()
{
    QInputDialog inputDialog;
    QFont font;
    font.setFamily("DejaVu Sans Mono");
    font.setPointSize(14);
    inputDialog.setInputMode(QInputDialog::TextInput);
    inputDialog.setTextValue(gstrAppName);
    inputDialog.setWindowTitle("Input");
    inputDialog.setLabelText("Enter The Rate_Per_CFT:");
    inputDialog.setFont(font);
    inputDialog.move(25,50);
    inputDialog.setWindowFlags(Qt::FramelessWindowHint);

    inputDialog.setTextValue(Home_ScreenObj->RP_husk);

    bool ok;
    ok = inputDialog.exec();

    if(ok && !inputDialog.textValue().isEmpty())
    {
        if(databaseObj->executeCommand("UPDATE configuration_master set rate_of_husk='"+inputDialog.textValue()+"';"))
        {
            databaseObj->con.commit();
        }
    }
}

void Rate_Config::on_pushButton_save_clicked()
{
    if(!ui->lineEdit_auto_cft->text().isEmpty() &&
            !ui->lineEdit_auto_count->text().isEmpty() &&
            !ui->lineEdit_company_cft->text().isEmpty() &&
            !ui->lineEdit_company_count->text().isEmpty() &&
            !ui->lineEdit_van_rate->text().isEmpty() &&
            !ui->lineEdit_van_rate->text().isEmpty())
    {
        if(databaseObj->executeCommand("update configuration_master set rate_of_cft='"+ui->lineEdit_company_cft->text().trimmed()+"',rate_of_husk='"+ui->lineEdit_company_count->text().trimmed()+"',auto_rate_of_cft='"+ui->lineEdit_auto_cft->text().trimmed()+"',auto_rate_of_husk='"+ui->lineEdit_auto_count->text().trimmed()+"',van_rate_of_cft='"+ui->lineEdit_van_rate->text().trimmed()+"',van_rate_of_husk='"+ui->lineEdit_van_count->text().trimmed()+"'"))
        {
#if(NativeCompile)
                QMessageBox gMsg_box;
                QFont gFont;
                gFont.setFamily("DejaVu Sans Mono");
                gFont.setPointSize(12);
                gMsg_box.setFont(gFont);
                gMsg_box.setParent(this);

                if(gMsg_box.information(this, "Success","Rate Configured Successfully..!",QMessageBox::Ok) == QMessageBox::Ok)
                {
                    on_pushButton_back_clicked();
                }
#endif

#if(SDK75)
                int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"Rate Configured Successfully..!",16,14);

                QFile sms("/opt/daemon_files/tower_value");
                QString tower;
                if(sms.open(QIODevice::ReadWrite))
                {
                    tower = sms.readAll().split(",").at(0);
                    tower = tower.remove("+CSQ: ");
                    qDebug()<<"tower level ===>>>"<<tower;
                }
                sms.close();

                if(tower.toInt() >=6 && tower.toInt() <= 10)
                {
//                    QFile number1("/opt/daemon_files/tower_value");
                    QString number;
//                    if(sms.open(QIODevice::ReadWrite))
//                    {
//                        number = sms.readAll();
//                    }
//                    number1.close();

                    QSqlQuery sms_number;
                    if(databaseObj->selectQuery("select user_mobile from user_master where user_type='2'",sms_number))
                    {
                        if(sms_number.next())
                        {
                            number = sms_number.value(0).toString();


                            QString send_msg = "gammu sendsms TEXT "+number+" -text \"Auto CFT     :Rs "+ui->lineEdit_auto_cft->text().trimmed()+"\nAuto Count   :Rs "+ui->lineEdit_auto_count->text().trimmed()+"\nCompany CFT  :Rs "+ui->lineEdit_company_cft->text().trimmed()+"\nCompany Count:Rs "+ui->lineEdit_company_count->text().trimmed()+"\nVan CFT      :Rs "+ui->lineEdit_van_rate->text().trimmed()+"\nVan Count    :Rs "+ui->lineEdit_van_count->text().trimmed()+"\"";
                            qDebug()<<"send_msg cmd ===>>>"<<send_msg;
                            execProcess(send_msg,"");
                            on_pushButton_back_clicked();
                        }
                    }


                }
                else
                {
                    int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"No Signal SMS\nSending Failed",16,14);
                    ui->pushButton_save->setFocus();
                    on_pushButton_back_clicked();
                }

#endif
        }
    }
}

void Rate_Config::on_lineEdit_auto_cft_returnPressed()
{
    if(!ui->lineEdit_auto_cft->text().isEmpty())
    {
        ui->lineEdit_auto_count->setEnabled(true);
        ui->lineEdit_auto_count->setFocus();
    }

}

void Rate_Config::on_lineEdit_auto_count_returnPressed()
{
    if(!ui->lineEdit_auto_count->text().isEmpty())
    {
        ui->lineEdit_company_cft->setEnabled(true);
        ui->lineEdit_company_cft->setFocus();
    }
}

void Rate_Config::on_lineEdit_company_cft_returnPressed()
{
    if(!ui->lineEdit_company_cft->text().isEmpty())
    {
        ui->lineEdit_company_count->setEnabled(true);
        ui->lineEdit_company_count->setFocus();
    }
}

void Rate_Config::on_lineEdit_company_count_returnPressed()
{
    if(!ui->lineEdit_company_count->text().isEmpty())
    {
        ui->lineEdit_van_rate->setEnabled(true);
        ui->lineEdit_van_rate->setFocus();
    }
}

void Rate_Config::on_lineEdit_van_rate_returnPressed()
{
    if(!ui->lineEdit_van_rate->text().isEmpty())
    {
        ui->lineEdit_van_count->setEnabled(true);
        ui->lineEdit_van_count->setFocus();
    }
}

void Rate_Config::on_lineEdit_van_count_returnPressed()
{
    if(!ui->lineEdit_van_count->text().isEmpty())
    {
        ui->pushButton_save->setEnabled(true);
        ui->pushButton_save->setFocus();
    }
}

void Rate_Config::on_pushButton_back_clicked()
{
    this->close();
    menuObj->call_menu();
    menuObj->show();
}

void Rate_Config::execProcess(QString ProcessName, QString Message)
{
    qDebug()<<"\r command ===>>>"<<ProcessName;
    QEventLoop loop;
    //    QProcess process;
    process.setProcessChannelMode(QProcess::MergedChannels);
    QObject::connect(&process, SIGNAL(finished(int,QProcess::ExitStatus)),&loop,SLOT(quit()));
    QObject::connect(&process, SIGNAL(finished(int)),&loop,SLOT(quit()));
    QObject::connect(&process,SIGNAL(error(QProcess::ProcessError)),&loop,SLOT(quit()));
    //    QObject::connect(&process,SIGNAL(stateChanged(QProcess::ProcessState)),this,SLOT(process_state()));

    ui->label_info->show();
    ui->label_info->raise();
    //    ui->label_status->setText((Message));
    process.start(ProcessName);
    qApp->processEvents();
    qApp->processEvents();


    bool returnBool = false;
    int s=0;
    while (returnBool == false)
    {
        s++;
        returnBool = process.waitForFinished(1000);

        QString stdout = process.readAllStandardOutput();
        qDebug()<<"process_state stdout ===>>>"<<stdout;

        if(ProcessName.contains("sendsms"))
        {
            if(stdout.contains("OK"))
            {
                process.kill();
                QMessageBox gMsg_box;
                QFont gFont;
                gFont.setFamily("DejaVu Sans Mono");
                gFont.setPointSize(16);
                gMsg_box.setFont(gFont);
                gMsg_box.setParent(this);

                if(gMsg_box.information(this, "Success","Message Send\nSuccessfully.",QMessageBox::Ok) == QMessageBox::Ok)
                {
                    ui->label_info->hide();
//                    call_MainWindow();
                }
            }

            if(stdout.contains("timeout"))
            {
                process.kill();
                QMessageBox gMsg_box;
                QFont gFont;
                gFont.setFamily("DejaVu Sans Mono");
                gFont.setPointSize(16);
                gMsg_box.setFont(gFont);
                gMsg_box.setParent(this);

                if(gMsg_box.information(this, "Success","Message Not Send.",QMessageBox::Ok) == QMessageBox::Ok)
                {
                    ui->label_info->hide();
//                    call_MainWindow();
                }
            }
        }
        if(ProcessName.contains("getussd"))
        {

        }

        if(s>59)
        {
            QMessageBox gMsg_box;
            QFont gFont;
            gFont.setFamily("DejaVu Sans Mono");
            gFont.setPointSize(16);
            gMsg_box.setFont(gFont);
            gMsg_box.setParent(this);
            if(gMsg_box.information(this, "Success","Message Send\nFailed",QMessageBox::Ok) == QMessageBox::Ok)
            {
                ui->label_info->hide();
                ui->pushButton_save->setFocus();
                on_pushButton_back_clicked();


                return;
            }
        }
    }

    //    loop.exec();

    //    if (process.state() == QProcess::Running )
    //    {
    //        process.kill();
    //    }
    //    else
    //    {
    //        QString stdout = process.readAllStandardOutput();
    //        qDebug()<<"stdout ===>>>"<<stdout;
    //        QString stderr = process.readAllStandardError();
    //        qDebug()<<"stderr ===>>>"<<stderr;
    //        if(!stdout.isEmpty())
    //        {
    //            qDebug()<<"stderr import===>>>"<<stderr;
    //            importError = true;
    //        }
    //    }

}
