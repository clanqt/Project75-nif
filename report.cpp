#include "report.h"
#include "ui_report.h"

#include <QMessageBox>
#include <QDebug>

#include <global.h>
using namespace Global;


Report::Report(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Report)
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


    scroll = new QScrollArea(ui->groupBox);
    scroll->setWidget(ui->verticalLayoutWidget);
    scroll->move(0,30);
    scroll->setFixedSize(320,150);//160
    scroll->setFocusPolicy(Qt::NoFocus);
    scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


}

Report::~Report()
{
    delete ui;
}

void Report::keyPressEvent(QKeyEvent *ke)
{
    if(ke->key()== Qt::Key_Escape)
    {
        if(ui->groupBox->isVisible())
        {
            this->close();
            menuObj->call_menu();
            menuObj->show();
        }
        else
        {
            call_Report();
        }
    }
}

void Report::call_Report()
{

    ui->groupBox_batch_report->hide();
    ui->groupBox_batch_report->move(0,0);

    ui->groupBox_batch_supplier->hide();
    ui->groupBox_batch_supplier->move(0,0);

    ui->groupBox_supplier_report->hide();
    ui->groupBox_supplier_report->move(0,0);

    ui->groupBox_bale_production->hide();
    ui->groupBox_bale_production->move(0,0);

    ui->groupBox_Employee_Report->hide();
    ui->groupBox_Employee_Report->move(0,0);


    ui->groupBox_day_close->hide();
    ui->groupBox_day_close->move(0,0);

    ui->groupBox_Expense_Report->hide();
    ui->groupBox_Expense_Report->move(0,0);


    ui->groupBox_bunk_report->hide();
    ui->groupBox_bunk_report->move(0,0);

    ui->groupBox_Receipt_Payment_Report->hide();
    ui->groupBox_Receipt_Payment_Report->move(0,0);

    ui->groupBox_diesel_consumption->hide();
    ui->groupBox_diesel_consumption->move(0,0);

    ui->lineEdit_supplier_vno->setValidator(gAmtValidator2);


    //    ui->comboBox_batch->setEnabled(true);


    //    ui->label_purchase->clear();
    //    ui->label_husk_bale->clear();
    //    ui->label_bale->clear();
    //    ui->label_purchase->clear();
    //    ui->label_gain_lose->clear();
    ui->comboBox_batch->clear();

    ui->dateEdit_from->setDateTime(QDateTime::currentDateTime());
    ui->dateEdit_to->setDateTime(QDateTime::currentDateTime().addDays(1));


    ui->dateEdit_from->setCurrentSection(QDateEdit::DaySection);
    ui->dateEdit_to->setCurrentSection(QDateEdit::DaySection);

    ui->dateEdit_from_supplier->setDateTime(QDateTime::currentDateTime());
    ui->dateEdit_to_supplier->setDateTime(QDateTime::currentDateTime());

    ui->dateEdit_from_supplier->setCurrentSection(QDateEdit::DaySection);
    ui->dateEdit_to_supplier->setCurrentSection(QDateEdit::DaySection);


    ui->dateEdit_from_bale_production->setCurrentSection(QDateEdit::DaySection);
    ui->dateEdit_to_bale_production->setCurrentSection(QDateEdit::DaySection);

    ui->dateEdit_from_bale_production->setDateTime(QDateTime::currentDateTime());
    ui->dateEdit_to_bale_production->setDateTime(QDateTime::currentDateTime().addDays(1));

    ui->dateEdit_from_Receipt_Payment_Report->setDateTime(QDateTime::currentDateTime());
    ui->dateEdit_to_Receipt_Payment_Report->setDateTime(QDateTime::currentDateTime().addDays(1));

    ui->dateEdit_from_Receipt_Payment_Report->setCurrentSection(QDateEdit::DaySection);
    ui->dateEdit_to_Receipt_Payment_Report->setCurrentSection(QDateEdit::DaySection);

    ui->dateEdit_from_bunk->setDateTime(QDateTime::currentDateTime());
    ui->dateEdit_to_bunk->setDateTime(QDateTime::currentDateTime().addDays(1));

    ui->dateEdit_from_bunk->setCurrentSection(QDateEdit::DaySection);
    ui->dateEdit_to_bunk->setCurrentSection(QDateEdit::DaySection);

    ui->dateEdit_from->setDateTime(QDateTime::currentDateTime());
    ui->dateEdit_to->setDateTime(QDateTime::currentDateTime().addDays(1));

    ui->dateEdit_from->setCurrentSection(QDateEdit::DaySection);
    ui->dateEdit_to->setCurrentSection(QDateEdit::DaySection);

    ui->dateEdit_from_diesel->setDateTime(QDateTime::currentDateTime());
    ui->dateEdit_to_diesel->setDateTime(QDateTime::currentDateTime().addDays(1));

    ui->dateEdit_from_diesel->setCurrentSection(QDateEdit::DaySection);
    ui->dateEdit_to_diesel->setCurrentSection(QDateEdit::DaySection);

    ui->dateEdit_from->installEventFilter(this);
    ui->dateEdit_to->installEventFilter(this);

    ui->dateEdit_from_supplier->installEventFilter(this);
    ui->dateEdit_to_supplier->installEventFilter(this);

    ui->dateEdit_from_bale_production->installEventFilter(this);
    ui->dateEdit_to_bale_production->installEventFilter(this);

    ui->dateEdit_from_Employee_Report->installEventFilter(this);
    ui->dateEdit_to_Employee_Report->installEventFilter(this);

    ui->dateEdit_from_Expense_Report->installEventFilter(this);
    ui->dateEdit_to_Expense_Report->installEventFilter(this);

    ui->dateEdit_from_Receipt_Payment_Report->installEventFilter(this);
    ui->dateEdit_to_Receipt_Payment_Report->installEventFilter(this);

    ui->dateEdit_from_bunk->installEventFilter(this);
    ui->dateEdit_to_bunk->installEventFilter(this);

    ui->dateEdit_from_diesel->installEventFilter(this);
    ui->dateEdit_to_diesel->installEventFilter(this);

    ui->comboBox_batch->installEventFilter(this);
    ui->lineEdit_batch_supplier->installEventFilter(this);

    ui->pushButton_print_supplier_report->setEnabled(false);
    ui->pushButton_print_bale_production->setEnabled(false);
    ui->pushButton_print_diesel->setEnabled(false);

    ui->pushButton_print_Receipt_Payment_Report->setEnabled(false);

    ui->groupBox->show();
    ui->pushButton_day_close->setFocus();

    QSqlQuery vehicle_details;
    if(databaseObj->selectQuery("select emp_name from employee_master where is_active='1'",vehicle_details))
    {
        if(vehicle_details.next())
        {
            lst_emp_name.clear();
            lst_emp_name << vehicle_details.value(0).toString().trimmed();
            while(vehicle_details.next())
            {
                lst_emp_name << vehicle_details.value(0).toString().trimmed();
            }
        }
    }

    cmpte6 = new QCompleter(lst_emp_name,this);
    cmpte6->setCaseSensitivity(Qt::CaseInsensitive);
    cmpte6->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->lineEdit_name_Employee_Report->setCompleter(cmpte6);


    vehicle_details.clear();
    if(databaseObj->selectQuery("select expense_master.expense_name from expense_master",vehicle_details))
    {
        if(vehicle_details.next())
        {
            lst_expense_name.clear();
            lst_expense_name << vehicle_details.value(0).toString().trimmed();
            while(vehicle_details.next())
            {
                lst_expense_name << vehicle_details.value(0).toString().trimmed();
            }
        }
    }

    cmpte7 = new QCompleter(lst_expense_name,this);
    cmpte7->setCaseSensitivity(Qt::CaseInsensitive);
    cmpte7->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->lineEdit_name_Expense_Report->setCompleter(cmpte7);


    ui->pushButton_print_bunk_report->setEnabled(false);
    QSqlQuery b_qur;
    lst_bunk_name_report.clear();
    lst_bunk_id_report.clear();
    if(databaseObj->selectQuery("select bunk_name,id_bunk_master from bunk_master",b_qur))
    {
        if(b_qur.next())
        {
            lst_bunk_name_report << b_qur.value(0).toString().trimmed();
            lst_bunk_id_report << b_qur.value(1).toString().trimmed();
            while(b_qur.next())
            {
                lst_bunk_name_report << b_qur.value(0).toString().trimmed();
                lst_bunk_id_report << b_qur.value(1).toString().trimmed();
            }

            cmpte8 = new QCompleter(lst_bunk_name_report,this);
            cmpte8->setCaseSensitivity(Qt::CaseInsensitive);
            cmpte8->setCompletionMode(QCompleter::PopupCompletion);
            ui->lineEdit_bunk_name->setCompleter(cmpte8);
        }
    }
}

bool Report::eventFilter(QObject *target, QEvent *event)
{
    QKeyEvent *key = static_cast <QKeyEvent*> (event);

    if(target == ui->comboBox_batch)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->comboBox_batch->hasFocus() && !ui->comboBox_batch->currentText().isEmpty())
                {

                    QString batch_name;
                    if(ui->comboBox_batch->currentText().contains("company",Qt::CaseInsensitive))
                        batch_name = "company_batch_no";
                    if(ui->comboBox_batch->currentText().contains("auto",Qt::CaseInsensitive))
                        batch_name = "other_batch_no";
                    if(ui->comboBox_batch->currentText().contains("van",Qt::CaseInsensitive))
                        batch_name = "van_batch_no";


                    QSqlQuery batch_close_qur;
                    batch_close_qur.clear();
                    if(databaseObj->selectQuery("select batch_no,total_husk_produced,est_bale,manu_bale,used_husk,excess_husk,diff_bale from "+batch_name+" where batch_no='"+QString::number(ui->comboBox_batch->currentText().split(" ").at(1).toInt())+"'",batch_close_qur))
                    {
                        if(batch_close_qur.next())
                        {
                            CPrinter print;
                            print.setFontType(CPrinter::eFontType_font2);

                            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

                            print.addData("BATCH CLOSE REPORT",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
                            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

                            print.addData("FROM :"+ui->dateEdit_from->date().toString("dd-MM-yyyy")+"  TO: "+ui->dateEdit_to->date().toString("dd-MM-yyyy"),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

                            print.addData("BATCH NAME        : "+ui->comboBox_batch->currentText().toUpper(),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                            print.addData("TOTAL PURCHASE    : "+batch_close_qur.value(1).toString().trimmed().append(" NOS"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

                            print.addData("TOTAL NO OF BALE  : "+batch_close_qur.value(3).toString().trimmed().append(" NOS"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                            print.addData("NO OF HUSK TO BALE: "+batch_close_qur.value(4).toString().trimmed().append(" NOS"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

                            QString diff_bale = batch_close_qur.value(6).toString().trimmed().append(" NOS");
                            QString diff_bale1 = diff_bale;

                            int diff_husk = batch_close_qur.value(4).toInt() - batch_close_qur.value(1).toInt();

                            print.addData("DIFFERENCE        :"+QString::number(diff_husk),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

                            //                            if(diff_bale1.contains("-"))
                            //                                print.addData("DIFFERENCE        :"+diff_bale.remove("-"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                            //                            else
                            //                                print.addData("DIFFERENCE        :"+diff_bale.prepend("-"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

                            if(diff_husk > 0)
                                print.addData("GAIN",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                            else
                                print.addData("LOSS",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

                            while(batch_close_qur.next())
                            {
                                print.addData("BATCH NAME        : "+ui->comboBox_batch->currentText().toUpper(),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                                print.addData("TOTAL PURCHASE    : "+batch_close_qur.value(1).toString().trimmed().append(" NOS"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                                print.addData("TOTAL NO OF BALE  : "+batch_close_qur.value(3).toString().trimmed().append(" NOS"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                                print.addData("NO OF HUSK TO BALE:"+batch_close_qur.value(2).toString().trimmed().append(" NOS"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

                                QString diff_bale = batch_close_qur.value(6).toString().trimmed().append(" NOS");
                                QString diff_bale1 = diff_bale;

                                if(diff_bale1.contains("-"))
                                    print.addData("DIFFERENCE        :"+diff_bale.remove("-"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                                else
                                    print.addData("DIFFERENCE        :"+diff_bale.prepend("-"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

                                if(diff_bale1.contains("-"))
                                    print.addData("GAIN",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                                else
                                    print.addData("LOSS",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                            }

                            print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                            print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                            print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                            print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                            if(print.print(false,false))
                            {
                                call_Report();
                            }
                        }
                    }






                    //                    int ind = ui->comboBox_batch->currentIndex();
                    //                    qDebug()<<"comboBox_batch 1 ===>>>"<<QString::number(ind);
                    //                    ui->label_purchase->setText(lst_purchase.at(ui->comboBox_batch->currentIndex()));
                    //                    qDebug()<<"comboBox_batch 2 ===>>>";
                    //                    ui->label_bale->setText(lst_bale.at(ui->comboBox_batch->currentIndex()));
                    //                    qDebug()<<"comboBox_batch 3 ===>>>";


                    //                    float h_to_b = lst_husk_bale.at(ui->comboBox_batch->currentIndex()).toFloat() / Home_ScreenObj->HP_bale.toFloat();
                    //                    qDebug()<<"comboBox_batch 4 ===>>>";
                    //                    qDebug()<<"husk to bale 5 ===>>>"<<QString::number(h_to_b,'f',2);
                    //                    qDebug()<<"comboBox_batch 6 ===>>>";

                    //                    ui->label_husk_bale->setText(QString::number(h_to_b,'f',2));
                    //                    qDebug()<<"husk to bale 1 ===>>>";
                    //                    ui->label_gain_lose->setText(lst_gain_lose.at(ui->comboBox_batch->currentIndex()));
                    //                    qDebug()<<"husk to bale 2 ===>>>";

                    return true;
                }
            }
        }

    }
    else if(target == ui->lineEdit_batch_supplier)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->lineEdit_batch_supplier->hasFocus() && !ui->lineEdit_batch_supplier->text().isEmpty())
                {

                    if((ui->lineEdit_batch_supplier->text().trimmed().contains("company",Qt::CaseInsensitive) || ui->lineEdit_batch_supplier->text().trimmed().contains("auto",Qt::CaseInsensitive) || ui->lineEdit_batch_supplier->text().trimmed().contains("van",Qt::CaseInsensitive) ) && ui->lineEdit_batch_supplier->text().trimmed().contains(" "))
                    {

                    }
                    else
                    {
#if(SDK75)
                            int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Critical,"Invalid Input.",16,14);
                            g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
                            ui->lineEdit_batch_supplier->selectAll();
#endif
                        ui->lineEdit_batch_supplier->setFocus();
                        return;
                    }


                    QSqlQuery batch_supplier_qur;

                    QString bat_type,bat_num;
                    //                        if(ui->lineEdit_batch_supplier->text().trimmed().contains())
                    if( ui->lineEdit_batch_supplier->text().trimmed().contains("company",Qt::CaseInsensitive))
                        bat_type = "0";
                    if( ui->lineEdit_batch_supplier->text().trimmed().contains("auto",Qt::CaseInsensitive))
                        bat_type = "1";
                    if( ui->lineEdit_batch_supplier->text().trimmed().contains("van",Qt::CaseInsensitive))
                        bat_type = "2";

                    bat_num = QString::number(ui->lineEdit_batch_supplier->text().trimmed().split(" ").at(1).toInt());
                    qDebug()<<"bat_num ===>>>"<<bat_num;

                    if(databaseObj->selectQuery("select vehicle_no,cus_name,count(vehicle_no),sum(inward_bale),sum(inward_hush) from transaction_master where is_void is null and batch_no='"+bat_num+"' and batch_type='"+bat_type+"' group by cus_name",batch_supplier_qur))
                    {
                        if(batch_supplier_qur.next())
                        {

                            CPrinter print;
                            print.setFontType(CPrinter::eFontType_font2);

                            print.addData("Batch Supplier Report",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);

                            print.addData("Batch :"+ui->lineEdit_batch_supplier->text().trimmed(),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);


                            QString batch_name;
                            if(ui->lineEdit_batch_supplier->text().trimmed().contains("company",Qt::CaseInsensitive))
                                batch_name = "company_batch_no";
                            if(ui->lineEdit_batch_supplier->text().trimmed().contains("auto",Qt::CaseInsensitive))
                                batch_name = "other_batch_no";
                            if(ui->lineEdit_batch_supplier->text().trimmed().contains("van",Qt::CaseInsensitive))
                                batch_name = "van_batch_no";

                            QSqlQuery b_date_qur;
                            if(databaseObj->selectQuery("select "+batch_name+".open_date,day_master.open_date as close_date from "+batch_name+" inner join day_master on day_master.day_no="+batch_name+".day_no_close where "+batch_name+".batch_no="+bat_num,b_date_qur))
                            {
                                if(b_date_qur.next())
                                {
                                    print.addData("From :"+b_date_qur.value(0).toString().trimmed()+"TO :"+b_date_qur.value(1).toString().trimmed(),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                                }
                            }




                            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                            print.addData("VEHICLE PRO/SUPP LOADS CFT HUSKS",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);


                            QString batch_supplier_details = batch_supplier_qur.value(0).toString().remove(" ").trimmed().leftJustified(10,' ',1)+" "+batch_supplier_qur.value(1).toString().remove(" ").trimmed().leftJustified(7,' ', true)+" "+batch_supplier_qur.value(2).toString().trimmed().rightJustified(2,' ', true)+" "+QString::number(batch_supplier_qur.value(3).toString().trimmed().toFloat(),'f',2).rightJustified(6,' ', true)+" "+QString::number(batch_supplier_qur.value(4).toString().trimmed().toFloat(),'f',2).rightJustified(9,' ', true);
                            qDebug()<<"batch_supplier_details ===>>>"<<batch_supplier_details;
                            print.addData(batch_supplier_details,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                            while(batch_supplier_qur.next())
                            {
                                QString batch_supplier_details = batch_supplier_qur.value(0).toString().remove(" ").trimmed().leftJustified(10,' ',1)+" "+batch_supplier_qur.value(1).toString().remove(" ").trimmed().leftJustified(7,' ', true)+" "+batch_supplier_qur.value(2).toString().trimmed().rightJustified(2,' ', true)+" "+QString::number(batch_supplier_qur.value(3).toString().trimmed().toFloat(),'f',2).rightJustified(6,' ', true)+" "+QString::number(batch_supplier_qur.value(4).toString().trimmed().toFloat(),'f',2).rightJustified(9,' ', true);
                                qDebug()<<"batch_supplier_details ===>>>"<<batch_supplier_details;
                                print.addData(batch_supplier_details,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                            }

                            batch_supplier_qur.clear();
                            if(databaseObj->selectQuery("select sum(inward_bale),sum(inward_hush),count(transaction_master.vehicle_no) from transaction_master where is_void is null and batch_no='"+bat_num+"' and batch_type='"+bat_type+"'",batch_supplier_qur))
                            {
                                if(batch_supplier_qur.next())
                                {
                                    QString Total_print = "Total "+batch_supplier_qur.value(2).toString().trimmed()+" "+QString::number(batch_supplier_qur.value(0).toString().trimmed().toFloat(),'f',2)+" "+batch_supplier_qur.value(1).toString().trimmed();
                                    qDebug()<<"Total_print ===>>>"<<Total_print;
                                    print.addData(Total_print,CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_RIGHT);
                                }
                            }

                            print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                            print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                            print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                            print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

                            if(print.print(false,false))
                            {

                            }
                            call_Report();
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

                            if(gMsg_box.information(this, "Success","No Result\nFound..!",QMessageBox::Ok) == QMessageBox::Ok)
                            {
                                ui->dateEdit_to->setFocus();
                            }
#endif

#if(SDK75)
                            int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Critical,"No Result\nFound.",16,14);
                            g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
                            ui->lineEdit_batch_supplier->selectAll();
#endif
                        }

                    }

                    return true;
                }
            }
        }

    }


    else if(target == ui->dateEdit_from_diesel)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->dateEdit_from_diesel->hasFocus())
                {
                    ui->dateEdit_to_diesel->setFocus();
                    ui->dateEdit_to_diesel->setDate(ui->dateEdit_to_diesel->date().addDays(1));
#if(SDK75)
                    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                    ui->dateEdit_to_diesel->setCurrentSection(QDateEdit::DaySection);

                    return true;
                }
            }
        }
    }

    else if(target == ui->dateEdit_to_diesel)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->dateEdit_to_diesel->hasFocus())
                {
                    ui->pushButton_print_diesel->setEnabled(true);
                    ui->pushButton_print_diesel->setFocus();
#if(SDK75)
                    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif

//                    ui->dateEdit_to_diesel->setDate(ui->dateEdit_to_diesel->date().addDays(1));
//#if(SDK75)
//                    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
//#endif
//                    ui->dateEdit_to_diesel->setCurrentSection(QDateEdit::DaySection);

                    return true;
                }
            }
        }
    }

    else if(target == ui->dateEdit_from_bunk)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->dateEdit_from_bunk->hasFocus())
                {
                    ui->dateEdit_to_bunk->setFocus();
                    ui->dateEdit_to_bunk->setDate(ui->dateEdit_from_bunk->date().addDays(1));
#if(SDK75)
                    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                    ui->dateEdit_to_bunk->setCurrentSection(QDateEdit::DaySection);

                    return true;
                }
            }
        }
    }



    else if(target == ui->dateEdit_to_bunk)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->dateEdit_to_bunk->hasFocus())
                {
                    ui->lineEdit_bunk_name->setFocus();

#if(SDK75)
                    g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
#endif


                    return true;
                }
            }
        }
    }
    else if(target == ui->dateEdit_from_Receipt_Payment_Report)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->dateEdit_from_Receipt_Payment_Report->hasFocus())
                {
                    ui->dateEdit_to_Receipt_Payment_Report->setFocus();
                    ui->dateEdit_to_Receipt_Payment_Report->setDate(ui->dateEdit_from_Receipt_Payment_Report->date().addDays(1));
#if(SDK75)
                    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                    ui->dateEdit_to_Receipt_Payment_Report->setCurrentSection(QDateEdit::DaySection);

                    return true;
                }
            }
        }
    }

    else if(target == ui->dateEdit_to_Receipt_Payment_Report)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->dateEdit_to_Receipt_Payment_Report->hasFocus())
                {
                    ui->pushButton_print_Receipt_Payment_Report->setEnabled(true);
                    ui->pushButton_print_Receipt_Payment_Report->setFocus();

#if(SDK75)
                    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif


                    return true;
                }
            }
        }
    }

    else if(target == ui->dateEdit_from_supplier)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->dateEdit_from_supplier->hasFocus())
                {
                    ui->dateEdit_to_supplier->setFocus();
                    ui->dateEdit_to_supplier->setDate(ui->dateEdit_to_supplier->date());
#if(SDK75)
                    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                    ui->dateEdit_to_supplier->setCurrentSection(QDateEdit::DaySection);

                    return true;
                }
            }
        }

    }
    else if(target == ui->dateEdit_to_supplier)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->dateEdit_to_supplier->hasFocus())
                {
                    //                    print_supplier_report();
#if(SDK75)
                    g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
#endif
                    ui->lineEdit_supplier_vno->setFocus();
                    return true;
                }

            }
        }

    }

    else if(target == ui->dateEdit_from_bale_production)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->dateEdit_from_bale_production->hasFocus())
                {
                    ui->dateEdit_to_bale_production->setFocus();
                    return true;
                }
            }
        }

    }
    else if(target == ui->dateEdit_to_bale_production)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->dateEdit_to_bale_production->hasFocus())
                {
                    ui->pushButton_print_bale_production->setEnabled(true);
                    ui->pushButton_print_bale_production->setFocus();
                    return true;
                }
            }
        }

    }

    else if(target == ui->dateEdit_from_Employee_Report)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->dateEdit_from_Employee_Report->hasFocus())
                {
                    ui->dateEdit_to_Employee_Report->setDate(ui->dateEdit_from_Employee_Report->date().addDays(1));
                    ui->dateEdit_to_Employee_Report->setMinimumDate(ui->dateEdit_from_Employee_Report->date().addDays(1));
                    ui->dateEdit_to_Employee_Report->setFocus();
                    return true;
                }
            }
        }

    }
    else if(target == ui->dateEdit_to_Employee_Report)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->dateEdit_to_Employee_Report->hasFocus())
                {
                    ui->lineEdit_name_Employee_Report->setFocus();
                    return true;
                }
            }
        }

    }

    else if(target == ui->dateEdit_from_Expense_Report)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->dateEdit_from_Expense_Report->hasFocus())
                {
                    ui->dateEdit_to_Expense_Report->setDate(ui->dateEdit_from_Expense_Report->date().addDays(1));
                    ui->dateEdit_to_Expense_Report->setMinimumDate(ui->dateEdit_from_Expense_Report->date().addDays(1));
                    ui->dateEdit_to_Expense_Report->setFocus();
                    return true;
                }
            }
        }

    }
    else if(target == ui->dateEdit_to_Expense_Report)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->dateEdit_to_Expense_Report->hasFocus())
                {
                    ui->lineEdit_name_Expense_Report->setFocus();
                    return true;
                }
            }
        }

    }


    else if(target == ui->dateEdit_from)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->dateEdit_from->hasFocus())
                {
                    ui->dateEdit_to->setFocus();
                    return true;
                }
            }
        }

    }
    else if(target == ui->dateEdit_to)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->dateEdit_to->hasFocus())
                {

                    QSqlQuery date_qur;
                    QStringList lst_day_no;

                    lst_batch_no.clear();
                    lst_purchase.clear();
                    lst_bale.clear();
                    lst_husk.clear();
                    lst_husk_bale.clear();
                    lst_gain_lose.clear();

                    if(databaseObj->selectQuery("select day_no from day_master  where (substr(open_date, 7, 4) || '-' || substr(open_date, 4, 2) || '-' || substr(open_date, 1, 2)) between '"+ui->dateEdit_from->date().toString("yyyy-MM-dd")+"' and '"+ui->dateEdit_to->date().toString("yyyy-MM-dd")+"' and status='0'",date_qur))
                    {
                        qDebug()<<"test ===>>>1";
                        if(date_qur.next())
                        {
                            qDebug()<<"test ===>>>1.0";
                            lst_day_no << date_qur.value(0).toString().trimmed();
                            while(date_qur.next())
                            {
                                qDebug()<<"test ===>>>1.1";
                                lst_day_no << date_qur.value(0).toString().trimmed();
                            }
                            qDebug()<<"test ===>>>1.2"<<lst_day_no;

                        }
                        qDebug()<<"test ===>>>2";
                        if(lst_day_no.size() > 0)
                        {
                            qDebug()<<"test ===>>>2.1";
                            QStringList lst_batch;
                            lst_batch << "company_batch_no" << "other_batch_no" << "van_batch_no";
                            qDebug()<<"test ===>>>2.1";

                            for(int i=0;i<lst_batch.size();i++)
                            {
                                qDebug()<<"test ===>>>3";
                                //! batch close
                                for(int d=0;d<lst_day_no.size();d++)
                                {
                                    qDebug()<<"test ===>>>4"<<lst_day_no;
                                    QSqlQuery batch_day_qur;
                                    if(databaseObj->selectQuery("select * from "+lst_batch.at(i)+" where day_no_close='"+lst_day_no.at(d)+"' and production_status='0'",batch_day_qur))
                                    {
                                        qDebug()<<"test ===>>>4.1";
                                        if(batch_day_qur.next())
                                        {
                                            qDebug()<<"test ===>>>4.2";
                                            QString batch_name;
                                            if(lst_batch.at(i).contains("company",Qt::CaseInsensitive))
                                                batch_name = "Company ";
                                            if(lst_batch.at(i).contains("other",Qt::CaseInsensitive))
                                                batch_name = "Auto ";
                                            if(lst_batch.at(i).contains("van",Qt::CaseInsensitive))
                                                batch_name = "Van ";

                                            qDebug()<<"test ===>>>4.3";
                                            lst_batch_no << batch_name+batch_day_qur.value(0).toString().trimmed().rightJustified(3,'0');
                                            lst_purchase << batch_day_qur.value(9).toString().trimmed();
                                            lst_bale << batch_day_qur.value(3).toString().trimmed();
                                            lst_husk_bale << batch_day_qur.value(11).toString().trimmed();
                                            QString gl = batch_day_qur.value(12).toString().trimmed();
                                            qDebug()<<"gain r lose ===>>>"<<gl;
                                            if(gl.contains("-"))
                                            {
                                                lst_gain_lose << "Gain";
                                            }
                                            else{
                                                lst_gain_lose << "Loss";
                                            }

                                            while(batch_day_qur.next())
                                            {
                                                QString batch_name;
                                                if(lst_batch.at(d).contains("company",Qt::CaseInsensitive))
                                                    batch_name = "Company ";
                                                if(lst_batch.at(d).contains("other",Qt::CaseInsensitive))
                                                    batch_name = "Auto ";
                                                if(lst_batch.at(d).contains("van",Qt::CaseInsensitive))
                                                    batch_name = "Van ";

                                                lst_batch_no << batch_name+batch_day_qur.value(0).toString().trimmed().rightJustified(3,'0');
                                                lst_purchase << batch_day_qur.value(9).toString().trimmed();
                                                lst_bale << batch_day_qur.value(3).toString().trimmed();
                                                lst_husk_bale << batch_day_qur.value(11).toString().trimmed();

                                                QString gl = batch_day_qur.value(12).toString().trimmed();
                                                qDebug()<<"gain r lose ===>>>"<<gl;
                                                if(gl.contains("-"))
                                                {
                                                    lst_gain_lose << "Gain";
                                                }
                                                else{
                                                    lst_gain_lose << "Loss";
                                                }
                                            }
                                            qDebug()<<"test ===>>>4.4";
                                            qDebug()<<"lst_batch_no ===>>>"<<lst_batch_no;
                                            qDebug()<<"lst_purchase ===>>>"<<lst_purchase;
                                            qDebug()<<"lst_bale ===>>>"<<lst_bale;
                                            qDebug()<<"lst_husk_bale ===>>>"<<lst_husk_bale;
                                            qDebug()<<"lst_gain_lose ===>>>"<<lst_gain_lose;

                                        }
                                    }
                                }
                            }
                            ui->comboBox_batch->clear();
                            if(lst_batch_no.size() > 0)
                            {
                                qDebug()<<"test ===>>>5";
                                ui->comboBox_batch->addItems(lst_batch_no);
                                ui->comboBox_batch->setCurrentIndex(0);
                                qDebug()<<"test ===>>>5.1";
                            }
                            qDebug()<<"test ===>>>6";


                            //!
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

                            if(gMsg_box.information(this, "Success","No Result\nFound..!",QMessageBox::Ok) == QMessageBox::Ok)
                            {
                                ui->dateEdit_to->setFocus();
                            }
#endif

#if(SDK75)
                            int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Critical,"No Result\nFound.",16,14);
                            ui->dateEdit_to->setFocus();
#endif
                        }
                    }

                    ui->comboBox_batch->setFocus();
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

void Report::on_pushButton_day_close_clicked()
{

    //    day_close_report();
    //    return;



    QSqlQuery day_qur;
    if(databaseObj->selectQuery("select day_no from day_master where status='0'",day_qur))
    {
        //        QStringList lst_day_close_no;
        if(day_qur.next())
        {
            lst_day_close_no << "Day "+day_qur.value(0).toString().trimmed().rightJustified(3,'0');
            while(day_qur.next())
            {
                lst_day_close_no << "Day "+day_qur.value(0).toString().trimmed().rightJustified(3,'0');
            }
            cmpte5 = new QCompleter(lst_day_close_no,this);
            cmpte5->setCaseSensitivity(Qt::CaseInsensitive);
            cmpte5->setCompletionMode(QCompleter::PopupCompletion);
            ui->lineEdit_day_no->setCompleter(cmpte5);

            ui->groupBox->hide();

            ui->groupBox_day_close->show();
            ui->groupBox_day_close->raise();

            ui->lineEdit_day_no->setFocus();
        }
    }
}

void Report::day_close_report()
{
#if(SDK75)
    QSqlQuery day_details;
    QString report_day_no;
    if(databaseObj->selectQuery("SELECT day_no,status,open_date,open_time,close_date,close_time,open_bull_reading,open_gen_reading,open_eb_reading,open_diesel_reading,opening_bale_balance FROM day_master WHERE id_day= (SELECT MAX(id_day) FROM day_master where status='0')",day_details))
    {
        //#if(SDK75)
        if(day_details.next())
        {
            CPrinter print;
            print.setFontType(CPrinter::eFontType_font2);

            print.addData("Day Close Report",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);

            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            print.addData("Day No    :"+day_details.value(0).toString(),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            report_day_no = day_details.value(0).toString().trimmed();
            print.addData("Open Date :"+day_details.value(2).toString(),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            print.addData("Open Time :"+day_details.value(3).toString(),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            print.addData("Close Date:"+day_details.value(4).toString(),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            print.addData("Close Time:"+day_details.value(5).toString(),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

            day_details.clear();
            QStringList lst_aval_batch_type;
            QString total_husk;
            QString rate_of_husk;

            if(databaseObj->selectQuery("select transaction_master.batch_type from transaction_master where transaction_master.is_void is null and transaction_master.day_no=(SELECT day_no FROM day_master WHERE id_day=(SELECT MAX(id_day) FROM day_master where status='0')) and transaction_master.is_payment=0 group by transaction_master.batch_type",day_details))
            {
                if(day_details.next())
                {
                    lst_aval_batch_type << day_details.value(0).toString().trimmed();
                    while(day_details.next())
                    {
                        lst_aval_batch_type << day_details.value(0).toString().trimmed();
                    }
                    qDebug()<<"avaliable batched ===>>>"<<lst_aval_batch_type;
                }
            }
            float t_husk = 0;
            if(lst_aval_batch_type.size() > 0)
            {
                print.addData("Purchase Report Details",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);

                print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                print.addData("TYPE  LOADS  T.CFT  T.HUSK    RUN KMS ",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);


                int t_loads=0;
                float t_cft =0;
                int t_kms = 0;

                for(int i=0;i<lst_aval_batch_type.size();i++)
                {
                    day_details.clear();

                    if(lst_aval_batch_type.at(i).toInt() == 0)
                        rate_of_husk = "rate_of_husk";

                    if(lst_aval_batch_type.at(i).toInt() == 1)
                        rate_of_husk = "auto_rate_of_husk";

                    if(lst_aval_batch_type.at(i).toInt() == 2)
                        rate_of_husk = "van_rate_of_husk";

                    qDebug()<<"lst_aval_batch_type ===>>>"<<lst_aval_batch_type.at(i);

                    if(databaseObj->selectQuery("select batch_type,count(transaction_master.batch_type) as no_of_loads,sum(transaction_master.inward_bale) as total_cft,sum(transaction_master.inward_hush) as total_husk,sum(transaction_master.excess_amt) as excess,sum(transaction_master.approved_amt) as approved_amt,round(sum(transaction_master.inward_hush)/sum(transaction_master.approved_amt),2) as rate_per_husk,sum(transaction_master.vkms) as vkms from transaction_master where transaction_master.is_void is null and transaction_master.batch_type='"+lst_aval_batch_type.at(i)+"'  and day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0'))",day_details))
                    {
                        if(day_details.next())
                        {
                            QString batch_name,to_print;
                            if(lst_aval_batch_type.at(i).toInt() == 0)
                                batch_name = "Comp";
                            if(lst_aval_batch_type.at(i).toInt() == 1)
                                batch_name = "Auto";
                            if(lst_aval_batch_type.at(i).toInt() == 2)
                                batch_name = "Van";

                            to_print = batch_name.leftJustified(4,' ',1)+"  "+day_details.value(1).toString().trimmed().rightJustified(6,' ')+"  "+day_details.value(2).toString().trimmed().rightJustified(6,' ',1)+"  "+day_details.value(3).toString().trimmed().rightJustified(7,' ',1)+"  "+day_details.value(7).toString().trimmed().rightJustified(7,' ',1);

                            t_loads += day_details.value(1).toInt();
                            t_cft += day_details.value(2).toFloat();
                            t_husk += day_details.value(3).toInt();
                            t_kms += day_details.value(7).toInt();
                            qDebug()<<"to_print ===>>>"<<to_print;

                            print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                        }
                    }
                }
                QString total_print;
                total_print = "Total "+QString::number(t_loads).rightJustified(6,' ')+"  "+QString::number(t_cft,'f',2).rightJustified(6,' ',1)+"  "+QString::number(t_husk).rightJustified(7,' ',1)+"  "+QString::number(t_kms).rightJustified(7,' ',1);
                print.addData(total_print,CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
                print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            }


            //! PURCHASE VALUE DETAILS

            print.addData("Purchase Value Details",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);

            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            print.addData("TYPE QUANTITY HUSKRATE  AMOUNT  EXCESS",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

            float pv_rate_of_husk = 0;
            float pv_amt = 0;
            int pv_excess =0;
            int count = 0;


            for(int i=0;i<lst_aval_batch_type.size();i++)
            {
                day_details.clear();

                if(lst_aval_batch_type.at(i).toInt() == 0)
                    rate_of_husk = "rate_of_husk";

                if(lst_aval_batch_type.at(i).toInt() == 1)
                    rate_of_husk = "auto_rate_of_husk";

                if(lst_aval_batch_type.at(i).toInt() == 2)
                    rate_of_husk = "van_rate_of_husk";

                if(databaseObj->selectQuery("select batch_type,count(transaction_master.batch_type) as no_of_loads,sum(transaction_master.inward_bale) as total_cft,sum(transaction_master.inward_hush) as total_husk,sum(transaction_master.excess_amt) as excess,sum(transaction_master.approved_amt) as approved_amt,round(sum(transaction_master.approved_amt)/sum(transaction_master.inward_hush),2) as rate_per_husk,sum(transaction_master.vkms) as vkms from transaction_master where transaction_master.is_void is null and transaction_master.batch_type='"+lst_aval_batch_type.at(i)+"' and day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0'))",day_details))
                {
                    if(day_details.next())
                    {
                        QString batch_name,to_print;
                        if(lst_aval_batch_type.at(i).toInt() == 0)
                            batch_name = "Comp";
                        if(lst_aval_batch_type.at(i).toInt() == 1)
                            batch_name = "Auto";
                        if(lst_aval_batch_type.at(i).toInt() == 2)
                            batch_name = "Van";

                        to_print = batch_name.leftJustified(5,' ',1)+" "+day_details.value(3).toString().trimmed().rightJustified(8,' ')+" "+day_details.value(6).toString().trimmed().rightJustified(8,' ',1)+" "+day_details.value(5).toString().trimmed().rightJustified(7,' ',1)+" "+day_details.value(4).toString().trimmed().rightJustified(6,' ',1);
                        count += 1;
                        pv_rate_of_husk += day_details.value(6).toFloat();
                        pv_amt += day_details.value(5).toInt();
                        pv_excess += day_details.value(4).toInt();


                        qDebug()<<"to_print ===>>>"<<to_print;

                        print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                    }
                }
            }
            QString pv_total_print;

            qDebug()<<"pv_total_print ===>>>"<<QString::number(pv_amt/t_husk);
            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            pv_total_print = QString("Avg & Total :").leftJustified(14,' ',1)+" "+QString::number(pv_amt/t_husk,'f',2).rightJustified(8,' ')+" "+QString::number(pv_amt).rightJustified(6,' ',1)+" "+QString::number(pv_excess).rightJustified(6,' ',1);
            print.addData(pv_total_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);


            //! PRODUCTION DETAILS

            QSqlQuery production_details_qur;
            if(databaseObj->selectQuery("select * from day_close where day_close.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0'))",production_details_qur))
            {
                if(production_details_qur.next())
                {

                    print.addData("Production Details",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
                    print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                    print.addData("Opening Bale      : "+Day_CloseObj->opening_bale+" Nos",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                    print.addData("Bale Produced     : "+Day_CloseObj->bale_produced+" Nos",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                    print.addData(production_details_qur.value(1).toString().toUpper().leftJustified(7,' ',1)+" "+QString::number(production_details_qur.value(2).toInt()).rightJustified(4,'0',1)+" :"+production_details_qur.value(3).toString()+" Nos",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                    while(production_details_qur.next())
                    {
                        print.addData(production_details_qur.value(1).toString().toUpper().leftJustified(7,' ',1)+" "+QString::number(production_details_qur.value(2).toInt()).rightJustified(4,'0',1)+" :"+production_details_qur.value(3).toString()+" Nos",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                    }
                    print.addData("Bale Dispatched   : "+Day_CloseObj->bale_dispatched+" Nos",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                    print.addData("Bale Dispatched To: "+Day_CloseObj->dispatched_to.toUpper(),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                    print.addData("Bale Closing Stock: "+Day_CloseObj->closing_bale.toUpper(),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

                    print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                }
            }




            //! CASH FLOW DETAILS
            print.addData("Cash Flow Details",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);




            int husk_pay = 0;
            for(int i=0;i<lst_aval_batch_type.size();i++)
            {
                day_details.clear();

                if(lst_aval_batch_type.at(i).toInt() == 0)
                    rate_of_husk = "rate_of_husk";

                if(lst_aval_batch_type.at(i).toInt() == 1)
                    rate_of_husk = "auto_rate_of_husk";

                if(lst_aval_batch_type.at(i).toInt() == 2)
                    rate_of_husk = "van_rate_of_husk";

                if(databaseObj->selectQuery("select batch_type,count(transaction_master.batch_type) as no_of_loads,sum(transaction_master.paid) as paid from transaction_master where transaction_master.is_void is null and transaction_master.batch_type='"+lst_aval_batch_type.at(i)+"'",day_details))
                {

                    if(day_details.next())
                    {
                        QString batch_name,to_print;
                        if(lst_aval_batch_type.at(i).toInt() == 0)
                            batch_name = "Comp";
                        if(lst_aval_batch_type.at(i).toInt() == 1)
                            batch_name = "Auto";
                        if(lst_aval_batch_type.at(i).toInt() == 2)
                            batch_name = "Van";

                        husk_pay += day_details.value(2).toInt();
                    }
                }
            }

            QSqlQuery cash_balance;
            if(databaseObj->selectQuery("select day_master.opening_cash,day_master.closing_cash from day_master where id_day=(SELECT MAX(id_day) FROM day_master where status='0')",cash_balance))
            {
                if(cash_balance.next())
                {
                    print.addData("Opening Cash Balance:Rs "+cash_balance.value(0).toString().trimmed().rightJustified(8,' ',1),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_RIGHT);
                }
            }

            QSqlQuery cash_receipt;
            if(databaseObj->selectQuery("select sum(cash_from_transaction.cash_recv) from cash_from_transaction where cash_from_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0'))",cash_receipt))
            {
                if(cash_receipt.next())
                {
                    print.addData("COMPANY CASH RCPT:Rs "+cash_receipt.value(0).toString().trimmed().rightJustified(8,' ',1),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_RIGHT);
                }
            }

            //                cash_balance.clear();
            //                if(databaseObj->selectQuery("select cash_from_transaction.user_name,user_master.name,cash_from_transaction.date_time,cash_from_transaction.cash_recv from cash_from_transaction inner join user_master on user_master.user_name=cash_from_transaction.user_name where cash_from_transaction.cash_from='Company' and day_no=(select day_master.day_no from day_master where day_master.id_day=id_day=(SELECT MAX(id_day) FROM day_master where status='1'))",cash_balance))
            //                {
            //                    int tot_cash_received = 0;
            //                    if(cash_balance.next())
            //                    {
            //                        print.addData("Company Cash Receipt",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_RIGHT);
            //                        print.addData(cash_balance.value(2).toString().right(20,' ',1)+" "+cash_balance.value(1).toString().trimmed().leftJustified(10,' ',1)+" "+cash_balance.value(3).toString().trimmed().rightJustified(7,' ',1),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            //                        tot_cash_received += cash_balance.value(3).toInt();
            //                        while(cash_balance.next())
            //                        {
            //                            print.addData(cash_balance.value(2).toString().right(20,' ',1)+" "+cash_balance.value(1).toString().trimmed().leftJustified(10,' ',1)+" "+cash_balance.value(3).toString().trimmed().rightJustified(7,' ',1),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            //                            tot_cash_received += cash_balance.value(3).toInt();
            //                        }
            //                        print.addData("Total Cash Received: Rs "+QString::number(tot_cash_received),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_RIGHT);
            //                    }
            //                }
            //                if(husk_pay > 0)
            //                {
            //                    print.addData("Husk Payment: Rs"+QString::number(husk_pay),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            //                }

            QSqlQuery payables_qur;
            QString v_pay = "0";
            float total_exp_amt = 0;
            QStringList lst_v_no,lst_party_name,lst_amt;
            payables_qur.clear();
            if(databaseObj->selectQuery("select vehicle_no,cus_name,paid from transaction_master where is_void is null and day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) and paid > 0",payables_qur))
            {
                if(payables_qur.next())
                {
                    lst_v_no << payables_qur.value(0).toString().trimmed();
                    lst_party_name << payables_qur.value(1).toString().trimmed();
                    lst_amt << payables_qur.value(2).toString().trimmed();
                    while(payables_qur.next())
                    {
                        lst_v_no << payables_qur.value(0).toString().trimmed();
                        lst_party_name << payables_qur.value(1).toString().trimmed();
                        lst_amt << payables_qur.value(2).toString().trimmed();
                    }
                }
                if(lst_v_no.size() > 0)
                {
                    print.addData("Husk Payment",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
                    print.addData("Vehicle No    Party Name       Amount",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

                    for(int i=0;i<lst_v_no.size();i++)
                    {
                        print.addData(lst_v_no.at(i).leftJustified(11,' ',1)+" "+lst_party_name.at(i).remove(" ").leftJustified(15,' ',1)+" "+QString::number(lst_amt.at(i).toFloat(),'f',2).rightJustified(10,' ',1),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                    }
                    payables_qur.clear();
                    if(databaseObj->selectQuery("select sum(paid) from transaction_master where is_void is null and day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0'))",payables_qur))
                    {
                        if(payables_qur.next())
                        {
                            v_pay = payables_qur.value(0).toString().trimmed();
                        }
                    }
                }
            }


            QSqlQuery bunk_qur;
            QString bunk_pay = "0";
            QStringList lst_bunk_name,lst_bunk_qty,lst_bunk_amount;
            if(databaseObj->selectQuery("select diesel_transaction.bunk_id,bunk_master.bunk_name,diesel_transaction.quantity,diesel_transaction.amount from diesel_transaction inner join bunk_master on diesel_transaction.bunk_id=bunk_master.id_bunk_master where day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0' and is_payment='1'))",bunk_qur))
            {
                if(bunk_qur.next())
                {
                    lst_bunk_name << bunk_qur.value(1).toString().trimmed();
                    lst_bunk_qty << bunk_qur.value(2).toString().trimmed();
                    lst_bunk_amount << bunk_qur.value(3).toString().trimmed();
                    while(bunk_qur.next())
                    {
                        lst_bunk_name << bunk_qur.value(1).toString().trimmed();
                        lst_bunk_qty << bunk_qur.value(2).toString().trimmed();
                        lst_bunk_amount << bunk_qur.value(3).toString().trimmed();
                    }
                }

                if(lst_bunk_name.size() > 0)
                {
                    print.addData("Bunk Payment",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
                    for(int i=0;i<lst_bunk_name.size();i++)
                    {
                        print.addData("            "+lst_bunk_name.at(i).leftJustified(15,' ')+" "+QString::number(lst_bunk_amount.at(i).rightJustified(10,' ').toFloat(),'f',2),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                    }
                    bunk_qur.clear();
                    if(databaseObj->selectQuery("select sum(diesel_transaction.amount) from diesel_transaction where day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) and is_payment='1'",bunk_qur))
                    {
                        if(bunk_qur.next())
                        {
                            bunk_pay = bunk_qur.value(0).toString().trimmed();
                        }
                    }
                }
            }

            QSqlQuery emp_qur;
            QString emp_pay = "0";
            QStringList lst_emp_name,lst_emp_amount;
            if(databaseObj->selectQuery("select emp_name,paid_salary from employee_transaction where paid_salary IS NOT NULL and day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0'))",emp_qur))
            {
                if(emp_qur.next())
                {
                    lst_emp_name << emp_qur.value(0).toString().trimmed();
                    lst_emp_amount << emp_qur.value(1).toString().trimmed();
                    while(emp_qur.next())
                    {
                        lst_emp_name << emp_qur.value(0).toString().trimmed();
                        lst_emp_amount << emp_qur.value(1).toString().trimmed();
                    }
                }
                if(lst_emp_name.size() > 0)
                {
                    print.addData("Labour Payment",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
                    for(int i=0;i<lst_emp_name.size();i++)
                    {
                        print.addData("            "+lst_emp_name.at(i).leftJustified(15,' ')+" "+QString::number(lst_emp_amount.at(i).rightJustified(10,' ').toFloat(),'f',2),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                    }
                    emp_qur.clear();
                    if(databaseObj->selectQuery("select sum(paid_salary) from employee_transaction where paid_salary IS NOT NULL and day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0'))",emp_qur))
                    {
                        if(emp_qur.next())
                        {
                            emp_pay = emp_qur.value(0).toString().trimmed();
                        }
                    }
                }
            }

            QSqlQuery expense_qur;
            QStringList lst_expense_name,lst_expense_bill_no,lst_expense_amount,lst_expense_user_id;
            if(databaseObj->selectQuery("select * from expense_transaction where day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0'))",expense_qur))
            {
                if(expense_qur.next())
                {
                    lst_expense_name << expense_qur.value(2).toString().trimmed();
                    lst_expense_bill_no << expense_qur.value(3).toString().trimmed();
                    lst_expense_amount << expense_qur.value(4).toString().trimmed();
                    lst_expense_user_id << expense_qur.value(6).toString().trimmed();
                    while(expense_qur.next())
                    {
                        lst_expense_name << expense_qur.value(2).toString().trimmed();
                        lst_expense_bill_no << expense_qur.value(3).toString().trimmed();
                        lst_expense_amount << expense_qur.value(4).toString().trimmed();
                        lst_expense_user_id << expense_qur.value(6).toString().trimmed();
                    }
                }
            }

            if(lst_expense_name.size() > 0)
            {
                print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                print.addData("Expense",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
                print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                print.addData("   Expense Name          Amount",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);


                for(int i=0;i<lst_expense_name.size();i++)
                {
                    QString prt_text = QString::number(i+1).rightJustified(2,' ')+" "+lst_expense_name.at(i).leftJustified(15,' ')+" "+QString::number(lst_expense_amount.at(i).toFloat(),'f',2).rightJustified(15,' ');
                    qDebug()<<"expense data ===>>>"<<prt_text;
                    print.addData(prt_text,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                    total_exp_amt += lst_expense_amount.at(i).toFloat();
                }
                //                    print.addData("Total Expense: "+QString::number(total_exp_amt,'f',2),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
            }
            if( (lst_v_no.size() != 0) || (lst_bunk_name.size() != 0) || (lst_emp_name.size() != 0) || total_exp_amt > 0)
            {
                print.addData("Total :Rs "+QString::number(v_pay.toFloat() + emp_pay.toFloat() + bunk_pay.toFloat() + total_exp_amt,'f',2 ),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
            }


            QSqlQuery closing_cash_balance;
            if(databaseObj->selectQuery("select day_master.opening_cash,day_master.closing_cash from day_master where id_day=(SELECT MAX(id_day) FROM day_master where status='0')",closing_cash_balance))
            {
                if(closing_cash_balance.next())
                {
                    print.addData("Closing Cash Balance:Rs "+closing_cash_balance.value(1).toString().trimmed().rightJustified(8,' ',1),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_RIGHT);
                }
            }
            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);


            print.addData("Stock Status Report",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

            //! today

            QSqlQuery stock_qur;
            QStringList lst_stock_batch;
            lst_stock_batch << "company_batch_no" << "other_batch_no" << "van_batch_no";
            print.addData(" TYPE   BATCHNO  CFT  NO.OF.HUSK",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            int husk_only = 0;
            float cft_only = 0;

            int husk_pro = 0;
            float cft_pro = 0;

            for(int i=0;i<lst_stock_batch.size();i++)
            {
                QStringList lst_stock_batch_no,lst_stock_batch_cft,lst_stock_batch_husk;
                QString stock_purchase,stock_production;
                QString pro_batch_name;
                if(databaseObj->selectQuery("select batch_no,total_husk_produced,inward_stock from "+lst_stock_batch.at(i)+" where production_status='2'",stock_qur))
                {

                    if(stock_qur.next())
                    {
                        lst_stock_batch_no << stock_qur.value(0).toString().trimmed();
                        lst_stock_batch_husk << stock_qur.value(1).toString().trimmed();
                        lst_stock_batch_cft << stock_qur.value(2).toString().trimmed();
                        while(stock_qur.next())
                        {
                            lst_stock_batch_no << stock_qur.value(0).toString().trimmed();
                            lst_stock_batch_husk << stock_qur.value(1).toString().trimmed();
                            lst_stock_batch_cft << stock_qur.value(2).toString().trimmed();
                        }

                        if(lst_stock_batch.at(i).contains("company_batch_no"))
                            pro_batch_name = "Comp";
                        if(lst_stock_batch.at(i).contains("other_batch_no"))
                            pro_batch_name = "Auto";
                        if(lst_stock_batch.at(i).contains("van_batch_no"))
                            pro_batch_name = "Van ";

                        for(int p=0;p<lst_stock_batch_no.size();p++)
                            print.addData(pro_batch_name.leftJustified(9,' ',1)+" "+lst_stock_batch_no.at(p).rightJustified(4,'0').rightJustified(7,' ',1)+" "+lst_stock_batch_cft.at(p).rightJustified(7,' ',1)+" "+lst_stock_batch_husk.at(p).rightJustified(10,' ',1),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);




                    }

                }

                stock_qur.clear();
                lst_stock_batch_no.clear();
                lst_stock_batch_husk.clear();
                lst_stock_batch_cft.clear();

                if(databaseObj->selectQuery("select batch_no,total_husk_produced,inward_stock from "+lst_stock_batch.at(i)+" where production_status is null",stock_qur))
                {
                    if(stock_qur.next())
                    {
                        lst_stock_batch_no << stock_qur.value(0).toString().trimmed();
                        lst_stock_batch_husk << stock_qur.value(1).toString().trimmed();
                        lst_stock_batch_cft << stock_qur.value(2).toString().trimmed();
                        while(stock_qur.next())
                        {
                            lst_stock_batch_no << stock_qur.value(0).toString().trimmed();
                            lst_stock_batch_husk << stock_qur.value(1).toString().trimmed();
                            lst_stock_batch_cft << stock_qur.value(2).toString().trimmed();
                        }

                        if(lst_stock_batch.at(i).contains("company_batch_no"))
                            pro_batch_name = "Comp";
                        if(lst_stock_batch.at(i).contains("other_batch_no"))
                            pro_batch_name = "Auto";
                        if(lst_stock_batch.at(i).contains("van_batch_no"))
                            pro_batch_name = "Van ";

                        for(int p=0;p<lst_stock_batch_no.size();p++)
                            print.addData(pro_batch_name.leftJustified(9,' ',1)+" "+lst_stock_batch_no.at(p).rightJustified(4,'0').rightJustified(7,' ',1)+" "+lst_stock_batch_cft.at(p).rightJustified(7,' ',1)+" "+lst_stock_batch_husk.at(p).rightJustified(10,' ',1),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

                    }



                }


                QString pro_batch_name1;
                if(lst_stock_batch.at(i).contains("company_batch_no"))
                    pro_batch_name1 = "company";
                if(lst_stock_batch.at(i).contains("other_batch_no"))
                    pro_batch_name1 = "auto";
                if(lst_stock_batch.at(i).contains("van_batch_no"))
                    pro_batch_name1 = "van";
                stock_qur.clear();
                if(databaseObj->selectQuery("select batch_no,husk_available,batch_type from production_batch_order where batch_type='"+pro_batch_name1+"'",stock_qur))
                {
                    if(stock_qur.next())
                    {

                        QString pro_batch_name2;
                        if(stock_qur.value(2).toString().contains("company"))
                            pro_batch_name2 = "Company";
                        if(stock_qur.value(2).toString().contains("auto"))
                            pro_batch_name2 = "Auto";
                        if(stock_qur.value(2).toString().contains("van"))
                            pro_batch_name2 = "Van";

                        int tmp_husk = stock_qur.value(1).toInt();
                        husk_pro += tmp_husk;
                        cft_pro += (tmp_husk/Home_ScreenObj->HP_cft.toFloat());
                        print.addData(pro_batch_name2.leftJustified(9,' ',1)+" "+stock_qur.value(0).toString().trimmed().rightJustified(4,'0').rightJustified(7,' ',1)+" "+QString::number(stock_qur.value(1).toInt()/Home_ScreenObj->HP_cft.toInt()).rightJustified(7,' ',1)+" "+stock_qur.value(1).toString().rightJustified(10,' ',1),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                        while(stock_qur.next())
                        {

                            QString pro_batch_name2;
                            if(stock_qur.value(2).toString().contains("company"))
                                pro_batch_name2 = "Company";
                            if(stock_qur.value(2).toString().contains("auto"))
                                pro_batch_name2 = "Auto";
                            if(stock_qur.value(2).toString().contains("van"))
                                pro_batch_name2 = "Van";

                            int tmp_husk = stock_qur.value(1).toInt();
                            husk_pro += tmp_husk;
                            cft_pro += (tmp_husk/Home_ScreenObj->HP_cft.toFloat());
                            print.addData(pro_batch_name2.leftJustified(9,' ',1)+" "+stock_qur.value(0).toString().trimmed().rightJustified(4,'0').rightJustified(7,' ',1)+" "+QString::number(stock_qur.value(1).toInt()/Home_ScreenObj->HP_cft.toInt()).rightJustified(7,' ',1)+" "+stock_qur.value(1).toString().rightJustified(10,' ',1),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                        }
                        qDebug()<<"cft_pro ===>>>"<<QString::number(cft_pro);
                    }
                }

                stock_qur.clear();

                if(databaseObj->selectQuery("select sum(total_husk_produced),sum(inward_stock) from "+lst_stock_batch.at(i)+" where production_status='2'",stock_qur))
                {
                    if(stock_qur.next())
                    {
                        husk_only += stock_qur.value(0).toString().trimmed().toInt();
                        cft_only += stock_qur.value(1).toString().trimmed().toFloat();
                        qDebug()<<"cft_only ===>>>"<<QString::number(cft_only);
                    }
                }

                if(databaseObj->selectQuery("select sum(total_husk_produced),sum(inward_stock) from "+lst_stock_batch.at(i)+" where production_status is null",stock_qur))
                {
                    if(stock_qur.next())
                    {
                        husk_only += stock_qur.value(0).toString().trimmed().toInt();
                        cft_only += stock_qur.value(1).toString().trimmed().toFloat();
                        qDebug()<<"cft_only ===>>>"<<QString::number(cft_only);
                    }
                }
            }

            QString tot_cft_husk = QString("Total").leftJustified(13,' ',1)+" "+QString::number(cft_only+cft_pro).trimmed().rightJustified(8,' ',1)+" "+QString::number(husk_only+husk_pro).trimmed().rightJustified(9,' ',1);
            qDebug()<<"tot_cft_husk ===>>>"<<tot_cft_husk;
            print.addData(tot_cft_husk,CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

            stock_qur.clear();
            QString closing_bale,closing_husk;
            int closing_husk1 = 0;
            if(databaseObj->selectQuery("select closing_bale_balance from day_master where day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0'))",stock_qur))
            {
                if(stock_qur.next())
                {
                    closing_bale = stock_qur.value(0).toString().trimmed();
                    closing_husk = QString::number(closing_bale.toFloat()*Home_ScreenObj->HP_bale.toFloat(),'f',2);
                    closing_husk1 = (closing_bale.toFloat()*Home_ScreenObj->HP_bale.toInt());
                    qDebug()<<"closing_husk1 ===>>>"<<QString::number(closing_husk1);
                }
            }
            //                float total_husk_count = husk_available_production.toFloat()+closing_husk.toFloat();
            print.addData(QString("Bale").leftJustified(13,' ',1)+" "+closing_bale.trimmed().append(" Nos").rightJustified(8,' ',1)+" "+closing_husk.trimmed().rightJustified(9,' ',1),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            print.addData("Total Husk In Stock "+QString::number(husk_only+husk_pro+closing_husk1).trimmed().rightJustified(9,' ',1),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

            QSqlQuery diesel_report_qur;
            print.addData("Diesel Consumption",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

            if(databaseObj->selectQuery("select open_diesel_reading,close_diesel_reading from day_master where day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0'))",diesel_report_qur ))
            {
                if(diesel_report_qur.next())
                {
                    print.addData("OPENING STOCK  : "+diesel_report_qur.value(0).toString().trimmed()+" Lts",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                }
            }

            diesel_report_qur.clear();
            if(databaseObj->selectQuery("select sum(diesel_transaction.quantity) from diesel_transaction where day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0'))",diesel_report_qur ))
            {
                if(diesel_report_qur.next())
                {
                    print.addData("TODAY PURCHASE : "+diesel_report_qur.value(0).toString().trimmed()+" Lts",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                }
            }

            diesel_report_qur.clear();
            if(databaseObj->selectQuery("select sum(diesel_usage.quantity) from diesel_usage where day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0'))",diesel_report_qur ))
            {
                if(diesel_report_qur.next())
                {
                    print.addData("CONSUMPTION    : "+diesel_report_qur.value(0).toString().trimmed()+" Lts",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                }
            }

            diesel_report_qur.clear();
            if(databaseObj->selectQuery("select diesel_usage.vehicle_no,sum(diesel_usage.quantity),diesel_usage.fill_type from diesel_usage where diesel_usage.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) group by diesel_usage.vehicle_no",diesel_report_qur))
            {
                if(diesel_report_qur.next())
                {
                    //! new
                    QString vehicle_no;
                    QString vehicle_consumption;
                    vehicle_no = diesel_report_qur.value(0).toString().trimmed();
                    vehicle_consumption = diesel_report_qur.value(1).toString().trimmed();

                    QString diesel_to_print;
                    QString millage;
                    QString unit;
                    if(vehicle_no.contains("bull",Qt::CaseInsensitive) || vehicle_no.contains("generator",Qt::CaseInsensitive))
                    {
                        unit = "Lts/Hr";
                        if(get_difference(vehicle_no).toFloat() > 0)
                        {
                            millage = QString::number(get_voulume(vehicle_no,report_day_no).toFloat()/get_difference(vehicle_no).toFloat());
                        }
                    }
                    else
                    {
                        unit = "km/lt";
                        if(get_difference(vehicle_no).toFloat() > 0)
                        {
                            millage = QString::number(get_difference(vehicle_no).toFloat()/get_voulume(vehicle_no,report_day_no).toFloat());
                        }
                    }

                    if(!millage.isEmpty())
                        print.addData(vehicle_no.toUpper().leftJustified(12,' ',1)+":"+vehicle_consumption.append("lts")+" Milage:"+millage+" "+unit,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                    else
                        print.addData(vehicle_no.toUpper().leftJustified(12,' ',1)+":"+vehicle_consumption.append("lts"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

                    while(diesel_report_qur.next())
                    {
                        //! new
                        QString vehicle_no;
                        QString vehicle_consumption;
                        vehicle_no = diesel_report_qur.value(0).toString().trimmed();
                        vehicle_consumption = diesel_report_qur.value(1).toString().trimmed();

                        QString diesel_to_print;
                        QString millage;
                        QString unit;
                        if(vehicle_no.contains("bull",Qt::CaseInsensitive) || vehicle_no.contains("generator",Qt::CaseInsensitive))
                        {
                            unit = "Lts/Hr";
                            if(get_difference(vehicle_no).toFloat() > 0)
                            {
                                millage = QString::number(get_voulume(vehicle_no,report_day_no).toFloat()/get_difference(vehicle_no).toFloat());
                            }
                        }
                        else
                        {
                            unit = "km/lt";
                            if(get_difference(vehicle_no).toFloat() > 0)
                            {
                                millage = QString::number(get_difference(vehicle_no).toFloat()/get_voulume(vehicle_no,report_day_no).toFloat());
                            }
                        }

                        if(!millage.isEmpty())
                            print.addData(vehicle_no.toUpper().leftJustified(12,' ',1)+":"+vehicle_consumption.append("lts")+" Milage:"+millage+" "+unit,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                        else
                            print.addData(vehicle_no.toUpper().leftJustified(12,' ',1)+":"+vehicle_consumption.append("lts"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

                    }
                }
            }

            //            QString diff = get_difference("bull");
            //            qDebug()<<"diff ===>>>"<<diff;
            //            float g=diff.toFloat();
            //            if(g > 0)
            //            {
            //                print.addData(QString("bull").toUpper().leftJustified(12,' ')+": "+diff ,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            //            }
            //            QString diff1 = get_difference("generator");
            //            qDebug()<<"diff ===>>>"<<diff1;
            //            float g1=diff1.toFloat();
            //            qDebug()<<"diff g1 ===>>>"<<QString::number(g1);
            //            if(g1 > 0)
            //            {
            //                print.addData(QString("generator").toUpper().leftJustified(12,' ')+": "+diff1 ,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            //            }


            //            QSqlQuery v_query;
            //            QStringList lst_vehicle_no;
            //            if(databaseObj->selectQuery("select vehicle_no from vehicle_registration where vehicle_owner='0'",v_query))
            //            {
            //                lst_vehicle_no.clear();
            //                if(v_query.next())
            //                {
            //                    lst_vehicle_no << v_query.value(0).toString().trimmed();
            //                    while(v_query.next())
            //                    {
            //                        lst_vehicle_no << v_query.value(0).toString().trimmed();
            //                    }
            //                }
            //                qDebug()<<"lst_vehicle_no ===>>>"<<lst_vehicle_no;
            //                if(lst_vehicle_no.size() > 0)
            //                {
            //                    for(int i=0;i<lst_vehicle_no.size();i++)
            //                    {
            //                        QString diff2 = get_difference(lst_vehicle_no.at(i));
            //                        qDebug()<<"diff2 ===>>>"<<diff2;
            //                        if(diff2.toInt() > 0)
            //                        {
            //                            print.addData(QString(lst_vehicle_no.at(i)).toUpper().leftJustified(12,' ')+": "+diff ,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            //                        }

            //                    }
            //                }
            //            }

            diesel_report_qur.clear();

            if(databaseObj->selectQuery("select open_diesel_reading,close_diesel_reading from day_master where day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0'))",diesel_report_qur ))
            {
                if(diesel_report_qur.next())
                {
                    print.addData("CLOSING STOCK  : "+diesel_report_qur.value(1).toString().trimmed()+" Lts",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                }
            }
            //! METER READING

            QSqlQuery reading_qur;
            if(databaseObj->selectQuery("select sum(day_master.close_bull_reading)-sum(day_master.open_bull_reading) as bull, sum(day_master.close_gen_reading)-sum(day_master.open_gen_reading) as gen, sum(day_master.close_eb_reading)-sum(day_master.open_eb_reading) as eb from day_master where day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0'))",reading_qur))
            {
                if(reading_qur.next())
                {
                    print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                    print.addData("Meter Reading",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
                    print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

                    print.addData("Bull Meter     :"+reading_qur.value(0).toString().trimmed()+" Hrs",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                    print.addData("Generator Meter:"+reading_qur.value(1).toString().trimmed()+" Hrs",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                    print.addData("EB Meter       :"+reading_qur.value(2).toString().trimmed()+" Units",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                    print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                }
            }



            //! LEDGER WISE REPORT


            float total_op_bal = 0;
            float total_cl_bal = 0;
            float total_paid = 0;
            float total_addition = 0;



            print.addData("Ledger Wise Report",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
            print.addData("  LEDGER   OP.BAL TODAY+  PAID  CL.BAL",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

            //! supplier
            print.addData("Supplier Ledger",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            QSqlQuery supplier_ledger;
            if(databaseObj->selectQuery("select transaction_master.vehicle_no,transaction_master.cus_name,min(transaction_master.previous_balance) as op_bal,min(transaction_master.previous_balance_type) as op_bal_type,sum(transaction_master.inward_hush) as inward_husk,sum(transaction_master.approved_amt) as approved_amt,sum(transaction_master.paid) as paid,customer_master.balance,customer_master.balance_type from transaction_master inner join customer_master on customer_master.cus_name=transaction_master.cus_name where transaction_master.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) group by transaction_master.cus_name",supplier_ledger))
            {
                if(supplier_ledger.next())
                {
                    QString to_print;
                    QString opening_str = "";
                    QString closing_str = "";

                    QSqlQuery supplier_ledger_op_qur;
                    if(databaseObj->selectQuery("select transaction_master.previous_balance,transaction_master.previous_balance_type from transaction_master where transaction_master.is_void is null and transaction_master.cus_name='"+supplier_ledger.value(1).toString()+"' and transaction_master.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) and rowid=(select min(rowid) from transaction_master where transaction_master.is_void is null and transaction_master.cus_name='"+supplier_ledger.value(1).toString().trimmed()+"' and transaction_master.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')))",supplier_ledger_op_qur))
                    {
                        if(supplier_ledger_op_qur.next())
                        {
                            if(supplier_ledger_op_qur.value(1).toInt() == 0 || supplier_ledger_op_qur.value(1).toInt() == 2){
                                opening_str = "+";
                                total_op_bal += supplier_ledger_op_qur.value(0).toFloat();
                            }
                            if(supplier_ledger_op_qur.value(1).toInt() == 1){
                                opening_str = "-";
                                total_op_bal -= supplier_ledger_op_qur.value(0).toFloat();
                            }

                        }
                    }



                    QSqlQuery closing_supplier_balance;
                    QString particular_supplier_bal;
                    if(databaseObj->selectQuery("select transaction_master.balance,transaction_master.balance_type from transaction_master where rowid=(select max(rowid) from transaction_master where transaction_master.is_void is null and transaction_master.vehicle_no='"+supplier_ledger.value(0).toString().trimmed()+"' and transaction_master.cus_name='"+supplier_ledger.value(1).toString().trimmed()+"')",closing_supplier_balance))
                    {
                        if(closing_supplier_balance.next())
                        {
                            particular_supplier_bal = closing_supplier_balance.value(0).toString().trimmed();
                            if(closing_supplier_balance.value(1).toInt() == 0 || closing_supplier_balance.value(1).toInt() == 2){
                                closing_str = "+";
                                total_cl_bal += closing_supplier_balance.value(0).toFloat();
                            }
                            if(closing_supplier_balance.value(1).toInt() == 1){
                                closing_str = "-";
                                total_cl_bal -= closing_supplier_balance.value(0).toFloat();
                            }
                        }
                    }

                    total_paid += supplier_ledger.value(6).toFloat();
                    total_addition += supplier_ledger.value(5).toFloat();

                    to_print = supplier_ledger.value(1).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger_op_qur.value(0).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+" "+supplier_ledger.value(5).toString().trimmed().rightJustified(6,' ',1)+" "+supplier_ledger.value(6).toString().trimmed().rightJustified(6,' ',1)+particular_supplier_bal.trimmed().prepend(closing_str).rightJustified(7,' ',1);
                    qDebug()<<"supplier_ledger ===>>>"<<to_print;
                    print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);



                    while(supplier_ledger.next())
                    {
                        QString to_print;
                        QString opening_str = "";
                        QString closing_str = "";


                        QSqlQuery supplier_ledger_op_qur;
                        if(databaseObj->selectQuery("select transaction_master.previous_balance,transaction_master.previous_balance_type from transaction_master where transaction_master.is_void is null and transaction_master.cus_name='"+supplier_ledger.value(1).toString()+"' and transaction_master.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) and rowid=(select min(rowid) from transaction_master where transaction_master.is_void is null and transaction_master.cus_name='"+supplier_ledger.value(1).toString().trimmed()+"' and transaction_master.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')))",supplier_ledger_op_qur))
                        {
                            if(supplier_ledger_op_qur.next())
                            {
                                if(supplier_ledger_op_qur.value(1).toInt() == 0 || supplier_ledger_op_qur.value(1).toInt() == 2){
                                    opening_str = "+";
                                    total_op_bal += supplier_ledger_op_qur.value(0).toFloat();
                                }
                                if(supplier_ledger_op_qur.value(1).toInt() == 1){
                                    opening_str = "-";
                                    total_op_bal -= supplier_ledger_op_qur.value(0).toFloat();
                                }

                            }
                        }


                        QSqlQuery closing_supplier_balance;
                        QString particular_supplier_bal;
                        if(databaseObj->selectQuery("select transaction_master.balance,transaction_master.balance_type from transaction_master where rowid=(select max(rowid) from transaction_master where transaction_master.is_void is null and transaction_master.vehicle_no='"+supplier_ledger.value(0).toString().trimmed()+"' and transaction_master.cus_name='"+supplier_ledger.value(1).toString().trimmed()+"')",closing_supplier_balance))
                        {
                            if(closing_supplier_balance.next())
                            {
                                particular_supplier_bal = closing_supplier_balance.value(0).toString().trimmed();
                                if(closing_supplier_balance.value(1).toInt() == 0 || closing_supplier_balance.value(1).toInt() == 2){
                                    closing_str = "+";
                                    total_cl_bal += closing_supplier_balance.value(0).toFloat();
                                }
                                if(closing_supplier_balance.value(1).toInt() == 1){
                                    closing_str = "-";
                                    total_cl_bal -= closing_supplier_balance.value(0).toFloat();
                                }
                            }
                        }

                        total_paid += supplier_ledger.value(6).toFloat();
                        total_addition += supplier_ledger.value(5).toFloat();

                        to_print = supplier_ledger.value(1).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger_op_qur.value(0).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+" "+supplier_ledger.value(5).toString().trimmed().rightJustified(6,' ',1)+" "+supplier_ledger.value(6).toString().trimmed().rightJustified(6,' ',1)+particular_supplier_bal.trimmed().prepend(closing_str).rightJustified(7,' ',1);
                        qDebug()<<"supplier_ledger ===>>>"<<to_print;
                        print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                    }
                }
            }
            supplier_ledger.clear();
            if(databaseObj->selectQuery("select customer_master.cus_name,customer_master.balance as cl_bal,customer_master.balance_type as cl_bal_type from customer_master where customer_master.balance>0 and customer_master.cus_name not in (select transaction_master.cus_name from transaction_master where transaction_master.is_void is null and transaction_master.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) group by transaction_master.cus_name)",supplier_ledger))
            {
                if(supplier_ledger.next())
                {
                    QString to_print;

//                    QString closing_str = "";
//                    if(supplier_ledger.value(2).toInt() == 0 || supplier_ledger.value(8).toInt() == 2){
//                        closing_str = "+";
//                        total_cl_bal += supplier_ledger.value(1).toFloat();
//                    }
//                    if(supplier_ledger.value(2).toInt() == 1){
//                        closing_str = "-";
//                        total_cl_bal -= supplier_ledger.value(1).toFloat();
//                    }

//                    to_print = supplier_ledger.value(1).toString().trimmed().leftJustified(31,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);


                    QString opening_str = "";
                    QString closing_str = "";

                    if(supplier_ledger.value(2).toInt() == 0 || supplier_ledger.value(8).toInt() == 2){
                        closing_str = "+";
                        total_cl_bal += supplier_ledger.value(1).toFloat();

                        opening_str = "+";
                        total_op_bal += supplier_ledger.value(1).toFloat();
                    }
                    if(supplier_ledger.value(2).toInt() == 1){
                        closing_str = "-";
                        total_cl_bal -= supplier_ledger.value(1).toFloat();

                        opening_str = "-";
                        total_op_bal -= supplier_ledger.value(1).toFloat();
                    }

                    to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+"              "+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);


                    qDebug()<<"supplier_ledger ===>>>"<<to_print;
                    print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                    while(supplier_ledger.next())
                    {
                        QString to_print;

//                        QString closing_str = "";
//                        if(supplier_ledger.value(2).toInt() == 0 || supplier_ledger.value(8).toInt() == 2){
//                            closing_str = "+";
//                            total_cl_bal += supplier_ledger.value(1).toFloat();
//                        }
//                        if(supplier_ledger.value(2).toInt() == 1){
//                            closing_str = "-";
//                            total_cl_bal -= supplier_ledger.value(1).toFloat();
//                        }

//                        to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(31,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);

                        QString opening_str = "";
                        QString closing_str = "";

                        if(supplier_ledger.value(2).toInt() == 0 || supplier_ledger.value(8).toInt() == 2){
                            closing_str = "+";
                            total_cl_bal += supplier_ledger.value(1).toFloat();

                            opening_str = "+";
                            total_op_bal += supplier_ledger.value(1).toFloat();
                        }
                        if(supplier_ledger.value(2).toInt() == 1){
                            closing_str = "-";
                            total_cl_bal -= supplier_ledger.value(1).toFloat();

                            opening_str = "-";
                            total_op_bal -= supplier_ledger.value(1).toFloat();
                        }

                        to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+"              "+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);

                        qDebug()<<"supplier_ledger ===>>>"<<to_print;
                        print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                    }
                }
            }

            qDebug()<<"Employee total_op_bal ===>>>"<<total_op_bal;
            qDebug()<<"Employee total_addition ===>>>"<<total_addition;
            qDebug()<<"Employee total_paid ===>>>"<<total_paid;
            qDebug()<<"Employee total_cl_bal ===>>>"<<total_cl_bal;

            //! employee

            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            print.addData("Employee Ledger",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            supplier_ledger.clear();
            if(databaseObj->selectQuery("select employee_transaction.emp_name,sum(employee_transaction.produced_bale) as produced_bale,min(employee_transaction.opening_balance) as op_bal,min(employee_transaction.opening_balance_type) as op_bal_type,sum(employee_transaction.calc_salary) as calc_salary,sum(employee_transaction.paid_salary) as paid,employee_master.emp_balance_bale_rate,employee_master.emp_balance_type from employee_transaction inner join employee_master on employee_master.emp_name=employee_transaction.emp_name where employee_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) group by employee_transaction.emp_name",supplier_ledger))
            {
                if(supplier_ledger.next())
                {
                    QString to_print;
                    QString opening_str = "";
                    QString closing_str = "";

//                    if(supplier_ledger.value(3).toInt() == 0 || supplier_ledger.value(3).toInt() == 2){
//                        opening_str = "+";
//                        total_op_bal += supplier_ledger.value(2).toFloat();
//                    }
//                    if(supplier_ledger.value(3).toInt() == 1){
//                        opening_str = "-";
//                        total_op_bal -= supplier_ledger.value(2).toFloat();
//                    }

                    QSqlQuery supplier_ledger_op_qur;
                    if(databaseObj->selectQuery("select employee_transaction.opening_balance,employee_transaction.opening_balance_type from employee_transaction where employee_transaction.emp_name='"+supplier_ledger.value(0).toString().trimmed()+"' and employee_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) and rowid=(select min(rowid) from employee_transaction where employee_transaction.emp_name='"+supplier_ledger.value(0).toString().trimmed()+"' and employee_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')))",supplier_ledger_op_qur))
                    {
                        if(supplier_ledger_op_qur.next())
                        {
                            if(supplier_ledger_op_qur.value(1).toInt() == 0 || supplier_ledger_op_qur.value(1).toInt() == 2){
                                opening_str = "+";
                                total_op_bal += supplier_ledger_op_qur.value(0).toFloat();
                            }
                            if(supplier_ledger_op_qur.value(1).toInt() == 1){
                                opening_str = "-";
                                total_op_bal -= supplier_ledger_op_qur.value(0).toFloat();
                            }

                        }
                    }

                    QSqlQuery closing_employee_balance;
                    QString particular_employee_bal;
                    if(databaseObj->selectQuery("select employee_transaction.pending_salary,employee_transaction.emp_balance_type from employee_transaction where rowid=(select max(rowid) from employee_transaction where employee_transaction.emp_name='"+supplier_ledger.value(0).toString().trimmed()+"')",closing_employee_balance))
                    {
                        if(closing_employee_balance.next())
                        {
                            particular_employee_bal = closing_employee_balance.value(0).toString().trimmed();
                            if(closing_employee_balance.value(1).toInt() == 0 || closing_employee_balance.value(1).toInt() == 2){
                                closing_str = "+";
                                total_cl_bal += closing_employee_balance.value(0).toFloat();
                            }
                            if(closing_employee_balance.value(1).toInt() == 1){
                                closing_str = "-";
                                total_cl_bal -= closing_employee_balance.value(0).toFloat();
                            }
                        }
                    }

                    total_paid += supplier_ledger.value(5).toFloat();
                    total_addition += supplier_ledger.value(4).toFloat();

                    to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger_op_qur.value(0).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+" "+supplier_ledger.value(4).toString().trimmed().rightJustified(6,' ',1)+" "+supplier_ledger.value(5).toString().trimmed().rightJustified(6,' ',1)+particular_employee_bal.trimmed().prepend(closing_str).rightJustified(7,' ',1);
                    qDebug()<<"supplier_ledger ===>>>"<<to_print;
                    print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);


                    while(supplier_ledger.next())
                    {
                        QString to_print;
                        QString opening_str = "";
                        QString closing_str = "";

//                        if(supplier_ledger.value(3).toInt() == 0 || supplier_ledger.value(3).toInt() == 2){
//                            opening_str = "+";
//                            total_op_bal += supplier_ledger.value(2).toFloat();
//                        }
//                        if(supplier_ledger.value(3).toInt() == 1){
//                            opening_str = "-";
//                            total_op_bal -= supplier_ledger.value(2).toFloat();
//                        }

                        QSqlQuery supplier_ledger_op_qur;
                        if(databaseObj->selectQuery("select employee_transaction.opening_balance,employee_transaction.opening_balance_type from employee_transaction where employee_transaction.emp_name='"+supplier_ledger.value(0).toString().trimmed()+"' and employee_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) and rowid=(select min(rowid) from employee_transaction where employee_transaction.emp_name='"+supplier_ledger.value(0).toString().trimmed()+"' and employee_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')))",supplier_ledger_op_qur))
                        {
                            if(supplier_ledger_op_qur.next())
                            {
                                if(supplier_ledger_op_qur.value(1).toInt() == 0 || supplier_ledger_op_qur.value(1).toInt() == 2){
                                    opening_str = "+";
                                    total_op_bal += supplier_ledger_op_qur.value(0).toFloat();
                                }
                                if(supplier_ledger_op_qur.value(1).toInt() == 1){
                                    opening_str = "-";
                                    total_op_bal -= supplier_ledger_op_qur.value(0).toFloat();
                                }

                            }
                        }


                        QSqlQuery closing_employee_balance;
                        QString particular_employee_bal;
                        if(databaseObj->selectQuery("select employee_transaction.pending_salary,employee_transaction.emp_balance_type from employee_transaction where rowid=(select max(rowid) from employee_transaction where employee_transaction.emp_name='"+supplier_ledger.value(0).toString().trimmed()+"')",closing_employee_balance))
                        {
                            if(closing_employee_balance.next())
                            {
                                particular_employee_bal = closing_employee_balance.value(0).toString().trimmed();
                                if(closing_employee_balance.value(1).toInt() == 0 || closing_employee_balance.value(1).toInt() == 2){
                                    closing_str = "+";
                                    total_cl_bal += closing_employee_balance.value(0).toFloat();
                                }
                                if(closing_employee_balance.value(1).toInt() == 1){
                                    closing_str = "-";
                                    total_cl_bal -= closing_employee_balance.value(0).toFloat();
                                }
                            }
                        }

                        total_paid += supplier_ledger.value(5).toFloat();
                        total_addition += supplier_ledger.value(4).toFloat();

                        to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger_op_qur.value(0).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+" "+supplier_ledger.value(4).toString().trimmed().rightJustified(6,' ',1)+" "+supplier_ledger.value(5).toString().trimmed().rightJustified(6,' ',1)+particular_employee_bal.trimmed().prepend(closing_str).rightJustified(7,' ',1);

                        qDebug()<<"supplier_ledger ===>>>"<<to_print;
                        print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                    }
                }
            }

            supplier_ledger.clear();
            if(databaseObj->selectQuery("select employee_master.emp_name,employee_master.emp_balance_bale_rate,employee_master.emp_balance_type from employee_master where  is_active='1' and employee_master.emp_name not in (select employee_transaction.emp_name from employee_transaction where employee_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) group by employee_transaction.emp_name)",supplier_ledger))
            {
                if(supplier_ledger.next())
                {
                    QString to_print;

                    QString opening_str = "";
                    QString closing_str = "";

                    if(supplier_ledger.value(2).toInt() == 0 || supplier_ledger.value(8).toInt() == 2){
                        closing_str = "+";
                        total_cl_bal += supplier_ledger.value(1).toFloat();

                        opening_str = "+";
                        total_op_bal += supplier_ledger.value(1).toFloat();
                    }
                    if(supplier_ledger.value(2).toInt() == 1){
                        closing_str = "-";
                        total_cl_bal -= supplier_ledger.value(1).toFloat();

                        opening_str = "-";
                        total_op_bal -= supplier_ledger.value(1).toFloat();
                    }

                    to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+"              "+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);

                    qDebug()<<"supplier_ledger ===>>>"<<to_print;
                    print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                    while(supplier_ledger.next())
                    {
                        QString to_print;

//                        QString closing_str = "";
//                        if(supplier_ledger.value(2).toInt() == 0 || supplier_ledger.value(8).toInt() == 2){
//                            closing_str = "+";
//                            total_cl_bal += supplier_ledger.value(1).toFloat();
//                        }
//                        if(supplier_ledger.value(2).toInt() == 1){
//                            closing_str = "-";
//                            total_cl_bal -= supplier_ledger.value(1).toFloat();
//                        }
//                        to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(31,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);

                        QString opening_str = "";
                        QString closing_str = "";

                        if(supplier_ledger.value(2).toInt() == 0 || supplier_ledger.value(8).toInt() == 2){
                            closing_str = "+";
                            total_cl_bal += supplier_ledger.value(1).toFloat();

                            opening_str = "+";
                            total_op_bal += supplier_ledger.value(1).toFloat();
                        }
                        if(supplier_ledger.value(2).toInt() == 1){
                            closing_str = "-";
                            total_cl_bal -= supplier_ledger.value(1).toFloat();

                            opening_str = "-";
                            total_op_bal -= supplier_ledger.value(1).toFloat();
                        }

                        to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+"              "+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);

                        qDebug()<<"supplier_ledger ===>>>"<<to_print;
                        print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                    }
                }
            }

            qDebug()<<"Employee total_op_bal ===>>>"<<total_op_bal;
            qDebug()<<"Employee total_addition ===>>>"<<total_addition;
            qDebug()<<"Employee total_paid ===>>>"<<total_paid;
            qDebug()<<"Employee total_cl_bal ===>>>"<<total_cl_bal;









            //! employee driver staff

            //                print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            //                print.addData("Employee Ledger",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            //                supplier_ledger.clear();
            //                if(databaseObj->selectQuery("select employee_transaction.emp_name,sum(employee_transaction.produced_bale) as produced_bale,min(employee_transaction.opening_balance) as op_bal,min(employee_transaction.opening_balance_type) as op_bal_type,sum(employee_transaction.calc_salary) as calc_salary,sum(employee_transaction.paid_salary) as paid,employee_master.emp_balance,employee_master.emp_balance_type from employee_transaction inner join employee_master on employee_master.emp_name=employee_transaction.emp_name where employee_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) group by employee_transaction.emp_name",supplier_ledger))
            //                {
            //                    if(supplier_ledger.next())
            //                    {
            //                        QString to_print;
            //                        QString opening_str = "";
            //                        QString closing_str = "";

            //                        if(supplier_ledger.value(3).toInt() == 0 || supplier_ledger.value(3).toInt() == 2){
            //                            opening_str = "+";
            //                            total_op_bal += supplier_ledger.value(2).toFloat();
            //                        }
            //                        if(supplier_ledger.value(3).toInt() == 1){
            //                            opening_str = "-";
            //                            total_op_bal -= supplier_ledger.value(2).toFloat();
            //                        }

            //                        QSqlQuery closing_employee_balance;
            //                        QString particular_employee_bal;
            //                        if(databaseObj->selectQuery("select employee_transaction.pending_salary,employee_transaction.emp_balance_type from employee_transaction where rowid=(select max(rowid) from employee_transaction where employee_transaction.emp_name='"+supplier_ledger.value(0).toString().trimmed()+"')",closing_employee_balance))
            //                        {
            //                            if(closing_employee_balance.next())
            //                            {
            //                                particular_employee_bal = closing_employee_balance.value(0).toString().trimmed();
            //                                if(closing_employee_balance.value(1).toInt() == 0 || closing_employee_balance.value(1).toInt() == 2){
            //                                    closing_str = "+";
            //                                    total_cl_bal += closing_employee_balance.value(0).toFloat();
            //                                }
            //                                if(closing_employee_balance.value(1).toInt() == 1){
            //                                    closing_str = "-";
            //                                    total_cl_bal -= closing_employee_balance.value(0).toFloat();
            //                                }
            //                            }
            //                        }

            //                        total_paid += supplier_ledger.value(5).toFloat();
            //                        total_addition += supplier_ledger.value(4).toFloat();

            //                        to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(2).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+" "+supplier_ledger.value(4).toString().trimmed().rightJustified(6,' ',1)+" "+supplier_ledger.value(5).toString().trimmed().rightJustified(6,' ',1)+particular_employee_bal.trimmed().prepend(closing_str).rightJustified(7,' ',1);
            //                        qDebug()<<"supplier_ledger ===>>>"<<to_print;
            //                        print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);


            //                        while(supplier_ledger.next())
            //                        {
            //                            QString to_print;
            //                            QString opening_str = "";
            //                            QString closing_str = "";

            //                            if(supplier_ledger.value(3).toInt() == 0 || supplier_ledger.value(3).toInt() == 2){
            //                                opening_str = "+";
            //                                total_op_bal += supplier_ledger.value(2).toFloat();
            //                            }
            //                            if(supplier_ledger.value(3).toInt() == 1){
            //                                opening_str = "-";
            //                                total_op_bal -= supplier_ledger.value(2).toFloat();
            //                            }


            //                            QSqlQuery closing_employee_balance;
            //                            QString particular_employee_bal;
            //                            if(databaseObj->selectQuery("select employee_transaction.pending_salary,employee_transaction.emp_balance_type from employee_transaction where rowid=(select max(rowid) from employee_transaction where employee_transaction.emp_name='"+supplier_ledger.value(0).toString().trimmed()+"')",closing_employee_balance))
            //                            {
            //                                if(closing_employee_balance.next())
            //                                {
            //                                    particular_employee_bal = closing_employee_balance.value(0).toString().trimmed();
            //                                    if(closing_employee_balance.value(1).toInt() == 0 || closing_employee_balance.value(1).toInt() == 2){
            //                                        closing_str = "+";
            //                                        total_cl_bal += closing_employee_balance.value(0).toFloat();
            //                                    }
            //                                    if(closing_employee_balance.value(1).toInt() == 1){
            //                                        closing_str = "-";
            //                                        total_cl_bal -= closing_employee_balance.value(0).toFloat();
            //                                    }
            //                                }
            //                            }

            //                            total_paid += supplier_ledger.value(5).toFloat();
            //                            total_addition += supplier_ledger.value(4).toFloat();

            //                            to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(2).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+" "+supplier_ledger.value(4).toString().trimmed().rightJustified(6,' ',1)+" "+supplier_ledger.value(5).toString().trimmed().rightJustified(6,' ',1)+particular_employee_bal.trimmed().prepend(closing_str).rightJustified(7,' ',1);

            //                            qDebug()<<"supplier_ledger ===>>>"<<to_print;
            //                            print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            //                        }
            //                    }
            //                }

            supplier_ledger.clear();
            if(databaseObj->selectQuery("select employee_master.emp_name,employee_master.emp_balance,employee_master.emp_balance_type from employee_master where  is_active='1' and employee_master.emp_type<>'Labour'",supplier_ledger))
            {
                if(supplier_ledger.next())
                {
                    QString to_print;

//                    QString closing_str = "";
//                    if(supplier_ledger.value(2).toInt() == 0 || supplier_ledger.value(8).toInt() == 2){
//                        closing_str = "+";
//                        total_cl_bal += supplier_ledger.value(1).toFloat();
//                    }
//                    if(supplier_ledger.value(2).toInt() == 1){
//                        closing_str = "-";
//                        total_cl_bal -= supplier_ledger.value(1).toFloat();
//                    }

//                    to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(31,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);


                    QString opening_str = "";
                    QString closing_str = "";

                    if(supplier_ledger.value(2).toInt() == 0 || supplier_ledger.value(8).toInt() == 2){
                        closing_str = "+";
                        total_cl_bal += supplier_ledger.value(1).toFloat();

                        opening_str = "+";
                        total_op_bal += supplier_ledger.value(1).toFloat();
                    }
                    if(supplier_ledger.value(2).toInt() == 1){
                        closing_str = "-";
                        total_cl_bal -= supplier_ledger.value(1).toFloat();

                        opening_str = "-";
                        total_op_bal -= supplier_ledger.value(1).toFloat();
                    }

                    to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+"              "+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);


                    qDebug()<<"supplier_ledger ===>>>"<<to_print;
                    print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                    while(supplier_ledger.next())
                    {
                        QString to_print;

//                        QString closing_str = "";
//                        if(supplier_ledger.value(2).toInt() == 0 || supplier_ledger.value(8).toInt() == 2){
//                            closing_str = "+";
//                            total_cl_bal += supplier_ledger.value(1).toFloat();
//                        }
//                        if(supplier_ledger.value(2).toInt() == 1){
//                            closing_str = "-";
//                            total_cl_bal -= supplier_ledger.value(1).toFloat();
//                        }
//                        to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(31,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);


                        QString opening_str = "";
                        QString closing_str = "";

                        if(supplier_ledger.value(2).toInt() == 0 || supplier_ledger.value(8).toInt() == 2){
                            closing_str = "+";
                            total_cl_bal += supplier_ledger.value(1).toFloat();

                            opening_str = "+";
                            total_op_bal += supplier_ledger.value(1).toFloat();
                        }
                        if(supplier_ledger.value(2).toInt() == 1){
                            closing_str = "-";
                            total_cl_bal -= supplier_ledger.value(1).toFloat();

                            opening_str = "-";
                            total_op_bal -= supplier_ledger.value(1).toFloat();
                        }

                        to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+"              "+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);

                        qDebug()<<"supplier_ledger ===>>>"<<to_print;
                        print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                    }
                }
            }

            qDebug()<<"Employee driver staff total_op_bal ===>>>"<<total_op_bal;
            qDebug()<<"Employee driver staff total_addition ===>>>"<<total_addition;
            qDebug()<<"Employee driver staff total_paid ===>>>"<<total_paid;
            qDebug()<<"Employee driver staff total_cl_bal ===>>>"<<total_cl_bal;























            //! bunk ledger
            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            print.addData("Bunk Ledger",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

            supplier_ledger.clear();
            //            if(databaseObj->selectQuery("select diesel_transaction.bunk_id,bunk_master.bunk_name,min(diesel_transaction.opening_balance) as op_bal,min(diesel_transaction.opening_balance_type) as op_bal_type,sum(diesel_transaction.amount) as paid,max(diesel_transaction.closing_balance) as cl_bal,max(diesel_transaction.closing_balance_type) as cl_bal_type from diesel_transaction inner join bunk_master on bunk_master.id_bunk_master=diesel_transaction.bunk_id where diesel_transaction.is_payment=1 and diesel_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0'))",supplier_ledger))
            if(databaseObj->selectQuery("select diesel_transaction.bunk_id,bunk_master.bunk_name,min(diesel_transaction.opening_balance) as op_bal,min(diesel_transaction.opening_balance_type) as op_bal_type,(select sum(diesel_transaction.amount) from diesel_transaction inner join bunk_master on bunk_master.id_bunk_master=diesel_transaction.bunk_id where diesel_transaction.is_payment=1 and diesel_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0'))) as paid,max(diesel_transaction.closing_balance) as cl_bal,max(diesel_transaction.closing_balance_type) as cl_bal_type from diesel_transaction inner join bunk_master on bunk_master.id_bunk_master=diesel_transaction.bunk_id where diesel_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0'))",supplier_ledger))
            {
                if(supplier_ledger.next())
                {
                    QString to_print;
                    QString opening_str = "";
                    QString closing_str = "";
                    if(supplier_ledger.value(3).toInt() == 0 || supplier_ledger.value(3).toInt() == 2){
                        opening_str = "+";
                        total_op_bal += supplier_ledger.value(2).toFloat();
                    }
                    if(supplier_ledger.value(3).toInt() == 1){
                        opening_str = "-";
                        total_op_bal -= supplier_ledger.value(2).toFloat();
                    }

                    QSqlQuery closing_bunk_balance;

                    //                    QString particular_bunk_bal;
                    //                    particular_bunk_bal = supplier_ledger.value(5).toString().trimmed();
                    //                    if(supplier_ledger.value(6).toInt() == 0 || supplier_ledger.value(6).toInt() == 2){
                    //                        closing_str = "+";
                    //                        total_cl_bal += supplier_ledger.value(5).toFloat();
                    //                    }
                    //                    if(supplier_ledger.value(6).toInt() == 1){
                    //                        closing_str = "-";
                    //                        total_cl_bal -= supplier_ledger.value(5).toFloat();
                    //                    }




                    QString particular_bunk_bal;
                    if(databaseObj->selectQuery("select diesel_transaction.closing_balance,diesel_transaction.closing_balance_type from diesel_transaction where diesel_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) and diesel_transaction.bunk_id='"+supplier_ledger.value(0).toString()+"' and rowid=(select max(rowid) from diesel_transaction where diesel_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) and diesel_transaction.bunk_id='"+supplier_ledger.value(0).toString()+"')",closing_bunk_balance))
                    {
                        if(closing_bunk_balance.next())
                        {
                            particular_bunk_bal = closing_bunk_balance.value(0).toString().trimmed();
                            if(closing_bunk_balance.value(1).toInt() == 0 || closing_bunk_balance.value(1).toInt() == 2){
                                closing_str = "+";
                                total_cl_bal += closing_bunk_balance.value(0).toFloat();
                            }
                            if(closing_bunk_balance.value(1).toInt() == 1){
                                closing_str = "-";
                                total_cl_bal -= closing_bunk_balance.value(0).toFloat();
                            }
                        }
                    }


                    QSqlQuery bunk_today_pur_qur;
                    QString bunk_todays_addition="";
                    if(databaseObj->selectQuery("select diesel_transaction.bunk_id,bunk_master.bunk_name,sum(diesel_transaction.amount) as paid from diesel_transaction inner join bunk_master on bunk_master.id_bunk_master=diesel_transaction.bunk_id where diesel_transaction.is_payment=0 and diesel_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) and diesel_transaction.bunk_id='"+supplier_ledger.value(0).toString()+"'",bunk_today_pur_qur))
                    {
                        if(bunk_today_pur_qur.next())
                        {
                            bunk_todays_addition = bunk_today_pur_qur.value(2).toString();
                        }
                    }


                    total_paid += supplier_ledger.value(4).toFloat();
                    total_addition += bunk_todays_addition.toFloat();
                    to_print = supplier_ledger.value(1).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(2).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+" "+bunk_todays_addition.rightJustified(6,' ',1)+" "+supplier_ledger.value(4).toString().trimmed().rightJustified(6,' ',1)+particular_bunk_bal.trimmed().prepend(closing_str).rightJustified(7,' ',1);
                    qDebug()<<"supplier_ledger ===>>>"<<to_print;
                    print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                    while(supplier_ledger.next())
                    {
                        QString to_print;
                        QString opening_str = "";
                        QString closing_str = "";
                        if(supplier_ledger.value(3).toInt() == 0 || supplier_ledger.value(3).toInt() == 2){
                            opening_str = "+";
                            total_op_bal += supplier_ledger.value(2).toFloat();
                        }
                        if(supplier_ledger.value(3).toInt() == 1){
                            opening_str = "-";
                            total_op_bal -= supplier_ledger.value(2).toFloat();
                        }

                        QSqlQuery closing_bunk_balance;

                        //                        QString particular_bunk_bal;
                        //                        particular_bunk_bal = supplier_ledger.value(5).toString().trimmed();
                        //                        if(supplier_ledger.value(6).toInt() == 0 || supplier_ledger.value(6).toInt() == 2){
                        //                            closing_str = "+";
                        //                            total_cl_bal += supplier_ledger.value(5).toFloat();
                        //                        }
                        //                        if(supplier_ledger.value(6).toInt() == 1){
                        //                            closing_str = "-";
                        //                            total_cl_bal -= supplier_ledger.value(5).toFloat();
                        //                        }


                        QString particular_bunk_bal;
                        if(databaseObj->selectQuery("select diesel_transaction.closing_balance,diesel_transaction.closing_balance_type from diesel_transaction where diesel_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) and diesel_transaction.bunk_id='"+supplier_ledger.value(0).toString()+"' and rowid=(select max(rowid) from diesel_transaction where diesel_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) and diesel_transaction.bunk_id='"+supplier_ledger.value(0).toString()+"')",closing_bunk_balance))
                        {
                            if(closing_bunk_balance.next())
                            {
                                particular_bunk_bal = closing_bunk_balance.value(0).toString().trimmed();
                                if(closing_bunk_balance.value(1).toInt() == 0 || closing_bunk_balance.value(1).toInt() == 2){
                                    closing_str = "+";
                                    total_cl_bal += closing_bunk_balance.value(0).toFloat();
                                }
                                if(closing_bunk_balance.value(1).toInt() == 1){
                                    closing_str = "-";
                                    total_cl_bal -= closing_bunk_balance.value(0).toFloat();
                                }
                            }
                        }

                        QSqlQuery bunk_today_pur_qur;
                        QString bunk_todays_addition="";
                        if(databaseObj->selectQuery("select diesel_transaction.bunk_id,bunk_master.bunk_name,sum(diesel_transaction.amount) as paid from diesel_transaction inner join bunk_master on bunk_master.id_bunk_master=diesel_transaction.bunk_id where diesel_transaction.is_payment=0 and diesel_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) and diesel_transaction.bunk_id='"+supplier_ledger.value(0).toString()+"'",bunk_today_pur_qur))
                        {
                            if(bunk_today_pur_qur.next())
                            {
                                bunk_todays_addition = bunk_today_pur_qur.value(2).toString();
                            }
                        }

                        total_paid += supplier_ledger.value(4).toFloat();
                        total_addition += bunk_todays_addition.toFloat();
                        to_print = supplier_ledger.value(1).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(2).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+" "+bunk_todays_addition.rightJustified(6,' ',1)+" "+supplier_ledger.value(4).toString().trimmed().rightJustified(6,' ',1)+particular_bunk_bal.trimmed().prepend(closing_str).rightJustified(7,' ',1);
                        qDebug()<<"supplier_ledger ===>>>"<<to_print;
                        print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                    }
                }
            }

            supplier_ledger.clear();
            if(databaseObj->selectQuery("select * from bunk_master where bunk_master.id_bunk_master not in (select diesel_transaction.bunk_id from diesel_transaction where diesel_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')))",supplier_ledger))
            {
                if(supplier_ledger.next())
                {
                    QString to_print;

//                    QString closing_str = "";
//                    if(supplier_ledger.value(4).toInt() == 0 || supplier_ledger.value(4).toInt() == 2){
//                        closing_str = "+";
//                        total_cl_bal += supplier_ledger.value(3).toFloat();
//                    }
//                    if(supplier_ledger.value(4).toInt() == 1){
//                        closing_str = "-";
//                        total_cl_bal -= supplier_ledger.value(3).toFloat();
//                    }

//                    to_print = supplier_ledger.value(1).toString().trimmed().leftJustified(31,' ',1)+supplier_ledger.value(3).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);


                    QString opening_str = "";
                    QString closing_str = "";

                    if(supplier_ledger.value(4).toInt() == 0 || supplier_ledger.value(4).toInt() == 2){
                        closing_str = "+";
                        total_cl_bal += supplier_ledger.value(3).toFloat();

                        opening_str = "+";
                        total_op_bal += supplier_ledger.value(3).toFloat();
                    }
                    if(supplier_ledger.value(4).toInt() == 1){
                        closing_str = "-";
                        total_cl_bal -= supplier_ledger.value(3).toFloat();

                        opening_str = "-";
                        total_op_bal -= supplier_ledger.value(3).toFloat();
                    }

                    to_print = supplier_ledger.value(1).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(3).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+"              "+supplier_ledger.value(3).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);


                    qDebug()<<"bunk_master ledger ===>>>"<<to_print;
                    print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                    while(supplier_ledger.next())
                    {
                        QString to_print;

//                        QString closing_str = "";
//                        if(supplier_ledger.value(4).toInt() == 0 || supplier_ledger.value(4).toInt() == 2){
//                            closing_str = "+";
//                            total_cl_bal += supplier_ledger.value(3).toFloat();
//                        }
//                        if(supplier_ledger.value(4).toInt() == 1){
//                            closing_str = "-";
//                            total_cl_bal -= supplier_ledger.value(3).toFloat();
//                        }
//                        to_print = supplier_ledger.value(1).toString().trimmed().leftJustified(31,' ',1)+supplier_ledger.value(3).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);


                        QString opening_str = "";
                        QString closing_str = "";

                        if(supplier_ledger.value(4).toInt() == 0 || supplier_ledger.value(4).toInt() == 2){
                            closing_str = "+";
                            total_cl_bal += supplier_ledger.value(3).toFloat();

                            opening_str = "+";
                            total_op_bal += supplier_ledger.value(3).toFloat();
                        }
                        if(supplier_ledger.value(4).toInt() == 1){
                            closing_str = "-";
                            total_cl_bal -= supplier_ledger.value(3).toFloat();

                            opening_str = "-";
                            total_op_bal -= supplier_ledger.value(3).toFloat();
                        }

//                        to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+"              "+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);
                        to_print = supplier_ledger.value(1).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(3).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+"              "+supplier_ledger.value(3).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);


                        qDebug()<<"bunk_master ledger ===>>>"<<to_print;
                        print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                    }
                }
            }


            QString to_print_total;
            to_print_total = "Total "+QString::number(total_op_bal).rightJustified(6,' ',1)+QString::number(total_addition).rightJustified(6,' ',1)+" "+QString::number(total_paid).rightJustified(5,' ',1)+" "+QString::number(total_cl_bal).rightJustified(6,' ',1);
            print.addData(to_print_total,CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);


            //            //            float

            //            //              LEDGER  |OP.BAL|TODAY+|  PAID  |CL.BAL

            //            print.addData("Ledger Wise Report",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
            //            print.addData("  LEDGER   OP.BAL TODAY+  PAID  CL.BAL",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            //            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

            //            //! supplier

            //            QSqlQuery supplier_ledger;
            //            if(databaseObj->selectQuery("select transaction_master.vehicle_no,transaction_master.cus_name,min(transaction_master.previous_balance) as op_bal,min(transaction_master.previous_balance_type) as op_bal_type,sum(transaction_master.inward_hush) as inward_husk,sum(transaction_master.approved_amt) as approved_amt,sum(transaction_master.paid) as paid,customer_master.balance,customer_master.balance_type from transaction_master inner join customer_master on customer_master.cus_name=transaction_master.cus_name where transaction_master.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) group by transaction_master.cus_name",supplier_ledger))
            //            {
            //                if(supplier_ledger.next())
            //                {
            //                    QString to_print;
            //                    QString opening_str = "";
            //                    QString closing_str = "";
            //                    if(supplier_ledger.value(3).toInt() == 0 || supplier_ledger.value(3).toInt() == 2)
            //                        opening_str = "+";
            //                    if(supplier_ledger.value(3).toInt() == 1)
            //                        opening_str = "-";

            //                    if(supplier_ledger.value(8).toInt() == 0 || supplier_ledger.value(8).toInt() == 2)
            //                        closing_str = "+";
            //                    if(supplier_ledger.value(8).toInt() == 1)
            //                        closing_str = "-";

            //                    to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(2).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+" "+supplier_ledger.value(5).toString().trimmed().rightJustified(6,' ',1)+" "+supplier_ledger.value(6).toString().trimmed().rightJustified(6,' ',1)+supplier_ledger.value(7).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);
            //                    qDebug()<<"supplier_ledger ===>>>"<<to_print;
            //                    print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            //                    while(supplier_ledger.next())
            //                    {
            //                        QString to_print;
            //                        QString opening_str = "";
            //                        QString closing_str = "";
            //                        if(supplier_ledger.value(3).toInt() == 0 || supplier_ledger.value(3).toInt() == 2)
            //                            opening_str = "+";
            //                        if(supplier_ledger.value(3).toInt() == 1)
            //                            opening_str = "-";

            //                        if(supplier_ledger.value(8).toInt() == 0 || supplier_ledger.value(8).toInt() == 2)
            //                            closing_str = "+";
            //                        if(supplier_ledger.value(8).toInt() == 1)
            //                            closing_str = "-";

            //                        to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(2).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+" "+supplier_ledger.value(5).toString().trimmed().rightJustified(6,' ',1)+" "+supplier_ledger.value(6).toString().trimmed().rightJustified(6,' ',1)+supplier_ledger.value(7).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);
            //                        qDebug()<<"supplier_ledger ===>>>"<<to_print;
            //                        print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            //                    }
            //                }
            //            }
            //            supplier_ledger.clear();
            //            if(databaseObj->selectQuery("select customer_master.cus_name,customer_master.balance as cl_bal,customer_master.balance_type as cl_bal_type from customer_master where customer_master.balance>0 and customer_master.cus_name not in (select transaction_master.cus_name from transaction_master where transaction_master.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) group by transaction_master.cus_name)",supplier_ledger))
            //            {
            //                if(supplier_ledger.next())
            //                {
            //                    QString to_print;

            //                    QString closing_str = "";
            //                    if(supplier_ledger.value(2).toInt() == 0 || supplier_ledger.value(8).toInt() == 2)
            //                        closing_str = "+";
            //                    if(supplier_ledger.value(2).toInt() == 1)
            //                        closing_str = "-";

            //                    to_print = supplier_ledger.value(1).toString().trimmed().leftJustified(31,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);
            //                    qDebug()<<"supplier_ledger ===>>>"<<to_print;
            //                    print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            //                    while(supplier_ledger.next())
            //                    {
            //                        QString to_print;

            //                        QString closing_str = "";
            //                        if(supplier_ledger.value(2).toInt() == 0 || supplier_ledger.value(8).toInt() == 2)
            //                            closing_str = "+";
            //                        if(supplier_ledger.value(2).toInt() == 1)
            //                            closing_str = "-";

            //                        to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(31,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);
            //                        qDebug()<<"supplier_ledger ===>>>"<<to_print;
            //                        print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            //                    }
            //                }
            //            }


            //            //! employee

            //            supplier_ledger.clear();
            //            if(databaseObj->selectQuery("select employee_transaction.emp_name,sum(employee_transaction.produced_bale) as produced_bale,min(employee_transaction.opening_balance) as op_bal,min(employee_transaction.opening_balance_type) as op_bal_type,sum(employee_transaction.calc_salary) as calc_salary,sum(employee_transaction.paid_salary) as paid,employee_master.emp_balance_bale_rate,employee_master.emp_balance_type from employee_transaction inner join employee_master on employee_master.emp_name=employee_transaction.emp_name where employee_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) group by employee_transaction.emp_name",supplier_ledger))
            //            {
            //                if(supplier_ledger.next())
            //                {
            //                    QString to_print;
            //                    QString opening_str = "";
            //                    QString closing_str = "";
            //                    if(supplier_ledger.value(3).toInt() == 0 || supplier_ledger.value(3).toInt() == 2)
            //                        opening_str = "+";
            //                    if(supplier_ledger.value(3).toInt() == 1)
            //                        opening_str = "-";

            //                    if(supplier_ledger.value(7).toInt() == 0 || supplier_ledger.value(7).toInt() == 2)
            //                        closing_str = "+";
            //                    if(supplier_ledger.value(7).toInt() == 1)
            //                        closing_str = "-";

            //                    to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(2).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+" "+supplier_ledger.value(4).toString().trimmed().rightJustified(6,' ',1)+" "+supplier_ledger.value(5).toString().trimmed().rightJustified(6,' ',1)+supplier_ledger.value(6).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);
            //                    qDebug()<<"supplier_ledger ===>>>"<<to_print;
            //                    print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            //                    while(supplier_ledger.next())
            //                    {
            //                        QString to_print;
            //                        QString opening_str = "";
            //                        QString closing_str = "";
            //                        if(supplier_ledger.value(3).toInt() == 0 || supplier_ledger.value(3).toInt() == 2)
            //                            opening_str = "+";
            //                        if(supplier_ledger.value(3).toInt() == 1)
            //                            opening_str = "-";

            //                        if(supplier_ledger.value(7).toInt() == 0 || supplier_ledger.value(7).toInt() == 2)
            //                            closing_str = "+";
            //                        if(supplier_ledger.value(7).toInt() == 1)
            //                            closing_str = "-";

            //                        to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(2).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+" "+supplier_ledger.value(4).toString().trimmed().rightJustified(6,' ',1)+" "+supplier_ledger.value(5).toString().trimmed().rightJustified(6,' ',1)+supplier_ledger.value(6).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);
            //                        qDebug()<<"supplier_ledger ===>>>"<<to_print;
            //                        print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            //                    }
            //                }
            //            }

            //            supplier_ledger.clear();
            //            if(databaseObj->selectQuery("select employee_master.emp_name,employee_master.emp_balance_bale_rate,employee_master.emp_balance_type from employee_master where employee_master.emp_name not in (select employee_transaction.emp_name from employee_transaction where employee_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) and is_active='1' group by employee_transaction.emp_name)",supplier_ledger))
            //            {
            //                if(supplier_ledger.next())
            //                {
            //                    QString to_print;

            //                    QString closing_str = "";
            //                    if(supplier_ledger.value(2).toInt() == 0 || supplier_ledger.value(8).toInt() == 2)
            //                        closing_str = "+";
            //                    if(supplier_ledger.value(2).toInt() == 1)
            //                        closing_str = "-";

            //                    to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(31,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);
            //                    qDebug()<<"supplier_ledger ===>>>"<<to_print;
            //                    print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            //                    while(supplier_ledger.next())
            //                    {
            //                        QString to_print;

            //                        QString closing_str = "";
            //                        if(supplier_ledger.value(2).toInt() == 0 || supplier_ledger.value(8).toInt() == 2)
            //                            closing_str = "+";
            //                        if(supplier_ledger.value(2).toInt() == 1)
            //                            closing_str = "-";

            //                        to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(31,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);
            //                        qDebug()<<"supplier_ledger ===>>>"<<to_print;
            //                        print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            //                    }
            //                }
            //            }

            //            //! bunk ledger

            //            supplier_ledger.clear();
            //            if(databaseObj->selectQuery("select diesel_transaction.bunk_id,bunk_master.bunk_name,min(diesel_transaction.opening_balance) as op_bal,min(diesel_transaction.opening_balance_type) as op_bal_type,sum(diesel_transaction.amount) as paid,max(diesel_transaction.closing_balance) as cl_bal,max(diesel_transaction.closing_balance_type) as cl_bal_type from diesel_transaction inner join bunk_master on bunk_master.id_bunk_master=diesel_transaction.bunk_id where diesel_transaction.is_payment=1 and diesel_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0'))",supplier_ledger))
            //            {
            //                if(supplier_ledger.next())
            //                {
            //                    QString to_print;
            //                    QString opening_str = "";
            //                    QString closing_str = "";
            //                    if(supplier_ledger.value(3).toInt() == 0 || supplier_ledger.value(3).toInt() == 2)
            //                        opening_str = "+";
            //                    if(supplier_ledger.value(3).toInt() == 1)
            //                        opening_str = "-";

            //                    if(supplier_ledger.value(6).toInt() == 0 || supplier_ledger.value(6).toInt() == 2)
            //                        closing_str = "+";
            //                    if(supplier_ledger.value(6).toInt() == 1)
            //                        closing_str = "-";

            //                    to_print = supplier_ledger.value(1).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(2).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+" "+QString("      ")+" "+supplier_ledger.value(4).toString().trimmed().rightJustified(6,' ',1)+supplier_ledger.value(5).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);
            //                    qDebug()<<"supplier_ledger ===>>>"<<to_print;
            //                    print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            //                    while(supplier_ledger.next())
            //                    {
            //                        QString to_print;
            //                        QString opening_str = "";
            //                        QString closing_str = "";
            //                        if(supplier_ledger.value(3).toInt() == 0 || supplier_ledger.value(3).toInt() == 2)
            //                            opening_str = "+";
            //                        if(supplier_ledger.value(3).toInt() == 1)
            //                            opening_str = "-";

            //                        if(supplier_ledger.value(6).toInt() == 0 || supplier_ledger.value(6).toInt() == 2)
            //                            closing_str = "+";
            //                        if(supplier_ledger.value(6).toInt() == 1)
            //                            closing_str = "-";

            //                        to_print = supplier_ledger.value(1).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(2).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+" "+QString("      ")+" "+supplier_ledger.value(4).toString().trimmed().rightJustified(6,' ',1)+supplier_ledger.value(5).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);
            //                        qDebug()<<"supplier_ledger ===>>>"<<to_print;
            //                        print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            //                    }
            //                }
            //            }


            QSqlQuery batch_close_qur;
            QStringList lst_batch;
            lst_batch << "company_batch_no" << "other_batch_no" << "van_batch_no";

            lst_batch_no.clear();
            for(int i=0;i<lst_batch.size();i++)
            {

                QString batch_name;
                if(lst_batch.at(i).contains("company",Qt::CaseInsensitive))
                    batch_name = "Company ";
                if(lst_batch.at(i).contains("other",Qt::CaseInsensitive))
                    batch_name = "Auto ";
                if(lst_batch.at(i).contains("van",Qt::CaseInsensitive))
                    batch_name = "Van ";


                if(databaseObj->selectQuery("select batch_no from "+lst_batch.at(i)+" where production_day_no_close=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) order by batch_no desc",batch_close_qur))
                {
                    if(batch_close_qur.next())
                    {
                        lst_batch_no << batch_name+batch_close_qur.value(0).toString().trimmed().rightJustified(3,'0');
                        while(batch_close_qur.next())
                        {
                            lst_batch_no << batch_name+batch_close_qur.value(0).toString().trimmed().rightJustified(3,'0');
                        }
                    }
                }
            }
            qDebug()<<"batch_close_qur ===>>>"<<lst_batch_no;
            if(lst_batch_no.size() > 0)
            {
                for(int i=0;i<lst_batch_no.size();i++)
                {
                    QString batch_name;
                    if(lst_batch_no.at(i).contains("company",Qt::CaseInsensitive))
                        batch_name = "company_batch_no";
                    if(lst_batch_no.at(i).contains("auto",Qt::CaseInsensitive))
                        batch_name = "other_batch_no";
                    if(lst_batch_no.at(i).contains("van",Qt::CaseInsensitive))
                        batch_name = "van_batch_no";


                    batch_close_qur.clear();
                    if(databaseObj->selectQuery("select batch_no,total_husk_produced,est_bale,manu_bale,used_husk,excess_husk,diff_bale from "+batch_name+" where production_day_no_close=((select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')))",batch_close_qur))
                    {
                        if(batch_close_qur.next())
                        {

                            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

                            print.addData("BATCH CLOSE REPORT",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
                            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

                            print.addData("BATCH NAME        : "+lst_batch_no.at(i).toUpper(),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                            print.addData("TOTAL PURCHASE    : "+batch_close_qur.value(1).toString().trimmed().append(" NOS"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

                            print.addData("TOTAL NO OF BALE  : "+batch_close_qur.value(3).toString().trimmed().append(" NOS"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                            print.addData("NO OF HUSK TO BALE: "+batch_close_qur.value(4).toString().trimmed().append(" NOS"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

                            QString diff_bale = batch_close_qur.value(6).toString().trimmed().append(" NOS");
                            QString diff_bale1 = diff_bale;

                            int diff_husk = batch_close_qur.value(4).toInt() - batch_close_qur.value(1).toInt();

                            print.addData("DIFFERENCE        :"+QString::number(diff_husk),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

                            //                            if(diff_bale1.contains("-"))
                            //                                print.addData("DIFFERENCE        :"+diff_bale.remove("-"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                            //                            else
                            //                                print.addData("DIFFERENCE        :"+diff_bale.prepend("-"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

                            if(diff_husk > 0)
                                print.addData("GAIN",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                            else
                                print.addData("LOSS",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

                            while(batch_close_qur.next())
                            {
                                print.addData("BATCH NAME        : "+lst_batch_no.at(i).toUpper(),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                                print.addData("TOTAL PURCHASE    : "+batch_close_qur.value(1).toString().trimmed().append(" NOS"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                                print.addData("TOTAL NO OF BALE  : "+batch_close_qur.value(3).toString().trimmed().append(" NOS"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                                print.addData("NO OF HUSK TO BALE:"+batch_close_qur.value(2).toString().trimmed().append(" NOS"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

                                QString diff_bale = batch_close_qur.value(6).toString().trimmed().append(" NOS");
                                QString diff_bale1 = diff_bale;

                                if(diff_bale1.contains("-"))
                                    print.addData("DIFFERENCE        :"+diff_bale.remove("-"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                                else
                                    print.addData("DIFFERENCE        :"+diff_bale.prepend("-"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

                                if(diff_bale1.contains("-"))
                                    print.addData("GAIN",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                                else
                                    print.addData("LOSS",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                            }
                        }
                    }
                }
            }


            //                diesel_report_qur.clear();
            //                if(databaseObj->selectQuery("select sum(diesel_usage.quantity),max(diesel_usage.reading) from diesel_usage where diesel_usage.vehicle_no='bull'",diesel_report_qur ))
            //                {
            //                    if(diesel_report_qur.next())
            //                    {
            //                        print.addData("BULL : "+diesel_report_qur.value(1).toString().trimmed()+" Lts",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            //                    }
            //                }

            //                diesel_report_qur.clear();
            //                if(databaseObj->selectQuery("select * from diesel_usage where day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) and vehicle_no='bull' group by vehicle_no",diesel_report_qur))
            //                {
            //                    if(diesel_qur.next())
            //                    {
            //                        QString v_name = diesel_qur.value(1).toString().trimmed();
            //                        QString diff = get_difference("bull");
            //                        qDebug()<<"diff ===>>>"<<diff;
            //                        if(diff.toInt() > 0)
            //                        {
            //                            print.addData(v_name.toUpper().leftJustified(12,' ')+": "+diff ,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            //                        }
            //                    }
            //                }


            //                QSqlQuery diesel_qur;

            //                QString initial_diesel_stock;
            //                diesel_qur.clear();
            //                if(databaseObj->selectQuery("select init_diesel_reading from configuration_master",diesel_qur))
            //                {
            //                    if(diesel_qur.next())
            //                    {
            //                        initial_diesel_stock = diesel_qur.value(0).toString().trimmed();
            //                    }
            //                }
            //                diesel_qur.clear();
            //                if(databaseObj->selectQuery("select * from diesel_usage where day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) and fill_type='1'",diesel_qur))
            //                {
            //                    if(diesel_qur.next())
            //                    {
            //                        print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            //                        print.addData("Diesel Consumption",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
            //                        print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

            //                        diesel_qur.clear();
            //                        if(databaseObj->selectQuery("select * from diesel_usage where day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) and fill_type='1' group by vehicle_no",diesel_qur))
            //                        {
            //                            if(diesel_qur.next())
            //                            {
            //                                QString v_name = diesel_qur.value(1).toString().trimmed();
            //                                QString diff = get_difference(v_name);
            //                                qDebug()<<"diff ===>>>"<<diff;
            //                                if(diff.toInt() > 0)
            //                                {
            //                                    print.addData(v_name.toUpper().leftJustified(12,' ')+": "+diff ,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            //                                }
            //                            }
            //                        }

            //                        QString diff = get_difference("bull");
            //                        qDebug()<<"diff ===>>>"<<diff;
            //                        if(diff.toInt() > 0)
            //                        {
            //                            print.addData(QString("bull").toUpper().leftJustified(12,' ')+": "+diff ,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            //                        }
            //                        QString diff = get_difference("generator");
            //                        qDebug()<<"diff ===>>>"<<diff;
            //                        if(diff.toInt() > 0)
            //                        {
            //                            print.addData(QString("generator").toUpper().leftJustified(12,' ')+": "+diff ,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            //                        }

            //                        print.addData("Closing Stock: "+initial_diesel_stock+" lts",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

            //                        diesel_qur.clear();
            //                    }
            //                }


            //                QSqlQuery payables_qur;
            //                QString v_pay = "0";
            //                QStringList lst_v_no,lst_party_name,lst_amt;
            //                payables_qur.clear();
            //                if(databaseObj->selectQuery("select vehicle_no,cus_name,paid from transaction_master where day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0'))",payables_qur))
            //                {
            //                    if(payables_qur.next())
            //                    {
            //                        lst_v_no << payables_qur.value(0).toString().trimmed();
            //                        lst_party_name << payables_qur.value(1).toString().trimmed();
            //                        lst_amt << payables_qur.value(2).toString().trimmed();
            //                        while(payables_qur.next())
            //                        {
            //                            lst_v_no << payables_qur.value(0).toString().trimmed();
            //                            lst_party_name << payables_qur.value(1).toString().trimmed();
            //                            lst_amt << payables_qur.value(2).toString().trimmed();
            //                        }
            //                    }
            //                    if(lst_v_no.size() > 0)
            //                    {
            //                        print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            //                        print.addData("Payables/Receivable",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
            //                        print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            //                        print.addData("Vehicle No    Party Name       Amount",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

            //                        for(int i=0;i<lst_v_no.size();i++)
            //                        {
            //                            print.addData(lst_v_no.at(i).leftJustified(11,' ')+" "+lst_party_name.at(i).rightJustified(15,' ')+" "+QString::number(lst_amt.at(i).rightJustified(10,' ').toFloat(),'f',2),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            //                        }
            //                        payables_qur.clear();
            //                        if(databaseObj->selectQuery("select sum(paid) from transaction_master where day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0'))",payables_qur))
            //                        {
            //                            if(payables_qur.next())
            //                            {
            //                                v_pay = payables_qur.value(0).toString().trimmed();
            //                            }
            //                        }
            //                    }
            //                }

            //                QSqlQuery bunk_qur;
            //                QString bunk_pay = "0";
            //                QStringList lst_bunk_name,lst_bunk_qty,lst_bunk_amount;
            //                if(databaseObj->selectQuery("select diesel_transaction.bunk_id,bunk_master.bunk_name,diesel_transaction.quantity,diesel_transaction.amount from diesel_transaction inner join bunk_master on diesel_transaction.bunk_id=bunk_master.id_bunk_master where day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0'))",bunk_qur))
            //                {
            //                    if(bunk_qur.next())
            //                    {
            //                        lst_bunk_name << bunk_qur.value(1).toString().trimmed();
            //                        lst_bunk_qty << bunk_qur.value(2).toString().trimmed();
            //                        lst_bunk_amount << bunk_qur.value(3).toString().trimmed();
            //                        while(bunk_qur.next())
            //                        {
            //                            lst_bunk_name << bunk_qur.value(1).toString().trimmed();
            //                            lst_bunk_qty << bunk_qur.value(2).toString().trimmed();
            //                            lst_bunk_amount << bunk_qur.value(3).toString().trimmed();
            //                        }
            //                    }


            //                    if(lst_bunk_name.size() > 0)
            //                    {

            //                        if(lst_v_no.size() == 0)
            //                        {
            //                            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            //                            print.addData("Payables/Receivable",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
            //                            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            //                        }

            //                        for(int i=0;i<lst_bunk_name.size();i++)
            //                        {
            //                            print.addData("            "+lst_bunk_name.at(i).leftJustified(15,' ')+" "+QString::number(lst_bunk_amount.at(i).rightJustified(10,' ').toFloat(),'f',2),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            //                        }
            //                        bunk_qur.clear();
            //                        if(databaseObj->selectQuery("select sum(diesel_transaction.amount) from diesel_transaction where day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0'))",bunk_qur))
            //                        {
            //                            if(bunk_qur.next())
            //                            {
            //                                bunk_pay = bunk_qur.value(0).toString().trimmed();
            //                            }
            //                        }
            //                    }
            //                }

            //                QSqlQuery emp_qur;
            //                QString emp_pay = "0";
            //                QStringList lst_emp_name,lst_emp_amount;
            //                if(databaseObj->selectQuery("select emp_name,paid_salary from employee_transaction where paid_salary IS NOT NULL and day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0'))",emp_qur))
            //                {
            //                    if(emp_qur.next())
            //                    {
            //                        lst_emp_name << emp_qur.value(0).toString().trimmed();
            //                        lst_emp_amount << emp_qur.value(1).toString().trimmed();
            //                        while(emp_qur.next())
            //                        {
            //                            lst_emp_name << emp_qur.value(0).toString().trimmed();
            //                            lst_emp_amount << emp_qur.value(1).toString().trimmed();
            //                        }
            //                    }
            //                    if(lst_emp_name.size() > 0)
            //                    {

            //                        if( (lst_v_no.size() == 0) && (lst_bunk_name.size() == 0) )
            //                        {
            //                            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            //                            print.addData("Payables/Receivable",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
            //                            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            //                        }

            //                        for(int i=0;i<lst_emp_name.size();i++)
            //                        {
            //                            print.addData("            "+lst_emp_name.at(i).leftJustified(15,' ')+" "+QString::number(lst_emp_amount.at(i).rightJustified(10,' ').toFloat(),'f',2),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            //                        }
            //                        emp_qur.clear();
            //                        if(databaseObj->selectQuery("select sum(paid_salary) from employee_transaction where paid_salary IS NOT NULL and day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0'))",emp_qur))
            //                        {
            //                            if(emp_qur.next())
            //                            {
            //                                emp_pay = emp_qur.value(0).toString().trimmed();
            //                            }
            //                        }
            //                    }
            //                }
            //                if( (lst_v_no.size() != 0) || (lst_bunk_name.size() != 0) || (lst_emp_name.size() != 0) )
            //                {
            //                    print.addData("Total Payables:Rs "+QString::number(v_pay.toFloat() + emp_pay.toFloat() + bunk_pay.toFloat(),'f',2 ),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
            //                }

            //                QSqlQuery batch_supplier_qur;
            //                if(databaseObj->selectQuery("select vehicle_no,cus_name,count(vehicle_no),sum(inward_bale),sum(inward_hush) from transaction_master where day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) group by cus_name",batch_supplier_qur))
            //                {
            //                    if(batch_supplier_qur.next())
            //                    {
            //                        QString batch_supplier_details = batch_supplier_qur.value(0).toString().trimmed().leftJustified(10,' ')+" "+batch_supplier_qur.value(1).toString().trimmed().leftJustified(7,' ')+" "+batch_supplier_qur.value(2).toString().trimmed().rightJustified(2,' ')+" "+QString::number(batch_supplier_qur.value(3).toString().trimmed(),'f',2).rightJustified(6,' ')+" "+QString::number(batch_supplier_qur.value(4).toString().trimmed(),'f',2).rightJustified(9,' ');
            //                        qDebug()<<"batch_supplier_details ===>>>"<<batch_supplier_details;
            //                        print.addData(batch_supplier_details,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            //                        while(batch_supplier_qur.next())
            //                        {
            //                            QString batch_supplier_details = batch_supplier_qur.value(0).toString().trimmed().leftJustified(10,' ')+" "+batch_supplier_qur.value(1).toString().trimmed().leftJustified(7,' ')+" "+batch_supplier_qur.value(2).toString().trimmed().rightJustified(2,' ')+" "+QString::number(batch_supplier_qur.value(3).toString().trimmed(),'f',2).rightJustified(6,' ')+" "+QString::number(batch_supplier_qur.value(4).toString().trimmed(),'f',2).rightJustified(9,' ');
            //                            qDebug()<<"batch_supplier_details ===>>>"<<batch_supplier_details;
            //                            print.addData(batch_supplier_details,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            //                        }
            //                        batch_supplier_qur.clear();
            //                        if(databaseObj->selectQuery("select sum(inward_bale),sum(inward_hush) from transaction_master where day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0'))",batch_supplier_qur))
            //                        {
            //                            if(batch_supplier_qur.next())
            //                            {
            ////                                QString batch_supplier_details = batch_supplier_qur.value(0).toString().trimmed().leftJustified(10,' ')+" "+batch_supplier_qur.value(1).toString().trimmed().leftJustified(7,' ')+" "+batch_supplier_qur.value(2).toString().trimmed().rightJustified(2,' ')+" "+QString::number(batch_supplier_qur.value(3).toString().trimmed(),'f',2).rightJustified(6,' ')+" "+QString::number(batch_supplier_qur.value(4).toString().trimmed(),'f',2).rightJustified(9,' ');
            ////                                qDebug()<<"batch_supplier_details ===>>>"<<batch_supplier_details;
            //                                print.addData(batch_supplier_details,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            //                            }
            //                        }
            //                    }
            //                }



            //            }

            print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            if(print.print(false,false))
            {

            }

        }
    }
#endif
}


QString Report::get_difference(QString name)
{
    QSqlQuery diesel_qur;
    if(databaseObj->selectQuery("SELECT count(*) FROM diesel_usage where vehicle_no='"+name+"' and fill_type=1 ORDER BY reading DESC limit 2",diesel_qur))
    {
        if(diesel_qur.next())
        {
            int count = diesel_qur.value(0).toString().toInt();
            qDebug()<<"count ===>>>"<<QString::number(count);
            if(count >= 2)
            {
                diesel_qur.clear();
                if(databaseObj->selectQuery("SELECT reading FROM diesel_usage where vehicle_no='"+name+"' and fill_type=1  ORDER BY reading DESC limit 2",diesel_qur))
                {
                    QString val1,val2;
                    if(diesel_qur.next())
                    {
                        val1 = diesel_qur.value(0).toString().trimmed();
                        qDebug()<<"val1 ===>>>"<<val1;
                        while(diesel_qur.next())
                        {
                            val2 = diesel_qur.value(0).toString().trimmed();
                            qDebug()<<"val2 ===>>>"<<val2;
                        }
                        QString reading = QString::number(val1.toFloat()-val2.toFloat(),'f',2);
                        qDebug()<<"reading ===>>>"<<reading;
                        return reading;

                    }
                }
            }
            else
                return "";

        }
        else
            return "";
    }
    else
        return "";

}

void Report::on_pushButton_batch_close_clicked()
{
    ui->groupBox->hide();


    ui->dateEdit_from->setDateTime(QDateTime::currentDateTime());
    ui->dateEdit_from->setCurrentSection(QDateEdit::DaySection);
    //    ui->dateEdit_to->setDateTime(QDateTime::currentDateTime());
    //    ui->dateEdit_to->setCurrentSection(QDateEdit::DaySection);

    ui->groupBox_batch_report->show();
    ui->groupBox_batch_report->raise();

    ui->dateEdit_from->setFocus();
}

//void Report::on_comboBox_batch_currentIndexChanged(int index)
//{

////    qDebug()<<"on_comboBox_batch_currentIndexChanged ===>>>";
////    ui->label_purchase->clear();
////    ui->label_husk_bale->clear();
////    ui->label_bale->clear();
////    ui->label_purchase->clear();
////    ui->label_gain_lose->clear();

//    //    if(lst_batch_no.size() > 0)
//    //    {

//    //    }
//}

void Report::on_pushButton_supplier_batch_wise_clicked()
{
    ui->lineEdit_batch_supplier->clear();
    QSqlQuery batch_supplier_qur;


    QStringList lst_batch;
    lst_batch << "company_batch_no" << "other_batch_no" << "van_batch_no";
    qDebug()<<"test ===>>>2.1";

    lst_batch_no.clear();
    for(int i=0;i<lst_batch.size();i++)
    {

        QString batch_name;
        if(lst_batch.at(i).contains("company",Qt::CaseInsensitive))
            batch_name = "Company ";
        if(lst_batch.at(i).contains("other",Qt::CaseInsensitive))
            batch_name = "Auto ";
        if(lst_batch.at(i).contains("van",Qt::CaseInsensitive))
            batch_name = "Van ";


        if(databaseObj->selectQuery("select batch_no from "+lst_batch.at(i)+" order by batch_no desc",batch_supplier_qur))
        {
            if(batch_supplier_qur.next())
            {
                lst_batch_no << batch_name+batch_supplier_qur.value(0).toString().trimmed().rightJustified(3,'0');
                while(batch_supplier_qur.next())
                {
                    lst_batch_no << batch_name+batch_supplier_qur.value(0).toString().trimmed().rightJustified(3,'0');
                }
            }
        }
    }
    if(lst_batch_no.size() > 0)
    {

        cmpter = new QCompleter(lst_batch_no,this);
        cmpter->setCaseSensitivity(Qt::CaseInsensitive);
        cmpter->setCompletionMode(QCompleter::PopupCompletion);
        ui->lineEdit_batch_supplier->setCompleter(cmpter);


        ui->groupBox->hide();
        ui->groupBox_batch_supplier->show();
        ui->groupBox_batch_supplier->raise();
#if(SDK75)
        g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
#endif
        ui->lineEdit_batch_supplier->setFocus();

    }
    else
    {
#if(SDK75)
        int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"Batch Not Available.",14,14);
        ui->pushButton_batch_close->setFocus();
#endif
    }

}

void Report::on_pushButton_supplier_clicked()
{
    ui->lineEdit_supplier_name->clear();
    ui->lineEdit_supplier_vno->clear();

    ui->label_name_balance_title->clear();
    ui->label_name_balance_amt->clear();

    QSqlQuery vehicle_details;
    if(databaseObj->selectQuery("select * from vehicle_registration",vehicle_details))
    {
        lst_vehicle_number.clear();
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

    cmpte3 = new QCompleter(lst_vehicle_number,this);
    cmpte3->setCaseSensitivity(Qt::CaseInsensitive);
    cmpte3->setCompletionMode(QCompleter::PopupCompletion);
    ui->lineEdit_supplier_vno->setCompleter(cmpte3);

    QSqlQuery broker_details;
    lst_broker_name.clear();
    lst_broker_mobile.clear();
    if(databaseObj->selectQuery("select * from customer_master where cus_type='1'",broker_details))
    {
        if(broker_details.next())
        {
            lst_broker_name << broker_details.value(1).toString().trimmed();
            lst_broker_mobile << broker_details.value(2).toString().trimmed();
        }
        while(broker_details.next())
        {
            lst_broker_name << broker_details.value(1).toString().trimmed();
            lst_broker_mobile << broker_details.value(2).toString().trimmed();
        }
    }

    cmpte4 = new QCompleter(lst_broker_name,this);
    cmpte4->setCaseSensitivity(Qt::CaseInsensitive);
    cmpte4->setCompletionMode(QCompleter::PopupCompletion);
    ui->lineEdit_supplier_name->setCompleter(cmpte4);


    ui->label_name->hide();
    ui->lineEdit_supplier_name->hide();

    ui->groupBox->hide();

    ui->groupBox_supplier_report->show();
    ui->groupBox_supplier_report->raise();

#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif

    ui->dateEdit_from_supplier->setFocus();



}

void Report::on_lineEdit_supplier_vno_returnPressed()
{
    if(!ui->lineEdit_supplier_vno->text().isEmpty())
    {
        QSqlQuery query;
        if(databaseObj->selectQuery("select * from vehicle_registration where vehicle_registration.vehicle_no='"+ui->lineEdit_supplier_vno->text().trimmed()+"'",query))
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

                ui->lineEdit_supplier_name->show();
                ui->label_name->show();

                if(selected_vehicle_type.toInt() == 0)
                {
                    ui->lineEdit_supplier_name->setReadOnly(false);
                    ui->label_name->setText("Broker    :");
                    ui->lineEdit_supplier_name->setFocus();
                    return;
                }

                ui->label_name->setText("Name      :");
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

                        ui->label_name_balance_amt->setText("Rs "+selected_cus_balance);

                        ui->lineEdit_supplier_name->setText(selected_cus_name);
                        ui->lineEdit_supplier_name->setReadOnly(true);
                        ui->label_name_balance_title->show();
                        if(selected_cus_balance_type.toInt() == 0 || selected_cus_balance_type.toInt() == 2)
                        {
                            ui->label_name_balance_title->setText("Op.Advance:");
                        }

                        if(selected_cus_balance_type.toInt() == 1)
                        {
                            ui->label_name_balance_title->setText("Op.Pending:");
                        }

                        qApp->processEvents();
                        qApp->processEvents();
                        print_supplier_report();


                    }
                }

            }
        }
    }
}

void Report::on_lineEdit_supplier_name_returnPressed()
{
    if(!ui->lineEdit_supplier_name->text().isEmpty())
    {

        QSqlQuery query;
        if(databaseObj->selectQuery("select * from customer_master where cus_name='"+ui->lineEdit_supplier_name->text().trimmed()+"'",query))
        {
            if(query.next())
            {
                selected_cus_id = query.value(0).toString().trimmed();
                selected_cus_name = query.value(1).toString().trimmed();
                selected_cus_mobile = query.value(2).toString().trimmed();
                selected_cus_balance = query.value(3).toString().trimmed();
                selected_cus_balance_type = query.value(4).toString().trimmed();

                ui->label_name_balance_amt->setText("Rs "+selected_cus_balance);

                if(selected_cus_balance_type.toInt() == 0)
                {
                    ui->label_name_balance_title->setText("Op.Advance:");
                }

                if(selected_cus_balance_type.toInt() == 1)
                {
                    ui->label_name_balance_title->setText("Op.Pending:");
                }

                ui->pushButton_print_supplier_report->setEnabled(true);
                ui->pushButton_print_supplier_report->setFocus();

            }
        }
    }


}

void Report::print_supplier_report()
{

    QSqlQuery date_qur;
    QStringList lst_day_no,lst_day_no_date;
    if(databaseObj->selectQuery("select day_no,open_date from day_master  where (substr(open_date, 7, 4) || '-' || substr(open_date, 4, 2) || '-' || substr(open_date, 1, 2)) between '"+ui->dateEdit_from_supplier->date().toString("yyyy-MM-dd")+"' and '"+ui->dateEdit_to_supplier->date().toString("yyyy-MM-dd")+"'",date_qur))
    {
        if(date_qur.next())
        {
            lst_day_no << date_qur.value(0).toString().trimmed();
            lst_day_no_date << date_qur.value(1).toString().trimmed();
            while(date_qur.next())
            {
                lst_day_no << date_qur.value(0).toString().trimmed();
                lst_day_no_date << date_qur.value(1).toString().trimmed();
            }

        }
    }
    qDebug()<<"supplier report day_no ===>>>"<<lst_day_no;
    if(lst_day_no.size() > 0)
    {
        //! //!
        QSqlQuery supplier_qur;

        QString bat_type,bat_num;
        qDebug()<<"selected_vehicle_type ===>>>"<<selected_vehicle_type;
        //        if( selected_vehicle_type.contains("company",Qt::CaseInsensitive))
        //            bat_type = "0";
        //        if( selected_vehicle_type.contains("other",Qt::CaseInsensitive))
        //            bat_type = "1";
        //        if( selected_vehicle_type.contains("van",Qt::CaseInsensitive))
        //            bat_type = "2";

        CPrinter print;
        print.setFontType(CPrinter::eFontType_font2);

        print.addData("Supplier Report",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
        print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
        print.addData("VEHICLE NO:"+ui->lineEdit_supplier_vno->text().trimmed().toUpper(),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
        print.addData("FROM :"+ui->dateEdit_from_supplier->date().toString("dd-MM-yyyy")+"  TO: "+ui->dateEdit_to_supplier->date().toString("dd-MM-yyyy"),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

        QSqlQuery op_qur;
        if(databaseObj->selectQuery("select transaction_master.previous_balance,transaction_master.previous_balance_type from transaction_master where transaction_master.is_void is null and transaction_master.day_no='"+lst_day_no.at(0)+"' and rowid=(select min(rowid ) from transaction_master where transaction_master.is_void is null and transaction_master.day_no='"+lst_day_no.at(0)+"' and transaction_master.vehicle_no='"+selected_vehicle_number.trimmed()+"' and transaction_master.cus_name='"+selected_cus_name+"') and transaction_master.vehicle_no='"+selected_vehicle_number.trimmed()+"' and transaction_master.cus_name='"+selected_cus_name.trimmed()+"'",op_qur))
        {
            if(op_qur.next())
            {
                QString bal_type="";
                if(op_qur.value(1).toString().contains("0"))
                    bal_type = " + ";
                if(op_qur.value(1).toString().contains("1"))
                    bal_type = " - ";
                print.addData("OPENING BALANCE: Rs "+bat_type+op_qur.value(0).toString(),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);



            }
        }


        print.addData("DATE LOADS HUSK VAULE PAID  BAL",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
        print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

        float total_closing=0;
        int total_load=0;
        int total_husk=0;
        float total_paid=0;
        float total_approved=0;
        int total_values=0;
        QString balance_sign;

        for(int i=0;i<lst_day_no.size();i++)
        {

            qDebug()<<"supplier report day_no in loop ===>>>"<<i<<lst_day_no.at(i);

            QSqlQuery load_qur;
            QString pay,loads,husk,values,paid,bal_amt,app_amt;
            QString tot_loads,tot_husk,tot_values,tot_paid,tot_bal_amt;
            QString closing_bal_amt,closing_bal_amt_type;
            loads = "0";
            pay = "0";
            if(databaseObj->selectQuery("select (transaction_master.vehicle_no),is_payment from transaction_master where transaction_master.is_void is null and transaction_master.day_no='"+lst_day_no.at(i)+"' and transaction_master.vehicle_no='"+selected_vehicle_number+"' and transaction_master.cus_name='"+selected_cus_name+"'",load_qur))
            {
                if(load_qur.next())
                {
                    qDebug()<<"test 1 ===>>>";
                    if(load_qur.value(1).toInt() == 0)
                    {
                        qDebug()<<"test 2 ===>>>";

                        loads = QString::number(loads.toInt()+1);
                        qDebug()<<"test 3 ===>>>"<<loads;


                    }
                    else
                    {
                        pay = QString::number(pay.toInt()+1);
                    }
                    while(load_qur.next())
                    {
                        if(load_qur.value(1).toInt() == 0)
                        {
                            loads = QString::number(loads.toInt()+1);
                            qDebug()<<"test 4 ===>>>"<<loads;
                        }
                        else
                        {
                            pay = QString::number(pay.toInt()+1);
                        }
                    }
                }

            }
            total_load += loads.toInt();
            if(loads.toInt() == 0 && pay.toInt() == 0)
            {
                qDebug()<<"in continue i ===>>>"<<i<<lst_day_no.at(i);
//                lst_day_no.removeAt(i);
//                lst_day_no_date.removeAt(i);

                continue;
            }
            qDebug()<<"out continue i ===>>>"<<i<<lst_day_no.at(i);



            QSqlQuery husk_qur;
            if(databaseObj->selectQuery("select sum(transaction_master.inward_hush),sum(transaction_master.paid),sum(transaction_master.approved_amt) from transaction_master where transaction_master.is_void is null and transaction_master.vehicle_no='"+selected_vehicle_number+"' and transaction_master.cus_name='"+selected_cus_name+"' and transaction_master.day_no='"+lst_day_no.at(i)+"'",husk_qur))
            {
                if(husk_qur.next())
                {
                    husk = husk_qur.value(0).toString().trimmed();
                    paid = husk_qur.value(1).toString().trimmed();
                    app_amt = husk_qur.value(2).toString().trimmed();

                    total_husk += husk.toInt();
                    total_paid += paid.toFloat();
                    total_approved += app_amt.toFloat();
                }
            }

            QSqlQuery closing_bal;
            if(databaseObj->selectQuery("select transaction_master.balance,cast(transaction_master.balance_type as integer) from transaction_master where transaction_master.is_void is null and transaction_master.day_no='"+lst_day_no.at(i)+"' and rowid=(select max(rowid ) from transaction_master where transaction_master.is_void is null and transaction_master.day_no='"+lst_day_no.at(i)+"' and transaction_master.vehicle_no='"+selected_vehicle_number+"' and transaction_master.cus_name='"+selected_cus_name+"') and transaction_master.vehicle_no='"+selected_vehicle_number+"' and transaction_master.cus_name='"+selected_cus_name+"'",closing_bal))
            {
                if(closing_bal.next())
                {
                    closing_bal_amt = closing_bal.value(0).toString().trimmed();
                    closing_bal_amt_type = closing_bal.value(1).toString().trimmed();
                    qDebug()<<"closing_bal_amt ===>>>"<<closing_bal_amt;
                    qDebug()<<"closing_bal_amt_type ===>>>"<<closing_bal_amt_type;

                    //                    if(i == lst_day_no.size()-1)
                    {
                        if(closing_bal_amt_type.contains("0") || closing_bal_amt_type.contains("2"))
                        {
                            total_closing = closing_bal_amt.toFloat();
                            balance_sign = "+";
                        }
                        if(closing_bal_amt_type.contains("1"))
                        {
                            total_closing = closing_bal_amt.toFloat();
                            balance_sign = "-";
                        }
                    }
                    qDebug()<<"balance_sign ===>>>"<<balance_sign;
                }
            }

            QString to_print = lst_day_no_date.at(i).rightJustified(5,' ',1)+" "+loads.rightJustified(4,' ',1)+" "+husk.rightJustified(6,' ',1)+" "+app_amt.rightJustified(6,' ',1)+" "+paid.rightJustified(6,' ',1)+" "+closing_bal_amt.prepend(balance_sign).rightJustified(6,' ',1);
            qDebug()<<"supplier report ===>>>"<<to_print;
            print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            //            LOOP:qDebug()<<"only loop ===>>>";
        }
        QString total;
        total = "Total "+QString::number(total_load).rightJustified(3,' ',1)+" "+QString::number(total_husk).rightJustified(6,' ',1)+" "+QString::number(total_approved).rightJustified(6,' ',1)+" "+QString::number(total_paid,'f',0).rightJustified(6,' ',1);
        //        if(total_closing >= 0)
        //        else
        //            total = "Total "+QString::number(total_load).rightJustified(3,' ',1)+" "+QString::number(total_husk).rightJustified(6,' ',1)+" "+QString::number(total_values).rightJustified(6,' ',1)+" "+QString::number(total_paid,'f',0).rightJustified(6,' ',1)+QString::number(total_closing).remove("-").prepend("-").rightJustified(6,' ',1);
        qDebug()<<"supplier report total ===>>>"<<total;
        print.addData(total,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);


        print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
        print.addData("CLOSING BALANCE:Rs."+QString::number(total_closing).prepend(balance_sign),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
        print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
        print.addData("Average Rate   :Rs."+QString::number(total_approved/total_load)+" /load",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
        print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

        //        float supplier_husk,supplier_amt = 0;
        //        for(int i=0;i<lst_day_no.size();i++)
        //        {
        //            if(databaseObj->selectQuery("select day_master.open_date,vehicle_no,cus_name,(inward_bale),(inward_hush),paid,balance,balance_type from transaction_master inner join day_master on transaction_master.day_no = day_master.day_no where cus_name='"+selected_cus_name+"' and batch_type='"+selected_vehicle_type+"' and vehicle_no='"+selected_vehicle_number+"' and is_payment='0' and transaction_master.day_no='"+lst_day_no.at(i)+"'",supplier_qur))
        //            {
        //                if(supplier_qur.next())
        //                {
        //                    QString balance_name = "";
        //                    QString str_supplier_husk,str_supplier_amt;
        //                    if(supplier_qur.value(7).toString().trimmed().toInt() == 0)
        //                        balance_name = "+";
        //                    if(supplier_qur.value(7).toString().trimmed().toInt() == 1)
        //                        balance_name = "-";

        //                    str_supplier_husk = supplier_qur.value(4).toString().trimmed();
        //                    str_supplier_amt = supplier_qur.value(5).toString().trimmed();
        //                    QString print_data = supplier_qur.value(0).toString().trimmed().leftJustified(10,' ',true)+" "+str_supplier_husk.trimmed().rightJustified(7,' ',true)+" "+str_supplier_amt.trimmed().rightJustified(9,' ',true)+" "+supplier_qur.value(6).toString().trimmed().prepend(balance_name).rightJustified(8,' ',true);
        //                    qDebug()<<"suppiler print data ===>>>"<<print_data;




        //                    print.addData(print_data,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

        //                    supplier_husk += str_supplier_husk.toFloat();
        //                    supplier_amt += str_supplier_amt.toFloat();

        //                    while(supplier_qur.next())
        //                    {
        //                        QString balance_name = "";
        //                        QString str_supplier_husk,str_supplier_amt;
        //                        if(supplier_qur.value(7).toString().trimmed().toInt() == 0)
        //                            balance_name = "+";
        //                        if(supplier_qur.value(7).toString().trimmed().toInt() == 1)
        //                            balance_name = "-";

        //                        str_supplier_husk = supplier_qur.value(4).toString().trimmed();
        //                        str_supplier_amt = supplier_qur.value(5).toString().trimmed();
        //                        QString print_data = supplier_qur.value(0).toString().trimmed().leftJustified(10,' ',true)+" "+str_supplier_husk.trimmed().rightJustified(7,' ',true)+" "+str_supplier_amt.trimmed().rightJustified(9,' ',true)+" "+supplier_qur.value(6).toString().trimmed().prepend(balance_name).rightJustified(8,' ',true);
        //                        qDebug()<<"suppiler print data ===>>>"<<print_data;

        //                        print.addData(print_data,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

        //                        supplier_husk += str_supplier_husk.toFloat();
        //                        supplier_amt += str_supplier_amt.toFloat();
        //                    }
        //                }
        //            }
        //            supplier_qur.clear();
        //            if(databaseObj->selectQuery("select day_master.open_date,vehicle_no,cus_name,(inward_bale),(inward_hush),paid,balance,balance_type from transaction_master inner join day_master on transaction_master.day_no = day_master.day_no where cus_name='"+selected_cus_name+"' and batch_type='"+selected_vehicle_type+"' and vehicle_no='"+selected_vehicle_number+"' and is_payment='1' and transaction_master.day_no='"+lst_day_no.at(i)+"'",supplier_qur))
        //            {
        //                if(supplier_qur.next())
        //                {
        //                    QString balance_name = "";
        //                    QString str_supplier_husk,str_supplier_amt;
        //                    if(supplier_qur.value(7).toString().trimmed().toInt() == 0)
        //                        balance_name = "+";
        //                    if(supplier_qur.value(7).toString().trimmed().toInt() == 1)
        //                        balance_name = "-";

        //                    str_supplier_husk = supplier_qur.value(4).toString().trimmed();
        //                    str_supplier_amt = supplier_qur.value(5).toString().trimmed();
        //                    QString print_data = supplier_qur.value(0).toString().trimmed().leftJustified(10,' ',true)+" "+str_supplier_husk.trimmed().rightJustified(7,' ',true)+" "+str_supplier_amt.trimmed().rightJustified(9,' ',true)+" "+supplier_qur.value(6).toString().trimmed().prepend(balance_name).rightJustified(8,' ',true);
        //                    qDebug()<<"suppiler print data ===>>>"<<print_data;

        //                    print.addData(print_data,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

        //                    supplier_husk += str_supplier_husk.toFloat();
        //                    supplier_amt += str_supplier_amt.toFloat();
        //                }

        //                while(supplier_qur.next())
        //                {
        //                    QString balance_name = "";
        //                    QString str_supplier_husk,str_supplier_amt;
        //                    if(supplier_qur.value(7).toString().trimmed().toInt() == 0)
        //                        balance_name = "+";
        //                    if(supplier_qur.value(7).toString().trimmed().toInt() == 1)
        //                        balance_name = "-";

        //                    str_supplier_husk = supplier_qur.value(4).toString().trimmed();
        //                    str_supplier_amt = supplier_qur.value(5).toString().trimmed();
        //                    QString print_data = supplier_qur.value(0).toString().trimmed().leftJustified(10,' ',true)+" "+str_supplier_husk.trimmed().rightJustified(7,' ',true)+" "+str_supplier_amt.trimmed().rightJustified(9,' ',true)+" "+supplier_qur.value(6).toString().trimmed().prepend(balance_name).rightJustified(8,' ',true);
        //                    qDebug()<<"suppiler print data ===>>>"<<print_data;

        //                    print.addData(print_data,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

        //                    supplier_husk += str_supplier_husk.toFloat();
        //                    supplier_amt += str_supplier_amt.toFloat();
        //                }
        //            }
        //        }

        print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
        print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
        print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
        print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

        if(print.print(false,false))
        {

        }
        call_Report();
        //        if(supplier_husk > 0)
        //        {
        //            print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
        //            print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
        //            print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
        //            print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

        //            if(print.print(false,false))
        //            {

        //            }
        //            call_Report();
        //        }
        //        else
        //        {
        //            //! msg
        //        }



    }
    else
    {
        //! no result for supplier
    }
    return true;

}

void Report::on_pushButton_bale_clicked()
{
    ui->groupBox->hide();
    ui->groupBox_bale_production->show();
    ui->groupBox_bale_production->raise();

    ui->dateEdit_from_bale_production->setFocus();

}

//void Report::on_comboBox_batch_currentTextChanged(const QString &arg1)
//{
//    qDebug()<<"on_comboBox_batch_currentIndexChanged ===>>>";
//    ui->label_purchase->clear();
//    ui->label_husk_bale->clear();
//    ui->label_bale->clear();
//    ui->label_purchase->clear();
//    ui->label_gain_lose->clear();
//}

void Report::on_lineEdit_batch_supplier_returnPressed()
{

}

void Report::on_lineEdit_day_no_returnPressed()
{

#if(SDK75)
    QSqlQuery day_details;
    QString report_day_no;
    if(databaseObj->selectQuery("SELECT day_no,status,open_date,open_time,close_date,close_time,open_bull_reading,open_gen_reading,open_eb_reading,open_diesel_reading,opening_bale_balance FROM day_master WHERE id_day= (SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"')",day_details))
    {
        //#if(SDK75)
        if(day_details.next())
        {
            CPrinter print;
            print.setFontType(CPrinter::eFontType_font2);

            print.addData("Day Close Report",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);

            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            print.addData("Day No    :"+day_details.value(0).toString(),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            report_day_no = day_details.value(0).toString().trimmed();
            print.addData("Open Date :"+day_details.value(2).toString(),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            print.addData("Open Time :"+day_details.value(3).toString(),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            print.addData("Close Date:"+day_details.value(4).toString(),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            print.addData("Close Time:"+day_details.value(5).toString(),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

            day_details.clear();
            QStringList lst_aval_batch_type;
            QString total_husk;
            QString rate_of_husk;

            if(databaseObj->selectQuery("select transaction_master.batch_type from transaction_master where transaction_master.is_void is null and transaction_master.day_no=(SELECT day_no FROM day_master WHERE id_day=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"')) and transaction_master.is_payment=0 group by transaction_master.batch_type",day_details))
            {
                if(day_details.next())
                {
                    lst_aval_batch_type << day_details.value(0).toString().trimmed();
                    while(day_details.next())
                    {
                        lst_aval_batch_type << day_details.value(0).toString().trimmed();
                    }
                    qDebug()<<"avaliable batched ===>>>"<<lst_aval_batch_type;
                }
            }
            float t_husk = 0;
            if(lst_aval_batch_type.size() > 0)
            {
                print.addData("Purchase Report Details",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);

                print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                print.addData("TYPE  LOADS  T.CFT  T.HUSK    RUN KMS ",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);


                int t_loads=0;
                float t_cft =0;
                int t_kms = 0;

                for(int i=0;i<lst_aval_batch_type.size();i++)
                {
                    day_details.clear();

                    if(lst_aval_batch_type.at(i).toInt() == 0)
                        rate_of_husk = "rate_of_husk";

                    if(lst_aval_batch_type.at(i).toInt() == 1)
                        rate_of_husk = "auto_rate_of_husk";

                    if(lst_aval_batch_type.at(i).toInt() == 2)
                        rate_of_husk = "van_rate_of_husk";

                    qDebug()<<"lst_aval_batch_type ===>>>"<<lst_aval_batch_type.at(i);

                    if(databaseObj->selectQuery("select batch_type,count(transaction_master.batch_type) as no_of_loads,sum(transaction_master.inward_bale) as total_cft,sum(transaction_master.inward_hush) as total_husk,sum(transaction_master.excess_amt) as excess,sum(transaction_master.approved_amt) as approved_amt,round(sum(transaction_master.inward_hush)/sum(transaction_master.approved_amt),2) as rate_per_husk,sum(transaction_master.vkms) as vkms from transaction_master where transaction_master.is_void is null and transaction_master.batch_type='"+lst_aval_batch_type.at(i)+"'  and day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"'))",day_details))
                    {
                        if(day_details.next())
                        {
                            QString batch_name,to_print;
                            if(lst_aval_batch_type.at(i).toInt() == 0)
                                batch_name = "Comp";
                            if(lst_aval_batch_type.at(i).toInt() == 1)
                                batch_name = "Auto";
                            if(lst_aval_batch_type.at(i).toInt() == 2)
                                batch_name = "Van";

                            to_print = batch_name.leftJustified(4,' ',1)+"  "+day_details.value(1).toString().trimmed().rightJustified(6,' ')+"  "+day_details.value(2).toString().trimmed().rightJustified(6,' ',1)+"  "+day_details.value(3).toString().trimmed().rightJustified(7,' ',1)+"  "+day_details.value(7).toString().trimmed().rightJustified(7,' ',1);

                            t_loads += day_details.value(1).toInt();
                            t_cft += day_details.value(2).toFloat();
                            t_husk += day_details.value(3).toInt();
                            t_kms += day_details.value(7).toInt();
                            qDebug()<<"to_print ===>>>"<<to_print;

                            print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                        }
                    }
                }
                QString total_print;
                total_print = "Total "+QString::number(t_loads).rightJustified(6,' ')+"  "+QString::number(t_cft,'f',2).rightJustified(6,' ',1)+"  "+QString::number(t_husk).rightJustified(7,' ',1)+"  "+QString::number(t_kms).rightJustified(7,' ',1);
                print.addData(total_print,CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
                print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            }


            //! PURCHASE VALUE DETAILS

            print.addData("Purchase Value Details",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);

            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            print.addData("TYPE QUANTITY HUSKRATE  AMOUNT  EXCESS",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

            float pv_rate_of_husk = 0;
            float pv_amt = 0;
            int pv_excess =0;
            int count = 0;


            for(int i=0;i<lst_aval_batch_type.size();i++)
            {
                day_details.clear();

                if(lst_aval_batch_type.at(i).toInt() == 0)
                    rate_of_husk = "rate_of_husk";

                if(lst_aval_batch_type.at(i).toInt() == 1)
                    rate_of_husk = "auto_rate_of_husk";

                if(lst_aval_batch_type.at(i).toInt() == 2)
                    rate_of_husk = "van_rate_of_husk";

                if(databaseObj->selectQuery("select batch_type,count(transaction_master.batch_type) as no_of_loads,sum(transaction_master.inward_bale) as total_cft,sum(transaction_master.inward_hush) as total_husk,sum(transaction_master.excess_amt) as excess,sum(transaction_master.approved_amt) as approved_amt,round(sum(transaction_master.approved_amt)/sum(transaction_master.inward_hush),2) as rate_per_husk,sum(transaction_master.vkms) as vkms from transaction_master where transaction_master.is_void is null and transaction_master.batch_type='"+lst_aval_batch_type.at(i)+"' and day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"'))",day_details))
                {
                    if(day_details.next())
                    {
                        QString batch_name,to_print;
                        if(lst_aval_batch_type.at(i).toInt() == 0)
                            batch_name = "Comp";
                        if(lst_aval_batch_type.at(i).toInt() == 1)
                            batch_name = "Auto";
                        if(lst_aval_batch_type.at(i).toInt() == 2)
                            batch_name = "Van";

                        to_print = batch_name.leftJustified(5,' ',1)+" "+day_details.value(3).toString().trimmed().rightJustified(8,' ')+" "+day_details.value(6).toString().trimmed().rightJustified(8,' ',1)+" "+day_details.value(5).toString().trimmed().rightJustified(7,' ',1)+" "+day_details.value(4).toString().trimmed().rightJustified(6,' ',1);
                        count += 1;
                        pv_rate_of_husk += day_details.value(6).toFloat();
                        pv_amt += day_details.value(5).toInt();
                        pv_excess += day_details.value(4).toInt();


                        qDebug()<<"to_print ===>>>"<<to_print;

                        print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                    }
                }
            }
            QString pv_total_print;

            qDebug()<<"pv_total_print ===>>>"<<QString::number(pv_amt/t_husk);
            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            pv_total_print = QString("Avg & Total :").leftJustified(14,' ',1)+" "+QString::number(pv_amt/t_husk,'f',2).rightJustified(8,' ')+" "+QString::number(pv_amt).rightJustified(6,' ',1)+" "+QString::number(pv_excess).rightJustified(6,' ',1);
            print.addData(pv_total_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);



            //! PRODUCTION DETAILS

            QSqlQuery production_details_qur;
            if(databaseObj->selectQuery("select day_master.day_no,day_master.open_date,day_master.opening_bale_balance,sum(bale_produced),bale_dispatched,bale_dispatched_to,closing_balance from day_close inner join day_master on day_master.day_no = day_close.day_no where day_close.day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"'",production_details_qur))
            {
                if(production_details_qur.next())
                {

                    print.addData("Production Details",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
                    print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                    print.addData("Opening Bale      : "+production_details_qur.value(2).toString().trimmed()+" Nos",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                    print.addData("Bale Produced     : "+production_details_qur.value(3).toString().trimmed()+" Nos",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);


                    QSqlQuery batch_wise_qur;
                    if(databaseObj->selectQuery("select * from day_close where day_close.day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"'",batch_wise_qur))
                    {
                        if(batch_wise_qur.next())
                        {

                            print.addData(batch_wise_qur.value(1).toString().toUpper().leftJustified(7,' ',1)+" "+QString::number(batch_wise_qur.value(2).toInt()).rightJustified(4,'0',1)+" :"+batch_wise_qur.value(3).toString()+" Nos",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                            while(batch_wise_qur.next())
                            {
                                print.addData(batch_wise_qur.value(1).toString().toUpper().leftJustified(7,' ',1)+" "+QString::number(batch_wise_qur.value(2).toInt()).rightJustified(4,'0',1)+" :"+batch_wise_qur.value(3).toString()+" Nos",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                            }

                        }
                    }

                    print.addData("Bale Dispatched   : "+production_details_qur.value(4).toString().trimmed()+" Nos",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                    print.addData("Bale Dispatched To: "+production_details_qur.value(5).toString().trimmed(),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                    print.addData("Bale Closing Stock: "+production_details_qur.value(6).toString().trimmed(),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

                    print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                }
            }






            //! CASH FLOW DETAILS
            print.addData("Cash Flow Details",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);




            int husk_pay = 0;
            for(int i=0;i<lst_aval_batch_type.size();i++)
            {
                day_details.clear();

                if(lst_aval_batch_type.at(i).toInt() == 0)
                    rate_of_husk = "rate_of_husk";

                if(lst_aval_batch_type.at(i).toInt() == 1)
                    rate_of_husk = "auto_rate_of_husk";

                if(lst_aval_batch_type.at(i).toInt() == 2)
                    rate_of_husk = "van_rate_of_husk";

                if(databaseObj->selectQuery("select batch_type,count(transaction_master.batch_type) as no_of_loads,sum(transaction_master.paid) as paid from transaction_master where transaction_master.is_void is null and transaction_master.batch_type='"+lst_aval_batch_type.at(i)+"'",day_details))
                {

                    if(day_details.next())
                    {
                        QString batch_name,to_print;
                        if(lst_aval_batch_type.at(i).toInt() == 0)
                            batch_name = "Comp";
                        if(lst_aval_batch_type.at(i).toInt() == 1)
                            batch_name = "Auto";
                        if(lst_aval_batch_type.at(i).toInt() == 2)
                            batch_name = "Van";

                        husk_pay += day_details.value(2).toInt();
                    }
                }
            }

            QSqlQuery cash_balance;
            if(databaseObj->selectQuery("select day_master.opening_cash,day_master.closing_cash from day_master where id_day=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"')",cash_balance))
            {
                if(cash_balance.next())
                {
                    print.addData("Opening Cash Balance:Rs "+cash_balance.value(0).toString().trimmed().rightJustified(8,' ',1),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_RIGHT);
                }
            }

            QSqlQuery cash_receipt;
            if(databaseObj->selectQuery("select sum(cash_from_transaction.cash_recv) from cash_from_transaction where cash_from_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"'))",cash_receipt))
            {
                if(cash_receipt.next())
                {
                    print.addData("COMPANY CASH RCPT:Rs "+cash_receipt.value(0).toString().trimmed().rightJustified(8,' ',1),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_RIGHT);
                }
            }

            //                cash_balance.clear();
            //                if(databaseObj->selectQuery("select cash_from_transaction.user_name,user_master.name,cash_from_transaction.date_time,cash_from_transaction.cash_recv from cash_from_transaction inner join user_master on user_master.user_name=cash_from_transaction.user_name where cash_from_transaction.cash_from='Company' and day_no=(select day_master.day_no from day_master where day_master.id_day=id_day=(SELECT MAX(id_day) FROM day_master where status='1' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"'))",cash_balance))
            //                {
            //                    int tot_cash_received = 0;
            //                    if(cash_balance.next())
            //                    {
            //                        print.addData("Company Cash Receipt",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_RIGHT);
            //                        print.addData(cash_balance.value(2).toString().right(20,' ',1)+" "+cash_balance.value(1).toString().trimmed().leftJustified(10,' ',1)+" "+cash_balance.value(3).toString().trimmed().rightJustified(7,' ',1),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            //                        tot_cash_received += cash_balance.value(3).toInt();
            //                        while(cash_balance.next())
            //                        {
            //                            print.addData(cash_balance.value(2).toString().right(20,' ',1)+" "+cash_balance.value(1).toString().trimmed().leftJustified(10,' ',1)+" "+cash_balance.value(3).toString().trimmed().rightJustified(7,' ',1),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            //                            tot_cash_received += cash_balance.value(3).toInt();
            //                        }
            //                        print.addData("Total Cash Received: Rs "+QString::number(tot_cash_received),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_RIGHT);
            //                    }
            //                }
            //                if(husk_pay > 0)
            //                {
            //                    print.addData("Husk Payment: Rs"+QString::number(husk_pay),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            //                }

            QSqlQuery payables_qur;
            QString v_pay = "0";
            float total_exp_amt = 0;
            QStringList lst_v_no,lst_party_name,lst_amt;
            payables_qur.clear();
            if(databaseObj->selectQuery("select vehicle_no,cus_name,paid from transaction_master where transaction_master.is_void is null and day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"')) and paid > 0",payables_qur))
            {
                if(payables_qur.next())
                {
                    lst_v_no << payables_qur.value(0).toString().trimmed();
                    lst_party_name << payables_qur.value(1).toString().trimmed();
                    lst_amt << payables_qur.value(2).toString().trimmed();
                    while(payables_qur.next())
                    {
                        lst_v_no << payables_qur.value(0).toString().trimmed();
                        lst_party_name << payables_qur.value(1).toString().trimmed();
                        lst_amt << payables_qur.value(2).toString().trimmed();
                    }
                }
                if(lst_v_no.size() > 0)
                {
                    print.addData("Husk Payment",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
                    print.addData("Vehicle No    Party Name       Amount",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

                    for(int i=0;i<lst_v_no.size();i++)
                    {
                        print.addData(lst_v_no.at(i).leftJustified(11,' ',1)+" "+lst_party_name.at(i).remove(" ").leftJustified(15,' ',1)+" "+QString::number(lst_amt.at(i).toFloat(),'f',2).rightJustified(10,' ',1),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                    }
                    payables_qur.clear();
                    if(databaseObj->selectQuery("select sum(paid) from transaction_master where transaction_master.is_void is null and day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"'))",payables_qur))
                    {
                        if(payables_qur.next())
                        {
                            v_pay = payables_qur.value(0).toString().trimmed();
                        }
                    }
                }
            }


            QSqlQuery bunk_qur;
            QString bunk_pay = "0";
            QStringList lst_bunk_name,lst_bunk_qty,lst_bunk_amount;
            if(databaseObj->selectQuery("select diesel_transaction.bunk_id,bunk_master.bunk_name,diesel_transaction.quantity,diesel_transaction.amount from diesel_transaction inner join bunk_master on diesel_transaction.bunk_id=bunk_master.id_bunk_master where day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0' and is_payment='1' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"'))",bunk_qur))
            {
                if(bunk_qur.next())
                {
                    lst_bunk_name << bunk_qur.value(1).toString().trimmed();
                    lst_bunk_qty << bunk_qur.value(2).toString().trimmed();
                    lst_bunk_amount << bunk_qur.value(3).toString().trimmed();
                    while(bunk_qur.next())
                    {
                        lst_bunk_name << bunk_qur.value(1).toString().trimmed();
                        lst_bunk_qty << bunk_qur.value(2).toString().trimmed();
                        lst_bunk_amount << bunk_qur.value(3).toString().trimmed();
                    }
                }

                if(lst_bunk_name.size() > 0)
                {
                    print.addData("Bunk Payment",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
                    for(int i=0;i<lst_bunk_name.size();i++)
                    {
                        print.addData("            "+lst_bunk_name.at(i).leftJustified(15,' ')+" "+QString::number(lst_bunk_amount.at(i).rightJustified(10,' ').toFloat(),'f',2),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                    }
                    bunk_qur.clear();
                    if(databaseObj->selectQuery("select sum(diesel_transaction.amount) from diesel_transaction where day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"')) and is_payment='1'",bunk_qur))
                    {
                        if(bunk_qur.next())
                        {
                            bunk_pay = bunk_qur.value(0).toString().trimmed();
                        }
                    }
                }
            }

            QSqlQuery emp_qur;
            QString emp_pay = "0";
            QStringList lst_emp_name,lst_emp_amount;
            if(databaseObj->selectQuery("select emp_name,paid_salary from employee_transaction where paid_salary IS NOT NULL and day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"'))",emp_qur))
            {
                if(emp_qur.next())
                {
                    lst_emp_name << emp_qur.value(0).toString().trimmed();
                    lst_emp_amount << emp_qur.value(1).toString().trimmed();
                    while(emp_qur.next())
                    {
                        lst_emp_name << emp_qur.value(0).toString().trimmed();
                        lst_emp_amount << emp_qur.value(1).toString().trimmed();
                    }
                }
                if(lst_emp_name.size() > 0)
                {
                    print.addData("Labour Payment",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
                    for(int i=0;i<lst_emp_name.size();i++)
                    {
                        print.addData("            "+lst_emp_name.at(i).leftJustified(15,' ')+" "+QString::number(lst_emp_amount.at(i).rightJustified(10,' ').toFloat(),'f',2),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                    }
                    emp_qur.clear();
                    if(databaseObj->selectQuery("select sum(paid_salary) from employee_transaction where paid_salary IS NOT NULL and day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"'))",emp_qur))
                    {
                        if(emp_qur.next())
                        {
                            emp_pay = emp_qur.value(0).toString().trimmed();
                        }
                    }
                }
            }

            QSqlQuery expense_qur;
            QStringList lst_expense_name,lst_expense_bill_no,lst_expense_amount,lst_expense_user_id;
            if(databaseObj->selectQuery("select * from expense_transaction where day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"'))",expense_qur))
            {
                if(expense_qur.next())
                {
                    lst_expense_name << expense_qur.value(2).toString().trimmed();
                    lst_expense_bill_no << expense_qur.value(3).toString().trimmed();
                    lst_expense_amount << expense_qur.value(4).toString().trimmed();
                    lst_expense_user_id << expense_qur.value(6).toString().trimmed();
                    while(expense_qur.next())
                    {
                        lst_expense_name << expense_qur.value(2).toString().trimmed();
                        lst_expense_bill_no << expense_qur.value(3).toString().trimmed();
                        lst_expense_amount << expense_qur.value(4).toString().trimmed();
                        lst_expense_user_id << expense_qur.value(6).toString().trimmed();
                    }
                }
            }

            if(lst_expense_name.size() > 0)
            {
                print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                print.addData("Expense",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
                print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                print.addData("   Expense Name          Amount",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);


                for(int i=0;i<lst_expense_name.size();i++)
                {
                    QString prt_text = QString::number(i+1).rightJustified(2,' ')+" "+lst_expense_name.at(i).leftJustified(15,' ')+" "+QString::number(lst_expense_amount.at(i).toFloat(),'f',2).rightJustified(15,' ');
                    qDebug()<<"expense data ===>>>"<<prt_text;
                    print.addData(prt_text,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                    total_exp_amt += lst_expense_amount.at(i).toFloat();
                }
                //                    print.addData("Total Expense: "+QString::number(total_exp_amt,'f',2),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
            }
            if( (lst_v_no.size() != 0) || (lst_bunk_name.size() != 0) || (lst_emp_name.size() != 0) || total_exp_amt > 0)
            {
                print.addData("Total :Rs "+QString::number(v_pay.toFloat() + emp_pay.toFloat() + bunk_pay.toFloat() + total_exp_amt,'f',2 ),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
            }


            QSqlQuery closing_cash_balance;
            if(databaseObj->selectQuery("select day_master.opening_cash,day_master.closing_cash from day_master where id_day=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"')",closing_cash_balance))
            {
                if(closing_cash_balance.next())
                {
                    print.addData("Closing Cash Balance:Rs "+closing_cash_balance.value(1).toString().trimmed().rightJustified(8,' ',1),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_RIGHT);
                }
            }
            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);


//            print.addData("Stock Status Report",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
//            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

//            //! today

//            QSqlQuery stock_qur;
//            QStringList lst_stock_batch;
//            lst_stock_batch << "company_batch_no" << "other_batch_no" << "van_batch_no";
//            print.addData(" TYPE   BATCHNO  CFT  NO.OF.HUSK",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
//            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
//            int husk_only = 0;
//            float cft_only = 0;

//            int husk_pro = 0;
//            float cft_pro = 0;

//            for(int i=0;i<lst_stock_batch.size();i++)
//            {
//                QStringList lst_stock_batch_no,lst_stock_batch_cft,lst_stock_batch_husk;
//                QString stock_purchase,stock_production;
//                QString pro_batch_name;
//                if(databaseObj->selectQuery("select batch_no,total_husk_produced,inward_stock from "+lst_stock_batch.at(i)+" where production_status='2'",stock_qur))
//                {

//                    if(stock_qur.next())
//                    {
//                        lst_stock_batch_no << stock_qur.value(0).toString().trimmed();
//                        lst_stock_batch_husk << stock_qur.value(1).toString().trimmed();
//                        lst_stock_batch_cft << stock_qur.value(2).toString().trimmed();
//                        while(stock_qur.next())
//                        {
//                            lst_stock_batch_no << stock_qur.value(0).toString().trimmed();
//                            lst_stock_batch_husk << stock_qur.value(1).toString().trimmed();
//                            lst_stock_batch_cft << stock_qur.value(2).toString().trimmed();
//                        }

//                        if(lst_stock_batch.at(i).contains("company_batch_no"))
//                            pro_batch_name = "Comp Husk";
//                        if(lst_stock_batch.at(i).contains("other_batch_no"))
//                            pro_batch_name = "Auto Husk";
//                        if(lst_stock_batch.at(i).contains("van_batch_no"))
//                            pro_batch_name = "Van Husk ";

//                        for(int p=0;p<lst_stock_batch_no.size();p++)
//                            print.addData(pro_batch_name.leftJustified(9,' ',1)+" "+lst_stock_batch_no.at(p).rightJustified(4,'0').rightJustified(7,' ',1)+" "+lst_stock_batch_cft.at(p).rightJustified(7,' ',1)+" "+lst_stock_batch_husk.at(p).rightJustified(10,' ',1),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);




//                    }

//                }
//                QString pro_batch_name1;
//                if(lst_stock_batch.at(i).contains("company_batch_no"))
//                    pro_batch_name1 = "company";
//                if(lst_stock_batch.at(i).contains("other_batch_no"))
//                    pro_batch_name1 = "auto";
//                if(lst_stock_batch.at(i).contains("van_batch_no"))
//                    pro_batch_name1 = "van";
//                stock_qur.clear();
//                if(databaseObj->selectQuery("select batch_no,husk_available,batch_type from production_batch_order where batch_type='"+pro_batch_name1+"'",stock_qur))
//                {
//                    if(stock_qur.next())
//                    {

//                        QString pro_batch_name2;
//                        if(stock_qur.value(2).toString().contains("company"))
//                            pro_batch_name2 = "Company";
//                        if(stock_qur.value(2).toString().contains("auto"))
//                            pro_batch_name2 = "Auto";
//                        if(stock_qur.value(2).toString().contains("van"))
//                            pro_batch_name2 = "Van";

//                        int tmp_husk = stock_qur.value(1).toInt();
//                        husk_pro += tmp_husk;
//                        cft_pro += (tmp_husk/Home_ScreenObj->HP_cft.toFloat());
//                        print.addData(pro_batch_name2.leftJustified(9,' ',1)+" "+stock_qur.value(0).toString().trimmed().rightJustified(4,'0').rightJustified(7,' ',1)+" "+QString::number(stock_qur.value(1).toInt()/Home_ScreenObj->HP_cft.toInt()).rightJustified(7,' ',1)+" "+stock_qur.value(1).toString().rightJustified(10,' ',1),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
//                        while(stock_qur.next())
//                        {

//                            QString pro_batch_name2;
//                            if(stock_qur.value(2).toString().contains("company"))
//                                pro_batch_name2 = "Company";
//                            if(stock_qur.value(2).toString().contains("auto"))
//                                pro_batch_name2 = "Auto";
//                            if(stock_qur.value(2).toString().contains("van"))
//                                pro_batch_name2 = "Van";

//                            int tmp_husk = stock_qur.value(1).toInt();
//                            husk_pro += tmp_husk;
//                            cft_pro += (tmp_husk/Home_ScreenObj->HP_cft.toFloat());
//                            print.addData(pro_batch_name2.leftJustified(9,' ',1)+" "+stock_qur.value(0).toString().trimmed().rightJustified(4,'0').rightJustified(7,' ',1)+" "+QString::number(stock_qur.value(1).toInt()/Home_ScreenObj->HP_cft.toInt()).rightJustified(7,' ',1)+" "+stock_qur.value(1).toString().rightJustified(10,' ',1),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
//                        }
//                        qDebug()<<"cft_pro ===>>>"<<QString::number(cft_pro);
//                    }
//                }

//                stock_qur.clear();

//                if(databaseObj->selectQuery("select sum(total_husk_produced),sum(inward_stock) from "+lst_stock_batch.at(i)+" where production_status='2'",stock_qur))
//                {
//                    if(stock_qur.next())
//                    {
//                        husk_only += stock_qur.value(0).toString().trimmed().toInt();
//                        cft_only += stock_qur.value(1).toString().trimmed().toFloat();
//                        qDebug()<<"cft_only ===>>>"<<QString::number(cft_only);
//                    }
//                }
//            }

//            QString tot_cft_husk = QString("Total").leftJustified(13,' ',1)+" "+QString::number(cft_only+cft_pro).trimmed().rightJustified(8,' ',1)+" "+QString::number(husk_only+husk_pro).trimmed().rightJustified(9,' ',1);
//            qDebug()<<"tot_cft_husk ===>>>"<<tot_cft_husk;
//            print.addData(tot_cft_husk,CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

//            stock_qur.clear();
//            QString closing_bale,closing_husk;
//            int closing_husk1 = 0;
//            if(databaseObj->selectQuery("select closing_bale_balance from day_master where day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"'))",stock_qur))
//            {
//                if(stock_qur.next())
//                {
//                    closing_bale = stock_qur.value(0).toString().trimmed();
//                    closing_husk = QString::number(closing_bale.toFloat()*Home_ScreenObj->HP_bale.toFloat(),'f',2);
//                    closing_husk1 = (closing_bale.toInt()*Home_ScreenObj->HP_bale.toInt());
//                    qDebug()<<"closing_husk1 ===>>>"<<QString::number(closing_husk1);
//                }
//            }
//            //                float total_husk_count = husk_available_production.toFloat()+closing_husk.toFloat();
//            print.addData(QString("Bale").leftJustified(13,' ',1)+" "+closing_bale.trimmed().append(" Nos").rightJustified(8,' ',1)+" "+closing_husk.trimmed().rightJustified(9,' ',1),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
//            print.addData("Total Husk In Stock "+QString::number(husk_only+husk_pro+closing_husk1).trimmed().rightJustified(9,' ',1),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
//            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

            QSqlQuery diesel_report_qur;
            print.addData("Diesel Consumption",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

            if(databaseObj->selectQuery("select open_diesel_reading,close_diesel_reading from day_master where day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"'))",diesel_report_qur ))
            {
                if(diesel_report_qur.next())
                {
                    print.addData("OPENING STOCK  : "+diesel_report_qur.value(0).toString().trimmed()+" Lts",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                }
            }

            diesel_report_qur.clear();
            if(databaseObj->selectQuery("select sum(diesel_transaction.quantity) from diesel_transaction where day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"'))",diesel_report_qur ))
            {
                if(diesel_report_qur.next())
                {
                    print.addData("TODAY PURCHASE : "+diesel_report_qur.value(0).toString().trimmed()+" Lts",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                }
            }

            diesel_report_qur.clear();
            if(databaseObj->selectQuery("select sum(diesel_usage.quantity) from diesel_usage where day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"'))",diesel_report_qur ))
            {
                if(diesel_report_qur.next())
                {
                    print.addData("CONSUMPTION    : "+diesel_report_qur.value(0).toString().trimmed()+" Lts",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                }
            }

            diesel_report_qur.clear();
            if(databaseObj->selectQuery("select diesel_usage.vehicle_no,sum(diesel_usage.quantity),diesel_usage.fill_type from diesel_usage where diesel_usage.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"')) group by diesel_usage.vehicle_no",diesel_report_qur))
            {
                if(diesel_report_qur.next())
                {
                    //! new
                    QString vehicle_no;
                    QString vehicle_consumption;
                    vehicle_no = diesel_report_qur.value(0).toString().trimmed();
                    vehicle_consumption = diesel_report_qur.value(1).toString().trimmed();

                    QString diesel_to_print;
                    QString millage;
                    QString unit;
                    if(vehicle_no.contains("bull",Qt::CaseInsensitive) || vehicle_no.contains("generator",Qt::CaseInsensitive))
                    {
                        unit = "Lts/Hr";
                        if(get_difference(vehicle_no).toFloat() > 0)
                        {
                            millage = QString::number(get_voulume(vehicle_no,report_day_no).toFloat()/get_difference(vehicle_no).toFloat());
                        }
                    }
                    else
                    {
                        unit = "km/lt";
                        if(get_difference(vehicle_no).toFloat() > 0)
                        {
                            millage = QString::number(get_difference(vehicle_no).toFloat()/get_voulume(vehicle_no,report_day_no).toFloat());
                        }
                    }

                    if(!millage.isEmpty())
                        print.addData(vehicle_no.toUpper().leftJustified(12,' ',1)+":"+vehicle_consumption.append("lts")+" Milage:"+millage,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                    else
                        print.addData(vehicle_no.toUpper().leftJustified(12,' ',1)+":"+vehicle_consumption.append("lts"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

                    while(diesel_report_qur.next())
                    {
                        //! new
                        QString vehicle_no;
                        QString vehicle_consumption;
                        vehicle_no = diesel_report_qur.value(0).toString().trimmed();
                        vehicle_consumption = diesel_report_qur.value(1).toString().trimmed();

                        QString diesel_to_print;
                        QString millage;
                        QString unit;
                        if(vehicle_no.contains("bull",Qt::CaseInsensitive) || vehicle_no.contains("generator",Qt::CaseInsensitive))
                        {
                            unit = "Lts/Hr";
                            if(get_difference(vehicle_no).toFloat() > 0)
                            {
                                millage = QString::number(get_voulume(vehicle_no,report_day_no).toFloat()/get_difference(vehicle_no).toFloat());
                            }
                        }
                        else
                        {
                            unit = "km/lt";
                            if(get_difference(vehicle_no).toFloat() > 0)
                            {
                                millage = QString::number(get_difference(vehicle_no).toFloat()/get_voulume(vehicle_no,report_day_no).toFloat());
                            }
                        }

                        if(!millage.isEmpty())
                            print.addData(vehicle_no.toUpper().leftJustified(12,' ',1)+":"+vehicle_consumption.append("lts")+" Milage:"+millage,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                        else
                            print.addData(vehicle_no.toUpper().leftJustified(12,' ',1)+":"+vehicle_consumption.append("lts"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

                    }
                }
            }

            diesel_report_qur.clear();

            if(databaseObj->selectQuery("select open_diesel_reading,close_diesel_reading from day_master where day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"'))",diesel_report_qur ))
            {
                if(diesel_report_qur.next())
                {
                    print.addData("CLOSING STOCK  : "+diesel_report_qur.value(1).toString().trimmed()+" Lts",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                }
            }
            //! METER READING

            QSqlQuery reading_qur;
            if(databaseObj->selectQuery("select sum(day_master.close_bull_reading)-sum(day_master.open_bull_reading) as bull, sum(day_master.close_gen_reading)-sum(day_master.open_gen_reading) as gen, sum(day_master.close_eb_reading)-sum(day_master.open_eb_reading) as eb from day_master where day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"'))",reading_qur))
            {
                if(reading_qur.next())
                {
                    print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                    print.addData("Meter Reading",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
                    print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

                    print.addData("Bull Meter     :"+reading_qur.value(0).toString().trimmed()+" Hrs",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                    print.addData("Generator Meter:"+reading_qur.value(1).toString().trimmed()+" Hrs",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                    print.addData("EB Meter       :"+reading_qur.value(2).toString().trimmed()+" Units",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                }
            }



//            //! LEDGER WISE REPORT


//            float total_op_bal = 0;
//            float total_cl_bal = 0;
//            float total_paid = 0;
//            float total_addition = 0;



//            print.addData("Ledger Wise Report",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
//            print.addData("  LEDGER   OP.BAL TODAY+  PAID  CL.BAL",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
//            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

//            //! supplier
//            print.addData("Supplier Ledger",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
//            QSqlQuery supplier_ledger;
//            if(databaseObj->selectQuery("select transaction_master.vehicle_no,transaction_master.cus_name,min(transaction_master.previous_balance) as op_bal,min(transaction_master.previous_balance_type) as op_bal_type,sum(transaction_master.inward_hush) as inward_husk,sum(transaction_master.approved_amt) as approved_amt,sum(transaction_master.paid) as paid,customer_master.balance,customer_master.balance_type from transaction_master inner join customer_master on customer_master.cus_name=transaction_master.cus_name where transaction_master.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"')) group by transaction_master.cus_name",supplier_ledger))
//            {
//                if(supplier_ledger.next())
//                {
//                    QString to_print;
//                    QString opening_str = "";
//                    QString closing_str = "";


////                    if(supplier_ledger.value(3).toInt() == 0 || supplier_ledger.value(3).toInt() == 2){
////                        opening_str = "+";
////                        total_op_bal += supplier_ledger.value(2).toFloat();
////                    }
////                    if(supplier_ledger.value(3).toInt() == 1){
////                        opening_str = "-";
////                        total_op_bal -= supplier_ledger.value(2).toFloat();
////                    }
//                    QSqlQuery supplier_ledger_op_qur;
//                    if(databaseObj->selectQuery("select transaction_master.previous_balance,transaction_master.previous_balance_type from transaction_master where transaction_master.cus_name='"+supplier_ledger.value(1).toString()+"' and transaction_master.day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"' and rowid=(select min(rowid) from transaction_master where transaction_master.cus_name='"+supplier_ledger.value(1).toString().trimmed()+"' and transaction_master.day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"')",supplier_ledger_op_qur))
//                    {
//                        if(supplier_ledger_op_qur.next())
//                        {
//                            if(supplier_ledger_op_qur.value(1).toInt() == 0 || supplier_ledger_op_qur.value(1).toInt() == 2){
//                                opening_str = "+";
//                                total_op_bal += supplier_ledger_op_qur.value(0).toFloat();
//                            }
//                            if(supplier_ledger_op_qur.value(1).toInt() == 1){
//                                opening_str = "-";
//                                total_op_bal -= supplier_ledger_op_qur.value(0).toFloat();
//                            }

//                        }
//                    }

//                    QSqlQuery closing_supplier_balance;
//                    QString particular_supplier_bal;
//                    if(databaseObj->selectQuery("select transaction_master.balance,transaction_master.balance_type from transaction_master where rowid=(select max(rowid) from transaction_master where transaction_master.vehicle_no='"+supplier_ledger.value(0).toString().trimmed()+"' and transaction_master.cus_name='"+supplier_ledger.value(1).toString().trimmed()+"' and transaction_master.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"')))",closing_supplier_balance))
//                    {
//                        if(closing_supplier_balance.next())
//                        {
//                            particular_supplier_bal = closing_supplier_balance.value(0).toString().trimmed();
//                            if(closing_supplier_balance.value(1).toInt() == 0 || closing_supplier_balance.value(1).toInt() == 2){
//                                closing_str = "+";
//                                total_cl_bal += closing_supplier_balance.value(0).toFloat();
//                            }
//                            if(closing_supplier_balance.value(1).toInt() == 1){
//                                closing_str = "-";
//                                total_cl_bal -= closing_supplier_balance.value(0).toFloat();
//                            }
//                        }
//                    }

//                    total_paid += supplier_ledger.value(6).toFloat();
//                    total_addition += supplier_ledger.value(5).toFloat();

//                    to_print = supplier_ledger.value(1).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger_op_qur.value(0).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+" "+supplier_ledger.value(5).toString().trimmed().rightJustified(6,' ',1)+" "+supplier_ledger.value(6).toString().trimmed().rightJustified(6,' ',1)+particular_supplier_bal.trimmed().prepend(closing_str).rightJustified(7,' ',1);
//                    qDebug()<<"supplier_ledger ===>>>"<<to_print;
//                    print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);



//                    while(supplier_ledger.next())
//                    {
//                        QString to_print;
//                        QString opening_str = "";
//                        QString closing_str = "";


////                        if(supplier_ledger.value(3).toInt() == 0 || supplier_ledger.value(3).toInt() == 2){
////                            opening_str = "+";
////                            total_op_bal += supplier_ledger.value(2).toFloat();
////                        }
////                        if(supplier_ledger.value(3).toInt() == 1){
////                            opening_str = "-";
////                            total_op_bal -= supplier_ledger.value(2).toFloat();
////                        }


//                        QSqlQuery supplier_ledger_op_qur;
//                        if(databaseObj->selectQuery("select transaction_master.previous_balance,transaction_master.previous_balance_type from transaction_master where transaction_master.cus_name='"+supplier_ledger.value(1).toString()+"' and transaction_master.day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"' and rowid=(select min(rowid) from transaction_master where transaction_master.cus_name='"+supplier_ledger.value(1).toString().trimmed()+"' and transaction_master.day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"')",supplier_ledger_op_qur))
//                        {
//                            if(supplier_ledger_op_qur.next())
//                            {
//                                if(supplier_ledger_op_qur.value(1).toInt() == 0 || supplier_ledger_op_qur.value(1).toInt() == 2){
//                                    opening_str = "+";
//                                    total_op_bal += supplier_ledger_op_qur.value(0).toFloat();
//                                }
//                                if(supplier_ledger_op_qur.value(1).toInt() == 1){
//                                    opening_str = "-";
//                                    total_op_bal -= supplier_ledger_op_qur.value(0).toFloat();
//                                }

//                            }
//                        }


//                        QSqlQuery closing_supplier_balance;
//                        QString particular_supplier_bal;
//                        if(databaseObj->selectQuery("select transaction_master.balance,transaction_master.balance_type from transaction_master where rowid=(select max(rowid) from transaction_master where transaction_master.vehicle_no='"+supplier_ledger.value(0).toString().trimmed()+"' and transaction_master.cus_name='"+supplier_ledger.value(1).toString().trimmed()+"' and transaction_master.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"')))",closing_supplier_balance))
//                        {
//                            if(closing_supplier_balance.next())
//                            {
//                                particular_supplier_bal = closing_supplier_balance.value(0).toString().trimmed();
//                                if(closing_supplier_balance.value(1).toInt() == 0 || closing_supplier_balance.value(1).toInt() == 2){
//                                    closing_str = "+";
//                                    total_cl_bal += closing_supplier_balance.value(0).toFloat();
//                                }
//                                if(closing_supplier_balance.value(1).toInt() == 1){
//                                    closing_str = "-";
//                                    total_cl_bal -= closing_supplier_balance.value(0).toFloat();
//                                }
//                            }
//                        }

//                        total_paid += supplier_ledger.value(6).toFloat();
//                        total_addition += supplier_ledger.value(5).toFloat();

//                        to_print = supplier_ledger.value(1).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger_op_qur.value(0).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+" "+supplier_ledger.value(5).toString().trimmed().rightJustified(6,' ',1)+" "+supplier_ledger.value(6).toString().trimmed().rightJustified(6,' ',1)+particular_supplier_bal.trimmed().prepend(closing_str).rightJustified(7,' ',1);
//                        qDebug()<<"supplier_ledger ===>>>"<<to_print;
//                        print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
//                    }
//                }
//            }
//            supplier_ledger.clear();
//            if(databaseObj->selectQuery("select customer_master.cus_name,customer_master.balance as cl_bal,customer_master.balance_type as cl_bal_type from customer_master where customer_master.balance>0 and customer_master.cus_name not in (select transaction_master.cus_name from transaction_master where transaction_master.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"')) group by transaction_master.cus_name)",supplier_ledger))
//            {
//                if(supplier_ledger.next())
//                {
//                    QString to_print;

////                    QString closing_str = "";
////                    if(supplier_ledger.value(2).toInt() == 0 || supplier_ledger.value(8).toInt() == 2){
////                        closing_str = "+";
////                        total_cl_bal += supplier_ledger.value(1).toFloat();
////                    }
////                    if(supplier_ledger.value(2).toInt() == 1){
////                        closing_str = "-";
////                        total_cl_bal -= supplier_ledger.value(1).toFloat();
////                    }

////                    to_print = supplier_ledger.value(1).toString().trimmed().leftJustified(31,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);

//                    QString opening_str = "";
//                    QString closing_str = "";

//                    if(supplier_ledger.value(2).toInt() == 0 || supplier_ledger.value(8).toInt() == 2){
//                        closing_str = "+";
//                        total_cl_bal += supplier_ledger.value(1).toFloat();

//                        opening_str = "+";
//                        total_op_bal += supplier_ledger.value(1).toFloat();
//                    }
//                    if(supplier_ledger.value(2).toInt() == 1){
//                        closing_str = "-";
//                        total_cl_bal -= supplier_ledger.value(1).toFloat();

//                        opening_str = "+";
//                        total_op_bal -= supplier_ledger.value(1).toFloat();
//                    }

//                    to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+"              "+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);


//                    qDebug()<<"supplier_ledger ===>>>"<<to_print;
//                    print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
//                    while(supplier_ledger.next())
//                    {
//                        QString to_print;

////                        QString closing_str = "";
////                        if(supplier_ledger.value(2).toInt() == 0 || supplier_ledger.value(8).toInt() == 2){
////                            closing_str = "+";
////                            total_cl_bal += supplier_ledger.value(1).toFloat();
////                        }
////                        if(supplier_ledger.value(2).toInt() == 1){
////                            closing_str = "-";
////                            total_cl_bal -= supplier_ledger.value(1).toFloat();
////                        }

//                        QString opening_str = "";
//                        QString closing_str = "";

//                        if(supplier_ledger.value(2).toInt() == 0 || supplier_ledger.value(8).toInt() == 2){
//                            closing_str = "+";
//                            total_cl_bal += supplier_ledger.value(1).toFloat();

//                            opening_str = "+";
//                            total_op_bal += supplier_ledger.value(1).toFloat();
//                        }
//                        if(supplier_ledger.value(2).toInt() == 1){
//                            closing_str = "-";
//                            total_cl_bal -= supplier_ledger.value(1).toFloat();

//                            opening_str = "+";
//                            total_op_bal -= supplier_ledger.value(1).toFloat();
//                        }

//                        to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+"              "+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);


//                        to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(31,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);
//                        qDebug()<<"supplier_ledger ===>>>"<<to_print;
//                        print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
//                    }
//                }
//            }

//            qDebug()<<"Supplier total_op_bal ===>>>"<<total_op_bal;
//            qDebug()<<"Supplier total_addition ===>>>"<<total_addition;
//            qDebug()<<"Supplier total_paid ===>>>"<<total_paid;
//            qDebug()<<"Supplier total_cl_bal ===>>>"<<total_cl_bal;

//            //! employee

//            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
//            print.addData("Employee Ledger",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
//            supplier_ledger.clear();
//            if(databaseObj->selectQuery("select employee_transaction.emp_name,sum(employee_transaction.produced_bale) as produced_bale,min(employee_transaction.opening_balance) as op_bal,min(employee_transaction.opening_balance_type) as op_bal_type,sum(employee_transaction.calc_salary) as calc_salary,sum(employee_transaction.paid_salary) as paid,employee_master.emp_balance_bale_rate,employee_master.emp_balance_type from employee_transaction inner join employee_master on employee_master.emp_name=employee_transaction.emp_name where employee_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"')) group by employee_transaction.emp_name",supplier_ledger))
//            {
//                if(supplier_ledger.next())
//                {
//                    QString to_print;
//                    QString opening_str = "";
//                    QString closing_str = "";

////                    if(supplier_ledger.value(3).toInt() == 0 || supplier_ledger.value(3).toInt() == 2){
////                        opening_str = "+";
////                        total_op_bal += supplier_ledger.value(2).toFloat();
////                    }
////                    if(supplier_ledger.value(3).toInt() == 1){
////                        opening_str = "-";
////                        total_op_bal -= supplier_ledger.value(2).toFloat();
////                    }


//                    QSqlQuery supplier_ledger_op_qur;
//                    if(databaseObj->selectQuery("select employee_transaction.opening_balance,employee_transaction.opening_balance_type from employee_transaction where employee_transaction.emp_name='"+supplier_ledger.value(0).toString().trimmed()+"' and employee_transaction.day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"' and rowid=(select min(rowid) from employee_transaction where employee_transaction.emp_name='"+supplier_ledger.value(0).toString().trimmed()+"' and employee_transaction.day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"')",supplier_ledger_op_qur))
//                    {
//                        if(supplier_ledger_op_qur.next())
//                        {
//                            if(supplier_ledger_op_qur.value(1).toInt() == 0 || supplier_ledger_op_qur.value(1).toInt() == 2){
//                                opening_str = "+";
//                                total_op_bal += supplier_ledger_op_qur.value(0).toFloat();
//                            }
//                            if(supplier_ledger_op_qur.value(1).toInt() == 1){
//                                opening_str = "-";
//                                total_op_bal -= supplier_ledger_op_qur.value(0).toFloat();
//                            }

//                        }
//                    }

//                    QSqlQuery closing_employee_balance;
//                    QString particular_employee_bal;
//                    if(databaseObj->selectQuery("select employee_transaction.pending_salary,employee_transaction.emp_balance_type from employee_transaction where rowid=(select max(rowid) from employee_transaction where employee_transaction.emp_name='"+supplier_ledger.value(0).toString().trimmed()+"')",closing_employee_balance))
//                    {
//                        if(closing_employee_balance.next())
//                        {
//                            particular_employee_bal = closing_employee_balance.value(0).toString().trimmed();
//                            if(closing_employee_balance.value(1).toInt() == 0 || closing_employee_balance.value(1).toInt() == 2){
//                                closing_str = "+";
//                                total_cl_bal += closing_employee_balance.value(0).toFloat();
//                            }
//                            if(closing_employee_balance.value(1).toInt() == 1){
//                                closing_str = "-";
//                                total_cl_bal -= closing_employee_balance.value(0).toFloat();
//                            }
//                        }
//                    }

//                    total_paid += supplier_ledger.value(5).toFloat();
//                    total_addition += supplier_ledger.value(4).toFloat();

//                    to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(2).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+" "+supplier_ledger.value(4).toString().trimmed().rightJustified(6,' ',1)+" "+supplier_ledger.value(5).toString().trimmed().rightJustified(6,' ',1)+particular_employee_bal.trimmed().prepend(closing_str).rightJustified(7,' ',1);
//                    qDebug()<<"Employee_ledger ===>>>"<<to_print;
//                    print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);


//                    while(supplier_ledger.next())
//                    {
//                        QString to_print;
//                        QString opening_str = "";
//                        QString closing_str = "";

////                        if(supplier_ledger.value(3).toInt() == 0 || supplier_ledger.value(3).toInt() == 2){
////                            opening_str = "+";
////                            total_op_bal += supplier_ledger.value(2).toFloat();
////                        }
////                        if(supplier_ledger.value(3).toInt() == 1){
////                            opening_str = "-";
////                            total_op_bal -= supplier_ledger.value(2).toFloat();
////                        }

//                        QSqlQuery supplier_ledger_op_qur;
//                        if(databaseObj->selectQuery("select employee_transaction.opening_balance,employee_transaction.opening_balance_type from employee_transaction where employee_transaction.emp_name='"+supplier_ledger.value(0).toString().trimmed()+"' and employee_transaction.day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"' and rowid=(select min(rowid) from employee_transaction where employee_transaction.emp_name='"+supplier_ledger.value(0).toString().trimmed()+"' and employee_transaction.day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"')",supplier_ledger_op_qur))
//                        {
//                            if(supplier_ledger_op_qur.next())
//                            {
//                                if(supplier_ledger_op_qur.value(1).toInt() == 0 || supplier_ledger_op_qur.value(1).toInt() == 2){
//                                    opening_str = "+";
//                                    total_op_bal += supplier_ledger_op_qur.value(0).toFloat();
//                                }
//                                if(supplier_ledger_op_qur.value(1).toInt() == 1){
//                                    opening_str = "-";
//                                    total_op_bal -= supplier_ledger_op_qur.value(0).toFloat();
//                                }

//                            }
//                        }


//                        QSqlQuery closing_employee_balance;
//                        QString particular_employee_bal;
//                        if(databaseObj->selectQuery("select employee_transaction.pending_salary,employee_transaction.emp_balance_type from employee_transaction where rowid=(select max(rowid) from employee_transaction where employee_transaction.emp_name='"+supplier_ledger.value(0).toString().trimmed()+"')",closing_employee_balance))
//                        {
//                            if(closing_employee_balance.next())
//                            {
//                                particular_employee_bal = closing_employee_balance.value(0).toString().trimmed();
//                                if(closing_employee_balance.value(1).toInt() == 0 || closing_employee_balance.value(1).toInt() == 2){
//                                    closing_str = "+";
//                                    total_cl_bal += closing_employee_balance.value(0).toFloat();
//                                }
//                                if(closing_employee_balance.value(1).toInt() == 1){
//                                    closing_str = "-";
//                                    total_cl_bal -= closing_employee_balance.value(0).toFloat();
//                                }
//                            }
//                        }

//                        total_paid += supplier_ledger.value(5).toFloat();
//                        total_addition += supplier_ledger.value(4).toFloat();

//                        to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(2).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+" "+supplier_ledger.value(4).toString().trimmed().rightJustified(6,' ',1)+" "+supplier_ledger.value(5).toString().trimmed().rightJustified(6,' ',1)+particular_employee_bal.trimmed().prepend(closing_str).rightJustified(7,' ',1);

//                        qDebug()<<"Employee_ledger ===>>>"<<to_print;
//                        print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
//                    }
//                }
//            }

//            supplier_ledger.clear();
//            if(databaseObj->selectQuery("select employee_master.emp_name,employee_master.emp_balance_bale_rate,employee_master.emp_balance_type from employee_master where  is_active='1' and employee_master.emp_name not in (select employee_transaction.emp_name from employee_transaction where employee_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"')) group by employee_transaction.emp_name)",supplier_ledger))
//            {
//                if(supplier_ledger.next())
//                {
//                    QString to_print;

////                    QString closing_str = "";
////                    if(supplier_ledger.value(2).toInt() == 0 || supplier_ledger.value(8).toInt() == 2){
////                        closing_str = "+";
////                        total_cl_bal += supplier_ledger.value(1).toFloat();
////                    }
////                    if(supplier_ledger.value(2).toInt() == 1){
////                        closing_str = "-";
////                        total_cl_bal -= supplier_ledger.value(1).toFloat();
////                    }
////                    to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(31,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);


//                    QString opening_str = "";
//                    QString closing_str = "";

//                    if(supplier_ledger.value(2).toInt() == 0 || supplier_ledger.value(8).toInt() == 2){
//                        closing_str = "+";
//                        total_cl_bal += supplier_ledger.value(1).toFloat();

//                        opening_str = "+";
//                        total_op_bal += supplier_ledger.value(1).toFloat();
//                    }
//                    if(supplier_ledger.value(2).toInt() == 1){
//                        closing_str = "-";
//                        total_cl_bal -= supplier_ledger.value(1).toFloat();

//                        opening_str = "+";
//                        total_op_bal -= supplier_ledger.value(1).toFloat();
//                    }

//                    to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+"              "+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);


//                    qDebug()<<"supplier_ledger ===>>>"<<to_print;
//                    print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
//                    while(supplier_ledger.next())
//                    {
//                        QString to_print;

////                        QString closing_str = "";
////                        if(supplier_ledger.value(2).toInt() == 0 || supplier_ledger.value(8).toInt() == 2){
////                            closing_str = "+";
////                            total_cl_bal += supplier_ledger.value(1).toFloat();
////                        }
////                        if(supplier_ledger.value(2).toInt() == 1){
////                            closing_str = "-";
////                            total_cl_bal -= supplier_ledger.value(1).toFloat();
////                        }
////                        to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(31,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);

//                        QString opening_str = "";
//                        QString closing_str = "";

//                        if(supplier_ledger.value(2).toInt() == 0 || supplier_ledger.value(8).toInt() == 2){
//                            closing_str = "+";
//                            total_cl_bal += supplier_ledger.value(1).toFloat();

//                            opening_str = "+";
//                            total_op_bal += supplier_ledger.value(1).toFloat();
//                        }
//                        if(supplier_ledger.value(2).toInt() == 1){
//                            closing_str = "-";
//                            total_cl_bal -= supplier_ledger.value(1).toFloat();

//                            opening_str = "+";
//                            total_op_bal -= supplier_ledger.value(1).toFloat();
//                        }

//                        to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+"              "+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);

//                        qDebug()<<"supplier_ledger ===>>>"<<to_print;
//                        print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
//                    }
//                }
//            }

//            qDebug()<<"Employee total_op_bal ===>>>"<<total_op_bal;
//            qDebug()<<"Employee total_addition ===>>>"<<total_addition;
//            qDebug()<<"Employee total_paid ===>>>"<<total_paid;
//            qDebug()<<"Employee total_cl_bal ===>>>"<<total_cl_bal;









//            //! employee driver staff

//            //                print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
//            //                print.addData("Employee Ledger",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
//            //                supplier_ledger.clear();
//            //                if(databaseObj->selectQuery("select employee_transaction.emp_name,sum(employee_transaction.produced_bale) as produced_bale,min(employee_transaction.opening_balance) as op_bal,min(employee_transaction.opening_balance_type) as op_bal_type,sum(employee_transaction.calc_salary) as calc_salary,sum(employee_transaction.paid_salary) as paid,employee_master.emp_balance,employee_master.emp_balance_type from employee_transaction inner join employee_master on employee_master.emp_name=employee_transaction.emp_name where employee_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"')) group by employee_transaction.emp_name",supplier_ledger))
//            //                {
//            //                    if(supplier_ledger.next())
//            //                    {
//            //                        QString to_print;
//            //                        QString opening_str = "";
//            //                        QString closing_str = "";

//            //                        if(supplier_ledger.value(3).toInt() == 0 || supplier_ledger.value(3).toInt() == 2){
//            //                            opening_str = "+";
//            //                            total_op_bal += supplier_ledger.value(2).toFloat();
//            //                        }
//            //                        if(supplier_ledger.value(3).toInt() == 1){
//            //                            opening_str = "-";
//            //                            total_op_bal -= supplier_ledger.value(2).toFloat();
//            //                        }

//            //                        QSqlQuery closing_employee_balance;
//            //                        QString particular_employee_bal;
//            //                        if(databaseObj->selectQuery("select employee_transaction.pending_salary,employee_transaction.emp_balance_type from employee_transaction where rowid=(select max(rowid) from employee_transaction where employee_transaction.emp_name='"+supplier_ledger.value(0).toString().trimmed()+"')",closing_employee_balance))
//            //                        {
//            //                            if(closing_employee_balance.next())
//            //                            {
//            //                                particular_employee_bal = closing_employee_balance.value(0).toString().trimmed();
//            //                                if(closing_employee_balance.value(1).toInt() == 0 || closing_employee_balance.value(1).toInt() == 2){
//            //                                    closing_str = "+";
//            //                                    total_cl_bal += closing_employee_balance.value(0).toFloat();
//            //                                }
//            //                                if(closing_employee_balance.value(1).toInt() == 1){
//            //                                    closing_str = "-";
//            //                                    total_cl_bal -= closing_employee_balance.value(0).toFloat();
//            //                                }
//            //                            }
//            //                        }

//            //                        total_paid += supplier_ledger.value(5).toFloat();
//            //                        total_addition += supplier_ledger.value(4).toFloat();

//            //                        to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(2).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+" "+supplier_ledger.value(4).toString().trimmed().rightJustified(6,' ',1)+" "+supplier_ledger.value(5).toString().trimmed().rightJustified(6,' ',1)+particular_employee_bal.trimmed().prepend(closing_str).rightJustified(7,' ',1);
//            //                        qDebug()<<"supplier_ledger ===>>>"<<to_print;
//            //                        print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);


//            //                        while(supplier_ledger.next())
//            //                        {
//            //                            QString to_print;
//            //                            QString opening_str = "";
//            //                            QString closing_str = "";

//            //                            if(supplier_ledger.value(3).toInt() == 0 || supplier_ledger.value(3).toInt() == 2){
//            //                                opening_str = "+";
//            //                                total_op_bal += supplier_ledger.value(2).toFloat();
//            //                            }
//            //                            if(supplier_ledger.value(3).toInt() == 1){
//            //                                opening_str = "-";
//            //                                total_op_bal -= supplier_ledger.value(2).toFloat();
//            //                            }


//            //                            QSqlQuery closing_employee_balance;
//            //                            QString particular_employee_bal;
//            //                            if(databaseObj->selectQuery("select employee_transaction.pending_salary,employee_transaction.emp_balance_type from employee_transaction where rowid=(select max(rowid) from employee_transaction where employee_transaction.emp_name='"+supplier_ledger.value(0).toString().trimmed()+"')",closing_employee_balance))
//            //                            {
//            //                                if(closing_employee_balance.next())
//            //                                {
//            //                                    particular_employee_bal = closing_employee_balance.value(0).toString().trimmed();
//            //                                    if(closing_employee_balance.value(1).toInt() == 0 || closing_employee_balance.value(1).toInt() == 2){
//            //                                        closing_str = "+";
//            //                                        total_cl_bal += closing_employee_balance.value(0).toFloat();
//            //                                    }
//            //                                    if(closing_employee_balance.value(1).toInt() == 1){
//            //                                        closing_str = "-";
//            //                                        total_cl_bal -= closing_employee_balance.value(0).toFloat();
//            //                                    }
//            //                                }
//            //                            }

//            //                            total_paid += supplier_ledger.value(5).toFloat();
//            //                            total_addition += supplier_ledger.value(4).toFloat();

//            //                            to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(2).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+" "+supplier_ledger.value(4).toString().trimmed().rightJustified(6,' ',1)+" "+supplier_ledger.value(5).toString().trimmed().rightJustified(6,' ',1)+particular_employee_bal.trimmed().prepend(closing_str).rightJustified(7,' ',1);

//            //                            qDebug()<<"supplier_ledger ===>>>"<<to_print;
//            //                            print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
//            //                        }
//            //                    }
//            //                }

//            supplier_ledger.clear();
//            if(databaseObj->selectQuery("select employee_master.emp_name,employee_master.emp_balance,employee_master.emp_balance_type from employee_master where  is_active='1' and  employee_master.emp_type<>'Labour'",supplier_ledger))
//            {
//                if(supplier_ledger.next())
//                {
//                    QString to_print;

////                    QString closing_str = "";
////                    if(supplier_ledger.value(2).toInt() == 0 || supplier_ledger.value(8).toInt() == 2){
////                        closing_str = "+";
////                        total_cl_bal += supplier_ledger.value(1).toFloat();
////                    }
////                    if(supplier_ledger.value(2).toInt() == 1){
////                        closing_str = "-";
////                        total_cl_bal -= supplier_ledger.value(1).toFloat();
////                    }

////                    to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(31,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);


//                    QString opening_str = "";
//                    QString closing_str = "";

//                    if(supplier_ledger.value(2).toInt() == 0 || supplier_ledger.value(8).toInt() == 2){
//                        closing_str = "+";
//                        total_cl_bal += supplier_ledger.value(1).toFloat();

//                        opening_str = "+";
//                        total_op_bal += supplier_ledger.value(1).toFloat();
//                    }
//                    if(supplier_ledger.value(2).toInt() == 1){
//                        closing_str = "-";
//                        total_cl_bal -= supplier_ledger.value(1).toFloat();

//                        opening_str = "+";
//                        total_op_bal -= supplier_ledger.value(1).toFloat();
//                    }

//                    to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+"              "+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);

//                    qDebug()<<"supplier_ledger ===>>>"<<to_print;
//                    print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
//                    while(supplier_ledger.next())
//                    {
//                        QString to_print;

////                        QString closing_str = "";
////                        if(supplier_ledger.value(2).toInt() == 0 || supplier_ledger.value(8).toInt() == 2){
////                            closing_str = "+";
////                            total_cl_bal += supplier_ledger.value(1).toFloat();
////                        }
////                        if(supplier_ledger.value(2).toInt() == 1){
////                            closing_str = "-";
////                            total_cl_bal -= supplier_ledger.value(1).toFloat();
////                        }
////                        to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(31,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);

//                        QString opening_str = "";
//                        QString closing_str = "";

//                        if(supplier_ledger.value(2).toInt() == 0 || supplier_ledger.value(8).toInt() == 2){
//                            closing_str = "+";
//                            total_cl_bal += supplier_ledger.value(1).toFloat();

//                            opening_str = "+";
//                            total_op_bal += supplier_ledger.value(1).toFloat();
//                        }
//                        if(supplier_ledger.value(2).toInt() == 1){
//                            closing_str = "-";
//                            total_cl_bal -= supplier_ledger.value(1).toFloat();

//                            opening_str = "+";
//                            total_op_bal -= supplier_ledger.value(1).toFloat();
//                        }

//                        to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+"              "+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);


//                        qDebug()<<"supplier_ledger ===>>>"<<to_print;
//                        print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
//                    }
//                }
//            }

//            qDebug()<<"Employee driver staff total_op_bal ===>>>"<<total_op_bal;
//            qDebug()<<"Employee driver staff total_addition ===>>>"<<total_addition;
//            qDebug()<<"Employee driver staff total_paid ===>>>"<<total_paid;
//            qDebug()<<"Employee driver staff total_cl_bal ===>>>"<<total_cl_bal;























//            //! bunk ledger
//            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
//            print.addData("Bunk Ledger",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

//            supplier_ledger.clear();

//            //            if(databaseObj->selectQuery("select diesel_transaction.bunk_id,bunk_master.bunk_name,min(diesel_transaction.opening_balance) as op_bal,min(diesel_transaction.opening_balance_type) as op_bal_type,sum(diesel_transaction.amount) as paid,max(diesel_transaction.closing_balance) as cl_bal,max(diesel_transaction.closing_balance_type) as cl_bal_type from diesel_transaction inner join bunk_master on bunk_master.id_bunk_master=diesel_transaction.bunk_id where diesel_transaction.is_payment=1 and diesel_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"'))",supplier_ledger))
//            if(databaseObj->selectQuery("select diesel_transaction.bunk_id,bunk_master.bunk_name,min(diesel_transaction.opening_balance) as op_bal,min(diesel_transaction.opening_balance_type) as op_bal_type,(select sum(diesel_transaction.amount) from diesel_transaction inner join bunk_master on bunk_master.id_bunk_master=diesel_transaction.bunk_id where diesel_transaction.is_payment=1 and diesel_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"'))) as paid,max(diesel_transaction.closing_balance) as cl_bal,max(diesel_transaction.closing_balance_type) as cl_bal_type from diesel_transaction inner join bunk_master on bunk_master.id_bunk_master=diesel_transaction.bunk_id where diesel_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"'))",supplier_ledger))
//            {
//                if(supplier_ledger.next())
//                {
//                    QString to_print;
//                    QString opening_str = "";
//                    QString closing_str = "";
//                    if(supplier_ledger.value(3).toInt() == 0 || supplier_ledger.value(3).toInt() == 2){
//                        opening_str = "+";
//                        total_op_bal += supplier_ledger.value(2).toFloat();
//                    }
//                    if(supplier_ledger.value(3).toInt() == 1){
//                        opening_str = "-";
//                        total_op_bal -= supplier_ledger.value(2).toFloat();
//                    }

//                    QSqlQuery closing_bunk_balance;
//                    //                    QString particular_bunk_bal;
//                    //                    particular_bunk_bal = supplier_ledger.value(5).toString().trimmed();
//                    //                    if(supplier_ledger.value(6).toInt() == 0 || supplier_ledger.value(6).toInt() == 2){
//                    //                        closing_str = "+";
//                    //                        total_cl_bal += supplier_ledger.value(5).toFloat();
//                    //                    }
//                    //                    if(supplier_ledger.value(6).toInt() == 1){
//                    //                        closing_str = "-";
//                    //                        total_cl_bal -= supplier_ledger.value(5).toFloat();
//                    //                    }





//                    QString particular_bunk_bal;
//                    if(databaseObj->selectQuery("select diesel_transaction.closing_balance,diesel_transaction.closing_balance_type from diesel_transaction where diesel_transaction.day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"' and diesel_transaction.bunk_id='"+supplier_ledger.value(0).toString()+"' and rowid=(select max(rowid) from diesel_transaction where diesel_transaction.day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"' and diesel_transaction.bunk_id='"+supplier_ledger.value(0).toString()+"')",closing_bunk_balance))
//                    {
//                        if(closing_bunk_balance.next())
//                        {
//                            particular_bunk_bal = closing_bunk_balance.value(0).toString().trimmed();
//                            if(closing_bunk_balance.value(1).toInt() == 0 || closing_bunk_balance.value(1).toInt() == 2){
//                                closing_str = "+";
//                                total_cl_bal += closing_bunk_balance.value(0).toFloat();
//                            }
//                            if(closing_bunk_balance.value(1).toInt() == 1){
//                                closing_str = "-";
//                                total_cl_bal -= closing_bunk_balance.value(0).toFloat();
//                            }
//                        }
//                    }

//                    QSqlQuery bunk_today_pur_qur;
//                    QString bunk_todays_addition="";
//                    if(databaseObj->selectQuery("select diesel_transaction.bunk_id,bunk_master.bunk_name,sum(diesel_transaction.amount) as paid from diesel_transaction inner join bunk_master on bunk_master.id_bunk_master=diesel_transaction.bunk_id where diesel_transaction.is_payment=0 and diesel_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"')) and diesel_transaction.bunk_id='"+supplier_ledger.value(0).toString()+"'",bunk_today_pur_qur))
//                    {
//                        if(bunk_today_pur_qur.next())
//                        {
//                            bunk_todays_addition = bunk_today_pur_qur.value(2).toString();
//                        }
//                    }


//                    total_paid += supplier_ledger.value(4).toFloat();
//                    total_addition += bunk_todays_addition.toFloat();
//                    to_print = supplier_ledger.value(1).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(2).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+" "+bunk_todays_addition.rightJustified(6,' ',1)+" "+supplier_ledger.value(4).toString().trimmed().rightJustified(6,' ',1)+particular_bunk_bal.trimmed().prepend(closing_str).rightJustified(7,' ',1);
//                    qDebug()<<"supplier_ledger ===>>>"<<to_print;
//                    print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
//                    while(supplier_ledger.next())
//                    {
//                        QString to_print;
//                        QString opening_str = "";
//                        QString closing_str = "";
//                        if(supplier_ledger.value(3).toInt() == 0 || supplier_ledger.value(3).toInt() == 2){
//                            opening_str = "+";
//                            total_op_bal += supplier_ledger.value(2).toFloat();
//                        }
//                        if(supplier_ledger.value(3).toInt() == 1){
//                            opening_str = "-";
//                            total_op_bal -= supplier_ledger.value(2).toFloat();
//                        }

//                        QSqlQuery closing_bunk_balance;
//                        //                        QString particular_bunk_bal;
//                        //                        particular_bunk_bal = supplier_ledger.value(5).toString().trimmed();
//                        //                        if(supplier_ledger.value(6).toInt() == 0 || supplier_ledger.value(6).toInt() == 2){
//                        //                            closing_str = "+";
//                        //                            total_cl_bal += supplier_ledger.value(5).toFloat();
//                        //                        }
//                        //                        if(supplier_ledger.value(6).toInt() == 1){
//                        //                            closing_str = "-";
//                        //                            total_cl_bal -= supplier_ledger.value(5).toFloat();
//                        //                        }




//                        QString particular_bunk_bal;
//                        if(databaseObj->selectQuery("select diesel_transaction.closing_balance,diesel_transaction.closing_balance_type from diesel_transaction where diesel_transaction.day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"' and diesel_transaction.bunk_id='"+supplier_ledger.value(0).toString()+"' and rowid=(select max(rowid) from diesel_transaction where diesel_transaction.day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"' and diesel_transaction.bunk_id='"+supplier_ledger.value(0).toString()+"')",closing_bunk_balance))
//                        {
//                            if(closing_bunk_balance.next())
//                            {
//                                particular_bunk_bal = closing_bunk_balance.value(0).toString().trimmed();
//                                if(closing_bunk_balance.value(1).toInt() == 0 || closing_bunk_balance.value(1).toInt() == 2){
//                                    closing_str = "+";
//                                    total_cl_bal += closing_bunk_balance.value(0).toFloat();
//                                }
//                                if(closing_bunk_balance.value(1).toInt() == 1){
//                                    closing_str = "-";
//                                    total_cl_bal -= closing_bunk_balance.value(0).toFloat();
//                                }
//                            }
//                        }
//                        QSqlQuery bunk_today_pur_qur;
//                        QString bunk_todays_addition="";
//                        if(databaseObj->selectQuery("select diesel_transaction.bunk_id,bunk_master.bunk_name,sum(diesel_transaction.amount) as paid from diesel_transaction inner join bunk_master on bunk_master.id_bunk_master=diesel_transaction.bunk_id where diesel_transaction.is_payment=0 and diesel_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"')) and diesel_transaction.bunk_id='"+supplier_ledger.value(0).toString()+"'",bunk_today_pur_qur))
//                        {
//                            if(bunk_today_pur_qur.next())
//                            {
//                                bunk_todays_addition = bunk_today_pur_qur.value(2).toString();
//                            }
//                        }

//                        total_paid += supplier_ledger.value(4).toFloat();
//                        total_addition += bunk_todays_addition.toFloat();
//                        to_print = supplier_ledger.value(1).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(2).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+" "+bunk_todays_addition.rightJustified(6,' ',1)+" "+supplier_ledger.value(4).toString().trimmed().rightJustified(6,' ',1)+particular_bunk_bal.trimmed().prepend(closing_str).rightJustified(7,' ',1);
//                        qDebug()<<"supplier_ledger ===>>>"<<to_print;
//                        print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
//                    }
//                }
//            }


//            supplier_ledger.clear();
//            if(databaseObj->selectQuery("select * from bunk_master where bunk_master.id_bunk_master not in (select diesel_transaction.bunk_id from diesel_transaction where diesel_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"')))",supplier_ledger))
//            {
//                if(supplier_ledger.next())
//                {
//                    QString to_print;

//                    QString closing_str = "";
//                    if(supplier_ledger.value(4).toInt() == 0 || supplier_ledger.value(4).toInt() == 2){
//                        closing_str = "+";
//                        total_cl_bal += supplier_ledger.value(3).toFloat();
//                    }
//                    if(supplier_ledger.value(4).toInt() == 1){
//                        closing_str = "-";
//                        total_cl_bal -= supplier_ledger.value(3).toFloat();
//                    }

//                    to_print = supplier_ledger.value(1).toString().trimmed().leftJustified(31,' ',1)+supplier_ledger.value(3).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);
//                    qDebug()<<"bunk_master ledger ===>>>"<<to_print;
//                    print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
//                    while(supplier_ledger.next())
//                    {
//                        QString to_print;

//                        QString closing_str = "";
//                        if(supplier_ledger.value(4).toInt() == 0 || supplier_ledger.value(4).toInt() == 2){
//                            closing_str = "+";
//                            total_cl_bal += supplier_ledger.value(3).toFloat();
//                        }
//                        if(supplier_ledger.value(4).toInt() == 1){
//                            closing_str = "-";
//                            total_cl_bal -= supplier_ledger.value(3).toFloat();
//                        }
//                        to_print = supplier_ledger.value(1).toString().trimmed().leftJustified(31,' ',1)+supplier_ledger.value(3).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);
//                        qDebug()<<"bunk_master ledger ===>>>"<<to_print;
//                        print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
//                    }
//                }
//            }

//            QString to_print_total;
//            to_print_total = "Total "+QString::number(total_op_bal).rightJustified(6,' ',1)+" "+QString::number(total_addition).rightJustified(6,' ',1)+" "+QString::number(total_paid).rightJustified(5,' ',1)+" "+QString::number(total_cl_bal).rightJustified(6,' ',1);
//            print.addData(to_print_total,CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);




            //!Batch Close report
            QSqlQuery batch_close_qur;
            QStringList lst_batch;
            lst_batch << "company_batch_no" << "other_batch_no" << "van_batch_no";

            lst_batch_no.clear();
            for(int i=0;i<lst_batch.size();i++)
            {

                QString batch_name;
                if(lst_batch.at(i).contains("company",Qt::CaseInsensitive))
                    batch_name = "Company ";
                if(lst_batch.at(i).contains("other",Qt::CaseInsensitive))
                    batch_name = "Auto ";
                if(lst_batch.at(i).contains("van",Qt::CaseInsensitive))
                    batch_name = "Van ";


                if(databaseObj->selectQuery("select batch_no from "+lst_batch.at(i)+" where production_day_no_close=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"')) order by batch_no desc",batch_close_qur))
                {
                    if(batch_close_qur.next())
                    {
                        lst_batch_no << batch_name+batch_close_qur.value(0).toString().trimmed().rightJustified(3,'0');
                        while(batch_close_qur.next())
                        {
                            lst_batch_no << batch_name+batch_close_qur.value(0).toString().trimmed().rightJustified(3,'0');
                        }
                    }
                }
            }
            qDebug()<<"batch_close_qur ===>>>"<<lst_batch_no;
            if(lst_batch_no.size() > 0)
            {
                for(int i=0;i<lst_batch_no.size();i++)
                {
                    QString batch_name;
                    if(lst_batch_no.at(i).contains("company",Qt::CaseInsensitive))
                        batch_name = "company_batch_no";
                    if(lst_batch_no.at(i).contains("auto",Qt::CaseInsensitive))
                        batch_name = "other_batch_no";
                    if(lst_batch_no.at(i).contains("van",Qt::CaseInsensitive))
                        batch_name = "van_batch_no";


                    batch_close_qur.clear();
                    if(databaseObj->selectQuery("select batch_no,total_husk_produced,est_bale,manu_bale,used_husk,excess_husk,diff_bale from "+batch_name+" where production_day_no_close=((select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"')))",batch_close_qur))
                    {
                        if(batch_close_qur.next())
                        {

                            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

                            print.addData("BATCH CLOSE REPORT",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
                            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

                            print.addData("BATCH NAME        : "+lst_batch_no.at(i).toUpper(),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                            print.addData("TOTAL PURCHASE    : "+batch_close_qur.value(1).toString().trimmed().append(" NOS"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

                            print.addData("TOTAL NO OF BALE  : "+batch_close_qur.value(3).toString().trimmed().append(" NOS"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                            print.addData("NO OF HUSK TO BALE: "+batch_close_qur.value(4).toString().trimmed().append(" NOS"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

                            QString diff_bale = batch_close_qur.value(6).toString().trimmed().append(" NOS");
                            QString diff_bale1 = diff_bale;

                            int diff_husk = batch_close_qur.value(4).toInt() - batch_close_qur.value(1).toInt();

                            print.addData("DIFFERENCE        :"+QString::number(diff_husk),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

                            //                            if(diff_bale1.contains("-"))
                            //                                print.addData("DIFFERENCE        :"+diff_bale.remove("-"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                            //                            else
                            //                                print.addData("DIFFERENCE        :"+diff_bale.prepend("-"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

                            if(diff_husk > 0)
                                print.addData("GAIN",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                            else
                                print.addData("LOSS",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

                            while(batch_close_qur.next())
                            {
                                print.addData("BATCH NAME        : "+lst_batch_no.at(i).toUpper(),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                                print.addData("TOTAL PURCHASE    : "+batch_close_qur.value(1).toString().trimmed().append(" NOS"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                                print.addData("TOTAL NO OF BALE  : "+batch_close_qur.value(3).toString().trimmed().append(" NOS"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                                print.addData("NO OF HUSK TO BALE:"+batch_close_qur.value(2).toString().trimmed().append(" NOS"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

                                QString diff_bale = batch_close_qur.value(6).toString().trimmed().append(" NOS");
                                QString diff_bale1 = diff_bale;

                                if(diff_bale1.contains("-"))
                                    print.addData("DIFFERENCE        :"+diff_bale.remove("-"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                                else
                                    print.addData("DIFFERENCE        :"+diff_bale.prepend("-"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

                                if(diff_bale1.contains("-"))
                                    print.addData("GAIN",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                                else
                                    print.addData("LOSS",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                            }
                        }
                    }
                }
            }
            print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            if(print.print(false,false))
            {

            }

        }
    }
#endif




















    //    //    if(ui->lineEdit_day_no->text().contains())

    //#if(SDK75)
    //    QSqlQuery day_details;
    //    if(databaseObj->selectQuery("SELECT day_no,status,open_date,open_time,close_date,close_time,open_bull_reading,open_gen_reading,open_eb_reading,open_diesel_reading,opening_bale_balance FROM day_master WHERE id_day= (SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"')",day_details))
    //    {
    //        //#if(SDK75)
    //        if(day_details.next())
    //        {
    //            CPrinter print;
    //            print.setFontType(CPrinter::eFontType_font2);

    //            print.addData("Day Close Report",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);

    //            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
    //            print.addData("Day No    :"+day_details.value(0).toString(),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    //            print.addData("Open Date :"+day_details.value(2).toString(),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    //            print.addData("Open Time :"+day_details.value(3).toString(),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    //            print.addData("Close Date:"+day_details.value(4).toString(),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    //            print.addData("Close Time:"+day_details.value(5).toString(),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    //            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

    //            day_details.clear();
    //            QStringList lst_aval_batch_type;
    //            QString total_husk;
    //            if(databaseObj->selectQuery("select transaction_master.batch_type from transaction_master where transaction_master.day_no=(SELECT day_no FROM day_master WHERE id_day=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"')) group by transaction_master.batch_type",day_details))
    //            {
    //                if(day_details.next())
    //                {
    //                    lst_aval_batch_type << day_details.value(0).toString().trimmed();
    //                    while(day_details.next())
    //                    {
    //                        lst_aval_batch_type << day_details.value(0).toString().trimmed();
    //                    }
    //                    qDebug()<<"avaliable batched ===>>>"<<lst_aval_batch_type;
    //                }
    //            }
    //            if(lst_aval_batch_type.size() > 0)
    //            {
    //                print.addData("Purchase Details",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
    //                print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
    //                print.addData("SNO  Vh   Load  CFT    HUSK    EXCESS",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);


    //                float tmp_total = 0;
    //                print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    //                for(int i=0;i<lst_aval_batch_type.size();i++)
    //                {
    //                    day_details.clear();
    //                    if(databaseObj->selectQuery("select count(transaction_master.batch_type),sum(transaction_master.inward_bale),sum(transaction_master.inward_hush),sum(transaction_master.excess_amt),sum(transaction_master.inward_hush)*(select configuration_master.auto_rate_of_husk from configuration_master),sum(transaction_master.vkms) from transaction_master where transaction_master.batch_type='"+lst_aval_batch_type.at(i)+"'",day_details))
    //                    {
    //                        if(day_details.next())
    //                        {
    //                            QString batch_name,to_print;
    //                            if(lst_aval_batch_type.at(i).toInt() == 0)
    //                                batch_name = "Comp";
    //                            if(lst_aval_batch_type.at(i).toInt() == 1)
    //                                batch_name = "Auto";
    //                            if(lst_aval_batch_type.at(i).toInt() == 2)
    //                                batch_name = "Van ";

    //                            to_print = QString::number(i+1).rightJustified(3,'0')+" "+batch_name+" "+day_details.value(0).toString().trimmed().rightJustified(4,' ')+" "+day_details.value(1).toString().trimmed().rightJustified(4,' ')+" "+day_details.value(3).toString().trimmed().rightJustified(6,' ')+" "+day_details.value(4).toString().trimmed().rightJustified(7,' ')+" "+QString::number(day_details.value(5).toString().trimmed().toFloat(),'f',2).rightJustified(9,' ');
    //                            //                            to_print = QString::number(i+1).rightJustified(3,'0')+batch_name
    //                            tmp_total+=day_details.value(2).toString().trimmed().toFloat();

    //                            qDebug()<<"tmp_total ===>>>"<<tmp_total;
    //                            qDebug()<<"to_print ===>>>"<<to_print;

    //                            print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

    //                        }
    //                    }
    //                }

    //                float total_husk = tmp_total;
    //                print.addData("Husk Purchased: "+QString::number(tmp_total,'f',2),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);

    //                print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
    //                print.addData("Cash Flow",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
    //                print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

    //                print.addData("SNO  vh     Qty   Rate    Amt    Kms ",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

    //                tmp_total = 0;
    //                for(int i=0;i<lst_aval_batch_type.size();i++)
    //                {

    //                    QString rate_of_husk;
    //                    day_details.clear();
    //                    if(databaseObj->selectQuery("select count(transaction_master.batch_type),sum(transaction_master.inward_bale),sum(transaction_master.inward_hush),sum(transaction_master.excess_amt),sum(transaction_master.inward_hush)*(select configuration_master.auto_rate_of_husk from configuration_master),sum(transaction_master.vkms) from transaction_master where transaction_master.batch_type='"+lst_aval_batch_type.at(i)+"'",day_details))
    //                    {
    //                        if(day_details.next())
    //                        {
    //                            QString batch_name,to_print,batch_name_rate;
    //                            if(lst_aval_batch_type.at(i).toInt() == 0){
    //                                batch_name = "Comp";
    //                                batch_name_rate = "rate_of_husk";
    //                            }
    //                            if(lst_aval_batch_type.at(i).toInt() == 1){
    //                                batch_name = "Auto";
    //                                batch_name_rate = "auto_rate_of_husk";
    //                            }
    //                            if(lst_aval_batch_type.at(i).toInt() == 2){
    //                                batch_name = "Van";
    //                                batch_name_rate = "van_rate_of_husk";
    //                            }

    //                            QSqlQuery husk_rate;
    //                            if(databaseObj->selectQuery("select configuration_master."+batch_name_rate+" from configuration_master",husk_rate))
    //                            {
    //                                if(husk_rate.next())
    //                                {
    //                                    rate_of_husk = husk_rate.value(0).toString().trimmed();
    //                                }
    //                            }

    //                            to_print = QString::number(i).rightJustified(3,'0')+" "+batch_name+" "+day_details.value(3).toString().trimmed().rightJustified(6,' ')+" "+rate_of_husk+" "+day_details.value(4).toString().trimmed().rightJustified(9,' ');
    //                            tmp_total+=day_details.value(4).toString().trimmed().toFloat();

    //                            qDebug()<<"tmp_total ===>>>"<<tmp_total;
    //                            qDebug()<<"to_print ===>>>"<<to_print;

    //                            print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);


    //                        }
    //                    }
    //                }
    //                float total_husk_amount = tmp_total;
    //                if(total_husk > 0)
    //                {
    //                    print.addData("Total Cash   : "+QString::number(tmp_total,'f',2),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
    //                    print.addData("Avg Hush Rate: "+QString::number(total_husk_amount/total_husk,'f',2),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
    //                }



    //                QSqlQuery expense_qur;
    //                QStringList lst_expense_name,lst_expense_bill_no,lst_expense_amount,lst_expense_user_id;
    //                if(databaseObj->selectQuery("select * from expense_transaction where day_no=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"')",expense_qur))
    //                {
    //                    if(expense_qur.next())
    //                    {
    //                        lst_expense_name << expense_qur.value(2).toString().trimmed();
    //                        lst_expense_bill_no << expense_qur.value(3).toString().trimmed();
    //                        lst_expense_amount << expense_qur.value(4).toString().trimmed();
    //                        lst_expense_user_id << expense_qur.value(6).toString().trimmed();
    //                        while(expense_qur.next())
    //                        {
    //                            lst_expense_name << expense_qur.value(2).toString().trimmed();
    //                            lst_expense_bill_no << expense_qur.value(3).toString().trimmed();
    //                            lst_expense_amount << expense_qur.value(4).toString().trimmed();
    //                            lst_expense_user_id << expense_qur.value(6).toString().trimmed();
    //                        }
    //                    }
    //                }

    //                if(lst_expense_name.size() > 0)
    //                {
    //                    print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
    //                    print.addData("Expense",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
    //                    print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
    //                    print.addData("SNO      Expense Name        Amount",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

    //                    float total_exp_amt = 0;
    //                    for(int i=0;i<lst_expense_name.size();i++)
    //                    {
    //                        QString prt_text = QString::number(i+1).rightJustified(2,' ')+" "+lst_expense_name.at(i).leftJustified(15,' ')+" "+QString::number(lst_expense_amount.at(i).toFloat(),'f',2).rightJustified(15,' ');
    //                        qDebug()<<"expense data ===>>>"<<prt_text;
    //                        print.addData(prt_text,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    //                        total_exp_amt += lst_expense_amount.at(i).toFloat();
    //                    }
    //                    print.addData("Total Expense: "+QString::number(total_exp_amt,'f',2),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
    //                }


    //                QSqlQuery husk_stock;
    //                //! auto batch

    //                print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
    //                print.addData("Stock Status Report",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
    //                print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);


    //                husk_stock.clear();
    //                if(databaseObj->selectQuery("select * from production_batch_order where batch_type='auto'",husk_stock))
    //                {
    //                    if(husk_stock.next())
    //                    {
    //                        print.addData("Auto Batch "+husk_stock.value(2).toString().rightJustified(3,'0')+": "+husk_stock.value(3).toString()+" Nos",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    //                        while(husk_stock.next())
    //                        {
    //                            print.addData("Auto Batch "+husk_stock.value(2).toString().rightJustified(3,'0')+": "+husk_stock.value(3).toString()+" Nos",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    //                        }
    //                    }
    //                }

    //                husk_stock.clear();
    //                if(databaseObj->selectQuery("select * from production_batch_order where batch_type='company'",husk_stock))
    //                {
    //                    if(husk_stock.next())
    //                    {
    //                        print.addData("Company Batch "+husk_stock.value(2).toString().rightJustified(3,'0')+": "+husk_stock.value(3).toString()+" Nos",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    //                        while(husk_stock.next())
    //                        {
    //                            print.addData("Company Batch "+husk_stock.value(2).toString().rightJustified(3,'0')+": "+husk_stock.value(3).toString()+" Nos",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    //                        }
    //                    }
    //                }

    //                husk_stock.clear();
    //                if(databaseObj->selectQuery("select * from production_batch_order where batch_type='van'",husk_stock))
    //                {
    //                    if(husk_stock.next())
    //                    {
    //                        print.addData("Van Batch "+husk_stock.value(2).toString().rightJustified(3,'0')+": "+husk_stock.value(3).toString()+" Nos",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    //                        while(husk_stock.next())
    //                        {
    //                            print.addData("Van Batch "+husk_stock.value(2).toString().rightJustified(3,'0')+": "+husk_stock.value(3).toString()+" Nos",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    //                        }
    //                    }
    //                }
    //                QString husk_available_production;
    //                husk_stock.clear();
    //                if(databaseObj->selectQuery("select sum(husk_available) from production_batch_order",husk_stock))
    //                {
    //                    if(husk_stock.next())
    //                    {
    //                        husk_available_production = husk_stock.value(0).toString().trimmed();
    //                        //                        print.addData("Auto Batch "+husk_stock.value(2).toString().rightJustified(3,'0')+": "+husk_stock.value(3).toString()+" Nos",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    //                    }
    //                }

    //                husk_stock.clear();
    //                QString closing_bale,closing_husk;
    //                if(databaseObj->selectQuery("select closing_bale_balance from day_master where day_no=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"')",husk_stock))
    //                {
    //                    if(husk_stock.next())
    //                    {
    //                        closing_bale = husk_stock.value(0).toString().trimmed();
    //                        closing_husk = QString::number(closing_bale.toFloat()*Home_ScreenObj->HP_bale.toFloat(),'f',2);
    //                    }
    //                }

    //                float total_husk_count = husk_available_production.toFloat()+closing_husk.toFloat();

    //                print.addData("Total No Of Husk: "+QString::number(total_husk_count,'f',2)+" Nos",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);



    //                QSqlQuery diesel_qur;

    //                QString initial_diesel_stock;
    //                diesel_qur.clear();
    //                if(databaseObj->selectQuery("select init_diesel_reading from configuration_master",diesel_qur))
    //                {
    //                    if(diesel_qur.next())
    //                    {
    //                        initial_diesel_stock = diesel_qur.value(0).toString().trimmed();
    //                    }
    //                }
    //                diesel_qur.clear();
    //                if(databaseObj->selectQuery("select * from diesel_usage where day_no=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"') and fill_type='1'",diesel_qur))
    //                {
    //                    if(diesel_qur.next())
    //                    {
    //                        print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
    //                        print.addData("Diesel Consumption",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
    //                        print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

    //                        diesel_qur.clear();
    //                        if(databaseObj->selectQuery("select * from diesel_usage where day_no=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"') and fill_type='1' group by vehicle_no",diesel_qur))
    //                        {
    //                            if(diesel_qur.next())
    //                            {
    //                                QString v_name = diesel_qur.value(1).toString().trimmed();
    //                                QString diff = get_difference(v_name);
    //                                qDebug()<<"diff ===>>>"<<diff;
    //                                if(diff.toInt() > 0)
    //                                {
    //                                    print.addData(v_name.toUpper().leftJustified(12,' ')+": "+diff ,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    //                                }
    //                            }
    //                        }

    //                        print.addData("Closing Stock: "+initial_diesel_stock+" lts",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

    //                        diesel_qur.clear();
    //                    }
    //                }


    //                QSqlQuery payables_qur;
    //                QString v_pay = "0";
    //                QStringList lst_v_no,lst_party_name,lst_amt;
    //                payables_qur.clear();
    //                if(databaseObj->selectQuery("select vehicle_no,cus_name,paid from transaction_master where day_no=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"')",payables_qur))
    //                {
    //                    if(payables_qur.next())
    //                    {
    //                        lst_v_no << payables_qur.value(0).toString().trimmed();
    //                        lst_party_name << payables_qur.value(1).toString().trimmed();
    //                        lst_amt << payables_qur.value(2).toString().trimmed();
    //                        while(payables_qur.next())
    //                        {
    //                            lst_v_no << payables_qur.value(0).toString().trimmed();
    //                            lst_party_name << payables_qur.value(1).toString().trimmed();
    //                            lst_amt << payables_qur.value(2).toString().trimmed();
    //                        }
    //                    }
    //                    if(lst_v_no.size() > 0)
    //                    {
    //                        print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
    //                        print.addData("Payables/Receivable",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
    //                        print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
    //                        print.addData("Vehicle No    Party Name       Amount",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

    //                        for(int i=0;i<lst_v_no.size();i++)
    //                        {
    //                            print.addData(lst_v_no.at(i).leftJustified(11,' ')+" "+lst_party_name.at(i).rightJustified(15,' ')+" "+QString::number(lst_amt.at(i).rightJustified(10,' ').toFloat(),'f',2),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    //                        }
    //                        payables_qur.clear();
    //                        if(databaseObj->selectQuery("select sum(paid) from transaction_master where day_no=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"')",payables_qur))
    //                        {
    //                            if(payables_qur.next())
    //                            {
    //                                v_pay = payables_qur.value(0).toString().trimmed();
    //                            }
    //                        }
    //                    }
    //                }

    //                QSqlQuery bunk_qur;
    //                QString bunk_pay = "0";
    //                QStringList lst_bunk_name,lst_bunk_qty,lst_bunk_amount;
    //                if(databaseObj->selectQuery("select diesel_transaction.bunk_id,bunk_master.bunk_name,diesel_transaction.quantity,diesel_transaction.amount from diesel_transaction inner join bunk_master on diesel_transaction.bunk_id=bunk_master.id_bunk_master where day_no=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"')",bunk_qur))
    //                {
    //                    if(bunk_qur.next())
    //                    {
    //                        lst_bunk_name << bunk_qur.value(1).toString().trimmed();
    //                        lst_bunk_qty << bunk_qur.value(2).toString().trimmed();
    //                        lst_bunk_amount << bunk_qur.value(3).toString().trimmed();
    //                        while(bunk_qur.next())
    //                        {
    //                            lst_bunk_name << bunk_qur.value(1).toString().trimmed();
    //                            lst_bunk_qty << bunk_qur.value(2).toString().trimmed();
    //                            lst_bunk_amount << bunk_qur.value(3).toString().trimmed();
    //                        }
    //                    }


    //                    if(lst_bunk_name.size() > 0)
    //                    {

    //                        if(lst_v_no.size() == 0)
    //                        {
    //                            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
    //                            print.addData("Payables/Receivable",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
    //                            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
    //                        }

    //                        for(int i=0;i<lst_bunk_name.size();i++)
    //                        {
    //                            print.addData("            "+lst_bunk_name.at(i).leftJustified(15,' ')+" "+QString::number(lst_bunk_amount.at(i).rightJustified(10,' ').toFloat(),'f',2),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    //                        }
    //                        bunk_qur.clear();
    //                        if(databaseObj->selectQuery("select sum(diesel_transaction.amount) from diesel_transaction where day_no=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"')",bunk_qur))
    //                        {
    //                            if(bunk_qur.next())
    //                            {
    //                                bunk_pay = bunk_qur.value(0).toString().trimmed();
    //                            }
    //                        }
    //                    }
    //                }

    //                QSqlQuery emp_qur;
    //                QString emp_pay = "0";
    //                QStringList lst_emp_name,lst_emp_amount;
    //                if(databaseObj->selectQuery("select emp_name,paid_salary from employee_transaction where paid_salary IS NOT NULL and day_no=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"')",emp_qur))
    //                {
    //                    if(emp_qur.next())
    //                    {
    //                        lst_emp_name << emp_qur.value(0).toString().trimmed();
    //                        lst_emp_amount << emp_qur.value(1).toString().trimmed();
    //                        while(emp_qur.next())
    //                        {
    //                            lst_emp_name << emp_qur.value(0).toString().trimmed();
    //                            lst_emp_amount << emp_qur.value(1).toString().trimmed();
    //                        }
    //                    }
    //                    if(lst_emp_name.size() > 0)
    //                    {

    //                        if( (lst_v_no.size() == 0) && (lst_bunk_name.size() == 0) )
    //                        {
    //                            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
    //                            print.addData("Payables/Receivable",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
    //                            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
    //                        }

    //                        for(int i=0;i<lst_emp_name.size();i++)
    //                        {
    //                            print.addData("            "+lst_emp_name.at(i).leftJustified(15,' ')+" "+QString::number(lst_emp_amount.at(i).rightJustified(10,' ').toFloat(),'f',2),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    //                        }
    //                        emp_qur.clear();
    //                        if(databaseObj->selectQuery("select sum(paid_salary) from employee_transaction where paid_salary IS NOT NULL and day_no=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"')",emp_qur))
    //                        {
    //                            if(emp_qur.next())
    //                            {
    //                                emp_pay = emp_qur.value(0).toString().trimmed();
    //                            }
    //                        }
    //                    }
    //                }
    //                if( (lst_v_no.size() != 0) || (lst_bunk_name.size() != 0) || (lst_emp_name.size() != 0) )
    //                {
    //                    print.addData("Total Payables:Rs "+QString::number(v_pay.toFloat() + emp_pay.toFloat() + bunk_pay.toFloat(),'f',2 ),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
    //                }

    //                //                QSqlQuery batch_supplier_qur;
    //                //                if(databaseObj->selectQuery("select vehicle_no,cus_name,count(vehicle_no),sum(inward_bale),sum(inward_hush) from transaction_master where day_no=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"') group by cus_name",batch_supplier_qur))
    //                //                {
    //                //                    if(batch_supplier_qur.next())
    //                //                    {
    //                //                        QString batch_supplier_details = batch_supplier_qur.value(0).toString().trimmed().leftJustified(10,' ')+" "+batch_supplier_qur.value(1).toString().trimmed().leftJustified(7,' ')+" "+batch_supplier_qur.value(2).toString().trimmed().rightJustified(2,' ')+" "+QString::number(batch_supplier_qur.value(3).toString().trimmed(),'f',2).rightJustified(6,' ')+" "+QString::number(batch_supplier_qur.value(4).toString().trimmed(),'f',2).rightJustified(9,' ');
    //                //                        qDebug()<<"batch_supplier_details ===>>>"<<batch_supplier_details;
    //                //                        print.addData(batch_supplier_details,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    //                //                        while(batch_supplier_qur.next())
    //                //                        {
    //                //                            QString batch_supplier_details = batch_supplier_qur.value(0).toString().trimmed().leftJustified(10,' ')+" "+batch_supplier_qur.value(1).toString().trimmed().leftJustified(7,' ')+" "+batch_supplier_qur.value(2).toString().trimmed().rightJustified(2,' ')+" "+QString::number(batch_supplier_qur.value(3).toString().trimmed(),'f',2).rightJustified(6,' ')+" "+QString::number(batch_supplier_qur.value(4).toString().trimmed(),'f',2).rightJustified(9,' ');
    //                //                            qDebug()<<"batch_supplier_details ===>>>"<<batch_supplier_details;
    //                //                            print.addData(batch_supplier_details,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    //                //                        }
    //                //                        batch_supplier_qur.clear();
    //                //                        if(databaseObj->selectQuery("select sum(inward_bale),sum(inward_hush) from transaction_master where day_no=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='"+QString::number(ui->lineEdit_day_no->text().trimmed().remove("Day",Qt::CaseInsensitive).toInt())+"')",batch_supplier_qur))
    //                //                        {
    //                //                            if(batch_supplier_qur.next())
    //                //                            {
    //                ////                                QString batch_supplier_details = batch_supplier_qur.value(0).toString().trimmed().leftJustified(10,' ')+" "+batch_supplier_qur.value(1).toString().trimmed().leftJustified(7,' ')+" "+batch_supplier_qur.value(2).toString().trimmed().rightJustified(2,' ')+" "+QString::number(batch_supplier_qur.value(3).toString().trimmed(),'f',2).rightJustified(6,' ')+" "+QString::number(batch_supplier_qur.value(4).toString().trimmed(),'f',2).rightJustified(9,' ');
    //                ////                                qDebug()<<"batch_supplier_details ===>>>"<<batch_supplier_details;
    //                //                                print.addData(batch_supplier_details,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    //                //                            }
    //                //                        }
    //                //                    }
    //                //                }



    //            }

    //            print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    //            print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    //            print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    //            print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    //            if(print.print(false,false))
    //            {

    //            }
    //            call_Report();

    //        }
    //    }
    //#endif
}

void Report::on_pushButton_stock_status_clicked()
{
    CPrinter print;
    print.setFontType(CPrinter::eFontType_font2);


    print.addData("Stock Status Report",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
    print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

    //! today

    QSqlQuery stock_qur;
    QStringList lst_stock_batch;
    lst_stock_batch << "company_batch_no" << "other_batch_no" << "van_batch_no";
    print.addData("* As On:"+QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm:ss"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
    print.addData(" TYPE   BATCHNO  CFT  NO.OF.HUSK",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
    print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
    int husk_only = 0;
    float cft_only = 0;

    int husk_pro = 0;
    float cft_pro = 0;

    for(int i=0;i<lst_stock_batch.size();i++)
    {
        QStringList lst_stock_batch_no,lst_stock_batch_cft,lst_stock_batch_husk;
        QString stock_purchase,stock_production;
        QString pro_batch_name;
        if(databaseObj->selectQuery("select batch_no,total_husk_produced,inward_stock from "+lst_stock_batch.at(i)+" where production_status='2'",stock_qur))
        {

            if(stock_qur.next())
            {
                lst_stock_batch_no << stock_qur.value(0).toString().trimmed();
                lst_stock_batch_husk << stock_qur.value(1).toString().trimmed();
                lst_stock_batch_cft << stock_qur.value(2).toString().trimmed();
                while(stock_qur.next())
                {
                    lst_stock_batch_no << stock_qur.value(0).toString().trimmed();
                    lst_stock_batch_husk << stock_qur.value(1).toString().trimmed();
                    lst_stock_batch_cft << stock_qur.value(2).toString().trimmed();
                }

                if(lst_stock_batch.at(i).contains("company_batch_no"))
                    pro_batch_name = "Comp Husk";
                if(lst_stock_batch.at(i).contains("other_batch_no"))
                    pro_batch_name = "Auto Husk";
                if(lst_stock_batch.at(i).contains("van_batch_no"))
                    pro_batch_name = "Van Husk ";

                for(int p=0;p<lst_stock_batch_no.size();p++)
                    print.addData(pro_batch_name.leftJustified(9,' ',1)+" "+lst_stock_batch_no.at(p).rightJustified(4,'0').rightJustified(7,' ',1)+" "+lst_stock_batch_cft.at(p).rightJustified(7,' ',1)+" "+lst_stock_batch_husk.at(p).rightJustified(10,' ',1),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);




            }

        }

        stock_qur.clear();
        lst_stock_batch_no.clear();
        lst_stock_batch_husk.clear();
        lst_stock_batch_cft.clear();

        if(databaseObj->selectQuery("select batch_no,total_husk_produced,inward_stock from "+lst_stock_batch.at(i)+" where production_status is null",stock_qur))
        {

            if(stock_qur.next())
            {
                lst_stock_batch_no << stock_qur.value(0).toString().trimmed();
                lst_stock_batch_husk << stock_qur.value(1).toString().trimmed();
                lst_stock_batch_cft << stock_qur.value(2).toString().trimmed();
                while(stock_qur.next())
                {
                    lst_stock_batch_no << stock_qur.value(0).toString().trimmed();
                    lst_stock_batch_husk << stock_qur.value(1).toString().trimmed();
                    lst_stock_batch_cft << stock_qur.value(2).toString().trimmed();
                }

                if(lst_stock_batch.at(i).contains("company_batch_no"))
                    pro_batch_name = "Comp";
                if(lst_stock_batch.at(i).contains("other_batch_no"))
                    pro_batch_name = "Auto";
                if(lst_stock_batch.at(i).contains("van_batch_no"))
                    pro_batch_name = "Van  ";

                for(int p=0;p<lst_stock_batch_no.size();p++)
                    print.addData(pro_batch_name.leftJustified(9,' ',1)+" "+lst_stock_batch_no.at(p).rightJustified(4,'0').rightJustified(7,' ',1)+" "+lst_stock_batch_cft.at(p).rightJustified(7,' ',1)+" "+lst_stock_batch_husk.at(p).rightJustified(10,' ',1),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);




            }

        }
        QString pro_batch_name1;
        if(lst_stock_batch.at(i).contains("company_batch_no"))
            pro_batch_name1 = "company";
        if(lst_stock_batch.at(i).contains("other_batch_no"))
            pro_batch_name1 = "auto";
        if(lst_stock_batch.at(i).contains("van_batch_no"))
            pro_batch_name1 = "van";
        stock_qur.clear();
        if(databaseObj->selectQuery("select batch_no,husk_available,batch_type from production_batch_order where batch_type='"+pro_batch_name1+"'",stock_qur))
        {
            if(stock_qur.next())
            {

                QString pro_batch_name2;
                if(stock_qur.value(2).toString().contains("company"))
                    pro_batch_name2 = "Company";
                if(stock_qur.value(2).toString().contains("auto"))
                    pro_batch_name2 = "Auto";
                if(stock_qur.value(2).toString().contains("van"))
                    pro_batch_name2 = "Van";

                int tmp_husk = stock_qur.value(1).toInt();
                husk_pro += tmp_husk;
                cft_pro += (tmp_husk/Home_ScreenObj->HP_cft.toFloat());
                print.addData(pro_batch_name2.leftJustified(9,' ',1)+" "+stock_qur.value(0).toString().trimmed().rightJustified(4,'0').rightJustified(7,' ',1)+" "+QString::number(stock_qur.value(1).toInt()/Home_ScreenObj->HP_cft.toInt()).rightJustified(7,' ',1)+" "+stock_qur.value(1).toString().rightJustified(10,' ',1),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                while(stock_qur.next())
                {

                    QString pro_batch_name2;
                    if(stock_qur.value(2).toString().contains("company"))
                        pro_batch_name2 = "Company";
                    if(stock_qur.value(2).toString().contains("auto"))
                        pro_batch_name2 = "Auto";
                    if(stock_qur.value(2).toString().contains("van"))
                        pro_batch_name2 = "Van";

                    int tmp_husk = stock_qur.value(1).toInt();
                    husk_pro += tmp_husk;
                    cft_pro += (tmp_husk/Home_ScreenObj->HP_cft.toFloat());
                    print.addData(pro_batch_name2.leftJustified(9,' ',1)+" "+stock_qur.value(0).toString().trimmed().rightJustified(4,'0').rightJustified(7,' ',1)+" "+QString::number(stock_qur.value(1).toInt()/Home_ScreenObj->HP_cft.toInt()).rightJustified(7,' ',1)+" "+stock_qur.value(1).toString().rightJustified(10,' ',1),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                }
                qDebug()<<"cft_pro ===>>>"<<QString::number(cft_pro);
            }
        }

        stock_qur.clear();

        if(databaseObj->selectQuery("select sum(total_husk_produced),sum(inward_stock) from "+lst_stock_batch.at(i)+" where production_status='2'",stock_qur))
        {
            if(stock_qur.next())
            {
                husk_only += stock_qur.value(0).toString().trimmed().toInt();
                cft_only += stock_qur.value(1).toString().trimmed().toFloat();
                qDebug()<<"cft_only ===>>>"<<QString::number(cft_only);
            }
        }

        if(databaseObj->selectQuery("select sum(total_husk_produced),sum(inward_stock) from "+lst_stock_batch.at(i)+" where production_status is null",stock_qur))
        {
            if(stock_qur.next())
            {
                husk_only += stock_qur.value(0).toString().trimmed().toInt();
                cft_only += stock_qur.value(1).toString().trimmed().toFloat();
                qDebug()<<"cft_only ===>>>"<<QString::number(cft_only);
            }
        }
    }

    QString tot_cft_husk = QString("Total").leftJustified(13,' ',1)+" "+QString::number(cft_only+cft_pro).trimmed().rightJustified(8,' ',1)+" "+QString::number(husk_only+husk_pro).trimmed().rightJustified(9,' ',1);
    qDebug()<<"tot_cft_husk ===>>>"<<tot_cft_husk;
    print.addData(tot_cft_husk,CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

    stock_qur.clear();
    QString closing_bale,closing_husk;
    int closing_husk1 = 0;
    if(databaseObj->selectQuery("select closing_bale_balance from day_master where day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0'))",stock_qur))
    {
        if(stock_qur.next())
        {
            closing_bale = stock_qur.value(0).toString().trimmed();
            closing_husk = QString::number(closing_bale.toFloat()*Home_ScreenObj->HP_bale.toFloat(),'f',2);
//            closing_husk1 = (closing_bale.toInt()*Home_ScreenObj->HP_bale.toInt());
            closing_husk1 = (closing_bale.toFloat()*Home_ScreenObj->HP_bale.toInt());

            qDebug()<<"closing_husk1 ===>>>"<<QString::number(closing_husk1);
        }
    }
    //                float total_husk_count = husk_available_production.toFloat()+closing_husk.toFloat();
    print.addData(QString("Bale").leftJustified(13,' ',1)+" "+closing_bale.trimmed().append(" Nos").rightJustified(8,' ',1)+" "+closing_husk.trimmed().rightJustified(9,' ',1),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    print.addData("Total Husk In Stock "+QString::number(husk_only+husk_pro+closing_husk1).trimmed().rightJustified(9,' ',1),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
    print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
    print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
    print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
    print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

    if(print.print(false,false))
    {

    }
}

void Report::on_pushButton_payable_clicked()
{
    CPrinter print;
    print.setFontType(CPrinter::eFontType_font2);

    float total_op_bal = 0;
    float total_cl_bal = 0;
    float total_paid = 0;
    float total_addition = 0;



    print.addData("Ledger Wise Report",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
    print.addData("* As On:"+QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm:ss"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
    print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
    print.addData("  LEDGER   OP.BAL TODAY+  PAID  CL.BAL",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
    print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

    //! supplier
    print.addData("Supplier Ledger",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    QSqlQuery supplier_ledger;
    if(databaseObj->selectQuery("select transaction_master.vehicle_no,transaction_master.cus_name,min(transaction_master.previous_balance) as op_bal,min(transaction_master.previous_balance_type) as op_bal_type,sum(transaction_master.inward_hush) as inward_husk,sum(transaction_master.approved_amt) as approved_amt,sum(transaction_master.paid) as paid,customer_master.balance,customer_master.balance_type from transaction_master inner join customer_master on customer_master.cus_name=transaction_master.cus_name where transaction_master.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) group by transaction_master.cus_name",supplier_ledger))
    {
        if(supplier_ledger.next())
        {
            QString to_print;
            QString opening_str = "";
            QString closing_str = "";


//            if(supplier_ledger.value(3).toInt() == 0 || supplier_ledger.value(3).toInt() == 2){
//                opening_str = "+";
//                total_op_bal += supplier_ledger.value(2).toFloat();
//            }
//            if(supplier_ledger.value(3).toInt() == 1){
//                opening_str = "-";
//                total_op_bal -= supplier_ledger.value(2).toFloat();
//            }

            QSqlQuery supplier_ledger_op_qur;
            if(databaseObj->selectQuery("select transaction_master.previous_balance,transaction_master.previous_balance_type from transaction_master where transaction_master.is_void is null and transaction_master.cus_name='"+supplier_ledger.value(1).toString()+"' and transaction_master.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) and rowid=(select min(rowid) from transaction_master where transaction_master.is_void is null and transaction_master.cus_name='"+supplier_ledger.value(1).toString().trimmed()+"' and transaction_master.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')))",supplier_ledger_op_qur))
            {
                if(supplier_ledger_op_qur.next())
                {
                    if(supplier_ledger_op_qur.value(1).toInt() == 0 || supplier_ledger_op_qur.value(1).toInt() == 2){
                        opening_str = "+";
                        total_op_bal += supplier_ledger_op_qur.value(0).toFloat();
                    }
                    if(supplier_ledger_op_qur.value(1).toInt() == 1){
                        opening_str = "-";
                        total_op_bal -= supplier_ledger_op_qur.value(0).toFloat();
                    }

                }
            }


            QSqlQuery closing_supplier_balance;
            QString particular_supplier_bal;
            if(databaseObj->selectQuery("select transaction_master.balance,transaction_master.balance_type from transaction_master where rowid=(select max(rowid) from transaction_master where transaction_master.is_void is null and transaction_master.vehicle_no='"+supplier_ledger.value(0).toString().trimmed()+"' and transaction_master.cus_name='"+supplier_ledger.value(1).toString().trimmed()+"')",closing_supplier_balance))
            {
                if(closing_supplier_balance.next())
                {
                    particular_supplier_bal = closing_supplier_balance.value(0).toString().trimmed();
                    if(closing_supplier_balance.value(1).toInt() == 0 || closing_supplier_balance.value(1).toInt() == 2){
                        closing_str = "+";
                        total_cl_bal += closing_supplier_balance.value(0).toFloat();
                    }
                    if(closing_supplier_balance.value(1).toInt() == 1){
                        closing_str = "-";
                        total_cl_bal -= closing_supplier_balance.value(0).toFloat();
                    }
                }
            }

            total_paid += supplier_ledger.value(6).toFloat();
            total_addition += supplier_ledger.value(5).toFloat();

            to_print = supplier_ledger.value(1).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger_op_qur.value(0).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+" "+supplier_ledger.value(5).toString().trimmed().rightJustified(6,' ',1)+" "+supplier_ledger.value(6).toString().trimmed().rightJustified(6,' ',1)+particular_supplier_bal.trimmed().prepend(closing_str).rightJustified(7,' ',1);
            qDebug()<<"supplier_ledger ===>>>"<<to_print;
            print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);



            while(supplier_ledger.next())
            {
                QString to_print;
                QString opening_str = "";
                QString closing_str = "";


//                if(supplier_ledger.value(3).toInt() == 0 || supplier_ledger.value(3).toInt() == 2){
//                    opening_str = "+";
//                    total_op_bal += supplier_ledger.value(2).toFloat();
//                }
//                if(supplier_ledger.value(3).toInt() == 1){
//                    opening_str = "-";
//                    total_op_bal -= supplier_ledger.value(2).toFloat();
//                }
                QSqlQuery supplier_ledger_op_qur;
                if(databaseObj->selectQuery("select transaction_master.previous_balance,transaction_master.previous_balance_type from transaction_master where transaction_master.is_void is null and transaction_master.cus_name='"+supplier_ledger.value(1).toString()+"' and transaction_master.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) and rowid=(select min(rowid) from transaction_master where transaction_master.is_void is null and transaction_master.cus_name='"+supplier_ledger.value(1).toString().trimmed()+"' and transaction_master.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')))",supplier_ledger_op_qur))
                {
                    if(supplier_ledger_op_qur.next())
                    {
                        if(supplier_ledger_op_qur.value(1).toInt() == 0 || supplier_ledger_op_qur.value(1).toInt() == 2){
                            opening_str = "+";
                            total_op_bal += supplier_ledger_op_qur.value(0).toFloat();
                        }
                        if(supplier_ledger_op_qur.value(1).toInt() == 1){
                            opening_str = "-";
                            total_op_bal -= supplier_ledger_op_qur.value(0).toFloat();
                        }

                    }
                }
                QSqlQuery closing_supplier_balance;
                QString particular_supplier_bal;
                if(databaseObj->selectQuery("select transaction_master.balance,transaction_master.balance_type from transaction_master where rowid=(select max(rowid) from transaction_master where transaction_master.is_void is null and transaction_master.vehicle_no='"+supplier_ledger.value(0).toString().trimmed()+"' and transaction_master.cus_name='"+supplier_ledger.value(1).toString().trimmed()+"')",closing_supplier_balance))
                {
                    if(closing_supplier_balance.next())
                    {
                        particular_supplier_bal = closing_supplier_balance.value(0).toString().trimmed();
                        if(closing_supplier_balance.value(1).toInt() == 0 || closing_supplier_balance.value(1).toInt() == 2){
                            closing_str = "+";
                            total_cl_bal += closing_supplier_balance.value(0).toFloat();
                        }
                        if(closing_supplier_balance.value(1).toInt() == 1){
                            closing_str = "-";
                            total_cl_bal -= closing_supplier_balance.value(0).toFloat();
                        }
                    }
                }

                total_paid += supplier_ledger.value(6).toFloat();
                total_addition += supplier_ledger.value(5).toFloat();

                to_print = supplier_ledger.value(1).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger_op_qur.value(0).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+" "+supplier_ledger.value(5).toString().trimmed().rightJustified(6,' ',1)+" "+supplier_ledger.value(6).toString().trimmed().rightJustified(6,' ',1)+particular_supplier_bal.trimmed().prepend(closing_str).rightJustified(7,' ',1);
                qDebug()<<"supplier_ledger ===>>>"<<to_print;
                print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            }
        }
    }
    supplier_ledger.clear();
    if(databaseObj->selectQuery("select customer_master.cus_name,customer_master.balance as cl_bal,customer_master.balance_type as cl_bal_type from customer_master where customer_master.balance>0 and customer_master.cus_name not in (select transaction_master.cus_name from transaction_master where transaction_master.is_void is null and transaction_master.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) group by transaction_master.cus_name)",supplier_ledger))
    {
        if(supplier_ledger.next())
        {
            QString to_print;

//            QString closing_str = "";
//            if(supplier_ledger.value(2).toInt() == 0 || supplier_ledger.value(8).toInt() == 2){
//                closing_str = "+";
//                total_cl_bal += supplier_ledger.value(1).toFloat();
//            }
//            if(supplier_ledger.value(2).toInt() == 1){
//                closing_str = "-";
//                total_cl_bal -= supplier_ledger.value(1).toFloat();
//            }

//            to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(31,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);



            QString opening_str = "";
            QString closing_str = "";

            if(supplier_ledger.value(2).toInt() == 0 || supplier_ledger.value(2).toInt() == 2){
                closing_str = "+";
                total_cl_bal += supplier_ledger.value(1).toFloat();

                opening_str = "+";
                total_op_bal += supplier_ledger.value(1).toFloat();
            }
            if(supplier_ledger.value(2).toInt() == 1){
                closing_str = "-";
                total_cl_bal -= supplier_ledger.value(1).toFloat();

                opening_str = "-";
                total_op_bal -= supplier_ledger.value(1).toFloat();
            }

            to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+"              "+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);

            qDebug()<<"supplier_ledger ===>>>"<<to_print;
            print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            while(supplier_ledger.next())
            {
                QString to_print;

//                QString closing_str = "";
//                if(supplier_ledger.value(2).toInt() == 0 || supplier_ledger.value(8).toInt() == 2){
//                    closing_str = "+";
//                    total_cl_bal += supplier_ledger.value(1).toFloat();
//                }
//                if(supplier_ledger.value(2).toInt() == 1){
//                    closing_str = "-";
//                    total_cl_bal -= supplier_ledger.value(1).toFloat();
//                }

//                to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(31,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);



                QString opening_str = "";
                QString closing_str = "";

                if(supplier_ledger.value(2).toInt() == 0 || supplier_ledger.value(2).toInt() == 2){
                    closing_str = "+";
                    total_cl_bal += supplier_ledger.value(1).toFloat();

                    opening_str = "+";
                    total_op_bal += supplier_ledger.value(1).toFloat();
                }
                if(supplier_ledger.value(2).toInt() == 1){
                    closing_str = "-";
                    total_cl_bal -= supplier_ledger.value(1).toFloat();

                    opening_str = "-";
                    total_op_bal -= supplier_ledger.value(1).toFloat();
                }

                to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+"              "+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);


                qDebug()<<"supplier_ledger ===>>>"<<to_print;
                print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            }
        }
    }

    qDebug()<<"Supplier total_op_bal ===>>>"<<total_op_bal;
    qDebug()<<"Supplier total_addition ===>>>"<<total_addition;
    qDebug()<<"Supplier total_paid ===>>>"<<total_paid;
    qDebug()<<"Supplier total_cl_bal ===>>>"<<total_cl_bal;

    //! employee

    print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
    print.addData("Employee Ledger",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    supplier_ledger.clear();
    if(databaseObj->selectQuery("select employee_transaction.emp_name,sum(employee_transaction.produced_bale) as produced_bale,min(employee_transaction.opening_balance) as op_bal,min(employee_transaction.opening_balance_type) as op_bal_type,sum(employee_transaction.calc_salary) as calc_salary,sum(employee_transaction.paid_salary) as paid,employee_master.emp_balance_bale_rate,employee_master.emp_balance_type from employee_transaction inner join employee_master on employee_master.emp_name=employee_transaction.emp_name where employee_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) group by employee_transaction.emp_name",supplier_ledger))
    {
        if(supplier_ledger.next())
        {
            QString to_print;
            QString opening_str = "";
            QString closing_str = "";

//            if(supplier_ledger.value(3).toInt() == 0 || supplier_ledger.value(3).toInt() == 2){
//                opening_str = "+";
//                total_op_bal += supplier_ledger.value(2).toFloat();
//            }
//            if(supplier_ledger.value(3).toInt() == 1){
//                opening_str = "-";
//                total_op_bal -= supplier_ledger.value(2).toFloat();
//            }
            QSqlQuery supplier_ledger_op_qur;
            if(databaseObj->selectQuery("select employee_transaction.opening_balance,employee_transaction.opening_balance_type from employee_transaction where employee_transaction.emp_name='"+supplier_ledger.value(0).toString().trimmed()+"' and employee_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) and rowid=(select min(rowid) from employee_transaction where employee_transaction.emp_name='"+supplier_ledger.value(0).toString().trimmed()+"' and employee_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')))",supplier_ledger_op_qur))
            {
                if(supplier_ledger_op_qur.next())
                {
                    if(supplier_ledger_op_qur.value(1).toInt() == 0 || supplier_ledger_op_qur.value(1).toInt() == 2){
                        opening_str = "+";
                        total_op_bal += supplier_ledger_op_qur.value(0).toFloat();
                    }
                    if(supplier_ledger_op_qur.value(1).toInt() == 1){
                        opening_str = "-";
                        total_op_bal -= supplier_ledger_op_qur.value(0).toFloat();
                    }

                }
            }

            QSqlQuery closing_employee_balance;
            QString particular_employee_bal;
            if(databaseObj->selectQuery("select employee_transaction.pending_salary,employee_transaction.emp_balance_type from employee_transaction where rowid=(select max(rowid) from employee_transaction where employee_transaction.emp_name='"+supplier_ledger.value(0).toString().trimmed()+"')",closing_employee_balance))
            {
                if(closing_employee_balance.next())
                {
                    particular_employee_bal = closing_employee_balance.value(0).toString().trimmed();
                    if(closing_employee_balance.value(1).toInt() == 0 || closing_employee_balance.value(1).toInt() == 2){
                        closing_str = "+";
                        total_cl_bal += closing_employee_balance.value(0).toFloat();
                    }
                    if(closing_employee_balance.value(1).toInt() == 1){
                        closing_str = "-";
                        total_cl_bal -= closing_employee_balance.value(0).toFloat();
                    }
                }
            }

            total_paid += supplier_ledger.value(5).toFloat();
            total_addition += supplier_ledger.value(4).toFloat();

            to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger_op_qur.value(0).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+" "+supplier_ledger.value(4).toString().trimmed().rightJustified(6,' ',1)+" "+supplier_ledger.value(5).toString().trimmed().rightJustified(6,' ',1)+particular_employee_bal.trimmed().prepend(closing_str).rightJustified(7,' ',1);
            qDebug()<<"employee_ledger ===>>>"<<to_print;
            print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);


            while(supplier_ledger.next())
            {
                QString to_print;
                QString opening_str = "";
                QString closing_str = "";

//                if(supplier_ledger.value(3).toInt() == 0 || supplier_ledger.value(3).toInt() == 2){
//                    opening_str = "+";
//                    total_op_bal += supplier_ledger.value(2).toFloat();
//                }
//                if(supplier_ledger.value(3).toInt() == 1){
//                    opening_str = "-";
//                    total_op_bal -= supplier_ledger.value(2).toFloat();
//                }
                QSqlQuery supplier_ledger_op_qur;
                if(databaseObj->selectQuery("select employee_transaction.opening_balance,employee_transaction.opening_balance_type from employee_transaction where employee_transaction.emp_name='"+supplier_ledger.value(0).toString().trimmed()+"' and employee_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) and rowid=(select min(rowid) from employee_transaction where employee_transaction.emp_name='"+supplier_ledger.value(0).toString().trimmed()+"' and employee_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')))",supplier_ledger_op_qur))
                {
                    if(supplier_ledger_op_qur.next())
                    {
                        if(supplier_ledger_op_qur.value(1).toInt() == 0 || supplier_ledger_op_qur.value(1).toInt() == 2){
                            opening_str = "+";
                            total_op_bal += supplier_ledger_op_qur.value(0).toFloat();
                        }
                        if(supplier_ledger_op_qur.value(1).toInt() == 1){
                            opening_str = "-";
                            total_op_bal -= supplier_ledger_op_qur.value(0).toFloat();
                        }

                    }
                }


                QSqlQuery closing_employee_balance;
                QString particular_employee_bal;
                if(databaseObj->selectQuery("select employee_transaction.pending_salary,employee_transaction.emp_balance_type from employee_transaction where rowid=(select max(rowid) from employee_transaction where employee_transaction.emp_name='"+supplier_ledger.value(0).toString().trimmed()+"')",closing_employee_balance))
                {
                    if(closing_employee_balance.next())
                    {
                        particular_employee_bal = closing_employee_balance.value(0).toString().trimmed();
                        if(closing_employee_balance.value(1).toInt() == 0 || closing_employee_balance.value(1).toInt() == 2){
                            closing_str = "+";
                            total_cl_bal += closing_employee_balance.value(0).toFloat();
                        }
                        if(closing_employee_balance.value(1).toInt() == 1){
                            closing_str = "-";
                            total_cl_bal -= closing_employee_balance.value(0).toFloat();
                        }
                    }
                }

                total_paid += supplier_ledger.value(5).toFloat();
                total_addition += supplier_ledger.value(4).toFloat();

                to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger_op_qur.value(0).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+" "+supplier_ledger.value(4).toString().trimmed().rightJustified(6,' ',1)+" "+supplier_ledger.value(5).toString().trimmed().rightJustified(6,' ',1)+particular_employee_bal.trimmed().prepend(closing_str).rightJustified(7,' ',1);

                qDebug()<<"employee_ledger ===>>>"<<to_print;
                print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            }
        }
    }

    //! employee from master labour
    supplier_ledger.clear();
    if(databaseObj->selectQuery("select employee_master.emp_name,employee_master.emp_balance_bale_rate,employee_master.emp_balance_type from employee_master where  is_active='1' and employee_master.emp_name not in (select employee_transaction.emp_name from employee_transaction where employee_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) group by employee_transaction.emp_name)",supplier_ledger))
    {
        if(supplier_ledger.next())
        {
            QString to_print;

            QString opening_str = "";
            QString closing_str = "";

            if(supplier_ledger.value(2).toInt() == 0 || supplier_ledger.value(8).toInt() == 2){
                closing_str = "+";
                total_cl_bal += supplier_ledger.value(1).toFloat();

                opening_str = "+";
                total_op_bal += supplier_ledger.value(1).toFloat();
            }
            if(supplier_ledger.value(2).toInt() == 1){
                closing_str = "-";
                total_cl_bal -= supplier_ledger.value(1).toFloat();

                opening_str = "-";
                total_op_bal -= supplier_ledger.value(1).toFloat();
            }

            to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+"              "+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);
            qDebug()<<"supplier_ledger ===>>>"<<to_print;
            print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            while(supplier_ledger.next())
            {
                QString to_print;

//                QString closing_str = "";
//                if(supplier_ledger.value(2).toInt() == 0 || supplier_ledger.value(8).toInt() == 2){
//                    closing_str = "+";
//                    total_cl_bal += supplier_ledger.value(1).toFloat();
//                }
//                if(supplier_ledger.value(2).toInt() == 1){
//                    closing_str = "-";
//                    total_cl_bal -= supplier_ledger.value(1).toFloat();
//                }
//                to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(31,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);

                QString opening_str = "";
                QString closing_str = "";

                if(supplier_ledger.value(2).toInt() == 0 || supplier_ledger.value(8).toInt() == 2){
                    closing_str = "+";
                    total_cl_bal += supplier_ledger.value(1).toFloat();

                    opening_str = "+";
                    total_op_bal += supplier_ledger.value(1).toFloat();
                }
                if(supplier_ledger.value(2).toInt() == 1){
                    closing_str = "-";
                    total_cl_bal -= supplier_ledger.value(1).toFloat();

                    opening_str = "-";
                    total_op_bal -= supplier_ledger.value(1).toFloat();
                }

                to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+"              "+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);


                qDebug()<<"supplier_ledger ===>>>"<<to_print;
                print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            }
        }
    }

    qDebug()<<"Employee total_op_bal ===>>>"<<total_op_bal;
    qDebug()<<"Employee total_addition ===>>>"<<total_addition;
    qDebug()<<"Employee total_paid ===>>>"<<total_paid;
    qDebug()<<"Employee total_cl_bal ===>>>"<<total_cl_bal;









    //! employee driver staff

    //        print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
    //        print.addData("Employee Ledger",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    //        supplier_ledger.clear();
    //        if(databaseObj->selectQuery("select employee_transaction.emp_name,sum(employee_transaction.produced_bale) as produced_bale,min(employee_transaction.opening_balance) as op_bal,min(employee_transaction.opening_balance_type) as op_bal_type,sum(employee_transaction.calc_salary) as calc_salary,sum(employee_transaction.paid_salary) as paid,employee_master.emp_balance,employee_master.emp_balance_type from employee_transaction inner join employee_master on employee_master.emp_name=employee_transaction.emp_name where employee_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) group by employee_transaction.emp_name",supplier_ledger))
    //        {
    //            if(supplier_ledger.next())
    //            {
    //                QString to_print;
    //                QString opening_str = "";
    //                QString closing_str = "";

    //                if(supplier_ledger.value(3).toInt() == 0 || supplier_ledger.value(3).toInt() == 2){
    //                    opening_str = "+";
    //                    total_op_bal += supplier_ledger.value(2).toFloat();
    //                }
    //                if(supplier_ledger.value(3).toInt() == 1){
    //                    opening_str = "-";
    //                    total_op_bal -= supplier_ledger.value(2).toFloat();
    //                }

    //                QSqlQuery closing_employee_balance;
    //                QString particular_employee_bal;
    //                if(databaseObj->selectQuery("select employee_transaction.pending_salary,employee_transaction.emp_balance_type from employee_transaction where rowid=(select max(rowid) from employee_transaction where employee_transaction.emp_name='"+supplier_ledger.value(0).toString().trimmed()+"')",closing_employee_balance))
    //                {
    //                    if(closing_employee_balance.next())
    //                    {
    //                        particular_employee_bal = closing_employee_balance.value(0).toString().trimmed();
    //                        if(closing_employee_balance.value(1).toInt() == 0 || closing_employee_balance.value(1).toInt() == 2){
    //                            closing_str = "+";
    //                            total_cl_bal += closing_employee_balance.value(0).toFloat();
    //                        }
    //                        if(closing_employee_balance.value(1).toInt() == 1){
    //                            closing_str = "-";
    //                            total_cl_bal -= closing_employee_balance.value(0).toFloat();
    //                        }
    //                    }
    //                }

    //                total_paid += supplier_ledger.value(5).toFloat();
    //                total_addition += supplier_ledger.value(4).toFloat();

    //                to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(2).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+" "+supplier_ledger.value(4).toString().trimmed().rightJustified(6,' ',1)+" "+supplier_ledger.value(5).toString().trimmed().rightJustified(6,' ',1)+particular_employee_bal.trimmed().prepend(closing_str).rightJustified(7,' ',1);
    //                qDebug()<<"supplier_ledger ===>>>"<<to_print;
    //                print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);


    //                while(supplier_ledger.next())
    //                {
    //                    QString to_print;
    //                    QString opening_str = "";
    //                    QString closing_str = "";

    //                    if(supplier_ledger.value(3).toInt() == 0 || supplier_ledger.value(3).toInt() == 2){
    //                        opening_str = "+";
    //                        total_op_bal += supplier_ledger.value(2).toFloat();
    //                    }
    //                    if(supplier_ledger.value(3).toInt() == 1){
    //                        opening_str = "-";
    //                        total_op_bal -= supplier_ledger.value(2).toFloat();
    //                    }


    //                    QSqlQuery closing_employee_balance;
    //                    QString particular_employee_bal;
    //                    if(databaseObj->selectQuery("select employee_transaction.pending_salary,employee_transaction.emp_balance_type from employee_transaction where rowid=(select max(rowid) from employee_transaction where employee_transaction.emp_name='"+supplier_ledger.value(0).toString().trimmed()+"')",closing_employee_balance))
    //                    {
    //                        if(closing_employee_balance.next())
    //                        {
    //                            particular_employee_bal = closing_employee_balance.value(0).toString().trimmed();
    //                            if(closing_employee_balance.value(1).toInt() == 0 || closing_employee_balance.value(1).toInt() == 2){
    //                                closing_str = "+";
    //                                total_cl_bal += closing_employee_balance.value(0).toFloat();
    //                            }
    //                            if(closing_employee_balance.value(1).toInt() == 1){
    //                                closing_str = "-";
    //                                total_cl_bal -= closing_employee_balance.value(0).toFloat();
    //                            }
    //                        }
    //                    }

    //                    total_paid += supplier_ledger.value(5).toFloat();
    //                    total_addition += supplier_ledger.value(4).toFloat();

    //                    to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(2).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+" "+supplier_ledger.value(4).toString().trimmed().rightJustified(6,' ',1)+" "+supplier_ledger.value(5).toString().trimmed().rightJustified(6,' ',1)+particular_employee_bal.trimmed().prepend(closing_str).rightJustified(7,' ',1);

    //                    qDebug()<<"supplier_ledger ===>>>"<<to_print;
    //                    print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
    //                }
    //            }
    //        }

    supplier_ledger.clear();
    if(databaseObj->selectQuery("select employee_master.emp_name,employee_master.emp_balance,employee_master.emp_balance_type from employee_master where is_active='1' and  employee_master.emp_type<>'Labour' and employee_master.emp_name not in (select employee_transaction.emp_name from employee_transaction where employee_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0' and day_no='3')) group by employee_transaction.emp_name)",supplier_ledger))
    {
        if(supplier_ledger.next())
        {
            QString to_print;

            QString closing_str = "";
            if(supplier_ledger.value(2).toInt() == 0 || supplier_ledger.value(8).toInt() == 2){
                closing_str = "+";
                total_cl_bal += supplier_ledger.value(1).toFloat();
            }
            if(supplier_ledger.value(2).toInt() == 1){
                closing_str = "-";
                total_cl_bal -= supplier_ledger.value(1).toFloat();
            }

            to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(31,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);
            qDebug()<<"supplier_ledger ===>>>"<<to_print;
            print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            while(supplier_ledger.next())
            {
                QString to_print;

                QString closing_str = "";
                if(supplier_ledger.value(2).toInt() == 0 || supplier_ledger.value(8).toInt() == 2){
                    closing_str = "+";
                    total_cl_bal += supplier_ledger.value(1).toFloat();
                }
                if(supplier_ledger.value(2).toInt() == 1){
                    closing_str = "-";
                    total_cl_bal -= supplier_ledger.value(1).toFloat();
                }
                to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(31,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);
                qDebug()<<"supplier_ledger ===>>>"<<to_print;
                print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            }
        }
    }

    qDebug()<<"Employee driver staff total_op_bal ===>>>"<<total_op_bal;
    qDebug()<<"Employee driver staff total_addition ===>>>"<<total_addition;
    qDebug()<<"Employee driver staff total_paid ===>>>"<<total_paid;
    qDebug()<<"Employee driver staff total_cl_bal ===>>>"<<total_cl_bal;























    //! bunk ledger
    print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
    print.addData("Bunk Ledger",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

    supplier_ledger.clear();
    //    if(databaseObj->selectQuery("select diesel_transaction.bunk_id,bunk_master.bunk_name,min(diesel_transaction.opening_balance) as op_bal,min(diesel_transaction.opening_balance_type) as op_bal_type,sum(diesel_transaction.amount) as paid,max(diesel_transaction.closing_balance) as cl_bal,max(diesel_transaction.closing_balance_type) as cl_bal_type from diesel_transaction inner join bunk_master on bunk_master.id_bunk_master=diesel_transaction.bunk_id where diesel_transaction.is_payment=1 and diesel_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0'))",supplier_ledger))
    if(databaseObj->selectQuery("select diesel_transaction.bunk_id,bunk_master.bunk_name,min(diesel_transaction.opening_balance) as op_bal,min(diesel_transaction.opening_balance_type) as op_bal_type,(select sum(diesel_transaction.amount) from diesel_transaction inner join bunk_master on bunk_master.id_bunk_master=diesel_transaction.bunk_id where diesel_transaction.is_payment=1 and diesel_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0'))) as paid,max(diesel_transaction.closing_balance) as cl_bal,max(diesel_transaction.closing_balance_type) as cl_bal_type from diesel_transaction inner join bunk_master on bunk_master.id_bunk_master=diesel_transaction.bunk_id where diesel_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0'))",supplier_ledger))
    {
        if(supplier_ledger.next())
        {
            QString to_print;
            QString opening_str = "";
            QString closing_str = "";
            if(supplier_ledger.value(3).toInt() == 0 || supplier_ledger.value(3).toInt() == 2){
                opening_str = "+";
                total_op_bal += supplier_ledger.value(2).toFloat();
            }
            if(supplier_ledger.value(3).toInt() == 1){
                opening_str = "-";
                total_op_bal -= supplier_ledger.value(2).toFloat();
            }

            QSqlQuery closing_bunk_balance;
            //            QString particular_bunk_bal;
            //            particular_bunk_bal = supplier_ledger.value(5).toString().trimmed();
            //            if(supplier_ledger.value(6).toInt() == 0 || supplier_ledger.value(6).toInt() == 2){
            //                closing_str = "+";
            //                total_cl_bal += supplier_ledger.value(5).toFloat();
            //            }
            //            if(supplier_ledger.value(6).toInt() == 1){
            //                closing_str = "-";
            //                total_cl_bal -= supplier_ledger.value(5).toFloat();
            //            }




            QString particular_bunk_bal;
            if(databaseObj->selectQuery("select diesel_transaction.closing_balance,diesel_transaction.closing_balance_type from diesel_transaction where diesel_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) and diesel_transaction.bunk_id='"+supplier_ledger.value(0).toString()+"' and rowid=(select max(rowid) from diesel_transaction where diesel_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) and diesel_transaction.bunk_id='"+supplier_ledger.value(0).toString()+"')",closing_bunk_balance))
            {
                if(closing_bunk_balance.next())
                {
                    particular_bunk_bal = closing_bunk_balance.value(0).toString().trimmed();
                    if(closing_bunk_balance.value(1).toInt() == 0 || closing_bunk_balance.value(1).toInt() == 2){
                        closing_str = "+";
                        total_cl_bal += closing_bunk_balance.value(0).toFloat();
                    }
                    if(closing_bunk_balance.value(1).toInt() == 1){
                        closing_str = "-";
                        total_cl_bal -= closing_bunk_balance.value(0).toFloat();
                    }
                }
            }


            QSqlQuery bunk_today_pur_qur;
            QString bunk_todays_addition="";
            if(databaseObj->selectQuery("select diesel_transaction.bunk_id,bunk_master.bunk_name,sum(diesel_transaction.amount) as paid from diesel_transaction inner join bunk_master on bunk_master.id_bunk_master=diesel_transaction.bunk_id where diesel_transaction.is_payment=0 and diesel_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) and diesel_transaction.bunk_id='"+supplier_ledger.value(0).toString()+"'",bunk_today_pur_qur))
            {
                if(bunk_today_pur_qur.next())
                {
                    bunk_todays_addition = bunk_today_pur_qur.value(2).toString();
                }
            }


            total_paid += supplier_ledger.value(4).toFloat();
            total_addition += bunk_todays_addition.toFloat();
            to_print = supplier_ledger.value(1).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(2).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+" "+bunk_todays_addition.rightJustified(6,' ',1)+" "+supplier_ledger.value(4).toString().trimmed().rightJustified(6,' ',1)+particular_bunk_bal.trimmed().prepend(closing_str).rightJustified(7,' ',1);
            qDebug()<<"supplier_ledger ===>>>"<<to_print;
            print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            while(supplier_ledger.next())
            {
                QString to_print;
                QString opening_str = "";
                QString closing_str = "";
                if(supplier_ledger.value(3).toInt() == 0 || supplier_ledger.value(3).toInt() == 2){
                    opening_str = "+";
                    total_op_bal += supplier_ledger.value(2).toFloat();
                }
                if(supplier_ledger.value(3).toInt() == 1){
                    opening_str = "-";
                    total_op_bal -= supplier_ledger.value(2).toFloat();
                }

                QSqlQuery closing_bunk_balance;
                //                QString particular_bunk_bal;
                //                particular_bunk_bal = supplier_ledger.value(5).toString().trimmed();
                //                if(supplier_ledger.value(6).toInt() == 0 || supplier_ledger.value(6).toInt() == 2){
                //                    closing_str = "+";
                //                    total_cl_bal += supplier_ledger.value(5).toFloat();
                //                }
                //                if(supplier_ledger.value(6).toInt() == 1){
                //                    closing_str = "-";
                //                    total_cl_bal -= supplier_ledger.value(5).toFloat();
                //                }



                QString particular_bunk_bal;
                if(databaseObj->selectQuery("select diesel_transaction.closing_balance,diesel_transaction.closing_balance_type from diesel_transaction where diesel_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) and diesel_transaction.bunk_id='"+supplier_ledger.value(0).toString()+"' and rowid=(select max(rowid) from diesel_transaction where diesel_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) and diesel_transaction.bunk_id='"+supplier_ledger.value(0).toString()+"')",closing_bunk_balance))
                {
                    if(closing_bunk_balance.next())
                    {
                        particular_bunk_bal = closing_bunk_balance.value(0).toString().trimmed();
                        if(closing_bunk_balance.value(1).toInt() == 0 || closing_bunk_balance.value(1).toInt() == 2){
                            closing_str = "+";
                            total_cl_bal += closing_bunk_balance.value(0).toFloat();
                        }
                        if(closing_bunk_balance.value(1).toInt() == 1){
                            closing_str = "-";
                            total_cl_bal -= closing_bunk_balance.value(0).toFloat();
                        }
                    }
                }

                QSqlQuery bunk_today_pur_qur;
                QString bunk_todays_addition="";
                if(databaseObj->selectQuery("select diesel_transaction.bunk_id,bunk_master.bunk_name,sum(diesel_transaction.amount) as paid from diesel_transaction inner join bunk_master on bunk_master.id_bunk_master=diesel_transaction.bunk_id where diesel_transaction.is_payment=0 and diesel_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) and diesel_transaction.bunk_id='"+supplier_ledger.value(0).toString()+"'",bunk_today_pur_qur))
                {
                    if(bunk_today_pur_qur.next())
                    {
                        bunk_todays_addition = bunk_today_pur_qur.value(2).toString();
                    }
                }

                total_paid += supplier_ledger.value(4).toFloat();
                total_addition += bunk_todays_addition.toFloat();
                to_print = supplier_ledger.value(1).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(2).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+" "+bunk_todays_addition.rightJustified(6,' ',1)+" "+supplier_ledger.value(4).toString().trimmed().rightJustified(6,' ',1)+particular_bunk_bal.trimmed().prepend(closing_str).rightJustified(7,' ',1);
                qDebug()<<"supplier_ledger ===>>>"<<to_print;
                print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            }
        }
    }

    supplier_ledger.clear();
    if(databaseObj->selectQuery("select * from bunk_master where bunk_master.id_bunk_master not in (select diesel_transaction.bunk_id from diesel_transaction where diesel_transaction.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')))",supplier_ledger))
    {
        if(supplier_ledger.next())
        {
            QString to_print;

//            QString closing_str = "";
//            if(supplier_ledger.value(4).toInt() == 0 || supplier_ledger.value(4).toInt() == 2){
//                closing_str = "+";
//                total_cl_bal += supplier_ledger.value(3).toFloat();
//            }
//            if(supplier_ledger.value(4).toInt() == 1){
//                closing_str = "-";
//                total_cl_bal -= supplier_ledger.value(3).toFloat();
//            }

//            to_print = supplier_ledger.value(1).toString().trimmed().leftJustified(31,' ',1)+supplier_ledger.value(3).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);

            QString opening_str = "";
            QString closing_str = "";

            if(supplier_ledger.value(4).toInt() == 0 || supplier_ledger.value(4).toInt() == 2){
                closing_str = "+";
                total_cl_bal += supplier_ledger.value(3).toFloat();

                opening_str = "+";
                total_op_bal += supplier_ledger.value(3).toFloat();
            }
            if(supplier_ledger.value(4).toInt() == 1){
                closing_str = "-";
                total_cl_bal -= supplier_ledger.value(3).toFloat();

                opening_str = "-";
                total_op_bal -= supplier_ledger.value(3).toFloat();
            }

//            to_print = supplier_ledger.value(1).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+"              "+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);
            to_print = supplier_ledger.value(1).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(3).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+"              "+supplier_ledger.value(3).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);



            qDebug()<<"bunk_master ledger ===>>>"<<to_print;
            print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            while(supplier_ledger.next())
            {
                QString to_print;

//                QString closing_str = "";
//                if(supplier_ledger.value(4).toInt() == 0 || supplier_ledger.value(4).toInt() == 2){
//                    closing_str = "+";
//                    total_cl_bal += supplier_ledger.value(3).toFloat();
//                }
//                if(supplier_ledger.value(4).toInt() == 1){
//                    closing_str = "-";
//                    total_cl_bal -= supplier_ledger.value(3).toFloat();
//                }
//                to_print = supplier_ledger.value(1).toString().trimmed().leftJustified(31,' ',1)+supplier_ledger.value(3).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);


                QString opening_str = "";
                QString closing_str = "";

                if(supplier_ledger.value(4).toInt() == 0 || supplier_ledger.value(4).toInt() == 2){
                    closing_str = "+";
                    total_cl_bal += supplier_ledger.value(3).toFloat();

                    opening_str = "+";
                    total_op_bal += supplier_ledger.value(3).toFloat();
                }
                if(supplier_ledger.value(4).toInt() == 1){
                    closing_str = "-";
                    total_cl_bal -= supplier_ledger.value(3).toFloat();

                    opening_str = "-";
                    total_op_bal -= supplier_ledger.value(3).toFloat();
                }

//                to_print = supplier_ledger.value(0).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(1).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+"              "+supplier_ledger.value(1).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);
                to_print = supplier_ledger.value(1).toString().trimmed().leftJustified(10,' ',1)+supplier_ledger.value(3).toString().trimmed().prepend(opening_str).rightJustified(7,' ',1)+"              "+supplier_ledger.value(3).toString().trimmed().prepend(closing_str).rightJustified(7,' ',1);

                qDebug()<<"bunk_master ledger ===>>>"<<to_print;
                print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            }
        }
    }

    QString to_print_total;
    to_print_total = "Total "+QString::number(total_op_bal).rightJustified(6,' ',1)+" "+QString::number(total_addition).rightJustified(6,' ',1)+" "+QString::number(total_paid).rightJustified(5,' ',1)+" "+QString::number(total_cl_bal).rightJustified(6,' ',1);
    print.addData(to_print_total,CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

    print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
    print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
    if(print.print(false,false))
    {
    }

    call_Report();
}

QString Report::get_voulume(QString name,QString day_no)
{
    QSqlQuery volume_qur;
    float qty_vol=0;
    if(databaseObj->selectQuery("SELECT * FROM diesel_usage where vehicle_no='"+name+"' and rowid<=(select max(rowid) from diesel_usage where diesel_usage.day_no<='"+day_no+"') ORDER BY reading DESC",volume_qur))
    {
        if(volume_qur.next())
        {
            if(volume_qur.value(3).toInt() == 1)
            {
                qty_vol += volume_qur.value(2).toString().toFloat();
            }
            while(volume_qur.next())
            {
                if(volume_qur.value(3).toInt() == 1)
                {
                    qDebug()<<"calculated volume ===>>>"<<QString::number(qty_vol,'f',2);
                    return QString::number(qty_vol);
                }
                qty_vol += volume_qur.value(2).toString().toFloat();

            }
        }
    }

}

void Report::on_pushButton_diesel_clicked()
{

//    CPrinter print;
//    print.setFontType(CPrinter::eFontType_font2);


//    QSqlQuery diesel_report_qur;
//    print.addData("Diesel Consumption",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
//    print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

//    if(databaseObj->selectQuery("select open_diesel_reading,close_diesel_reading from day_master where day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0'))",diesel_report_qur ))
//    {
//        if(diesel_report_qur.next())
//        {
//            print.addData("OPENING STOCK  : "+diesel_report_qur.value(0).toString().trimmed()+" Lts",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
//        }
//    }

//    diesel_report_qur.clear();
//    if(databaseObj->selectQuery("select sum(diesel_transaction.quantity) from diesel_transaction where day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0'))",diesel_report_qur ))
//    {
//        if(diesel_report_qur.next())
//        {
//            print.addData("TODAY PURCHASE : "+diesel_report_qur.value(0).toString().trimmed()+" Lts",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
//        }
//    }

//    diesel_report_qur.clear();
//    if(databaseObj->selectQuery("select sum(diesel_usage.quantity) from diesel_usage where day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0'))",diesel_report_qur ))
//    {
//        if(diesel_report_qur.next())
//        {
//            print.addData("CONSUMPTION    : "+diesel_report_qur.value(0).toString().trimmed()+" Lts",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
//        }
//    }

//    diesel_report_qur.clear();
//    QString report_day_no;
//    if(databaseObj->selectQuery("select diesel_usage.vehicle_no,sum(diesel_usage.quantity),diesel_usage.fill_type,diesel_usage.day_no from diesel_usage where diesel_usage.day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0')) group by diesel_usage.vehicle_no",diesel_report_qur))
//    {
//        if(diesel_report_qur.next())
//        {
//            //! new
//            QString vehicle_no;
//            QString vehicle_consumption;
//            vehicle_no = diesel_report_qur.value(0).toString().trimmed();
//            vehicle_consumption = diesel_report_qur.value(1).toString().trimmed();
//            report_day_no = diesel_report_qur.value(3).toString().trimmed();

//            QString diesel_to_print;
//            QString millage;
//            QString unit;
//            if(vehicle_no.contains("bull",Qt::CaseInsensitive) || vehicle_no.contains("generator",Qt::CaseInsensitive))
//            {
//                unit = "Lts/Hr";
//                if(get_difference(vehicle_no).toFloat() > 0)
//                {
//                    millage = QString::number(get_voulume(vehicle_no,report_day_no).toFloat()/get_difference(vehicle_no).toFloat());
//                }
//            }
//            else
//            {
//                unit = "km/lt";
//                if(get_difference(vehicle_no).toFloat() > 0)
//                {
//                    millage = QString::number(get_difference(vehicle_no).toFloat()/get_voulume(vehicle_no,report_day_no).toFloat());
//                }
//            }

//            if(!millage.isEmpty())
//                print.addData(vehicle_no.toUpper().leftJustified(12,' ',1)+":"+vehicle_consumption.append("lts")+" Milage:"+millage+" "+unit,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
//            else
//                print.addData(vehicle_no.toUpper().leftJustified(12,' ',1)+":"+vehicle_consumption.append("lts"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

//            while(diesel_report_qur.next())
//            {
//                //! new
//                QString vehicle_no;
//                QString vehicle_consumption;
//                vehicle_no = diesel_report_qur.value(0).toString().trimmed();
//                vehicle_consumption = diesel_report_qur.value(1).toString().trimmed();

//                QString diesel_to_print;
//                QString millage;
//                //                millage = QString::number(vehicle_consumption.toFloat()/get_difference(vehicle_no).toFloat());





//                QString unit;
//                if(vehicle_no.contains("bull",Qt::CaseInsensitive) || vehicle_no.contains("generator",Qt::CaseInsensitive))
//                {
//                    unit = "Lts/Hr";
//                    if(get_difference(vehicle_no).toFloat() > 0)
//                    {
//                        millage = QString::number(get_voulume(vehicle_no,report_day_no).toFloat()/get_difference(vehicle_no).toFloat());
//                    }
//                }
//                else
//                {
//                    unit = "km/lt";
//                    if(get_difference(vehicle_no).toFloat() > 0)
//                    {
//                        millage = QString::number(get_difference(vehicle_no).toFloat()/get_voulume(vehicle_no,report_day_no).toFloat());
//                    }
//                }

//                if(!millage.isEmpty())
//                    print.addData(vehicle_no.toUpper().leftJustified(12,' ',1)+":"+vehicle_consumption.append("lts")+" Milage:"+millage+" "+unit,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
//                else
//                    print.addData(vehicle_no.toUpper().leftJustified(12,' ',1)+":"+vehicle_consumption.append("lts"),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

//            }
//        }
//    }

//    //            QString diff = get_difference("bull");
//    //            qDebug()<<"diff ===>>>"<<diff;
//    //            float g=diff.toFloat();
//    //            if(g > 0)
//    //            {
//    //                print.addData(QString("bull").toUpper().leftJustified(12,' ')+": "+diff ,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
//    //            }
//    //            QString diff1 = get_difference("generator");
//    //            qDebug()<<"diff ===>>>"<<diff1;
//    //            float g1=diff1.toFloat();
//    //            qDebug()<<"diff g1 ===>>>"<<QString::number(g1);
//    //            if(g1 > 0)
//    //            {
//    //                print.addData(QString("generator").toUpper().leftJustified(12,' ')+": "+diff1 ,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
//    //            }


//    //            QSqlQuery v_query;
//    //            QStringList lst_vehicle_no;
//    //            if(databaseObj->selectQuery("select vehicle_no from vehicle_registration where vehicle_owner='0'",v_query))
//    //            {
//    //                lst_vehicle_no.clear();
//    //                if(v_query.next())
//    //                {
//    //                    lst_vehicle_no << v_query.value(0).toString().trimmed();
//    //                    while(v_query.next())
//    //                    {
//    //                        lst_vehicle_no << v_query.value(0).toString().trimmed();
//    //                    }
//    //                }
//    //                qDebug()<<"lst_vehicle_no ===>>>"<<lst_vehicle_no;
//    //                if(lst_vehicle_no.size() > 0)
//    //                {
//    //                    for(int i=0;i<lst_vehicle_no.size();i++)
//    //                    {
//    //                        QString diff2 = get_difference(lst_vehicle_no.at(i));
//    //                        qDebug()<<"diff2 ===>>>"<<diff2;
//    //                        if(diff2.toInt() > 0)
//    //                        {
//    //                            print.addData(QString(lst_vehicle_no.at(i)).toUpper().leftJustified(12,' ')+": "+diff ,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
//    //                        }

//    //                    }
//    //                }
//    //            }

//    diesel_report_qur.clear();

//    if(databaseObj->selectQuery("select open_diesel_reading,close_diesel_reading from day_master where day_no=(select day_master.day_no from day_master where day_master.id_day=(SELECT MAX(id_day) FROM day_master where status='0'))",diesel_report_qur ))
//    {
//        if(diesel_report_qur.next())
//        {
//            print.addData("CLOSING STOCK  : "+diesel_report_qur.value(1).toString().trimmed()+" Lts",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
//        }
//    }
//    print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
//    print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
//    print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
//    print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

//    if(print.print(false,false))
//    {
//        //        call_Report();
//    }

    ui->groupBox->hide();
    ui->groupBox_diesel_consumption->show();
    ui->groupBox_diesel_consumption->raise();

    ui->dateEdit_from_diesel->setFocus();



}

//void Report::on_comboBox_batch_currentIndexChanged(const QString &arg1)
//{
//    qDebug()<<"on_comboBox_batch_currentIndexChanged ===>>>";
//    ui->label_purchase->clear();
//    ui->label_husk_bale->clear();
//    ui->label_bale->clear();
//    ui->label_purchase->clear();
//    ui->label_gain_lose->clear();
//}

void Report::on_pushButton_print_supplier_report_clicked()
{
    print_supplier_report();
}

void Report::on_pushButton_print_bale_production_clicked()
{
    QString last_date = QString::number(QDate::currentDate().daysInMonth());

    QString from_date = ui->dateEdit_from_bale_production->date().toString("yyyy-MM-dd");
    QString to_date = ui->dateEdit_to_bale_production->date().toString("yyyy-MM-dd");

    QSqlQuery month_report_qur;
    int nif_count = 0;
    int vcp_count = 0;
    if(databaseObj->selectQuery("select day_master.day_no,day_master.open_date,sum(bale_produced),bale_dispatched,bale_dispatched_to,closing_balance,opening_bale_balance from day_close inner join day_master on day_master.day_no = day_close.day_no where day_close.day_no in (select day_no from day_master  where (substr(open_date, 7, 4) || '-' || substr(open_date, 4, 2) || '-' || substr(open_date, 1, 2)) between '"+from_date+"' and '"+to_date+"' and status='0') group by day_close.day_no",month_report_qur))
    {
        if(month_report_qur.next())
        {
#if(SDK75)
            CPrinter print;
            print.setFontType(CPrinter::eFontType_font2);

            print.addData("Bale Production & Supply Report",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            print.addData("FROM :"+ui->dateEdit_from_bale_production->date().toString("dd-MM-yyyy")+"  TO: "+ui->dateEdit_to_bale_production->date().toString("dd-MM-yyyy"),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            print.addData("DATE OpStock PROD SUPPLY PARTY CpStock",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);


            //            print.addData("Day No       :"+month_report_qur.value(0).toString().trimmed(),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            //            print.addData("Day Date     :"+month_report_qur.value(1).toString().trimmed(),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            //            print.addData("Bale Produced:"+month_report_qur.value(2).toString().trimmed()+" Nos",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            //            print.addData("Bale Dispatch:"+month_report_qur.value(3).toString().trimmed()+" Nos",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);



            QString dispatched_to = month_report_qur.value(4).toString().trimmed();
            float count = month_report_qur.value(3).toString().toFloat();

            qDebug()<<"count ===>>>"<<count;

            QString dispatched_to_name;
            if(count > 0)
            {
                if(dispatched_to.contains("nif",Qt::CaseInsensitive)){
                    dispatched_to_name = "nif";
                    nif_count+=1;
                }
                if(dispatched_to.contains("vcp",Qt::CaseInsensitive)){
                    dispatched_to_name = "vcp";
                    vcp_count+=1;
                }
            }


            //            print.addData("Dispatch To  :"+dispatched_to,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            //            print.addData("Closing Bale :"+month_report_qur.value(5).toString().trimmed()+" Nos",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);



            QString to_print;
            to_print = month_report_qur.value(1).toString().trimmed().leftJustified(5,' ',1)+" "+month_report_qur.value(6).toString().trimmed().rightJustified(5,' ',1)+" "+month_report_qur.value(2).toString().trimmed().rightJustified(5,' ',1)+month_report_qur.value(3).toString().trimmed().rightJustified(5,' ',1)+" "+dispatched_to_name.rightJustified(5,' ',1)+" "+month_report_qur.value(5).toString().trimmed().rightJustified(5,' ',1);
            qDebug()<<"to_print Bale Production & Supply Report ===>>>"<<to_print;
            print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);


            while(month_report_qur.next())
            {
                //                print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                //                print.addData("Day No       :"+month_report_qur.value(0).toString().trimmed(),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                //                print.addData("Day Date     :"+month_report_qur.value(1).toString().trimmed(),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                //                print.addData("Bale Produced:"+month_report_qur.value(2).toString().trimmed()+" Nos",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                //                print.addData("Bale Dispatch:"+month_report_qur.value(3).toString().trimmed()+" Nos",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                QString dispatched_to = month_report_qur.value(4).toString().trimmed();
                float count = month_report_qur.value(3).toString().toFloat();

                qDebug()<<"count ===>>>"<<count;

                QString dispatched_to_name;
                if(count > 0)
                {
                    if(dispatched_to.contains("nif",Qt::CaseInsensitive)){
                        dispatched_to_name = "nif";
                        nif_count+=1;
                    }
                    if(dispatched_to.contains("vcp",Qt::CaseInsensitive)){
                        dispatched_to_name = "vcp";
                        vcp_count+=1;
                    }
                }
                QString to_print;
                to_print = month_report_qur.value(1).toString().trimmed().leftJustified(5,' ',1)+" "+month_report_qur.value(6).toString().trimmed().rightJustified(5,' ',1)+" "+month_report_qur.value(2).toString().trimmed().rightJustified(5,' ',1)+month_report_qur.value(3).toString().trimmed().rightJustified(5,' ',1)+" "+dispatched_to_name.rightJustified(5,' ',1)+" "+month_report_qur.value(5).toString().trimmed().rightJustified(5,' ',1);
                qDebug()<<"to_print Bale Production & Supply Report ===>>>"<<to_print;
                print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

                //                print.addData("Dispatch To  :"+dispatched_to,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                //                print.addData("Closing Bale :"+month_report_qur.value(5).toString().trimmed()+" Nos",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            }

            if(nif_count > 0)
            {
                print.addData("Total Loads NIF:"+QString::number(nif_count),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            }
            if(vcp_count > 0)
            {
                print.addData("Total Loads VCP:"+QString::number(vcp_count),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            }

            print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
            if(print.print(false,false))
            {
                call_Report();
            }
#endif

        }
    }
}

void Report::on_pushButton_Employee_Report_clicked()
{
    ui->groupBox->hide();
    ui->groupBox_Employee_Report->show();

    ui->groupBox_Employee_Report->raise();

    ui->dateEdit_from_Employee_Report->setFocus();
}


void Report::on_lineEdit_name_Expense_Report_returnPressed()
{
    if(!ui->lineEdit_name_Expense_Report->text().isEmpty())
    {
        for(int i=0;i<lst_expense_name.size();i++)
        {
            if(lst_expense_name.at(i).compare(ui->lineEdit_name_Expense_Report->text(),Qt::CaseSensitive))
            {
                ui->pushButton_print_Expense_Report->setFocus();
            }
        }
    }

}

void Report::on_lineEdit_name_Employee_Report_returnPressed()
{
    if(!ui->lineEdit_name_Employee_Report->text().isEmpty())
    {
        for(int i=0;i<lst_emp_name.size();i++)
        {
            if(lst_emp_name.at(i).compare(ui->lineEdit_name_Employee_Report->text(),Qt::CaseSensitive))
            {
                ui->pushButton_print_Employee_Report->setFocus();
            }
        }
    }
}

void Report::on_pushButton_print_Receipt_Payment_Report_clicked()
{

    QSqlQuery date_qur;
    QStringList lst_day_no,lst_day_no_date;
    if(databaseObj->selectQuery("select day_no,open_date from day_master  where (substr(open_date, 7, 4) || '-' || substr(open_date, 4, 2) || '-' || substr(open_date, 1, 2)) between '"+ui->dateEdit_from_Receipt_Payment_Report->date().toString("yyyy-MM-dd")+"' and '"+ui->dateEdit_to_Receipt_Payment_Report->date().toString("yyyy-MM-dd")+"'",date_qur))
    {
        if(date_qur.next())
        {
            lst_day_no << date_qur.value(0).toString().trimmed();
            lst_day_no_date << date_qur.value(1).toString().trimmed();
            while(date_qur.next())
            {
                lst_day_no << date_qur.value(0).toString().trimmed();
                lst_day_no_date << date_qur.value(1).toString().trimmed();
            }

        }
    }
    if(lst_day_no.size() > 0)
    {
        CPrinter print;
        print.setFontType(CPrinter::eFontType_font2);
        float total_inflow_amount,total_outflow_amount = 0;
        for(int i=0;i<lst_day_no.size();i++)
        {
            if(i==0)
            {

                print.addData("RECEIPTS & PAYMENT REPORT",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
                print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                print.addData("FROM :"+ui->dateEdit_from_Receipt_Payment_Report->date().toString("dd-MM-yyyy")+"  TO: "+ui->dateEdit_to_Receipt_Payment_Report->date().toString("dd-MM-yyyy"),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

                print.addData("DATE OPBAL INFLOW OUTFLOW CLBAL",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
                print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            }

            float total_amt_per_day = 0;
            QString inflow_cash;
            QSqlQuery inflow_qur;
            if(databaseObj->selectQuery("select sum(cash_from_transaction.cash_recv) from cash_from_transaction where cash_from_transaction.day_no='"+lst_day_no.at(i)+"'",inflow_qur))
            {
                if(inflow_qur.next())
                {
                    inflow_cash = inflow_qur.value(0).toString();
                }
            }


            QString open_balance,closing_balance;
            QSqlQuery open_close_qur;
            if(databaseObj->selectQuery("select day_master.opening_cash,day_master.closing_cash from day_master where day_master.day_no='"+lst_day_no.at(i)+"'",open_close_qur))
            {
                if(open_close_qur.next())
                {
                    open_balance = open_close_qur.value(0).toString().trimmed();
                    closing_balance = open_close_qur.value(1).toString().trimmed();
                }
            }

            QSqlQuery out_flow_qur;
            if(databaseObj->selectQuery("select sum(paid) from transaction_master where transaction_master.is_void is null and day_no='"+lst_day_no.at(i)+"'",out_flow_qur))
            {
                if(out_flow_qur.next())
                {
                    total_amt_per_day += out_flow_qur.value(0).toString().toFloat();
                }
            }

            out_flow_qur.clear();
            if(databaseObj->selectQuery("select sum(diesel_transaction.amount) from diesel_transaction where day_no='"+lst_day_no.at(i)+"' and is_payment='1'",out_flow_qur))
            {
                if(out_flow_qur.next())
                {
                    total_amt_per_day += out_flow_qur.value(0).toString().toFloat();
                }
            }

            out_flow_qur.clear();
            if(databaseObj->selectQuery("select sum(paid_salary) from employee_transaction where paid_salary IS NOT NULL and day_no='"+lst_day_no.at(i)+"'",out_flow_qur))
            {
                if(out_flow_qur.next())
                {
                    total_amt_per_day += out_flow_qur.value(0).toString().toFloat();
                }
            }

            out_flow_qur.clear();
            if(databaseObj->selectQuery("select sum(expense_transaction.amount) from expense_transaction where expense_transaction.day_no='"+lst_day_no.at(i)+"'",out_flow_qur))
            {
                if(out_flow_qur.next())
                {
                    total_amt_per_day += out_flow_qur.value(0).toString().toFloat();
                }
            }

            total_inflow_amount = total_inflow_amount+inflow_cash.toFloat();
            total_outflow_amount = total_outflow_amount+total_amt_per_day;
            QString to_print;
            to_print = lst_day_no_date.at(i).rightJustified(5,' ',1)+" "+open_balance.rightJustified(6,' ',1)+" "+inflow_cash.rightJustified(6,' ',1)+" "+QString::number(total_amt_per_day).rightJustified(6,' ',1)+" "+closing_balance.rightJustified(6,' ',1);
            qDebug()<<"receipts and payments ===>>>"<<to_print;
            print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
        }
        print.addData("Total "+QString::number(total_inflow_amount,'f',0)+" "+QString::number(total_outflow_amount,'f',0),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
        print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
        print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
        print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
        print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
        if(print.print(false,false))
        {
            call_Report();
        }
    }



}

void Report::on_pushButton_Expense_report_clicked()
{
    ui->groupBox_Expense_Report->show();
    ui->groupBox_Expense_Report->raise();

    ui->groupBox->hide();

    ui->dateEdit_from_Expense_Report->setFocus();

}

void Report::on_pushButton_print_Expense_Report_clicked()
{
    if(!ui->lineEdit_name_Expense_Report->text().isEmpty())
    {
        qDebug()<<"lst_expense_name ===>>>"<<lst_expense_name.size()<<lst_expense_name;
        for(int i=0;i<lst_expense_name.size();i++)
        {
            qDebug()<<"lst_expense_name at ===>>>"<<i<<lst_expense_name.at(i)<<ui->lineEdit_name_Expense_Report->text();
            if(lst_expense_name.at(i).compare(ui->lineEdit_name_Expense_Report->text(),Qt::CaseSensitive) == 0)
            {
                qDebug()<<"lst_emp_name at i ===>>>"<<lst_expense_name.at(i);
                QSqlQuery date_qur;
                QStringList lst_day_no,lst_day_no_date;
                if(databaseObj->selectQuery("select day_no,open_date from day_master  where (substr(open_date, 7, 4) || '-' || substr(open_date, 4, 2) || '-' || substr(open_date, 1, 2)) between '"+ui->dateEdit_from_Expense_Report->date().toString("yyyy-MM-dd")+"' and '"+ui->dateEdit_to_Expense_Report->date().toString("yyyy-MM-dd")+"'",date_qur))
                {
                    if(date_qur.next())
                    {
                        lst_day_no << date_qur.value(0).toString().trimmed();
                        lst_day_no_date << date_qur.value(1).toString().trimmed();
                        while(date_qur.next())
                        {
                            lst_day_no << date_qur.value(0).toString().trimmed();
                            lst_day_no_date << date_qur.value(1).toString().trimmed();
                        }

                    }
                }
                if(lst_day_no.size() > 0)
                {

                    CPrinter print;
                    print.setFontType(CPrinter::eFontType_font2);

                    print.addData("Expense Report",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);

                    print.addData("Expense Name:"+ui->lineEdit_name_Expense_Report->text().trimmed(),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                    print.addData("FROM :"+ui->dateEdit_from_Expense_Report->date().toString("dd-MM-yyyy")+"  TO: "+ui->dateEdit_to_Expense_Report->date().toString("dd-MM-yyyy"),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

                    print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                    print.addData("Date       BillNo        Amount",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                    print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);


                    float total_expense=0;
                    for(int x=0;x<lst_day_no.size();x++)
                    {
                        QSqlQuery Expense_qur;
//                        expense_transaction.user_id=(select user_master.user_name from user_master where user_master.user_type='1' limit 1) and
                        if(databaseObj->selectQuery("select expense_transaction.user_id,expense_transaction.bill_no,sum(expense_transaction.amount) as total_expense from expense_transaction where expense_transaction.day_no='"+lst_day_no.at(x)+"' and  expense_transaction.expense_name='"+ui->lineEdit_name_Expense_Report->text().trimmed()+"'",Expense_qur))
                        {
                            if(Expense_qur.next())
                            {
                                QString bill_no;
                                QString expense_amount;

                                bill_no = Expense_qur.value(1).toString().trimmed();
                                expense_amount = Expense_qur.value(2).toString().trimmed();

                                total_expense += Expense_qur.value(2).toFloat();

                                if(expense_amount.toFloat() > 0)
                                {
                                    QString to_print;
                                    to_print = lst_day_no_date.at(x).rightJustified(5,' ',1)+" "+bill_no.rightJustified(15,' ',1)+" "+expense_amount.rightJustified(15,' ',1);
                                    qDebug()<<"expense to_print ===>>>"<<to_print;
                                    print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                                }
                            }
                            while(Expense_qur.next())
                            {
                                QString bill_no;
                                QString expense_amount;

                                bill_no = Expense_qur.value(1).toString().trimmed();
                                expense_amount = Expense_qur.value(2).toString().trimmed();

                                total_expense += Expense_qur.value(2).toFloat();

                                if(expense_amount.toFloat() > 0)
                                {
                                    QString to_print;
                                    to_print = lst_day_no_date.at(x).rightJustified(5,' ',1)+" "+bill_no.rightJustified(15,' ',1)+" "+expense_amount.rightJustified(15,' ',1);
                                    qDebug()<<"expense to_print ===>>>"<<to_print;
                                    print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                                }
                            }
                        }
                    }
                    print.addData("Total Expense: Rs "+QString::number(total_expense,'f',2),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

                    print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                    print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                    print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                    print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

                    if(print.print(false,false))
                    {
                        call_Report();
                    }
                }

            }
        }
    }
}

void Report::on_pushButton_print_Employee_Report_clicked()
{
    if(!ui->lineEdit_name_Employee_Report->text().isEmpty())
    {
        qDebug()<<"lst_emp_name ===>>>"<<lst_emp_name;
        for(int i=0;i<lst_emp_name.size();i++)
        {
            if(lst_emp_name.at(i).compare(ui->lineEdit_name_Employee_Report->text(),Qt::CaseSensitive) == 0)
            {
                qDebug()<<"lst_emp_name at i ===>>>"<<lst_emp_name.at(i);
                QSqlQuery date_qur;
                QStringList lst_day_no,lst_day_no_date;
                if(databaseObj->selectQuery("select day_no,open_date from day_master  where (substr(open_date, 7, 4) || '-' || substr(open_date, 4, 2) || '-' || substr(open_date, 1, 2)) between '"+ui->dateEdit_from_Employee_Report->date().toString("yyyy-MM-dd")+"' and '"+ui->dateEdit_to_Employee_Report->date().toString("yyyy-MM-dd")+"'",date_qur))
                {
                    if(date_qur.next())
                    {
                        lst_day_no << date_qur.value(0).toString().trimmed();
                        lst_day_no_date << date_qur.value(1).toString().trimmed();
                        while(date_qur.next())
                        {
                            lst_day_no << date_qur.value(0).toString().trimmed();
                            lst_day_no_date << date_qur.value(1).toString().trimmed();
                        }

                    }
                }
                if(lst_day_no.size() > 0)
                {
                    float total_bale = 0;
                    float total_hrs = 0;
                    float total_hrs_salary = 0;
                    float total_paid = 0;
                    float total_calc_salary = 0;
                    CPrinter print;
                    print.setFontType(CPrinter::eFontType_font2);


                    print.addData("Employee Report",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);

                    print.addData("Employee Name:"+ui->lineEdit_name_Employee_Report->text().trimmed(),CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

                    print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                    print.addData("DATE OpBal PROD Hrs Salary Paid clBal",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                    print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);


                    for(int x=0;x<lst_day_no.size();x++)
                    {
                        QSqlQuery emp_qur;
                        QString str_produced_bale,str_hrs,str_hrs_salary,str_paid,str_calc_salary,str_op_bal,str_op_bal_type,str_cl_bal,str_cl_bal_type;
                        if(databaseObj->selectQuery("select sum(employee_transaction.produced_bale) as produced_bale,sum(employee_transaction.working_hrs) as working_hrs,sum(employee_transaction.working_hrs_salary) as hrs_salary,sum(employee_transaction.paid_salary) as paid,sum(employee_transaction.calc_salary) as calc_salary from employee_transaction where employee_transaction.emp_name='"+ui->lineEdit_name_Employee_Report->text().trimmed()+"' and employee_transaction.day_no='"+lst_day_no.at(x)+"'",emp_qur))
                        {
                            if(emp_qur.next())
                            {
                                str_produced_bale = emp_qur.value(0).toString();
                                str_hrs = emp_qur.value(1).toString();
                                str_hrs_salary = emp_qur.value(2).toString();
                                str_paid = emp_qur.value(3).toString();
                                str_calc_salary = emp_qur.value(4).toString();

                                total_bale += emp_qur.value(0).toFloat();
                                total_hrs += emp_qur.value(1).toFloat();
                                total_hrs_salary += emp_qur.value(2).toFloat();
                                total_paid += emp_qur.value(3).toFloat();
                                total_calc_salary += emp_qur.value(4).toFloat();

                                emp_qur.clear();

                                if(databaseObj->selectQuery("select employee_transaction.opening_balance,employee_transaction.opening_balance_type from employee_transaction where rowid=(select min(rowid) from employee_transaction where employee_transaction.emp_name='"+ui->lineEdit_name_Employee_Report->text().trimmed()+"' and employee_transaction.day_no='"+lst_day_no.at(x)+"')",emp_qur))
                                {
                                    if(emp_qur.next())
                                    {
                                        str_op_bal = emp_qur.value(0).toString();
                                        str_op_bal_type = emp_qur.value(1).toString();

                                        if(emp_qur.value(1).toInt() == 0)
                                        {
                                            str_op_bal.prepend("+");
                                        }
                                        if(emp_qur.value(1).toInt() == 1)
                                        {
                                            str_op_bal.prepend("-");
                                        }
                                    }
                                }

                                emp_qur.clear();

                                if(databaseObj->selectQuery("select employee_transaction.pending_salary,employee_transaction.emp_balance_type from employee_transaction where rowid=(select max(rowid) from employee_transaction where employee_transaction.emp_name='"+ui->lineEdit_name_Employee_Report->text().trimmed()+"' and employee_transaction.day_no='"+lst_day_no.at(x)+"')",emp_qur))
                                {
                                    if(emp_qur.next())
                                    {
                                        str_cl_bal = emp_qur.value(0).toString();
                                        str_cl_bal_type = emp_qur.value(1).toString();

                                        if(emp_qur.value(1).toInt() == 0)
                                        {
                                            str_cl_bal.prepend("+");
                                        }
                                        if(emp_qur.value(1).toInt() == 1)
                                        {
                                            str_cl_bal.prepend("-");
                                        }
                                    }
                                }


                                QString to_print;
                                to_print = lst_day_no_date.at(x).rightJustified(5,' ',1)+" "+str_op_bal.rightJustified(5,' ',1)+" "+str_produced_bale.rightJustified(3,' ',1)+" "+str_hrs.rightJustified(4,' ',1)+" "+str_calc_salary.rightJustified(5,' ',1)+" "+str_paid.rightJustified(5,' ',1)+" "+str_cl_bal.rightJustified(5,' ',1);
                                qDebug()<<"to_print employee report ===>>>"<<to_print;
                                print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

                                while(emp_qur.next())
                                {
                                    str_produced_bale = emp_qur.value(0).toString();
                                    str_hrs = emp_qur.value(1).toString();
                                    str_hrs_salary = emp_qur.value(2).toString();
                                    str_paid = emp_qur.value(3).toString();
                                    str_calc_salary = emp_qur.value(4).toString();

                                    total_bale += emp_qur.value(0).toFloat();
                                    total_hrs += emp_qur.value(1).toFloat();
                                    total_hrs_salary += emp_qur.value(2).toFloat();
                                    total_paid += emp_qur.value(3).toFloat();
                                    total_calc_salary += emp_qur.value(4).toFloat();

                                    emp_qur.clear();

                                    if(databaseObj->selectQuery("select employee_transaction.opening_balance,employee_transaction.opening_balance_type from employee_transaction where rowid=(select min(rowid) from employee_transaction where employee_transaction.emp_name='"+ui->lineEdit_name_Employee_Report->text().trimmed()+"' and employee_transaction.day_no='"+lst_day_no.at(x)+"')",emp_qur))
                                    {
                                        if(emp_qur.next())
                                        {
                                            str_op_bal = emp_qur.value(0).toString();
                                            str_op_bal_type = emp_qur.value(1).toString();

                                            if(emp_qur.value(1).toInt() == 0)
                                            {
                                                str_op_bal.prepend("+");
                                            }
                                            if(emp_qur.value(1).toInt() == 1)
                                            {
                                                str_op_bal.prepend("-");
                                            }
                                        }
                                    }

                                    emp_qur.clear();

                                    if(databaseObj->selectQuery("select employee_transaction.pending_salary,employee_transaction.emp_balance_type from employee_transaction where rowid=(select max(rowid) from employee_transaction where employee_transaction.emp_name='"+ui->lineEdit_name_Employee_Report->text().trimmed()+"' and employee_transaction.day_no='"+lst_day_no.at(x)+"')",emp_qur))
                                    {
                                        if(emp_qur.next())
                                        {
                                            str_cl_bal = emp_qur.value(0).toString();
                                            str_cl_bal_type = emp_qur.value(1).toString();

                                            if(emp_qur.value(1).toInt() == 0)
                                            {
                                                str_cl_bal.prepend("+");
                                            }
                                            if(emp_qur.value(1).toInt() == 1)
                                            {
                                                str_cl_bal.prepend("-");
                                            }
                                        }
                                    }

                                    QString to_print;
                                    to_print = lst_day_no_date.at(x).rightJustified(5,' ',1)+" "+str_op_bal.rightJustified(5,' ',1)+" "+str_produced_bale.rightJustified(3,' ',1)+" "+str_hrs.rightJustified(4,' ',1)+" "+str_calc_salary.rightJustified(5,' ',1)+" "+str_paid.rightJustified(5,' ',1)+" "+str_cl_bal.rightJustified(5,' ',1);
                                    qDebug()<<"to_print employee report ===>>>"<<to_print;
                                    print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                                }
                            }
                        }
                    }

                    print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                    print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                    print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                    print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);

                    if(print.print(false,false))
                    {
                        call_Report();
                    }
                }
            }
        }
    }
}

void Report::on_pushButton_receipt_payment_clicked()
{
    ui->groupBox->hide();

    ui->groupBox_Receipt_Payment_Report->show();
    ui->groupBox_Receipt_Payment_Report->raise();

    ui->dateEdit_from_Receipt_Payment_Report->setFocus();
}

void Report::on_lineEdit_bunk_name_returnPressed()
{

    selected_bunk_id.clear();
    selected_bunk_name.clear();

    if(!ui->lineEdit_bunk_name->text().isEmpty())
    {
        QSqlQuery selected_bunk_qur;
        QString op_bal,op_bal_type,cl_bal,cl_bal_type,paid,amount,lts,lts_amt;
        if(databaseObj->selectQuery("select * from bunk_master where bunk_master.bunk_name='"+ui->lineEdit_bunk_name->text().trimmed()+"'",selected_bunk_qur))
        {
            if(selected_bunk_qur.next())
            {
                selected_bunk_id = selected_bunk_qur.value(0).toString().trimmed();
                selected_bunk_name = selected_bunk_qur.value(1).toString().trimmed();

                ui->pushButton_print_bunk_report->setEnabled(true);
                ui->pushButton_print_bunk_report->setFocus();
            }
        }


    }
}

void Report::on_pushButton_print_bunk_report_clicked()
{
    QSqlQuery date_qur;
    QStringList lst_day_no,lst_day_no_date;
    if(databaseObj->selectQuery("select day_no,open_date from day_master  where (substr(open_date, 7, 4) || '-' || substr(open_date, 4, 2) || '-' || substr(open_date, 1, 2)) between '"+ui->dateEdit_from_bunk->date().toString("yyyy-MM-dd")+"' and '"+ui->dateEdit_to_bunk->date().toString("yyyy-MM-dd")+"'",date_qur))
    {
        if(date_qur.next())
        {
            lst_day_no << date_qur.value(0).toString().trimmed();
            lst_day_no_date << date_qur.value(1).toString().trimmed();
            while(date_qur.next())
            {
                lst_day_no << date_qur.value(0).toString().trimmed();
                lst_day_no_date << date_qur.value(1).toString().trimmed();
            }

        }
    }
    if(lst_day_no.size() > 0)
    {
        CPrinter print;
        print.setFontType(CPrinter::eFontType_font2);
        for(int i=0;i<lst_day_no.size();i++)
        {
            if(i==0)
            {

                print.addData("Bunk REPORT",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
                print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                print.addData("FROM :"+ui->dateEdit_from_bunk->date().toString("dd-MM-yyyy")+"  TO: "+ui->dateEdit_to_bunk->date().toString("dd-MM-yyyy"),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

                print.addData("DATE OPBAL  LTS AMT PAID  CLBAL",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
                print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
            }

            QSqlQuery selected_bunk_qur;
            QString op_bal,op_bal_type,cl_bal_type;
            float cl_bal=0;
            float lts = 0;
            float lts_amt = 0;
            float paid = 0;
            float amount = 0;
            if(databaseObj->selectQuery("select * from diesel_transaction where diesel_transaction.day_no='"+lst_day_no.at(i)+"' and diesel_transaction.bunk_id='"+selected_bunk_id+"'",selected_bunk_qur))
            {
                if(selected_bunk_qur.next())
                {
                    op_bal = selected_bunk_qur.value(7).toString().trimmed();
                    if(selected_bunk_qur.value(8).toInt() == 0)
                        op_bal_type = "+";
                    if(selected_bunk_qur.value(8).toInt() == 1)
                        op_bal_type = "-";

                    cl_bal = selected_bunk_qur.value(9).toFloat();
                    if(selected_bunk_qur.value(10).toInt() == 0)
                        cl_bal_type = "+";
                    if(selected_bunk_qur.value(10).toInt() == 1)
                        cl_bal_type = "-";

                    if(selected_bunk_qur.value(6).toInt() == 1)
                        paid += selected_bunk_qur.value(3).toFloat();


                    if(selected_bunk_qur.value(6).toInt() == 0)
                    {
                        lts_amt += selected_bunk_qur.value(3).toFloat();
                        lts += selected_bunk_qur.value(2).toFloat();
                    }

                    while(selected_bunk_qur.next())
                    {
                        cl_bal = selected_bunk_qur.value(9).toFloat();
                        if(selected_bunk_qur.value(10).toInt() == 0)
                            cl_bal_type = "+";
                        if(selected_bunk_qur.value(10).toInt() == 1)
                            cl_bal_type = "-";

                        if(selected_bunk_qur.value(6).toInt() == 1)
                            paid += selected_bunk_qur.value(3).toFloat();


                        if(selected_bunk_qur.value(6).toInt() == 0)
                        {
                            lts_amt += selected_bunk_qur.value(3).toFloat();
                            lts += selected_bunk_qur.value(2).toFloat();
                        }
                    }

                    QString to_print = lst_day_no_date.at(i).rightJustified(5,' ',1)+" "+op_bal.prepend(op_bal_type).rightJustified(6,' ',1)+" "+QString::number(lts).rightJustified(4,' ',1)+" "+QString::number(lts_amt).rightJustified(6,' ',1)+" "+QString::number(paid).rightJustified(6,' ',1)+" "+QString::number(cl_bal).prepend(cl_bal_type).rightJustified(6,' ',1);
                    qDebug()<<"bunk report ===>>>"<<to_print;
                    print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);

                }
            }
        }
        print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
        print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
        print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
        print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
        if(print.print(false,false))
        {
            call_Report();
        }
    }

}

void Report::on_pushButton_bunk_report_clicked()
{
    ui->groupBox->hide();

    ui->groupBox_bunk_report->show();
    ui->groupBox_bunk_report->raise();

    ui->dateEdit_from_bunk->setFocus();
}

void Report::on_pushButton_print_diesel_clicked()
{
    QSqlQuery date_qur;
    QStringList lst_day_no,lst_day_no_date;
    if(databaseObj->selectQuery("select day_no,open_date from day_master  where (substr(open_date, 7, 4) || '-' || substr(open_date, 4, 2) || '-' || substr(open_date, 1, 2)) between '"+ui->dateEdit_from_diesel->date().toString("yyyy-MM-dd")+"' and '"+ui->dateEdit_to_diesel->date().toString("yyyy-MM-dd")+"'",date_qur))
    {
        if(date_qur.next())
        {
            lst_day_no << date_qur.value(0).toString().trimmed();
            lst_day_no_date << date_qur.value(1).toString().trimmed();
            while(date_qur.next())
            {
                lst_day_no << date_qur.value(0).toString().trimmed();
                lst_day_no_date << date_qur.value(1).toString().trimmed();
            }

        }
    }

    if(lst_day_no.size() > 0)
    {
        QString last_cl_bal = "0";
        CPrinter print;
        print.setFontType(CPrinter::eFontType_font2);
        for(int i=0;i<lst_day_no.size();i++)
        {
            if(i==0)
            {

                print.addData("Diesel Consumption Report",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
                print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                print.addData("FROM :"+ui->dateEdit_from_diesel->date().toString("dd-MM-yyyy")+"  TO: "+ui->dateEdit_to_diesel->date().toString("dd-MM-yyyy"),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                print.addData("OPST IN BULL  GEN  VAN CLSTOSK",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);


            }

            QSqlQuery diesel_qur;

            if(databaseObj->selectQuery("select day_master.day_no,day_master.open_date,day_master.open_diesel_reading,diesel_usage.vehicle_no,sum(diesel_usage.quantity),day_master.close_diesel_reading from diesel_usage inner join day_master on day_master.day_no=diesel_usage.day_no where diesel_usage.day_no='"+lst_day_no.at(i)+"' group by diesel_usage.vehicle_no",diesel_qur))
            {
                if(diesel_qur.next())
                {
                    QString to_print;
                    QString bull = "0";
                    QString gen = "0";
                    QString van = "0";
                    QString purchase = "0";
                    QString op_st = "0";
                    QString cl_st = "0";


                    op_st = diesel_qur.value(2).toString().trimmed();
                    if(diesel_qur.value(3).toString().trimmed().contains("bull"))
                    {
                        bull = diesel_qur.value(4).toString().trimmed();
                    }
                    else if(diesel_qur.value(3).toString().trimmed().contains("generator"))
                    {
                        gen = diesel_qur.value(4).toString().trimmed();
                    }
                    else
                    {
                        van = diesel_qur.value(4).toString().trimmed();
                    }


                    QSqlQuery diesel_in_qur;
                    if(databaseObj->selectQuery("select day_master.day_no,day_master.open_date,sum(diesel_transaction.quantity) as purchase from diesel_transaction inner join day_master on diesel_transaction.day_no=day_master.day_no where diesel_transaction.day_no='"+lst_day_no.at(i)+"' and diesel_transaction.is_payment=0",diesel_in_qur))
                    {
                        if(diesel_in_qur.next())
                        {
                            purchase = diesel_in_qur.value(2).toString().trimmed();
                        }
                    }
                    last_cl_bal = cl_st = diesel_qur.value(5).toString().trimmed();

                    while(diesel_qur.next())
                    {

                        op_st = diesel_qur.value(2).toString().trimmed();
                        if(diesel_qur.value(3).toString().trimmed().contains("bull"))
                        {
                            bull = diesel_qur.value(4).toString().trimmed();
                        }
                        else if(diesel_qur.value(3).toString().trimmed().contains("generator"))
                        {
                            gen = diesel_qur.value(4).toString().trimmed();
                        }
                        else
                        {
                            van = diesel_qur.value(4).toString().trimmed();
                        }


//                        QSqlQuery diesel_in_qur;
//                        if(databaseObj->selectQuery("select day_master.day_no,day_master.open_date,sum(diesel_transaction.quantity) as purchase from diesel_transaction inner join day_master on diesel_transaction.day_no=day_master.day_no where diesel_transaction.day_no=1 and diesel_transaction.is_payment=0",diesel_in_qur))
//                        {
//                            if(diesel_in_qur.next())
//                            {
//                                purchase = diesel_in_qur.value(2).toString().trimmed();
//                            }
//                        }
                        last_cl_bal = cl_st = diesel_qur.value(5).toString().trimmed();

                    }
                    to_print = op_st.trimmed().rightJustified(5,' ',1)+" "+purchase.trimmed().rightJustified(5,' ',1)+" "+bull.trimmed().rightJustified(5,' ',1)+" "+gen.trimmed().rightJustified(5,' ',1)+" "+van.trimmed().rightJustified(5,' ',1)+" "+cl_st.trimmed().rightJustified(5,' ',1);
                    if(i==0)
                    {
                        print.addData("Opening Stock:"+op_st.trimmed().append(" lts"),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
                        print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                        print.addData("OPST IN  BULL  GEN  VAN  CLSTOCK",CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
                        print.addData("--------------------------------------",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                    }
//                    if(lst_day_no.size()-1 == i)
//                    {
//                    }
                    print.addData(to_print,CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
                    qDebug()<< "diesel report ===>>>"<<to_print;
                }
            }



        }
        print.addData("Closing Stock:"+last_cl_bal.trimmed().append(" lts"),CPrinter::eFontSize_MEDIUM,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_LEFT);
        print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
        print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
        print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
        print.addData("",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_BOLD,CPrinter::eAlignment_LEFT);
        if(print.print(false,false))
        {
            call_Report();
        }
    }
    else
    {
        int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Critical,"No Result\nFound.",16,14);
        call_Report();
    }

}

void Report::on_lineEdit_supplier_vno_textEdited(const QString &arg1)
{
    ui->lineEdit_supplier_vno->setText(arg1.toUpper());
}
