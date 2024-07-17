#include "Yellow3.hpp"

Yellow3::Yellow3() : YellowCard(3, "Yellow3") {}
std::string Yellow3::getName() const
{
    return name;
}
std::string Yellow3::getType() const
{
    return type;
}
int Yellow3::getNumerOnTheCard() const
{
    return numberOnTheCard;
}
int Yellow3::getPoints() const
{
    return points;
}
void Yellow3::setPoints(int pointsVal)
{
    points = pointsVal ;
}