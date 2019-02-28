#ifndef DAY_CLOSE_H
#define DAY_CLOSE_H

#include <QWidget>
#include <QProcess>

namespace Ui {
class Day_Close;
}

class Day_Close : public QWidget
{
    Q_OBJECT

public:

    QProcess process;

    QString opening_bale,batch_type,batch_no,husk_available,total_husk_available,total_bale_estimated,bale_dispatched,closing_bale;
    QStringList lst_batch_type,lst_batch_no,lst_husk_to_bale,lst_husk_available;
    bool use_next_batch;
    int company_or_other;

    QString before_dispatch,after_dispatch,dispatched_to,bale_produced;

    void execProcess(QString ProcessName , QString Message);

    void call_Day_Close();

    void keyPressEvent(QKeyEvent *ke);

    bool eventFilter(QObject *target, QEvent *event);

    explicit Day_Close(QWidget *parent = 0);
    ~Day_Close();

private slots:

    void on_lineEdit_bale_produced_returnPressed();

    void on_lineEdit_bale_dispatched_returnPressed();

    void on_pushButton_close_clicked();

private:
    Ui::Day_Close *ui;
};

#endif // DAY_CLOSE_H
