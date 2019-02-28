#include "payment.h"
#include "ui_payment.h"

#include <global.h>
#include <QMessageBox>

using namespace Global;

Payment::Payment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Payment)
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

    is_payment = false;
}

Payment::~Payment()
{
    delete ui;
}

void Payment::call_Payment()
{
    ui->groupBox_home->move(0,0);
    ui->groupBox_Husk->move(0,0);
    ui->groupBox_diesel_payment->move(0,0);
    ui->groupBox_labour_payment->move(0,0);

    ui->groupBox_home->show();
    ui->groupBox_home->raise();

    ui->groupBox_preview->hide();
    ui->label_info_2->hide();

    ui->label_info->hide();

    ui->pushButton_save->hide();

    ui->groupBox_diesel_payment->hide();
    ui->groupBox_labour_payment->hide();

    ui->lineEdit_vehicle_number->clear();
    ui->lineEdit_customer->clear();
    ui->label_balance->clear();
    ui->label_balance_title->clear();
    ui->label_Total->clear();
    ui->label_vihecleType->clear();

    ui->label_Total_title->setText("Total:");

    ui->lineEdit_diesel_amount->setValidator(gAmtValidator1);
    ui->lineEdit_labour_amount->setValidator(gAmtValidator1);
    ui->lineEdit_paid_amt->setValidator(gAmtValidator1);
    ui->lineEdit_vehicle_number->setValidator(gAmtValidator2);


    ui->groupBox_Husk->hide();
    lst_vehicle_number.clear();

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


    cmpter2 = new QCompleter(lst_vehicle_number,this);
    cmpter2->setCaseSensitivity(Qt::CaseInsensitive);
    cmpter2->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->lineEdit_vehicle_number->setCompleter(cmpter2);

    lst_bunk_name.clear();
    vehicle_details.clear();
    if(databaseObj->selectQuery("select bunk_name,id_bunk_master from bunk_master",vehicle_details))
    {
        if(vehicle_details.next())
        {
            lst_bunk_name << vehicle_details.value(0).toString().trimmed();
            while(vehicle_details.next())
            {
                lst_bunk_name << vehicle_details.value(0).toString().trimmed();
            }
        }
    }
    cmpter3 = new QCompleter(lst_bunk_name,this);
    cmpter3->setCaseSensitivity(Qt::CaseInsensitive);
    cmpter3->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->lineEdit_diesel_bunk_name->setCompleter(cmpter3);

    vehicle_details.clear();
    lst_emp_name.clear();
    if(databaseObj->selectQuery("select emp_name from employee_master where is_active='1'",vehicle_details))
    {
        if(vehicle_details.next())
        {
            lst_emp_name << vehicle_details.value(0).toString().trimmed();

            while(vehicle_details.next())
            {
                lst_emp_name << vehicle_details.value(0).toString().trimmed();
            }
        }
    }

    cmpter4 = new QCompleter(lst_emp_name,this);
    cmpter4->setCaseSensitivity(Qt::CaseInsensitive);
    cmpter4->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->lineEdit_labour_name->setCompleter(cmpter4);
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
    ui->pushButton_staff->setFocus();

    if(gstrUserType.toInt() == 0)
    {
        ui->pushButton_staff->hide();
        ui->pushButton_Diesel->hide();
        ui->pushButton_other->hide();
#if(SDK75)
        g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
        ui->pushButton_Husk->setFocus();
    }

    if(gstrUserType.toInt() == 2)
    {
        ui->pushButton_staff->hide();
#if(SDK75)
        g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
        ui->pushButton_Husk->setFocus();
    }
    if(gstrUserType.toInt() == 1)
    {
        ui->pushButton_staff->setFocus();
    }

    if(is_payment)
        called_for_payment();
    else
        called_for_receipt();



}

