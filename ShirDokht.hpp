#ifndef SHIRDOKHT_HPP
#define SHIRDOKHT_HPP

#include "PurpleCard.hpp"

class ShirDokht : public PurpleCard
{
public:
    ShirDokht();
    virtual std::string getName() const override;
    virtual std::string getType() const override;
    virtual int getNumerOnTheCard() const override;
    virtual int getPoints() const override;
    virtual void setPoints(int) override;

private:
};
#endif