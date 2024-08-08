#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include "savedgamesmenu.h"
#include "game.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class mainmenu; }
QT_END_NAMESPACE

class mainmenu : public QMainWindow
{
    Q_OBJECT

public:
    mainmenu(QWidget *parent = nullptr);
    ~mainmenu();

private:
    Ui::mainmenu *ui;
   // savedGamesMenu *sgMenu;

private slots:
    void on_exit_btn_clicked();
    void on_saved_btn_clicked();
    void on_newgame_btn_clicked();
};
#endif // MAINMENU_H
