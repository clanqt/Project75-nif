#include "server_get_post.h"
#include "ui_server_get_post.h"
#include <global.h>
#include <QDebug>
#include <QUrl>
#include <QDir>
#include <QAbstractItemView>
#include <QtXml/QDomDocument>
#include <QFile>
#include <QXmlStreamReader>

using namespace Global;

Server_Get_Post::Server_Get_Post(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Server_Get_Post)
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


    http_get_requester_success = false;
    isTimeout = false;



}

Server_Get_Post::~Server_Get_Post()
{
    delete ui;
}

void Server_Get_Post::http_get_requester(QString api_url)
{
    qDebug()<<"http_get_requester api_url===>>>"<<api_url;
    networkManager_mac_reg = new QNetworkAccessManager(this);
    url_mac_reg = api_url;

    QNetworkRequest req;
    req.setUrl(url_mac_reg);
    req.setRawHeader( "User-Agent" , "Mozilla Firefox" );

    reply_server = networkManager_mac_reg->get(req);
    connect(networkManager_mac_reg, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinished(QNetworkReply*)));
    timerTimeout = 60000;
    timerId=startTimer(timerTimeout);
    //     qDebug()<<"timer id ===>>>"<<QString::number(timerId);

}

void Server_Get_Post::replyFinished(QNetworkReply *reply)
{
    QString reply_server_rpy;
    killTimer(timerId);
    isTimeout = true;
    if(reply_server->error() > 0)
    {
        QString error_Msg = "No Reply";
        emit read_server_reply(error_Msg);
        reply_server->abort();
        qDebug()<<"\r reply Error  download"<<reply_server->error();
    }
    else
    {
        int v = reply_server->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        if (v >= 200 && v < 300)
        {
            reply_server_rpy = reply_server->readAll();
            reply_server->abort();
            qApp->processEvents();
            qApp->processEvents();
            qDebug()<<"\r reply success  download"<<v;
            //            qDebug()<<"\r Enter reply ===>>>";
            QByteArray byte;
            reply->seek(0);
            byte = reply_server_rpy.toLatin1();
            QString str(byte);

            QFile f1("/tmp/server_reply.xml");
            f1.resize(0);
            if(f1.open(QIODevice::ReadWrite))
            {
                QTextStream stream(&f1);
                stream << str << endl;
            }
            f1.close();
            emit read_server_reply(reply_server_rpy);
        }
    }

}

void Server_Get_Post::timerEvent(QTimerEvent *event)
{
    //    qDebug()<<"timer id1 ===>>>"<<QString::number(timerId);
    killTimer(timerId);
    reply_server->abort();
    if(reply_server->error() > 0)
    {
        QString error_Msg = "Server Timeout";
        emit read_server_reply(error_Msg);
        reply_server->abort();
        qDebug()<<"\r reply Error  download"<<reply_server->error();
    }
    else
    {
        int v = reply_server->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        if (v >= 200 && v < 300)
        {
            emit read_server_reply(reply_server->readAll());
            reply_server->abort();
            qApp->processEvents();
            qApp->processEvents();
            qDebug()<<"\r reply success  download"<<v;
        }
    }
}


QString Server_Get_Post::xml_child_value_reader(QString server_reply, QString child_name)
{
    QDomDocument domDoc;
    QString child_value;
    QXmlStreamReader xml(server_reply);
    if( !xml.hasError())
    {
        //        qDebug()<<"test 1 ===>>>";
        QXmlStreamReader::TokenType token = xml.readNext(); /* Read next element.*/
        /* If token is just StartDocument, we'll go to next.*/

        if(token == QXmlStreamReader::StartDocument)
        {
            //            qDebug()<<"test 2 ===>>>";
            xml.readNext();
            if(xml.tokenType() == QXmlStreamReader::StartElement)
            {
                //                qDebug()<<"test 3 ===>>>";



                if(domDoc.setContent(server_reply))
                {
                    qDebug()<<"isDocument ===>>>"<<domDoc.setContent(server_reply);

                    //!
                    QDomNodeList id = domDoc.elementsByTagName(child_name);
                    for(int i = 0; i < id.size(); i++){
                        child_value = id.item(i)./*toElement().text();//*/firstChild().nodeValue();
                        //                        qDebug()<<child_name<<"===>>>"<< child_value;
                    }
                    return child_value;
                }
            }
        }
    }
}

