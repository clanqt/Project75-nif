#include "input_config.h"
#include "ui_input_config.h"

#include <QMessageBox>

#include <global.h>
using namespace Global;

Input_Config::Input_Config(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Input_Config)
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

Input_Config::~Input_Config()
{
    delete ui;
}

void Input_Config::call_Input_Config()
{
    ui->lineEdit_bull->clear();
    ui->lineEdit_cash->clear();
    ui->lineEdit_diesel->clear();
    ui->lineEdit_eb->clear();
    ui->lineEdit_generator->clear();
    ui->lineEdit_husk_per_bale->clear();
    ui->lineEdit_husk_per_cft->clear();

    ui->lineEdit_bull->installEventFilter(this);
    ui->lineEdit_cash->installEventFilter(this);
    ui->lineEdit_diesel->installEventFilter(this);
    ui->lineEdit_eb->installEventFilter(this);
    ui->lineEdit_generator->installEventFilter(this);
    ui->lineEdit_husk_per_bale->installEventFilter(this);
    ui->lineEdit_husk_per_cft->installEventFilter(this);

    //    ui->label_site_site_title->hide();
    //    ui->lineEdit_cash->hide();
    //    ui->label_unit_rs->hide();

    ui->pushButton_save->setEnabled(false);

    QSqlQuery reading_qur;
    if(databaseObj->selectQuery("select configuration_master.init_bull_reading,configuration_master.init_gen_reading,configuration_master.init_eb_reading,configuration_master.init_diesel_reading,configuration_master.husk_per_cft,configuration_master.husk_per_bale from configuration_master",reading_qur))
    {
        if(reading_qur.next())
        {
            last_bull_meter_reading = reading_qur.value(0).toString().trimmed();
            last_gen_meter_reading = reading_qur.value(1).toString().trimmed();
            last_eb_meter_reading = reading_qur.value(2).toString().trimmed();
            last_deisel_reading = reading_qur.value(3).toString().trimmed();
            last_husk_per_cft = reading_qur.value(4).toString().trimmed();
            last_husk_per_bale = reading_qur.value(5).toString().trimmed();
        }
        qDebug()<< "last_bull_meter_reading Input_ConfigObj ===>>>"<<last_bull_meter_reading;
        qDebug()<< "last_gen_meter_reading Input_ConfigObj ===>>>"<<last_gen_meter_reading;
        qDebug()<< "last_eb_meter_reading Input_ConfigObj ===>>>"<<last_eb_meter_reading;
        qDebug()<< "last_deisel_reading Input_ConfigObj ===>>>"<<last_deisel_reading;
        qDebug()<< "last_husk_per_cft Input_ConfigObj ===>>>"<<last_husk_per_cft;
        qDebug()<< "last_husk_per_bale Input_ConfigObj ===>>>"<<last_husk_per_bale;
    }
    ui->lineEdit_husk_per_cft->setText(last_husk_per_cft);
    ui->lineEdit_husk_per_bale->setText(last_husk_per_bale);
    ui->lineEdit_bull->setText(last_bull_meter_reading);
    ui->lineEdit_diesel->setText(last_deisel_reading);
    ui->lineEdit_generator->setText(last_gen_meter_reading);
    ui->lineEdit_eb->setText(last_eb_meter_reading);


    QSqlQuery cash_qur;
    if(databaseObj->selectQuery("select sum(user_master.aval_cash) from user_master",cash_qur))
    {
        if(cash_qur.next())
        {
            ui->lineEdit_cash->setText(cash_qur.value(0).toString().trimmed());
        }
    }


    ui->lineEdit_husk_per_cft->setFocus();
}

void Input_Config::keyPressEvent(QKeyEvent *ke)
{
    if(ke->key()== Qt::Key_Escape)
    {
        this->close();
        menuObj->call_menu();
        menuObj->show();
    }
}

