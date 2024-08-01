#include "yellow3.h"

Yellow3::Yellow3(QWidget *parent)
    : YellowCard(3, "Yellow3", parent)
{
    faceURL = ":/new/cards/zard/assets/cards/zard/003.png";
}

std::string Yellow3::getName() const
{
    return name;
}

std::string Yellow3::getType() const
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
