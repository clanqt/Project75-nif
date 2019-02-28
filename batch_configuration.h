#ifndef BATCH_CONFIGURATION_H
#define BATCH_CONFIGURATION_H

#include <QWidget>
#include <QProcess>

namespace Ui {
class Batch_Configuration;
}

class Batch_Configuration : public QWidget
{
    Q_OBJECT

public:

    int company_or_other;

    QProcess process;

    void execProcess(QString ProcessName , QString Message);


    QStringList lst_company_batch_no,lst_van_batch_no,lst_auto_batch_no,lst_batch_name;

    bool is_production_batch_close;

    QString available_stock_company,available_stock_auto,available_stock_van;

    QString str_cmp_pro_batch_status,str_auto_pro_batch_status,str_van_pro_batch_status;
    QString str_cmp_pro_batch_no,str_auto_pro_batch_no,str_van_pro_batch_no,production_batch_count;

    int total_production_batch_active,tmp_total_production_batch_active;

    QStringList lst_production_batch_type,lst_production_batch_no;

    void keyPressEvent(QKeyEvent *ke);

    bool eventFilter(QObject *target, QEvent *event);

    void call_Batch_Configuration();

    void show_screen(int scr);

    void load_details();

    bool from_home_screen;

    explicit Batch_Configuration(QWidget *parent = 0);
    ~Batch_Configuration();

public slots:
    void on_pushButton_purchase_clicked();

    void on_pushButton_Production_clicked();

    void on_pushButton_Company_clicked();

    void on_pushButton_auto_clicked();

    void on_pushButton_van_clicked();

    void on_pushButton_Production_open_clicked();

    void on_pushButton_Production_close_clicked();

    void on_groupBox_company_production_clicked();

    void on_groupBox_company_production_toggled(bool arg1);

    void on_pushButton_purchase_save_clicked();

private:
    Ui::Batch_Configuration *ui;
};

#endif // BATCH_CONFIGURATION_H
