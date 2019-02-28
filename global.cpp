#include "global.h"
#include <qdebug.h>
#include <QApplication>
using namespace Global;

QMdiArea* Global::mdi = 0;
Login* Global::loginObj = 0;
CDatabase* Global::databaseObj = 0;
Menu* Global::menuObj = 0;
Server_Get_Post* Global::Server_Get_PostObj=0;
Settings* Global::SettingsObj = 0;
PrinterSettings* Global::PrinterSettingsObj = 0;
ThreadClass *Global::threadObj = 0;
Process_Selection *Global::Process_SelectionObj = 0;

Home_Screen *Global::Home_ScreenObj = 0;
Customer_Details *Global::Customer_DetailsObj = 0;
Rate_Config *Global::Rate_ConfigObj = 0;
Add_User *Global::Add_UserObj = 0;
Batch_Close *Global::Batch_CloseObj = 0;
Batch_Configuration *Global::Batch_ConfigurationObj = 0;
Customer_Master *Global::Customer_MasterObj = 0;
Payment *Global::PaymentObj = 0;
EmployeeMaster *Global::EmployeeMasterObj = 0;
Master_Config_Menu *Global::Master_Config_MenuObj = 0;
Input_Config *Global::Input_ConfigObj = 0;
Diesel_Maintanance *Global::Diesel_MaintananceObj = 0;
Expense_Master *Global::Expense_MasterObj = 0;
Day_Close *Global::Day_CloseObj = 0;
Salary_Calculation *Global::Salary_CalculationObj = 0;
Staff_Cash *Global::Staff_CashObj = 0;
Report *Global::ReportObj = 0;
DataTransfer *Global::DataTransferObj = 0;
Void_Last_BIll *Global::Void_Last_BIllObj = 0;

/** LogIN **/
QString Global::gstr_Users_server_id="";
QString Global::gstrUserName="";
QString Global::gstr_Users_Name="";
QString Global::gstr_User_Mobile="";
QString Global::gstr_User_Designation="";
QString Global::gstrUserType="";

QRegExpValidator *Global::gAmtValidator1;
QRegExpValidator *Global::gAmtValidator2;


QString Global::gstrmachineId="";
QString Global::gstrBillNo="";
QString Global::gstrpayBillNo="";
QString Global::gstrServerName="";

QString Global::gstrday_no = "";
QString Global::gstrday_open_date = "";
QString Global::gstrday_close_date = "";
QString Global::gstrday_open_time = "";
QString Global::gstrday_close_time = "";
QString Global::gstrDeviceUdId = "";
QString Global::gstrday_open_bale = "";
QString Global::gstrday_close_bale = "";

QString Global::gstropen_bull_reading = "";
QString Global::gstropen_gen_reading = "";
QString Global::gstropen_eb_reading = "";
QString Global::gstropen_diesel_reading = "";


QString Global::gstrshift_no="";
QString Global::gstrshift_day_number="";
QString Global::gstrshift_open_date = "";
QString Global::gstrshift_close_date = "";
QString Global::gstrshift_open_time = "";
QString Global::gstrshift_close_time = "";

QString Global::gstrshift_no_other ="";
QString Global::gstrshift_day_number_other ="";
QString Global::gstrshift_open_date_other = "";
QString Global::gstrshift_close_date_other = "";
QString Global::gstrshift_open_time_other = "";
QString Global::gstrshift_close_time_other = "";

QString Global::gstrshift_no_van ="";
QString Global::gstrshift_day_number_van ="";
QString Global::gstrshift_open_date_van = "";
QString Global::gstrshift_close_date_van = "";
QString Global::gstrshift_open_time_van = "";
QString Global::gstrshift_close_time_van = "";

QString Global::gstrDeviceName="";
QString Global::gstrAppName="";
QString Global::gstrBillName="";

bool Global::isDay_Open = false;
bool Global::isShift_Open = false;
bool Global::isShift_Open_other = false;
bool Global::isShift_Open_van = false;
bool Global::isDefaultAdmin = false;
bool Global::gthreadFlag = false;

bool Global::isHeaderON = false;
bool Global::isHeaderIMG_ON = false;
bool Global::isFooterON = false;
bool Global::isFooterIMG_ON = false;

