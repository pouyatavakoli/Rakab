#include "savedgamesmenu.h"
#include "mainmenu.h"
#include "ui_savedgamesmenu.h"
#include <QDebug>

savedGamesMenu::savedGamesMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::savedGamesMenu)
{
    ui->setupUi(this);
}

savedGamesMenu::~savedGamesMenu()
{
    delete ui;
}

void savedGamesMenu::on_back_btn_clicked()
{
    mainmenu *menu = new mainmenu();
    menu->show();
    this->close();
}

