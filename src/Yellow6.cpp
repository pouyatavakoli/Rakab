#include "yellow6.h"

Yellow6::Yellow6(QObject *parent)
    : YellowCard(6, "Yellow6", parent)
{
}

QString Yellow6::getName() const
{
    return name;
}

QString Yellow6::getType() const
{
    return type;
}

int Yellow6::getNumberOnTheCard() const
{
    return numberOnTheCard;
}

int Yellow6::getPoints() const
{
    return points;
}

void Yellow6::setPoints(int pointsVal)
{
    points = pointsVal;
}
