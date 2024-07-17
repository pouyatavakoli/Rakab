#ifndef CARD_H
#define CARD_H

#include <QObject>
#include <QString>

class Card : public QObject
{
    Q_OBJECT

public:
    explicit Card(int numberOnTheCardVal, const QString &typeVal, const QString &nameVal, QObject *parent = nullptr);

    virtual QString getName() const = 0;
    virtual QString getType() const = 0;
    virtual int getNumberOnTheCard() const = 0;
    virtual int getPoints() const = 0;
    virtual void setPoints(int pointsVal) = 0;

protected:
    QString name;
    QString type;
    int numberOnTheCard;
    int points;
};

#endif // CARD_H
