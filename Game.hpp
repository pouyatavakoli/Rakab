#include <vector>

#include "Player.hpp"
#include "Deck.hpp"

#ifndef GAME_HPP
#define GAME_HPP


class Game {
public:
    Game(); 
    void run();
    void setPlayersCount(int);
private:
    int playerCount;
    std::vector<Player> players;
    Deck mainDeck;
    bool winnerIsPicked;
};

#endif
