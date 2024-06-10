#include "Player.hpp"
#include <algorithm>
#include <iostream>
#include "PurpleCard.hpp"
// constructors
Player::Player() : age(0), totalScore(0), isAbleToPlay(true), winStatus(false) {}
Player::Player(int ageVal, std::string nameVal) : age(ageVal), name(nameVal), totalScore(0), isAbleToPlay(true), winStatus(false) {}

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
void Player::setWinStatus(bool statusVal)
{
    winStatus = statusVal;
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
std::string Player::getName()
    const
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
bool Player::getWinStatus()
{
    return winStatus;
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
    isAbleToPlay = false;
}

int Player::playPurpleCard(const std::string &cardName)
{

    // TODO: add if else for each purple card name
    auto it = std::find_if(purpleHand.begin(), purpleHand.end(), [&cardName](const std::shared_ptr<Card> &card)
                           { return card->getName() == cardName; });
    if (it != purpleHand.end())
    {
        std::shared_ptr<Card> playedCard = *it; // Store the card to be played
        std::cout << "played " << playedCard->getName() << " for " << name << std::endl;
        std::shared_ptr<PurpleCard> purpleCard = std::dynamic_pointer_cast<PurpleCard>(playedCard);
        if (purpleCard)
        {
            if (playedCard->getName() == "Matarsak" || playedCard->getName() == "TablZan")
            {
                purpleCard->startEffect(*this);
                purpleOnTable.push_back(playedCard);
                purpleHand.erase(it);
                purpleHand.shrink_to_fit();
                return 1; // we found Matarsak or TablZan
            }
            else if (playedCard->getName() == "Winter" || playedCard->getName() == "Spring")
            {
                purpleOnTable.push_back(playedCard);
                purpleHand.erase(it);
                purpleHand.shrink_to_fit();
                return 2; // we found Winter or Spring
            }
            else if (playedCard->getName() == "ShirDokht" || playedCard->getName() == "ShirZan" ||
                     playedCard->getName() == "ParchamDar")
            {
                purpleCard->startEffect();
                purpleOnTable.push_back(playedCard);
                purpleHand.erase(it);
                purpleHand.shrink_to_fit();
                return 3; // we found other cards
            }
        }
    }
    return 0;
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

int Player::PlayThisCard(const std::string userChoice)
{
    if (userChoice == "pass")
    {
        updatePlayerEligibility(false);
        return -1;
    }
    else
    {
        // Check if the user choice matches any card name
        int situation{0};
        bool cardFound = false;
        for (int i = 1; i <= 10; ++i)
        {
            if (i == 7 || i == 8 || i == 9)
            {
                continue;
            }
            std::string cardName = "Yellow" + std::to_string(i);
            if (userChoice == cardName)
            {
                cardFound = true;
                if (playYellowCard(cardName))
                {
                    return 1; // card card has been played
                }
            }
        }

        // If the user choice is not a Yellow card, try to play a Purple card
        if (!cardFound)
        {
            situation = playPurpleCard(userChoice);
            if (situation == 0)
            {
                return 0; //nothing founded
            }
            else if(situation == 1 || situation == 3)
            {
                return 1; //card has been played
            }
            else if(situation == 2)
            {
                return 2; //Winter or spring should be played
            }
        }
        return 0;
    }
}

int Player::getNumberOfOwnedProvinces()
{
    return dominatedAreas.size();
}