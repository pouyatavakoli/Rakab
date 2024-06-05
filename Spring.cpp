#include "Spring.hpp"

Spring::Spring() : Season(0, "Spring") {}
void Spring::start(std::vector<Player> &)
{
}
void Spring::end(std::vector<Player> &)
{
}

std::string Spring::getType() const
{
    return Card::getType();
}