void Payment::keyPressEvent(QKeyEvent *ke)
{
    if(ke->key()== Qt::Key_Escape)
    {
        if(ui->groupBox_home->isVisible())
        {

            qDebug()<<"groupBox_Home ===>>>";

            //            this->close();
            //            Process_SelectionObj->call_Process_Selection();
            //            Process_SelectionObj->show();

            this->close();
            menuObj->call_menu();
            menuObj->show();

            return;
        }
        if(ui->groupBox_Husk->isVisible() || ui->groupBox_diesel_payment->isVisible() || ui->groupBox_labour_payment->isVisible())
        {
            qDebug()<<"groupBox_Husk ===>>>";
            call_Payment();
            return;
        }
        if(ui->groupBox_preview->isVisible())
        {
            ui->groupBox_preview->hide();
            ui->groupBox_Husk->show();
            ui->groupBox_Husk->raise();
            ui->label_info->hide();
            ui->pushButton_husk_payment_save->setEnabled(true);
            ui->pushButton_husk_payment_save->setFocus();
            return;
        }
    }
    if(ke->key()== Qt::Key_F1)
    {
        ui->label_info_2->show();
        ui->label_info_2->raise();
        qApp->processEvents();
        if(ui->groupBox_preview->isVisible())
        {
            on_pushButton_print_4_clicked();
        }
    }
    if(ke->key()== Qt::Key_F5)
    {
        if(ui->groupBox_Husk->isVisible())
        {
            int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Information,"Do You Want\nReprint Last\nReceipt?",16,14,"YES","NO");
            if(ret==1)
            {
                QFile inputFile("/home/root/last_print_payment.txt");
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
                        else if(data.contains("Bal.Total:"))
                            print.addData(data,CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                        else if(data.contains("Adv.Total:"))
                            print.addData(data,CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                        else if(data.compare("Payment Receipt",data,Qt::CaseSensitive) == 0)
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
}

void Payment::show_screen(int scr)
{
    if(scr == 1)
    {
        ui->lineEdit_vehicle_number->clear();
        ui->lineEdit_customer->clear();
        ui->lineEdit_customer->clear();
        ui->label_balance->clear();
        //        ui->label_balance_title->clear();
        ui->label_Total->clear();
        ui->label_vihecleType->clear();
        ui->label_Total->clear();
        ui->lineEdit_paid_amt->clear();

        ui->label_Total_title->setText("Total:");

        ui->groupBox_Husk->show();
        ui->groupBox_Husk->raise();
        ui->groupBox_home->hide();
        ui->groupBox_diesel_payment->hide();

        ui->pushButton_husk_payment_save->setEnabled(false);
#if(SDK75)
        g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
#endif
        ui->lineEdit_vehicle_number->setFocus();

    }
    if(scr == 2)
    {
        ui->groupBox_Husk->hide();
        ui->groupBox_home->hide();
        ui->groupBox_labour_payment->hide();
        ui->groupBox_diesel_payment->show();

        ui->lineEdit_diesel_amount->clear();
        ui->lineEdit_diesel_bunk_name->clear();
        ui->label_diesel_balance_amt->clear();
        ui->label_diesel_pending->clear();
#if(SDK75)
        g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
#endif
        ui->lineEdit_diesel_bunk_name->setFocus();

    }
    if(scr == 3)
    {
        ui->groupBox_Husk->hide();
        ui->groupBox_home->hide();
        ui->groupBox_diesel_payment->hide();
        ui->groupBox_labour_payment->show();
        ui->groupBox_labour_payment->raise();

        ui->lineEdit_labour_amount->clear();
        ui->lineEdit_labour_name->clear();
        ui->label_labour_balance_amt->clear();
        ui->label_labour_pending->clear();
#if(SDK75)
        g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
#endif
        ui->lineEdit_labour_name->setFocus();

    }
}

void Payment::on_pushButton_Husk_clicked()
{
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
#endif
    show_screen(1);
}

void Payment::on_lineEdit_vehicle_number_returnPressed()
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


                if(selected_vehicle_type.toInt() == 0){
                    ui->label_vihecleType->setText("Company");
                    selected_vehicle_type_name = "Company";
                }
                if(selected_vehicle_type.toInt() == 1){
                    ui->label_vihecleType->setText("Auto");
                    selected_vehicle_type_name = "Auto";
                }
                if(selected_vehicle_type.toInt() == 2){
                    ui->label_vihecleType->setText("Van");
                    selected_vehicle_type_name = "Van";
                }


                if(selected_vehicle_type.toInt() == 0)
                {
                    ui->lineEdit_customer->setReadOnly(false);
                    ui->label_4->setText("Broker");


                    QSqlQuery customer_details;
                    if(databaseObj->selectQuery("select * from customer_master where cus_type=1",customer_details))
                    {
                        lst_broker_name.clear();
                        lst_customer_mobile.clear();
                        if(customer_details.next())
                        {
                            lst_broker_name << customer_details.value(1).toString().trimmed();
                            lst_customer_mobile << customer_details.value(2).toString().trimmed();
                        }
                        while(customer_details.next())
                        {
                            lst_broker_name << customer_details.value(1).toString().trimmed();
                            lst_customer_mobile << customer_details.value(2).toString().trimmed();
                        }
                    }

                    qDebug()<<"lst_broker_name ===>>>"<<lst_broker_name;
                    qDebug()<<"lst_customer_mobile ===>>>"<<lst_customer_mobile;

                    cmpter5 = new QCompleter(lst_broker_name,this);
                    cmpter5->setCaseSensitivity(Qt::CaseInsensitive);
                    ui->lineEdit_customer->setCompleter(cmpter5);

#if(SDK75)
                    g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
#endif
                    ui->lineEdit_customer->setFocus();
                    return;
                }

                ui->label_4->setText("User:");

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

                        if(selected_cus_balance_type.toInt() == 0 || selected_cus_balance_type.toInt() == 2)
                        {
                            ui->label_balance_title->setText("Advance:");
                        }

                        if(selected_cus_balance_type.toInt() == 1)
                        {
                            ui->label_balance_title->setText("Pending:");
                        }
                    }
                }
                ui->lineEdit_customer->setText(selected_cus_name);
                ui->label_balance->setText(selected_cus_balance);
#if(SDK75)
                g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                ui->lineEdit_paid_amt->setFocus();

            }
        }
    }
}

