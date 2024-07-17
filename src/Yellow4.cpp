#include "Yellow4.hpp"

Yellow4::Yellow4() : YellowCard(4, "Yellow4") {}
std::string Yellow4::getName() const
{
    return name;
}
std::string Yellow4::getType() const
{
    return type;
}
int Yellow4::getNumerOnTheCard() const
{
    return numberOnTheCard;
}
int Yellow4::getPoints() const
{
    return points;
}
void Yellow4::setPoints(int pointsVal)
{
    points = pointsVal;
}