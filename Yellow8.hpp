#include "YellowCard.hpp"

#ifndef YELLOW8_HPP
#define YELLOW8_HPP
class Yellow8 : public YellowCard
{
public:
    Yellow8();
    virtual int get_score() const;
    virtual int getOriginalScore() const override;
    virtual std::string getType() const override;

private:
};
#endif