#ifndef VOID_LAST_BILL_H
#define VOID_LAST_BILL_H

#include <QWidget>

namespace Ui {
class Void_Last_BIll;
}

class Void_Last_BIll : public QWidget
{
    Q_OBJECT

public:

    void call_Void_Last_BIll();

    void keyPressEvent(QKeyEvent *ke);

    explicit Void_Last_BIll(QWidget *parent = 0);
    ~Void_Last_BIll();

private slots:
    void on_pushButton_purchase_clicked();

    void on_pushButton_payment_clicked();

private:
    Ui::Void_Last_BIll *ui;
};

#endif // VOID_LAST_BILL_H
