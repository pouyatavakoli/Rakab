#include <QDebug>

#include "savedgamesmenu.h"
#include "mainmenu.h"
#include "ui_savedgamesmenu.h"
#include "mapwindow.h"
#include "playground.h"


savedGamesMenu::savedGamesMenu(Game &game, QWidget *parent) :
    QWidget(parent),
    game(game),ui(new Ui::savedGamesMenu)
{
    // load game should be added here
    //auto players = save.getPlayers();
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


void savedGamesMenu::on_load1_btn_clicked()
{
    if(game.loadFromFile() == 1) // battle completed
    {
        // open on map
        mapwindow* map = new mapwindow(game);
        map ->show();
        this ->close();
    }
    else
    {
        // open on playground
    }
    this->close();
    qDebug() << "loaded game from file ";
}

