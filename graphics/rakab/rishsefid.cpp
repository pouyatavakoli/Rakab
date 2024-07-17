#include "rishsefid.h"

RishSefid::RishSefid(QObject *parent)
    : PurpleCard(0, "RishSefid", parent) // Initialize PurpleCard with default values
{
    // Additional initialization specific to RishSefid if needed
}

QString RishSefid::getName() const
{
    return name;
}

QString RishSefid::getType() const
{
    return type;
}

int RishSefid::getNumberOnTheCard() const
{
    return numberOnTheCard;
}

int RishSefid::getPoints() const
{
    return points;
}

void RishSefid::setPoints(int pointsVal)
{
    points = pointsVal;
}

