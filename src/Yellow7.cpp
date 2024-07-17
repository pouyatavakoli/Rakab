#include "Yellow7.hpp"

Yellow7::Yellow7() : YellowCard(7, "Yellow7") {}

std::string Yellow7::getName() const
{
    return name;
}
std::string Yellow7::getType() const
{
    return type;
}
int Yellow7::getNumerOnTheCard() const
{
    return numberOnTheCard;
}
int Yellow7::getPoints() const
{
    return points;
}
void Yellow7::setPoints(int pointsVal)
{
    points = pointsVal ;
}