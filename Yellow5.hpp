#include "YellowCard.hpp"

#ifndef YELLOW5_HPP
#define YELLOW5_HPP
class Yellow5 : public YellowCard
{
public:
    Yellow5();
    virtual int get_score() const;
    virtual int getOriginalScore() const override;
    virtual std::string getType() const override;

private:
};
#endif