#ifndef YELLOWCARD_HPP
#define YELLOWCARD_HPP

#include "card.h"

class YellowCard : public Card
{
    Q_OBJECT

public:
    YellowCard(int numberOnTheCard, const std::string &nameVal, QObject *parent = nullptr);

    // Pure virtual functions to be implemented by derived classes
    virtual std::string getType() const override = 0;
    virtual std::string getName() const override = 0;
    virtual int getNumberOnTheCard() const override = 0;
    virtual int getPoints() const override = 0;
    virtual void setPoints(int pointsVal) override = 0;
};

#endif // YELLOWCARD_HPP
