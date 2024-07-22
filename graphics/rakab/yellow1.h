#ifndef YELLOW1_HPP
#define YELLOW1_HPP

#include "yellowcard.h"

class Yellow1 : public YellowCard
{
    Q_OBJECT

public:
    Yellow1(QObject *parent = nullptr);

    std::string getName() const override;
    std::string getType() const override;
    int getNumberOnTheCard() const override;
    int getPoints() const override;
    void setPoints(int pointsVal) override;
};

#endif // YELLOW1_HPP
