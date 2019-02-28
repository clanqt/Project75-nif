#ifndef MASTER_CONFIG_MENU_H
#define MASTER_CONFIG_MENU_H

#include <QWidget>

namespace Ui {
class Master_Config_Menu;
}

class Master_Config_Menu : public QWidget
{
    Q_OBJECT

public:

    void call_Master_Config_Menu();

    void keyPressEvent(QKeyEvent *ke);

    bool eventFilter(QObject *target, QEvent *event);

    void show_screen(int screen_no);

    explicit Master_Config_Menu(QWidget *parent = 0);
    ~Master_Config_Menu();

private slots:
    void on_pushButton_Customer_clicked();

    void on_pushButton_fuel_2_clicked();

    void on_pushButton_expense_clicked();

    void on_pushButton_Employee_clicked();

    void on_pushButton_fuel_clicked();

    void on_pushButton_save_clicked();

    void on_pushButton_user_master_clicked();

    void on_pushButton_save_app_config_clicked();

    void on_pushButton_app_config_clicked();

private:
    Ui::Master_Config_Menu *ui;
};

#endif // MASTER_CONFIG_MENU_H
