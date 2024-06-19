#include "Province.hpp"

Province::Province() {}

void Province::set_name(std::string name)
{
    this->name = name;
}

std::string Province::get_name() const
{
    return name;
}
