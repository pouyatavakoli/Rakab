#ifndef RAKHSHSEFID_H
#define RAKHSHSEFID_H

#include "purplecard.h"

class RakhshSefid : public PurpleCard
{
    Q_OBJECT

public:
    RakhshSefid(QWidget *parent = nullptr);

    // Override virtual functions from PurpleCard
    void startEffect() override;
    void endEffect() override;
    std::string getName() const override;
    std::string getType() const override;
    int getNumberOnTheCard() const override;
    int getPoints() const override;
    void setPoints(int pointsVal) override;
};

#endif // RAKHSHSEFID_H
