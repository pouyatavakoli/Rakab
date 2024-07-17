#include "yellow10.h"

Yellow10::Yellow10(QObject *parent)
    : YellowCard(10, "Yellow10", parent)
{
}

QString Yellow10::getName() const
{
    return name;
}

QString Yellow10::getType() const
{
    return type;
}

int Yellow10::getNumberOnTheCard() const
{
    return numberOnTheCard;
}

int Yellow10::getPoints() const
{
    return points;
}

void Yellow10::setPoints(int pointsVal)
{
    points = pointsVal;
}
