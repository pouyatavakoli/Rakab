#ifndef SPRING_HPP
#define SPRING_HPP

#include "season.h"

class Spring : public Season
{
    Q_OBJECT

public:
    Spring(QWidget *parent = nullptr);

    // Override virtual functions from Season
    std::string getName() const override;
    std::string getType() const override;
    int getNumberOnTheCard() const override;
    int getPoints() const override;
    void setPoints(int pointsVal) override;
};

#endif // SPRING_HPP
