#ifndef SHIRDOKHT_HPP
#define SHIRDOKHT_HPP

#include "PurpleCard.hpp"

class ShirDokht : public PurpleCard
{
public:
    ShirDokht();
    virtual void startEffect() override;
    virtual void endEffect() override;

private:
};
#endif