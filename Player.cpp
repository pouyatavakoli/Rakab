#include "Player.hpp"
//setters
void Player::setAge(int ageVal){
    age = ageVal;
}
void Player::setName(std::string nameVal){
    name = nameVal;

}
//getters
int Player::getAge(){
    return age;
}
std::string Player::getName(){
    return name;
}
