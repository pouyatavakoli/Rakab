#include "Winter.hpp"

Winter::Winter() : Season(0, "Winter") {}

void Winter::startEffect(std::vector<Player> &player)
{
    for (auto &changePlayer : player)
    {
        for (auto &yellowcards : changePlayer.getYellowHand())
        {
            if (yellowcards->getPoints() != 1)
            {
                yellowcards->setPoints(1);
            }
        }
    }
}

void Winter::endEffect(std::vector<Player> &player)
{
    for (auto &changePlayer : player)
    {
        for (auto &yellowcards : changePlayer.getYellowHand())
        {
            if (yellowcards->getType() != "Yellow1")
            {
                yellowcards->setPoints(yellowcards->getNumerOnTheCard());
            }
        }
    }
}

void Winter::refresh(std::vector<Player> &player)
{
    endEffect(player);
    startEffect(player);
}

std::string Winter::getName() const
{
    return name;
}
std::string Winter::getType() const
{
    return type;
}
int Winter::getNumerOnTheCard() const
{
    return numberOnTheCard;
}
int Winter::getPoints() const
{
    return points;
}
void Winter::setPoints(int pointsVal)
{
    points = pointsVal;
}