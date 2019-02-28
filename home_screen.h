#ifndef HOME_SCREEN_H
#define HOME_SCREEN_H

#include <QWidget>

#include <QCompleter>


namespace Ui {
class Home_Screen;
}

class Home_Screen : public QWidget
{
    Q_OBJECT

public:

    QCompleter *cmpter,*cmpter1,*cmpter2;
    QStringList lst_customer_name,lst_customer_mobile,lst_vehicle_number;
    QString selected_cus_name,selected_cus_mobile,selected_cus_balance,selected_cus_balance_type,selected_cus_id,odometer_reading,odometer_reading_old,distaance_covered;
    QString selected_vehicle_number_id,selected_vehicle_number,selected_vehicle_name,selected_vehicle_type,selected_vehicle_type_name,selected_vehicle_length,selected_vehicle_length_inch,selected_vehicle_width,selected_vehicle_width_inch,selected_vehicle_height,selected_vehicle_height_inche,selected_vehicle_length_ft,selected_vehicle_width_ft;
    QString final_count,total_cft,estimated_amount;
    QStringList lst_broker_name,lst_broker_mobile;
    int inward_type;
    QString RP_husk,RP_cft,HP_bale,HP_cft;
    QString RP_husk_auto,RP_cft_auto;
    QString RP_husk_van,RP_cft_van;
    QString company_odometer;

    QString total_husk,est_husk;

    void open_day(QWidget *w);
    void open_shift(QWidget *w); //! company batch
    void open_shift_other(QWidget *w); //! Auto batch
    void open_shift_van(QWidget *w); //! van batch

    void day_shift();



    void close_day(QWidget *w);
    bool close_shift(QWidget *w);
    bool close_shift_other(QWidget *w);
    bool close_shift_van(QWidget *w);

    bool isDayOpen();
    bool isShiftOpen(); //! company batch
    bool isShiftOpen_other(); //! other batch
    bool isShiftOpen_van(); //! van batch

    void call_Home_Screen();

    void set_focus();

    void search_vehicle();

    void keyPressEvent(QKeyEvent *ke);

    bool eventFilter(QObject *target, QEvent *event);

    bool check_batch();

    explicit Home_Screen(QWidget *parent = 0);
    ~Home_Screen();

private slots:
    void on_lineEdit_vehicle_number_returnPressed();

    void on_lineEdit_height_returnPressed();

    void on_lineEdit_customer_name_returnPressed();

    void on_lineEdit_customer_mobile_returnPressed();

    void on_pushButton_next_clicked();

    void on_lineEdit_customer_name_textEdited(const QString &arg1);

    void on_lineEdit_customer_mobile_textEdited(const QString &arg1);

    void on_lineEdit_count_returnPressed();

    void on_lineEdit_reg_name_returnPressed();

    void on_lineEdit_reg_length_returnPressed();

    void on_lineEdit_reg_breadth_returnPressed();

    void on_pushButton_reg_save_clicked();

    void on_radioButton_count_clicked(bool checked);

    void on_radioButton_cft_clicked(bool checked);

    void on_lineEdit_height_inches_returnPressed();

    void on_lineEdit_height_inches_textEdited(const QString &arg1);

    void on_lineEdit_reg_type_returnPressed();

    void on_lineEdit_reg_breadth_inche_returnPressed();

    void on_lineEdit_reg_length_inche_returnPressed();

    void on_lineEdit_reg_opening_balance_returnPressed();

    void on_pushButton_initial_config_save_clicked();

    void on_lineEdit_vehicle_number_textEdited(const QString &arg1);

    void on_lineEdit_height_textEdited(const QString &arg1);

private:
    Ui::Home_Screen *ui;
};

#endif // HOME_SCREEN_H
