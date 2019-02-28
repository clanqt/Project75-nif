#include "add_user.h"
#include "ui_add_user.h"

#include <QMessageBox>

#include <global.h>
using namespace Global;

Add_User::Add_User(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Add_User)
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

Add_User::~Add_User()
{
    delete ui;
}

void Add_User::call_Add_User()
{
    ui->lineEdit_name->clear();
    ui->lineEdit_designation->clear();
    ui->lineEdit_modile->clear();
    ui->lineEdit_password->clear();
    ui->lineEdit_user_id->clear();

    edit_user = false;

    ui->lineEdit_name->setReadOnly(false);
    ui->lineEdit_user_id->setReadOnly(false);
    ui->lineEdit_designation->setReadOnly(true);
    ui->lineEdit_modile->setReadOnly(true);
    ui->lineEdit_password->setReadOnly(true);
    ui->comboBox_type->setEnabled(false);

    //    ui->lineEdit_user_id->setReadOnly(true);
    //    ui->lineEdit_name->setReadOnly(true);

    ui->comboBox_type->setCurrentIndex(0);

#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
#endif

    ui->lineEdit_name->setFocus();


    ui->lineEdit_designation->installEventFilter(this);
    ui->lineEdit_modile->installEventFilter(this);
    ui->lineEdit_name->installEventFilter(this);
    ui->lineEdit_password->installEventFilter(this);
    ui->lineEdit_user_id->installEventFilter(this);
    ui->comboBox_type->installEventFilter(this);
    ui->radioButton_active->installEventFilter(this);
    ui->radioButton_inactive->installEventFilter(this);



    QSqlQuery query;
    lst_User_Name.clear();
    lst_User_id.clear();
    if(databaseObj->selectQuery("select id,name,user_name,user_password,user_mobile,user_designation,user_type from user_master",query))
    {
        if(query.next())
        {
            lst_User_Name << query.value(1).toString().trimmed();
            lst_User_id <<  query.value(2).toString().trimmed();
            while(query.next())
            {
                lst_User_Name << query.value(1).toString().trimmed();
                lst_User_id <<  query.value(2).toString().trimmed();
            }
        }
    }

    cmpter = new QCompleter(lst_User_Name,this);
    cmpter->setCaseSensitivity(Qt::CaseInsensitive);
    cmpter->setCompletionMode(QCompleter::PopupCompletion);
    ui->lineEdit_name->setCompleter(cmpter);

    cmpter1 = new QCompleter(lst_User_id,this);
    cmpter1->setCaseSensitivity(Qt::CaseInsensitive);
    cmpter1->setCompletionMode(QCompleter::PopupCompletion);
    ui->lineEdit_user_id->setCompleter(cmpter1);

}

void Add_User::keyPressEvent(QKeyEvent *ke)
{
    if(ke->key()== Qt::Key_Escape)
    {
        if(!edit_user)
        {
            edit_user = false;
            this->close();
            //            Master_Config_MenuObj = new Master_Config_Menu;
            Master_Config_MenuObj->call_Master_Config_Menu();
            Master_Config_MenuObj->show();
        }
        if(edit_user)
            call_Add_User();
    }

    if(ke->key()== Qt::Key_F2)
    {
        ui->lineEdit_user_id->setEnabled(false);
        ui->lineEdit_designation->setReadOnly(false);
        ui->lineEdit_modile->setReadOnly(false);
        ui->lineEdit_password->setReadOnly(false);
        ui->comboBox_type->setEnabled(true);

        ui->pushButton_edit->hide();
        ui->pushButton_save->show();

        ui->lineEdit_modile->setFocus();
        edit_user = true;


    }
}

