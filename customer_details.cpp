#include "customer_details.h"
#include "ui_customer_details.h"
#include <math.h>

#include <global.h>
using namespace Global;

Customer_Details::Customer_Details(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Customer_Details)
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

Customer_Details::~Customer_Details()
{
    delete ui;
}

void Customer_Details::keyPressEvent(QKeyEvent *ke)
{
    if(ke->key()== Qt::Key_Escape)
    {
        if(ui->groupBox->isVisible())
        {
            this->close();
            Home_ScreenObj->set_focus();
            Home_ScreenObj->show();
            return;
        }
        if(ui->groupBox_preview->isVisible())
        {
            ui->groupBox_preview->hide();
            ui->groupBox->show();
            ui->pushButton_print->setEnabled(true);
            ui->pushButton_print->setFocus();
            return;
        }

    }
    if(ke->key()== Qt::Key_F1)
    {
        if(ui->groupBox_preview->isVisible())
        {
            on_pushButton_print_4_clicked();
        }
    }


}

void Customer_Details::call_Customer_Details()
{
    ui->lineEdit_Excess->clear();
    ui->lineEdit_paid->clear();

    ui->label_excess_title->hide();
    ui->label_excess_paid->hide();

    ui->label_balance_title->hide();
    ui->label_final_balance->hide();

    ui->label_count->clear();
    ui->label_est_amt->clear();
    ui->label_final_balance->clear();
    ui->label_Payable->clear();

    ui->label_previous_balance->clear();

    ui->label_unit_5->hide();
    ui->label_unit_8->hide();

    ui->label_kms->hide();

    ui->groupBox_preview->hide();
    ui->textEdit->clear();

    ui->label_info_2->hide();
    ui->label_info_2->lower();
    ui->label_info->hide();
    ui->label_info->lower();

    ui->groupBox->show();
    ui->groupBox->raise();

    pending_print = false;

    ui->lineEdit_Excess->setValidator(gAmtValidator1);
    ui->lineEdit_paid->setValidator(gAmtValidator1);

    //    select configuration_master.husk_per_cft,configuration_master.rate_of_cft,configuration_master.husk_per_bale,configuration_master.rate_of_husk from configuration_master

    if(Home_ScreenObj->selected_cus_balance_type.toInt() == 0)
    {
        ui->label_balance_type->setText("Op.Advance:");
    }

    if(Home_ScreenObj->selected_cus_balance_type.toInt() == 1)
    {
        ui->label_balance_type->setText("Op.Pending:");
    }

    if(Home_ScreenObj->selected_vehicle_type.toInt() == 0)
    {
        ui->label_kms->show();
        ui->label_kms->raise();
        ui->label_kms->setText(Home_ScreenObj->distaance_covered+"km");

    }


    qDebug()<<"test1 ===>>>";
    ui->label_previous_balance->setText(Home_ScreenObj->selected_cus_balance);
    qDebug()<<"test2 ===>>>"<<Home_ScreenObj->selected_cus_balance;

    ui->label_count->setText(Home_ScreenObj->final_count);
    qDebug()<<"test3 ===>>>"<<Home_ScreenObj->final_count;

    ui->label_est_amt->setText(Home_ScreenObj->estimated_amount);
    qDebug()<<"test4 ===>>>"<<Home_ScreenObj->estimated_amount;


    ui->lineEdit_Excess->installEventFilter(this);
    ui->lineEdit_paid->installEventFilter(this);



    ui->lineEdit_Excess->setFocus();
}

//bool Customer_Details::eventFilter(QObject *target, QEvent *event)
//{
//    QKeyEvent *key = static_cast <QKeyEvent*> (event);
//    if(target == ui->lineEdit_Excess)
//    {
////        if(event->type() == QEvent::FocusIn)
////        {
//////            g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
////            //            g_ccmainObj->setKeypadModeLock(false);
////            return true;
////        }
//    }
//    else if(target == ui->lineEdit_Excess)
//    {
//        if(event->type() == QEvent::FocusIn)
//        {
////            g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
//            //            g_ccmainObj->setKeypadModeLock(false);
//            return true;
//        }
//    }
//    else
//    {
//        return false;
//    }
//    return false;
//}

void Customer_Details::on_lineEdit_Excess_returnPressed()
{
    if(!ui->lineEdit_Excess->text().isEmpty())
    {

        qDebug()<<"Home_ScreenObj->selected_cus_balance_type ===>>>"<<Home_ScreenObj->selected_cus_balance_type;
        if(Home_ScreenObj->selected_cus_balance_type.toInt() == 0)
        {
            payable_amt = QString::number(ceil(ui->lineEdit_Excess->text().toFloat() - Home_ScreenObj->selected_cus_balance.toFloat()),'f',2);
            ui->label_Payable->setText(payable_amt);
            ui->lineEdit_paid->setFocus();

        }

        if(Home_ScreenObj->selected_cus_balance_type.toInt() == 1)
        {
            payable_amt = QString::number(ceil(ui->lineEdit_Excess->text().toFloat() + Home_ScreenObj->selected_cus_balance.toFloat()),'f',2);
            ui->label_Payable->setText(payable_amt);
            ui->lineEdit_paid->setFocus();
        }

        if(Home_ScreenObj->selected_cus_balance_type.toInt() == 2)
        {
            payable_amt = QString::number(ceil(ui->lineEdit_Excess->text().toFloat()),'f',2);
            ui->label_Payable->setText(payable_amt);
            ui->lineEdit_paid->setFocus();
        }
        float excess_calc = ui->lineEdit_Excess->text().toFloat() - Home_ScreenObj->estimated_amount.toFloat();
        if(excess_calc > 0)
        {
            ui->label_excess_title->show();
            ui->label_excess_paid->show();
            ui->label_excess_title->setText("Excess Paid:");
            ui->label_unit_5->show();
            ui->label_excess_paid->setText(QString::number(excess_calc,'f',2));
            ui->lineEdit_paid->setFocus();

        }

        if(excess_calc < 0)
        {
            ui->label_excess_title->show();
            ui->label_excess_title->setText("Gain       :");
            ui->label_excess_paid->show();
            ui->label_unit_5->show();
            ui->label_excess_paid->setText(QString::number(excess_calc,'f',2).remove("-"));
            qDebug()<<"gain ===>>>"<<QString::number(excess_calc,'f',2);
            ui->lineEdit_paid->setFocus();

        }





    }
}

