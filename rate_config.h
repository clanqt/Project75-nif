#ifndef RATE_CONFIG_H
#define RATE_CONFIG_H

#include <QWidget>
#include <QProcess>

namespace Ui {
class Rate_Config;
}

class Rate_Config : public QWidget
{
    Q_OBJECT

public:

    void call_Rate_Config();

    QProcess process;

    QString RP_husk,RP_cft,HP_bale,HP_cft;
    QString RP_husk_auto,RP_cft_auto;
    QString RP_husk_van,RP_cft_van;

    void execProcess(QString ProcessName , QString Message);

    void keyPressEvent(QKeyEvent *ke);

    explicit Rate_Config(QWidget *parent = 0);
    ~Rate_Config();

private slots:

    void on_pushButton_HP_cft_clicked();

    void on_pushButton_HP_bale_clicked();

    void on_pushButton_RP_cft_clicked();

    void on_pushButton_RP_husk_clicked();

    void on_pushButton_save_clicked();

    void on_lineEdit_auto_cft_returnPressed();

    void on_lineEdit_auto_count_returnPressed();

    void on_lineEdit_company_cft_returnPressed();

    void on_lineEdit_company_count_returnPressed();

    void on_lineEdit_van_rate_returnPressed();

    void on_lineEdit_van_count_returnPressed();

    void on_pushButton_back_clicked();

private:
    Ui::Rate_Config *ui;
};

#endif // RATE_CONFIG_H
