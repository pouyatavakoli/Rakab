#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSignalMapper>
#include <QLabel>
#include <QString>
#include <QMap>
#include <QPixmap>
#include "game.hpp"
#include "cardlabel.h"

namespace Ui {
class playground;
}

class playground : public QWidget
{
    Q_OBJECT

public:
    explicit playground(Game &game, const std::string province, QWidget *parent = nullptr);
    ~playground();

private slots:
    void onCardClicked(QWidget *cardLabel);

private:
    Ui::playground *ui;
    Game &game;
    QGridLayout *playgroundLayout;
    QVBoxLayout *tableLayout;
    QList<QLayout*> playerLayouts;
    QSignalMapper *signalMapper;
    QMap<QString, QString> cardImages;
    int currentPlayerIndex;

    void initializeCardImages();
    void setupPlayground(int numPlayers);
    void addCardToTable(const QString &cardName);
    void removeCardFromTable(CardLabel *cardLabel);
    void addCardToPlayer(int playerIndex, const QString &cardName);
    void setupPlayerCards(const Player &player, int playerIndex);
    void nextTurn();
};

#endif // PLAYGROUND_H
