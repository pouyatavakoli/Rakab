#include "spring.h"

Spring::Spring(QObject *parent)
    : Season(0, "Spring", parent) // Initialize Season with default values
{
    // Additional initialization specific to Spring if needed
}

QString Spring::getName() const
{
    return name;
}

QString Spring::getType() const
{
    return type;
}

int Spring::getNumberOnTheCard() const
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
