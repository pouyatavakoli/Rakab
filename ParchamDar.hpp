#ifndef PARCHAMDAR_HPP
#define PARCHAMDAR_HPP

#include "PurpleCard.hpp"

class ParchamDar : public PurpleCard
{
public:
    ParchamDar();
    // bool ParchamAndBadkhahet(); // It ends the game so inout should br Game type(probably!!!)

    virtual void startEffect() ;
    virtual void endEffect() ;
    virtual std::string getName() const override;
    virtual std::string getType() const override;
    virtual int getNumerOnTheCard() const override;
    virtual int getPoints() const override;
    virtual void setPoints(int) override;

private:
};
#endif