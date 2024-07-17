#ifndef SPRING_HPP
#define SPRING_HPP

#include "season.h"

class Spring : public Season
{
    Q_OBJECT

public:
    Spring(QObject *parent = nullptr);

    // Override virtual functions from Season
    QString getName() const override;
    QString getType() const override;
    int getNumberOnTheCard() const override;
    int getPoints() const override;
    void setPoints(int pointsVal) override;
};

#endif // SPRING_HPP
