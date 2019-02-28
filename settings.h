#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QScrollArea>
#include <QInputDialog>

namespace Ui {
class Settings;
}

class Settings : public QWidget
{
    Q_OBJECT

public:
    QScrollArea *scroll;

    void call_settings();

    void keyPressEvent(QKeyEvent *ke);

    explicit Settings(QWidget *parent = 0);
    ~Settings();
    QInputDialog inputDialog_bill_title;

public slots:
    void callMenu();

private slots:

    void bill_title_entry(QString str);


    void on_pushButton_server_config_clicked();

    void on_lineEdit_domain_name_returnPressed();

    void on_pushButton_settings_back_clicked();

    void on_pushButton_App_name_clicked();

    void on_pushButton_device_name_clicked();

    void on_pushButton_Bill_Title_clicked();

    void on_pushButton_printer_settings_clicked();

    void on_pushButton_device_setting_clicked();

    void on_pushButton_save_clicked();

    void on_pushButton_user_master_clicked();

    void on_pushButton_customer_master_clicked();

private:
    Ui::Settings *ui;
};

#endif // SETTINGS_H
