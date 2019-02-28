#include "day_close.h"
#include "ui_day_close.h"

#include <QMessageBox>

#include <global.h>
using namespace Global;

Day_Close::Day_Close(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Day_Close)
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

Day_Close::~Day_Close()
{
    delete ui;
}

void Day_Close::call_Day_Close()
{
    ui->lineEdit_op_bale->clear();
    ui->lineEdit_bale_dispatched->clear();
    ui->lineEdit_bale_produced->clear();
    ui->lineEdit_closing_bale->clear();

    ui->label_info->hide();

    ui->radioButton_nif->installEventFilter(this);
    ui->radioButton_vcp->installEventFilter(this);

    ui->pushButton_close->setEnabled(false);

    after_dispatch.clear();
    before_dispatch.clear();

    lst_batch_type.clear();
    lst_batch_no.clear();
    lst_husk_available.clear();
    lst_husk_to_bale.clear();

    QSqlQuery query;
    if(databaseObj->selectQuery("select * from production_batch_order",query))
    {
        if(query.next())
        {
            lst_batch_type << query.value(1).toString().trimmed();
            lst_batch_no << query.value(2).toString().trimmed();
            lst_husk_available << query.value(3).toString().trimmed();
            lst_husk_to_bale << QString::number(query.value(3).toString().trimmed().toFloat()/Home_ScreenObj->HP_bale.toFloat());
            while(query.next())
            {
                lst_batch_type << query.value(1).toString().trimmed();
                lst_batch_no << query.value(2).toString().trimmed();
                lst_husk_available << query.value(3).toString().trimmed();
                lst_husk_to_bale << QString::number(query.value(3).toString().trimmed().toFloat()/Home_ScreenObj->HP_bale.toFloat());
            }
        }
        if(lst_batch_no.size() > 0)
        {
            batch_type = lst_batch_no.at(0);
            batch_type = lst_batch_type.at(0);
            husk_available = lst_husk_available.at(0);
        }
        qDebug()<<"lst_batch_type ===>>>"<<lst_batch_type;
        qDebug()<<"lst_batch_no ===>>>"<<lst_batch_no;
        qDebug()<<"lst_husk_available ===>>>"<<lst_husk_available;
        qDebug()<<"lst_husk_available ===>>>"<<lst_husk_to_bale;



    }


    query.clear();
    if(databaseObj->selectQuery("select sum(husk_available) from production_batch_order",query))
    {
        if(query.next())
        {
            total_husk_available = query.value(0).toString().trimmed();

            total_bale_estimated = QString::number(total_husk_available.toFloat()/Home_ScreenObj->HP_bale.toFloat(),'f',2);
        }

        qDebug()<<"total_husk_available ===>>>"<<total_husk_available;
        qDebug()<<"total_bale_estimated ===>>>"<<total_bale_estimated;
    }

    qDebug()<<"gstrday_open_bale ===>>>"<<gstrday_open_bale;
    ui->lineEdit_op_bale->setText(gstrday_open_bale);

#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif

    ui->lineEdit_bale_produced->setFocus();

}

void Day_Close::keyPressEvent(QKeyEvent *ke)
{
    if(ke->key()== Qt::Key_Escape)
    {
        this->close();
        menuObj->call_menu();
        menuObj->show();
    }
}

