#include "cardlabel.h"

CardLabel::CardLabel(QWidget *parent) : QLabel(parent)
{
}

void CardLabel::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked();
    }
    QLabel::mousePressEvent(event);
}
