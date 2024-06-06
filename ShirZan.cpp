#include "ShirZan.hpp"

ShirZan::ShirZan() : PurpleCard(1, "ShirZan") {}

std::string ShirZan::getName() const
{
    return Card::getName();
}

std::string ShirZan::getType() const
{
    return Card::getType();
}