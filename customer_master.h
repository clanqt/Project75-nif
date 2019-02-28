#ifndef CUSTOMER_MASTER_H
#define CUSTOMER_MASTER_H

#include <QWidget>
#include <QCompleter>

namespace Ui {
class Customer_Master;
}

class Customer_Master : public QWidget
{
    Q_OBJECT

public:

    QCompleter *cmpter,*cmpter1;
    QStringList lst_customer_name,lst_customer_mobile,lst_vehicle_number;
    QString selected_cus_name,selected_cus_mobile,selected_cus_balance,selected_cus_balance_type,selected_cus_id;
    QString selected_vehicle_number_id,selected_vehicle_number,selected_vehicle_name,selected_vehicle_type,selected_vehicle_type_name,selected_vehicle_length,selected_vehicle_length_inch,selected_vehicle_width,selected_vehicle_width_inch,selected_vehicle_height,selected_vehicle_height_inche;
    QString final_count,total_cft,estimated_amount;


    bool is_new_customer;

    void search_vehicle();

    void keyPressEvent(QKeyEvent *ke);

    bool eventFilter(QObject *target, QEvent *event);

    void call_Customer_Master();

    explicit Customer_Master(QWidget *parent = 0);
    ~Customer_Master();

private slots:
    void on_lineEdit_vehicle_number_returnPressed();

    void on_pushButton_vehicle_save_clicked();

    void on_lineEdit_reg_name_returnPressed();

    void on_lineEdit_reg_length_returnPressed();

    void on_lineEdit_reg_length_inche_returnPressed();

    void on_lineEdit_reg_breadth_returnPressed();

    void on_lineEdit_reg_breadth_inche_returnPressed();

    void on_lineEdit_reg_opening_balance_returnPressed();

    void on_lineEdit_vehicle_number_textEdited(const QString &arg1);

private:
    Ui::Customer_Master *ui;
};

#endif // CUSTOMER_MASTER_H
