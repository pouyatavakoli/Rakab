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
    void run();

private:
    // Help function
    void help();
    // Functions for Players
    void setPlayersCount(int);
    int getPlayersCount() const;
    void addPlayer(Player);
    void handCardsToPLayers();
    Player getPlayerWhoShouldStart();
    const Player &findSmallestPlayer();
    std::vector<Player> getGamePlayers() const;
    // Functions for Battle
    void startBattle(const std::string &, Interface &);
    void checkThisBattleWinner(const std::string &);
    void setBattleStarter(const Player &);
    void setLastWinner(Player);
    // Functions for Season
    void startSeason(const std::string);
    void endSeason(const std::string &);
    void refreshSeason(const std::string);
    bool canStartSeason(const std::string) const;
    void removeGameSeason(const std::string);
    // Functions for scoring system
    void updateTotalScore();
    void reorderPurpleOnTable();
    void endAllEffects();
    void startAllEffects();
    void refreshEffects();
    // Functions for handling cards
    void fillMainDeck();
    void shuffleDeck();
    int getHighestYellowCardInGame();
    void updateCardHoldersCount();
    void removeCardFromDeck(std::shared_ptr<Card> card, std::vector<std::shared_ptr<Card>> &);
    // Functions for game winner
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
    Player *lastPlayerWhoPassed;
    int cardHoldersCount;
};

#endif // GAME_HPP
