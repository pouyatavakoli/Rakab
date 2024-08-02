#include "parchamdar.h"

ParchamDar::ParchamDar(QWidget *parent)
    : PurpleCard(0, "ParchamDar", parent) // Initialize PurpleCard with default values
{
    // Additional initialization specific to ParchamDar if needed
    faceURL = ":/new/cards/banafsh/assets/cards/banafsh/Parcham_Dar.png";
}

std::string ParchamDar::getName() const
{
    return name;
}

std::string ParchamDar::getType() const
{
    return type;
}

int ParchamDar::getNumberOnTheCard() const
{
    return numberOnTheCard;
}

int ParchamDar::getPoints() const
{
    return points;
}

void ParchamDar::setPoints(int pointsVal)
{
    points = pointsVal;
}

void ParchamDar::startEffect()
{
    // Implement start effect for ParchamDar if needed
}

void ParchamDar::endEffect()
{
    // Implement end effect for ParchamDar if needed
}

