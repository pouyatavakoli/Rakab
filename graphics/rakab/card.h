#ifndef CARD_H
#define CARD_H

#include <QObject>
#include <string>

class Card : public QObject
{
    Q_OBJECT

public:
    explicit Card(int numberOnTheCardVal, const std::string &typeVal, const std::string &nameVal, QObject *parent = nullptr);

    virtual std::string getName() const = 0;
    virtual std::string getType() const = 0;
    virtual int getNumberOnTheCard() const = 0;
    virtual int getPoints() const = 0;
    virtual void setPoints(int pointsVal) = 0;

protected:
    std::string name;
    std::string type;
    int numberOnTheCard;
    int points;
};

#endif // CARD_H
