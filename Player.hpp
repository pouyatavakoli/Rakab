#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <memory>
#include <string>

#include "Card.hpp"

class Player
{
public:
    // constructor
    Player();
    Player(int age, std::string name);
    // setters
    void setAge(int age);
    void setName(std::string name);
    void setScore(int score);
    void addOwnedProvinces(const std::string &);
    void addCardToYellowOnTable(std::shared_ptr<Card>);
    void addCardToYellowHand(std::shared_ptr<Card>);
    void addCardToPurpleOnTable(std::shared_ptr<Card>);
    void addCardToPurpleHand(std::shared_ptr<Card>);
    std::shared_ptr<Card> removeCardFromYellowOnTable(const std::string &cardName);
    std::shared_ptr<Card> removeCardFromPurpleOnTable(const std::string &cardName);
    std::shared_ptr<Card> removeCardFromYellowHand(const std::string &cardName);
    std::shared_ptr<Card> removeCardFromPurpleHand(const std::string &cardName);
    // getters
    int getAge() const;
    std::string getName() const;
    int getPoints() const;
    std::vector<std::string> getOwnedProvinces() const;
    std::vector<std::shared_ptr<Card>> getYellowOnTable() const;
    std::vector<std::shared_ptr<Card>> getYellowHand() const;
    std::vector<std::shared_ptr<Card>> getPurpleOnTable() const;
    std::vector<std::shared_ptr<Card>> getPurpleHand() const;

private:
    int age;
    std::string name;
    int totalScore;
    std::vector<std::string> dominatedAreas;
    std::vector<std::shared_ptr<Card>> yellowOnTable;
    std::vector<std::shared_ptr<Card>> purpleOnTable;
    std::vector<std::shared_ptr<Card>> yellowHand;
    std::vector<std::shared_ptr<Card>> purpleHand;
};

#endif
