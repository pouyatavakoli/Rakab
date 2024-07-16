#include "savedgamesmenu.h"
#include "ui_savedgamesmenu.h"

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
