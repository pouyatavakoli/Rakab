#include "card.h"
#include <QDebug>

Card::Card(int numberOnTheCardVal, const std::string &typeVal, const std::string &nameVal, QWidget *parent)
    : QLabel(parent), numberOnTheCard(numberOnTheCardVal), type(typeVal), name(nameVal), points(0) {}

void Card::setName(std::string nameVal)
{
    name = nameVal ;
}

void Card::setType(std::string typeVal)
{
    type = typeVal ;
}

void Card::setNumberOnTheCard(int numberOnTheCardVal)
{
    numberOnTheCard = numberOnTheCardVal ;
}

void Card::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        qDebug() << "CardLabel clicked.";
        emit clicked();  // Emit clicked signal
    }
    QLabel::mouseReleaseEvent(event);  // Call base class handler
}

void Card::setFaceURL(std::string urlVal)
{
    faceURL = QString::fromStdString( urlVal ) ;
}

void Card::setBackURL(std::string urlVal)
{
    backURL = QString::fromStdString( urlVal ) ;
}

QString Card::getFaceURL()
{
    return faceURL;
}

QString Card::getBackURL()
{
    return backURL ;
}

void Card::setindexOfOwner(int x)
{
    indexOfOwner = x;
}

int Card::getindexOfOwner() const
{
    return indexOfOwner;
}

void Card::setImage(const QString &imagePath)
{
    QPixmap pixmap(imagePath);
    QPixmap scaledPixmap = pixmap.scaled(50, 75, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    this->setPixmap(scaledPixmap);
}

std::string Card::toString() const {
    std::ostringstream oss;
    oss  << name << ", "
//        << ", Type: " << type
//        << ", Number: " << numberOnTheCard
//        << ", Points: " << points
         << indexOfOwner;
    return oss.str();
}