void Payment::on_lineEdit_paid_amt_returnPressed()
{
    if(!ui->lineEdit_paid_amt->text().isEmpty() && ui->lineEdit_paid_amt->text().toInt() >= 0)
    {
        ui->pushButton_husk_payment_save->setEnabled(true);
#if(SDK75)
        g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
        ui->pushButton_husk_payment_save->setFocus();


        if(selected_cus_balance_type.toInt() == 1)//pending
        {

            if((ui->lineEdit_paid_amt->text().toFloat() < selected_cus_balance.toFloat()))
            {
                //                final_total = QString::number(ui->lineEdit_paid_amt->text().toFloat() + selected_cus_balance.toFloat());
                final_total = QString::number(selected_cus_balance.toFloat() - ui->lineEdit_paid_amt->text().toFloat());
                qDebug()<<"final_total ===>>>"<<final_total;
                ui->label_Total->show();
                ui->label_Total->setText(final_total);
                ui->label_Total_title->setText("Bal.Total:");
#if(SDK75)
                g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                ui->pushButton_husk_payment_save->setFocus();


                return;
            }
            if((ui->lineEdit_paid_amt->text().toFloat() > selected_cus_balance.toFloat()))
            {
                //            final_total = QString::number(ui->lineEdit_paid_amt->text().toFloat() + selected_cus_balance.toFloat());
                final_total = QString::number(ui->lineEdit_paid_amt->text().toFloat() - selected_cus_balance.toFloat());
                qDebug()<<"final_total ===>>>"<<final_total;
                ui->label_Total->show();
                ui->label_Total->setText(final_total);
                ui->label_Total_title->setText("Adv.Total:");
#if(SDK75)
                g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                ui->pushButton_husk_payment_save->setFocus();
                return;
            }
            if((ui->lineEdit_paid_amt->text().toFloat() == selected_cus_balance.toFloat()))
            {
                final_total = QString::number(ui->lineEdit_paid_amt->text().toFloat() - selected_cus_balance.toFloat());
                qDebug()<<"final_total completed ===>>>"<<final_total;
                ui->label_Total->show();
                ui->label_Total->setText("Payment Complete");
                ui->label_Total_title->setText("Total:");
#if(SDK75)
                g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                ui->pushButton_husk_payment_save->setFocus();

                return;
            }
        }
        if(selected_cus_balance_type.toInt() == 0 || selected_cus_balance_type.toInt() == 2)
        {
            final_total = QString::number(ui->lineEdit_paid_amt->text().toFloat() + selected_cus_balance.toFloat());
            qDebug()<<"final_total ===>>>"<<final_total;
            ui->label_Total->show();
            ui->label_Total->setText(final_total);
            ui->label_Total_title->setText("Adv.Total:");
#if(SDK75)
            g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
            ui->pushButton_husk_payment_save->setFocus();
            return;
        }
    }

}


