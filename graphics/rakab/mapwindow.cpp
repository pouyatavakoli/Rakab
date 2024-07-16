#include "mapwindow.h"
#include "ui_mapwindow.h"
#include "mainmenu.h"

mapwindow::mapwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mapwindow)
{
    ui->setupUi(this);

    setAutoFillBackground(true);
    QPixmap pixmap(":/new/map/assets/Map.png");
    QSize size = this->size();  // Get the size of the window
    QPixmap scaledPixmap = pixmap.scaled(size, Qt::KeepAspectRatioByExpanding);  // Scale the pixmap to fit the window
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(scaledPixmap));
    this->setPalette(palette); // Set the palette of the widget
}

mapwindow::~mapwindow()
{
    delete ui;
}

void mapwindow::on_pushButton_clicked()
{
    mainmenu *menu = new mainmenu();
    menu ->show();
    this->close();
}

