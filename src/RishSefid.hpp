#ifndef RISHSEFID_HPP
#define RISHSEFID_HPP

#include "PurpleCard.hpp"

class RishSefid : public PurpleCard
{
public:
    RishSefid();

    // Override virtual functions from PurpleCard
    virtual std::string getName() const override;
    virtual std::string getType() const override;
    virtual int getNumerOnTheCard() const override;
    virtual int getPoints() const override;
    virtual void setPoints(int) override;
};

#endif // RISHSEFID_HPP
