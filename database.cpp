/*****************************************************************************
                                INCLUDES
******************************************************************************/
#include "database.h"
#include "global.h"
#include<QDir>
#include<QMessageBox>

using namespace Global;
/*****************************************************************************
                                MACROS
******************************************************************************/
#define DB_DRIVER ("QSQLITE") /** The Database Driver name. */
#define DB_NAME ("/home/root/nif.db");
//const QString DB_PATH =QDir::currentPath();  /** The Database Path. */


CDatabase::CDatabase()
{
    /* add the database driver for sqlite */
    con= QSqlDatabase::addDatabase(DB_DRIVER);
    qDebug()<<"\r local db Constructor called";

}

//bool CDatabase::openConnections()
bool CDatabase::openConnections(QString DB_name)
{
    try
    {
        qDebug()<<"\r test1"<<DB_name;
        //        con.setDatabaseName(DB_PATH +"/" +DB_NAME);
        con.setDatabaseName(DB_name);
        /* open the database and check whether opened or not */
        if ( ! con.open() )
        {
            qDebug()<<"\rtest2";
            return false;
        }
        qDebug()<<"\rtest3";
        con=QSqlDatabase::database();
        qDebug()<<"\rtest4";

        if(!createDefaultTables())
        {
            qDebug()<<"\rtest5";
            return false;
        }
        qDebug()<<"\ropen connection passed";
        return true;
    }
    catch(...)
    {
        qDebug()<<"\rtest6";
        return false;
    }
}

