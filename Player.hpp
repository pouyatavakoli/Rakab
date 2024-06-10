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
    void setColor(std::string color);
    void updatePlayerEligibility(bool);
    void setWinStatus(bool status);
    void addOwnedProvinces(const std::string &);
    void addCardToYellowOnTable(std::shared_ptr<Card>);
    void addCardToYellowHand(std::shared_ptr<Card>);
    void addCardToPurpleOnTable(std::shared_ptr<Card>);
    void addCardToPurpleHand(std::shared_ptr<Card>);
    std::shared_ptr<Card> removeCardFromYellowOnTable(const std::string &cardName);
    std::shared_ptr<Card> removeCardFromPurpleOnTable(const std::string &cardName); // IMPLEMENTATION IS UNDONE
    std::shared_ptr<Card> removeCardFromYellowHand(const std::string &cardName);    // IMPLEMENTATION IS UNDONE
    std::shared_ptr<Card> removeCardFromPurpleHand(const std::string &cardName);    // IMPLEMENTATION IS UNDONE
    // getters
    int getAge() const;
    std::string getName() const;
    int getPoints() const;
    std::string getColor();
    bool canPlay();
    bool getWinStatus();
    std::vector<std::string> getOwnedProvinces() const;
    std::vector<std::shared_ptr<Card>> getYellowOnTable() const;
    std::vector<std::shared_ptr<Card>> getYellowHand() const;
    std::vector<std::shared_ptr<Card>> getPurpleOnTable() const;
    std::vector<std::shared_ptr<Card>> getPurpleHand() const;
    void passAndDontPlay();
    bool playPurpleCard(const std::string &);
    bool playYellowCard(const std::string &);
    void increaseScore(int);
    int getNumberOfOwnedProvinces();
private:
    int age;
    std::string name;
    std::string color;
    int totalScore;
    bool isAbleToPlay;
    bool winStatus ;
    std::vector<std::string> dominatedAreas;
    std::vector<std::shared_ptr<Card>> yellowOnTable;
    std::vector<std::shared_ptr<Card>> purpleOnTable;
    std::vector<std::shared_ptr<Card>> yellowHand;
    std::vector<std::shared_ptr<Card>> purpleHand;
};

#endif
