#ifndef ADD_USER_H
#define ADD_USER_H

#include <QWidget>
#include <QCompleter>

namespace Ui {
class Add_User;
}

class Add_User : public QWidget
{
    Q_OBJECT

public:

    QCompleter *cmpter,*cmpter1;

    QStringList lst_UserPassword,lst_User_Name,lst_User_id,lst_User_mobile,lst_User_Operator,lst_User_Desg,lst_User_Password;

    QString selected_UserPassword,selected_User_Name,selected_User_id,selected_User_mobile,selected_User_Operator,selected_User_Desg;

    bool edit_user;

    void call_Add_User();

    void keyPressEvent(QKeyEvent *ke);

    bool eventFilter(QObject *target, QEvent *event);

    explicit Add_User(QWidget *parent = 0);
    ~Add_User();

private slots:
    void on_pushButton_save_clicked();

    void on_pushButton_edit_clicked();

    void on_lineEdit_name_textEdited(const QString &arg1);

private:
    Ui::Add_User *ui;
};

#endif // ADD_USER_H
