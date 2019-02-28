#include "batch_configuration.h"
#include "ui_batch_configuration.h"

#include <QMessageBox>

#include <global.h>
using namespace Global;

Batch_Configuration::Batch_Configuration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Batch_Configuration)
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

Batch_Configuration::~Batch_Configuration()
{
    delete ui;
}

void Batch_Configuration::call_Batch_Configuration()
{
    ui->groupBox_batch_home->move(0,0);
    ui->groupBox_purchase->move(0,0);
    ui->groupBox_Production->move(0,0);

    is_production_batch_close = false;
//    from_home_screen = false;
    total_production_batch_active = 0;

    ui->groupBox_batch_home->show();
    ui->groupBox_batch_home->raise();

    ui->groupBox_purchase->hide();
    ui->groupBox_purchase->lower();

    ui->groupBox_Production->hide();
    ui->groupBox_Production->lower();

    ui->label_info->hide();

    //    ui->comboBox_auto_Production_batch->installEventFilter(this);
    //    ui->comboBox_company_Production_batch->installEventFilter(this);
    //    ui->comboBox_van_Production_batch->installEventFilter(this);

    //    ui->groupBox_company_production->installEventFilter(this);
    //    ui->groupBox_auto_production->installEventFilter(this);


    ui->comboBox_batch_1->installEventFilter(this);
    ui->comboBox_batch_1_no->installEventFilter(this);

    ui->comboBox_batch_2->installEventFilter(this);
    ui->comboBox_batch_2_no->installEventFilter(this);

    ui->comboBox_batch_3->installEventFilter(this);
    ui->comboBox_batch_3_no->installEventFilter(this);

    ui->comboBox_batch_1->clear();
    ui->comboBox_batch_1_no->clear();

    ui->comboBox_batch_2->clear();
    ui->comboBox_batch_2_no->clear();

    ui->comboBox_batch_3->clear();
    ui->comboBox_batch_3_no->clear();

//    ui->pushButton_Production_close->hide();



    ui->groupBox_batch_home->installEventFilter(this);

    ui->pushButton_purchase->setFocus();

    if(!gstrUserName.contains("mcadmin",Qt::CaseSensitive))
    {
        if(!Home_ScreenObj->isDayOpen())
        {
            //            open_day(this);
        }
        if(!Home_ScreenObj->isShiftOpen())
        {
            //            open_shift(this);
        }
        if(!Home_ScreenObj->isShiftOpen_other())
        {
            //            open_shift_other(this);
        }
        if(!Home_ScreenObj->isShiftOpen_van())
        {
            //            open_shift_van(this);
        }
    }
}

