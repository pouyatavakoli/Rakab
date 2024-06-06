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