void Customer_Details::on_lineEdit_paid_returnPressed()
{
    QString available_cash = get_cash_available(gstrUserName);
    if(available_cash.toFloat() >= ui->lineEdit_paid->text().toFloat())
    {

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

        //        if(gMsg_box.information(this, "Cash Available: Rs"+QString::number(available_cash.toFloat(),QMessageBox::Ok) == QMessageBox::Ok)
        //        {

        //    }
#endif

#if(SDK75)
        int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"Cash Available: \nRs"+QString::number(available_cash.toFloat(),'f',2),16,14);
        ui->lineEdit_paid->setFocus();
        return;
#endif

    }

    if(!ui->lineEdit_paid->text().isEmpty())
    {
        paid_amt = ui->lineEdit_paid->text();
        qDebug()<<"paid_amt payable_amt ===>>>"<<paid_amt<<payable_amt;
        if(payable_amt.toFloat() > paid_amt.toFloat())
        {
            qDebug()<<"balance 1 ===>>>";
            balance = QString::number(payable_amt.toFloat() - paid_amt.toFloat());
            balance_type = "1";

            ui->label_balance_title->show();
            ui->label_balance_title->setText("Pending    :");


            ui->label_final_balance->show();
            ui->label_unit_8->show();
            ui->label_final_balance->setText(balance);
        }
        else if(payable_amt.toFloat() < paid_amt.toFloat())
        {
            qDebug()<<"balance 2 ===>>>";
            balance = QString::number(paid_amt.toFloat() - payable_amt.toFloat());
            balance_type = "0";

            ui->label_balance_title->show();
            ui->label_balance_title->setText("Advance.Amt:");

            ui->label_final_balance->show();
            ui->label_unit_8->show();
            ui->label_final_balance->setText(balance);
        }
        else
        {
            qDebug()<<"balance 3 ===>>>";
            balance = QString::number(paid_amt.toFloat() - payable_amt.toFloat());
            balance_type = "2";
        }



        ui->pushButton_print->setFocus();
    }
}

