#include "Yellow8.hpp"

Yellow8::Yellow8() : YellowCard(8, "Yellow8") {}

std::string Yellow8::getName() const
{
    return name;
}
std::string Yellow8::getType() const
{
    return type;
}
int Yellow8::getNumerOnTheCard() const
{
    return numberOnTheCard;
}
int Yellow8::getPoints() const
{
    return points;
}
void Yellow8::setPoints(int pointsVal)
{
    points = pointsVal ;
}