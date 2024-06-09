#include "ShirZan.hpp"

ShirZan::ShirZan() : PurpleCard(1, "ShirZan") {}

void ShirZan::startEffect() {}

void ShirZan::endEffect() {}

std::string ShirZan::getName() const
{
    return name;
}
std::string ShirZan::getType() const
{
    return type;
}
int ShirZan::getNumerOnTheCard() const
{
    return numberOnTheCard;
}
int ShirZan::getPoints() const
{
    return points;
}
void ShirZan::setPoints(int pointsVal)
{
    points = pointsVal;
}