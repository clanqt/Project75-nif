#ifndef EXPENSE_MASTER_H
#define EXPENSE_MASTER_H

#include <QWidget>
#include <QCompleter>

namespace Ui {
class Expense_Master;
}

class Expense_Master : public QWidget
{
    Q_OBJECT

public:

    QCompleter *cmpter,*cmpter1;

    bool from_payments;

    bool expense_entry;

    QStringList lst_expense_id,lst_expense_name;

    void call_Expense_Master();

    void keyPressEvent(QKeyEvent *ke);

    bool eventFilter(QObject *target, QEvent *event);

    void show_screen(int screen_no);

    explicit Expense_Master(QWidget *parent = 0);
    ~Expense_Master();

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_save_clicked();

    void on_lineEdit_expense_name_returnPressed();

private:
    Ui::Expense_Master *ui;
};

#endif // EXPENSE_MASTER_H
