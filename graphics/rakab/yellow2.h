#ifndef YELLOW2_HPP
#define YELLOW2_HPP

#include "yellowcard.h"

class Yellow2 : public YellowCard
{
    Q_OBJECT

public:
    Yellow2(QObject *parent = nullptr);

    QString getName() const override;
    QString getType() const override;
    int getNumberOnTheCard() const override;
    int getPoints() const override;
    void setPoints(int pointsVal) override;
};

#endif // YELLOW2_HPP
