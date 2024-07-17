#include "yellow1.h"

Yellow1::Yellow1(QObject *parent)
    : YellowCard(1, "Yellow1", parent)
{
}

QString Yellow1::getName() const
{
    return name;
}

QString Yellow1::getType() const
{
    return type;
}

int Yellow1::getNumberOnTheCard() const
{
    return numberOnTheCard;
}

int Yellow1::getPoints() const
{
    return points;
}

void Yellow1::setPoints(int pointsVal)
{
    points = pointsVal;
}