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
    // getplayer used to return const value but now returns non const to change player eligibility
    Player& getPlayer(int);
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
    void setNeshaneSolhgOwner(int);
    void setNeshaneJangOwner();
    void setBattleStarter(const Player &);

    Player getPlayerWhoShouldStart();
    const Player &findSmallestPlayer();


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

    bool getIsFirstRound() const;
    void setIsFirstRound(bool);

    bool getAnyPlayerCanPlay() const;
    void updateAnyPlayerCanPlay();


    void updatePlayersEligibility(int);

    bool winGame1();
    bool winGame2();
    void findWinner();

    void setLastWinner(Player &);
    int checkThisBattleWinner(const std::string &);


signals:
    void cardPlayed(int playerIndex, const std::shared_ptr<Card>& card);


private:
    int playerCount;
    std::vector <Player*> players;
    std::vector<std::shared_ptr<Card>> mainDeck;
    Map map;
    int currentPlayerIndex;
    int cardHoldersCount;
    bool anyPlayerCanPlay{true};
    std::string seasonSituation;
    bool parchamDarIsPlayed{false};
    Player *lastWinner;
    Player *NeshaneJangOwner;
    Player *NeshaneSolhgOwner; //RishSefid
    Player *lastPlayerWhoPassed;
    int countRishSefid{0};
    bool firstRound{true};

};

#endif // GAME_HPP