bool Add_User::eventFilter(QObject *target, QEvent *event)
{
    QKeyEvent *key = static_cast <QKeyEvent*> (event);

    if(target == ui->lineEdit_name)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->lineEdit_name->hasFocus())
                {
                    if(!ui->lineEdit_name->text().isEmpty())
                    {

                        QSqlQuery query;
                        if(databaseObj->selectQuery("select id,name,user_name,user_password,user_mobile,user_designation,user_type from user_master where name='"+ui->lineEdit_name->text().trimmed()+"'",query))
                        {
                            if(query.next())
                            {
                                selected_User_Name = query.value(1).toString().trimmed();
                                selected_User_id =  query.value(2).toString().trimmed();
                                selected_UserPassword =  query.value(3).toString().trimmed();
                                selected_User_mobile =  query.value(4).toString().trimmed();
                                selected_User_Desg =  query.value(5).toString().trimmed();
                                selected_User_Operator =  query.value(6).toString().trimmed();


                                ui->lineEdit_designation->setText(selected_User_Desg);
                                ui->lineEdit_modile->setText(selected_User_mobile);
                                ui->lineEdit_password->setText(selected_UserPassword);
                                ui->comboBox_type->setCurrentIndex(selected_User_Operator.toInt());
                                ui->lineEdit_user_id->setText(selected_User_id);

                                ui->pushButton_edit->show();

                                ui->pushButton_save->hide();

                                ui->lineEdit_name->setFocus();

                                edit_user = true;

                                return true;

                            }


                            ui->pushButton_edit->hide();
                            ui->pushButton_save->show();

                            ui->pushButton_edit->hide();
#if(SDK75)
                            g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
#endif
                            ui->lineEdit_user_id->setFocus();
                            edit_user = false;


                        }



                        //                        ui->lineEdit_user_id->setFocus();
                        return true;
                    }
                }
            }
        }
    }
    else if(target == ui->lineEdit_user_id)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->lineEdit_user_id->hasFocus())
                {
                    if(!ui->lineEdit_user_id->text().isEmpty())
                    {
                        QSqlQuery query;
                        if(databaseObj->selectQuery("select id,name,user_name,user_password,user_mobile,user_designation,user_type from user_master where user_name='"+ui->lineEdit_user_id->text().trimmed()+"'",query))
                        {
                            if(query.next())
                            {
                                selected_User_Name = query.value(1).toString().trimmed();
                                selected_User_id =  query.value(2).toString().trimmed();
                                selected_UserPassword =  query.value(3).toString().trimmed();
                                selected_User_mobile =  query.value(4).toString().trimmed();
                                selected_User_Desg =  query.value(5).toString().trimmed();
                                selected_User_Operator =  query.value(6).toString().trimmed();


                                ui->lineEdit_designation->setText(selected_User_Desg);
                                ui->lineEdit_modile->setText(selected_User_mobile);
                                ui->lineEdit_password->setText(selected_UserPassword);
                                ui->comboBox_type->setCurrentIndex(selected_User_Operator.toInt());
                                ui->lineEdit_user_id->setText(selected_User_id);
                                return true;
                            }
                        }

                        ui->lineEdit_user_id->setEnabled(true);
                        ui->lineEdit_designation->setReadOnly(false);
                        ui->lineEdit_modile->setReadOnly(false);
                        ui->lineEdit_password->setReadOnly(false);
                        ui->comboBox_type->setEnabled(true);

                        ui->pushButton_edit->hide();

#if(SDK75)
                        g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                        ui->lineEdit_modile->setFocus();
                        edit_user = false;

                        return true;
                    }
                }
            }
        }
    }
    else if(target == ui->lineEdit_modile)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->lineEdit_modile->hasFocus())
                {
                    if(!ui->lineEdit_modile->text().isEmpty())
                    {
#if(SDK75)
                        g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
#endif
                        ui->comboBox_type->setFocus();
                        return true;
                    }
                }
            }
        }
    }
    else if(target == ui->lineEdit_password)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->lineEdit_password->hasFocus())
                {
                    if(!ui->lineEdit_password->text().isEmpty() && ui->lineEdit_password->text().length()==4)
                    {
#if(SDK75)
                        g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                        ui->radioButton_active->setFocus();
                        return true;
                    }
                }
            }
        }
    }
    else if(target == ui->radioButton_active || target == ui->radioButton_inactive)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->radioButton_active->hasFocus())
                {
#if(SDK75)
                    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                    ui->radioButton_active->setChecked(true);
                    ui->radioButton_inactive->setChecked(false);
                    ui->pushButton_save->setFocus();
                    return true;
                }
                if(ui->radioButton_inactive->hasFocus())
                {
#if(SDK75)
                    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                    ui->radioButton_inactive->setChecked(true);
                    ui->radioButton_active->setChecked(false);
                    ui->pushButton_save->setFocus();
                    return true;
                }
            }
        }
    }
    else if(target == ui->lineEdit_designation)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->lineEdit_designation->hasFocus())
                {
                    if(!ui->lineEdit_designation->text().isEmpty())
                    {
#if(SDK75)
                        g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                        ui->lineEdit_password->setFocus();
                        return true;
                    }
                }
            }
        }
    }
    else if(target == ui->comboBox_type)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->comboBox_type->hasFocus())
                {
#if(SDK75)
                    g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
#endif
                    ui->lineEdit_designation->setFocus();
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

void Add_User::on_pushButton_save_clicked()
{
    QString str_active;
    if(ui->radioButton_active->isChecked())
        str_active = "1";
    else
        str_active = "0";


    if(!ui->lineEdit_name->text().isEmpty() && !ui->lineEdit_user_id->text().isEmpty() && !ui->lineEdit_user_id->text().isEmpty() && !ui->lineEdit_password->text().isEmpty() && ui->lineEdit_password->text().length()==4 && !ui->lineEdit_designation->text().isEmpty())
    {
        qDebug()<<"user_master edit_user ===>>>"<<edit_user;
        if(!edit_user)
        {
            QSqlQuery qur;
            if(databaseObj->executeCommand("insert into user_master (name,user_name,user_password,user_mobile,user_type,user_designation,aval_cash,is_active) values ('"+ui->lineEdit_name->text().trimmed()+"','"+ui->lineEdit_user_id->text().trimmed()+"','"+ui->lineEdit_password->text().trimmed()+"','"+ui->lineEdit_modile->text().trimmed()+"','"+QString::number(ui->comboBox_type->currentIndex()).trimmed()+"','"+ui->lineEdit_designation->text().trimmed()+"','0','"+str_active+"')"))
            {
                qDebug()<<"user_master data saved ===>>>";

#if(NativeCompile)
                QMessageBox gMsg_box;
                QFont gFont;
                gFont.setFamily("DejaVu Sans Mono");
                gFont.setPointSize(12);
                gMsg_box.setFont(gFont);
                gMsg_box.setParent(this);

                if(gMsg_box.information(this, "Success","User Saved Successfully..!",QMessageBox::Ok) == QMessageBox::Ok)
                {
                    call_Add_User();
                }
#endif

#if(SDK75)
                int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"User Saved Successfully..!",16,14);
                call_Add_User();
#endif
            }
        }
        if(edit_user)
        {

#if(NativeCompile)
            QMessageBox gMsg_box;
            QFont gFont;
            gFont.setFamily("DejaVu Sans Mono");
            gFont.setPointSize(12);
            gMsg_box.setFont(gFont);
            gMsg_box.setParent(this);

            if(databaseObj->executeCommand("update user_master set name='"+ui->lineEdit_name->text().trimmed()+"',user_name='"+ui->lineEdit_user_id->text().trimmed()+"',user_password='"+ui->lineEdit_password->text().trimmed()+"',user_mobile='"+ui->lineEdit_modile->text().trimmed()+"',user_type='"+QString::number(ui->comboBox_type->currentIndex()).trimmed()+"',user_designation='"+ui->lineEdit_designation->text().trimmed()+"'"))
            {
                if(gMsg_box.information(this, "Success","User Saved Successfully..!",QMessageBox::Ok) == QMessageBox::Ok)
                {
                    call_Add_User();
                }
            }
#endif

#if(SDK75)
            if(databaseObj->executeCommand("update user_master set name='"+ui->lineEdit_name->text().trimmed()+"',user_name='"+ui->lineEdit_user_id->text().trimmed()+"',user_password='"+ui->lineEdit_password->text().trimmed()+"',user_mobile='"+ui->lineEdit_modile->text().trimmed()+"',user_type='"+QString::number(ui->comboBox_type->currentIndex()).trimmed()+"',user_designation='"+ui->lineEdit_designation->text().trimmed()+"',is_active='"+str_active+"' where user_name='"+ui->lineEdit_user_id->text().trimmed()+"'"))
            {
                int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"User Saved\nSuccessfully..!",16,14);
                call_Add_User();
                return;
            }
            else
            {
                int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Error,"User Edit\nFailed",16,14);
                call_Add_User();
                return;
            }

#endif
        }
    }
}

void Add_User::on_pushButton_edit_clicked()
{
    edit_user = true;

    ui->lineEdit_name->setReadOnly(true);
    ui->lineEdit_user_id->setReadOnly(true);


    ui->lineEdit_user_id->setEnabled(false);
    ui->lineEdit_designation->setReadOnly(false);
    ui->lineEdit_modile->setReadOnly(false);
    ui->lineEdit_password->setReadOnly(false);
    ui->comboBox_type->setEnabled(true);

    ui->lineEdit_modile->setFocus();
}

void Add_User::on_lineEdit_name_textEdited(const QString &arg1)
{
    ui->lineEdit_designation->clear();
    ui->lineEdit_modile->clear();
    ui->lineEdit_password->clear();
    ui->lineEdit_user_id->clear();

    ui->lineEdit_designation->setReadOnly(true);
    ui->lineEdit_modile->setReadOnly(true);
    ui->lineEdit_password->setReadOnly(true);
    ui->comboBox_type->setEnabled(false);

}
