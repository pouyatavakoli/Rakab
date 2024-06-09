#ifndef SEASON_HPP
#define SEASON_HPP

#include "PurpleCard.hpp"
#include "Player.hpp"

class Season : public PurpleCard
{
public:
    Season(int, std::string);
    virtual std::string getName() const = 0;
    virtual std::string getType() const = 0;
    virtual int getNumerOnTheCard() const = 0;
    virtual int getPoints() const = 0;
private:
};
#endif
