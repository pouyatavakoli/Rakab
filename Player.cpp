#include "Player.hpp"

// constructor
Player::Player(int ageVal, std::string nameVal) : age(ageVal), name(nameVal), score(0) {}

// setters
void Player::setAge(int ageVal)
{
    age = ageVal;
}

void Player::setName(std::string nameVal)
{
    name = nameVal;
}

void Player::setScore(int scoreVal)
{
    score = scoreVal;
}

void Player::addOwnedProvinces(const std::string &newProvince)
{
    owned_provinces.push_back(newProvince);
}

void Player::addCardToPlayedYellow(std::shared_ptr<YellowCard> card)
{
    playedYellowDeck.push_back(card);
}

void Player::addCardToHandYellow(std::shared_ptr<YellowCard> card)
{
    yellowHand.push_back(card);
}

void Player::addCardToPlayedPurple(std::shared_ptr<PurpleCard> card)
{
    playedPurpleDeck.push_back(card);
}

void Player::addCardToHandPurple(std::shared_ptr<PurpleCard> card)
{
    purpleHand.push_back(card);
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

std::vector<std::string> Player::getOwnedProvinces() const
{
    return owned_provinces;
}

std::vector<std::shared_ptr<YellowCard>> Player::getPlayedYellowDeck() const
{
    return playedYellowDeck;
}

std::vector<std::shared_ptr<YellowCard>> Player::getYellowHand() const
{
    return yellowHand;
}

std::vector<std::shared_ptr<PurpleCard>> Player::getPlayedPurpleDeck() const
{
    return playedPurpleDeck;
}

std::vector<std::shared_ptr<PurpleCard>> Player::getPurpleHand() const
{
    return purpleHand;
}

int Player::getScore() const
{
    return score;
}
