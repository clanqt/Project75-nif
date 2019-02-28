#ifndef GLOBAL_H
#define GLOBAL_H


#include <QMdiArea>
#include <login.h>
#include<database.h>
#include "menu.h"
#include "server_get_post.h"
#include "settings.h"
#include "printersettings.h"
#include "threadclass.h"

#include "home_screen.h"
#include "customer_details.h"
#include "rate_config.h"
#include "batch_close.h"
#include "add_user.h"
#include "process_selection.h"
#include "batch_configuration.h"
#include "customer_master.h"
#include "payment.h"
#include "employeemaster.h"
#include "master_config_menu.h"
#include "input_config.h"
#include "diesel_maintanance.h"
#include "expense_master.h"
#include <day_close.h>
#include "salary_calculation.h"
#include "staff_cash.h"
#include "report.h"
#include "datatransfer.h"
#include "void_last_bill.h"

#include <QRegExpValidator>

using namespace std;

#include <iostream>

#if(SDK75)
#include <GlobalClass.h>
#include <device_menu.h>

using namespace Globalclass;
#endif

namespace Global
{
extern QMdiArea* mdi;
extern Login* loginObj;

extern CDatabase *databaseObj;
extern Menu *menuObj;
extern Server_Get_Post *Server_Get_PostObj;
extern Settings *SettingsObj;
extern PrinterSettings *PrinterSettingsObj;
extern ThreadClass *threadObj;
extern Process_Selection *Process_SelectionObj;
extern Batch_Configuration *Batch_ConfigurationObj;
extern Home_Screen *Home_ScreenObj;
extern Customer_Details *Customer_DetailsObj;
extern Rate_Config *Rate_ConfigObj;
extern Batch_Close *Batch_CloseObj;
extern Add_User *Add_UserObj;
extern Customer_Master *Customer_MasterObj;
extern Payment *PaymentObj;
extern EmployeeMaster *EmployeeMasterObj;
extern Master_Config_Menu *Master_Config_MenuObj;
extern Input_Config *Input_ConfigObj;
extern Diesel_Maintanance *Diesel_MaintananceObj;
extern Expense_Master *Expense_MasterObj;
extern Day_Close *Day_CloseObj;
extern Salary_Calculation *Salary_CalculationObj;
extern Staff_Cash *Staff_CashObj;
extern Report *ReportObj;
extern DataTransfer *DataTransferObj;
extern Void_Last_BIll *Void_Last_BIllObj;

extern QRegExpValidator *gAmtValidator1;
extern QRegExpValidator *gAmtValidator2;

extern QString gstr_Users_server_id;
extern QString gstrUserName;
extern QString gstr_Users_Name;
extern QString gstr_User_Mobile;
extern QString gstr_User_Designation;
extern QString gstrUserType;

extern QString gstrmachineId;
extern QString gstrBillNo;
extern QString gstrpayBillNo;
extern QString gstrServerName;

extern QString gstrDeviceName;
extern QString gstrAppName;
extern QString gstrBillName;
extern QString gstrDeviceUdId;

extern QString gstrday_no;
extern QString gstrday_open_date;
extern QString gstrday_close_date;
extern QString gstrday_open_time;
extern QString gstrday_close_time;
extern QString gstrday_open_bale;
extern QString gstrday_close_bale;

extern QString gstropen_bull_reading;
extern QString gstropen_gen_reading;
extern QString gstropen_eb_reading;
extern QString gstropen_diesel_reading;

extern QString gstrshift_no;
extern QString gstrshift_day_number;
extern QString gstrshift_open_date;
extern QString gstrshift_close_date;
extern QString gstrshift_open_time;
extern QString gstrshift_close_time;

extern QString gstrshift_no_other;
extern QString gstrshift_day_number_other;
extern QString gstrshift_open_date_other;
extern QString gstrshift_close_date_other;
extern QString gstrshift_open_time_other;
extern QString gstrshift_close_time_other;

extern QString gstrshift_no_van;
extern QString gstrshift_day_number_van;
extern QString gstrshift_open_date_van;
extern QString gstrshift_close_date_van;
extern QString gstrshift_open_time_van;
extern QString gstrshift_close_time_van;



extern bool isDay_Open;
extern bool isShift_Open;
extern bool isShift_Open_other;
extern bool isShift_Open_van;
extern bool isDefaultAdmin;
extern bool gthreadFlag;

//! ************* HEADER / FOOTER **********

extern bool isHeaderON;
extern bool isHeaderIMG_ON;
extern bool isFooterON;
extern bool isFooterIMG_ON;

extern QStringList glst_header;
extern QStringList glst_footer;

extern QStringList gHerader_Size;
extern QStringList gFooter_Size;

extern QStringList gHerader_Bold;
extern QStringList gFooter_Bold;

extern QString gDownloadUrl;
extern QString gDownloadFileName;
extern bool gcheckAppDownload;

//! ************* HEADER / FOOTER **********


string numToWords(int n, string s);
string convertToWords(long n);

bool isNetwork();

void Tab_Key(QObject *obj);

bool update_user_cash(QString cash,QString plus_minus,QString user_name);

QString get_cash_available(QString user_name);
}



#endif // GLOBAL_H
