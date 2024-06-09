#include "Yellow9.hpp"

Yellow9::Yellow9() : YellowCard(9, "Yellow9") {}

std::string Yellow9::getName() const
{
    return name;
}
std::string Yellow9::getType() const
{
    return type;
}
int Yellow9::getNumerOnTheCard() const
{
    return numberOnTheCard;
}
int Yellow9::getPoints() const
{
    return points;
}
void Yellow9::setPoints(int pointsVal)
{
    points = pointsVal ;
}