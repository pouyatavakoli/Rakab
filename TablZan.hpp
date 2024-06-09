#ifndef TABLZAN_HPP
#define TABLZAN_HPP

#include "PurpleCard.hpp"
#include "Player.hpp"

class TablZan : public PurpleCard
{
public:
    TablZan();
    virtual void startEffect(Player &) override;
    virtual void endEffect(Player &) override;
    virtual std::string getName() const override;
    virtual std::string getType() const override;
    virtual int getNumerOnTheCard() const override;
    virtual int getPoints() const override;
    virtual void setPoints(int) override;

private:
};
#endif