void Customer_Details::on_pushButton_print_clicked()
{
    ui->textEdit->clear();
    ui->pushButton_print->setEnabled(false);
    ui->label_info->show();
    ui->label_info->raise();
    qApp->processEvents();

    QSqlQuery qry;
    if(databaseObj->selectQuery("select last_bill_no from configuration_master",qry))
    {
        if(qry.next())
        {
            if(qry.value(0).toString().trimmed().isEmpty())
            {
                gstrBillNo="00001";
                if(databaseObj->executeCommand("insert into configuration_master (last_bill_no) values ('00000')"))
                {
                    databaseObj->con.commit();
                }
            }
            else
                gstrBillNo=QString::number(qry.value(0).toInt() + 1).rightJustified(5,'0');
        }
        else{
            gstrBillNo="00001";
            if(databaseObj->executeCommand("insert into configuration_master (last_bill_no) values ('00000')"))
            {
                databaseObj->con.commit();
            }
        }
    }

    addPreViewData("--------------------------------",Customer_Details::PreViewFontSize_SMALL,Customer_Details::PreViewFontStyle_BOLD,Customer_Details::PreViewAlignment_LEFT);
    addPreViewData("Purchase Receipt",Customer_Details::PreViewFontSize_MEDIUM,Customer_Details::PreViewFontStyle_REGULAR,Customer_Details::PreViewAlignment_CENTER);
    addPreViewData("--------------------------------",Customer_Details::PreViewFontSize_SMALL,Customer_Details::PreViewFontStyle_BOLD,Customer_Details::PreViewAlignment_LEFT);
    addPreViewData("Purchase Receipt No.:"+gstrBillNo,Customer_Details::PreViewFontSize_SMALL,Customer_Details::PreViewFontStyle_REGULAR,Customer_Details::PreViewAlignment_LEFT);
    addPreViewData(StringAlign("Date & Time:",15)+QDate::currentDate().toString("dd-MM-yyyy")+" "+QTime::currentTime().toString("hh:mm"),Customer_Details::PreViewFontSize_SMALL,Customer_Details::PreViewFontStyle_REGULAR,Customer_Details::PreViewAlignment_LEFT);
    addPreViewData(StringAlign("USER Name  :",15)+gstrUserName,Customer_Details::PreViewFontSize_SMALL,Customer_Details::PreViewFontStyle_REGULAR,Customer_Details::PreViewAlignment_LEFT);
    addPreViewData("--------------------------------",Customer_Details::PreViewFontSize_SMALL,Customer_Details::PreViewFontStyle_BOLD,Customer_Details::PreViewAlignment_LEFT);

    if(Home_ScreenObj->selected_vehicle_type.toInt() == 0)
    {
        addPreViewData(StringAlign("Broker Name :",15)+Home_ScreenObj->selected_cus_name,Customer_Details::PreViewFontSize_SMALL,Customer_Details::PreViewFontStyle_REGULAR,Customer_Details::PreViewAlignment_LEFT);
    }
    else
    {
        addPreViewData(StringAlign("Party Name :",15)+Home_ScreenObj->selected_cus_name,Customer_Details::PreViewFontSize_SMALL,Customer_Details::PreViewFontStyle_REGULAR,Customer_Details::PreViewAlignment_LEFT);
    }
    //    addPreViewData(StringAlign("Party Mob  :",15)+Home_ScreenObj->selected_cus_mobile,Customer_Details::PreViewFontSize_SMALL,Customer_Details::PreViewFontStyle_REGULAR,Customer_Details::PreViewAlignment_LEFT);

    QString inward,uom,tot;
    if(Home_ScreenObj->inward_type == 0)
    {
        inward = "CFT  ";
        tot = Home_ScreenObj->total_cft;
        uom = "CFT";
    }
    if(Home_ScreenObj->inward_type == 1)
    {
        inward = "Count";
        tot = Home_ScreenObj->final_count;
        uom = "Nos";
    }

    addPreViewData(StringAlign("Vehicle No. :",15)+Home_ScreenObj->selected_vehicle_number,Customer_Details::PreViewFontSize_SMALL,Customer_Details::PreViewFontStyle_REGULAR,Customer_Details::PreViewAlignment_LEFT);

    QString batch_number;
    if(Home_ScreenObj->selected_vehicle_type.toInt() == 0)
    {
        batch_number = gstrshift_no;
    }
    if(Home_ScreenObj->selected_vehicle_type.toInt() == 1)
    {
        batch_number = gstrshift_no_other;
    }
    if(Home_ScreenObj->selected_vehicle_type.toInt() == 2)
    {
        batch_number = gstrshift_no_van;
    }

    addPreViewData(StringAlign("Batch Type  :",15)+Home_ScreenObj->selected_vehicle_type_name+" "+batch_number.rightJustified(4,'0'),Customer_Details::PreViewFontSize_SMALL,Customer_Details::PreViewFontStyle_REGULAR,Customer_Details::PreViewAlignment_LEFT);

    if(Home_ScreenObj->selected_vehicle_type.toInt() == 0)
    {
        addPreViewData(StringAlign("Distance     :",15)+Home_ScreenObj->distaance_covered.append(" kms"),Customer_Details::PreViewFontSize_SMALL,Customer_Details::PreViewFontStyle_REGULAR,Customer_Details::PreViewAlignment_LEFT);
    }
    addPreViewData(StringAlign("Inward Type:",15)+inward,Customer_Details::PreViewFontSize_SMALL,Customer_Details::PreViewFontStyle_REGULAR,Customer_Details::PreViewAlignment_LEFT);
    addPreViewData(StringAlign("Measurement :",15)+Home_ScreenObj->selected_vehicle_length_ft+"*"+Home_ScreenObj->selected_vehicle_width_ft+"*"+Home_ScreenObj->selected_vehicle_height,Customer_Details::PreViewFontSize_SMALL,Customer_Details::PreViewFontStyle_REGULAR,Customer_Details::PreViewAlignment_LEFT);

    if(Home_ScreenObj->inward_type == 0){
        addPreViewData(StringAlign("Total "+inward+" :",15)+Home_ScreenObj->total_cft+" "+uom,Customer_Details::PreViewFontSize_SMALL,Customer_Details::PreViewFontStyle_REGULAR,Customer_Details::PreViewAlignment_LEFT);
    }

    if(Home_ScreenObj->inward_type == 1){
        addPreViewData(StringAlign("Total "+inward+" :",15)+Home_ScreenObj->final_count+" "+uom,Customer_Details::PreViewFontSize_SMALL,Customer_Details::PreViewFontStyle_REGULAR,Customer_Details::PreViewAlignment_LEFT);
    }
    addPreViewData(StringAlign(ui->label_balance_type->text(),15)+" Rs."+Home_ScreenObj->selected_cus_balance,Customer_Details::PreViewFontSize_SMALL,Customer_Details::PreViewFontStyle_REGULAR,Customer_Details::PreViewAlignment_LEFT);
    addPreViewData(StringAlign("Numbers     :",15)+Home_ScreenObj->final_count+" Nos",Customer_Details::PreViewFontSize_SMALL,Customer_Details::PreViewFontStyle_REGULAR,Customer_Details::PreViewAlignment_LEFT);
    addPreViewData(StringAlign("Estimated.Amt:",15)+" Rs."+Home_ScreenObj->estimated_amount,Customer_Details::PreViewFontSize_SMALL,Customer_Details::PreViewFontStyle_REGULAR,Customer_Details::PreViewAlignment_LEFT);
    addPreViewData(StringAlign("Approved.Amt:",15)+" Rs."+ui->lineEdit_Excess->text(),Customer_Details::PreViewFontSize_SMALL,Customer_Details::PreViewFontStyle_REGULAR,Customer_Details::PreViewAlignment_LEFT);

    if(payable_amt>0)
    {
        addPreViewData(StringAlign("Payable Amt :",15)+" Rs."+payable_amt,Customer_Details::PreViewFontSize_SMALL,Customer_Details::PreViewFontStyle_REGULAR,Customer_Details::PreViewAlignment_LEFT);
    }
    addPreViewData("Paid Amount : Rs."+paid_amt,Customer_Details::PreViewFontSize_MEDIUM,Customer_Details::PreViewFontStyle_BOLD,Customer_Details::PreViewAlignment_LEFT);

    //    addPreViewData(StringAlign("Balance    :",15)+" Rs."+balance,Customer_Details::PreViewFontSize_SMALL,Customer_Details::PreViewFontStyle_REGULAR,Customer_Details::PreViewAlignment_LEFT);

    qDebug()<<"ui->label_excess_paid->text() ===>>>"<<ui->label_excess_paid->text();

    float f1 = ui->label_excess_paid->text().toFloat();
    qDebug()<<"ui->label_excess_paid->text() to float ===>>>"<<QString::number(f1);
    if(f1 > 0 && !ui->label_excess_title->text().contains("gain",Qt::CaseInsensitive))
    {
        qDebug()<<"ui->label_excess_paid->text() > 0===>>>";
        addPreViewData("--------------------------------",Customer_Details::PreViewFontSize_SMALL,Customer_Details::PreViewFontStyle_BOLD,Customer_Details::PreViewAlignment_LEFT);

        addPreViewData("Excess Amt: Rs."+ui->label_excess_paid->text(),Customer_Details::PreViewFontSize_MEDIUM,Customer_Details::PreViewFontStyle_BOLD,Customer_Details::PreViewAlignment_CENTER);

        addPreViewData("--------------------------------",Customer_Details::PreViewFontSize_SMALL,Customer_Details::PreViewFontStyle_BOLD,Customer_Details::PreViewAlignment_LEFT);

    }

    pending_print = false;
    if(ui->label_balance_title->isVisible())
    {
        pending_print = true;
        addPreViewData(StringAlign(ui->label_balance_title->text()+":",15)+" Rs."+ui->label_final_balance->text(),Customer_Details::PreViewFontSize_SMALL,Customer_Details::PreViewFontStyle_REGULAR,Customer_Details::PreViewAlignment_LEFT);
    }
    addPreViewData("--------------------------------",Customer_Details::PreViewFontSize_SMALL,Customer_Details::PreViewFontStyle_BOLD,Customer_Details::PreViewAlignment_LEFT);
    addPreViewData("Thank You",Customer_Details::PreViewFontSize_SMALL,Customer_Details::PreViewFontStyle_REGULAR,Customer_Details::PreViewAlignment_CENTER);
    addPreViewData("--------------------------------",Customer_Details::PreViewFontSize_SMALL,Customer_Details::PreViewFontStyle_BOLD,Customer_Details::PreViewAlignment_LEFT);


    ui->groupBox_preview->show();
    ui->groupBox_preview->raise();
    ui->groupBox_preview->move(0,0);

    ui->groupBox->hide();

    ui->label_info->hide();
    ui->label_info->lower();

    ui->textEdit->setFocus();

}

