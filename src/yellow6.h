#ifndef YELLOW6_HPP
#define YELLOW6_HPP

#include "yellowcard.h"

class Yellow6 : public YellowCard
{
    Q_OBJECT

public:
    Yellow6(QObject *parent = nullptr);

    QString getName() const override;
    QString getType() const override;
    int getNumberOnTheCard() const override;
    int getPoints() const override;
    void setPoints(int pointsVal) override;
};

#endif // YELLOW6_HPP
