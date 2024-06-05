#include "YellowCard.hpp"

#ifndef YELLOW9_HPP
#define YELLOW9_HPP
class Yellow9 : public YellowCard
{
public:
    Yellow9();
    virtual int get_score() const;
    virtual int getOriginalScore() const override;
private:
};
#endif