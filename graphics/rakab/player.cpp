#include "player.h"

// Default constructor
Player::Player(QObject *parent) : QObject(parent), age(0) {}

// Parameterized constructor
Player::Player(int age, const std::string &name, QObject *parent)
    : QObject(parent), age(age), name(name) {}

void Player::setAge(int age) {
    this->age = age;
}

void Player::setName(const std::string &name) {
    this->name = name;
}

void Player::setScore(int scoreVal)
{
    totalScore = scoreVal;
}

void Player::setCanPutNeshaneJang(bool x)
{
    canPutNeshaneJang = x;
}

void Player::setWinStatus(bool statusVal)
{
    winStatus = statusVal;
}

int Player::getAge() const {
    return age;
}

std::string Player::getName() const {
    return name;
}

bool Player::getWinStatus()
{
    return winStatus;
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
void Player::addCardToPurpleHand(std::shared_ptr<Card> card)
{
    purpleHand.push_back(card);
}

void Player::addCardToPurpleOnTable(std::shared_ptr<Card> card)
{
    purpleOnTable.push_back(card);
}
void Player::setPurpleOnTable(std::vector<std::shared_ptr<Card>> cards)
{
    purpleOnTable.clear();
    for (const auto& card : cards)
    {
        purpleOnTable.push_back(card);
    }
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
std::vector<std::shared_ptr<Card>> Player::getPlayedCards() const
{
    return playedCards;
}

int Player::getPoints() const
{
    return totalScore;
}

int Player::getNumberOfOwnedProvinces()
{
    return dominatedAreas.size();
}

int Player::getCountShirZan() const
{
    return countShirZan;
}

bool Player::getCanPutNeshaneJang() const
{
    return canPutNeshaneJang;
}
