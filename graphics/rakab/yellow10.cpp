#include "yellow10.h"

Yellow10::Yellow10(QObject *parent)
    : YellowCard(10, "Yellow10", parent)
{
}

std::string Yellow10::getName() const
{
    return name;
}

std::string Yellow10::getType() const
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
