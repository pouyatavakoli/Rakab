#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "Player.hpp"

class Game {
public:
    Game(); 
    void run();
    void setPlayersCount(int);
private:
    int playerCount;
    std::vector<Player> players;
};

#endif
