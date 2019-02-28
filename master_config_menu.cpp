#include "master_config_menu.h"
#include "ui_master_config_menu.h"

#include <QMessageBox>
#include <global.h>
using namespace Global;

Master_Config_Menu::Master_Config_Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Master_Config_Menu)
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

Master_Config_Menu::~Master_Config_Menu()
{
    delete ui;
}

void Master_Config_Menu::call_Master_Config_Menu()
{
    show_screen(1);

    ui->lineEdit_bunk_name->installEventFilter(this);
    ui->lineEdit_opening_balance->installEventFilter(this);
    ui->lineEdit_bunk_contact->installEventFilter(this);

    ui->radioButton_advance->installEventFilter(this);
    ui->radioButton_pending->installEventFilter(this);

    ui->radioButton_count_off->installEventFilter(this);
    ui->radioButton_count_on->installEventFilter(this);



    ui->pushButton_Customer->setFocus();
}

void Master_Config_Menu::keyPressEvent(QKeyEvent *ke)
{
    if(ke->key()== Qt::Key_Escape)
    {
        if(ui->groupBox_master_config_menu->isVisible())
        {
            this->close();
            menuObj->call_menu();
            menuObj->show();
        }
        if(ui->groupBox_bunk_master->isVisible())
        {
            call_Master_Config_Menu();
        }
        if(ui->groupBox_app_config->isVisible())
        {
            call_Master_Config_Menu();
        }
    }
}

void Master_Config_Menu::show_screen(int screen_no)
{
    if(screen_no == 1)
    {
        ui->groupBox_master_config_menu->show();
        ui->groupBox_master_config_menu->raise();

        ui->groupBox_app_config->hide();
        ui->groupBox_app_config->move(0,0);

        ui->groupBox_bunk_master->hide();
        ui->groupBox_bunk_master->move(0,0);

    }
    else if(screen_no == 2)
    {

        ui->lineEdit_bunk_contact->clear();
        ui->lineEdit_bunk_name->clear();
        ui->lineEdit_opening_balance->clear();


        ui->groupBox_master_config_menu->hide();
        ui->groupBox_master_config_menu->lower();

        ui->groupBox_bunk_master->show();
        ui->groupBox_bunk_master->move(0,0);
        ui->groupBox_bunk_master->raise();

        ui->pushButton_save->setEnabled(false);

#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
#endif
        ui->lineEdit_bunk_name->setFocus();

    }
}

