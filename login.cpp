#include "login.h"
#include "ui_login.h"

#include <QScrollArea>
#include <QTime>
#include <global.h>
using namespace Global;

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
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

    exitStatus = false;
    timerStarted = false;
    min=0;

//    if(!gstrDeviceUdId.isEmpty())
//    {
//        qDebug()<<"!gstrDeviceUdId.isEmpty() thread started in login cons ===>>>";
//        StartThread();
//    }
}

Login::~Login()
{
    delete ui;
}


void Login::call_login()
{

    qDebug()<<"Mcadmin Screen";
    /** function to initialize the login screen **/
    ui->lineEdit_pwd->clear();
    ui->label_user_details->setAlignment(Qt::AlignCenter);
    ui->label_user_details->setText("Enter Password");
    //    ui->comboBox->clear();
    //    ui->comboBox->setEditable(false);


    QSqlQuery query;
    QString uc;
    if(databaseObj->selectQuery("select count(*) from user_master where is_active='1'",query))
    {
        qDebug()<<"user_count 2===>>>";
        if(query.next())
        {
            qDebug()<<"user_count 3===>>>";
            uc = query.value(0).toString();
            user_count = uc.toInt();
            qDebug()<<"user_count ===>>>"<<QString::number(user_count)<<uc;
        }
        query.clear();
        if(databaseObj->selectQuery("select user_password from user_master where is_active='1'",query))
        {
            lst_UserPassword.clear();
            while(query.next())
            {
                lst_UserPassword << query.value(0).toString();
            }
            qDebug()<<"user_count 4===>>>"<<lst_UserPassword;
        }
    }
    ui->pushButton_froget_password->hide();
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
    ui->lineEdit_pwd->setFocus();
}

void Login::StartThread()
{
    qDebug()<<"thread started in login StartThread() ===>>>";

    threadObj->start();
}

void Login::keyPressEvent(QKeyEvent *ke)
{
    qDebug()<<"esc pressed time1"<<QTime::currentTime()<<Qt::Key_Escape;

    if(ke->key()== Qt::Key_Escape)
    {
        qDebug()<<"esc pressed quit time ===>>>"<<QTime::currentTime();
//        exit(0);
    }


    //    if(ke->key()== Qt::Key_Escape)
    //    {
    //        qDebug()<<"esc pressed time"<<QTime::currentTime()<<Qt::Key_Escape;
    //        //        on_pushButton_Exit_clicked();
    //    }
    //    if(ke->key()==Qt::Key_Up)
    //    {
    //        Indexno=ui->comboBox->currentIndex();

    //        Indexno=Indexno-1;
    //        qDebug()<<"\r usercount uparrow"<<UserCount;
    //        if(Indexno>=0 && Indexno<=UserCount)
    //        {
    //            qDebug()<<"\r usercount uparrow  inside func"<<UserCount;
    //            ui->comboBox->setCurrentIndex(Indexno);
    //            ui->lineEdit_pwd->clear();
    //        }
    //        else
    //        {
    //        }
    //    }
    //    if(ke->key()==Qt::Key_Down)
    //    {
    //        Indexno=ui->comboBox->currentIndex();

    //        Indexno=Indexno+1;
    //        qDebug()<<"\r usercount downarrow"<<UserCount;
    //        if(Indexno>=0 && Indexno<=UserCount)
    //        {
    //            qDebug()<<"\r usercount downarrow inside func"<<UserCount;
    //            ui->comboBox->setCurrentIndex(Indexno);
    //            ui->lineEdit_pwd->clear();
    //        }
    //        else
    //        {

    //        }
    //    }
    //    if(ke->key()==Qt::Key_Return)
    //    {
    //        if(ui->comboBox->hasFocus())
    //        {
    //            ui->lineEdit_pwd->setFocus();
    //        }
    //    }
}

void Login::timerEvent(QTimerEvent *event)
{
    killTimer(timerId);
    if(ui->lineEdit_pwd->text().toInt() == 1111)
    {
        this->close();
        menuObj->call_menu();
        menuObj->show();

    }
    else
    {
        this->close();
        menuObj->call_menu();
        menuObj->show();
    }
}

