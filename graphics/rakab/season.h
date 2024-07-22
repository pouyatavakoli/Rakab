#ifndef SEASON_HPP
#define SEASON_HPP

#include "purplecard.h"

class Season : public PurpleCard
{
    Q_OBJECT

public:
    Season(int numberOnTheCardVal, const std::string &nameVal, QObject *parent = nullptr);

    // Override virtual functions from PurpleCard
    virtual std::string getName() const override = 0;
    virtual std::string getType() const override = 0;
    virtual int getNumberOnTheCard() const override = 0;
    virtual int getPoints() const override = 0;
};

#endif // SEASON_HPP
