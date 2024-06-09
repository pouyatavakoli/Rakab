#ifndef PURPLE_HPP
#define PURPLE_HPP

#include "Card.hpp"
#include "Player.hpp"
#include "Game.hpp"

class PurpleCard : public Card
{
public:
    PurpleCard(int, std::string);

    // functions to override
    virtual std::string getName() const = 0;
    virtual std::string getType() const = 0;
    virtual int getNumerOnTheCard() const = 0;
    virtual int getPoints() const = 0;
    // setters
    virtual void setPoints(int) = 0;
    virtual void startEffect();
    virtual void endEffect();
    virtual void refresh();
    virtual void startEffect(Player &);              // overloaded
    virtual void endEffect(Player &);                // overloaded
    virtual void startEffect(Game &);                // overloaded
    virtual void endEffect(Game &);                  // overloaded
    virtual void refresh(Game &);                    // overloaded
    virtual void startEffect(std::vector<Player> &); // overloaded
    virtual void endEffect(std::vector<Player> &);   // overloaded
    virtual void refresh(std::vector<Player> &);     // overloaded
};
#endif
