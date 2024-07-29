#ifndef YELLOW6_HPP
#define YELLOW6_HPP

#include "yellowcard.h"

class Yellow6 : public YellowCard
{
    Q_OBJECT

public:
    Yellow6(QWidget *parent = nullptr);

    std::string getName() const override;
    std::string getType() const override;
    int getNumberOnTheCard() const override;
    int getPoints() const override;
    void setPoints(int pointsVal) override;
};

#endif // YELLOW6_HPP