QStringList Server_Get_Post::xml_child_child_attributes_reader(QString server_reply, QString child_name, QStringList child_attrributes)
{
    QDomDocument domDoc;
    QStringList child_attributes_value;
    QXmlStreamReader xml(server_reply);
    if( !xml.hasError())
    {
        //        qDebug()<<"test 1 ===>>>";
        QXmlStreamReader::TokenType token = xml.readNext(); /* Read next element.*/
        /* If token is just StartDocument, we'll go to next.*/

        if(token == QXmlStreamReader::StartDocument)
        {
            //            qDebug()<<"test 2 ===>>>";
            xml.readNext();
            if(xml.tokenType() == QXmlStreamReader::StartElement)
            {
                //                qDebug()<<"test 3 ===>>>";



                if(domDoc.setContent(server_reply))
                {
                    qDebug()<<"isDocument ===>>>"<<domDoc.setContent(server_reply);

                    //!
                    QDomElement docElem = domDoc.documentElement();
                    QString rootTag = docElem.tagName();

                    QDomNodeList nodeList = docElem.elementsByTagName(child_name);
                    for(int ii = 0;ii < nodeList.count(); ii++)
                    {
                        QDomElement el = nodeList.at(ii).toElement();

                        for(int j=0;j<child_attrributes.size();j++)
                        {
                            child_attributes_value << el.attribute(child_attrributes.at(j));
                            //                            qDebug()<<child_attrributes.at(j)<<"===>>>"<< el.attribute(child_attrributes.at(j));
                        }
                    }
                    return child_attributes_value;
                }
            }
        }
    }
}

void Server_Get_Post::http_post_xml_requester_api(QString api_url, QStringList post_data, QString post_data_separator, ContentHeaderType HeaderType)
{
    qDebug()<<"url="<<api_url<<"\npost data="<<post_data<<"post_data_separator="<<post_data_separator;
    QByteArray join_post_data;
    if(!post_data.size() > 0)
    {
        QString error_Msg = "No Data To Post";
        emit read_server_reply(error_Msg);
        return;
    }
    else
    {
        QString tmp = post_data.join(post_data_separator.toLatin1());
        join_post_data = tmp.toLatin1();
        qDebug()<<"xml data to be posted ===>>>"<<join_post_data;
    }

    networkManager_mac_reg = new QNetworkAccessManager(this);
    url_mac_reg = api_url;


    QNetworkRequest req;
    req.setUrl(url_mac_reg);

    switch(int(HeaderType))
    {

    case application_x_www_form_urlencoded:
        req.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
        qDebug()<<"ContentTypeHeader ===>>>"<<"application/x-www-form-urlencoded";
        break;

    case application_xml:
        req.setHeader(QNetworkRequest::ContentTypeHeader, "application/xml");
        qDebug()<<"ContentTypeHeader ===>>>"<<"application/xml";
        break;

    case application_json:
        req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        qDebug()<<"ContentTypeHeader ===>>>"<<"application/json";
        break;

    default:
        req.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
        qDebug()<<"ContentTypeHeader default===>>>"<<"application/x-www-form-urlencoded";
        break;
    }


    QNetworkRequest request(url_mac_reg);


    reply_server = networkManager_mac_reg->post(req,join_post_data);
    connect(networkManager_mac_reg, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinished(QNetworkReply*)));
    timerTimeout = 60000;
    timerId=startTimer(timerTimeout);
    qDebug()<<"timer id ===>>>"<<QString::number(timerId);
}

