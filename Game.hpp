#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <memory>
#include <string>

#include "Interface.hpp"
#include "Map.hpp"

class Game
{
public:
    Game();
    void help();
    void run();
    void fillMainDeck();
    void shuffleDeck();
    void setPlayersCount(int);
    void startBattle(const std::string &, Interface &); // Correct function declaration
    void checkThisBattleWinner(const std::string &);
    int getHighestYellowCardInGame();

    void updateTotalScore();
    void reorderPurpleOnTable();
    void endEffects();
    void startEffects();
    void refreshEffects();

    void handCardsToPLayers();
    void removeCardFromDeck(std::shared_ptr<Card> card, std::vector<std::shared_ptr<Card>> &);
    std::vector<Player> getGamePlayers() const;
    int getPlayersCount() const;
    void addPlayer(Player);
    const Player &findSmallestPlayer();
    void setBattleStarter(const Player &);

    void setLastWinner(Player);
    Player getPlayerWhoShouldStart();

    void startSeason(const std::string);
    void endSeason(const std::string);
    void refreshSeason(const std::string);
    bool canStartSeason(const std::string) const;
    void removeGameSeason(const std::string);

    bool winGame1();
    bool winGame2();
    void findWinner();

private:
    int playerCount;
    Map map;
    std::vector<Player> players;
    std::vector<std::shared_ptr<Card>> mainDeck;
    bool winnerIsPicked;
    bool anyPlayerCanPlay;
    std::string seasonSituation;
    Player lastWinner;
    Player* lastPlayerWhoPassed;
};

#endif // GAME_HPP
