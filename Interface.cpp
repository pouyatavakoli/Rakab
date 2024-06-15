#include <iostream>
#include <iomanip>

#define RESET_TEXT "\033[0m"
#define YELLOW_TEXT "\u001b[33m"
#define PURPLE_TEXT "\u001b[35m"

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
    std::cout << " total points : " << player.getPoints() << std::endl;
    std::cout << player.getName();
    std::cout << " you have these cards in hand : " << std::endl;
    for (auto card : player.getYellowHand())
    {
        std::cout << YELLOW_TEXT << std::setw(10) << card->getName() << " " << RESET_TEXT;
    }
    for (auto card : player.getPurpleHand())
    {
        std::cout << PURPLE_TEXT << std::setw(10) << card->getName() << " " << RESET_TEXT;
    }
    std::cout << std::endl;
    std::cout << "pick one card from list above or enter pass or burn. \n(burning hand works ony if you have no yellow cards in hand)" << std::endl;
    std::cout << "@ " << player.getName() << " : ";
    std::string command;
    std::cin >> command;
    // std::getline(std::cin, command);
    return command;
}
std::string Interface::askUserToPickAColor(int i)
{
    std::string color;
    std::cout << "enter player " << i + 1 << " color : ";
    std::cin >> color;
    return color;
}
std::string Interface::askPlayerToPickBattleProvince(const Player &player)
{
    std::string provinceName;
    std::cout << player.getName() << " enter starting battle province: " << std::endl;
    std::cout << "@ " << player.getName() << " : ";
    std::cin >> provinceName;
    return provinceName;
}