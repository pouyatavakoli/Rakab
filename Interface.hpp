#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <iostream>

#include "Player.hpp"

class Interface
{
public:
    int getPlayersCountFromUser();
    std::string getPlayersNameFromUser(int);
    int getPlayerAgeFromUser(int);
    std::string askUserToPickACardOrPass(Player);
    std::string askUserToPickAColor(int);
    std::string askSmallestPlayerToPickBattleProvince(const Player&);
};

#endif
