#ifndef TABLZAN_H
#define TABLZAN_H

#include "purplecard.h"

class TablZan : public PurpleCard
{
    Q_OBJECT

public:
    TablZan(QWidget *parent = nullptr);

    // Override virtual functions from PurpleCard
    void startEffect(Player &) override;
    void endEffect(Player &) override;
    std::string getName() const override;
    std::string getType() const override;
    int getNumberOnTheCard() const override;
    int getPoints() const override;
    void setPoints(int pointsVal) override;
};

#endif // TABLZAN_H
