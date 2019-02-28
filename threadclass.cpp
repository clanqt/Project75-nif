#include "threadclass.h"
#include <global.h>
#include <QProcess>
//#include <QVariantList>
//#include<QEventLoop>
//#include <QMessageBox>
//#include<QXmlStreamReader>
//#include<QXmlStreamWriter>
//#include<QFile>]
#include <QObject>

using namespace Global;
ThreadClass::ThreadClass(QObject *parent):
    QThread(parent)
{

    gprsFlag = false;
    thredstatusflag =false;
    gthreadFlag = false;
    qDebug()<<"\r call1pppp1";

    if(!gthreadFlag)
    {
        qDebug()<<"\r call11";
        //        if(!Obj->isGprs())
        if(!isNetwork())
            //        if(!(Obj->isGprs()||Obj->isWifi()))
        {
            qDebug()<<" \rNO GPRS available";
            gprsFlag = true;
            return;
        }
    }
    Upload_in_Process = 0;

//    QObject::connect(Server_Get_PostObj,SIGNAL(read_server_reply(QString)),this,SLOT(http_get_server_reply(QString)));
    QObject::connect(this,SIGNAL(UploadBackground()),Server_Get_PostObj,SLOT(ThreadSlot()));
    QObject::connect(this,SIGNAL(thread_data_saved()),this,SLOT(start_Thread()));
}