void Login::on_lineEdit_pwd_textEdited(const QString &arg1)
{
    qDebug()<<"test 1 ===>>>";
    ui->label_user_details->setAlignment(Qt::AlignCenter);
    ui->label_user_details->setText("Enter Password");
    if(ui->lineEdit_pwd->text().trimmed().size() == 4)
    {
        qDebug()<<"test 2 ===>>>"<<QString::number(user_count);
        if(user_count > 0)
        {
            for(int i=0;i<lst_UserPassword.size();i++)
            {
                qDebug()<<"test 3 ===>>>";
                if(ui->lineEdit_pwd->text().trimmed() == lst_UserPassword.at(i))
                {
                    qDebug()<<"test 4 ===>>>";
                    QSqlQuery query;
                    if(databaseObj->selectQuery("select id,name,user_name,user_password,user_mobile,user_designation,user_type from user_master where user_password='"+lst_UserPassword.at(i)+"' and is_active='1'",query))
                    {
                        qDebug()<<"test 5 ===>>>";
                        if(query.next())
                        {

                            gstr_Users_server_id = query.value(0).toString();
                            gstr_Users_Name = query.value(1).toString();
                            gstrUserName = query.value(2).toString();
                            gstr_User_Mobile = query.value(4).toString();
                            gstr_User_Designation = query.value(5).toString();
                            gstrUserType = query.value(6).toString();
                            if(gstrUserType.toInt() == 1)
                            {
                                isDefaultAdmin = true;
                            }


                            qDebug()<<"test 6 ===>>>"<<gstr_Users_server_id<<gstrUserName<<gstr_User_Designation<<gstrUserType<<gstr_User_Mobile<<"\n user count"<<QString::number(user_count);

                            {
                                if(databaseObj->executeCommand("insert into device_login_master (id_user, user_name, login_time, upload_login) values ('"+gstr_Users_server_id+"','"+gstrUserName+"','"+QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss")+"','0')"))
                                {
                                    qDebug()<<"device_login_master login saved ===>>>";
                                }
                            }

                            qApp->processEvents();
                            ui->label_user_details->setAlignment(Qt::AlignLeft);
                            ui->label_user_details->setText("Name  :"+gstr_Users_Name+"\nDesg  :"+gstr_User_Designation+"\nMoblie:"+gstr_User_Mobile);
                            timerId=startTimer(2000);
                            return;
                        }
                    }
                }
            }
            ui->label_user_details->setAlignment(Qt::AlignCenter);
            ui->label_user_details->setText("Invalid User..!");
            qApp->processEvents();
            qApp->processEvents();
            qApp->processEvents();
            system("sleep 1");
            ui->label_user_details->setText("Enter Password");
            ui->lineEdit_pwd->selectAll();
        }
        else
        {
            if(ui->lineEdit_pwd->text().contains("1111",Qt::CaseSensitive))
            {
                gstr_Users_server_id = "0000";
                gstrUserName = "mcadmin";
                gstr_Users_Name = "Device Admin";
                gstr_User_Designation = "Device Admin";
                gstrUserType = "2";



                qDebug()<<"mcadmin ===>>>"<<gstr_Users_server_id<<gstrUserName<<gstr_User_Designation<<gstrUserType<<gstr_User_Mobile<<"\n user count"<<QString::number(user_count);
                qApp->processEvents();


                ui->label_user_details->setAlignment(Qt::AlignCenter);
                ui->label_user_details->setText("Device Admin");
                isDefaultAdmin = true;
                timerId=startTimer(2000);
                return;
            }
            else
            {
                ui->label_user_details->setAlignment(Qt::AlignCenter);
                ui->label_user_details->setText("Invalid User..!");
                qApp->processEvents();
                qApp->processEvents();
                qApp->processEvents();
                system("sleep 1");
                ui->label_user_details->setText("Enter Password");
                ui->lineEdit_pwd->selectAll();
            }
        }
    }
}
