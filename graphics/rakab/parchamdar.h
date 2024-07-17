#ifndef PARCHAMDAR_HPP
#define PARCHAMDAR_HPP

#include "purplecard.h"

class ParchamDar : public PurpleCard
{
    Q_OBJECT

public:
    ParchamDar(QObject *parent = nullptr);

    // Override virtual functions from PurpleCard
    QString getName() const override;
    QString getType() const override;
    int getNumberOnTheCard() const override;
    int getPoints() const override;
    void setPoints(int pointsVal) override;

    void startEffect() override;
    void endEffect() override;
};

#endif // PARCHAMDAR_HPP