bool CDatabase::createDefaultTables()
{
    /** adding flags to all upload tables **/

    /** -----------------------------Creating Table for user_master---------------------------------------- **/
    if(!executeCommand("CREATE TABLE user_master (`id` INTEGER PRIMARY KEY AUTOINCREMENT,`name` VARCHAR(75),`user_name` TEXT(50), `user_password` INTEGER(4),`user_mobile` VARCHAR(20),`user_type` INTEGER(1),`user_designation`TEXT(20),`aval_cash` FLOAT );"))
    {
        qDebug()<<"\ruser_master Table created failed 1";
        if(executeCommand("alter table user_master add `is_active` INTEGER"))
        {
            qDebug()<<"configuration_master Table altered failed 1";
        }
        //        return false;
    }
    else
    {
        qDebug()<<"user_master Table created 1";
        if(executeCommand("alter table user_master add `is_active` INTEGER"))
        {
            qDebug()<<"configuration_master Table altered failed 1";
        }
    }

    /** -----------------------------Creating Table for configuration_master ---------------------------------------- **/

    //!     production_van_batch_status : 0-closed 1-active 2-next

//    , `production_company_batch_no` INTEGER, `production_company_batch_status` INTEGER,`production_auto_batch_no` INTEGER, `production_auto_batch_status` INTEGER, `production_van_batch_no` INTEGER, `production_van_batch_status` INTEGER   ===> removed
    if(!executeCommand("CREATE TABLE `configuration_master` (`id_configuration_master` INTEGER PRIMARY KEY AUTOINCREMENT,`domain_name` TEXT,`device_number` INTEGER,`uid` INTEGER,`app_name` TEXT,`app_logo` TEXT,`company_name` INTEGER,`company_code` INTEGER,`bill_name` TEXT,`state_code` INTEGER,`last_bill_no` INTEGER,`last_user_name` TEXT,`husk_per_cft` INTEGER,`husk_per_bale` INTEGER,`rate_of_cft` FLOAT,`rate_of_husk` FLOAT,`auto_rate_of_cft` FLOAT,`auto_rate_of_husk` FLOAT,`van_rate_of_cft` FLOAT,`van_rate_of_husk` FLOAT,`init_bull_reading` INTEGER,`init_gen_reading` INTEGER,`init_eb_reading` INTEGER,`init_diesel_reading` INTEGER,`is_purchase_count` INTEGER,`is_hrs` INTEGER);"))
    {
        qDebug()<<"configuration_master Table created failed 1";
        if(executeCommand("alter table configuration_master add `payment_bill_no` INTEGER"))
        {
            qDebug()<<"configuration_master Table altered failed 1";
        }

        //        return false;
    }
    else
    {
        if(executeCommand("alter table configuration_master add `payment_bill_no` INTEGER"))
        {
            qDebug()<<"configuration_master Table altered failed 1";
        }
        qDebug()<<"configuration_master Table created 1";
        if(databaseObj->executeCommand("insert into configuration_master (last_bill_no,is_purchase_count,is_hrs) values ('0000','1','1')"))
        {

            qDebug()<<"configuration_master bill_no";
        }
    }

    /** -----------------------------Creating Table for vehicle_registration ---------------------------------------- **/
    if(!executeCommand("CREATE TABLE `vehicle_registration` (`id_vehicle_registration` INTEGER PRIMARY KEY AUTOINCREMENT,`vehicle_no` INTEGER,`vehicle_name` INTEGER,`vehicle_length` FLOAT,`vehicle_length_inch` FLOAT,`vehicle_width` FLOAT,`vehicle_width_inch` FLOAT,`vehicle_owner` INTEGER,`customer_id` INTEGER,`odometer_reading` INTEGER);"))
    {
        qDebug()<<"vehicle_registration Table created failed 1";
        //        return false;
    }
    else
    {
        qDebug()<<"vehicle_registration Table created 1";
    }

    /** -----------------------------Creating Table for production_batch_order ---------------------------------------- **/
    if(!executeCommand("CREATE TABLE `production_batch_order` (`id_production_batch_order` INTEGER PRIMARY KEY AUTOINCREMENT, `batch_type` TEXT, `batch_no` INTEGER, `husk_available` INTEGER, `batch_status` INTEGER);"))
    {
        qDebug()<<"production_batch_order Table created failed 1";
        //        return false;
    }
    else
    {
        qDebug()<<"production_batch_order Table created 1";
    }

    /** -----------------------------Creating Table for day_close ---------------------------------------- **/
    //! batch_status ==>> 0: closed 1:open
    if(!executeCommand("CREATE TABLE `day_close` (`id_day_close` INTEGER PRIMARY KEY AUTOINCREMENT, `batch_type` TEXT, `batch_no` INTEGER, `bale_produced` INTEGER, `batch_status` INTEGER, `bale_dispatched` FOLAT, `bale_dispatched_to` INTEGER, `closing_balance` FLOAT, `day_no` INTEGER);"))
    {
        qDebug()<<"day_close Table created failed 1";
        //        return false;
    }
    else
    {
        qDebug()<<"day_close Table created 1";
    }

    /** -----------------------------Creating Table for company_batch_no ---------------------------------------- **/
    if(!executeCommand("CREATE TABLE company_batch_no ( `id_company_batch_no` INTEGER PRIMARY KEY AUTOINCREMENT, `batch_no` INTEGER, `day_no` INTEGER, `inward_stock` INTEGER, `open_date` INTEGER, `open_time` INTEGER, `close_date` INTEGER, `close_time` INTEGER, `status` INTEGER, `total_husk_produced` INTEGER, `est_bale` INTEGER, `manu_bale` INTEGER, `diff_bale` INTEGER, `used_husk` INTEGER, `excess_husk` INTEGER, `open_user_id` INTEGER, `close_user_id` INTEGER, `day_no_close` INTEGER,`production_day_no_open` INTEGER,`production_day_no_close` INTEGER, `production_status` INTEGER)"))
    {
        qDebug()<<"company_batch_no Table created failed 1";
        //        return false;
    }
    else
    {
        qDebug()<<"company_batch_no Table created 1";
    }

    /** -----------------------------Creating Table for other_batch_no ---------------------------------------- **/
    if(!executeCommand("CREATE TABLE other_batch_no ( `id_other_batch_no` INTEGER PRIMARY KEY AUTOINCREMENT, `batch_no` INTEGER, `day_no` INTEGER, `inward_stock` FLOAT, `open_date` DATE, `open_time` TIME, `close_date` DATE, `close_time` TIME, `status` INTEGER, `total_husk_produced` FLOAT, `est_bale` FLOAT, `manu_bale` FLOAT, `diff_bale` FLOAT, `used_husk` FLOAT, `excess_husk` FLOAT, `open_user_id` INTEGER, `close_user_id` INTEGER, `day_no_close` INTEGER,`production_day_no_open` INTEGER,`production_day_no_close` INTEGER, `production_status` INTEGER)"))
    {
        qDebug()<<"other_batch_no Table created failed 1";
        //        return false;
    }
    else
    {
        qDebug()<<"other_batch_no Table created 1";
    }

    /** -----------------------------Creating Table for van_batch_no ---------------------------------------- **/
    if(!executeCommand("CREATE TABLE van_batch_no ( `id_van_batch_no` INTEGER PRIMARY KEY AUTOINCREMENT, `batch_no` INTEGER, `day_no` INTEGER, `inward_stock` FLOAT, `open_date` DATE, `open_time` TIME, `close_date` DATE, `close_time` TIME, `status` INTEGER, `total_husk_produced` FLOAT, `est_bale` FLOAT, `manu_bale` FLOAT, `diff_bale` FLOAT, `used_husk` FLOAT, `excess_husk` FLOAT, `open_user_id` INTEGER, `close_user_id` INTEGER, `day_no_close` INTEGER,`production_day_no_open` INTEGER,`production_day_no_close` INTEGER, `production_status` INTEGER)"))
    {
        qDebug()<<"van_batch_no Table created failed 1";
        //        return false;
    }
    else
    {
        qDebug()<<"van_batch_no Table created 1";
    }

    /** -----------------------------Creating Table for customer_master ---------------------------------------- **/
    //! cus_type 0-supplier 1-broker
    if(!executeCommand("CREATE TABLE customer_master ( `id_customer_master` INTEGER PRIMARY KEY AUTOINCREMENT, `cus_name` TEXT, `cus_mobile` INTEGER, `balance` FLOAT, `balance_type` INTEGER, `id_vehicle_registration` INTEGER,`cus_type` INTEGER)"))
    {
        qDebug()<<"customer_master Table created failed 1";
        //        return false;
    }
    else
    {
        qDebug()<<"customer_master Table created 1";
    }

    /** -----------------------------Creating Table for bunk_master ---------------------------------------- **/
    if(!executeCommand("CREATE TABLE `bunk_master` ( `id_bunk_master` INTEGER PRIMARY KEY AUTOINCREMENT, `bunk_name` INTEGER, `bunk_contact` VARCHAR, `bunk_opening_balance` FLOAT,`bunk_opening_balance_type` INTEGER);"))
    {
        qDebug()<<"bunk_master Table created failed 1";
        //        return false;
    }
    else
    {
        qDebug()<<"bunk_master Table created 1";
    }


    /** -----------------------------Creating Table for diesel_transaction ---------------------------------------- **/
    if(!executeCommand("CREATE TABLE `diesel_transaction` (  `id_diesel_transaction` INTEGER PRIMARY KEY AUTOINCREMENT,  `bunk_id` INTEGER,  `quantity` FLOAT,  `amount` FLOAT,  `day_no` INTEGER,  `user_id` VARCHAR , `is_payment` INTEGER, `opening_balance` FLOAT, `opening_balance_type` INTEGER, `closing_balance` FLOAT, `closing_balance_type` INTEGER);"))
    {
        qDebug()<<"diesel_transaction Table created failed 1";
        //        return false;
    }
    else
    {
        qDebug()<<"diesel_transaction Table created 1";
    }


    /** -----------------------------Creating Table for diesel_transaction ---------------------------------------- **/
    if(!executeCommand("CREATE TABLE `diesel_usage` ( `id_diesel_usage` INTEGER PRIMARY KEY AUTOINCREMENT, `vehicle_no` INTEGER, `quantity` INTEGER, `fill_type` INTEGER, `reading` INTEGER, `day_no` INTEGER, `user_id` INTEGER);"))
    {
        qDebug()<<"diesel_transaction Table created failed 1";
        //        return false;
    }
    else
    {
        qDebug()<<"diesel_transaction Table created 1";
    }

    /** -----------------------------Creating Table for expense_transaction ---------------------------------------- **/
    if(!executeCommand("CREATE TABLE `expense_transaction` ( `id_expense_transaction` INTEGER, `expense_transaction_id` INTEGER, `expense_name` INTEGER, `bill_no` INTEGER, `amount` FLOAT, `day_no` INTEGER, `user_id` INTEGER);"))
    {
        qDebug()<<"expense_transaction Table created failed 1";
        //        return false;
    }
    else
    {
        qDebug()<<"expense_transaction Table created 1";
    }

    /** -----------------------------Creating Table for expense_master ---------------------------------------- **/
    if(!executeCommand("CREATE TABLE expense_master ( `id_expense_master` INTEGER PRIMARY KEY AUTOINCREMENT,`expense_name` TEXT UNIQUE);"))
    {
        qDebug()<<"expense_master Table created failed 1";
        //        return false;
    }
    else
    {
        qDebug()<<"expense_master Table created 1";
    }

    /** -----------------------------Creating Table for employee_master ---------------------------------------- **/
    if(!executeCommand("CREATE TABLE `employee_master` ( `id_employee_master` INTEGER PRIMARY KEY AUTOINCREMENT, `emp_name` TEXT, `emp_contact` VARCHAR, `emp_gender` TEXT, `emp_type` INTEGER, `daily_wages` INTEGER, `emp_target` INTEGER, `emp_target_charge` INTEGER, `emp_balance` FLOAT, `emp_balance_type` INTEGER, `emp_balance_bale` INTEGER, `emp_balance_bale_rate` FLOAT, `is_active` INTEGER);"))
    {
        qDebug()<<"employee_master Table created failed 1";
        //        return false;
    }
    else
    {
        qDebug()<<"employee_master Table created 1";
    }

    /** -----------------------------Creating Table for employee_transaction ---------------------------------------- **/
    if(!executeCommand("CREATE TABLE `employee_transaction` (  `id_employee_transaction` INTEGER PRIMARY KEY AUTOINCREMENT,  `emp_name` TEXT,  `emp_id` INTEGER,  `day_no` INTEGER,  `produced_bale` FLOAT,  `calc_salary` FLOAT, `paid_salary` FLOAT ,  `pending_bale` FLOAT,  `pending_salary` FLOAT, `emp_balance_type` INTEGER,`opening_balance` FLOAT,`opening_balance_type` FLOAT, `working_hrs` FLOAT, `working_hrs_salary` FLOAT,`is_payment` INTEGER);"))
    {
        qDebug()<<"employee_master Table created failed 1";
        //        return false;
    }
    else
    {
        qDebug()<<"employee_master Table created 1";
    }

    /** -----------------------------Creating Table for expense_transaction ---------------------------------------- **/
    if(!executeCommand("CREATE TABLE `expense_transaction` (`id_expense_transaction` INTEGER PRIMARY KEY AUTOINCREMENT,`user_id` INTEGER,`expense_type` INTEGER,`expense_amount` INTEGER,`expense_remarks` INTEGER,`day_no` INTEGER,`batch_no` INTEGER,`expense_date` INTEGER,`expense_time` INTEGER,`upload_txid` INTEGER);"))
    {
        qDebug()<<"expense_transaction Table created failed 1";
        //        return false;
    }
    else
    {
        qDebug()<<"expense_transaction Table created 1";
    }

    /** -----------------------------Creating Table for transaction_master ---------------------------------------- **/
    //! INWARD_TYP 0 - cft ; 1 - count
    if(!executeCommand("CREATE TABLE transaction_master ( `id_transaction_master` INTEGER PRIMARY KEY AUTOINCREMENT, `bill_no` INTEGER, `cus_id` INTEGER, `cus_name` TEXT, `cus_mobile` INTEGER, `vehicle_no` VARCHAR, `vehicle_height` FLOAT, `inward_type` INTEGER, `previous_balance` FLOAT, `est_amt` INTEGER, `excess_amt` INTEGER, `payable` INTEGER, `paid` INTEGER, `balance` FLOAT, `balance_type` FLOAT, `uploade_flag` INTEGER, `day_no` INTEGER, `batch_type` INTEGER, `batch_no` INTEGER ,`odometer_reading` INTEGER, `inward_bale` FLOAT, `inward_hush` FLOAT,`vkms` INTEGER,`is_payment` INTEGER, `approved_amt` FLOAT, `is_gain` INTEGER,`previous_balance_type` INTEGER)"))
    {
        qDebug()<<"transaction_master Table created failed 1";
        if(executeCommand("alter table transaction_master add `is_void` INTEGER"))
        {
            qDebug()<<"transaction_master Table altered for is_void";
        }
        //        return false;
    }
    else
    {
        qDebug()<<"transaction_master Table created 1";
        if(executeCommand("alter table transaction_master add `is_void` INTEGER"))
        {
            qDebug()<<"transaction_master Table altered for is_void";
        }
    }

    /** -----------------------------Creating Table for device_login_master---------------------------------------- **/

    if(!executeCommand("CREATE TABLE device_login_master (`id_user` TEXT(50), `user_name` TEXT(50), `login_time` DATETIME, `session_time` DATETIME, `logout_time` DATETIME, `upload_login` INT(2), `upload_logout` INT(2));"))
    {
        qDebug()<<"device_login_master Table created failed 1";
        //        return false;
    }
    else
    {
        qDebug()<<"device_login_master Table created 1";
    }

    /** -----------------------------Creating Table for day_master---------------------------------------- **/
    if(!executeCommand("CREATE TABLE IF NOT EXISTS day_master (id_day INTEGER PRIMARY KEY AUTOINCREMENT, day_no INT(10), open_date DATE, open_time TIME, close_date DATE, close_time TIME, status  INT(4) default '0', open_user_id INT(10),close_user_id INT(10),`open_bull_reading` INTEGER,`open_gen_reading` INTEGER,`open_eb_reading` INTEGER,`open_diesel_reading` INTEGER,`close_bull_reading` INTEGER,`close_gen_reading` INTEGER,`close_eb_reading` INTEGER,`close_diesel_reading` INTEGER, `opening_bale_balance` FLOAT, `closing_bale_balance` FLOAT, `opening_cash` FLOAT, `closing_cash` FLOAT);"))
    {
        qDebug()<<"\rday_master Table created failed 3";
        return false;
    }
    else
    {
        qDebug()<<"\rday_master Table created 3";
    }

    /** -----------------------------Creating Table for cash_from_transaction ---------------------------------------- **/
    if(!executeCommand("CREATE TABLE cash_from_transaction ( `id_cash_from_transaction` INTEGER PRIMARY KEY AUTOINCREMENT, `user_name` TEXT, `user_type` INTEGER, `avail_cash` FLOAT, `cash_from` TEXT, `cash_recv` FLOAT, `total_aval_cash` FLOAT, `date_time` TIME, `day_no` INTEGER)"))
    {
        qDebug()<<"cash_from_transaction Table created failed 1";
        //        return false;
    }
    else
    {
        qDebug()<<"cash_from_transaction Table created 1";
    }

    /** -----------------------------Creating Table for cash_to_transaction ---------------------------------------- **/
    if(!executeCommand("CREATE TABLE cash_to_transaction ( `id_cash_to_transaction` INTEGER PRIMARY KEY AUTOINCREMENT, `user_name` TEXT, `user_type` INTEGER, `avail_cash` FLOAT, `cash_to_operator` TEXT, `cash_given` FLOAT, `total_aval_cash` FLOAT, `date_time` TIME, `day_no` INTEGER)"))
    {
        qDebug()<<"cash_to_transaction Table created failed 1";
        //        return false;
    }
    else
    {
        qDebug()<<"cash_to_transaction Table created 1";
    }

    /** -----------------------------Creating Table for printer_master---------------------------------------- **/

    //!         Size :  0 - Small | 1 - Medium  |  2 - Big

    //!         Font :  0 - Uni Space(type 1)  | 1 - Bit Stream Sans Mono(type 2)  |  2 - Consola(type 3)

    //!         bold :  0 - regular  |  1 - bold

    if(!executeCommand("CREATE TABLE printer_master (`is_header_on` INTEGER(4),`is_footer_on` INTEGER(4),`font_type` INTEGER(4), `h1` TEXT(100), `h1_size` INTEGER(4), `h1_bold` INTEGER(1), `h2` TEXT(100), `h2_size` INTEGER(4), `h2_bold` INTEGER(1), `h3` TEXT(100), `h3_size` INTEGER(4), `h3_bold` INTEGER(1), `h4` TEXT(100), `h4_size` INTEGER(4), `h4_bold` INTEGER(1), `h5` TEXT(100), `h5_size` INTEGER(4), `h5_bold` INTEGER(1), `h6` TEXT(100), `h6_size` INTEGER(4), `h6_bold` INTEGER(1), `h_img` TEXT(50), `f1` TEXT(100), `f1_size` INTEGER(4), `f1_bold` INTEGER(1), `f2` TEXT(100), `f2_size` INTEGER(4), `f2_bold` INTEGER(1), `f3` TEXT(100), `f3_size` INTEGER(4), `f3_bold` INTEGER(1), `footer_img` TEXT(50));"))
    {
        qDebug()<<"printer_master Table created failed 1";
//        return false;
    }
    else
    {
        qDebug()<<"printer_master Table created 1";

        if(databaseObj->executeCommand("insert into printer_master (font_type) values ('2')"))
        {
            databaseObj->con.commit();
        }

    }

    return true;
}

