#include "Winter.hpp"

Winter::Winter() : Season(0, "Winter") {}

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