void Customer_Details::save_transaction()
{
    QString batch_type,inward_to,batch_number,odometer_name,odometer_value;
    if(Home_ScreenObj->selected_vehicle_type.toInt() == 0)
    {
        batch_type = "0";
        batch_number = gstrshift_no;
        inward_to = "company_batch_no";
        odometer_name = ",odometer_reading";


    }
    if(Home_ScreenObj->selected_vehicle_type.toInt() == 1)
    {
        batch_type = "1";
        batch_number = gstrshift_no_other;
        inward_to = "other_batch_no";
    }
    if(Home_ScreenObj->selected_vehicle_type.toInt() == 2)
    {
        batch_type = "2";
        batch_number = gstrshift_no_van;
        inward_to = "van_batch_no";
    }
    QString is_gain = "";
    if(ui->label_excess_paid->text().toInt() > 0 && ui->label_excess_title->text().contains("excess",Qt::CaseInsensitive))
        is_gain = "0";
    if(ui->label_excess_paid->text().toInt() > 0 && !ui->label_excess_title->text().contains("excess",Qt::CaseInsensitive))
        is_gain = "1";

    if(Home_ScreenObj->selected_vehicle_type.toInt() == 0)
    {
        if(databaseObj->executeCommand("insert into transaction_master (cus_id,cus_name,cus_mobile,vehicle_no,vehicle_height,inward_type,previous_balance,est_amt,excess_amt,payable,paid,balance,uploade_flag,day_no,batch_type,batch_no,bill_no,odometer_reading,inward_bale,inward_hush,vkms,balance_type,is_payment,approved_amt,is_gain,previous_balance_type) values ('"+Home_ScreenObj->selected_cus_id+"','"+Home_ScreenObj->selected_cus_name+"','"+Home_ScreenObj->selected_cus_mobile+"','"+Home_ScreenObj->selected_vehicle_number+"','"+Home_ScreenObj->selected_vehicle_height+"','"+QString::number(Home_ScreenObj->inward_type)+"','"+Home_ScreenObj->selected_cus_balance+"','"+Home_ScreenObj->estimated_amount+"','"+QString::number(ui->label_excess_paid->text().toFloat(),'f',2)+"','"+payable_amt+"','"+paid_amt+"','"+balance+"','0','"+gstrday_no+"','"+Home_ScreenObj->selected_vehicle_type+"','"+batch_number+"','"+gstrBillNo+"','"+Home_ScreenObj->odometer_reading+"','"+Home_ScreenObj->total_cft+"','"+Home_ScreenObj->final_count+"',(select '"+Home_ScreenObj->odometer_reading+"'-sum(vehicle_registration.odometer_reading) from vehicle_registration where vehicle_registration.vehicle_no='"+Home_ScreenObj->selected_vehicle_number+"'),'"+balance_type+"','0','"+ui->lineEdit_Excess->text().trimmed()+"','"+is_gain+"','"+Home_ScreenObj->selected_cus_balance_type+"')"))
        {
            qDebug()<<"save_transaction ===>>>"<<Home_ScreenObj->odometer_reading;

            qDebug()<<"cash update before ===>>>"<<get_cash_available(gstrUserName);
            if(update_user_cash(paid_amt,"-",gstrUserName))
            {
                qDebug()<<"cash update after ===>>>"<<get_cash_available(gstrUserName);
            }

            if(databaseObj->executeCommand("update customer_master set balance='"+balance+"',balance_type='"+balance_type+"' where id_customer_master='"+Home_ScreenObj->selected_cus_id+"'"))
            {
                qDebug()<<"balance update success ===>>>"<<gstrBillNo;
            }

            if(databaseObj->executeCommand("update vehicle_registration set odometer_reading='"+Home_ScreenObj->odometer_reading+"' where vehicle_no='"+Home_ScreenObj->selected_vehicle_number+"'"))
            {
                qDebug()<<"vehicle_registration odometer_reading update success ===>>>"<<Home_ScreenObj->selected_vehicle_number<<Home_ScreenObj->odometer_reading;
            }


            if(databaseObj->executeCommand("update "+inward_to+" set inward_stock=(select "+inward_to+".inward_stock from "+inward_to+"  where batch_no='"+batch_number+"' and status='1' )+'"+Home_ScreenObj->total_cft+"' where batch_no='"+batch_number+"' and status='1' "))
            {
                qDebug()<<"balance update success ===>>>"<<gstrBillNo;

                if(databaseObj->executeCommand("update "+inward_to+" set total_husk_produced=(select "+inward_to+".total_husk_produced from "+inward_to+"  where batch_no='"+batch_number+"' and status='1' )+'"+Home_ScreenObj->final_count+"' where batch_no='"+batch_number+"' and status='1' "))
                {
                    qDebug()<<"total_husk_produced update success ===>>>";
                }

            }
            if(databaseObj->executeCommand("update configuration_master set last_bill_no='"+gstrBillNo+"'"))
            {
                qDebug()<<"bill_no update success ===>>>";
            }
            //            if(databaseObj->executeCommand("update vehicle_registration set odometer_reading='"+Home_ScreenObj->odometer_reading+"' where vehi"))
            //            {
            //                qDebug()<<"odometer_reading update success ===>>>";
            //            }
        }
    }
    else
    {

        if(databaseObj->executeCommand("insert into transaction_master (cus_id,cus_name,cus_mobile,vehicle_no,vehicle_height,inward_type,previous_balance,est_amt,excess_amt,payable,paid,balance,uploade_flag,day_no,batch_type,batch_no,bill_no,inward_bale,inward_hush,balance_type,is_payment,approved_amt,is_gain,previous_balance_type) values ('"+Home_ScreenObj->selected_cus_id+"','"+Home_ScreenObj->selected_cus_name+"','"+Home_ScreenObj->selected_cus_mobile+"','"+Home_ScreenObj->selected_vehicle_number+"','"+Home_ScreenObj->selected_vehicle_height+"','"+QString::number(Home_ScreenObj->inward_type)+"','"+Home_ScreenObj->selected_cus_balance+"','"+Home_ScreenObj->estimated_amount+"','"+QString::number(ui->label_excess_paid->text().toFloat(),'f',2)+"','"+payable_amt+"','"+paid_amt+"','"+balance+"','0','"+gstrday_no+"','"+Home_ScreenObj->selected_vehicle_type+"','"+batch_number+"','"+gstrBillNo+"','"+Home_ScreenObj->total_cft+"','"+Home_ScreenObj->final_count+"','"+balance_type+"','0','"+ui->lineEdit_Excess->text().trimmed()+"','"+is_gain+"','"+Home_ScreenObj->selected_cus_balance_type+"')"))
        {
            qDebug()<<"save_transaction ===>>>";
            qDebug()<<"cash update before ===>>>"<<get_cash_available(gstrUserName);
            if(update_user_cash(paid_amt,"-",gstrUserName))
            {
                qDebug()<<"cash update after ===>>>"<<get_cash_available(gstrUserName);
            }

            if(databaseObj->executeCommand("update customer_master set balance='"+balance+"',balance_type='"+balance_type+"' where id_customer_master='"+Home_ScreenObj->selected_cus_id+"'"))
            {
                qDebug()<<"balance update success ===>>>"<<gstrBillNo;
            }
            if(databaseObj->executeCommand("update "+inward_to+" set inward_stock=(select "+inward_to+".inward_stock from "+inward_to+"  where batch_no='"+batch_number+"' and status='1' )+'"+Home_ScreenObj->total_cft+"' where batch_no='"+batch_number+"' and status='1' "))
            {
                qDebug()<<"balance update success ===>>>"<<gstrBillNo;

                if(databaseObj->executeCommand("update "+inward_to+" set total_husk_produced=(select "+inward_to+".total_husk_produced from "+inward_to+"  where batch_no='"+batch_number+"' and status='1' )+'"+Home_ScreenObj->final_count+"' where batch_no='"+batch_number+"' and status='1' "))
                {
                    qDebug()<<"total_husk_produced update success ===>>>";
                }

            }
            if(databaseObj->executeCommand("update configuration_master set last_bill_no='"+gstrBillNo+"'"))
            {
                qDebug()<<"bill_no update success ===>>>";
            }
        }

    }
}

