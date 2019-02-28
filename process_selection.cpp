#include "process_selection.h"
#include "ui_process_selection.h"
#include <QMessageBox>

#include <global.h>
using namespace Global;


Process_Selection::Process_Selection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Process_Selection)
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

Process_Selection::~Process_Selection()
{
    delete ui;
}

void Process_Selection::call_Process_Selection()
{
    ui->pushButton_purchase->setFocus();
}

void Process_Selection::on_pushButton_purchase_clicked()
{

    if(gstrUserType.toInt() == 0 || gstrUserType.toInt() == 2)
    {
        if(!Home_ScreenObj->isDayOpen())
        {
#if(NativeCompile)
                QMessageBox gMsg_box;
                QFont gFont;
                gFont.setFamily("DejaVu Sans Mono");
                gFont.setPointSize(12);
                gMsg_box.setFont(gFont);
                gMsg_box.setParent(this);

                if(gMsg_box.information(this, "Success","Day Not Opened.",QMessageBox::Ok) == QMessageBox::Ok)
                {
                    return;
                }
#endif

#if(SDK75)
                int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"Day Not Opened.",16,14);
                ui->pushButton_purchase->setFocus();
                return;
#endif


        }
    }


    {
        this->close();
        Home_ScreenObj->call_Home_Screen();
        Home_ScreenObj->check_batch();
        Home_ScreenObj->day_shift();
        Home_ScreenObj->show();
    }

}


void Process_Selection::keyPressEvent(QKeyEvent *ke)
{
    if(ke->key()== Qt::Key_F1)
    {
        this->close();
        menuObj->call_menu();
        menuObj->show();
    }
}

void Process_Selection::on_pushButton_payment_clicked()
{
    this->close();
//    PaymentObj = new Payment;
    PaymentObj->call_Payment();
    PaymentObj->show();
}