void Payment::on_pushButton_husk_payment_save_clicked()
{
    if(ui->lineEdit_paid_amt->text().toInt() <= 0)
    {
        int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Information,"Enter Validn\nAmount.",16,14);
        ui->lineEdit_paid_amt->setFocus();
        return;
    }

    ui->label_info->show();
    ui->label_info->raise();
    ui->textEdit->clear();
    qApp->processEvents();
    addPreViewData("--------------------------------",Payment::PreViewFontSize_SMALL,Payment::PreViewFontStyle_BOLD,Payment::PreViewAlignment_LEFT);
    addPreViewData("Payment Receipt",Payment::PreViewFontSize_MEDIUM,Payment::PreViewFontStyle_REGULAR,Payment::PreViewAlignment_CENTER);
    addPreViewData("--------------------------------",Payment::PreViewFontSize_SMALL,Payment::PreViewFontStyle_BOLD,Payment::PreViewAlignment_LEFT);
    addPreViewData(("Payment Receipt No.:")+gstrpayBillNo,Payment::PreViewFontSize_SMALL,Payment::PreViewFontStyle_REGULAR,Payment::PreViewAlignment_LEFT);
    addPreViewData(StringAlign("Date & Time:",15)+QDate::currentDate().toString("dd-MM-yyyy")+" "+QTime::currentTime().toString("hh:mm"),Payment::PreViewFontSize_SMALL,Payment::PreViewFontStyle_REGULAR,Payment::PreViewAlignment_LEFT);
    addPreViewData(StringAlign("USER Name  :",15)+gstrUserName,Payment::PreViewFontSize_SMALL,Payment::PreViewFontStyle_REGULAR,Payment::PreViewAlignment_LEFT);
    addPreViewData("--------------------------------",Payment::PreViewFontSize_SMALL,Payment::PreViewFontStyle_BOLD,Payment::PreViewAlignment_LEFT);
    addPreViewData(StringAlign("Party Name :",15)+selected_cus_name,Payment::PreViewFontSize_SMALL,Payment::PreViewFontStyle_REGULAR,Payment::PreViewAlignment_LEFT);
    addPreViewData(StringAlign("Vehicle No. :",15)+selected_vehicle_number,Payment::PreViewFontSize_SMALL,Payment::PreViewFontStyle_REGULAR,Payment::PreViewAlignment_LEFT);
    addPreViewData(StringAlign("Vehicle Type :",15)+selected_vehicle_type_name,Payment::PreViewFontSize_SMALL,Payment::PreViewFontStyle_REGULAR,Payment::PreViewAlignment_LEFT);
    addPreViewData(StringAlign("Pre."+ui->label_balance_title->text().remove(":").append(" Amt:"),18)+selected_cus_balance,Payment::PreViewFontSize_SMALL,Payment::PreViewFontStyle_REGULAR,Payment::PreViewAlignment_LEFT);
    addPreViewData(StringAlign("Paid Amount :",15)+" Rs."+ui->lineEdit_paid_amt->text(),Payment::PreViewFontSize_MEDIUM,Payment::PreViewFontStyle_REGULAR,Payment::PreViewAlignment_LEFT);
    addPreViewData(StringAlign(ui->label_Total_title->text().trimmed()+":",15)+" Rs."+ui->label_Total->text().trimmed(),Payment::PreViewFontSize_MEDIUM,Payment::PreViewFontStyle_REGULAR,Payment::PreViewAlignment_LEFT);



    ui->pushButton_husk_payment_save->setEnabled(false);



    ui->groupBox_Husk->hide();
    ui->groupBox_preview->show();
    ui->groupBox_preview->raise();

    ui->groupBox_preview->move(0,0);
    ui->textEdit->setFocus();
    ui->label_info_2->hide();
    ui->label_info_2->lower();
    ui->label_info->hide();
    ui->label_info->lower();





}

QString Payment::StringAlign(QString Data,int len)
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


QString Payment::StringRightAlign(QString Data,int len)
{
    QString space = "";
    for(int i=Data.length();i < len ;i++)
        space=" "+space;
    qDebug() << "rightlignsize" <<Data.size()+space.size();
    return space+Data;
}

void Payment::on_pushButton_other_clicked()
{
    this->close();
    Expense_MasterObj->call_Expense_Master();
    Expense_MasterObj->show_screen(2);
    Expense_MasterObj->show();

}

void Payment::on_lineEdit_diesel_bunk_name_returnPressed()
{
    if(!ui->lineEdit_diesel_bunk_name->text().isEmpty())
    {
        selected_bunk_id.clear();
        selected_bunk_name.clear();
        selected_bunk_balance_type.clear();
        selected_bunk_balance.clear();

        QSqlQuery query;
        if(databaseObj->selectQuery("select * from bunk_master where bunk_name='"+ui->lineEdit_diesel_bunk_name->text().trimmed()+"'",query))
        {
            if(query.next())
            {
                selected_bunk_id = query.value(0).toString().trimmed();
                selected_bunk_name = query.value(1).toString().trimmed();
                selected_bunk_balance = query.value(3).toString().trimmed();
                selected_bunk_balance_type = query.value(4).toString().trimmed();
            }
        }

        if(selected_bunk_balance_type.toInt() == 0)
            ui->label_8->setText("Advance    :");

        if(selected_bunk_balance_type.toInt() == 1)
            ui->label_8->setText("Balance    :");


        qDebug()<<"selected_bunk_id ===>>>"<<selected_bunk_id;
        qDebug()<<"selected_bunk_name ===>>>"<<selected_bunk_name;
        qDebug()<<"selected_bunk_balance ===>>>"<<selected_bunk_balance;
        qDebug()<<"selected_bunk_balance_type ===>>>"<<selected_bunk_balance_type;
        ui->label_diesel_pending->setText(selected_bunk_balance);
#if(SDK75)
        g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
        ui->lineEdit_diesel_amount->setFocus();
    }
}