bool Master_Config_Menu::eventFilter(QObject *target, QEvent *event)
{
    QKeyEvent *key = static_cast <QKeyEvent*> (event);

    if(target == ui->lineEdit_bunk_name)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->lineEdit_bunk_name->hasFocus() && !ui->lineEdit_bunk_name->text().trimmed().isEmpty())
                {
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                    ui->lineEdit_bunk_contact->setFocus();
                    return true;
                }
            }
        }
    }
    else if(target == ui->lineEdit_bunk_contact)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->lineEdit_bunk_contact->hasFocus() && !ui->lineEdit_bunk_contact->text().trimmed().isEmpty())
                {
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                    ui->lineEdit_opening_balance->setFocus();
                    return true;
                }
            }
        }
    }
    else if(target == ui->lineEdit_opening_balance)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->lineEdit_opening_balance->hasFocus() && !ui->lineEdit_opening_balance->text().trimmed().isEmpty())
                {
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                    ui->radioButton_pending->setFocus();
                    return true;
                }
            }
        }
    }
    else if(target == ui->radioButton_pending)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->radioButton_pending->hasFocus() && !ui->lineEdit_bunk_name->text().trimmed().isEmpty() && !ui->lineEdit_bunk_contact->text().trimmed().isEmpty() && !ui->lineEdit_opening_balance->text().trimmed().isEmpty())
                {
                    ui->radioButton_advance->setChecked(false);
                    ui->radioButton_pending->setChecked(true);
                    ui->pushButton_save->setEnabled(true);
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                    ui->pushButton_save->setFocus();
                    return true;
                }
            }
        }
    }
    else if(target == ui->radioButton_advance)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->radioButton_advance->hasFocus() && !ui->lineEdit_bunk_name->text().trimmed().isEmpty() && !ui->lineEdit_bunk_contact->text().trimmed().isEmpty() && !ui->lineEdit_opening_balance->text().trimmed().isEmpty())
                {
                    ui->radioButton_advance->setChecked(true);
                    ui->radioButton_pending->setChecked(false);
                    ui->pushButton_save->setEnabled(true);
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_NUMERIC);
#endif
                    ui->pushButton_save->setFocus();
                    return true;
                }
            }
        }
    }

    else if(target == ui->radioButton_count_on)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->radioButton_count_on->hasFocus())
                {
                    ui->radioButton_count_on->setChecked(true);
                    ui->radioButton_count_off->setChecked(false);
                    ui->pushButton_save_app_config->setFocus();
                    return true;
                }
            }
        }
    }

    else if(target == ui->radioButton_count_off)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(key->key() == Qt::Key_Return || key->key() == Qt::Key_Enter)
            {
                if(ui->radioButton_count_off->hasFocus())
                {
                    ui->radioButton_count_on->setChecked(false);
                    ui->radioButton_count_off->setChecked(true);
                    ui->pushButton_save_app_config->setFocus();
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

void Master_Config_Menu::on_pushButton_Customer_clicked()
{
    this->close();
    Customer_MasterObj = new Customer_Master;
    Customer_MasterObj->call_Customer_Master();
    Customer_MasterObj->show();
}

void Master_Config_Menu::on_pushButton_fuel_2_clicked()
{

}

void Master_Config_Menu::on_pushButton_expense_clicked()
{
    this->close();
#if(SDK75)
    g_ccmainObj->setKeypadMode(eKeypadMode_ALPHABETS);
#endif
    Expense_MasterObj->call_Expense_Master();
    Expense_MasterObj->show_screen(1);
    Expense_MasterObj->show();
}

void Master_Config_Menu::on_pushButton_Employee_clicked()
{
    this->close();
    EmployeeMasterObj = new EmployeeMaster;
    EmployeeMasterObj->call_employee_master();
    EmployeeMasterObj->show();
}

void Master_Config_Menu::on_pushButton_fuel_clicked()
{
    show_screen(2);
    ui->lineEdit_bunk_name->setFocus();
}

void Master_Config_Menu::on_pushButton_save_clicked()
{
    if(!ui->lineEdit_bunk_contact->text().isEmpty() && !ui->lineEdit_bunk_name->text().isEmpty() && !ui->lineEdit_opening_balance->text().trimmed().isEmpty())
    {
        QString balance_type;
        if(ui->radioButton_advance->isChecked())
        {
            balance_type = "0";
        }
        else if(ui->radioButton_pending->isChecked())
        {
            balance_type = "1";
        }
        else
        {

        }
        if(databaseObj->executeCommand("insert into bunk_master (bunk_name,bunk_contact,bunk_opening_balance,bunk_opening_balance_type) values ('"+ui->lineEdit_bunk_name->text().trimmed()+"','"+ui->lineEdit_bunk_contact->text().trimmed()+"','"+ui->lineEdit_opening_balance->text().trimmed()+"','"+balance_type+"')"))
        {
            qDebug()<<"bunk_master saved ===>>>";

#if(NativeCompile)
                QMessageBox gMsg_box;
                QFont gFont;
                gFont.setFamily("DejaVu Sans Mono");
                gFont.setPointSize(12);
                gMsg_box.setFont(gFont);
                gMsg_box.setParent(this);

                if(gMsg_box.information(this, "Success","Bunk Saved Successfully..!",QMessageBox::Ok) == QMessageBox::Ok)
                {
                    show_screen(2);
                }
#endif

#if(SDK75)
                int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"Bunk Saved Successfully.",16,14);
                show_screen(2);
#endif

        }
    }
}

void Master_Config_Menu::on_pushButton_user_master_clicked()
{
    this->close();
    Add_UserObj = new Add_User;
    Add_UserObj->call_Add_User();
    Add_UserObj->show();
}

void Master_Config_Menu::on_pushButton_save_app_config_clicked()
{

    if(ui->radioButton_count_on->isChecked())
    {
        if(databaseObj->executeCommand("update configuration_master set is_purchase_count='1'"))
        {
            int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"Count Purchase Enabled.",16,14);
            qDebug()<<"purchase in count is enabled ===>>>";
        }
    }
    if(ui->radioButton_count_off->isChecked())
    {
        if(databaseObj->executeCommand("update configuration_master set is_purchase_count='0'"))
        {
            int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"Count Purchase Disabled.",16,14);
            qDebug()<<"purchase in count is disabled ===>>>";
        }
    }

    if(ui->radioButton_hrs_on->isChecked())
    {
        if(databaseObj->executeCommand("update configuration_master set is_hrs='1'"))
        {
            int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"Count Purchase Enabled.",16,14);
            qDebug()<<"purchase in count is enabled ===>>>";
        }
    }
    if(ui->radioButton_hrs_off->isChecked())
    {
        if(databaseObj->executeCommand("update configuration_master set is_hrs='0'"))
        {
            int ret = g_ccmainObj->messagebox(this,"Status",eMessageType_Success,"Count Purchase Disabled.",16,14);
            qDebug()<<"purchase in count is disabled ===>>>";
        }
    }


    call_Master_Config_Menu();

}


void Master_Config_Menu::on_pushButton_app_config_clicked()
{
    ui->groupBox_master_config_menu->hide();

    ui->groupBox_app_config->move(0,0);
    ui->groupBox_app_config->show();
    ui->groupBox_app_config->raise();

    QSqlQuery is_count;

    if(databaseObj->selectQuery("select is_purchase_count from configuration_master",is_count))
    {
        if(is_count.next())
        {
            if(is_count.value(0).toInt() == 1)
            {
                ui->radioButton_count_on->setFocus();
                ui->radioButton_count_on->setChecked(true);
                ui->radioButton_count_off->setChecked(false);
            }
            if(is_count.value(0).toInt() == 0)
            {
                ui->radioButton_count_off->setFocus();
                ui->radioButton_count_off->setChecked(true);
                ui->radioButton_count_on->setChecked(false);
            }
        }
    }

    is_count.clear();
    if(databaseObj->selectQuery("select is_hrs from configuration_master",is_count))
    {
        if(is_count.next())
        {
            if(is_count.value(0).toInt() == 1)
            {
                ui->radioButton_hrs_on->setFocus();
                ui->radioButton_hrs_on->setChecked(true);
                ui->radioButton_hrs_off->setChecked(false);
            }
            if(is_count.value(0).toInt() == 0)
            {
                ui->radioButton_hrs_off->setFocus();
                ui->radioButton_hrs_off->setChecked(true);
                ui->radioButton_hrs_on->setChecked(false);
            }
        }
    }

//    ui->radioButton_count_on->setFocus();
}
