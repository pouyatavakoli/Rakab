#ifndef YELLOW3_HPP
#define YELLOW3_HPP

#include "yellowcard.h"

class Yellow3 : public YellowCard
{
    Q_OBJECT

public:
    Yellow3(QObject *parent = nullptr);

    std::string getName() const override;
    std::string getType() const override;
    int getNumberOnTheCard() const override;
    int getPoints() const override;
    void setPoints(int pointsVal) override;
};

#endif // YELLOW3_HPP
