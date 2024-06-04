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
    void setScore(int score);
    void add_owned_provinces(std::string);
    void addCardToDeck(Card);
    // getters
    int getAge() const;
    std::string getName() const;
    std::vector<std::string> get_owned_provinces() const;
    std::vector<Card> Player::getPlayerDeck() const;
    int getScore() const;

private:
    int age;
    int score;
    std::string name;
    std::vector<std::string> owned_provinces;
    std::vector<Card> playerDeck;
    std::vector<Card> hand;
};
#endif