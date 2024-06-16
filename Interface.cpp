#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>

#define RESET_TEXT "\033[0m"
#define YELLOW_TEXT "\u001b[33m"
#define PURPLE_TEXT "\u001b[35m"

#include "Interface.hpp"

std::map<std::string, std::string> commandTypos = {
    {"hlep", "help"},
    {"tblzn", "TablZan"},
    {"wntr", "Winter"},
    {"y1", "Yellow1"},
    {"y2", "Yellow2"},
    {"y3", "Yellow3"},
    {"y4", "Yellow4"},
    {"y5", "Yellow5"},
    {"y6", "Yellow6"},
    // {"y7", "Yellow7"},
    // {"y8", "Yellow8"},
    // {"y9", "Yellow9"},
    {"y10", "Yellow10"}};
// add more later

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
    std::cout << "pick one card from list above or enter pass or burn. \n(burning hand works only if you have no yellow cards in hand)" << std::endl;
    std::cout << "@ " << player.getName() << " : ";
    std::string command;
    std::cin >> command;
    // std::getline(std::cin, command);
    return command;
}
std::string Interface::askUserToPickAColor(int i)
{
    std::map<std::string, int> colors = {
        {"green", 1},
        {"red", 2},
        {"blue", 3},
        {"pink", 4},
        {"black", 5},
        {"white", 6}};

    std::string color;
    bool isValid = false;

    while (!isValid)
    {
        std::cout << "Choose one of these colors: green-red-blue-pink-black-white\n";
        std::cout << "Enter player " << i + 1 << " color: ";
        std::cin >> color;

        if (colors.find(color) != colors.end())
        {
            int colorCode = colors[color];
            if (std::find(chosenColors.begin(), chosenColors.end(), colorCode) == chosenColors.end())
            {
                isValid = true;
            }
            else
            {
                std::cout << "This color has already been chosen. Please pick a different color.\n";
            }
        }
        else
        {
            std::cout << "Invalid color. Please choose a valid color.\n";
        }
    }
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

std::string Interface::checkCommandTypos(std::string input)
{
    if (commandTypos.find(input) != commandTypos.end())
    {
        std::cout << "Did you mean: " << commandTypos.at(input) << " instead of " << input << " ? (y/n)" << std::endl;
        char response;
        std::cin >> response;
        if (response == 'y')
        {
            return commandTypos.at(input);
        }
    }
    return "404";
}

void Interface::printPlayerCards(const std::vector<Player> &players)
{
    for (const auto &player : players)
    {
        std::cout << player.getName() << " cards: ";
        for (const auto &card : player.getPlayedCards())
        {
            std::cout << card->getName() << " ";
        }
        std::cout << std::endl;
    }
}
void Interface::printPlayerOwnedProvinces(const std::vector<Player> &players)
{
    for (const auto &player : players)
    {
        std::cout << player.getName() << " provinces: ";
        for (const auto &province : player.getOwnedProvinces())
        {
            std::cout << province << " ";
        }
        std::cout << std::endl;
    }
}