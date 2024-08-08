#include "yellow1.h"

Yellow1::Yellow1(QWidget *parent)
    : YellowCard(1, "Yellow1", parent)
{
    faceURL = ":/new/cards/zard/assets/cards/zard/001.png";
}


std::string Yellow1::getName() const
{
    return name;
}

std::string Yellow1::getType() const
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
