#include <QDebug>

#include "savedgamesmenu.h"
#include "mainmenu.h"
#include "ui_savedgamesmenu.h"
#include "mapwindow.h"
#include "playground.h"
#include "save.h"


savedGamesMenu::savedGamesMenu(Game &game, QWidget *parent) :
    QWidget(parent),
    game(game),ui(new Ui::savedGamesMenu)
{
    // load game should be added here
    //auto players = save.getPlayers();

    ui->setupUi(this);
    save = new Save;
    updateButtons();
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



void savedGamesMenu::updateButtons()
{
    for (int i = 1; i <= 5; ++i) {
        QString saveFileName = QString("saved_games_%1.txt").arg(i);
        QPushButton* button = nullptr;

        switch (i) {
        case 1: button = ui->load1_btn; break;
        case 2: button = ui->load2_btn; break;
        case 3: button = ui->load3_btn; break;
        case 4: button = ui->load4_btn; break;
        case 5: button = ui->load5_btn; break;
        }

        // Check if the save pointer is valid AND if the file contains an empty word
        if (save != nullptr && save->containsEmptyWord(saveFileName.toStdString())) {
            button->setEnabled(false);
        } else {
            button->setEnabled(true);
        }
    }
}

void savedGamesMenu::on_load1_btn_clicked()
{
    if(game.loadFromFile("saved_games_1.txt") == 1) // battle completed
    {
        // open on map
        game.setBattleCompleted("Yes");
        mapwindow* map = new mapwindow(game);
        map ->show();
        this ->close();
    }
    else
    {
        game.setBattleCompleted("No");
        mapwindow* map = new mapwindow(game);
        map ->show();

        /*Playground* pg = new Playground(game , game.getBattleIsOnThis());
        pg->show();*/

        this->close();


    }
    this->close();
    qDebug() << "loaded game from file ";
}


void savedGamesMenu::on_load2_btn_clicked()
{
    if(game.loadFromFile("saved_games_2.txt") == 1) // battle completed
    {
        // open on map
        game.setBattleCompleted("Yes");
        qDebug() << "battle  completed";
        mapwindow* map = new mapwindow(game);
        map ->show();
        this ->close();
    }
    else
    {
        game.setBattleCompleted("No");
        qDebug() << "battle not completed";
        mapwindow* map = new mapwindow(game);
        map ->show();

//        Playground* pg = new Playground(game , game.getBattleIsOnThis());
//        pg->show();

        this->close();


    }
    this->close();
    qDebug() << "loaded game from file ";
}


void savedGamesMenu::on_load3_btn_clicked()
{
    if(game.loadFromFile("saved_games_3.txt") == 1) // battle completed
    {
        // open on map
        game.setBattleCompleted("Yes");
        mapwindow* map = new mapwindow(game);
        map ->show();
        this ->close();
    }
    else
    {
        game.setBattleCompleted("NO");
        mapwindow* map = new mapwindow(game);
        map ->show();

//        Playground* pg = new Playground(game , game.getBattleIsOnThis());
//        pg->show();

        this->close();


    }
    this->close();
    qDebug() << "loaded game from file ";
}


void savedGamesMenu::on_load4_btn_clicked()
{
    if(game.loadFromFile("saved_games_4.txt") == 1) // battle completed
    {
        // open on map
        game.setBattleCompleted("Yes");
        mapwindow* map = new mapwindow(game);
        map ->show();
        this ->close();
    }
    else
    {
        game.setBattleCompleted("NO");
        mapwindow* map = new mapwindow(game);
        map ->show();

//        Playground* pg = new Playground(game , game.getBattleIsOnThis());
//        pg->show();

        this->close();


    }
    this->close();
    qDebug() << "loaded game from file ";
}


void savedGamesMenu::on_load5_btn_clicked()
{
    if(game.loadFromFile("saved_games_5.txt") == 1) // battle completed
    {
        // open on map
        game.setBattleCompleted("Yes");
        mapwindow* map = new mapwindow(game);
        map ->show();
        this ->close();
    }
    else
    {
        game.setBattleCompleted("NO");
        mapwindow* map = new mapwindow(game);
        map ->show();

//        Playground* pg = new Playground(game , game.getBattleIsOnThis());
//        pg->show();

        this->close();


    }
    this->close();
    qDebug() << "loaded game from file ";
}

