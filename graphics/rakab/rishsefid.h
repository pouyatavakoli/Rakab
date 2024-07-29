#ifndef RISHSEFID_HPP
#define RISHSEFID_HPP

#include "purplecard.h"

class RishSefid : public PurpleCard
{
    Q_OBJECT

public:
    RishSefid(QWidget *parent = nullptr);

    // Override virtual functions from PurpleCard
    std::string getName() const override;
    std::string getType() const override;
    int getNumberOnTheCard() const override;
    int getPoints() const override;
    void setPoints(int pointsVal) override;
};

#endif // RISHSEFID_HPP
