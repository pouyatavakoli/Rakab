#ifndef SHIRZAN_HPP
#define SHIRZAN_HPP

#include "PurpleCard.hpp"

class ShirZan : public PurpleCard
{
public:
    ShirZan();
    virtual void startEffect() override;
    virtual void endEffect() override;
    virtual std::string getName() const override;
    virtual std::string getType() const override;
    virtual int getNumerOnTheCard() const override;
    virtual int getPoints() const override;
    virtual void setPoints(int) override;

private:
};
#endif