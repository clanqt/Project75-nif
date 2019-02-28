#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QTimer>
#include <QEventLoop>
#include <QKeyEvent>
#include <QScrollArea>
#include <QInputDialog>
#include "downloadmanager.h"

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:

    QString UdId,device_status;

    int Download_in_Process,Upload_in_Process;

    int company_or_other;

    enum Download_Process
    {
        Time_Sync = 1 ,
        Device_Status = 2 ,
        Config_download = 3 ,
        User_Download = 4 ,
        Category_Download = 5 ,
        Product_Download = 6
    };
    enum Upload_Process
    {
        Sale_Upload = 1 ,
        Product_Upload = 2
    };

    DownloadManager* mManager;

    QNetworkAccessManager *networkManager_mac_reg;
    QNetworkReply *reply_server;
    QUrl url_mac_reg;

    QTimer *timer_http;
    int timerTimeout;

    QTimer *timer;

    QScrollArea *scroll;

    void keyPressEvent(QKeyEvent *ke);

    void startRequestTimer(QEventLoop &);

    void stopRequestTimer(QEventLoop &);

    void call_menu();

    void check_init_config();

    bool convert_header,convert_footer;

    explicit Menu(QWidget *parent = 0);
    ~Menu();


public slots:

    void http_get_server_reply(QString rpy);

//    void replyFinished(QNetworkReply *);

    void callMenu();

signals:
    void data_saved();


private slots:
    void on_pushButton_device_setting_clicked();

    void on_pushButton_download_clicked();

    void on_pushButton_Configuration_clicked();

    void on_pushButton_rate_config_clicked();

    void on_pushButton_Day_Close_clicked();

    void on_pushButton_Shift_Close_clicked();

    void on_pushButton_Other_batch_close_clicked();

    void on_pushButton_batch_config_clicked();

    void on_pushButton_master_config_clicked();

    void on_pushButton_input_config_clicked();

    void on_pushButton_diesel_clicked();

    void on_pushButton_Reports_clicked();

    void on_pushButton_purchase_clicked();

    void on_pushButton_payment_clicked();

    void on_pushButton_Day_Open_clicked();

    void on_pushButton_Data_transfer_clicked();

    void on_pushButton_Receipt_clicked();

    void on_pushButton_Reset_Data_clicked();

    void on_pushButton_Void_Last_Bill_clicked();

private:
    Ui::Menu *ui;
};

#endif // MENU_H