void Batch_Configuration::load_details()
{
    QSqlQuery query;
    QStringList lst_batch_type,lst_batch_no;
    if(databaseObj->selectQuery("select batch_type,batch_no from production_batch_order",query))
    {
        if(query.next())
        {
            lst_batch_type << query.value(0).toString().trimmed();
            lst_batch_no << query.value(1).toString().trimmed().rightJustified(4,'0').prepend(query.value(0).toString().trimmed().at(0).toUpper());
            while(query.next())
            {
                lst_batch_type << query.value(0).toString().trimmed();
                lst_batch_no << query.value(1).toString().trimmed().rightJustified(4,'0').prepend(query.value(0).toString().trimmed().at(0).toUpper());
            }
            qDebug()<<"lst_batch_type ===>>>"<<lst_batch_type;
            qDebug()<<"lst_batch_no ===>>>"<<lst_batch_no;
        }
        else
        {
            lst_batch_name.clear();
            lst_batch_name << "Auto" << "Company" << "Van";

            ui->comboBox_batch_1->addItems(lst_batch_name);
            ui->comboBox_batch_1->setFocus();

            qDebug()<<"lst_van_batch_no else 2 ===>>>"<<lst_van_batch_no;
            qDebug()<<"lst_company_batch_no else 2 ===>>>"<<lst_company_batch_no;
            qDebug()<<"lst_auto_batch_no else 2 ===>>>"<<lst_auto_batch_no;


            qDebug()<<"lst_batch_type else ===>>>"<<lst_batch_type;
            qDebug()<<"lst_batch_no else ===>>>"<<lst_batch_no;
            return;
        }
    }
    else
    {
        qDebug()<<"lst_batch_type 1 else ===>>>"<<lst_batch_type;
        qDebug()<<"lst_batch_no 1 else===>>>"<<lst_batch_no;
    }


    if(lst_batch_type.size() > 0)
    {
        for(int i=0;i<lst_batch_no.size();i++)
        {
            lst_auto_batch_no.removeAt(lst_auto_batch_no.indexOf(lst_batch_no.at(i)));
            lst_van_batch_no.removeAt(lst_van_batch_no.indexOf(lst_batch_no.at(i)));
            lst_company_batch_no.removeAt(lst_company_batch_no.indexOf(lst_batch_no.at(i)));
        }
        for(int i=0;i<lst_batch_type.size();i++)
        {
            qDebug()<<"batch in production ===>>>"<<lst_batch_type.size()<<lst_batch_type.at(i);
            if(i==0)
            {
                ui->comboBox_batch_1->addItem(lst_batch_type.at(0));
                ui->comboBox_batch_1_no->addItem(lst_batch_no.at(0));
                ui->comboBox_batch_1->setEnabled(false);
                ui->comboBox_batch_1_no->setEnabled(false);

                ui->comboBox_batch_2->setFocus();

            }
            if(i==1)
            {
                ui->comboBox_batch_2->addItem(lst_batch_type.at(1));
                ui->comboBox_batch_2_no->addItem(lst_batch_no.at(1));
                ui->comboBox_batch_2->setEnabled(false);
                ui->comboBox_batch_2_no->setEnabled(false);
                ui->comboBox_batch_3->setFocus();
            }

            if(i==2)
            {
                ui->comboBox_batch_3->addItem(lst_batch_type.at(2));
                ui->comboBox_batch_3_no->addItem(lst_batch_no.at(2));
                ui->comboBox_batch_3->setEnabled(false);
                ui->comboBox_batch_3_no->setEnabled(false);
                ui->pushButton_purchase_back_2->setFocus();
            }

            lst_batch_name.clear();
            lst_batch_name << "Auto" << "Company" << "Van";
        }
        if(ui->comboBox_batch_1->isEnabled())
        {
            ui->comboBox_batch_1->addItems(lst_batch_name);
            ui->comboBox_batch_1->setFocus();
            return;
        }

        if(ui->comboBox_batch_2->isEnabled())
        {
            ui->comboBox_batch_2->addItems(lst_batch_name);
            ui->comboBox_batch_2->setFocus();
            return;
        }
        if(ui->comboBox_batch_3->isEnabled())
        {
            ui->comboBox_batch_3->addItems(lst_batch_name);
            ui->comboBox_batch_3->setFocus();
            return;
        }
    }



    lst_batch_name.clear();
    lst_batch_name << "Auto" << "Company" << "Van";

    if(lst_auto_batch_no.isEmpty())
    {
        lst_batch_name.removeAt(0);
    }
    if(lst_company_batch_no.isEmpty())
    {
        lst_batch_name.removeAt(1);
    }
    if(lst_van_batch_no.isEmpty())
    {
        lst_batch_name.removeAt(2);
    }

    ui->comboBox_batch_1->addItems(lst_batch_name);
    ui->comboBox_batch_1->setFocus();

    qDebug()<<"lst_van_batch_no 2 ===>>>"<<lst_van_batch_no;
    qDebug()<<"lst_company_batch_no 2 ===>>>"<<lst_company_batch_no;
    qDebug()<<"lst_auto_batch_no 2 ===>>>"<<lst_auto_batch_no;

}

void Batch_Configuration::keyPressEvent(QKeyEvent *ke)
{
    if(ke->key()== Qt::Key_Escape)
    {
        if(!from_home_screen)
        {
            from_home_screen = false;
            this->close();
            menuObj->call_menu();
            menuObj->show();
            return;
//            this->close();
//            Home_ScreenObj->call_Home_Screen();
////            Home_ScreenObj->check_batch();
////            Home_ScreenObj->day_shift();
//            Home_ScreenObj->show();
            return;
        }
        if(ui->groupBox_batch_home->isVisible())
        {
            this->close();
            menuObj->call_menu();
            menuObj->show();
            return;
        }
        if(ui->groupBox_purchase->isVisible() || ui->groupBox_Production->isVisible())
        {
            call_Batch_Configuration();
            return;
        }
    }
    if(ke->key()== Qt::Key_F1)
    {
        if(ui->groupBox_Production->isVisible())
        {
            on_pushButton_purchase_save_clicked();
        }
    }

}



void Batch_Configuration::on_pushButton_purchase_clicked()
{
    show_screen(1);
}

