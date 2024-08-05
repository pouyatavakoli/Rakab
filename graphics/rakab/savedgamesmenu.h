#ifndef SAVEDGAMESMENU_H
#define SAVEDGAMESMENU_H

#include <QWidget>
#include "save.h"

namespace Ui {
class savedGamesMenu;
}

class savedGamesMenu : public QWidget
{
    Q_OBJECT

public:
    explicit savedGamesMenu(Save &save , QWidget *parent = nullptr);
    ~savedGamesMenu();

private slots:
    void on_back_btn_clicked();

    void on_load1_btn_clicked();

private:
    Ui::savedGamesMenu *ui;
    Save *save ;
};

#endif // SAVEDGAMESMENU_H
