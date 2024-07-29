#ifndef YELLOW2_HPP
#define YELLOW2_HPP

#include "yellowcard.h"

class Yellow2 : public YellowCard
{
    Q_OBJECT

public:
    Yellow2(QWidget *parent = nullptr);

    std::string getName() const override;
    std::string getType() const override;
    int getNumberOnTheCard() const override;
    int getPoints() const override;
    void setPoints(int pointsVal) override;
};

#endif // YELLOW2_HPP
