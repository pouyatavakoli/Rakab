#include "Spring.hpp"

Spring::Spring() : Season(0, "Spring") {}

// adds 3 to highest card
void Spring::startEffect(Game &game)
{
    std::vector<Player> players = game.getGamePlayers();
    int max = game.getHighestYellowCardInGame(players);
    for (auto player : players)
    {
        for (auto &yellowCard : player.getYellowOnTable())
        {
            if (yellowCard->getPoints() == max)
            {
                yellowCard->setPoints(max + 3);
            }
        }
    }
}

// revert to default scores
void Spring::endEffect(Game &game)
{
    std::vector<Player> players = game.getGamePlayers();
    for (auto &player : players)
    {
        for (auto &yellowCard : player.getYellowOnTable())
        {
            yellowCard->setPoints(yellowCard->getNumerOnTheCard());
        }
    }
}

// revert cards to original and sets spring again
void Spring::refresh(Game &game)
{
    endEffect(game);
    startEffect(game);
}

std::string Spring::getName() const
{
    return name;
}
std::string Spring::getType() const
{
    return type;
}
int Spring::getNumerOnTheCard() const
{
    return numberOnTheCard;
}
int Spring::getPoints() const
{
    return points;
}
void Spring::setPoints(int pointsVal)
{
    points = pointsVal;
}