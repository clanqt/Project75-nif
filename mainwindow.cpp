#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#define APP_VER "V1.0.1"
#define APP_DATE "2018-04-06T12:00:00"
#define APP_ID "Q18D06P001"
#define APP_NAME "Billing_Application"
#include <QDir>
#if(NativeCompile)
#define APP_DB "/home/yaswant/Desktop/nif_final_release/nif.db"
#endif

#if(SDK75)
#define APP_DB "/home/root/nif.db"
#endif

#include <global.h>
using namespace Global;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug()<<"MainWindow ===>>>";

#if(NativeCompile)

    mdi=new QMdiArea(this);
    setCentralWidget(mdi);
    mdi->setBackground(QBrush(Qt::white));
    gstrmachineId = "751GH1234";

#endif

//    QSizePolicy sp = this->sizePolicy();
//    sp.setHeightForWidth(true);
//    this->setSizePolicy(sp);


#if(SDK75)

    qDebug()<<"MainWindow ===>>>2";
    MdiArea=new QMdiArea(this);
    setCentralWidget(MdiArea);
    MdiArea->setBackground(QBrush(Qt::white));
    setWindowFlags(Qt::FramelessWindowHint);
    qDebug()<<"MainWindow ===>>>3";
    g_ccmainObj = new CHHC72xx(MdiArea);
    qDebug()<<"MainWindow ===>>>4";
    addToolBar(g_ccmainObj->serverMethod()->HHC80xxPanel());
    qDebug()<<"MainWindow ===>>>5";
    addToolBarBreak(Qt::TopToolBarArea);
    qDebug()<<"MainWindow ===>>>5.0";
    gstrmachineId = g_ccmainObj->machineId().trimmed();
    qDebug()<<"MainWindow ===>>>5.1";

#endif


    gAmtValidator1 = new QRegExpValidator(QRegExp("[0-9]{0,10}"));
    gAmtValidator2 = new QRegExpValidator(QRegExp("[A-Za-z0-9]{0,10}"));

    qDebug()<<"MainWindow ===>>>6";

    setFocusPolicy(Qt::NoFocus);
    setFixedSize(320,240);

    qDebug()<<"MainWindow ===>>>7";

    this->hide();


    databaseObj=new CDatabase();

    if(databaseObj->openConnections(APP_DB))
    {
        qDebug() << "databaseObj openConnections ===>>>";
    }

    QSqlQuery qry;
    if(databaseObj->selectQuery("select domain_name from configuration_master",qry))
    {
        if(qry.next())
        {
            if(qry.value(0).toString().trimmed().isEmpty())
            {
//#if(NativeCompile)
//                gstrServerName="https://cloudide.co.in/workspace/tdcb/api/v1/";
//#endif
//#if(SDK75)
//                gstrServerName="https://cloudide.co.in/workspace/tdcb/api/v1/";
//#endif

            }
            else
                gstrServerName=qry.value(0).toString();
        }

        else
        {
//#if(NativeCompile)
//                gstrServerName="https://cloudide.co.in/workspace/tdcb";
//#endif
//#if(SDK75)
//                gstrServerName="http://sdjmi.com";
//#endif
        }
    }

    QSqlQuery uid_qur;
    if(databaseObj->selectQuery("select configuration_master.uid from configuration_master",uid_qur))
    {
        if(uid_qur.next())
        {
            gstrDeviceUdId = uid_qur.value(0).toString();;
            qDebug()<<"UdId details ===>>>"<<gstrDeviceUdId;
        }
        else
        {
            gstrDeviceUdId = "";
            qDebug()<<"UdId details not available===>>>"<<gstrDeviceUdId;
        }
    }


    Server_Get_PostObj = new Server_Get_Post;
    Server_Get_PostObj->hide();

    threadObj = new ThreadClass;

    loginObj = new Login;
    loginObj->show();

    menuObj = new Menu;
    menuObj->hide();

    PrinterSettingsObj = new PrinterSettings;
    PrinterSettingsObj->assign_printer_details();
    PrinterSettingsObj->hide();

    Home_ScreenObj = new Home_Screen;
    Home_ScreenObj->call_Home_Screen();
    Home_ScreenObj->hide();

    Customer_DetailsObj = new Customer_Details;
    Customer_DetailsObj->hide();

    Batch_ConfigurationObj = new Batch_Configuration;
    Batch_ConfigurationObj->hide();

    Batch_CloseObj = new Batch_Close;
    Batch_CloseObj->hide();


    Process_SelectionObj = new Process_Selection;
    Process_SelectionObj->hide();

    Expense_MasterObj = new Expense_Master;
    Expense_MasterObj->hide();

    Salary_CalculationObj = new Salary_Calculation;
    Salary_CalculationObj->hide();

    Day_CloseObj = new Day_Close;
    Day_CloseObj->hide();

    Staff_CashObj = new Staff_Cash;
    Staff_CashObj->hide();

    PaymentObj = new Payment;
    PaymentObj->hide();

    loginObj->call_login();

}

MainWindow::~MainWindow()
{
    delete ui;
}
