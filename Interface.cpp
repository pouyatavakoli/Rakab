#include <iostream>
#include "Interface.hpp"

int Interface::getPlayersCountFromUser()
{
    int playersCount = 0;
    while (true)
    {
        std::cout << "Enter players count: ";
        std::cin >> playersCount;

        if (playersCount >= 3 && playersCount <= 6)
        {
            return playersCount;
        }
        else
        {
            std::cout << "Number of players must be between 3 and 6. Please try again." << std::endl;
        }
    }
}

std::string Interface::getPlayersNameFromUser(int i)
{
    std::string name;
    std::cout << "Enter name for player " << i + 1 << ": ";
    std::cin >> name;
    return name;
}