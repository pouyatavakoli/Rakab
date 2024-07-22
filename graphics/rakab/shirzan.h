#ifndef SHIRZAN_H
#define SHIRZAN_H

#include "purplecard.h"

class ShirZan : public PurpleCard
{
    Q_OBJECT

public:
    ShirZan(QObject *parent = nullptr);

    // Override virtual functions from PurpleCard
    void startEffect() override;
    void endEffect() override;
    std::string getName() const override;
    std::string getType() const override;
    int getNumberOnTheCard() const override;
    int getPoints() const override;
    void setPoints(int pointsVal) override;
};

#endif // SHIRZAN_H
