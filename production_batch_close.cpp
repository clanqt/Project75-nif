#include "production_batch_close.h"
#include "ui_production_batch_close.h"

Production_batch_close::Production_batch_close(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Production_batch_close)
{
    ui->setupUi(this);
}

Production_batch_close::~Production_batch_close()
{
    delete ui;
}