void ThreadClass::http_get_server_reply(QString rpy)
{

    //! *******************************************************************************

    qDebug()<<"http_get_server_reply thread ===>>>"<<rpy;

//    if(rpy == "No Reply")
//    {
//#if(SDK75)
//        g_ccmainObj->messagebox(this,"Status",eMessageType_Error,"Server Error");
//        ui->label_info->hide();
//        ui->pushButton_Reports->setFocus();
//        return;
//#endif
//    }
//    if(rpy == "Server Timeout")
//    {
//#if(SDK75)
//        g_ccmainObj->messagebox(this,"Status",eMessageType_Error,"Server Timeout");
//        ui->pushButton_Reports->setFocus();
//        return;
//#endif
//    }

    if(rpy != "No Reply" && rpy != "Server Timeout")
    {
        if(Upload_in_Process == Sale_Upload)
        {
            qDebug()<<"Upload_in_Process Sale_Upload ===>>>";

            lstSaleUploadBillno.clear();
            lstSaleUploadBillTxnId.clear();
            lstSaleUploadBillno << Server_Get_PostObj->xml_child_sub_child_reader(rpy,"item","billno");
            qDebug()<<"http_get_server_reply lstSaleUploadBillno ===>>>"<<lstSaleUploadBillno;

            lstSaleUploadBillTxnId << Server_Get_PostObj->xml_child_sub_child_reader(rpy,"item","txid");
            qDebug()<<"http_get_server_reply lstSaleUploadBillTxnId ===>>>"<<lstSaleUploadBillTxnId;

            for(int i=0;i<lstSaleUploadBillno.size();i++)
            {
                if(databaseObj->executeCommand("update product_transaction set sale_txnid='"+lstSaleUploadBillTxnId.at(i)+"' where bill_no='"+lstSaleUploadBillno.at(i)+"' and upload_flag='0'"))
                {
                    if(databaseObj->executeCommand("update sale_transaction set upload_flag='1' where bill_no='"+lstSaleUploadBillno.at(i)+"' and upload_flag='0'"))
                    {
                        databaseObj->con.commit();
                        qDebug()<<"product_transaction lstSaleUploadBillTxnId saved ===>>>";
                    }
                }
            }
            Upload_in_Process = 0;
            emit thread_data_saved();
        }
        if(Upload_in_Process == Product_Upload)
        {
            qDebug()<<"Upload_in_Process Product_Upload ===>>>";
            lstProductUploadItemId.clear();
            lstProductUploadItemTxnId.clear();
            lstProductUploadItemBillNo.clear();

            lstProductUploadItemId << Server_Get_PostObj->xml_child_sub_child_reader(rpy,"item","itemid");
            qDebug()<<"http_get_server_reply lstSaleUploadBillno ===>>>"<<lstProductUploadItemId;

            lstProductUploadItemTxnId << Server_Get_PostObj->xml_child_sub_child_reader(rpy,"item","txid");
            qDebug()<<"http_get_server_reply lstSaleUploadBillTxnId ===>>>"<<lstProductUploadItemTxnId;

            lstProductUploadItemBillNo << Server_Get_PostObj->xml_child_sub_child_reader(rpy,"item","billno");
            qDebug()<<"http_get_server_reply lstProductUploadItemBillNo ===>>>"<<lstProductUploadItemBillNo;

            for(int i=0;i<lstProductUploadItemId.size();i++)
            {
                if(databaseObj->executeCommand("update product_transaction set upload_flag='"+lstProductUploadItemTxnId.at(i)+"' where rowid='"+Current_Uploading_RowId+"' and bill_no='"+lstProductUploadItemBillNo.at(i)+"'"))
                {
                    databaseObj->con.commit();
                    qDebug()<<"product_transaction lstProductUploadItemId saved ===>>>";
                }
            }

            Upload_in_Process = 0;
            emit thread_data_saved();
        }
        if(Upload_in_Process == User_login_Upload)
        {
            qDebug()<<"Upload_in_Process User_login_Upload ===>>>";
            lstUserLoginUploadTxnId.clear();
            lstUserLoginUploadTxnId << Server_Get_PostObj->xml_child_sub_child_reader(rpy,"item","txid");
            qDebug()<<"http_get_server_reply lstUserLoginUploadTxnId ===>>>"<<lstUserLoginUploadTxnId;
            for(int i=0;i<lstUserLoginUploadTxnId.size();i++)
            {
                if(databaseObj->executeCommand("update device_login_master set upload_login='"+lstUserLoginUploadTxnId.at(i)+"' where rowid='"+Current_Uploading_UserLoginRowId+"'"))
                {
                    databaseObj->con.commit();
                    qDebug()<<"device_login_master lstUserLoginUploadTxnId saved ===>>>";
                }
            }
            Upload_in_Process = 0;
            emit thread_data_saved();
        }
        if(Upload_in_Process == User_logout_Upload)
        {
            qDebug()<<"Upload_in_Process User_logout_Upload ===>>>";
            lstUserLogoutUploadTxnId.clear();
            lstUserLogoutUploadServerId.clear();

            lstUserLogoutUploadTxnId << Server_Get_PostObj->xml_child_sub_child_reader(rpy,"item","txid");
            qDebug()<<"http_get_server_reply lstUserLogoutUploadTxnId ===>>>"<<lstUserLogoutUploadTxnId;
            for(int i=0;i<lstUserLogoutUploadTxnId.size();i++)
            {
                if(databaseObj->executeCommand("update device_login_master set upload_logout='"+lstUserLogoutUploadTxnId.at(i)+"' where rowid='"+Current_Uploading_UserLogoutRowId+"'"))
                {
                    databaseObj->con.commit();
                    qDebug()<<"device_login_master lstUserLogoutUploadTxnId saved ===>>>";
                }
                if(databaseObj->executeCommand("delete from device_login_master where rowid='"+Current_Uploading_UserLogoutRowId+"'"))
                {
                    databaseObj->con.commit();
                    qDebug()<<"device_login_master lstUserLogoutUploadTxnId delete from device_login_master ===>>>";
                }
            }

            Upload_in_Process = 0;
            emit thread_data_saved();
        }
    }

}