void Batch_Configuration::show_screen(int scr)
{
    if(scr == 1)
    {

        if(is_production_batch_close)
        {

            ui->groupBox_batch_home->hide();
            ui->groupBox_batch_home->lower();

            ui->groupBox_purchase->show();
            ui->groupBox_purchase->raise();

            ui->groupBox_Production->hide();
            ui->groupBox_Production->lower();

            ui->pushButton_Company->setFocus();

            QSqlQuery query;
            if(databaseObj->selectQuery("select production_company_batch_no,production_company_batch_status,production_auto_batch_no,production_auto_batch_status,production_van_batch_no,production_van_batch_status from configuration_master",query))
            {
                if(query.next())
                {
                    str_cmp_pro_batch_status = query.value(0).toString().trimmed();
                    str_cmp_pro_batch_no = query.value(1).toString().trimmed();

                    str_auto_pro_batch_status = query.value(2).toString().trimmed();
                    str_auto_pro_batch_no = query.value(3).toString().trimmed();

                    str_van_pro_batch_status = query.value(4).toString().trimmed();
                    str_van_pro_batch_no = query.value(5).toString().trimmed();


                    qDebug()<<"str_cmp_pro_batch_status ===>>>"<<str_cmp_pro_batch_status;
                    qDebug()<<"str_cmp_pro_batch_no ===>>>"<<str_cmp_pro_batch_no;
                    qDebug()<<"str_auto_pro_batch_status ===>>>"<<str_auto_pro_batch_status;
                    qDebug()<<"str_auto_pro_batch_no ===>>>"<<str_auto_pro_batch_no;
                    qDebug()<<"str_van_pro_batch_status ===>>>"<<str_van_pro_batch_status;
                    qDebug()<<"str_van_pro_batch_no ===>>>"<<str_van_pro_batch_no;


                    if(str_cmp_pro_batch_status.toInt() >= 1)
                    {
                        total_production_batch_active+=1;
                    }
                    if(str_auto_pro_batch_status.toInt() >= 1)
                    {
                        total_production_batch_active+=1;
                    }
                    if(str_van_pro_batch_status.toInt() >= 1)
                    {
                        total_production_batch_active+=1;
                    }
                    qDebug()<<"total_production_batch_active ===>>>"<<QString::number(total_production_batch_active);
                }
            }
            return;
        }


        //! screen for purchase
        ui->groupBox_batch_home->hide();
        ui->groupBox_batch_home->lower();

        ui->groupBox_purchase->show();
        ui->groupBox_purchase->raise();

        ui->groupBox_Production->hide();
        ui->groupBox_Production->lower();

        ui->pushButton_Company->setFocus();

        QSqlQuery stock_qur;
        if(Home_ScreenObj->isShiftOpen()){
            ui->pushButton_Company->setEnabled(true);
            ui->pushButton_Company->setText("Company Batch Close:"+gstrshift_no.rightJustified(3,'0'));
            stock_qur.clear();
            if(databaseObj->selectQuery("select sum(total_husk_produced) from company_batch_no where batch_no='"+gstrshift_no+"'",stock_qur))
            {
                if(stock_qur.next())
                {
                    available_stock_company = stock_qur.value(0).toString().trimmed();
                }
            }
        }
        else
            ui->pushButton_Company->setEnabled(false);

        if(Home_ScreenObj->isShiftOpen_other()){
            ui->pushButton_auto->setEnabled(true);
            ui->pushButton_auto->setText("Auto Batch Close   :"+gstrshift_no_other.rightJustified(3,'0'));
            stock_qur.clear();
            if(databaseObj->selectQuery("select sum(total_husk_produced) from other_batch_no where batch_no='"+gstrshift_no_other+"'",stock_qur))
            {
                if(stock_qur.next())
                {
                    available_stock_auto = stock_qur.value(0).toString().trimmed();
                }
            }
        }
        else
            ui->pushButton_auto->setEnabled(false);

        if(Home_ScreenObj->isShiftOpen_van()){
            ui->pushButton_van->setEnabled(true);
            ui->pushButton_van->setText("Van Batch Close    :"+gstrshift_no_van.rightJustified(3,'0'));
            stock_qur.clear();
            if(databaseObj->selectQuery("select sum(total_husk_produced) from van_batch_no where batch_no='"+gstrshift_no_van+"'",stock_qur))
            {
                if(stock_qur.next())
                {
                    available_stock_van = stock_qur.value(0).toString().trimmed();
                }
            }
        }
        else
            ui->pushButton_van->setEnabled(false);

        ui->pushButton_esc->setFocus();

        return;
    }
    if(scr == 2)
    {
        //! screen for production
        ui->groupBox_batch_home->hide();
        ui->groupBox_batch_home->lower();

        ui->groupBox_purchase->hide();
        ui->groupBox_purchase->lower();

        ui->groupBox_Production->show();
        ui->groupBox_Production->raise();

        return;
    }
}

void Batch_Configuration::on_pushButton_Production_clicked()
{
    show_screen(2);
}

void Batch_Configuration::on_pushButton_Company_clicked()
{
    if(isShift_Open)
    {

        company_or_other = 0;

//        this->close();
//        Batch_CloseObj = new Batch_Close;
//        Batch_CloseObj->call_Batch_Close();
//        Batch_CloseObj->show();


        if(Home_ScreenObj->close_shift(this))
        {
            call_Batch_Configuration();
//            this->close();
//            menuObj->call_menu();
//            menuObj->show();
//            return;
        }


        //        Home_ScreenObj->close_shift(this);
        //        ui->pushButton_Shift_Close->setFocus();

    }
    else
    {
#if(SDK75)

        g_ccmainObj->messagebox(this,"Shift close",eMessageType_Information,"Company Batch already closed.");
#endif
        ui->pushButton_Company->setFocus();
    }
}

