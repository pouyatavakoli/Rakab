#ifndef WINTER_HPP
#define WINTER_HPP

#include "season.h"

class Winter : public Season
{
    Q_OBJECT

public:
    Winter(QObject *parent = nullptr);

    // Override virtual functions from Season
    QString getName() const override;
    QString getType() const override;
    int getNumberOnTheCard() const override;
    int getPoints() const override;
    void setPoints(int pointsVal) override;
};

#endif // WINTER_HPP