void Payment::on_lineEdit_diesel_amount_returnPressed()
{
    if(!selected_bunk_name.isEmpty())
    {
        final_deisel_amt.clear();
        final_bal_type.clear();
        if(selected_bunk_balance_type.toInt() == 1)
        {
            if(selected_bunk_balance.toFloat() >= ui->lineEdit_diesel_amount->text().toFloat())
            {
                final_deisel_amt = QString::number(selected_bunk_balance.toFloat() - ui->lineEdit_diesel_amount->text().toFloat(),'f',2);
                ui->label_diesel_balance_title->setText("Pending Amt:");
                ui->label_diesel_balance_amt->setText(final_deisel_amt);
                final_bal_type = "1";
#if(SDK75)
                g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                ui->pushButton_payment_diesel_save->setFocus();
                return;

            }
            if(selected_bunk_balance.toFloat() <= ui->lineEdit_diesel_amount->text().toFloat())
            {
                final_deisel_amt = QString::number(ui->lineEdit_diesel_amount->text().toFloat() - selected_bunk_balance.toFloat(),'f',2);
                ui->label_diesel_balance_title->setText("Advance Amt:");
                ui->label_diesel_balance_amt->setText(final_deisel_amt);
                final_bal_type = "0";
#if(SDK75)
                g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                ui->pushButton_payment_diesel_save->setFocus();
                return;
            }

        }
        if(selected_bunk_balance_type.toInt() == 0)
        {
            final_deisel_amt = QString::number(selected_bunk_balance.toFloat() + ui->lineEdit_diesel_amount->text().toFloat(),'f',2);
            ui->label_diesel_balance_title->setText("Advance Amt:");
            ui->label_diesel_balance_amt->setText(final_deisel_amt);
            final_bal_type = "0";
#if(SDK75)
            g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
            ui->pushButton_payment_diesel_save->setFocus();
            return;
        }
    }
}

void Payment::on_pushButton_payment_diesel_save_clicked()
{
    QString available_cash = get_cash_available(gstrUserName);
    if(available_cash.toFloat() >= ui->lineEdit_diesel_amount->text().trimmed().toFloat())
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
        ui->pushButton_payment_diesel_save->setFocus();
        return;
#endif

    }

    if(databaseObj->executeCommand("insert into diesel_transaction (bunk_id,amount,day_no,user_id,is_payment,opening_balance,opening_balance_type,closing_balance,closing_balance_type) values ('"+selected_bunk_id+"','"+ui->lineEdit_diesel_amount->text().trimmed()+"','"+gstrday_no+"','"+gstrUserName+"','1','"+selected_bunk_balance+"','"+selected_bunk_balance_type+"','"+final_deisel_amt+"','"+final_bal_type+"')"))
    {
        qDebug()<<"bunk_master payment success ===>>>";
        if(databaseObj->executeCommand("update bunk_master set bunk_opening_balance='"+final_deisel_amt+"',bunk_opening_balance_type='"+final_bal_type+"' where bunk_name='"+selected_bunk_name+"'"))
        {
            qDebug()<<"bunk_master update success ===>>>";

            qDebug()<<"cash update before ===>>>"<<get_cash_available(gstrUserName);
            if(update_user_cash(ui->lineEdit_diesel_amount->text().trimmed(),"-",gstrUserName))
            {
                qDebug()<<"cash update after ===>>>"<<get_cash_available(gstrUserName);
            }

            call_Payment();
        }

    }

}

void Payment::on_pushButton_Diesel_clicked()
{
    show_screen(2);
}

void Payment::on_lineEdit_labour_bunk_name_returnPressed()
{

}

