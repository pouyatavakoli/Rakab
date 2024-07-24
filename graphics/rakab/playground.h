#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QMap>
#include <QLabel>
#include <QString>
#include <memory>
#include <QSignalMapper>

#include "game.hpp"

namespace Ui {
class playground;
}

class playground : public QWidget
{
    Q_OBJECT

public:
    explicit playground(Game &game, const std::string province, QWidget *parent = nullptr);
    ~playground();

private:
    Ui::playground *ui;
    Game &game;
    QGridLayout *playgroundLayout;
    QVBoxLayout *tableLayout;
    QList<QLayout *> playerLayouts;
    QMap<QString, QString> cardImages;
    int currentPlayerIndex;
    QSignalMapper *signalMapper;

    void initializeCardImages();
    void setupPlayground(int numPlayers);
    void addCardToTable(const QString &cardName);
    void removeCardFromTable(QLabel *cardLabel);
    void addCardToPlayer(int playerIndex, const QString &cardName);
    void setupPlayerCards(const Player &player, int playerIndex);
    void nextTurn();
};

#endif // PLAYGROUND_H
