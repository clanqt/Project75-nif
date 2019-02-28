#ifndef BATCH_CLOSE_H
#define BATCH_CLOSE_H

#include <QWidget>

namespace Ui {
class Batch_Close;
}

class Batch_Close : public QWidget
{
    Q_OBJECT

public:

    QString total_husk,est_husk,manuf_bale,diff_bale,used_husk,excess_husk;
    QStringList lst_vehicle_no;
    QString bale_produced_in_batch;
    QString last_bull_meter_reading,last_gen_meter_reading,last_eb_meter_reading,last_deisel_reading,last_husk_per_cft,last_husk_per_bale;

    float produced_bale_available;

    QStringList lst_production_batch_close_name,lst_production_batch_close_no,lst_production_batch_close_husk,lst_produced_bale;


    QString produced_bale_this,remaining_bale;

    bool from_batch_config;

    void call_Batch_Close();

    void keyPressEvent(QKeyEvent *ke);

    void set_focus();

//    bool eventFilter(QObject *target, QEvent *event);

    explicit Batch_Close(QWidget *parent = 0);
    ~Batch_Close();

signals:
    void goto_next_vihecle();
    void goto_next_batch();

private slots:
    void odo_reading_slot();

    void on_lineEdit_manuf_bale_returnPressed();

    void on_pushButton_close_clicked();

    void on_lineEdit_bull_reading_returnPressed();

    void on_lineEdit_generator_reading_returnPressed();

    void on_lineEdit_eb_reading_returnPressed();

    void on_pushButton_goto_odo_reading_clicked();

    void on_lineEdit_odo_reading_returnPressed();


    void on_pushButton_close_odo_clicked();

    void on_pushButton_odo_save_clicked();

private:
    Ui::Batch_Close *ui;
};

#endif // BATCH_CLOSE_H
