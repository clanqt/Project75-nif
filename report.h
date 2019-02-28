#ifndef REPORT_H
#define REPORT_H

#include <QWidget>
#include <QScrollArea>
#include <QCompleter>


namespace Ui {
class Report;
}

class Report : public QWidget
{
    Q_OBJECT

public:

    QScrollArea *scroll;

    QCompleter *cmpter,*cmpte2,*cmpte3,*cmpte4,*cmpte5,*cmpte6,*cmpte7,*cmpte8;

    QStringList lst_bunk_name,lst_emp_name,lst_expense_name,lst_bunk_name_report,lst_bunk_id_report;

    QStringList lst_day_close_no,lst_broker_name,lst_broker_mobile,lst_batch_no,lst_purchase,lst_bale,lst_husk,lst_husk_bale,lst_gain_lose,lst_vehicle_number;

    QString selected_cus_name,selected_cus_mobile,selected_cus_balance,selected_cus_balance_type,selected_cus_id,odometer_reading;
    QString selected_vehicle_number_id,selected_vehicle_number,selected_vehicle_name,selected_vehicle_type,selected_vehicle_type_name,selected_vehicle_length,selected_vehicle_length_inch,selected_vehicle_width,selected_vehicle_width_inch,selected_vehicle_height,selected_vehicle_height_inche;

    QString selected_bunk_name,selected_bunk_id;

    QString get_difference(QString name);
    QString get_voulume(QString name, QString day_no);

    void print_supplier_report();

    void call_Report();

    void day_close_report();

    void keyPressEvent(QKeyEvent *ke);

    bool eventFilter(QObject *target, QEvent *event);

    explicit Report(QWidget *parent = 0);
    ~Report();

public slots:
    void on_pushButton_day_close_clicked();

    void on_pushButton_batch_close_clicked();

//    void on_comboBox_batch_currentIndexChanged(int index);

    void on_pushButton_supplier_batch_wise_clicked();

    void on_pushButton_bale_clicked();

    void on_pushButton_supplier_clicked();

    void on_lineEdit_supplier_vno_returnPressed();

    void on_lineEdit_supplier_name_returnPressed();

private slots:
//    void on_comboBox_batch_currentTextChanged(const QString &arg1);

    void on_lineEdit_batch_supplier_returnPressed();

    void on_lineEdit_day_no_returnPressed();

    void on_pushButton_stock_status_clicked();

    void on_pushButton_payable_clicked();

    void on_pushButton_diesel_clicked();

//    void on_comboBox_batch_currentIndexChanged(const QString &arg1);

    void on_pushButton_print_supplier_report_clicked();

    void on_pushButton_print_bale_production_clicked();

    void on_pushButton_Employee_Report_clicked();

    void on_pushButton_print_Expense_Report_clicked();

    void on_lineEdit_name_Expense_Report_returnPressed();

    void on_lineEdit_name_Employee_Report_returnPressed();

    void on_pushButton_print_Receipt_Payment_Report_clicked();

    void on_pushButton_Expense_report_clicked();

    void on_pushButton_print_Employee_Report_clicked();

    void on_pushButton_receipt_payment_clicked();

    void on_lineEdit_bunk_name_returnPressed();

    void on_pushButton_print_bunk_report_clicked();

    void on_pushButton_bunk_report_clicked();

    void on_pushButton_print_diesel_clicked();

    void on_lineEdit_supplier_vno_textEdited(const QString &arg1);

private:
    Ui::Report *ui;
};

#endif // REPORT_H
