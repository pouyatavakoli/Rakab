#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <QObject>
#include <QString>
#include <sstream>

#include "card.h"

class Player : public QObject {
    Q_OBJECT

public:

    Player(QObject *parent = nullptr);
    Player(int age, const std::string &name, QObject *parent = nullptr);


    void setAge(int age);
    void setName(const std::string &name);
    void setColor(const std::string &color);
    void setScore(int score);
    void setCanPutNeshaneJang(bool);
    void setCanPutNeshaneSolh(bool);
    void setWinStatus(bool status);

    void addOwnedProvinces(const std::string &);
    void addCardToYellowOnTable(std::shared_ptr<Card>);
    void addCardToYellowHand(std::shared_ptr<Card>);
    void addCardToPurpleOnTable(std::shared_ptr<Card>);
    void setPurpleOnTable(std::vector<std::shared_ptr<Card>>);
    void addCardToPurpleHand(std::shared_ptr<Card>);
    std::shared_ptr<Card> removeCardFromYellowOnTable(const std::string &cardName);

    bool getWinStatus();
    std::vector<std::string> getOwnedProvinces() const;
    std::vector<std::shared_ptr<Card>> getYellowOnTable() const;
    std::vector<std::shared_ptr<Card>> getYellowHand() const;
    std::vector<std::shared_ptr<Card>> getPurpleOnTable() const;
    std::vector<std::shared_ptr<Card>> getPurpleHand() const;
    std::vector<std::shared_ptr<Card>> getPlayedCards() const;

    int getPoints() const;
    int getNumberOfOwnedProvinces();
    int getCountShirZan() const;
    bool getCanPutNeshaneJang() const;
    bool getCanPutNeshaneSolh() const;

    int getAge() const;
    std::string getName() const;
    std::string getColor() const;

    int playPurpleCard(const std::string &);
    bool playYellowCard(const std::string &);
    int PlayThisCard(const std::string);

    int getTablZanCounter() const;
    void incrementTablZanCounter();
    bool getUsedRakhshSefid() const;

    void applyEffect();
    void cancelEffects();
    void burnHand();

    bool canPlay();
    void passAndDontPlay();
    void updatePlayerEligibility(bool);

    void flushTable();

    std::string toString() const;

    void reset();

    void setTablZanCounter(int);
    void setUsedRakhshSefid(bool);
private:
    int age;
    std::string name;
    std::string color;
    int totalScore;
    bool isAbleToPlay;
    bool winStatus;
    bool usedTablZan;
    int countShirZan{0};
    bool canPutNeshaneSolh; // can be changed by RishSefid
    bool canPutNeshaneJang; // can be changed by ShirZan
    std::vector<std::string> dominatedAreas;
    std::vector<std::shared_ptr<Card>> yellowOnTable;
    std::vector<std::shared_ptr<Card>> purpleOnTable;
    std::vector<std::shared_ptr<Card>> yellowHand;
    std::vector<std::shared_ptr<Card>> purpleHand;
    std::vector<std::shared_ptr<Card>> burntCards;
    std::vector<std::shared_ptr<Card>> playedCards;

    int tablZanCounter{0};
    bool usedRakhshSefid{false};
};

#endif // PLAYER_HPP
