// this is temp game class to make sure playground works properly
#ifndef GAME_HPP
#define GAME_HPP

#include "player.h"
#include "card.h"
#include "map.h"

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
    void StartEffectOfRishSefid();


    bool canStartSeason(const std::string) const;
    void startSeason(const std::string);
    void endSeason(const std::string &);

    std::vector<std::shared_ptr<Card>> getMainDeck();
    int playPlayerCard(int playerIndex, const std::string& cardName );

    std::vector<std::shared_ptr<Card>> getPlayerYellowHand(int playerIndex) const;
    std::vector<std::shared_ptr<Card>> getPlayerPurpleHand(int playerIndex) const;
    std::vector<std::shared_ptr<Card>> getPlayerYellowOnTable(int playerIndex) const;
    std::vector<std::shared_ptr<Card>> getPlayerPurpleOnTable(int playerIndex) const;

    void setPlayerIndex(int);
    int getPlayerIndex() const;

    bool winGame1();
    bool winGame2();
    void findWinner();

    void setLastWinner(Player &);
    int checkThisBattleWinner(const std::string &);



signals:
    void cardPlayed(int playerIndex, const std::shared_ptr<Card>& card);

private:


private:
    int playerCount;
    std::vector <Player*> players;
    Player *lastWinner;
    std::vector<std::shared_ptr<Card>> mainDeck;
    Map map;
    int currentPlayerIndex;
    int cardHoldersCount;
    bool anyPlayerCanPlay{false};
    std::string seasonSituation;
    bool parchamDarIsPlayed{false};

};

#endif // GAME_HPP
