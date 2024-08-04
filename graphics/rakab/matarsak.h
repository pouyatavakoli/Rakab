#ifndef MATARSAK_H
#define MATARSAK_H

#include "purplecard.h"

class Matarsak : public PurpleCard
{
    Q_OBJECT

public:
    Matarsak(QWidget *parent = nullptr);

    void startEffect() override;
    void endEffect() override;
    std::string getName() const override;
    std::string getType() const override;
    int getNumberOnTheCard() const override;
    int getPoints() const override;
    void setPoints(int pointsVal) override;
};

#endif // MATARSAK_H
