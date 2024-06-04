#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "YellowCard.hpp"
#include "PurpleCard.hpp"

class Player {
public:
    // constructor
    Player(int, std::string);
    // setters
    void setAge(int);
    void setName(std::string);
    void setScore(int score);
    void addOwnedProvinces(const std::string&);
    void addCardToPlayedYellow(std::shared_ptr<YellowCard>);
    void addCardToHandYellow(std::shared_ptr<YellowCard>);
    void addCardToPlayedPurple(std::shared_ptr<PurpleCard>);
    void addCardToHandPurple(std::shared_ptr<PurpleCard>);
    // getters
    int getAge() const;
    std::string getName() const;
    std::vector<std::string> getOwnedProvinces() const;
    std::vector<std::shared_ptr<YellowCard>> getPlayedYellowDeck() const;
    std::vector<std::shared_ptr<YellowCard>> getYellowHand() const;
    std::vector<std::shared_ptr<PurpleCard>> getPlayedPurpleDeck() const;
    std::vector<std::shared_ptr<PurpleCard>> getPurpleHand() const;
    int getScore() const;

private:
    int age;
    int score;
    std::string name;
    std::vector<std::string> owned_provinces;
    std::vector<std::shared_ptr<YellowCard>> playedYellowDeck;
    std::vector<std::shared_ptr<YellowCard>> yellowHand;
    std::vector<std::shared_ptr<PurpleCard>> playedPurpleDeck;
    std::vector<std::shared_ptr<PurpleCard>> purpleHand;
};

#endif // PLAYER_HPP
