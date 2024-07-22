#include "yellowcard.h"

YellowCard::YellowCard(int numberOnTheCard, const std::string &nameVal, QObject *parent)
    : Card(numberOnTheCard, "Yellow", nameVal, parent)
{
}
