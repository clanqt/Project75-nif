#ifndef PROCESS_SELECTION_H
#define PROCESS_SELECTION_H

#include <QWidget>

namespace Ui {
class Process_Selection;
}

class Process_Selection : public QWidget
{
    Q_OBJECT

public:

    void call_Process_Selection();

    void keyPressEvent(QKeyEvent *ke);

    explicit Process_Selection(QWidget *parent = 0);
    ~Process_Selection();

private slots:
    void on_pushButton_purchase_clicked();

    void on_pushButton_payment_clicked();

private:
    Ui::Process_Selection *ui;
};

#endif // PROCESS_SELECTION_H
