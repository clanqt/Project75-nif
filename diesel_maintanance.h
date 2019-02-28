#ifndef DIESEL_MAINTANANCE_H
#define DIESEL_MAINTANANCE_H

#include <QWidget>
#include <QCompleter>
#include <QScrollArea>

namespace Ui {
class Diesel_Maintanance;
}

class Diesel_Maintanance : public QWidget
{
    Q_OBJECT

public:

    QString initial_diesel_stock,bill_no;

    QCompleter *cmpter,*cmpter1;

    QScrollArea *scroll;

    QStringList lst_bunk_name,lst_bunk_id,lst_vehicle_number;

    QString selected_bunk_name;

    void call_Diesel_Maintanance();

    void keyPressEvent(QKeyEvent *ke);

    bool eventFilter(QObject *target, QEvent *event);

    void show_screen(int screen_no);

    explicit Diesel_Maintanance(QWidget *parent = 0);
    ~Diesel_Maintanance();

private slots:
    void on_pushButton_purchase_clicked();

    void on_pushButton_usage_clicked();

    void on_pushButton_bull_clicked();

    void on_pushButton_company_vehicle_clicked();

    void on_pushButton_generator_clicked();

    void on_lineEdit_today_parchase_returnPressed();

    void on_lineEdit_bill_value_returnPressed();

    void on_lineEdit_bunk_name_returnPressed();

    void on_lineEdit_bunk_name_textEdited(const QString &arg1);

    void on_pushButton_save_clicked();

    void on_pushButton_save_usage_clicked();

    void on_lineEdit_meter_reading_returnPressed();

    void on_lineEdit_today_parchase_textChanged(const QString &arg1);

private:
    Ui::Diesel_Maintanance *ui;
};

#endif // DIESEL_MAINTANANCE_H
