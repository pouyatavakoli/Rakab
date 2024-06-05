#include "Season.hpp"
#include "Game.hpp"

#ifndef SPRING_HPP
#define SPRING_HPP

class Spring : public Season
{
public:
    Spring();
    void start(Game &);
    void end(Game &);
    virtual std::string getType() const;
    void refresh(Game &);

private:
};
#endif