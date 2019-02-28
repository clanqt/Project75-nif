#include "datatransfer.h"
#include "ui_datatransfer.h"
#include <QDebug>
#include <QDateTime>
#include <QProcess>
#include <qfile.h>
#include <QMessageBox>
#include <QTextStream>
#include <QDir>
#include <QEventLoop>

#include "global.h"


using namespace Global;

DataTransfer::DataTransfer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DataTransfer)
{
    ui->setupUi(this);


    setParent(mdi,Qt::Dialog);

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

DataTransfer::~DataTransfer()
{
    delete ui;
}

void DataTransfer::call_DataTransfer()
{
    dbName = "nif.db";
    dbPath = "/home/root/";

    importError = false;
    fExport = false;
    fImport = false;

    lstExportAs.clear();
    lstTables.clear();

    lstExportAs << "CSV" << "DATABASE";
//    lstTables <<"cancel_req"<<"reprinting_master"<<"configuration_master"<<"static_master"<<"customer_master"<<"station_master"<<"receipt_master"<<"versions"<<"plant_master"<<"user_master"<<"item_master"<<"transaction_master"<<"dc_master"<<"sync_table"<<"mobile_master"<<"user";

    lstTables_import << "bunk_master"<<"configuration_master"<<"customer_master"<<"employee_master"<<"user_master"<<"vehicle_registration";
    lstTables_export << "bunk_master" << "cash_from_transaction" << "cash_to_transaction" << "company_batch_no" << "configuration_master" << "customer_master" << "day_close" << "day_master" << "device_login_master" << "diesel_transaction" << "diesel_usage" << "employee_master" << "employee_transaction" << "expense_master" << "expense_transaction" << "other_batch_no" << "printer_master" << "production_batch_order" << "sqlite_sequence" << "transaction_master" << "user_master" << "van_batch_no" << "vehicle_registration";

    ui->gridLayoutWidget->hide();
    ui->label_Export_Import->hide();

    ui->verticalLayoutWidget->show();
    ui->verticalLayoutWidget->raise();

    ui->label_status->clear();

    ui->radioButton_PC->setFocus();
    ui->radioButton_PC->setChecked(false);
    ui->radioButton_USB->setChecked(false);
}

void DataTransfer::keyPressEvent(QKeyEvent *ke)
{
    if(ke->key()==Qt::Key_Escape)
    {
        on_pushButton_cancel_clicked();
    }
    else if(ke->key() == Qt::Key_Return)
    {
        if(ui->radioButton_PC->hasFocus())
        {
            ui->radioButton_PC->setChecked(true);
            ui->pushButton_upload->setFocus();
        }
        else if(ui->radioButton_USB->hasFocus())
        {
            ui->radioButton_USB->setChecked(true);
            ui->pushButton_upload->setFocus();
        }
        else if(ui->comboBox_db_csv->hasFocus())
        {
            ui->comboBox_select->setFocus();
        }
        else if(ui->comboBox_select->hasFocus())
        {
            on_pushButton_clicked();
        }
    }
}

void DataTransfer::on_pushButton_upload_clicked()
{
    qDebug()<<"\r upload button clicked";
    fExport = true;
    if((ui->radioButton_PC->isChecked()) || (ui->radioButton_USB->isChecked()))
    {
        showExport();
    }
    else
    {
        qDebug()<<"Choose the Mode of Transfer ===>>>";
        g_ccmainObj->messagebox(this,"Error",eMessageType_Error,"Choose the Mode \nof Transfer.");
        {
            fExport = false;
        }
    }
}

void DataTransfer::on_pushButton_download_clicked()
{
    if((ui->radioButton_PC->isChecked()) || (ui->radioButton_USB->isChecked()))
    {
        //! disconnect db to cp
//        databaseObj->con.commit();
//        databaseObj->closeConnection();
        QString cmd1 = "cp "+dbPath+dbName+" /tmp";
        ui->label_status->setText("Please Wait..");
        execProcess(cmd1,"Please Wait...");
        showImport();
        databaseObj->openConnections(dbPath+dbName);
    }
    else
    {
        qDebug()<<"Choose the Mode of Transfer ===>>>";
        g_ccmainObj->messagebox(this,"Error",eMessageType_Error,"Choose the Mode \nof Transfer.");
        {
            enableButtons();
        }
    }
}

void DataTransfer::execProcess(QString ProcessName, QString Message)
{
    qDebug()<<"\r command ===>>>"<<ProcessName;
    QEventLoop loop;
    QProcess process;
    process.setProcessChannelMode(QProcess::MergedChannels);
    QObject::connect(&process, SIGNAL(finished(int,QProcess::ExitStatus)),&loop,SLOT(quit()));
    QObject::connect(&process, SIGNAL(finished(int)),&loop,SLOT(quit()));
    QObject::connect(&process,SIGNAL(error(QProcess::ProcessError)),&loop,SLOT(quit()));
    ui->label_status->setText((Message));
    process.start(ProcessName);

    loop.exec();

    if (process.state() == QProcess::Running )
    {
        process.kill();
    }
    else
    {
        QString stdout = process.readAllStandardOutput();
        qDebug()<<"stdout ===>>>"<<stdout;
        QString stderr = process.readAllStandardError();
        qDebug()<<"stderr ===>>>"<<stderr;
        if(fImport)
        {
            if(!stdout.isEmpty())
            {
                qDebug()<<"stderr import===>>>"<<stderr;
                importError = true;
                //                if(QMessageBox::warning(this,tr("Error"),(ui->comboBox_select->currentText().trimmed()+".csv File is Invalid."),QMessageBox::Ok)==QMessageBox::Ok)
                //                {
                //                    ui->pushButton->setFocus();
                //                }
            }
        }
        //        QFile debug("/tmp/importDebug");
        //        if(debug.exists())
        //        {

        //        }
    }

}

void DataTransfer::enableButtons()
{
    ui->pushButton_backup->setDisabled(false);
    ui->pushButton_download->setDisabled(false);
    ui->pushButton_upload->setDisabled(false);
}

void DataTransfer::disableButtons()
{
    qDebug()<<"test ===>>>2";
    ui->pushButton_backup->setDisabled(true);
    ui->pushButton_download->setDisabled(true);
    ui->pushButton_upload->setDisabled(true);
}

void DataTransfer::on_pushButton_cancel_clicked()
{
    if(fExport || fImport)
    {
        fExport = false;
        fImport = false;
        ui->label_Export_Import->hide();
        ui->gridLayoutWidget->hide();
        ui->verticalLayoutWidget->show();
        ui->horizontalLayoutWidget->show();
        ui->horizontalLayoutWidget->raise();
        //        ui->label_status->clear();
    }
    else
    {
        QString cmd1 = "sh /usr/share/scripts/gadgets/gadgetfilestorage.sh stop";
        ui->label_status->setText("Device Disconnecting..");
        execProcess(cmd1,"Device Disconnecting..");
        ui->label_status->setText("Device Disconnected");

        system("rm /media/file_storage/* -rf");
//        QString cmd2 = "rm /media/file_storage/* -rf";
//        ui->label_status->setText("");
//        execProcess(cmd2,"");
        databaseObj->openConnections(dbPath+dbName);
        menuObj->show();
        menuObj->call_menu();
        this->hide();
    }
}

void DataTransfer::showExport()
{
    fExport = true;
//    ui->gridLayoutWidget->move(0,75);

    ui->label_Export_Import->setText(tr("Export"));
    ui->label_db_csv->setText(tr("Export AS:"));
    ui->pushButton->setText(tr("Export"));

    ui->label_Export_Import->show();
    ui->label_Export_Import->raise();

    ui->gridLayoutWidget->show();
    ui->gridLayoutWidget->raise();

    ui->verticalLayoutWidget->hide();
    ui->horizontalLayoutWidget->hide();

    ui->label_select->show();
    ui->comboBox_select->show();

    ui->comboBox_db_csv->clear();
    ui->comboBox_select->clear();
    ui->comboBox_db_csv->addItems(lstExportAs);
    ui->comboBox_select->addItems(lstTables_export);

    QString cmd2 = "sh /usr/share/scripts/gadgets/gadgetfilestorage.sh stop";
    execProcess(cmd2,"");
}

void DataTransfer::showImport()
{
    fImport = true;
//    ui->gridLayoutWidget->move(0,75);

    ui->pushButton->setText(tr("Import"));
    ui->label_Export_Import->setText(tr("Import"));
    ui->label_db_csv->setText(tr("Import:"));
    ui->label_select->setText(tr("Select Table\nTo Import:"));

    ui->label_Export_Import->show();
    ui->label_Export_Import->raise();
    ui->gridLayoutWidget->show();
    ui->gridLayoutWidget->raise();
    ui->verticalLayoutWidget->hide();
    ui->horizontalLayoutWidget->hide();

    ui->label_select->show();
    ui->comboBox_select->show();

    ui->comboBox_db_csv->clear();
    ui->comboBox_select->clear();

    ui->comboBox_db_csv->addItems(lstExportAs);
    ui->comboBox_select->addItems(lstTables_import);


    QString cmd1 = "sh /usr/share/scripts/gadgets/gadgetfilestorage.sh stop";
    ui->label_status->setText("Device Connecting.");
    execProcess(cmd1,"Device Connecting.");
    ui->label_status->setText("Device Connecting..");

    QString cmd2 = "sh /usr/share/scripts/gadgets/gadgetfilestorage.sh start";
    ui->label_status->setText("Device Connecting..");
    execProcess(cmd2,"Device Connecting...");
    ui->label_status->setText("Device Connected");


}

void DataTransfer::on_comboBox_db_csv_currentIndexChanged(const QString &arg1)
{
    if(ui->comboBox_db_csv->currentText().contains("CSV"))
    {
        ui->comboBox_select->show();
        ui->label_select->show();
    }
    else
    {
        ui->comboBox_select->hide();
        ui->label_select->hide();
    }
}

void DataTransfer::on_pushButton_clicked()
{
    databaseObj->con.commit();
    databaseObj->closeConnection();
    if(fExport)
    {
        if(ui->radioButton_PC->isChecked())
        {
            qDebug()<<"Mode of transfer: PC ===>>>";

            if(ui->comboBox_db_csv->currentText().contains("CSV"))
            {
                QString tmpDB = "cp "+dbPath+dbName+" /tmp/";
                execProcess(tmpDB,"");

                writeScriptFile();


                QString cmd1 = "sh /home/root/sqlite_to_csv/export_db.sh";
                ui->label_status->setText("Exporting Database..");
                execProcess(cmd1,"Exporting Database...");

                QString cmd2 = "sh /usr/share/scripts/gadgets/gadgetfilestorage.sh stop";
                ui->label_status->setText("Device Connecting.");
                execProcess(cmd2,"Device Connecting.");
                ui->label_status->setText("Device Connecting..");

                QString cmd3 = "sh /usr/share/scripts/gadgets/gadgetfilestorage.sh start";
                ui->label_status->setText("Device Connecting..");
                execProcess(cmd3,"Device Connecting...");

                ui->label_status->setText("CSV Export Complete");
                on_pushButton_cancel_clicked();
            }
            else
            {
                QString cmd1 = "cp "+dbPath+dbName+" /media/file_storage/";
                ui->label_status->setText("Exporting Database..");
                execProcess(cmd1,"Exporting Database...");

                QString cmd2 = "sh /usr/share/scripts/gadgets/gadgetfilestorage.sh start";
                ui->label_status->setText("Device Connecting..");
                execProcess(cmd2,"Device Connecting...");

                ui->label_status->setText("Database Exported");
                on_pushButton_cancel_clicked();
            }
        }
        else
        {
            qDebug()<<"Mode of transfer: USB ===>>>";

            QDir thumbdrive("/media/thumbdrive/");
            if(thumbdrive.exists())
            {
                if(ui->comboBox_db_csv->currentText().contains("CSV"))
                {
                    writeScriptFile();

                    QString cmd1 = "sh /home/root/sqlite_to_csv/export_db.sh";
                    ui->label_status->setText("Exporting CSV..");
                    execProcess(cmd1,"Exporting CSV...");
                    ui->label_status->setText("CSV Export Complete");
                    on_pushButton_cancel_clicked();

                }
                else
                {
                    QString cmd1 = "cp "+dbPath+dbName+" /media/thumbdrive/";
                    ui->label_status->setText("Exporting Database..");
                    execProcess(cmd1,"Exporting Database...");
                    ui->label_status->setText("Database Exported");
                    on_pushButton_cancel_clicked();
                }
            }
            else
            {
                g_ccmainObj->messagebox(this,"Error",eMessageType_Error,"USB Device Not Found.");
                {
                    qDebug()<<"test ===>>>5";
                    ui->pushButton->setFocus();
                }
            }

        }
    }
    else if(fImport)
    {
        if(ui->radioButton_PC->isChecked())
        {
            qDebug()<<"Mode of transfer: USB ===>>>";

            if(ui->comboBox_db_csv->currentText().contains("CSV"))
            {
                QString status_msg;
                writeScriptFile();

                QString cmd1 = "sh /usr/share/scripts/gadgets/gadgetfilestorage.sh stop";
                ui->label_status->setText("Device Connecting.");
                execProcess(cmd1,"Device Connecting.");
                ui->label_status->setText("Device Connecting..");

                QFile importFile("/media/file_storage/"+ui->comboBox_select->currentText().trimmed()+".csv");
                qDebug()<<"size of csv file to import ===>>>"<<importFile.size();
                if((importFile.exists()))
                {
                    if((importFile.size() > 0))
                    {
                        databaseObj->con.commit();
                        databaseObj->closeConnection();

                        QString tmpDB = "cp "+dbPath+dbName+" /tmp/";
                        execProcess(tmpDB,"Importing CSV...");


//                        importError->clear();
                        importError = false;
                        QString cmd1 = "sh /home/root/sqlite_to_csv/import_db.sh";
                        ui->label_status->setText("Importing CSV.");
                        execProcess(cmd1,"Importing CSV..");

                        if(importError)
                        {
                            g_ccmainObj->messagebox(this,"Error",eMessageType_Error,(ui->comboBox_select->currentText().trimmed()+".csv File\nis Invalid."));
                            {
                                importError = false;
                                status_msg = "CSV File Error";
                                ui->pushButton->setFocus();
                                QString cmd3 = "sh /usr/share/scripts/gadgets/gadgetfilestorage.sh start";
                                ui->label_status->setText(status_msg);
                                execProcess(cmd3,status_msg);
                                ui->pushButton->setFocus();
                            }
                        }
                        else
                        {
                            QString cmd4 = "rm "+dbPath+dbName;
                            execProcess(cmd4,"Importing CSV..");

                            QString cmd3 = "cp /tmp/"+dbName+" "+dbPath+"";
                            ui->label_status->setText("Importing CSV...");
                            system("cp /tmp/nif.db /home/root/");
//                            execProcess(cmd3,"Importing CSV...");
                            on_pushButton_cancel_clicked();
                            ui->label_status->setText("CSV Import Complete");
                        }
                    }
                    else
                    {
                        g_ccmainObj->messagebox(this,"Error",eMessageType_Error,(ui->comboBox_select->currentText().trimmed()+".csv File\nis Empty."));
                        {
                            qDebug()<<"test ===>>>5";
                            ui->pushButton->setFocus();
                        }
                    }
                }
                else
                {
                    g_ccmainObj->messagebox(this,"Error",eMessageType_Error,(ui->comboBox_select->currentText().trimmed()+".csv File\nnot found."));

//                    if(QMessageBox::warning(this,tr("Error"),(ui->comboBox_select->currentText().trimmed()+".csv File not found."),QMessageBox::Ok)==QMessageBox::Ok)
                    {
                        qDebug()<<"test ===>>>5";
                        status_msg = "CSV File Error";
                        ui->pushButton->setFocus();
                        QString cmd3 = "sh /usr/share/scripts/gadgets/gadgetfilestorage.sh start";
                        ui->label_status->setText(status_msg);
                        execProcess(cmd3,status_msg);
                    }
                }


            }
            else
            {
                QString cmd1 = "sh /usr/share/scripts/gadgets/gadgetfilestorage.sh stop";
                ui->label_status->setText("Device Connecting.");
                execProcess(cmd1,"Device Connecting.");
                ui->label_status->setText("Device Connecting..");

                QFile importFile("/media/file_storage/"+dbName);
                if((importFile.exists()))
                {
                    databaseObj->con.commit();
                    databaseObj->closeConnection();

                    QString cmd1 = "cp /media/file_storage/"+dbName+" "+dbPath ;
                    ui->label_status->setText("Importing Database..");
                    execProcess(cmd1,"Importing Database...");

                    ui->label_status->setText("Database Import Complete");
                    on_pushButton_cancel_clicked();

                }
                else
                {
                    g_ccmainObj->messagebox(this,"Error",eMessageType_Error,(dbName+" File\nnot found."));
                    {
                        qDebug()<<"test ===>>>5";
                        ui->pushButton->setFocus();
                        QString cmd2 = "sh /usr/share/scripts/gadgets/gadgetfilestorage.sh start";
                        ui->label_status->setText("Device Connecting..");
                        execProcess(cmd2,"Device Connecting...");
                        ui->label_status->setText("Device Connected");
                    }
                }
            }
        }
        else
        {
            qDebug()<<"Mode of transfer: USB ===>>>";

            QDir thumbdrive("/media/thumbdrive/");
            if(thumbdrive.exists())
            {
                if(ui->comboBox_db_csv->currentText().contains("CSV"))
                {
                    writeScriptFile();

                    QString cmd1 = "sh /home/root/sqlite_to_csv/import_db.sh";
                    ui->label_status->setText("Importing CSV..");
                    execProcess(cmd1,"Importing CSV...");
                    ui->label_status->setText("CSV Import Complete");
                    on_pushButton_cancel_clicked();

                }
                else
                {
                    QString cmd1 = "cp "+dbPath+dbName+" /media/thumbdrive/";
                    ui->label_status->setText("Importing Database..");
                    execProcess(cmd1,"Importing Database...");
                    ui->label_status->setText("Database Import Complete");
                    on_pushButton_cancel_clicked();
                }
            }
            else
            {
                g_ccmainObj->messagebox(this,"Error",eMessageType_Error,"USB Device Not\nFound.");
                {
                    qDebug()<<"test ===>>>5";
                    ui->pushButton->setFocus();
                }
            }
        }
    }
}

void DataTransfer::writeScriptFile()
{
    QString outputPath;
    if(fExport)
    {
        if(ui->radioButton_PC->isChecked())
        {
            outputPath = "/media/file_storage/";
        }
        else
        {
            outputPath = "/media/thumbdrive/";
        }

        QStringList EXPORT_sqlite_csv;
        QString tempDB_Path = "/tmp/";

        EXPORT_sqlite_csv << "ATTACH DATABASE '"+tempDB_Path+dbName+"' as '"+dbName+"1';\n";
        EXPORT_sqlite_csv << ".headers on\n";
        EXPORT_sqlite_csv << ".separator |\n";
        EXPORT_sqlite_csv << ".output "+outputPath+ui->comboBox_select->currentText().trimmed()+".csv\n";
        EXPORT_sqlite_csv << "select * from "+ui->comboBox_select->currentText().trimmed()+";\n";
        EXPORT_sqlite_csv << ".quit\n";
        EXPORT_sqlite_csv << "DETACH DATABASE '"+dbName+"1';\n";
        EXPORT_sqlite_csv << ".exit\n";

        QFile exportScript("/home/root/sqlite_to_csv/EXPORT-sqlite-csv");
        exportScript.remove();
        if(exportScript.open(QIODevice::ReadWrite | QIODevice::Append))
        {
            QTextStream fwrite(&exportScript);
            for(int i=0;i<EXPORT_sqlite_csv.size();i++)
            {
                fwrite << EXPORT_sqlite_csv.at(i).toLatin1();;
                qDebug()<<"in script file ===>>>"<<EXPORT_sqlite_csv.at(i).toLatin1();
            }
            exportScript.close();
        }
    }
    else if(fImport)
    {
        if(ui->radioButton_PC->isChecked())
        {
            outputPath = "/media/file_storage/";
        }
        else
        {
            outputPath = "/media/thumbdrive/";
        }

        QStringList IMPORT_sqlite_csv;
        QString tempDB_Path = "/tmp/";

        IMPORT_sqlite_csv << "ATTACH DATABASE '"+tempDB_Path+dbName+"' as '"+dbName+"1';\n";
        IMPORT_sqlite_csv << "DELETE FROM "+ui->comboBox_select->currentText().trimmed()+";\n";
//        IMPORT_sqlite_csv << ".headers off\n";
        IMPORT_sqlite_csv << ".separator |\n";
        IMPORT_sqlite_csv << ".import "+outputPath+ui->comboBox_select->currentText().trimmed()+".csv "+ui->comboBox_select->currentText().trimmed()+"\n";
        IMPORT_sqlite_csv << ".quit\n";
        IMPORT_sqlite_csv << "DETACH DATABASE '"+dbName+"1';\n";
        IMPORT_sqlite_csv << ".exit\n";

        QFile importScript("/home/root/sqlite_to_csv/IMPORT-sqlite-csv");
        //        if(IMPORTScript.exists())
        {
            importScript.remove();
            if(importScript.open(QIODevice::ReadWrite | QIODevice::Append))
            {
                QTextStream fwrite(&importScript);
                for(int i=0;i<IMPORT_sqlite_csv.size();i++)
                {
                    fwrite << IMPORT_sqlite_csv.at(i).toLatin1();;
                    qDebug()<<"in script file ===>>>"<<IMPORT_sqlite_csv.at(i).toLatin1();
                }
                importScript.close();
            }
        }
    }
    else
    {

    }
}

void DataTransfer::on_pushButton_backup_clicked()
{

}

