bool CDatabase::selectQuery(const QString &query,QSqlQuery &resQuery)
{
    qDebug()<<"\r"<<query;
#if DEBUG
#endif
    //    qDebug()<<"\rchk connection";
    if(con.isOpen()) /* check the database connection is open or not */
    {
        //        qDebug()<<"\rconnection open";
        /* execute the query string and give the the result via resQuery */
        if(!(resQuery.exec(query)))
        {
            qDebug()<<"\r"<<resQuery.lastError().text();
            return false;
        }
        //        qDebug()<<"\rinside if";
        resQuery.size();
        return true;
    }
    else
    {
        qDebug()<<"connection opened0000";
        con.open();
        qDebug()<<"connection opened111";
        return false;
    }
    //    qDebug()<<"\rtesting";
}

bool CDatabase::executeQuery(QSqlQuery &sqlQuery)
{
#if DEBUG
    qDebug()<<"\r query : "<<sqlQuery.lastQuery();
#endif
    if(con.isOpen()) /* check the database connection is open or not */
    {
        /* execute the query string and give the the result via resQuery */
        if(!sqlQuery.exec())
        {
            qDebug()<<"\r unable to execute the query";
            return false;
        }
        return true;
    }
    else
    {
        qDebug()<<"\r connection not open in executequery";
        return false;
    }
}

int CDatabase::size(QSqlQuery query)
{
    int size1=0;
    /* count the no of records in the result */
    while(query.next())
    {
        size1++;
    }
    query.clear();
    return size1;
}

bool CDatabase::executeCommand(const QString &query)
{
    qDebug()<<"\r"<<query;
#if DEBUG
#endif
    QSqlQuery q; /* query to execute the command */

    if(con.isOpen()) /* check the database connection is open or not */
    {

        /* execute the command query like INSERT,UPDATE,DELETE,..etc., */
        if(!(q.exec(query)))
        {

            qDebug()<<"\r dfd"<<q.lastError().text();
            return false;
        }
        qDebug()<<"Execute ok";
        q.clear(); /* clear the query result */
        return true;
    }
    else
    {
        return false;
    }
}

void CDatabase::closeConnection()
{
    if(con.isOpen()) /* close the database connection if It is opened */
    {
        qDebug()<<"\r local db connection closed";
        con.close();
    }
}

CDatabase::~CDatabase()
{
    closeConnection();
    QSqlDatabase::removeDatabase(DB_DRIVER); /* remove the database driver */
}

