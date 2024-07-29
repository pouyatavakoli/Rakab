#include "winter.h"

Winter::Winter(QWidget *parent)
    : Season(0, "Winter", parent) // Initialize Season with default values
{
    // Additional initialization specific to Winter if needed
}

std::string Winter::getName() const
{
    return name;
}

std::string Winter::getType() const
{
    return type;
}

int Winter::getNumberOnTheCard() const
{
    return numberOnTheCard;
}

int Winter::getPoints() const
{
    return points;
}

void Winter::setPoints(int pointsVal)
{
    points = pointsVal;
}
