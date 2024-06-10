#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <memory>
#include <string>

#include "Player.hpp"
#include "Interface.hpp"
#include "Map.hpp"

class Game
{
public:
    Game();
    void run();
    void fillMainDeck();
    void shuffleDeck();
    void setPlayersCount(int);
    void startBattle(const std::string &, Interface &); // Correct function declaration
    void checkThisBattleWinner(const std::string &);
    int getHighestYellowCardInGame(std::vector<Player> &);
    void updateTotalScore();
    void handCardsToPLayers();
    void removeCardFromDeck(std::shared_ptr<Card> card, std::vector<std::shared_ptr<Card>> &);
    std::vector<Player> getGamePlayers() const;
    int getPlayersCount() const;
    void addPlayer(Player);
    const Player &findSmallestPlayer();
    void setBattleStarter(const Player &);

    void winGame1(Player & , Map &);
    void winGame2();
    void findWinner();

private:
    int playerCount;
    std::vector<Player> players;
    std::vector<std::shared_ptr<Card>> mainDeck;
    bool winnerIsPicked;
    bool anyPlayerCanPlay;
};

#endif // GAME_HPP
