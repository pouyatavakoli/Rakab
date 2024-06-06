#include "PurpleCard.hpp"

#ifndef SHIRDOKHT_HPP
#define SHIRDOKHT_HPP

class ShirDokht : public PurpleCard
{
public:
    ShirDokht();
    virtual std::string getName() const;
    virtual std::string getType() const;

private:
};
#endif