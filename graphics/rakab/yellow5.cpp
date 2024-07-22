#include "yellow5.h"

Yellow5::Yellow5(QObject *parent)
    : YellowCard(5, "Yellow5", parent)
{
}

std::string Yellow5::getName() const
{
    return name;
}

std::string Yellow5::getType() const
{
    return type;
}

int Yellow5::getNumberOnTheCard() const
{
    return numberOnTheCard;
}

int Yellow5::getPoints() const
{
    return points;
}

void Yellow5::setPoints(int pointsVal)
{
    points = pointsVal;
}
