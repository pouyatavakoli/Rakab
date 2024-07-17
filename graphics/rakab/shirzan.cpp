#include "shirzan.h"

ShirZan::ShirZan(QObject *parent)
    : PurpleCard(1, "ShirZan", parent) // Initialize PurpleCard with default values
{
    // Additional initialization specific to ShirZan if needed
}

void ShirZan::startEffect()
{
    // Implement start effect for ShirZan
}

void ShirZan::endEffect()
{
    // Implement end effect for ShirZan
}

QString ShirZan::getName() const
{
    return name;
}

QString ShirZan::getType() const
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
