#ifndef SHAHDOKHT_HPP
#define SHAHDOKHT_HPP

#include "purplecard.h"

class ShahDokht : public PurpleCard
{
    Q_OBJECT

public:
    ShahDokht(QObject *parent = nullptr);


    std::string getName() const override;
    std::string getType() const override;
    int getNumberOnTheCard() const override;
    int getPoints() const override;
    void setPoints(int pointsVal) override;
};

#endif // SHAHDOKHT_HPP
