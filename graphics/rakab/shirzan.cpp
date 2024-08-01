#include "shirzan.h"

ShirZan::ShirZan(QWidget *parent)
    : PurpleCard(1, "ShirZan", parent) // Initialize PurpleCard with default values
{
    // Additional initialization specific to ShirZan if needed
    faceURL = ":/new/cards/banafsh/assets/cards/banafsh/Shir_Zan.png";
}

void ShirZan::startEffect()
{
    // Implement start effect for ShirZan
}

void ShirZan::endEffect()
{
    // Implement end effect for ShirZan
}

std::string ShirZan::getName() const
{
    return name;
}

std::string ShirZan::getType() const
{
    return type;
}

int ShirZan::getNumberOnTheCard() const
{
    return numberOnTheCard;
}

int ShirZan::getPoints() const
{
    return points;
}

void ShirZan::setPoints(int pointsVal)
{
    points = pointsVal;
}
