#ifndef STAFF_CASH_H
#define STAFF_CASH_H

#include <QWidget>

namespace Ui {
class Staff_Cash;
}

class Staff_Cash : public QWidget
{
    Q_OBJECT

public:

    QStringList lst_from,lst_operator;

    void call_Staff_Cash();

    bool from_day_open;

    void keyPressEvent(QKeyEvent *ke);

    bool eventFilter(QObject *target, QEvent *event);

    explicit Staff_Cash(QWidget *parent = 0);
    ~Staff_Cash();

public slots:
    void on_pushButton_from_clicked();

    void on_pushButton_to_clicked();

    void on_pushButton_from_save_clicked();

    void on_pushButton_from_save_2_clicked();

private:
    Ui::Staff_Cash *ui;
};

#endif // STAFF_CASH_H