QString Customer_Details::StringAlign(QString Data,int len)
{
    QString space = "";
    QString final;
    if(Data.length()<len){
        for(int i=Data.length();i < len ;i++)
            space=space+" ";
        final=Data+space;
    }
    else
    {
        Data.truncate(len);
        final=Data;
    }
    qDebug() << "alignsize" <<final.size();
    return final;
}


QString Customer_Details::StringRightAlign(QString Data,int len)
{
    QString space = "";
    for(int i=Data.length();i < len ;i++)
        space=" "+space;
    qDebug() << "rightlignsize" <<Data.size()+space.size();
    return space+Data;
}

void Customer_Details::on_lineEdit_Excess_textEdited(const QString &arg1)
{
    ui->label_excess_title->hide();
    ui->label_excess_paid->hide();
    ui->label_excess_paid->clear();
    ui->label_unit_5->hide();
}

void Customer_Details::addPreViewData(const QString &r_const_strDATA,
                                      PreView_FontSize preview_FontSize,
                                      PreView_FontStyle preview_FontStyle,
                                      PreView_Alignment preview_Align,
                                      bool bUnderLine)
{
    //        qDebug()<<"\r add data";
    QString temp=r_const_strDATA;
    int datalen=temp.length();
    QString FontStyle,Align,Style;int FontSize;bool fontItalic=false;
    /** FontStyle for print data**/
    switch(int(preview_FontStyle))
    {
    case PreViewFontStyle_BOLD:
        Style="weight";
        FontStyle="bold";
        break;
    case PreViewFontStyle_REGULAR:
        Style="style";
        FontStyle="normal";
        break;
    case PreViewFontStyle_ITALIC:
        Style="style";
        fontItalic=true;
        break;
    default:
        FontStyle="L";
        break;
    }
    /** Font Size for print data**/
    switch(int(preview_FontSize))
    {
    case PreViewFontSize_BIG:
        //        FontSize=14;   //ORG
        FontSize=14;
        //        temp.remove(27,datalen-27);  //QTextEdit testing
        qDebug()<<"temp big ===>>>"<<temp<<"("<<temp.size()<<")";
        break;
    case PreViewFontSize_MEDIUM:
        FontSize=12;
        //        temp.remove(32,datalen-32);
        qDebug()<<"temp medium ===>>>"<<temp<<"("<<temp.size()<<")";
        break;
    case PreViewFontSize_SMALL:
        FontSize=10;
        //        temp.remove(38,datalen-38);
        qDebug()<<"temp small ===>>>"<<temp<<"("<<temp.size()<<")";
        break;
    default:
        FontSize=10;
        break;
    }
    /** Font Alignment for print data**/
    switch(int(preview_Align))
    {
    case PreViewAlignment_CENTER:
        Align="C";
        break;
    case PreViewAlignment_LEFT:
        Align="L";
        break;
    case PreViewAlignment_RIGHT:
        Align="R";
        break;
    default:
        Align="L";
        break;
    }

    QTextDocument * textDocument = ui->textEdit->document();
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextBlockFormat textBlockFormat = cursor.blockFormat();
    QFont font;
    font.setFamily("Monospace");

    //    font.setStyleHint(QFont::Courier);
    qApp->processEvents();
    font.setFixedPitch(true);
    ui->textEdit->setFont(font);

    if(!bUnderLine)
    {
        if(FontStyle.contains("normal"))
        {ui->textEdit->setFontWeight(50);}

        else if(FontStyle.contains("bold"))
        {ui->textEdit->setFontWeight(99);}

        else if(FontStyle.contains("bold"))
        {ui->textEdit->setFontItalic(fontItalic);}

        ui->textEdit->setFontPointSize(FontSize);
        //        ui->textEdit->append("<span style=\" font-size:"+QString::number(FontSize)+"pt; font-"+Style+":"+FontStyle+";\">"+temp);
        ui->textEdit->append(temp);
        textBlockFormat = cursor.blockFormat();
        if(Align.contains("C"))
            textBlockFormat.setAlignment(Qt::AlignCenter);
        else if(Align.contains("L"))
            textBlockFormat.setAlignment(Qt::AlignLeft);
        else if(Align.contains("R"))
            textBlockFormat.setAlignment(Qt::AlignRight);
        cursor.mergeBlockFormat(textBlockFormat);
        ui->textEdit->setTextCursor(cursor);

        //        QString filename="/home/demo/yaswant/BT_PDF/sample"+QDateTime::currentDateTime().toString("hhmmss")+".pdf";
        //        QPrinter printer(QPrinter::HighResolution);
        //        printer.setOutputFormat(QPrinter::PdfFormat);
        //        printer.setOutputFileName(filename);
        //        printer.setPageMargins(2,2,2,2,QPrinter::Millimeter);
        //        printer.setOutputFormat(QPrinter::PdfFormat);
        //        QSizeF s;
        //        s.setWidth(56);
        //        s.setHeight(56);
        //        printer.setPaperSize(s,QPrinter::Millimeter);
        //        //        ui->textEdit->print(&printer);


        //        Document *document1 = Document::load(filename);
        //        document1->setRenderBackend(Document::ArthurBackend);
        //        document1->setRenderHint(Document::TextAntialiasing, true);
        //        document1->setRenderHint(Document::TextHinting, true);
        //        document1->setRenderHint(Document::TextSlightHinting, true);
        //        document1->setPaperColor(Qt::transparent);


        //        QSvgGenerator svgGenerator;
        //        svgGenerator.setResolution(192); // resolution in dpi 192
        //        svgGenerator.setFileName("/home/demo/yaswant/BT_PDF/svg/output.svg");
        //        QSize s1;
        //        s1.setWidth(384);
        //        s1.setHeight(300);
        //        svgGenerator.setSize(s1);
        //        QPainter painter1(&svgGenerator);
        //        bool load=document1->page(0)->renderToPainter(&painter1);
        //        painter1.end();

        //        QSvgRenderer renderer(QString("/home/demo/yaswant/BT_PDF/svg/output.svg"));
        //        QImage image(384,720 ,QImage::Format_MonoLSB);
        //        image.fill(Qt::black);
        //        QPainter painter11(&image);
        //        renderer.render(&painter11);
        //        qDebug()<<image.save("/home/demo/yaswant/BT_PDF/svg/svg.bmp");

        //        system("/home/demo/yaswant/BT_PDF/bmp_to_binary/bmpTObinary /home/demo/yaswant/BT_PDF/svg/svg.bmp /home/demo/yaswant/BT_PDF/svg/print.txt /home/demo/yaswant/BT_PDF/svg/print");

    }
    else
    {
        ui->textEdit->append("<span style=\" font-size:"+QString::number(FontSize)+"pt; font-"+Style+":"+FontStyle+";\"><u> "+r_const_strDATA+"</u>");
        textBlockFormat = cursor.blockFormat();
        if(Align.contains("C"))
            textBlockFormat.setAlignment(Qt::AlignCenter);
        else if(Align.contains("L"))
            textBlockFormat.setAlignment(Qt::AlignLeft);
        else if(Align.contains("R"))
            textBlockFormat.setAlignment(Qt::AlignRight);
        cursor.mergeBlockFormat(textBlockFormat);
        ui->textEdit->setTextCursor(cursor);
    }

}

