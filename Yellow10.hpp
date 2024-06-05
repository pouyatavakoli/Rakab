#include "YellowCard.hpp"

#ifndef YELLOW10_HPP
#define YELLOW10_HPP
class Yellow10 : public YellowCard
{
public:
    Yellow10();
    virtual int get_score() const;
    virtual int getOriginalScore() const override;
    virtual std::string getType() const override;

private:
};
#endif