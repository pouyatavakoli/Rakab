#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <iostream>
#include "Game.hpp"

class Interface {
public:
    int getPlayersCountFromUser();
    std::string getPlayersNameFromUser(int);
};

#endif