bool Day_Close::eventFilter(QObject *target, QEvent *event)
{
    QKeyEvent *key = static_cast <QKeyEvent*> (event);

    if(target == ui->radioButton_nif)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->radioButton_nif->hasFocus())
                {
                    ui->radioButton_nif->setChecked(true);
                    ui->radioButton_vcp->setChecked(false);
                    ui->pushButton_close->setEnabled(true);

                    //                    before_dispatch = QString::number(ui->lineEdit_op_bale->text().toFloat() + ui->lineEdit_bale_produced->text().toFloat());
                    //                    after_dispatch = before_dispatch

                    ui->pushButton_close->setEnabled(true);
                    ui->pushButton_close->setFocus();

                    return true;
                }
            }
        }
    }
    else if(target == ui->radioButton_vcp)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->radioButton_vcp->hasFocus())
                {
                    ui->radioButton_vcp->setChecked(true);
                    ui->radioButton_nif->setChecked(false);
                    ui->pushButton_close->setEnabled(true);
                    ui->pushButton_close->setEnabled(true);
                    ui->pushButton_close->setFocus();

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

void Day_Close::on_lineEdit_bale_produced_returnPressed()
{
    if(ui->lineEdit_bale_produced->text().toInt() >= 0)
    {
        before_dispatch = QString::number(ui->lineEdit_op_bale->text().toFloat() + ui->lineEdit_bale_produced->text().toFloat());
        ui->lineEdit_bale_dispatched->setFocus();
    }
}

void Day_Close::on_lineEdit_bale_dispatched_returnPressed()
{
    QString tmp_dispatch_qty = ui->lineEdit_bale_dispatched->text().trimmed();
    qDebug()<<"Day_Close test 1 ===>>>";
    use_next_batch = false;
    qDebug()<<"Day_Close test 2 ===>>>";
    if(ui->lineEdit_bale_dispatched->text().toInt() > 0)
    {
        ui->radioButton_nif->setEnabled(true);
        ui->radioButton_vcp->setEnabled(true);
        qDebug()<<"Day_Close test 3 ===>>>";
        if(ui->lineEdit_bale_dispatched->text().toFloat() <= before_dispatch.toFloat())
        {
            bale_dispatched = ui->lineEdit_bale_dispatched->text().trimmed();

            after_dispatch = QString::number(before_dispatch.toFloat() - bale_dispatched.toFloat(),'f',2);
            ui->lineEdit_closing_bale->setText(after_dispatch);

            qDebug()<<"Day_Close test 4 ===>>>";
            ui->radioButton_nif->setFocus();
            //            for(int i=0;i<lst_batch_no.size();i++)
            //            {
            //                qDebug()<<"Day_Close test 5 ===>>>"<<i;
            //                if(tmp_dispatch_qty >= lst_husk_available.at(i))
            //                {
            //                    qDebug()<<"Day_Close test 6 ===>>>";
            //                    tmp_dispatch_qty = QString::number(tmp_dispatch_qty.toFloat() - lst_husk_available.at(i).toFloat(),'f',2);
            //                    //! current batch need to closed

            //                    batch_no = lst_batch_no.at(i);
            //                    batch_type = lst_batch_type.at(i);
            //                    husk_available = lst_husk_available.at(i);

            //                    qDebug()<<"batch_type ===>>>"<<batch_type;
            //                    qDebug()<<"batch_no ===>>>"<<batch_no;
            //                    qDebug()<<"husk_available ===>>>"<<husk_available;

            //                    if(lst_batch_type.at(i).contains("company",Qt::CaseInsensitive))
            //                        company_or_other = 0;
            //                    if(lst_batch_type.at(i).contains("auto",Qt::CaseInsensitive))
            //                        company_or_other = 1;
            //                    if(lst_batch_type.at(i).contains("van",Qt::CaseInsensitive))
            //                        company_or_other = 2;


            //                    this->hide();
            //                    Batch_CloseObj->call_Batch_Close();
            //                    Batch_CloseObj->show();

            //                    qDebug()<<"after call ===>>>";


            //                }

            //                if(tmp_dispatch_qty <= lst_husk_available.at(i))
            //                {
            //                    qDebug()<<"Day_Close test 7 ===>>>";
            //                    tmp_dispatch_qty = QString::number(lst_husk_available.at(i).toFloat() - tmp_dispatch_qty.toFloat(),'f',2);

            //                }
            //            }


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

            if(gMsg_box.information(this, "Warning","Invalid Input!",QMessageBox::Ok) == QMessageBox::Ok)
            {
                ui->lineEdit_bale_dispatched->clear();
                ui->lineEdit_bale_dispatched->setFocus();
            }
#endif

#if(SDK75)
            int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"Invalid Input!",16,14);
            ui->lineEdit_bale_dispatched->clear();
            ui->lineEdit_bale_dispatched->setFocus();
#endif
        }
    }
    else
    {
        ui->radioButton_nif->setEnabled(false);
        ui->radioButton_vcp->setEnabled(false);

        ui->radioButton_nif->setChecked(false);
        ui->radioButton_vcp->setChecked(false);
        bale_dispatched = ui->lineEdit_bale_dispatched->text().trimmed();

        after_dispatch = QString::number(before_dispatch.toFloat() - bale_dispatched.toFloat(),'f',2);
        ui->lineEdit_closing_bale->setText(after_dispatch);

        ui->pushButton_close->setEnabled(true);
        ui->pushButton_close->setFocus();
    }
}

