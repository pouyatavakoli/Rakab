#ifndef YELLOW4_HPP
#define YELLOW4_HPP

#include "yellowcard.h"

class Yellow4 : public YellowCard
{
    Q_OBJECT

public:
    Yellow4(QObject *parent = nullptr);

    QString getName() const override;
    QString getType() const override;
    int getNumberOnTheCard() const override;
    int getPoints() const override;
    void setPoints(int pointsVal) override;
};

#endif // YELLOW4_HPP
