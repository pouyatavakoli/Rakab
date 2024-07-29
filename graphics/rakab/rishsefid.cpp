#include "rishsefid.h"

RishSefid::RishSefid(QWidget *parent)
    : PurpleCard(0, "RishSefid", parent) // Initialize PurpleCard with default values
{
    // Additional initialization specific to RishSefid if needed
}

std::string RishSefid::getName() const
{
    return name;
}

std::string RishSefid::getType() const
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

