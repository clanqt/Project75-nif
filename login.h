#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:

    int user_count;

    QStringList lst_UserPassword;

    void call_login();
    void keyPressEvent(QKeyEvent *ke);
    void timerEvent(QTimerEvent *event);
    bool exitStatus,timerStarted;
    int timer,min,timerId;
    int Indexno,UserCount;

    void StartThread();



    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_lineEdit_pwd_textEdited(const QString &arg1);

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
