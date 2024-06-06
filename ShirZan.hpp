#ifndef SHIRZAN_HPP
#define SHIRZAN_HPP

#include "PurpleCard.hpp"

class ShirZan : public PurpleCard
{
public:
    ShirZan();
    virtual std::string getName() const;
    virtual std::string getType() const;

private:
};
#endif