void Batch_Configuration::on_pushButton_auto_clicked()
{
    if(isShift_Open_other)
    {
        company_or_other = 1;

//        this->close();
//        Batch_CloseObj = new Batch_Close;
//        Batch_CloseObj->call_Batch_Close();
//        Batch_CloseObj->show();

        if(Home_ScreenObj->close_shift_other(this))
        {

            call_Batch_Configuration();
//            this->close();
//            menuObj->call_menu();
//            menuObj->show();
//            return;
        }

        //        Home_ScreenObj->close_shift_other(this);
        //        ui->pushButton_Other_batch_close->setFocus();
    }
    else
    {
#if(SDK75)

        g_ccmainObj->messagebox(this,"Shift close",eMessageType_Information,"Other Batch already closed.");
#endif
        ui->pushButton_auto->setFocus();
    }
}

void Batch_Configuration::on_pushButton_van_clicked()
{
    if(isShift_Open_van)
    {
        company_or_other = 2;

//        this->close();
//        Batch_CloseObj = new Batch_Close;
//        Batch_CloseObj->call_Batch_Close();
//        Batch_CloseObj->show();

        if(Home_ScreenObj->close_shift_van(this))
        {
            call_Batch_Configuration();
//            this->close();
//            menuObj->call_menu();
//            menuObj->show();
//            return;
        }


        //        Home_ScreenObj->close_shift_van(this);
        //        ui->pushButton_van_batch_close->setFocus();
    }
    else
    {
#if(SDK75)
        g_ccmainObj->messagebox(this,"Shift close",eMessageType_Information,"van Batch already closed.");
#endif
        ui->pushButton_van->setFocus();
    }
}

void Batch_Configuration::on_pushButton_Production_open_clicked()
{

    //    if(total_production_batch_active == 2)
    //    {
    //#if(NativeCompile)
    //            QMessageBox gMsg_box;
    //            QFont gFont;
    //            gFont.setFamily("DejaVu Sans Mono");
    //            gFont.setPointSize(12);
    //            gMsg_box.setFont(gFont);
    //            gMsg_box.setParent(this);

    //            if(gMsg_box.information(this, "Status","All Batch are opened..!",QMessageBox::Ok) == QMessageBox::Ok)
    //            {
    //                ui->pushButton_Production_open->setFocus();
    //            }
    //            else
    //            {

    //            }
    //#endif

    //#if(SDK75)
    //            int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"All Batch are opened..!",16,14);
    //#endif

    //        return;
    //    }

    //    ui->comboBox_auto_Production_batch->clear();
    //    ui->comboBox_company_Production_batch->clear();
    //    ui->comboBox_van_Production_batch->clear();

    lst_company_batch_no.clear();
    lst_auto_batch_no.clear();
    lst_van_batch_no.clear();

    ui->comboBox_batch_1->setEnabled(true);
    ui->comboBox_batch_1_no->setEnabled(true);

    ui->comboBox_batch_2->setEnabled(true);
    ui->comboBox_batch_2_no->setEnabled(true);

    ui->comboBox_batch_3->setEnabled(true);
    ui->comboBox_batch_3_no->setEnabled(true);

    QSqlQuery query;
    if(databaseObj->selectQuery("select batch_no from company_batch_no where status='0' and production_status='2'",query))
    {
        if(query.next())
        {
            lst_company_batch_no.clear();
            lst_company_batch_no << query.value(0).toString().trimmed().rightJustified(4,'0').prepend("C");
            while(query.next())
            {
                lst_company_batch_no << query.value(0).toString().trimmed().rightJustified(4,'0').prepend("C");
            }
        }

    }

    query.clear();
    if(databaseObj->selectQuery("select batch_no from other_batch_no where status='0' and production_status='2'",query))
    {
        if(query.next())
        {
            lst_auto_batch_no.clear();
            lst_auto_batch_no << query.value(0).toString().trimmed().rightJustified(4,'0').prepend("A");
            while(query.next())
            {
                lst_auto_batch_no << query.value(0).toString().trimmed().rightJustified(4,'0').prepend("A");
            }
        }

    }

    query.clear();
    if(databaseObj->selectQuery("select batch_no from van_batch_no where status='0' and production_status='2'",query))
    {
        if(query.next())
        {
            lst_van_batch_no.clear();
            lst_van_batch_no << query.value(0).toString().trimmed().rightJustified(4,'0').prepend("V");
            while(query.next())
            {
                lst_van_batch_no << query.value(0).toString().trimmed().rightJustified(4,'0').prepend("V");
            }
        }

    }

    qDebug()<<"lst_van_batch_no ===>>>"<<lst_van_batch_no;
    qDebug()<<"lst_company_batch_no ===>>>"<<lst_company_batch_no;
    qDebug()<<"lst_auto_batch_no ===>>>"<<lst_auto_batch_no;

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
            ui->pushButton_Production_open->setFocus();
        }
        else
        {

        }
