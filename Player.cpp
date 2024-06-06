#include "Player.hpp"
#include <algorithm>

// constructor
Player::Player(){};
Player::Player(int ageVal, std::string nameVal) : age(ageVal), name(nameVal), totalScore(0) {}

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
    totalScore = scoreVal;
}

void Player::addOwnedProvinces(const std::string &newProvince)
{
    dominatedAreas.push_back(newProvince);
}

void Player::addCardToYellowOnTable(std::shared_ptr<Card> card)
{
    yellowOnTable.push_back(card);
}

void Player::addCardToYellowHand(std::shared_ptr<Card> card)
{
    yellowHand.push_back(card);
}

void Player::addCardToPurpleOnTable(std::shared_ptr<Card> card)
{
    purpleOnTable.push_back(card);
}

void Player::addCardToPurpleHand(std::shared_ptr<Card> card)
{
    purpleHand.push_back(card);
}

std::shared_ptr<Card> Player::removeCardFromYellowOnTable(const std::string &cardName)
{
    auto it = std::find_if(yellowOnTable.begin(), yellowOnTable.end(), [&cardName](const std::shared_ptr<Card> &card)
                           { return card->getName() == cardName; });

    if (it != yellowOnTable.end())
    {
        std::shared_ptr<Card> targetCard = *it;
        yellowOnTable.erase(it);
        return targetCard;
    }
    else
    {
        return nullptr;
    }
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
    return dominatedAreas;
}

std::vector<std::shared_ptr<Card>> Player::getYellowOnTable() const
{
    return yellowOnTable;
}

std::vector<std::shared_ptr<Card>> Player::getYellowHand() const
{
    return yellowHand;
}

std::vector<std::shared_ptr<Card>> Player::getPurpleOnTable() const
{
    return purpleOnTable;
}

std::vector<std::shared_ptr<Card>> Player::getPurpleHand() const
{
    return purpleHand;
}

int Player::getPoints() const
{
    return totalScore;
}
