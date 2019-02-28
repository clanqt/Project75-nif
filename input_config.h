#ifndef INPUT_CONFIG_H
#define INPUT_CONFIG_H

#include <QWidget>

namespace Ui {
class Input_Config;
}

class Input_Config : public QWidget
{
    Q_OBJECT

public:

    QString last_bull_meter_reading,last_gen_meter_reading,last_eb_meter_reading,last_deisel_reading,last_husk_per_cft,last_husk_per_bale;

    void call_Input_Config();

    void keyPressEvent(QKeyEvent *ke);

    bool eventFilter(QObject *target, QEvent *event);

    explicit Input_Config(QWidget *parent = 0);
    ~Input_Config();

private slots:
    void on_pushButton_save_clicked();

private:
    Ui::Input_Config *ui;
};

#endif // INPUT_CONFIG_H
