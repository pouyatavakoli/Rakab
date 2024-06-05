#include "YellowCard.hpp"

#ifndef YELLOW4_HPP
#define YELLOW4_HPP
class Yellow4 : public YellowCard
{
public:
    Yellow4();
    virtual int get_score() const;
    virtual int getOriginalScore() const override;
    virtual std::string getType() const override;

private:
};
#endif