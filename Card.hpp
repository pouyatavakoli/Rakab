#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
class Card
{
public:
    Card();
    Card(int, std::string);
    void play();
    virtual void set_score(int);
    virtual int get_score() const;
    virtual std::string getType();

private:
    std::string type;
    int score;
};
#endif