void ThreadClass::run()
{
    qDebug()<<"\r run method called";
    qDebug()<<"\r mw 10";
    qDebug() <<"\r GSM finish time" << QTime::currentTime();

    QSqlQuery query;
    gthreadFlag = true;
    while(1)
    {
        //        qDebug()<<"inside while of run ===>>>"<<gthreadFlag;

        if(gthreadFlag)
        {
            if(isNetwork())
            {

                gthreadFlag = false;
                emit UploadBackground();
//                if(databaseObj->con.isOpen())
//                {
//                    qDebug()<<"GPRS available inside thread flag ===>>>";

//                    //! start upload process...

//                    QStringList str_bill_no,str_totalamt,cus_name,cus_address,cus_mobile,cus_mail,pay_mode,cus_proof_name,cus_proof_number,cheque_number,cheque_date,bank_name,day_no,shift_no,user_name,isTax,token_no,time_stamp,net_total,user_server_id;

//                    QStringList product_server_id,product_bill_no,product_id,product_name,product_qty,product_unit_price,product_total_amount,product_category_id,product_sale_txnId;
//                    QString postreq_sale,postreq_product;
//                    bool containDetails_sale=false,containDetails_product=false;
//                    QSqlQuery select_qur;
//                    if(databaseObj->selectQuery("select * from sale_transaction where upload_flag='0' limit 1",select_qur))
//                    {
//                        while(select_qur.next())
//                        {

//                            str_bill_no << select_qur.value(1).toString().trimmed();
//                            str_totalamt << select_qur.value(2).toString().trimmed();
//                            cus_name << select_qur.value(3).toString().trimmed();
//                            cus_address << select_qur.value(4).toString().trimmed();
//                            cus_mobile << select_qur.value(5).toString().trimmed();
//                            cus_mail << select_qur.value(6).toString().trimmed();
//                            pay_mode << select_qur.value(7).toString().trimmed();
//                            cus_proof_name << select_qur.value(8).toString().trimmed();
//                            cus_proof_number << select_qur.value(9).toString().trimmed();
//                            cheque_number << select_qur.value(10).toString().trimmed();
//                            cheque_date << select_qur.value(11).toString().trimmed();
//                            bank_name << select_qur.value(12).toString().trimmed();
//                            day_no << select_qur.value(13).toString().trimmed();
//                            shift_no << select_qur.value(14).toString().trimmed();
//                            user_name << select_qur.value(15).toString().trimmed();
//                            isTax << select_qur.value(16).toString().trimmed();
//                            token_no << select_qur.value(17).toString().trimmed();
//                            time_stamp << select_qur.value(19).toString().trimmed();
//                            net_total << select_qur.value(20).toString().trimmed();
//                            user_server_id << select_qur.value(21).toString().trimmed();
//                        }

//                        qDebug()<<"str_bill_no ===>>>"<<str_bill_no;// << select_qur.value(0).toString().trimmed();
//                        qDebug()<<"str_totalamt"<< str_totalamt;// << select_qur.value(0).toString().trimmed();
//                        qDebug()<<"cus_name"<< cus_name;// << select_qur.value(0).toString().trimmed();
//                        qDebug()<<"cus_address"<< cus_address;// << select_qur.value(0).toString().trimmed();
//                        qDebug()<<"cus_mobile"<< cus_mobile;// << select_qur.value(0).toString().trimmed();
//                        qDebug()<<"cus_mail"<< cus_mail;// << select_qur.value(0).toString().trimmed();
//                        qDebug()<<"pay_mode"<< pay_mode;// << select_qur.value(0).toString().trimmed();
//                        qDebug()<<"cus_proof_name"<< cus_proof_name;// << select_qur.value(0).toString().trimmed();
//                        qDebug()<<"cus_proof_number"<< cus_proof_number;// << select_qur.value(0).toString().trimmed();
//                        qDebug()<<"cheque_number"<< cheque_number;// << select_qur.value(0).toString().trimmed();
//                        qDebug()<<"cheque_date"<< cheque_date;// << select_qur.value(0).toString().trimmed();
//                        qDebug()<<"bank_name"<< bank_name;// << select_qur.value(0).toString().trimmed();
//                        qDebug()<<"day_no"<< day_no;// << select_qur.value(0).toString().trimmed();
//                        qDebug()<<"shift_no"<< shift_no;// << select_qur.value(0).toString().trimmed();
//                        qDebug()<<"user_name"<< user_name;// << select_qur.value(0).toString().trimmed();
//                        qDebug()<<"isTax"<< isTax;// << select_qur.value(0).toString().trimmed();
//                        qDebug()<<"token_no"<< token_no;// << select_qur.value(0).toString().trimmed();
//                        qDebug()<<"time_stamp"<< time_stamp;// << select_qur.value(0).toString().trimmed();
//                        qDebug()<<"net_total"<< net_total;// << select_qur.value(0).toString().trimmed();
//                        qDebug()<<"user_server_id"<< user_server_id;// << select_qur.value(0).toString().trimmed();
//                    }
//                    QSqlQuery select_qur1;
//                    if(databaseObj->selectQuery("select * from product_transaction where product_transaction.upload_flag='0' and product_transaction.sale_txnid  NOT NULL limit 1",select_qur1))
//                    {
//                        while(select_qur1.next())
//                        {
//                            product_server_id << select_qur1.value(0).toString();
//                            product_bill_no << select_qur1.value(1).toString();
//                            product_id << select_qur1.value(2).toString();
//                            product_name << select_qur1.value(3).toString();
//                            product_qty << select_qur1.value(4).toString();
//                            product_unit_price << select_qur1.value(5).toString();
//                            product_total_amount << select_qur1.value(6).toString();
//                            product_category_id << select_qur1.value(7).toString();
//                            product_sale_txnId << select_qur1.value(9).toString();
//                        }
//                        qDebug()<<"product_server_id"<< product_server_id;
//                        qDebug()<<"product_bill_no"<< product_bill_no;
//                        qDebug()<<"product_id"<< product_id;
//                        qDebug()<<"product_name"<< product_name;
//                        qDebug()<<"product_qty"<< product_qty;
//                        qDebug()<<"product_unit_price"<< product_unit_price;
//                        qDebug()<<"product_total_amount"<< product_total_amount;
//                        qDebug()<<"product_category_id"<< product_category_id;
//                        qDebug()<<"product_sale_txnId"<< product_sale_txnId;

//                    }

//                    for(int i =0;i<str_bill_no.size();i++)
//                    {
//                        int pay_mode_type = 0;
//                        if(pay_mode.at(i).contains("Cash"))
//                            pay_mode_type = 1;
//                        if(pay_mode.at(i).contains("Card"))
//                            pay_mode_type = 2;
//                        if(pay_mode.at(i).contains("Cheque"))
//                            pay_mode_type = 3;

//                        QString url = gstrServerName+"sales/";

//                        QUrl url2 = QString(gstrServerName+"sales/");

//                        postreq_sale = "udid="+gstrDeviceUdId+"&count=1&timestamp[]="+(QDateTime::fromString(time_stamp.at(i),"dd/MM/yyyy & HH:mm:ss").toString("yyyy-MM-dd HH:mm:ss"))+"&billno[]="+str_bill_no.at(i).trimmed()+"&custname[]="+cus_name.at(i).trimmed()+"&custaddress[]="+cus_address.at(i).trimmed()+"&custmobile[]="+cus_mobile.at(i).trimmed()+"&email[]="+cus_mail.at(i).trimmed()+"&proof[]="+cus_proof_name.at(i).trimmed()+"&proofno[]="+cus_proof_number.at(i).trimmed()+"&paymode[]="+QString::number(pay_mode_type)+"&chequeno[]="+cheque_number.at(i).trimmed()+"&chequedate[]="+QDateTime::fromString(cheque_date.at(i).trimmed(),"dd-MM-yyyy").toString("yyyy-MM-dd")+"&bankname[]="+bank_name.at(i).trimmed()+"&totalamount[]="+net_total.at(i).trimmed()+"&dayno[]="+day_no.at(i).trimmed()+"&shiftno[]="+shift_no.at(i).trimmed()+"&userid[]="+user_server_id.at(i).trimmed()+"&istax[]="+isTax.at(i).trimmed()+"&tokenno[]="+token_no.at(i).trimmed();
//                        qDebug()<<"thread class end str_bill_no ===>>>";
//                        Server_Get_PostObj->http_post_xml_requester_api(QString(gstrServerName+"sales/"),postreq_sale,1);
////                        QEventLoop eventLoop;
////                        QObject::connect(this,SIGNAL(thread_data_saved()),&eventLoop,SLOT(quit()));
//                        Download_in_Process = 0;
//                        Upload_in_Process = 1;
////                        eventLoop.exec();
//                        qDebug()<<"thread class end str_bill_no ===>>>";
//                    }
//                    for(int i =0;i<product_sale_txnId.size();i++)
//                    {
//                        postreq_product = "udid="+gstrDeviceUdId+"&count=1&salesid[]="+product_sale_txnId.at(i)+"&itemid[]="+product_server_id.at(i)+"&categoryid[]="+product_category_id.at(i)+"&itemname[]="+product_name.at(i)+"&qty[]="+product_qty.at(i)+"&unitprice[]="+product_unit_price.at(i)+"&itemtotal[]="+product_total_amount.at(i);
//                        Current_Uploading_BillNo = product_bill_no.at(i);
//                        qDebug()<<"thread class start product_sale_txnId ===>>>";
//                        Server_Get_PostObj->http_post_xml_requester_api(QString(gstrServerName+"salesitem/"),postreq_product,1);
////                        QEventLoop eventLoop;
////                        QObject::connect(this,SIGNAL(thread_data_saved()),&eventLoop,SLOT(quit()));
//                        Download_in_Process = 0;
//                        Upload_in_Process = 2;
////                        eventLoop.exec();
//                        qDebug()<<"thread class end product_sale_txnId ===>>>";
//                    }

//                }
//                else
//                {
//                    qDebug()<<"\r gprs not available inside thread";
//                }
            }
            else
            {
                qDebug()<<"\r thread flag is false";
            }
            qDebug()<<"\r going to sleep";
        }
        sleep(5);
    }
}

