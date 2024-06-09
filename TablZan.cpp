#include "TablZan.hpp"

TablZan::TablZan() : PurpleCard(0, "TablZan") {}

void TablZan::startEffect(Player &player)
{
    std::vector<std::shared_ptr<Card>> deck = player.getYellowOnTable();
    for (auto &card : deck)
    {
        if (card->getType() == "Yellow")
        {
            /* card score was added to players score when the card was played
            now this addition doubles the score in total*/
            player.setScore(player.getPoints() + card->getPoints());
        }
    }
}

void TablZan::endEffect(Player &) {}
std::string TablZan::getName() const
{
    return name;
}
std::string TablZan::getType() const
{
    return type;
}
int TablZan::getNumerOnTheCard() const
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
