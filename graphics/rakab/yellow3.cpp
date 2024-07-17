#include "yellow3.h"

Yellow3::Yellow3(QObject *parent)
    : YellowCard(3, "Yellow3", parent)
{
}

QString Yellow3::getName() const
{
    return name;
}

QString Yellow3::getType() const
{
    return type;
}

int Yellow3::getNumberOnTheCard() const
{
    return numberOnTheCard;
}

int Yellow3::getPoints() const
{
    return points;
}

void Yellow3::setPoints(int pointsVal)
{
    points = pointsVal;
}
