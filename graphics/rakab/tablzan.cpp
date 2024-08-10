#include "tablzan.h"

TablZan::TablZan(QWidget *parent) : PurpleCard(0, "TablZan", parent)
{
    faceURL = ":/new/cards/banafsh/assets/cards/banafsh/Tabl_Zan.png";
}

void TablZan::startEffect(Player &player) {

    endEffect(player);
    std::vector<std::shared_ptr<Card>> deck = player.getYellowOnTable();
    int counter = player.getTablZanCounter();
    double multiplier = std::pow(1.5, std::pow(2, counter)); // Apply 1.5^(2^counter)
    for (auto &card : deck) {
        card->setPoints(static_cast<int>(card->getPoints() * multiplier));
    }
}

void TablZan::endEffect(Player &player)
{
    std::vector<std::shared_ptr<Card>> deck = player.getYellowOnTable();
    for (auto &card : deck)
    {
        /* card is now worth 2 times number written on it */
        card->setPoints(card->getNumberOnTheCard());
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
