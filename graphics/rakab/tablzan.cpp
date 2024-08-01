#include "tablzan.h"

TablZan::TablZan(QWidget *parent) : PurpleCard(0, "TablZan", parent)
{
    faceURL = ":/new/cards/banafsh/assets/cards/banafsh/Tabl_Zan.png";
}

void TablZan::startEffect(Player &player)
{
    std::vector<std::shared_ptr<Card>> deck = player.getYellowOnTable();
    for (auto &card : deck)
    {
        /* card is now worth 2 times number written on it */
        card->setPoints(card->getPoints() * 2);
    }
}

void TablZan::endEffect(Player &player)
{
    std::vector<std::shared_ptr<Card>> deck = player.getYellowOnTable();
    for (auto &card : deck)
    {
        /* card is now worth 2 times number written on it */
        card->setPoints(card->getPoints()/ 2);
    }
}

std::string TablZan::getName() const
{
    return name;
}
std::string TablZan::getType() const
{
    return type;
}
int TablZan::getNumberOnTheCard() const
{
    return numberOnTheCard;
}
int TablZan::getPoints() const
{
    return points;
}
void TablZan::setPoints(int pointsVal)
{
    points = pointsVal;
}
