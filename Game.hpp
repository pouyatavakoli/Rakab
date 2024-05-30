#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "Player.hpp"

class Game {
public:
    Game(); 
    void setPlayersCount(int);
    void setPlayersName(std::string);
private:
    int playerCount;
    std::vector<Player> Players;
};

#endif
