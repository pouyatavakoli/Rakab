#include <string>
#ifndef PLAYER_HPP
#define PLAYER_HPP
class Player
{
public:
    // constructor
    Player(int, std::string);
    // setters
    void setAge(int);
    void setName(std::string);
    // getters
    int getAge();
    std::string getName();

private:
    int age;
    std::string name;
};
#endif