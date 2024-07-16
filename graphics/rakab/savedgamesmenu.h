#ifndef SAVEDGAMESMENU_H
#define SAVEDGAMESMENU_H

#include <QWidget>

namespace Ui {
class savedGamesMenu;
}

class savedGamesMenu : public QWidget
{
    Q_OBJECT

public:
    explicit savedGamesMenu(QWidget *parent = nullptr);
    ~savedGamesMenu();

private slots:
    void on_back_btn_clicked();

private:
    Ui::savedGamesMenu *ui;
};

#endif // SAVEDGAMESMENU_H
