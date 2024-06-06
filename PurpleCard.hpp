#ifndef PURPLE_HPP
#define PURPLE_HPP

#include "Card.hpp"
#include "Player.hpp"
#include "Game.hpp"

class PurpleCard : public Card
{
public:
    PurpleCard(int, std::string);

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
