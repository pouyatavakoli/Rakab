#include "matarsak.h"

Matarsak::Matarsak(QWidget *parent)
    : PurpleCard(0, "Matarsak", parent) // Initialize PurpleCard with default values
{
    // Additional initialization specific to ParchamDar if needed
    faceURL = ":/new/cards/banafsh/assets/cards/banafsh/Matarsak.png";
}

std::string Matarsak::getName() const
{
    return name;
}

std::string Matarsak::getType() const
{
    return type;
}

int Matarsak::getNumberOnTheCard() const
{
    return numberOnTheCard;
}

int Matarsak::getPoints() const
{
    return points;
}

void Matarsak::setPoints(int pointsVal)
{
    points = pointsVal;
}

void Matarsak::startEffect()
{
    // Implement start effect for Matarsak if needed
}

void Matarsak::endEffect()
{
    // Implement end effect for Matarsak if needed
}

