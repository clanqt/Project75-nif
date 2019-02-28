#ifndef THREADCLASS_H
#define THREADCLASS_H

#include <QThread>
#include<QStringList>
#include <QEventLoop>
#include <QTimer>

class ThreadClass : public QThread
{
    Q_OBJECT

public:
    explicit ThreadClass(QObject *parent = 0);
    void stop_Thread();
    bool gprsFlag;
    bool thredstatusflag;

    enum Upload_Process
    {
        Sale_Upload = 11 ,
        Product_Upload = 22 ,
        User_login_Upload = 33 ,
        User_logout_Upload = 44
    };

    int Download_in_Process,Upload_in_Process;
    QStringList lstUserServerId,lstName,lstUserName,lstPassword,lstMobile,lstDesignation,lstIsAdmin;
    QStringList lstCategoryServerId,lstCategoryId,lstCategoryName;
    QStringList lstProductServerId,lstProductId,lstProductName,lstProductCategoryId,lstProductPrice;

    QStringList lstSaleUploadBillno,lstSaleUploadBillTxnId;
    QStringList lstProductUploadItemId,lstProductUploadItemTxnId,lstProductUploadItemBillNo;
    QString Current_Uploading_RowId,Current_Uploading_UserLoginRowId,Current_Uploading_UserLogoutRowId;

    QStringList lstUserLoginUploadTxnId,lstUserLoginUploadServerId;
    QStringList lstUserLogoutUploadTxnId,lstUserLogoutUploadServerId;

    QStringList lstHeaderLine,lstHeaderLineBold,lstHeaderLineSize;

public slots:

    void http_get_server_reply(QString rpy);
    void start_Thread();



signals:
    void Thread_stopped(bool);
    void thread_error();
    void readData();
//    void pausethread();
    void thread_data_saved();
    void UploadBackground();



    //    void dataUploadstatus();
private:
    void run();

private slots:
    void errorHandler();
    void pausethread();


};


#endif // THREADCLASS_H
