#include "yellowcard.h"

YellowCard::YellowCard(int numberOnTheCard, const QString &nameVal, QObject *parent)
    : Card(numberOnTheCard, "Yellow", nameVal, parent)
{
}
