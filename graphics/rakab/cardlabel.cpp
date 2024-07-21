#include <QMouseEvent>

#include "cardlabel.h"

CardLabel::CardLabel(QWidget *parent) : QLabel(parent) {}

void CardLabel::setCard(const QString &color, int numberOnTheCard, int score) {
    this->color = color;
    this->numberOnTheCard = numberOnTheCard;
    this->score = score;

    QString imagePath = getCardImagePath();
    QPixmap pixmap(imagePath);
    if (pixmap.isNull()) {
        qWarning() << "Failed to load image:" << imagePath;
    } else {
        setPixmap(pixmap.scaled(100, 150, Qt::KeepAspectRatio));
    }
}

/*
QString CardLabel::getCardImagePath() const {
    QString numberStr = QString("%1").arg(numberOnTheCard, 3, 10, QChar('0')); // Pad the number with zeros to make it 3 digits
    return QString(":/new/cards/%1/assets/cards/%1/%2.png").arg(color).arg(numberStr);
}
*/

// test function for yellow1 png
QString CardLabel::getCardImagePath() const {
    return QString(":/new/cards/zard/assets/cards/zard/001.png");
}


void CardLabel::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        QByteArray itemData;
        QDataStream dataStream(&itemData, QIODevice::WriteOnly);
        dataStream << color << numberOnTheCard << score;

        QMimeData *mimeData = new QMimeData;
        mimeData->setData("application/x-card", itemData);

        QDrag *drag = new QDrag(this);
        drag->setMimeData(mimeData);
        drag->setPixmap(QPixmap::fromImage(grab().toImage()));
        drag->exec(Qt::MoveAction);
    }
}
