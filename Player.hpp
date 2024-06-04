#include <iostream>
#include <vector>

#include "Card.hpp"

#ifndef PLAYER_HPP
#define PLAYER_HPP
class Player
{
public:
    // constructor
    Player(int, std::string);
    // setters
    void setAge(int);
    void setName(std::string);
    void add_owned_provinces(std::string);
    // getters
    int getAge();
    std::string getName();
    std::vector<std::string> get_owned_provinces() const;
    void addCardToDeck(Card);
    std::vector<Card> Player::getPlayerDeck();
    

private:
    int age;
    int score ;
    std::string name;
    std::vector<std::string> owned_provinces;
    std::vector<Card> playerDeck;
};
#endif