#endif

#if(SDK75)
        int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"Closed Batch\nNot Available..!",16,14);
        ui->pushButton_Production_open->setFocus();
#endif

        return;
    }

    //    if(lst_auto_batch_no.size() == 0)
    //    {
    //        ui->groupBox_auto_production->setEnabled(false);
    //    }

    //    if(lst_company_batch_no.size() == 0)
    //    {
    //        ui->groupBox_company_production->setEnabled(false);
    //    }
    //    if(lst_van_batch_no.size() == 0)
    //    {
    //        ui->groupBox_van_production->setEnabled(false);
    //    }

    QSqlQuery query1;
    if(databaseObj->selectQuery("select count(*) from production_batch_order",query1))
    {
        if(query1.next())
        {
            production_batch_count = query1.value(0).toString().trimmed();
        }
    }

    //    for(int i=0;i<=lst_production_batch_type.size();i++)
    //    {
    //        if(lst_production_batch_type.at(i).contains("company"))
    //        {
    //            ui->groupBox_company_production->setEnabled(false);
    //        }
    //        if(lst_production_batch_type.at(i).contains("auto"))
    //        {
    //            ui->groupBox_auto_production->setEnabled(false);
    //        }
    //        if(lst_production_batch_type.at(i).contains("van"))
    //        {
    //            ui->groupBox_van_production->setEnabled(false);
    //        }
    //    }

    tmp_total_production_batch_active = total_production_batch_active;

    //    ui->comboBox_company_Production_batch->addItems(lst_company_batch_no);
    //    ui->comboBox_auto_Production_batch->addItems(lst_auto_batch_no);
    //    ui->comboBox_van_Production_batch->addItems(lst_van_batch_no);

    //    ui->groupBox_company_production->setFocus();
    //    ui->label_batch_close_title->setText("Purchase Batch Config");

    show_screen(2);

    load_details();

}

void Batch_Configuration::on_pushButton_Production_close_clicked()
{

//    is_production_batch_close = true;
//    ui->label_batch_close_title->setText("Production Batch Config");

//    show_screen(1);

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
            int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Error,"Do You Want To\nClose "+str_batch_order_name.toUpper()+" "+str_batch_order_no+"?",16,14,"YES","NO");
            if(ret==1)
            {
                //!yes

                if(str_batch_order_name.contains("company",Qt::CaseInsensitive))
                {
                    Day_CloseObj->company_or_other = 0;
                }
                if(str_batch_order_name.contains("auto",Qt::CaseInsensitive))
                {
                    Day_CloseObj->company_or_other = 1;
                }
                if(str_batch_order_name.contains("van",Qt::CaseInsensitive))
                {
                    Day_CloseObj->company_or_other = 2;
                }

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
                                QString send_msg = "gammu sendsms TEXT "+number+" -text \""+str_batch_order_name.toUpper()+" "+str_batch_order_no+" by "+gstrUserName+"\"";
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
                    ui->pushButton_Production_close->setFocus();
//                    on_pushButton_back_clicked();
                }

#endif




                    ui->pushButton_purchase->setFocus();
                }
//                this->close();
//                Batch_CloseObj->from_batch_config = true;
//                Batch_CloseObj->call_Batch_Close();
//                Batch_CloseObj->show();
            }
            else
            {
                qDebug()<<"not close production batch ===>>>";
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
        ui->pushButton_Production_close->setFocus();
#endif

        }
    }



}

void Batch_Configuration::on_groupBox_company_production_clicked()
{

}

