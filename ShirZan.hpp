#ifndef SHIRZAN_HPP
#define SHIRZAN_HPP

#include "PurpleCard.hpp"

class ShirZan : public PurpleCard
{
public:
    ShirZan();
    virtual void startEffect() override;
    virtual void endEffect() override;

private:
};
#endif