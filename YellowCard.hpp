#include "Card.hpp"

#ifndef YELLOW_HPP
#define YELLOW_Hpp

class YellowCard : public Card
{
public:
    YellowCard();
    YellowCard(int, int, std::string);
    void set_score(int);
    virtual std::string getType();
    virtual int getOriginalScore() const;

private:
    const int originalScore;
};
#endif
