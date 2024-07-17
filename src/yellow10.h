#ifndef YELLOW10_HPP
#define YELLOW10_HPP

#include "yellowcard.h"

class Yellow10 : public YellowCard
{
    Q_OBJECT

public:
    Yellow10(QObject *parent = nullptr);

    QString getName() const override;
    QString getType() const override;
    int getNumberOnTheCard() const override;
    int getPoints() const override;
    void setPoints(int pointsVal) override;
};

#endif // YELLOW10_HPP