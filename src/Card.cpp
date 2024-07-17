#include "card.h"

Card::Card(int numberOnTheCardVal, const QString &typeVal, const QString &nameVal, QObject *parent)
    : QObject(parent), name(nameVal), type(typeVal), numberOnTheCard(numberOnTheCardVal)
{
    points = numberOnTheCard;
}
