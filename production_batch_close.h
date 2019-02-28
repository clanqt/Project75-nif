#ifndef PRODUCTION_BATCH_CLOSE_H
#define PRODUCTION_BATCH_CLOSE_H

#include <QWidget>

namespace Ui {
class Production_batch_close;
}

class Production_batch_close : public QWidget
{
    Q_OBJECT

public:
    explicit Production_batch_close(QWidget *parent = 0);
    ~Production_batch_close();

private:
    Ui::Production_batch_close *ui;
};

#endif // PRODUCTION_BATCH_CLOSE_H
