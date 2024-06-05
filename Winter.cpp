#include "Winter.hpp"

Winter::Winter() : Season(0, "Winter") {}

void Winter::start(std::vector<Player> &player)
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

void Winter::end(std::vector<Player> &player)
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

std::string Winter::getType() const
{
    return Card::getType();
}
