#include "yellow6.h"

Yellow6::Yellow6(QWidget *parent)
    : YellowCard(6, "Yellow6", parent)
{
    faceURL = ":/new/cards/zard/assets/cards/zard/006.png";
}

std::string Yellow6::getName() const
{
    return name;
}

std::string Yellow6::getType() const
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
