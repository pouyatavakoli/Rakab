#ifndef RISHSEFID_HPP
#define RISHSEFID_HPP

#include "purpleCard.h"

class RishSefid : public PurpleCard
{
    Q_OBJECT

public:
    RishSefid(QObject *parent = nullptr);

    // Override virtual functions from PurpleCard
    QString getName() const override;
    QString getType() const override;
    int getNumberOnTheCard() const override;
    int getPoints() const override;
    void setPoints(int pointsVal) override;
};

#endif // RISHSEFID_HPP
