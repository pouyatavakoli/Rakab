#ifndef GAME_HPP
#define GAME_HPP

#include <vector>

#include "Player.hpp"

class Game
{
public:
    Game();
    void run();
    void fillMainDeck();
    void shuffleDeck();
    void setPlayersCount(int);
    void removeCardFromDeck(std::shared_ptr<Card> card, std::vector<std::shared_ptr<Card>> &);
    int getHighestYellowCardInGame(std::vector<Player> &);
    std::vector<Player> getGamePlayers() const;
    int getPlayersCount() const;
    void addPlayer(Player);

private:
    int playerCount;
    std::vector<Player> players;
    std::vector<std::shared_ptr<Card>> mainDeck;
    bool winnerIsPicked;
    bool anyPlayerCanPlay;
};

#endif
