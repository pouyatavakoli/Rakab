#ifndef CARD_HPP
#define CARD_HPP
class Card
{
public:
    Card();
    Card(int);
    void play();
    virtual int get_score() const;

private:
    int score;
};
#endif