#include "Yellow1.hpp"

Yellow1::Yellow1() : YellowCard(1, "Yellow1") {}

std::string Yellow1::getName() const
{
    return name;
}
std::string Yellow1::getType() const
{
    return type;
}
int Yellow1::getNumerOnTheCard() const
{
    return numberOnTheCard;
}
int Yellow1::getPoints() const
{
    return points;
}
void Yellow1::setPoints(int pointsVal)
{
    points = pointsVal;
}