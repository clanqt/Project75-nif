#ifndef SALARY_CALCULATION_H
#define SALARY_CALCULATION_H

#include <QWidget>

#include <QLineEdit>
#include <QScrollArea>

#include <QModelIndex>
#include <QListWidgetItem>

namespace Ui {
class Salary_Calculation;
}

class Salary_Calculation : public QWidget
{
    Q_OBJECT

public:

    QScrollArea *scroll;

    QStringList lst_emp_availble,lst_selected_items;

    QStringList lst_selected_emp_name,lst_selected_emp_gender,lst_selected_emp_daily_wages,lst_selected_emp_target,lst_selected_emp_target_charge,lst_selected_emp_balance,lst_selected_emp_balance_type,lst_selected_emp_pending_bale,lst_selected_emp_pending_bale_amount;

    QString estimated_salary,Total_payable,paid_amount,calc_row,unpaid_bale_amt,salary_per_hour,hrs_salary,worked_hrs;

    QLineEdit* tmpLineEdit_target,*tmpLineEdit_salary;

    float charge_per_bale;

    void call_Salary_Calculation();

    void keyPressEvent(QKeyEvent *ke);

    bool eventFilter(QObject *target, QEvent *event);

    explicit Salary_Calculation(QWidget *parent = 0);
    ~Salary_Calculation();

signals:
    void goto_next_employee();

private slots:

//    void on_tmpLineEdit_target_returned_pressed();

//    void on_tmpLineEdit_salary_returned_pressed();

//    void Calculation_salary();


    void on_comboBox_name_currentIndexChanged(const QString &arg1);

    void on_checkBox_target_clicked(bool checked);

    void on_checkBox_hrs_clicked(bool checked);

    void on_lineEdit_target_returnPressed();

    void on_lineEdit_hrs_returnPressed();

    void on_pushButton_next_clicked();

    void on_pushButton_save_emp_salary_clicked();

private:
    Ui::Salary_Calculation *ui;
};

#endif // SALARY_CALCULATION_H
