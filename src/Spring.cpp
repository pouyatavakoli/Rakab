#include "Spring.hpp"

Spring::Spring() : Season(0, "Spring") {}

std::string Spring::getName() const
{
    return name;
}
std::string Spring::getType() const
{
    return type;
}
int Spring::getNumerOnTheCard() const
{
    return numberOnTheCard;
}
int Spring::getPoints() const
{
    return points;
}
void Spring::setPoints(int pointsVal)
{
    points = pointsVal;
}