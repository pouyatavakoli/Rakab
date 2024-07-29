#ifndef YELLOW5_HPP
#define YELLOW5_HPP

#include "yellowcard.h"

class Yellow5 : public YellowCard
{
    Q_OBJECT

public:
    Yellow5(QWidget *parent = nullptr);

    std::string getName() const override;
    std::string getType() const override;
    int getNumberOnTheCard() const override;
    int getPoints() const override;
    void setPoints(int pointsVal) override;
};

#endif // YELLOW5_HPP
