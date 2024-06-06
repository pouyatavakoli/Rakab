#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
class Card
{
public:
    Card(int numberOnTheCard, std::string type, std::string name);
    virtual void play();

    // getters
    virtual std::string getName() const;
    virtual std::string getType() const;
    virtual int getNumerOnTheCard() const;
    virtual int getPoints() const;
    // setters
    virtual void setPoints(int);

private:
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