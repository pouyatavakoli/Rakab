#ifndef SAVEDGAMESMENU_H
#define SAVEDGAMESMENU_H

#include <QWidget>
#include "game.hpp"
#include "save.h"

namespace Ui {
class savedGamesMenu;
}

class savedGamesMenu : public QWidget
{
    Q_OBJECT

public:
    explicit savedGamesMenu(Game & game , QWidget *parent = nullptr);
    ~savedGamesMenu();

private slots:
    void on_back_btn_clicked();

    void on_load1_btn_clicked();

private:
    Game &game;
    Ui::savedGamesMenu *ui;

};

#endif // SAVEDGAMESMENU_H
