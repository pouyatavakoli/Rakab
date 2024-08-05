#include <QDebug>

#include "savedgamesmenu.h"
#include "mainmenu.h"
#include "ui_savedgamesmenu.h"
#include "mapwindow.h"
#include "playground.h"


savedGamesMenu::savedGamesMenu(Save &save, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::savedGamesMenu),save(&save)
{
    // load game should be added here

    auto players = save.getPlayers();
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
    auto players = save->getPlayers();
    std::vector<std::string> playerNames;
    std::vector<int> playerAges ;
    for (const auto &player : players){
        playerNames.push_back (player->getName());
    }
    for (const auto &player : players){
        playerAges.push_back(player->getAge());
    }
    // new empty game
    // inject these info into the game

    // todo : write overload of game constructor to get info if needed
    Game *game = new Game(*save);

    // this line does job of getinfo window
    game->setPlayers(playerNames, playerAges);


    // if battle finished  : open map
    // if battle not finished : open playground

    std::string battleCompleted = save->getBattleCompleted();
    if (battleCompleted == "Yes"){
        qDebug()<< "previous battle was completed starting new one";
        mapwindow* map = new mapwindow(*game);
        map ->show();

    }
    // if battle incomplete we need to resume battle on that province
    else {
        // open playgroud with hand and table info
    }
    // todo: write overload of playground

    // Playground *pg = new Playground(game , province);

    this->close();

    qDebug() << "loaded game from file ";
}

