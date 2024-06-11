#ifndef PURPLE_HPP
#define PURPLE_HPP

#include "Card.hpp"
#include "Player.hpp"
#include "Game.hpp"

class PurpleCard : public Card
{
public:
    PurpleCard(int, std::string);

    // virtual std::string getName() const;
    // virtual std::string getType() const;
    // virtual int getNumerOnTheCard() const;
    // virtual int getPoints() const;
    virtual std::string getName() const = 0;
    virtual std::string getType() const = 0;
    virtual int getNumerOnTheCard() const = 0;
    virtual int getPoints() const = 0;
    // setters
    virtual void setPoints(int);

    virtual void startEffect();
    virtual void startEffect(Player &); // overloaded

    virtual void endEffect();
    virtual void endEffect(Player &); // overloaded

    virtual void refresh();
};
#endif
