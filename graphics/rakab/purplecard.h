#ifndef PURPLECARD_HPP
#define PURPLECARD_HPP

#include <QObject>
#include <QString>
#include "card.h" // Include base class header
#include "player.h" // Include Player class header if needed

class PurpleCard : public Card
{
    Q_OBJECT

public:
    PurpleCard(int numberOnTheCardVal, const std::string &nameVal, QObject *parent = nullptr);

    // Override pure virtual functions from Card
    virtual std::string getName() const override = 0;
    virtual std::string getType() const override = 0;
    virtual int getNumberOnTheCard() const override = 0;
    virtual int getPoints() const override = 0;
    virtual void setPoints(int pointsVal) override;

    // Additional methods specific to PurpleCard
    virtual void startEffect();
    virtual void startEffect(Player &player); // overloaded for Player parameter

    virtual void endEffect();
    virtual void endEffect(Player &player); // overloaded for Player parameter

    virtual void refresh();
};

#endif // PURPLECARD_HPP