bool Batch_Configuration::eventFilter(QObject *target, QEvent *event)
{
    QKeyEvent *key = static_cast <QKeyEvent*> (event);

    if(target == ui->comboBox_batch_1)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->comboBox_batch_1->hasFocus())
                {
                    tmp_total_production_batch_active=-1;
                    if(ui->comboBox_batch_1->currentText().contains("Auto",Qt::CaseInsensitive))
                    {
                        ui->comboBox_batch_1_no->clear();
                        ui->comboBox_batch_1_no->addItems(lst_auto_batch_no);
                        ui->comboBox_batch_1_no->setFocus();
                    }
                    else if(ui->comboBox_batch_1->currentText().contains("Company",Qt::CaseInsensitive))
                    {
                        ui->comboBox_batch_1_no->clear();
                        ui->comboBox_batch_1_no->addItems(lst_company_batch_no);
                        ui->comboBox_batch_1_no->setFocus();
                    }
                    else if(ui->comboBox_batch_1->currentText().contains("Van",Qt::CaseInsensitive))
                    {
                        ui->comboBox_batch_1_no->clear();
                        ui->comboBox_batch_1_no->addItems(lst_van_batch_no);
                        ui->comboBox_batch_1_no->setFocus();
                    }
                }
                return true;
            }
        }
    }
    else if(target == ui->comboBox_batch_2)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->comboBox_batch_2->hasFocus())
                {
                    tmp_total_production_batch_active=-1;
                    if(ui->comboBox_batch_2->currentText().contains("Auto",Qt::CaseInsensitive))
                    {
                        ui->comboBox_batch_2_no->clear();
                        ui->comboBox_batch_2_no->addItems(lst_auto_batch_no);
                        ui->comboBox_batch_2_no->setFocus();
                    }
                    else if(ui->comboBox_batch_2->currentText().contains("Company",Qt::CaseInsensitive))
                    {
                        ui->comboBox_batch_2_no->clear();
                        ui->comboBox_batch_2_no->addItems(lst_company_batch_no);
                        ui->comboBox_batch_2_no->setFocus();
                    }
                    else if(ui->comboBox_batch_2->currentText().contains("Van",Qt::CaseInsensitive))
                    {
                        ui->comboBox_batch_2_no->clear();
                        ui->comboBox_batch_2_no->addItems(lst_van_batch_no);
                        ui->comboBox_batch_2_no->setFocus();
                    }
                }
                return true;
            }
        }
    }
    else if(target == ui->comboBox_batch_3)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->comboBox_batch_3->hasFocus())
                {
                    tmp_total_production_batch_active=-1;
                    if(ui->comboBox_batch_3->currentText().contains("Auto",Qt::CaseInsensitive))
                    {
                        ui->comboBox_batch_3_no->clear();
                        ui->comboBox_batch_3_no->addItems(lst_auto_batch_no);
                        ui->comboBox_batch_3_no->setFocus();
                    }
                    else if(ui->comboBox_batch_3->currentText().contains("Company",Qt::CaseInsensitive))
                    {
                        ui->comboBox_batch_3_no->clear();
                        ui->comboBox_batch_3_no->addItems(lst_company_batch_no);
                        ui->comboBox_batch_3_no->setFocus();
                    }
                    else if(ui->comboBox_batch_3->currentText().contains("Van",Qt::CaseInsensitive))
                    {
                        ui->comboBox_batch_3_no->clear();
                        ui->comboBox_batch_3_no->addItems(lst_van_batch_no);
                        ui->comboBox_batch_3_no->setFocus();
                    }
                }
                return true;
            }
        }
    }
    else if(target == ui->comboBox_batch_1_no)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->comboBox_batch_1_no->hasFocus())
                {
                    if(!ui->comboBox_batch_1_no->currentText().isEmpty())
                    {
                        if(ui->comboBox_batch_1->currentText().contains("Company",Qt::CaseInsensitive))
                        {
                            lst_company_batch_no.removeAt(lst_company_batch_no.indexOf(ui->comboBox_batch_1_no->currentText()));
                        }
                        if(ui->comboBox_batch_1->currentText().contains("Auto",Qt::CaseInsensitive))
                        {
                            lst_auto_batch_no.removeAt(lst_auto_batch_no.indexOf(ui->comboBox_batch_1_no->currentText()));
                        }
                        if(ui->comboBox_batch_1->currentText().contains("Van",Qt::CaseInsensitive))
                        {
                            lst_van_batch_no.removeAt(lst_van_batch_no.indexOf(ui->comboBox_batch_1_no->currentText()));
                        }
                        

                        ui->comboBox_batch_2->addItems(lst_batch_name);
                        ui->comboBox_batch_2->setFocus();
                    }
                }
                return true;
            }
        }
    }
    else if(target == ui->comboBox_batch_2_no)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->comboBox_batch_2_no->hasFocus())
                {
                    if(!ui->comboBox_batch_2_no->currentText().isEmpty())
                    {

                        if(ui->comboBox_batch_2->currentText().contains("Company",Qt::CaseInsensitive))
                        {
                            lst_company_batch_no.removeAt(lst_company_batch_no.indexOf(ui->comboBox_batch_2_no->currentText()));
                        }
                        if(ui->comboBox_batch_2->currentText().contains("Auto",Qt::CaseInsensitive))
                        {
                            lst_auto_batch_no.removeAt(lst_auto_batch_no.indexOf(ui->comboBox_batch_2_no->currentText()));
                        }
                        if(ui->comboBox_batch_2->currentText().contains("Van",Qt::CaseInsensitive))
                        {
                            lst_van_batch_no.removeAt(lst_van_batch_no.indexOf(ui->comboBox_batch_2_no->currentText()));
                        }

                        ui->comboBox_batch_3->addItems(lst_batch_name);
                        ui->comboBox_batch_3->setFocus();
                    }
                }
                return true;
            }
        }
    }
    else if(target == ui->comboBox_batch_3_no)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->comboBox_batch_3_no->hasFocus())
                {
                    if(!ui->comboBox_batch_3_no->currentText().isEmpty())
                    {

                        if(ui->comboBox_batch_3->currentText().contains("Company",Qt::CaseInsensitive))
                        {
                            lst_company_batch_no.removeAt(lst_company_batch_no.indexOf(ui->comboBox_batch_3_no->currentText()));
                        }
                        if(ui->comboBox_batch_3->currentText().contains("Auto",Qt::CaseInsensitive))
                        {
                            lst_auto_batch_no.removeAt(lst_auto_batch_no.indexOf(ui->comboBox_batch_3_no->currentText()));
                        }
                        if(ui->comboBox_batch_3->currentText().contains("Van",Qt::CaseInsensitive))
                        {
                            lst_van_batch_no.removeAt(lst_van_batch_no.indexOf(ui->comboBox_batch_3_no->currentText()));
                        }

                        ui->pushButton_purchase_save->setFocus();
                    }
                }
                return true;
            }
        }
    }
    else
    {
        return false;
    }
    return false;
}

