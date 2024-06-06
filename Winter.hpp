#ifndef WINTER_HPP
#define WINTER_HPP

#include "Season.hpp"

class Winter : public Season
{
public:
    Winter();
    void start(std::vector<Player> &);
    void end(std::vector<Player> &);
    virtual std::string getType() const;

private:
};
#endif