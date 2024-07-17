#include "Yellow2.hpp"

Yellow2::Yellow2() : YellowCard(2, "Yellow2") {}

std::string Yellow2::getName() const
{
    return name;
}
std::string Yellow2::getType() const
{
    return type;
}
int Yellow2::getNumerOnTheCard() const
{
    return numberOnTheCard;
}
int Yellow2::getPoints() const
{
    return points;
}
void Yellow2::setPoints(int pointsVal)
{
    points = pointsVal ;
}
