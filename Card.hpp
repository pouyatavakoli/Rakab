#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
class Card
{
public:
    Card(int numberOnTheCard, std::string type, std::string name);

    // getters
    virtual std::string getName() const = 0;
    virtual std::string getType() const = 0;
    virtual int getNumerOnTheCard() const = 0;
    virtual int getPoints() const = 0;
    // setters
    virtual void setPoints(int) = 0;

protected:
    // exact name of the card
    const std::string name;
    // purple or yellow
    const std::string type;
    // number written on the card
    const int numberOnTheCard;
    // how much the card is worth depending on game situation
    int points;
};
#endif