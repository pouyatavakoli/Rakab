#include "Yellow5.hpp"

Yellow5::Yellow5() : YellowCard(5, "Yellow5") {}

std::string Yellow5::getName() const
{
    return name;
}
std::string Yellow5::getType() const
{
    return type;
}
int Yellow5::getNumerOnTheCard() const
{
    return numberOnTheCard;
}
int Yellow5::getPoints() const
{
    return points;
}
void Yellow5::setPoints(int pointsVal)
{
    points = pointsVal ;
}