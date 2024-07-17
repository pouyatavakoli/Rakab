#ifndef SEASON_HPP
#define SEASON_HPP

#include "purplecard.h"

class Season : public PurpleCard
{
    Q_OBJECT

public:
    Season(int numberOnTheCardVal, const QString &nameVal, QObject *parent = nullptr);

    // Override virtual functions from PurpleCard
    virtual QString getName() const override = 0;
    virtual QString getType() const override = 0;
    virtual int getNumberOnTheCard() const override = 0;
    virtual int getPoints() const override = 0;
};

#endif // SEASON_HPP
