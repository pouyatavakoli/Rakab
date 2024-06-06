#ifndef SHIRDOKHT_HPP
#define SHIRDOKHT_HPP

#include "PurpleCard.hpp"

class ShirDokht : public PurpleCard
{
public:
    ShirDokht();
    virtual std::string getName() const;
    virtual std::string getType() const;

private:
};
#endif