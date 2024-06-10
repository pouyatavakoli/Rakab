#ifndef PURPLE_HPP
#define PURPLE_HPP

#include "Card.hpp"
#include "Player.hpp"
#include "Game.hpp"

class PurpleCard : public Card
{
public:
    PurpleCard(int, std::string);

    virtual std::string getName() const = 0;
    virtual std::string getType() const = 0;
    virtual int getNumerOnTheCard() const = 0;
    virtual int getPoints() const = 0;
    // setters
    virtual void setPoints(int) = 0;

    virtual void startEffect() = 0;
    virtual void startEffect(Player &) = 0;              // overloaded
    virtual void startEffect(Game &)= 0;                // overloaded
    virtual void startEffect(std::vector<Player> &) = 0; // overloaded

    virtual void endEffect() = 0;
    virtual void endEffect(Player &) = 0;                // overloaded
    virtual void endEffect(Game &) = 0;                  // overloaded
    virtual void endEffect(std::vector<Player> &) = 0;   // overloaded

    virtual void refresh() = 0;
    virtual void refresh(Game &) = 0;                    // overloaded
    virtual void refresh(std::vector<Player> &) = 0;     // overloaded
};
#endif
