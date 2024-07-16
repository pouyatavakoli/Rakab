#include "getplayersinfowindow.h"
#include "ui_getplayersinfowindow.h"
#include "mainmenu.h"

getPlayersInfoWindow::getPlayersInfoWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::getPlayersInfoWindow)
{
    ui->setupUi(this);
}

getPlayersInfoWindow::~getPlayersInfoWindow()
{
    delete ui;
}

void getPlayersInfoWindow::on_back_btn_clicked()
{
    mainmenu *menu = new mainmenu();
    menu -> show();
    this -> close();
}

