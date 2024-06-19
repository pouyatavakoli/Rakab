#include "Yellow10.hpp"

Yellow10::Yellow10() : YellowCard(10, "Yellow10") {}

std::string Yellow10::getName() const
{
    return name;
}
std::string Yellow10::getType() const
{
    return type;
}
int Yellow10::getNumerOnTheCard() const
{
    return numberOnTheCard;
}
int Yellow10::getPoints() const
{
    return points;
}
void Yellow10::setPoints(int pointsVal)
{
    points = pointsVal ;
}