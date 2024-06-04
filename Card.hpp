#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
class Card
{
public:
    Card();
    Card(int, std::string);
    void play();
    virtual int get_score() const;
    std::string getType();

private:
    std::string type;
    int score;
};
#endif