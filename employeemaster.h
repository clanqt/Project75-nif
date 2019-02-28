#ifndef EMPLOYEEMASTER_H
#define EMPLOYEEMASTER_H

#include <QWidget>
#include <QScrollArea>

#include <QCompleter>

namespace Ui {
class EmployeeMaster;
}

class EmployeeMaster : public QWidget
{
    Q_OBJECT

public:

    void call_employee_master();

    QScrollArea *scroll;

    bool is_edit;

    QStringList lst_emp_name;

    QCompleter *cmpter;

    void keyPressEvent(QKeyEvent *ke);

    bool eventFilter(QObject *target, QEvent *event);

    explicit EmployeeMaster(QWidget *parent = 0);
    ~EmployeeMaster();

private slots:
    void on_lineEdit_emp_name_returnPressed();

    void on_lineEdit_emp_contact_returnPressed();

    void on_lineEdit_rate_pe_hour_returnPressed();

    void on_lineEdit_target_returnPressed();

    void on_lineEdit_charges_returnPressed();

    void on_lineEdit_op_balance_returnPressed();

    void on_pushButton_purchase_save_clicked();

private:
    Ui::EmployeeMaster *ui;
};

#endif // EMPLOYEEMASTER_H