void Payment::on_lineEdit_labour_amount_returnPressed()
{
    if(!selected_labour_name.isEmpty())
    {
        final_labour_amt.clear();
        final_bal_type.clear();
        if(selected_labour_balance_type.toInt() == 1)
        {
            if(selected_labour_balance.toFloat() >= ui->lineEdit_labour_amount->text().toFloat())
            {
                final_labour_amt = QString::number(selected_labour_balance.toFloat() - ui->lineEdit_labour_amount->text().toFloat(),'f',2);
                ui->label_labour_balance_title->setText("Pending Amt:");
                ui->label_labour_balance_amt->setText(final_labour_amt);
                final_bal_type = "1";
#if(SDK75)
                g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                ui->pushButton_payment_labour_save->setFocus();
                return;
            }
            if(selected_labour_balance.toFloat() <= ui->lineEdit_labour_amount->text().toFloat())
            {
                final_labour_amt = QString::number(ui->lineEdit_labour_amount->text().toFloat() - selected_labour_balance.toFloat(),'f',2);
                ui->label_labour_balance_title->setText("Advance Amt:");
                ui->label_labour_balance_amt->setText(final_labour_amt);
                final_bal_type = "0";
#if(SDK75)
                g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                ui->pushButton_payment_labour_save->setFocus();
                return;
            }
        }
        if(selected_labour_balance_type.toInt() == 0)
        {
            final_labour_amt = QString::number(selected_labour_balance.toFloat() + ui->lineEdit_labour_amount->text().toFloat(),'f',2);
            ui->label_labour_balance_title->setText("Advance Amt:");
            ui->label_labour_balance_amt->setText(final_labour_amt);
            final_bal_type = "0";
#if(SDK75)
            g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
            ui->pushButton_payment_labour_save->setFocus();
            return;
        }
    }
}

void Payment::on_pushButton_payment_labour_save_clicked()
{

    QString available_cash = get_cash_available(gstrUserName);
    if(available_cash.toFloat() >= ui->lineEdit_labour_amount->text().trimmed().toFloat())
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
        ui->lineEdit_labour_amount->setFocus();
        return;
#endif

    }

    QString balance_name = "emp_balance";
    if(selected_labour_type.contains("labour",Qt::CaseInsensitive))
    {
        balance_name = "emp_balance_bale_rate";
    }
    else
    {
        balance_name = "emp_balance";
    }
    if(databaseObj->executeCommand("update employee_master set "+balance_name+"='"+final_labour_amt+"',emp_balance_type='"+final_bal_type+"' where emp_name='"+selected_labour_name+"'"))
    {
        qDebug()<<"employee_master update success ===>>>";

        qDebug()<<"cash update before ===>>>"<<get_cash_available(gstrUserName);
        if(update_user_cash(ui->lineEdit_labour_amount->text().trimmed(),"-",gstrUserName))
        {
            qDebug()<<"cash update after ===>>>"<<get_cash_available(gstrUserName);
        }

        if(databaseObj->executeCommand("insert into employee_transaction (emp_name,day_no,paid_salary,emp_balance_type,pending_salary,opening_balance,opening_balance_type,is_payment) values ('"+selected_labour_name+"','"+gstrday_no+"','"+ui->lineEdit_labour_amount->text()+"','"+final_bal_type+"','"+final_labour_amt+"','"+selected_labour_balance+"','"+selected_labour_balance_type+"','1')"))
        {
            qDebug()<<"employee_transaction insert success ===>>>";
        }

        call_Payment();
    }
}

void Payment::on_pushButton_labour_clicked()
{
    //! org
    show_screen(3);




    //! temp

    //    this->close();
    //    Salary_CalculationObj->call_Salary_Calculation();
    //    Salary_CalculationObj->show();

}

void Payment::on_lineEdit_labour_name_returnPressed()
{
    if(!ui->lineEdit_labour_name->text().isEmpty())
    {
        selected_labour_name.clear();
        selected_labour_balance_type.clear();
        selected_labour_balance.clear();

        QSqlQuery query;
        if(databaseObj->selectQuery("select * from employee_master where emp_name='"+ui->lineEdit_labour_name->text().trimmed()+"' and is_active='1'",query))
        {
            if(query.next())
            {
                selected_labour_name = query.value(1).toString().trimmed();
                selected_labour_balance = query.value(8).toString().trimmed();
                selected_labour_balance_type = query.value(9).toString().trimmed();
                selected_labour_type = query.value(4).toString().trimmed();

                if(selected_labour_type.contains("labour",Qt::CaseInsensitive))
                {
                    selected_labour_balance = query.value(11).toString().trimmed();
                    selected_labour_balance_type = query.value(9).toString().trimmed();
                }
            }
        }

        if(selected_labour_balance.isEmpty())
        {
            selected_labour_balance = "0";
            selected_labour_balance_type = "0";
        }



        if(selected_labour_balance_type.toInt() == 0)
            ui->label_11->setText("Advance    :");
        if(selected_labour_balance_type.toInt() == 1)
            ui->label_11->setText("Balance    :");


        qDebug()<<"selected_labour_name ===>>>"<<selected_labour_name;
        qDebug()<<"selected_labour_balance ===>>>"<<selected_labour_balance;
        qDebug()<<"selected_labour_balance_type ===>>>"<<selected_labour_balance_type;
        ui->label_labour_pending->setText(selected_labour_balance);
#if(SDK75)
        g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
        ui->lineEdit_labour_amount->setFocus();
    }
}

