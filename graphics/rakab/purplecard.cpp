#include "purplecard.h"

PurpleCard::PurpleCard(int numberOnTheCardVal, const std::string &nameVal, QObject *parent)
    : Card(numberOnTheCardVal, "Purple", nameVal, parent)
{

}

void PurpleCard::setPoints(int pointsVal)
{
    points = pointsVal;
}

void PurpleCard::startEffect()
{

}

void PurpleCard::startEffect(Player &player)
{

}

void PurpleCard::endEffect()
{

}

void PurpleCard::endEffect(Player &player)
{

}

void PurpleCard::refresh()
{

}
