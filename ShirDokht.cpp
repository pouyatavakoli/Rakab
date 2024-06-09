#include "ShirDokht.hpp"

ShirDokht::ShirDokht() : PurpleCard(10, "ShirDokht") {}

void ShirDokht::startEffect() {}

void ShirDokht::endEffect() {}

std::string ShirDokht::getName() const
{
    return name;
}
std::string ShirDokht::getType() const
{
    return type;
}
int ShirDokht::getNumerOnTheCard() const
{
    return numberOnTheCard;
}
int ShirDokht::getPoints() const
{
    return points;
}
void ShirDokht::setPoints(int pointsVal)
{
    points = pointsVal ;
}