void ThreadClass::errorHandler()
{
    //    qDebug()<<"\r Calling ErrorHandler";
    //    QProcess process;
    //    process.setProcessChannelMode(QProcess::SeparateChannels);
    //    qDebug()<<"\r before test ping google";
    //    //    process.start("ping -c 2 "+gDB_HOST);
    //    //    process.start("ping -c 2 "+gServerIp);
    //    while(process.state() == QProcess::Running || process.state() == QProcess::Starting)
    //    {
    //        qDebug()<<"\r b4 event loop, running";
    //        QEventLoop e;
    //        connect(&process, SIGNAL(finished(int)), &e, SLOT(quit()));
    //        e.exec();
    //        disconnect(&process, SIGNAL(finished(int)), &e, SLOT(quit()));
    //        qDebug()<<"\r inside finished";
    //        //        QString strtmp = QString(process.readAllStandardOutput());
    //        //        qDebug()<<"\r b4 event loop, running"<<strtmp;
    //        gprsFlag = true;
    //        if(isNetwork())
    //            //        if(!(Obj->isGprs()||Obj->isWifi()))
    //        {
    //            Errorstr = Obj->lastError();
    //            qDebug()<<"\r error from sdk "<<Errorstr;
    //            LastError = true;
    //            gprsFlag = false;
    //            // emit Thread_stopped(true);
    //            if(isRunning())
    //            {
    //                qDebug()<<"\r before thread terminate";
    //                wait();
    //                terminate();
    //            }
    //            msleep(50);
    //            return;
    //        }
    //    }
    //    process.reset();
}
void ThreadClass::stop_Thread()
{
    //    if (isRunning())
    {
        qDebug()<<"\r before Wait";
        gthreadFlag = false;
        //        QThread::quit();
        //        wait();
        qDebug()<<"\r exit wait";
    }
}

void ThreadClass::start_Thread()
{
    qDebug()<<"\r isRunning()"<<isRunning();
    gthreadFlag = true;
    //    QThread::run();
    //    gbThreadFlag=true;
    //    if (isRunning())
    //    start();
}

void ThreadClass::pausethread()
{
    qDebug()<<"\r &&&&& before pause &&&&&";
    gthreadFlag = false;
    qDebug()<<"\r ^^^^^^^exit pause^^^^^^";
}
