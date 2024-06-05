#include "YellowCard.hpp"

#ifndef YELLOW2_HPP
#define YELLOW2_HPP
class Yellow2 : public YellowCard
{
public:
    Yellow2();
    virtual int get_score() const;
    virtual int getOriginalScore() const override;
    virtual std::string getType() const override;
private:
};
#endif // YELLOW2_HPP