void Customer_Details::on_pushButton_print_4_clicked()
{
    //! print

    ui->label_info_2->show();
    ui->label_info_2->raise();

    QSqlQuery qry;
    if(databaseObj->selectQuery("select last_bill_no from configuration_master",qry))
    {
        if(qry.next())
        {
            if(qry.value(0).toString().trimmed().isEmpty())
            {
                gstrBillNo="00001";
                if(databaseObj->executeCommand("insert into configuration_master (last_bill_no) values ('00000')"))
                {
                    databaseObj->con.commit();
                }
            }
            else
                gstrBillNo=QString::number(qry.value(0).toInt() + 1).rightJustified(5,'0');
        }
        else{
            gstrBillNo="00001";
            if(databaseObj->executeCommand("insert into configuration_master (last_bill_no) values ('00000')"))
            {
                databaseObj->con.commit();
            }
        }
    }


    QString available_cash = get_cash_available(gstrUserName);
    if(available_cash.toFloat() >= paid_amt.toFloat())
    {

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

        //        if(gMsg_box.information(this, "Cash Available: Rs"+QString::number(available_cash.toFloat(),QMessageBox::Ok) == QMessageBox::Ok)
        //        {

        //    }
#endif

#if(SDK75)
        int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"Cash Available: \nRs"+QString::number(available_cash.toFloat(),'f',2),16,14);
        ui->lineEdit_paid->setFocus();
        return;
#endif

    }



    save_transaction();
    qDebug()<<"billno"<<gstrBillNo;



