#include "ParchamDar.hpp"

// bool ParchamDar::ParchamAndBadkhahet() {}

ParchamDar::ParchamDar() : PurpleCard(0, "ParchamDar") {}


void ParchamDar::startEffect() {}

void ParchamDar::endEffect() {}
std::string ParchamDar::getName() const
{
    return name;
}
std::string ParchamDar::getType() const
{
    return type;
}
int ParchamDar::getNumerOnTheCard() const
{
    return numberOnTheCard;
}
int ParchamDar::getPoints() const
{
    return points;
}
void ParchamDar::setPoints(int pointsVal)
{
    points = pointsVal ;
}