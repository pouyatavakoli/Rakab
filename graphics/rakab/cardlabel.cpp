#include "cardlabel.h"
#include <QMouseEvent>
#include <QDebug>

CardLabel::CardLabel(QWidget *parent) : QLabel(parent) {}

void CardLabel::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        qDebug() << "CardLabel clicked.";
        emit clicked();  // Emit clicked signal
    }
    QLabel::mouseReleaseEvent(event);  // Call base class handler
}

