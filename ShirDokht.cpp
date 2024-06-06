#include "ShirDokht.hpp"

ShirDokht::ShirDokht() : PurpleCard(10, "ShirDokht") {}

std::string ShirDokht::getName() const
{
    return Card::getName();
}

std::string ShirDokht::getType() const
{
    return Card::getType();
}