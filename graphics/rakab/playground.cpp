#include "playground.h"
#include "ui_playground.h"

playground::playground(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::playground)
{
    ui->setupUi(this);
}

playground::~playground()
{
    delete ui;
}