QStringList Global::glst_header;
QStringList Global::glst_footer;

QStringList Global::gHerader_Size;
QStringList Global::gFooter_Size;

QStringList Global::gHerader_Bold;
QStringList Global::gFooter_Bold;

QString Global::gDownloadUrl = "";
QString Global::gDownloadFileName = "";
bool Global::gcheckAppDownload=false;





string Global::numToWords(int n, string s)
{

    string one[] = { "", "One ", "Two ", "Three ", "Four ",
                     "Five ", "Six ", "Seven ", "eight ",
                     "Nine ", "Ten ", "Eleven ", "Twelve ",
                     "Thirteen ", "Fourteen ", "Fifteen ",
                     "Sixteen ", "Seventeen ", "Eighteen ",
                     "Nineteen "
                   };

    // strings at index 0 and 1 are not used, they is to
    // make array indexing simple
    string ten[] = { "", "", "Twenty ", "Thirty ", "Forty ",
                     "Fifty ", "Sixty ", "Seventy ", "Eighty ",
                     "Ninety "
                   };


    string str = "";
    // if n is more than 19, divide it
    if (n > 19)
        str += ten[n / 10] + one[n % 10];
    else
        str += one[n];

    // if n is non-zero
    if (n)
        str += s;

    cout << str << endl;

    return str;
}

// Function to print a given number in words
string Global::convertToWords(long n)
{

    qDebug()<<"in convertToWords ===>>>";

    string one[] = { "", "One ", "Two ", "Three ", "Four ",
                     "Five ", "Six ", "Seven ", "eight ",
                     "Nine ", "Ten ", "Eleven ", "Twelve ",
                     "Thirteen ", "Fourteen ", "Fifteen ",
                     "Sixteen ", "Seventeen ", "Eighteen ",
                     "Nineteen "
                   };

    // strings at index 0 and 1 are not used, they is to
    // make array indexing simple
    string ten[] = { "", "", "Twenty ", "Thirty ", "Forty ",
                     "Fifty ", "Sixty ", "Seventy ", "Eighty ",
                     "Ninety "
                   };


    // stores word representation of given number n
    string out;

    // handles digits at ten millions and hundred
    // millions places (if any)
    out += numToWords((n / 10000000), "Core ");

    // handles digits at hundred thousands and one
    // millions places (if any)
    out += numToWords(((n / 100000) % 100), "Lakh ");

    // handles digits at thousands and tens thousands
    // places (if any)
    out += numToWords(((n / 1000) % 100), "Thousand ");

    // handles digit at hundreds places (if any)
    out += numToWords(((n / 100) % 10), "Hundred ");

    if (n > 100 && n % 100)
        out += "& ";

    // handles digits at ones and tens places (if any)
    out += numToWords((n % 100), "");

    cout << out << endl;

    return out;
}

bool Global::isNetwork()
{
#if(SDK75)
    if(!g_ccmainObj->isGprs()&&!g_ccmainObj->isEthernet()&&!g_ccmainObj->isWifi())
    {
        return false;
    }
    return true;
#endif
#if(NativeCompile)
    return true;
#endif
}

void Global::Tab_Key(QObject *obj)
{
    qDebug()<<"test Tab_Key===>>>";
    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_Tab,Qt::NoModifier,QString(QChar(15)));  //navigate using keyboard at the begining of app launch
    qApp->postEvent((QObject*)obj,(QEvent *)eve1);
}

bool Global::update_user_cash(QString cash, QString plus_minus, QString user_name)
{
    if(databaseObj->executeCommand("update user_master set aval_cash=(select aval_cash from user_master where user_name='"+user_name+"')"+plus_minus+cash+" where user_name='"+user_name+"'"))
    {
        return true;
    }
    else
        return false;
}

QString Global::get_cash_available(QString user_name)
{
    QSqlQuery query;
    if(databaseObj->selectQuery("select aval_cash from user_master where user_name='"+user_name+"'",query))
    {
        if(query.next())
        {
            return query.value(0).toString().trimmed();
        }
        else
            return "0";
    }
}
