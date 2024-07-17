#include "Winter.h"

Winter::Winter(QObject *parent)
    : Season(0, "Winter", parent) // Initialize Season with default values
{
    // Additional initialization specific to Winter if needed
}

QString Winter::getName() const
{
    return name;
}

QString Winter::getType() const
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
