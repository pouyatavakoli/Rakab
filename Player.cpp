#include "Player.hpp"
// constructor
Player::Player(int ageVal, std::string nameVal)
{
    age = ageVal;
    name = nameVal;
}

// setters
void Player::setAge(int ageVal)
{
    age = ageVal;
}
void Player::setName(std::string nameVal)
{
    name = nameVal;
}
// getters
int Player::getAge()
{
    return age;
}
std::string Player::getName()
{
    return name;
}
