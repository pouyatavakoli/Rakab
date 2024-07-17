#include "yellow4.h"

Yellow4::Yellow4(QObject *parent)
    : YellowCard(4, "Yellow4", parent)
{
}

QString Yellow4::getName() const
{
    return name;
}

QString Yellow4::getType() const
{
    return type;
}

int Yellow4::getNumberOnTheCard() const
{
    return numberOnTheCard;
}

int Yellow4::getPoints() const
{
    return points;
}

void Yellow4::setPoints(int pointsVal)
{
    points = pointsVal;
}