void Payment::on_lineEdit_customer_returnPressed()
{
    if(!ui->lineEdit_customer->text().isEmpty())
    {
        QSqlQuery query;
        if(databaseObj->selectQuery("select * from customer_master where cus_name='"+ui->lineEdit_customer->text().trimmed()+"'",query))
        {
            if(query.next())
            {
                selected_cus_id = query.value(0).toString().trimmed();
                selected_cus_name = query.value(1).toString().trimmed();
                selected_cus_mobile = query.value(2).toString().trimmed();
                selected_cus_balance = query.value(3).toString().trimmed();
                selected_cus_balance_type = query.value(4).toString().trimmed();

                if(selected_cus_balance_type.toInt() == 0)
                {
                    ui->label_balance_title->setText("Advance:");
                }

                if(selected_cus_balance_type.toInt() == 1)
                {
                    ui->label_balance_title->setText("Pending:");
                }
            }
        }
        ui->lineEdit_customer->setText(selected_cus_name);
        ui->label_balance->setText(selected_cus_balance);
#if(SDK75)
        g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
        ui->lineEdit_paid_amt->setFocus();
    }
}

void Payment::on_pushButton_staff_clicked()
{
    if(!gstrUserName.contains("mcadmin"))
    {
        //        this->close();
        //        Staff_CashObj = new Staff_Cash;
        //        Staff_CashObj->call_Staff_Cash();
        //        Staff_CashObj->from_day_open = false;
        //        Staff_CashObj->show();

        this->close();
        Staff_CashObj->call_Staff_Cash();
        Staff_CashObj->on_pushButton_to_clicked();
        Staff_CashObj->show();
    }
}

void Payment::called_for_payment()
{
    ui->pushButton_staff->show();


    ui->pushButton_Husk->show();
    ui->pushButton_Diesel->show();
    ui->pushButton_labour->show();
    ui->pushButton_other->show();

    ui->pushButton_Husk->setFocus();
}

void Payment::called_for_receipt()
{
    ui->pushButton_staff->show();

    ui->pushButton_Husk->hide();
    ui->pushButton_Diesel->hide();
    ui->pushButton_labour->hide();
    ui->pushButton_other->hide();

    ui->pushButton_staff->setFocus();
}

