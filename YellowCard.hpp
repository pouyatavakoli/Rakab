#include "Card.hpp"

#ifndef YELLOW_HPP
#define YELLOW_Hpp

class YellowCard : public Card
{
public:
    YellowCard();
    YellowCard(int, std::string);
    void set_score(int);
    virtual std::string getType();

private:
};
#endif
