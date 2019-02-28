#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include <QGraphicsScene>
#include <QGraphicsProxyWidget>
#include <QGraphicsView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    QGraphicsScene Scene,Scene1;
    QGraphicsProxyWidget *Proxy;
    QGraphicsProxyWidget *Proxy1;
    QGraphicsView view,view1;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