void Batch_Configuration::on_groupBox_company_production_toggled(bool arg1)
{

}

void Batch_Configuration::on_pushButton_purchase_save_clicked()
{
    if(!is_production_batch_close)
    {
        if(!ui->comboBox_batch_1_no->currentText().isEmpty() && ui->comboBox_batch_1_no->isEnabled())
        {
            if(ui->comboBox_batch_1->currentText().contains("company",Qt::CaseInsensitive))
            {
                if(databaseObj->executeCommand("insert into production_batch_order (batch_type,batch_no,husk_available,batch_status) values ('company','"+ui->comboBox_batch_1_no->currentText().remove("C").trimmed()+"',(select total_husk_produced  from company_batch_no where batch_no='"+ui->comboBox_batch_1_no->currentText().remove("C").trimmed()+"'),'2')"))
                {
                    if(databaseObj->executeCommand("update company_batch_no set production_status='1' where batch_no='"+ui->comboBox_batch_1_no->currentText().remove("C").trimmed()+"'"))
                    {

                    }
                }
            }
            if(ui->comboBox_batch_1->currentText().contains("auto",Qt::CaseInsensitive))
            {
                if(databaseObj->executeCommand("insert into production_batch_order (batch_type,batch_no,husk_available,batch_status) values ('auto','"+ui->comboBox_batch_1_no->currentText().remove("A").trimmed()+"',(select total_husk_produced  from other_batch_no where batch_no='"+ui->comboBox_batch_1_no->currentText().remove("A").trimmed()+"'),'2')"))
                {
                    if(databaseObj->executeCommand("update other_batch_no set production_status='1' where batch_no='"+ui->comboBox_batch_1_no->currentText().remove("A").trimmed()+"'"))
                    {

                    }
                }
            }
            if(ui->comboBox_batch_1->currentText().contains("van",Qt::CaseInsensitive))
            {
                if(databaseObj->executeCommand("insert into production_batch_order (batch_type,batch_no,husk_available,batch_status) values ('van','"+ui->comboBox_batch_1_no->currentText().remove("V").trimmed()+"',(select total_husk_produced  from van_batch_no where batch_no='"+ui->comboBox_batch_1_no->currentText().remove("V").trimmed()+"'),'2')"))
                {
                    if(databaseObj->executeCommand("update van_batch_no set production_status='1' where batch_no='"+ui->comboBox_batch_1_no->currentText().remove("A").trimmed()+"'"))
                    {

                    }
                }
            }
        }

        if(!ui->comboBox_batch_2_no->currentText().isEmpty() && ui->comboBox_batch_2_no->isEnabled())
        {
            if(ui->comboBox_batch_2->currentText().contains("company",Qt::CaseInsensitive))
            {
                if(databaseObj->executeCommand("insert into production_batch_order (batch_type,batch_no,husk_available,batch_status) values ('company','"+ui->comboBox_batch_2_no->currentText().remove("C").trimmed()+"',(select total_husk_produced  from company_batch_no where batch_no='"+ui->comboBox_batch_2_no->currentText().remove("C").trimmed()+"'),'2')"))
                {
                    if(databaseObj->executeCommand("update company_batch_no set production_status='1' where batch_no='"+ui->comboBox_batch_2_no->currentText().remove("C").trimmed()+"'"))
                    {

                    }
                }
            }
            if(ui->comboBox_batch_2->currentText().contains("auto",Qt::CaseInsensitive))
            {
                if(databaseObj->executeCommand("insert into production_batch_order (batch_type,batch_no,husk_available,batch_status) values ('auto','"+ui->comboBox_batch_2_no->currentText().remove("A").trimmed()+"',(select total_husk_produced  from other_batch_no where batch_no='"+ui->comboBox_batch_2_no->currentText().remove("A").trimmed()+"'),'2')"))
                {
                    if(databaseObj->executeCommand("update other_batch_no set production_status='1' where batch_no='"+ui->comboBox_batch_2_no->currentText().remove("A").trimmed()+"'"))
                    {

                    }
                }
            }
            if(ui->comboBox_batch_2->currentText().contains("van",Qt::CaseInsensitive))
            {
                if(databaseObj->executeCommand("insert into production_batch_order (batch_type,batch_no,husk_available,batch_status) values ('van','"+ui->comboBox_batch_2_no->currentText().remove("V").trimmed()+"',(select total_husk_produced  from van_batch_no where batch_no='"+ui->comboBox_batch_2_no->currentText().remove("V").trimmed()+"'),'2')"))
                {
                    if(databaseObj->executeCommand("update van_batch_no set production_status='1' where batch_no='"+ui->comboBox_batch_2_no->currentText().remove("V").trimmed()+"'"))
                    {

                    }
                }
            }
        }

        if(!ui->comboBox_batch_3_no->currentText().isEmpty() && ui->comboBox_batch_3_no->isEnabled())
        {
            if(ui->comboBox_batch_3->currentText().contains("company",Qt::CaseInsensitive))
            {
                if(databaseObj->executeCommand("insert into production_batch_order (batch_type,batch_no,husk_available,batch_status) values ('company','"+ui->comboBox_batch_3_no->currentText().remove("C").trimmed()+"',(select total_husk_produced  from company_batch_no where batch_no='"+ui->comboBox_batch_3_no->currentText().remove("C").trimmed()+"'),'2')"))
                {
                    if(databaseObj->executeCommand("update company_batch_no set production_status='1' where batch_no='"+ui->comboBox_batch_3_no->currentText().remove("C").trimmed()+"'"))
                    {

                    }
                }
            }
            if(ui->comboBox_batch_3->currentText().contains("auto",Qt::CaseInsensitive))
            {
                if(databaseObj->executeCommand("insert into production_batch_order (batch_type,batch_no,husk_available,batch_status) values ('auto','"+ui->comboBox_batch_3_no->currentText().remove("A").trimmed()+"',(select total_husk_produced  from other_batch_no where batch_no='"+ui->comboBox_batch_3_no->currentText().remove("A").trimmed()+"'),'2')"))
                {
\
                    if(databaseObj->executeCommand("update other_batch_no set production_status='1' where batch_no='"+ui->comboBox_batch_3_no->currentText().remove("A").trimmed()+"'"))
                    {

                    }
                }
            }
            if(ui->comboBox_batch_3->currentText().contains("van",Qt::CaseInsensitive))
            {
                if(databaseObj->executeCommand("insert into production_batch_order (batch_type,batch_no,husk_available,batch_status) values ('van','"+ui->comboBox_batch_3_no->currentText().remove("V").trimmed()+"',(select total_husk_produced  from van_batch_no where batch_no='"+ui->comboBox_batch_3_no->currentText().remove("V").trimmed()+"'),'2')"))
                {
                    if(databaseObj->executeCommand("update van_batch_no set production_status='1' where batch_no='"+ui->comboBox_batch_3_no->currentText().remove("V").trimmed()+"'"))
                    {

                    }
                }
            }
        }

#if(NativeCompile)
                QMessageBox gMsg_box;
                QFont gFont;
                gFont.setFamily("DejaVu Sans Mono");
                gFont.setPointSize(12);
                gMsg_box.setFont(gFont);
                gMsg_box.setParent(this);

                if(gMsg_box.information(this, "Success","Batch Saved Successfully..!",QMessageBox::Ok) == QMessageBox::Ok)
                {
//                    call_Add_User();
                    call_Batch_Configuration();
                }
#endif

#if(SDK75)
                int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"Batch Saved Successfully.",16,14);
                call_Batch_Configuration();
#endif

    }

    //    if(ui->groupBox_company_production->isEnabled())
    //    {
    //        if(databaseObj->executeCommand("insert into production_batch_order (batch_type,batch_no) values ('company','"+ui->comboBox_company_Production_batch->currentText().remove("C").trimmed()+"'))"))
    //        {

    //        }
    //    }
    //    if(ui->groupBox_auto_production->isEnabled())
    //    {
    //        if(databaseObj->executeCommand("insert into production_batch_order (batch_type,batch_no) values ('auto','"+ui->comboBox_company_Production_batch->currentText().remove("C").trimmed()+"'))"))
    //        {

    //        }
    //    }
    //    if(ui->groupBox_company_production->isEnabled())
    //    {
    //        if(databaseObj->executeCommand("insert into production_batch_order (batch_type,batch_no) values ('van','"+ui->comboBox_company_Production_batch->currentText().remove("C").trimmed()+"'))"))
    //        {

    //        }
    //    }
}

void Batch_Configuration::execProcess(QString ProcessName, QString Message)
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
                ui->pushButton_Production_close->setFocus();
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
