#include "card.h"
#include <QDebug>

Card::Card(int numberOnTheCardVal, const std::string &typeVal, const std::string &nameVal, QWidget *parent)
    : QLabel(parent), numberOnTheCard(numberOnTheCardVal), type(typeVal), name(nameVal), points(0) {}

void Card::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        qDebug() << "CardLabel clicked.";
        emit clicked();  // Emit clicked signal
    }
    QLabel::mouseReleaseEvent(event);  // Call base class handler
}
