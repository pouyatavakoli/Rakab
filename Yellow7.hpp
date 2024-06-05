#include "YellowCard.hpp"

#ifndef YELLOW7_HPP
#define YELLOW7_HPP
class Yellow7 : public YellowCard
{
public:
    Yellow7();
    virtual int get_score() const;
    virtual int getOriginalScore() const override;
    virtual std::string getType() const override;

private:
};
#endif