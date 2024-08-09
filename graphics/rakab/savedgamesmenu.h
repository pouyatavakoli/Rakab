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


    void updateButtons();
private slots:
    void on_back_btn_clicked();

    void on_load1_btn_clicked();

    void on_load2_btn_clicked();

    void on_load3_btn_clicked();

    void on_load4_btn_clicked();

    void on_load5_btn_clicked();

private:
    Game &game;
    Save* save;
    Ui::savedGamesMenu *ui;

};

#endif // SAVEDGAMESMENU_H
