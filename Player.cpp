#include "Player.hpp"
#include <algorithm>

// constructor
Player::Player(){};
Player::Player(int ageVal, std::string nameVal) : age(ageVal), name(nameVal), totalScore(0), isAbleToPlay(true) {}

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
void Player::setColor(std::string colorVal)
{
    color = colorVal;
}
void Player::updatePlayerEligibility(bool canPlayVal)
{
    isAbleToPlay = canPlayVal;
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
std::string Player::getColor()
{
    return color;
}
bool Player::canPlay()
{
    return isAbleToPlay;
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
void Player::passAndDontPlay()
{
    isAbleToPlay = false ;
}

bool Player::playPurpleCard(const std::string &cardName)
{
    auto it = std::find_if(purpleHand.begin(), purpleHand.end(), [&cardName](const std::shared_ptr<Card> &card)
                           { return card->getName() == cardName; });

    if (it != purpleHand.end())
    {
        std::shared_ptr<Card> playedCard = *it; // Store the card to be played
        std::cout << "played " << playedCard->getName() << " for " << name << std::endl;
        purpleOnTable.push_back(playedCard); // Add the card to the on-table vector
        purpleHand.erase(it);                // Remove the card from the hand after playing
        purpleHand.shrink_to_fit();
        return true;
    }
    return false;
}

bool Player::playYellowCard(const std::string &cardName)
{
    auto it = std::find_if(yellowHand.begin(), yellowHand.end(), [&cardName](const std::shared_ptr<Card> &card)
                           { return card->getName() == cardName; });

    if (it != yellowHand.end())
    {
        std::shared_ptr<Card> playedCard = *it; // Store the card to be played
        std::cout << "played " << playedCard->getName() << " for " << name << std::endl;
        yellowOnTable.push_back(playedCard); // Add the card to the on-table vector
        yellowHand.erase(it);                // Remove the card from the hand after playing
        yellowHand.shrink_to_fit();
        return true;
    }
    return false;
}