bool Input_Config::eventFilter(QObject *target, QEvent *event)
{
    QKeyEvent *key = static_cast <QKeyEvent*> (event);

    if(target == ui->lineEdit_husk_per_cft)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->lineEdit_husk_per_cft->hasFocus() && !ui->lineEdit_husk_per_cft->text().trimmed().isEmpty())
                {
                    ui->lineEdit_husk_per_bale->setFocus();
                }
            }
        }
    }
    else if(target == ui->lineEdit_husk_per_bale)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->lineEdit_husk_per_bale->hasFocus() && !ui->lineEdit_husk_per_bale->text().trimmed().isEmpty())
                {
                    ui->lineEdit_bull->setFocus();
                }
            }
        }
    }
    else if(target == ui->lineEdit_bull)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->lineEdit_bull->hasFocus() && !ui->lineEdit_bull->text().trimmed().isEmpty())
                {
                    ui->lineEdit_generator->setFocus();
                }
            }
        }
    }
    else if(target == ui->lineEdit_generator)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->lineEdit_generator->hasFocus() && !ui->lineEdit_generator->text().trimmed().isEmpty())
                {
                    ui->lineEdit_eb->setFocus();
                }
            }
        }
    }
    else if(target == ui->lineEdit_eb)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->lineEdit_eb->hasFocus() && !ui->lineEdit_eb->text().trimmed().isEmpty())
                {
                    ui->lineEdit_diesel->setFocus();
                }
            }
        }
    }
    else if(target == ui->lineEdit_diesel)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->lineEdit_diesel->hasFocus() && !ui->lineEdit_diesel->text().trimmed().isEmpty())
                {
                    ui->lineEdit_cash->setEnabled(true);
                    ui->lineEdit_cash->setFocus();
                    //                    ui->pushButton_save->setEnabled(true);
                    //                    ui->pushButton_save->setFocus();
                }
            }
        }
    }
    else if(target == ui->lineEdit_cash)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->lineEdit_cash->hasFocus() && !ui->lineEdit_cash->text().trimmed().isEmpty() && !ui->lineEdit_eb->text().trimmed().isEmpty() && !ui->lineEdit_generator->text().trimmed().isEmpty() && !ui->lineEdit_bull->text().trimmed().isEmpty() && !ui->lineEdit_husk_per_bale->text().trimmed().isEmpty() && !ui->lineEdit_husk_per_cft->text().trimmed().isEmpty())
                {
                    ui->pushButton_save->setEnabled(true);
                    ui->pushButton_save->setFocus();
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

void Input_Config::on_pushButton_save_clicked()
{
#if(SDK75)
    int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Error,"Do You Want To\nUpdate Vehicle\nOdometer",16,14,"YES","NO");
    if(ret==1)
    {
        QSqlQuery v_qur;
        if(databaseObj->selectQuery("select vehicle_registration.vehicle_no,vehicle_registration.odometer_reading from vehicle_registration where vehicle_registration.vehicle_owner=0",v_qur))
        {
            if(v_qur.next())
            {
                /*LOOP:*/                QInputDialog inputDialog;
                QFont font;
                font.setFamily("DejaVu Sans Mono");
                font.setPointSize(14);
                inputDialog.setInputMode(QInputDialog::TextInput);
//                inputDialog.setTextValue(gstrAppName);
                inputDialog.setWindowTitle("Input");
                inputDialog.setTextValue(v_qur.value(1).toString().trimmed());
                inputDialog.setLabelText("Enter Odometer Reading\nfor "+v_qur.value(0).toString().trimmed());
                inputDialog.setFont(font);
                inputDialog.move(25,50);
                inputDialog.setWindowFlags(Qt::FramelessWindowHint);

                //            inputDialog.setTextValue(Home_ScreenObj->HP_cft);

                bool ok;
                ok = inputDialog.exec();

                QString current_batch_bale;

                if(ok && !inputDialog.textValue().isEmpty())
                {
                    if(databaseObj->executeCommand("update vehicle_registration set odometer_reading='"+inputDialog.textValue().trimmed()+"' where vehicle_no='"+v_qur.value(0).toString().trimmed()+"'"))
                    {

                    }
                }
                else
                {
                    //                    goto LOOP;
//                    return;
                }

            }
        }
    }
#endif

    QString manager_id;
    QSqlQuery check_user;
    if(databaseObj->selectQuery("select * from user_master where user_master.user_type='1'",check_user))
    {
        if(check_user.next())
        {
            manager_id = check_user.value(2).toString().trimmed();
        }
    }


    if(databaseObj->executeCommand("update configuration_master set husk_per_cft='"+ui->lineEdit_husk_per_cft->text().trimmed()+"',husk_per_bale='"+ui->lineEdit_husk_per_bale->text().trimmed()+"',init_bull_reading='"+ui->lineEdit_bull->text().trimmed()+"',init_gen_reading='"+ui->lineEdit_generator->text().trimmed()+"',init_eb_reading='"+ui->lineEdit_eb->text().trimmed()+"',init_diesel_reading='"+ui->lineEdit_diesel->text().trimmed()+"'"))
    {
        //            update_user_cash(ui->lineEdit_cash->text().trimmed(),"+",manager_id);

        if(!manager_id.isEmpty())
        {
            if(databaseObj->executeCommand("update user_master set aval_cash='"+ui->lineEdit_cash->text().trimmed()+"' where user_name='"+manager_id+"'"))
            {
                //                    return true;
            }
        }

        qDebug()<<"initial configuration_master saved ===>>>";
#if(NativeCompile)
        QMessageBox gMsg_box;
        QFont gFont;
        gFont.setFamily("DejaVu Sans Mono");
        gFont.setPointSize(12);
        gMsg_box.setFont(gFont);
        gMsg_box.setParent(this);

        if(gMsg_box.information(this, "Success","Initial Configuretion\nSaved Successfully..!",QMessageBox::Ok) == QMessageBox::Ok)
        {
            this->close();
            menuObj->call_menu();
            menuObj->show();
        }
#endif

#if(SDK75)
        int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"Initial Configuretion\nSaved Successfully..!",14,14);
        this->close();
        menuObj->call_menu();
        menuObj->show();
#endif
    }
}