void Server_Get_Post::http_post_xml_requester_api(QString api_url, QString post_data,  int HeaderType)
{
    qDebug()<<"url="<<api_url<<"\npost data="<<post_data;
    QByteArray join_post_data;
    //    if(!post_data.size() > 0)
    //    {
    //        QString error_Msg = "No Data To Post";
    //        emit read_server_reply(error_Msg);
    //        return;
    //    }
    //    else
    //    {
    //        QString tmp = post_data.join(post_data_separator.toLatin1());
    //        join_post_data = tmp.toLatin1();
    //        qDebug()<<"xml data to be posted ===>>>"<<join_post_data;
    //    }

    join_post_data = post_data.toLatin1();
    networkManager_mac_reg = new QNetworkAccessManager(this);
    url_mac_reg = api_url;


    QNetworkRequest req;
    req.setUrl(url_mac_reg);

    switch(int(HeaderType))
    {

    case application_x_www_form_urlencoded:
        req.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
        qDebug()<<"ContentTypeHeader ===>>>"<<"application/x-www-form-urlencoded";
        break;

    case application_xml:
        req.setHeader(QNetworkRequest::ContentTypeHeader, "application/xml");
        qDebug()<<"ContentTypeHeader ===>>>"<<"application/xml";
        break;

    case application_json:
        req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        qDebug()<<"ContentTypeHeader ===>>>"<<"application/json";
        break;

    default:
        req.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
        qDebug()<<"ContentTypeHeader default===>>>"<<"application/x-www-form-urlencoded";
        break;
    }


    QNetworkRequest request(url_mac_reg);


    reply_server = networkManager_mac_reg->post(req,join_post_data);
    connect(networkManager_mac_reg, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinished(QNetworkReply*)));
    timerTimeout = 60000;
    timerId=startTimer(timerTimeout);
    qDebug()<<"timer id ===>>>"<<QString::number(timerId);
}



QStringList Server_Get_Post::xml_child_sub_child_reader(QString server_reply, QString child_name, QString sub_child)
{
    QDomDocument domDoc;
    QStringList sub_child_value;
    QXmlStreamReader xml(server_reply);
    if( !xml.hasError())
    {
        //        qDebug()<<"test 1 ===>>>";
        QXmlStreamReader::TokenType token = xml.readNext(); /* Read next element.*/
        /* If token is just StartDocument, we'll go to next.*/

        if(token == QXmlStreamReader::StartDocument)
        {
            //            qDebug()<<"test 2 ===>>>";
            xml.readNext();
            if(xml.tokenType() == QXmlStreamReader::StartElement)
            {
                //                qDebug()<<"test 3 ===>>>";



                if(domDoc.setContent(server_reply))
                {
                    qDebug()<<"isDocument ===>>>"<<domDoc.setContent(server_reply);

                    QDomElement docElem = domDoc.documentElement();

                    QDomNodeList nodeList = docElem.elementsByTagName(child_name);
                    for(int ii = 0;ii < nodeList.count(); ii++)
                    {
                        QDomElement el = nodeList.at(ii).toElement();
                        QDomNode pEntries = el.firstChild();
                        while(!pEntries.isNull())
                        {
                            QDomElement peData = pEntries.toElement();
                            //                            qDebug()<<"test 4 ===>>>"<< peData.tagName();;
                            QString tagNam = peData.tagName();
                            if(tagNam == sub_child)
                            {
                                sub_child_value << peData.text();
                                //                                qDebug()<<"name ===>>>"<< peData.text();
                            }
                            pEntries = pEntries.nextSibling();
                        }
                    }
                    if(sub_child_value.size() > 0)
                    {
                        //                        qDebug()<<"sub_child_value ===>>>"<<sub_child_value;
                        return sub_child_value;
                    }
                    else{
                        qDebug()<<"no sub_child_value ===>>>";
                        return sub_child_value;
                    }
                }
            }
        }
    }
}

