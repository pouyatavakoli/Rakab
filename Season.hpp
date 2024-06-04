#include "PurpleCard.hpp"
#include "Player.hpp"

#ifndef SEASON_HPP
#define SEASON_HPP

class Season : public PurpleCard
{
public:
    Season();
    void start(Player);
    void end(Player);

private:
};
#endif
