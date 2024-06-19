#include "Yellow6.hpp"

Yellow6::Yellow6() : YellowCard(6, "Yellow6") {}

std::string Yellow6::getName() const
{
    return name;
}
std::string Yellow6::getType() const
{
    return type;
}
int Yellow6::getNumerOnTheCard() const
{
    return numberOnTheCard;
}
int Yellow6::getPoints() const
{
    return points;
}
void Yellow6::setPoints(int pointsVal)
{
    points = pointsVal ;
}