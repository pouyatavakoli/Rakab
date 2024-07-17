#ifndef MATARSAK_HPP
#define MATARSAK_HPP

#include "PurpleCard.hpp"
#include "Player.hpp"

class Matarsak : public PurpleCard
{
public:
    Matarsak();
    // functions to override
    virtual std::string getName() const override;
    virtual std::string getType() const override;
    virtual int getNumerOnTheCard() const override;
    virtual int getPoints() const override;
    virtual void setPoints(int) override ;

    virtual void startEffect(Player &) ;
    virtual void endEffect(Player &) ;

private:
};
#endif