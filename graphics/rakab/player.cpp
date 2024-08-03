#include "player.h"
#include "purplecard.h"

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

int Player::PlayThisCard(const std::string userChoice)
{
    if (userChoice == "pass")
    {
//        updatePlayerEligibility(false);
        return -1;
    }

    // if (userChoice.substr(4) == "help")
    // {
    //     return -10 ; // show help
    // }
    if (userChoice == "help")
    {
        return -10; // show help
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
                return 0; // nothing founded
            }
            else if (situation == 1 || situation == 3)
            {
                return 1; // Matarsak or TablZan or ShirDokht or ShirZan has been played
            }
            else if (situation == 2)
            {
                return 2; // Winter or spring should be played
            }
            else if (situation == 4)
            {
                return 4; // the card can not be used
            }
            else if (situation == 5)
            {
                return 5; // RishSefid should be played
            }
            else if (situation == 6)
            {
                return 6; // ParchamDar should be played
            }
        }
        return 0;
    }
}

bool Player::playYellowCard(const std::string &cardName)
{
    auto it = std::find_if(yellowHand.begin(), yellowHand.end(), [&cardName](const std::shared_ptr<Card> &card)
                           { return card->getName() == cardName; });
    if (it != yellowHand.end())
    {
        std::shared_ptr<Card> playedCard = *it; // Store the card to be played
        yellowOnTable.push_back(playedCard); // Add the card to the on-table vector
        playedCards.push_back(playedCard);
        yellowHand.erase(it); // Remove the card from the hand after playing
        yellowHand.shrink_to_fit();
        return true;
    }
    return false;
}

int Player::playPurpleCard(const std::string &cardName)
{

    // TODO: add if else for each purple card name
    auto it = std::find_if(purpleHand.begin(), purpleHand.end(), [&cardName](const std::shared_ptr<Card> &card)
                           { return card->getName() == cardName; });
    if (it != purpleHand.end())
    {
        std::shared_ptr<Card> playedCard = *it; // Store the card to be played
        std::shared_ptr<PurpleCard> purpleCard = std::dynamic_pointer_cast<PurpleCard>(playedCard);
        if (purpleCard)
        {
            if (playedCard->getName() == "Matarsak")
            {
                if (!yellowOnTable.empty())
                {
                    purpleCard->startEffect(*this);
                    purpleOnTable.push_back(playedCard);
                    playedCards.push_back(playedCard);
                    purpleHand.erase(it);
                    purpleHand.shrink_to_fit();
                    return 1; // we found Matarsak

                }
                else
                {
                    return 4; // The card can not be played
                }
            }
            else if (playedCard->getName() == "TablZan")
            {
                if (!usedTablZan)
                {
                    // purpleCard->startEffect(*this);
                    purpleOnTable.push_back(playedCard);
                    playedCards.push_back(playedCard);
                    purpleHand.erase(it);
                    purpleHand.shrink_to_fit();
                    usedTablZan = true;
                    return 1; // we found TablZan
                }
                return 4; // The card can not be played
            }

            else if (playedCard->getName() == "Winter" || playedCard->getName() == "Spring")
            {
                purpleOnTable.push_back(playedCard);
                playedCards.push_back(playedCard);
                purpleHand.erase(it);
                purpleHand.shrink_to_fit();
                return 2; // we found Winter or Spring
            }
            else if (playedCard->getName() == "RishSefid")
            {
                // purpleCard->startEffect();
                purpleOnTable.push_back(playedCard);
                playedCards.push_back(playedCard);
                purpleHand.erase(it);
                purpleHand.shrink_to_fit();
                return 5; // we found RishSefid
            }
            else if (playedCard->getName() == "ShahDokht")
            {
                // purpleCard->startEffect();
                purpleOnTable.push_back(playedCard);
                playedCards.push_back(playedCard);
                purpleHand.erase(it);
                purpleHand.shrink_to_fit();
                return 3; // we found ShirDokht
            }
            else if (playedCard->getName() == "ShirZan")
            {
                // purpleCard->startEffect();
                ++countShirZan;
                purpleOnTable.push_back(playedCard);
                playedCards.push_back(playedCard);
                purpleHand.erase(it);
                purpleHand.shrink_to_fit();
                return 3; // we found ShirZan
            }
            else if (playedCard->getName() == "ParchamDar")
            {
                // purpleCard->startEffect();
                purpleOnTable.push_back(playedCard);
                playedCards.push_back(playedCard);
                purpleHand.erase(it);
                purpleHand.shrink_to_fit();
                return 6; // we found ParchamDar
            }
        }
    }
    return 0;
}

void Player::applyEffect()
{
    for (auto &card : purpleOnTable)
    {
        if (card->getName() == "Winter" || card->getName() == "Spring" || card->getName() == "ShahDokht")
        {
            // card is Winter, Spring, or ShirDokht, no effect to apply here
        }
        else if (card->getName() == "TablZan")
        {
            std::shared_ptr<PurpleCard> TablZan = std::dynamic_pointer_cast<PurpleCard>(card);
            if (TablZan)
            {
                TablZan->startEffect(*this);
            }
            else
            {
                //Error: dynamic_pointer_cast failed for TablZan.
            }
        }
    }
}

void Player::cancelEffects()
{
    for (auto &card : yellowOnTable)
    {
        card->setPoints(card->getNumberOnTheCard());
    }
}
void Player::burnHand()
{

    burntCards.insert(burntCards.end(), purpleHand.rbegin(), purpleHand.rend());
    burntCards.insert(burntCards.end(), yellowHand.rbegin(), yellowHand.rend());

    purpleHand.clear();
    yellowHand.clear();
}

bool Player::canPlay()
{
    return isAbleToPlay;
}

void Player::passAndDontPlay()
{
    isAbleToPlay = false;
}

void Player::updatePlayerEligibility(bool canPlayVal)
{
    isAbleToPlay = canPlayVal;
}

void Player::flushTable()
{

    burntCards.insert(burntCards.end(), purpleOnTable.rbegin(), purpleOnTable.rend());
    burntCards.insert(burntCards.end(), yellowOnTable.rbegin(), yellowOnTable.rend());

    purpleOnTable.clear();
    yellowOnTable.clear();   
}