void Server_Get_Post::ThreadSlot()
{
    if(databaseObj->con.isOpen())
    {
        qDebug()<<"GPRS available inside thread flag ===>>>";

        //! start upload process...

        QStringList str_bill_no,str_totalamt,cus_name,cus_address,cus_mobile,cus_mail,pay_mode,cus_proof_name,cus_proof_number,cheque_number,cheque_date,bank_name,day_no,shift_no,user_name,isTax,token_no,time_stamp,net_total,user_server_id;

        QStringList product_server_id,product_bill_no,product_id,product_name,product_qty,product_unit_price,product_total_amount,product_category_id,product_sale_txnId,product_row_id;
        QString postreq_sale,postreq_product,postreq_device_login,postreq_device_logout;
        QStringList device_login_user_name,device_login_user_server_id,device_login_user_login_time,device_login_user_login_rowid;
        QStringList device_logout_user_name,device_logout_user_server_id,device_logout_user_logout_time,device_logout_user_logout_rowid;


        bool containDetails_sale=false,containDetails_product=false;
        QSqlQuery select_qur;
        if(databaseObj->selectQuery("select * from sale_transaction where upload_flag='0' limit 1",select_qur))
        {
            while(select_qur.next())
            {

                str_bill_no << select_qur.value(1).toString().trimmed();
                str_totalamt << select_qur.value(2).toString().trimmed();
                cus_name << select_qur.value(3).toString().trimmed();
                cus_address << select_qur.value(4).toString().trimmed();
                cus_mobile << select_qur.value(5).toString().trimmed();
                cus_mail << select_qur.value(6).toString().trimmed();
                pay_mode << select_qur.value(7).toString().trimmed();
                cus_proof_name << select_qur.value(8).toString().trimmed();
                cus_proof_number << select_qur.value(9).toString().trimmed();
                cheque_number << select_qur.value(10).toString().trimmed();
                cheque_date << select_qur.value(11).toString().trimmed();
                bank_name << select_qur.value(12).toString().trimmed();
                day_no << select_qur.value(13).toString().trimmed();
                shift_no << select_qur.value(14).toString().trimmed();
                user_name << select_qur.value(15).toString().trimmed();
                isTax << select_qur.value(16).toString().trimmed();
                token_no << select_qur.value(17).toString().trimmed();
                time_stamp << select_qur.value(19).toString().trimmed();
                net_total << select_qur.value(20).toString().trimmed();
                user_server_id << select_qur.value(21).toString().trimmed();
            }

            qDebug()<<"str_bill_no ===>>>"<<str_bill_no;// << select_qur.value(0).toString().trimmed();
            qDebug()<<"str_totalamt"<< str_totalamt;// << select_qur.value(0).toString().trimmed();
            qDebug()<<"cus_name"<< cus_name;// << select_qur.value(0).toString().trimmed();
            qDebug()<<"cus_address"<< cus_address;// << select_qur.value(0).toString().trimmed();
            qDebug()<<"cus_mobile"<< cus_mobile;// << select_qur.value(0).toString().trimmed();
            qDebug()<<"cus_mail"<< cus_mail;// << select_qur.value(0).toString().trimmed();
            qDebug()<<"pay_mode"<< pay_mode;// << select_qur.value(0).toString().trimmed();
            qDebug()<<"cus_proof_name"<< cus_proof_name;// << select_qur.value(0).toString().trimmed();
            qDebug()<<"cus_proof_number"<< cus_proof_number;// << select_qur.value(0).toString().trimmed();
            qDebug()<<"cheque_number"<< cheque_number;// << select_qur.value(0).toString().trimmed();
            qDebug()<<"cheque_date"<< cheque_date;// << select_qur.value(0).toString().trimmed();
            qDebug()<<"bank_name"<< bank_name;// << select_qur.value(0).toString().trimmed();
            qDebug()<<"day_no"<< day_no;// << select_qur.value(0).toString().trimmed();
            qDebug()<<"shift_no"<< shift_no;// << select_qur.value(0).toString().trimmed();
            qDebug()<<"user_name"<< user_name;// << select_qur.value(0).toString().trimmed();
            qDebug()<<"isTax"<< isTax;// << select_qur.value(0).toString().trimmed();
            qDebug()<<"token_no"<< token_no;// << select_qur.value(0).toString().trimmed();
            qDebug()<<"time_stamp"<< time_stamp;// << select_qur.value(0).toString().trimmed();
            qDebug()<<"net_total"<< net_total;// << select_qur.value(0).toString().trimmed();
            qDebug()<<"user_server_id"<< user_server_id;// << select_qur.value(0).toString().trimmed();
        }
        QSqlQuery select_qur1;
        if(databaseObj->selectQuery("select *,rowid from product_transaction where product_transaction.upload_flag='0' and product_transaction.sale_txnid  NOT NULL limit 1",select_qur1))
        {
            while(select_qur1.next())
            {
                product_server_id << select_qur1.value(0).toString();
                product_bill_no << select_qur1.value(1).toString();
                product_id << select_qur1.value(2).toString();
                product_name << select_qur1.value(3).toString();
                product_qty << select_qur1.value(4).toString();
                product_unit_price << select_qur1.value(5).toString();
                product_total_amount << select_qur1.value(6).toString();
                product_category_id << select_qur1.value(7).toString();
                product_sale_txnId << select_qur1.value(9).toString();
                product_row_id << select_qur1.value(10).toString();
            }
            qDebug()<<"product_server_id"<< product_server_id;
            qDebug()<<"product_bill_no"<< product_bill_no;
            qDebug()<<"product_id"<< product_id;
            qDebug()<<"product_name"<< product_name;
            qDebug()<<"product_qty"<< product_qty;
            qDebug()<<"product_unit_price"<< product_unit_price;
            qDebug()<<"product_total_amount"<< product_total_amount;
            qDebug()<<"product_category_id"<< product_category_id;
            qDebug()<<"product_sale_txnId"<< product_sale_txnId;
            qDebug()<<"product_row_id"<< product_row_id;

        }
        QSqlQuery select_qur2;
//        select_qur2.
        if(databaseObj->selectQuery("select device_login_master.user_name, device_login_master.id_user, device_login_master.login_time, device_login_master.rowid from device_login_master where device_login_master.upload_login='0' limit 1",select_qur2))
        {
            while(select_qur2.next())
            {
                device_login_user_name << select_qur2.value(0).toString();
                device_login_user_server_id << select_qur2.value(1).toString();
                device_login_user_login_time << select_qur2.value(2).toString();
                device_login_user_login_rowid << select_qur2.value(3).toString();
            }

            qDebug()<<"device_login_user_name"<< device_login_user_name;
            qDebug()<<"device_login_user_server_id"<< device_login_user_server_id;
            qDebug()<<"device_login_user_login_time"<< device_login_user_login_time;
            qDebug()<<"device_login_user_login_rowid"<< device_login_user_login_rowid;
        }

        QSqlQuery select_qur3;
        if(databaseObj->selectQuery("select device_login_master.user_name, device_login_master.id_user, device_login_master.logout_time, device_login_master.rowid from device_login_master where device_login_master.upload_logout='0' limit 1",select_qur3))
        {
            while(select_qur3.next())
            {
                device_logout_user_name << select_qur3.value(0).toString();
                device_logout_user_server_id << select_qur3.value(1).toString();
                device_logout_user_logout_time << select_qur3.value(2).toString();
                device_logout_user_logout_rowid << select_qur3.value(3).toString();
            }

            qDebug()<<"device_logout_user_name"<< device_logout_user_name;
            qDebug()<<"device_logout_user_server_id"<< device_logout_user_server_id;
            qDebug()<<"device_logout_user_logout_time"<< device_logout_user_logout_time;
            qDebug()<<"device_logout_user_logout_rowid"<< device_logout_user_logout_rowid;
        }


        //! ********************** SALE ********************************
        for(int i =0;i<str_bill_no.size();i++)
        {
            int pay_mode_type = 0;
            if(pay_mode.at(i).contains("Cash"))
                pay_mode_type = 1;
            if(pay_mode.at(i).contains("Card"))
                pay_mode_type = 2;
            if(pay_mode.at(i).contains("Cheque"))
                pay_mode_type = 3;

            QString url = gstrServerName+"sales/";

            QUrl url2 = QString(gstrServerName+"sales/");

            postreq_sale = "udid="+gstrDeviceUdId+"&count=1&timestamp[]="+(QDateTime::fromString(time_stamp.at(i),"dd/MM/yyyy & HH:mm:ss").toString("yyyy-MM-dd HH:mm:ss"))+"&billno[]="+str_bill_no.at(i).trimmed()+"&custname[]="+cus_name.at(i).trimmed()+"&custaddress[]="+cus_address.at(i).trimmed()+"&custmobile[]="+cus_mobile.at(i).trimmed()+"&email[]="+cus_mail.at(i).trimmed()+"&proof[]="+cus_proof_name.at(i).trimmed()+"&proofno[]="+cus_proof_number.at(i).trimmed()+"&paymode[]="+QString::number(pay_mode_type)+"&chequeno[]="+cheque_number.at(i).trimmed()+"&chequedate[]="+QDateTime::fromString(cheque_date.at(i).trimmed(),"dd-MM-yyyy").toString("yyyy-MM-dd")+"&bankname[]="+bank_name.at(i).trimmed()+"&totalamount[]="+net_total.at(i).trimmed()+"&dayno[]="+day_no.at(i).trimmed()+"&shiftno[]="+shift_no.at(i).trimmed()+"&userid[]="+user_server_id.at(i).trimmed()+"&istax[]="+isTax.at(i).trimmed()+"&tokenno[]="+token_no.at(i).trimmed();
            qDebug()<<"thread class end str_bill_no ===>>>";
            Server_Get_PostObj->http_post_xml_requester_api(QString(gstrServerName+"sales/"),postreq_sale,1);
            QEventLoop eventLoop;
            QObject::connect(threadObj,SIGNAL(thread_data_saved()),&eventLoop,SLOT(quit()));
            QObject::connect(this,SIGNAL(read_server_reply(QString)),threadObj,SLOT(http_get_server_reply(QString)));
            threadObj->Download_in_Process = 0;
            threadObj->Upload_in_Process = 11;
            eventLoop.exec();
            qDebug()<<"thread class end str_bill_no ===>>>";
            return;
        }


        //! ********************** PRODUCT ********************************
        for(int i =0;i<product_sale_txnId.size();i++)
        {
            postreq_product = "udid="+gstrDeviceUdId+"&count=1&salesid[]="+product_sale_txnId.at(i)+"&itemid[]="+product_server_id.at(i)+"&categoryid[]="+product_category_id.at(i)+"&itemname[]="+product_name.at(i)+"&qty[]="+product_qty.at(i)+"&unitprice[]="+product_unit_price.at(i)+"&itemtotal[]="+product_total_amount.at(i);
            threadObj->Current_Uploading_RowId = product_row_id.at(i);
            qDebug()<<"thread class start product_sale_txnId ===>>>"<<threadObj->Current_Uploading_RowId;
            Server_Get_PostObj->http_post_xml_requester_api(QString(gstrServerName+"salesitem/"),postreq_product,1);
            QEventLoop eventLoop;
            QObject::connect(threadObj,SIGNAL(thread_data_saved()),&eventLoop,SLOT(quit()));
            QObject::connect(this,SIGNAL(read_server_reply(QString)),threadObj,SLOT(http_get_server_reply(QString)));
            threadObj->Download_in_Process = 0;
            threadObj->Upload_in_Process = 22;
            eventLoop.exec();
            qDebug()<<"thread class end product_sale_txnId ===>>>";
            return;
        }


        //! ********************** LOGIN ********************************
        for(int i =0;i<device_login_user_name.size();i++)
        {
            postreq_device_login = "udid="+gstrDeviceUdId+"&userid="+device_login_user_server_id.at(i)+"&sessiontype=1&timestamp="+device_login_user_login_time.at(i);
            threadObj->Current_Uploading_UserLoginRowId = device_login_user_login_rowid.at(i);
            qDebug()<<"thread class start device_login_user_name ===>>>"<<threadObj->Current_Uploading_UserLoginRowId;
            Server_Get_PostObj->http_post_xml_requester_api(QString(gstrServerName+"usersession/"),postreq_device_login,1);
            QEventLoop eventLoop;
            QObject::connect(threadObj,SIGNAL(thread_data_saved()),&eventLoop,SLOT(quit()));
            QObject::connect(this,SIGNAL(read_server_reply(QString)),threadObj,SLOT(http_get_server_reply(QString)));
            threadObj->Download_in_Process = 0;
            threadObj->Upload_in_Process = 33;
            eventLoop.exec();
            qDebug()<<"thread class end postreq_device_loginpostreq_device_login ===>>>";
            return;
        }


        //! ********************** LOGOUT ********************************
        for(int i =0;i<device_logout_user_name.size();i++)
        {
            postreq_device_logout = "udid="+gstrDeviceUdId+"&userid="+device_logout_user_server_id.at(i)+"&sessiontype=0&timestamp="+device_logout_user_logout_time.at(i);
            threadObj->Current_Uploading_UserLogoutRowId = device_logout_user_logout_rowid.at(i);
            qDebug()<<"thread class start device_login_user_name ===>>>"<<threadObj->Current_Uploading_UserLogoutRowId;
            Server_Get_PostObj->http_post_xml_requester_api(QString(gstrServerName+"usersession/"),postreq_device_logout,1);
            QEventLoop eventLoop;
            QObject::connect(threadObj,SIGNAL(thread_data_saved()),&eventLoop,SLOT(quit()));
            QObject::connect(this,SIGNAL(read_server_reply(QString)),threadObj,SLOT(http_get_server_reply(QString)));
            threadObj->Download_in_Process = 0;
            threadObj->Upload_in_Process = 44;
            eventLoop.exec();
            qDebug()<<"thread class end postreq_device_logout postreq_device_logout ===>>>";
            return;
        }
        threadObj->start_Thread();return;
    }
    else
    {
        qDebug()<<"\r gprs not available inside thread";
    }
}
