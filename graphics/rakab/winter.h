#ifndef WINTER_HPP
#define WINTER_HPP

#include "season.h"

class Winter : public Season
{
    Q_OBJECT

public:
    Winter(QWidget *parent = nullptr);

    // Override virtual functions from Season
    std::string getName() const override;
    std::string getType() const override;
    int getNumberOnTheCard() const override;
    int getPoints() const override;
    void setPoints(int pointsVal) override;
};

#endif // WINTER_HPP

