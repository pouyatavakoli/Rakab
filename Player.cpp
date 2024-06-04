#include "Player.hpp"
// constructor
Player::Player(int ageVal, std::string nameVal)
{
    age = ageVal;
    name = nameVal;
    score = 0;
}

// setters
void Player::setAge(int ageVal)
{
    age = ageVal;
}
void Player::setName(std::string nameVal)
{
    name = nameVal;
}
void Player::add_owned_provinces(std::string newProvince)
{
    owned_provinces.push_back(newProvince);
}
// getters
int Player::getAge() const
{
    return age;
}
std::string Player::getName() const
{
    return name;
}
std::vector<std::string> Player::get_owned_provinces() const
{
    return owned_provinces;
}
void Player::addCardToDeck(Card card) 
{
    playerDeck.push_back(card);
}
std::vector<Card> Player::getPlayerDeck() const
{
    return playerDeck;
}
void Player::setScore(int scoreVal)
{
    score = scoreVal;
}
int Player::getScore() const
{
    return score ;
}