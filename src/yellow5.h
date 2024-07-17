#ifndef YELLOW5_HPP
#define YELLOW5_HPP

#include "yellowcard.h"

class Yellow5 : public YellowCard
{
    Q_OBJECT

public:
    Yellow5(QObject *parent = nullptr);

    QString getName() const override;
    QString getType() const override;
    int getNumberOnTheCard() const override;
    int getPoints() const override;
    void setPoints(int pointsVal) override;
};

#endif // YELLOW5_HPP