void Day_Close::on_pushButton_close_clicked()
{
    if((ui->lineEdit_bale_dispatched->text().toInt() >= 0) && (ui->lineEdit_bale_produced->text().toInt() >= 0))
    {
        //        Home_ScreenObj->close_day(this);
        QSqlQuery batch_close_query;
        if(databaseObj->selectQuery("select count(*) from production_batch_order where CAST(batch_status AS INTEGER)==0",batch_close_query))
        {
            if(batch_close_query.next())
            {
                if(batch_close_query.value(0).toInt() == 0)
                {
                    QSqlQuery check_production_stock;
                    QString noof_husk;

                    check_production_stock.clear();
                    if(databaseObj->selectQuery("select * from production_batch_order limit 1",check_production_stock))
                    {
                        if(check_production_stock.next())
                        {
                            noof_husk = check_production_stock.value(3).toString().trimmed();
                            qDebug()<<"husk available in dayclose noof_husk ===>>>"<<noof_husk;
                            float noof_bale = noof_husk.toFloat()/Home_ScreenObj->HP_bale.toFloat();
                            qDebug()<<"husk available in dayclose noof_bale ===>>>"<<noof_bale;
                            if(noof_bale < ui->lineEdit_bale_produced->text().toFloat())
                            {

                                check_production_stock.clear();
                                if(databaseObj->selectQuery("select count(*) from production_batch_order",check_production_stock))
                                {
                                    if(check_production_stock.next())
                                    {
                                        if(check_production_stock.value(0).toInt() <2 )
                                        {
#if(SDK75)
                                            int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Critical,"Next Priority Batch Not Available.",16,14);
                                            ui->pushButton_close->setFocus();
                                            return;
#endif
                                        }
                                    }
                                }

                                qDebug()<<"production batch close from day close ===>>>";

                                QSqlQuery query;
                                QString str_batch_order_name,str_batch_order_no;
                                if(databaseObj->selectQuery("select * from production_batch_order where batch_status='2' limit 1",query))
                                {
                                    if(query.next())
                                    {
                                        str_batch_order_name = query.value(1).toString().trimmed();
                                        str_batch_order_no = query.value(2).toString().trimmed();

                                        Day_CloseObj->batch_no = str_batch_order_no;

#if(NativeCompile)
                                        QMessageBox gMsg_box;
                                        QFont gFont;
                                        gFont.setFamily("DejaVu Sans Mono");
                                        gFont.setPointSize(12);
                                        gMsg_box.setFont(gFont);
                                        gMsg_box.setParent(this);

                                        if(gMsg_box.question(this, "Status","Do You Want To\nClose "+str_batch_order_name.toUpper()+" "+str_batch_order_no+"?",QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes)
                                        {
                                            qDebug()<<"close production batch ===>>>";

                                            //! yes


                                            if(str_batch_order_name.contains("company",Qt::CaseInsensitive))
                                            {
                                                company_or_other = 0;
                                            }
                                            if(str_batch_order_name.contains("auto",Qt::CaseInsensitive))
                                            {
                                                company_or_other = 1;
                                            }
                                            if(str_batch_order_name.contains("van",Qt::CaseInsensitive))
                                            {
                                                company_or_other = 2;
                                            }

                                            if(databaseObj->executeCommand("update production_batch_order set batch_status='0' where batch_type='"+str_batch_order_name+"' and batch_no='"+str_batch_order_no+"'"))
                                            {
                                                qDebug()<<"production_batch_order close update success ===>>>";
                                            }




                                        }
                                        else
                                        {
                                            qDebug()<<"not close production batch ===>>>";
                                        }
#endif


#if(SDK75)
                                        int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Error,"Estimated Stock\nIs Lower Than\nProduction\nDo You Want To\nClose "+str_batch_order_name.toUpper()+" "+str_batch_order_no+"?",16,14,"YES","NO");
                                        if(ret==1)
                                        {
                                            //!yes

                                            //                                if(str_batch_order_name.contains("company",Qt::CaseInsensitive))
                                            //                                {
                                            //                                    Day_CloseObj->company_or_other = 0;
                                            //                                }
                                            //                                if(str_batch_order_name.contains("auto",Qt::CaseInsensitive))
                                            //                                {
                                            //                                    Day_CloseObj->company_or_other = 1;
                                            //                                }
                                            //                                if(str_batch_order_name.contains("van",Qt::CaseInsensitive))
                                            //                                {
                                            //                                    Day_CloseObj->company_or_other = 2;
                                            //                                }

                                            if(databaseObj->executeCommand("update production_batch_order set batch_status='0' where batch_type='"+str_batch_order_name+"' and batch_no='"+str_batch_order_no+"'"))
                                            {
                                                qDebug()<<"production_batch_order close update success ===>>>";


                                                //!sms

#if(SDK75)
                                                QFile sms("/opt/daemon_files/tower_value");
                                                QString tower;
                                                if(sms.open(QIODevice::ReadWrite))
                                                {
                                                    tower = sms.readAll();
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

                                                            if(!number.isEmpty())
                                                            {
                                                                QString send_msg = "gammu sendsms TEXT "+number+" -text \""+str_batch_order_name.toUpper()+" "+str_batch_order_no+" is closed by "+gstrUserName+"\"";
                                                                qDebug()<<"send_msg cmd ===>>>"<<send_msg;
                                                                execProcess(send_msg,"");
                                                            }
                                                            //                            on_pushButton_back_clicked();
                                                        }
                                                    }


                                                }
                                                else
                                                {
                                                    int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"No Signal SMS\nSending Failed",16,14);
                                                    ui->pushButton_close->setFocus();
                                                    //                    on_pushButton_back_clicked();
                                                }

#endif




                                                ui->pushButton_close->setFocus();
                                            }
                                            //                this->close();
                                            //                Batch_CloseObj->from_batch_config = true;
                                            //                Batch_CloseObj->call_Batch_Close();
                                            //                Batch_CloseObj->show();
                                        }
                                        else
                                        {
                                            qDebug()<<"not close production batch ===>>>";
                                            ui->pushButton_close->setFocus();
                                            return;
                                        }
#endif
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
                                            ui->pushButton_Production_close->setFocus();
                                            return;
                                        }
                                        else
                                        {

                                        }
#endif

#if(SDK75)
                                        int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"Production Batch\nNot Available.",16,14);
                                        ui->pushButton_close->setFocus();
#endif

                                    }
                                }
                            }
                        }
                    }


                }
            }
        }























        closing_bale = ui->lineEdit_closing_bale->text();
        if(ui->radioButton_nif->isChecked() && ui->radioButton_nif->isEnabled())
            dispatched_to = "nif";
        else if(ui->radioButton_vcp->isChecked() && ui->radioButton_vcp->isEnabled())
            dispatched_to = "vcp";
        else
            dispatched_to = "";

        bale_produced = ui->lineEdit_bale_produced->text().trimmed();
        opening_bale = ui->lineEdit_op_bale->text().trimmed();



        this->hide();
        Batch_CloseObj->call_Batch_Close();
        Batch_CloseObj->show();
    }
}

void Day_Close::execProcess(QString ProcessName, QString Message)
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
                ui->pushButton_close->setFocus();
                //                on_pushButton_back_clicked();


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