void Payment::on_pushButton_print_4_clicked()
{
    QString available_cash = get_cash_available(gstrUserName);
    if(available_cash.toFloat() >= ui->lineEdit_paid_amt->text().trimmed().toFloat())
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

        ui->label_info_2->hide();
        ui->pushButton_print_4->setFocus();
        return;
#endif

    }

    QString str_bal_type;
    if(ui->label_Total_title->text().compare("Bal.Total:",Qt::CaseSensitive) == 0)
        str_bal_type = "1";
    if(ui->label_Total_title->text().compare("Adv.Total:",Qt::CaseSensitive) == 0)
        str_bal_type = "0";
    if(ui->label_Total_title->text().compare("Total:",Qt::CaseSensitive) == 0)
        str_bal_type = "0";

    QSqlQuery qry;
    if(databaseObj->selectQuery("select payment_bill_no from configuration_master",qry))
    {
        if(qry.next())
        {
            if(qry.value(0).toString().trimmed().isEmpty())
            {
                gstrpayBillNo="00001";
                if(databaseObj->executeCommand("update configuration_master set payment_bill_no='0000'"))
                {
                    databaseObj->con.commit();
                }
            }
            else
                gstrpayBillNo=QString::number(qry.value(0).toInt() + 1).rightJustified(5,'0');
        }
        else{
            gstrpayBillNo="00001";
            if(databaseObj->executeCommand("update configuration_master set payment_bill_no='0000'"))
            {
                databaseObj->con.commit();
            }
        }
    }

    if(databaseObj->executeCommand("insert into transaction_master (cus_id,cus_name,vehicle_no,previous_balance,paid,balance,uploade_flag,balance_type,is_payment,day_no,previous_balance_type,bill_no) values ('"+selected_cus_id+"','"+selected_cus_name+"','"+selected_vehicle_number+"','"+selected_cus_balance+"','"+ui->lineEdit_paid_amt->text().trimmed()+"','"+final_total+"','0','"+str_bal_type+"','1','"+gstrday_no+"','"+selected_cus_balance_type+"','"+gstrpayBillNo+"')"))
    {
        qDebug()<<"insert from husk payment ===>>>";

        qDebug()<<"cash update before ===>>>"<<get_cash_available(gstrUserName);
        if(update_user_cash(ui->lineEdit_paid_amt->text().trimmed(),"-",gstrUserName))
        {
            qDebug()<<"cash update after ===>>>"<<get_cash_available(gstrUserName);
        }

        if(databaseObj->executeCommand("update customer_master set balance='"+final_total+"',balance_type='"+str_bal_type+"' where id_customer_master='"+selected_cus_id+"'"))
        {
            if(databaseObj->executeCommand("update configuration_master set payment_bill_no='"+gstrpayBillNo+"'"))
            {
                qDebug()<<"payment_bill_no update success ===>>>";
            }
#if(NativeCompile)
            QMessageBox gMsg_box;
            QFont gFont;
            gFont.setFamily("DejaVu Sans Mono");
            gFont.setPointSize(12);
            gMsg_box.setFont(gFont);
            gMsg_box.setParent(this);

            if(gMsg_box.information(this, "Success","Payment Saved Successfully..!",QMessageBox::Ok) == QMessageBox::Ok)
            {
                show_screen(1);
            }
#endif

#if(SDK75)
            int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"Payment Saved\nSuccessfully..!",16,14);


#if(SDK75)

            ui->label_info->show();
            ui->label_info->raise();

            qApp->processEvents();
            qApp->processEvents();

            CPrinter print;
            print.setFontType(CPrinter::eFontType_font2);

            QStringList lst_print_data;

            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            lst_print_data << "--------------------------------------" ;

            print.addData("Payment Receipt",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
            lst_print_data << "Payment Receipt";

            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            lst_print_data << "--------------------------------------";

            print.addData(("Payment Receipt No.:")+gstrpayBillNo,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            lst_print_data << "Payment Receipt No.:"+gstrpayBillNo;

            print.addData(StringAlign("Date & Time:",15)+QDate::currentDate().toString("dd-MM-yyyy")+" "+QTime::currentTime().toString("hh:mm"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            lst_print_data << StringAlign("Date & Time:",15)+QDate::currentDate().toString("dd-MM-yyyy")+" "+QTime::currentTime().toString("hh:mm") ;

            print.addData(StringAlign("USER Name  :",15)+gstrUserName,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            lst_print_data << StringAlign("USER Name  :",15)+gstrUserName;

            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            lst_print_data << "--------------------------------------";

            print.addData(StringAlign("Party Name :",15)+selected_cus_name,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            lst_print_data << StringAlign("Party Name :",15)+selected_cus_name;
            selected_cus_name.clear();

            print.addData(StringAlign("Vehicle No. :",15)+selected_vehicle_number,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            lst_print_data << StringAlign("Vehicle No. :",15)+selected_vehicle_number;
            selected_vehicle_number.clear();

            print.addData(StringAlign("Vehicle Type :",15)+selected_vehicle_type_name,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            lst_print_data << StringAlign("Vehicle Type :",15)+selected_vehicle_type_name;
            selected_vehicle_type_name.clear();

            print.addData(StringAlign("Pre."+ui->label_balance_title->text().remove(":").append(" Amt:"),18)+selected_cus_balance,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            lst_print_data << StringAlign("Pre."+ui->label_balance_title->text().remove(":").append(" Amt:"),18)+selected_cus_balance;
            selected_cus_balance.clear();

            print.addData(StringAlign("Paid Amount :",15)+" Rs."+ui->lineEdit_paid_amt->text(),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            lst_print_data << StringAlign("Paid Amount :",15)+" Rs."+ui->lineEdit_paid_amt->text();

            print.addData(StringAlign(ui->label_Total_title->text().trimmed()+":",15)+" Rs."+ui->label_Total->text().trimmed(),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            lst_print_data << StringAlign(ui->label_Total_title->text().trimmed()+":",15)+" Rs."+ui->label_Total->text().trimmed();


            QFile fOut("/home/root/last_print_payment.txt");
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
            ui->label_info_2->hide();
            ui->label_info_2->lower();

            ui->groupBox_preview->hide();
            ui->label_info->hide();
#endif
            show_screen(1);
#endif
        }
    }
}

void Payment::addPreViewData(const QString &r_const_strDATA,
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

void Payment::on_lineEdit_vehicle_number_textEdited(const QString &arg1)
{
    ui->lineEdit_vehicle_number->setText(arg1.toUpper());
}

void Payment::on_lineEdit_paid_amt_textEdited(const QString &arg1)
{

    ui->pushButton_husk_payment_save->setEnabled(false);
}