#if(SDK75)

    //    int print_count=2;
    //    for(int i=0;i<print_count;i++)
    //    {
    CPrinter print;
    print.setFontType(CPrinter::eFontType_font2);
    //    print.addData("New India Fiber",CPrinter::eFontSize_BIG,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
    //    print.addData("New India Fiber",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);

    QStringList lst_print_data;

    print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
    lst_print_data << "--------------------------------------" ;

    print.addData("Purchase Receipt",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
    lst_print_data << "Purchase Receipt" ;

    print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
    lst_print_data << "--------------------------------------" ;

    print.addData("Purchase Receipt No.:"+gstrBillNo,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    lst_print_data << "Purchase Receipt No.:"+gstrBillNo ;

    print.addData(StringAlign("Date & Time:",15)+QDate::currentDate().toString("dd-MM-yyyy")+" "+QTime::currentTime().toString("hh:mm"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    lst_print_data << StringAlign("Date & Time:",15)+QDate::currentDate().toString("dd-MM-yyyy")+" "+QTime::currentTime().toString("hh:mm") ;

    print.addData(StringAlign("USER Name  :",15)+gstrUserName,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    lst_print_data << StringAlign("USER Name  :",15)+gstrUserName ;

    print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
    lst_print_data << "--------------------------------------" ;

    if(Home_ScreenObj->selected_vehicle_type.toInt() == 0)
    {
        print.addData(StringAlign("Broker Name :",15)+Home_ScreenObj->selected_cus_name,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
        lst_print_data << StringAlign("Broker Name :",15)+Home_ScreenObj->selected_cus_name ;
    }
    else
    {
        print.addData(StringAlign("Party Name :",15)+Home_ScreenObj->selected_cus_name,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
        lst_print_data << StringAlign("Party Name :",15)+Home_ScreenObj->selected_cus_name ;
    }
    //    print.addData(StringAlign("Party Mob  :",15)+Home_ScreenObj->selected_cus_mobile,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

    QString inward,uom,tot;
    if(Home_ScreenObj->inward_type == 0)
    {
        inward = "CFT  ";
        tot = Home_ScreenObj->total_cft;
        uom = "CFT";

    }
    if(Home_ScreenObj->inward_type == 1)
    {
        inward = "Count";
        tot = Home_ScreenObj->final_count;
        uom = "Nos";
    }


    print.addData(StringAlign("Vehicle No. :",15)+Home_ScreenObj->selected_vehicle_number,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    lst_print_data << StringAlign("Vehicle No. :",15)+Home_ScreenObj->selected_vehicle_number ;

    QString batch_number;
    if(Home_ScreenObj->selected_vehicle_type.toInt() == 0)
    {
        batch_number = gstrshift_no;
    }
    if(Home_ScreenObj->selected_vehicle_type.toInt() == 1)
    {
        batch_number = gstrshift_no_other;
    }
    if(Home_ScreenObj->selected_vehicle_type.toInt() == 2)
    {
        batch_number = gstrshift_no_van;
    }


    print.addData(StringAlign("Batch Type  :",15)+Home_ScreenObj->selected_vehicle_type_name+" "+batch_number.rightJustified(4,'0'),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    lst_print_data << StringAlign("Batch Type  :",15)+Home_ScreenObj->selected_vehicle_type_name+" "+batch_number.rightJustified(4,'0') ;

    if(Home_ScreenObj->selected_vehicle_type.toInt() == 0)
    {
        print.addData(StringAlign("Distance     :",15)+Home_ScreenObj->distaance_covered.append(" kms"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
        lst_print_data << StringAlign("Distance     :",15)+Home_ScreenObj->distaance_covered ;
    }



    print.addData(StringAlign("Inward Type:",15)+inward,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    lst_print_data << StringAlign("Inward Type:",15)+inward ;


    print.addData(StringAlign("Measurement :",15)+Home_ScreenObj->selected_vehicle_length_ft+"*"+Home_ScreenObj->selected_vehicle_width_ft+"*"+Home_ScreenObj->selected_vehicle_height,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    lst_print_data << StringAlign("Measurement :",15)+Home_ScreenObj->selected_vehicle_length_ft+"*"+Home_ScreenObj->selected_vehicle_width_ft+"*"+Home_ScreenObj->selected_vehicle_height ;


    if(Home_ScreenObj->inward_type == 0){
        print.addData(StringAlign("Total "+inward+" :",15)+Home_ScreenObj->total_cft+" "+uom,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
        lst_print_data << StringAlign("Total "+inward+" :",15)+Home_ScreenObj->total_cft+" "+uom ;
    }

    if(Home_ScreenObj->inward_type == 1){
        print.addData(StringAlign("Total "+inward+" :",15)+Home_ScreenObj->final_count+" "+uom,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
        lst_print_data << StringAlign("Total "+inward+" :",15)+Home_ScreenObj->final_count+" "+uom ;
    }


    print.addData(StringAlign(ui->label_balance_type->text(),15)+" Rs."+Home_ScreenObj->selected_cus_balance,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    lst_print_data << StringAlign(ui->label_balance_type->text(),15)+" Rs."+Home_ScreenObj->selected_cus_balance ;

    print.addData(StringAlign("Numbers     :",15)+Home_ScreenObj->final_count+" Nos",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    lst_print_data << StringAlign("Numbers     :",15)+Home_ScreenObj->final_count+" Nos" ;

    print.addData(StringAlign("Estimated.Amt:",15)+" Rs."+Home_ScreenObj->estimated_amount,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    lst_print_data << StringAlign("Estimated.Amt:",15)+" Rs."+Home_ScreenObj->estimated_amount ;

    print.addData(StringAlign("Approved.Amt:",15)+" Rs."+ui->lineEdit_Excess->text(),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    lst_print_data << StringAlign("Approved.Amt:",15)+" Rs."+ui->lineEdit_Excess->text() ;

    if(payable_amt>0)
    {
        print.addData(StringAlign("Payable Amt :",15)+" Rs."+payable_amt,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
        lst_print_data << StringAlign("Payable Amt :",15)+" Rs."+payable_amt ;
    }
    print.addData(StringAlign("Paid Amount :",15)+" Rs."+paid_amt,CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    lst_print_data << StringAlign("Paid Amount :",15)+" Rs."+paid_amt ;

    //    print.addData(StringAlign("Balance    :",15)+" Rs."+balance,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

    qDebug()<<"ui->label_excess_paid->text() ===>>>"<<ui->label_excess_paid->text();

    float f1 = ui->label_excess_paid->text().toFloat();
    qDebug()<<"ui->label_excess_paid->text() to float ===>>>"<<QString::number(f1);
    if(f1 > 0 && !ui->label_excess_title->text().contains("gain",Qt::CaseInsensitive))
    {
        qDebug()<<"ui->label_excess_paid->text() > 0===>>>";
        print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
        lst_print_data << "--------------------------------------" ;
        print.addData(StringAlign("Excess Amt  :",15)+" Rs."+ui->label_excess_paid->text(),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
        lst_print_data << StringAlign("Excess Amt  :",15)+" Rs."+ui->label_excess_paid->text() ;
        print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
        lst_print_data << "--------------------------------------" ;
    }

    if(pending_print)
    {
        print.addData(StringAlign(ui->label_balance_title->text()+":",15)+" Rs."+ui->label_final_balance->text(),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
        lst_print_data << StringAlign(ui->label_balance_title->text()+":",15)+" Rs."+ui->label_final_balance->text() ;
    }
    print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
    lst_print_data << "--------------------------------------" ;
    print.addData("Thank You",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
    lst_print_data << "Thank You" ;
    print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
    lst_print_data << "--------------------------------------" ;

    qDebug()<<"lst_print_data ===>>>"<<lst_print_data;

    QFile fOut("/home/root/last_print.txt");
    fOut.resize(0);
    if (fOut.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream s(&fOut);
        for (int i = 0; i < lst_print_data.size(); ++i)
            s << lst_print_data.at(i) << '\n';
    } else
    {
        std::cerr << "error opening output file\n";
        //            return EXIT_FAILURE;
    }
    fOut.close();

    print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    if(print.print(true,false))
    {

    }

#endif


    //    g_ccmainObj->setKeypadModeLock(false);
    ui->pushButton_print->setEnabled(true);
    ui->label_info_2->hide();
    ui->label_info_2->lower();
    this->close();
    Home_ScreenObj->call_Home_Screen();
    Home_ScreenObj->show();
}
