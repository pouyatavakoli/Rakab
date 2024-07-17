#include "Matarsak.hpp"
#include <iostream>

Matarsak::Matarsak() : PurpleCard(0, "Matarsak") {}

std::string Matarsak::getName() const
{
    return name;
}
std::string Matarsak::getType() const
{
    return type;
}
int Matarsak::getNumerOnTheCard() const
{
    return numberOnTheCard;
}
int Matarsak::getPoints() const
{
    return points;
}
void Matarsak::setPoints(int pointsVal)
{
    points = pointsVal;
}

void Matarsak::startEffect(Player &player)
{
    bool found = false;
    while (!found)
    {
        std::string cardName;
        std::cin >> cardName;

        std::shared_ptr<Card> targetCard = player.removeCardFromYellowOnTable(cardName);

        if (targetCard)
        {
            std::cout << cardName << " has been picked up from the table and returned to the hand! " << std::endl;
            player.addCardToYellowHand(targetCard);
            found = true;
        }
        else
        {
            std::cout << "Card " << cardName << " not found on the table. Please try again." << std::endl;
        }
    }
}

void Matarsak::endEffect(Player &) {}
