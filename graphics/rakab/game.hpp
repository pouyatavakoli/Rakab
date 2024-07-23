// this is temp game class to make sure playground works properly
#ifndef GAME_HPP
#define GAME_HPP

#include "player.h"
#include "card.h"

#include <vector>
#include <string>
#include <QObject>
#include <QWidget>
#include <memory>


class Game : public QObject {
    Q_OBJECT
public:

    Game(QObject *parent = nullptr);
    void setPlayersCount(int);
    void setPlayers(const std::vector<std::string>&, const std::vector<int>&);
    Player& currentPlayer();
    void nextTurn();
    int getPlayerCount() const;
    const Player& getPlayer(int);
    void handCardsToPLayers();
    void fillMainDeck();
    void shuffleDeck();
    int getHighestYellowCardInGame() const;
    void updateCardHoldersCount();
    void removeCardFromDeck(std::shared_ptr<Card> card, std::vector<std::shared_ptr<Card>> &);
    void updateTotalScore();
    void reorderPurpleOnTable();
    void endAllEffects();
    void startAllEffects();
    void refreshEffects();



signals:
    void turnChanged(int playerIndex);

private:


private:
    int playerCount;
    std::vector <Player*> players;
    std::vector<std::shared_ptr<Card>> mainDeck;
    int currentPlayerIndex;
    int cardHoldersCount;

};

#endif // GAME_HPP
