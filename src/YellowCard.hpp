#ifndef YELLOW_HPP
#define YELLOW_HPP

#include "Card.hpp"

class YellowCard : public Card
{
public:
    YellowCard(int numberOnTheCard, std::string name);

    virtual std::string getType() const = 0;
    virtual std::string getName() const = 0;
    virtual int getNumerOnTheCard() const = 0;
    virtual int getPoints() const = 0;
    // setters
    virtual void setPoints(int) = 0;
};

#endif
