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
    std::cout << "Enter name for player " << i + 1 << " : ";
    std::cin >> name;
    return name;
}
int Interface::getPlayerAgeFromUser(int i)
{
    int age;
    std::cout << "enter player " << i + 1 << " age : ";
    std::cin >> age;
    return age;
}
std::string Interface::askUserToPickACardOrPass(Player player)
{
    std::cout << player.getName();
    std::cout << " enter card you want to play or enter pass if you want to pass : ";
    std::string cardsName;
    std::cin >> cardsName;
    return cardsName;
}
std::string Interface::askUserToPickAColor(int i)
{
    std::string color;
    std::cout << "enter player " << i + 1 << " color : ";
    std::cin >> color;
    return color;
}