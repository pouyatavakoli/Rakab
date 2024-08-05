#ifndef CARD_H
#define CARD_H

#include <QLabel>
#include <QMouseEvent>
#include <QString>
#include <string>
#include <sstream>

class Card : public QLabel
{
    Q_OBJECT

public:
    explicit Card(int numberOnTheCardVal, const std::string &typeVal, const std::string &nameVal, QWidget *parent = nullptr);

    virtual std::string getName() const = 0;
    virtual std::string getType() const = 0;
    virtual int getNumberOnTheCard() const = 0;
    virtual int getPoints() const = 0;
    virtual void setPoints(int pointsVal) = 0;
    virtual void setindexOfOwner(int) ;
    virtual int getindexOfOwner() const;
    virtual void setImage(const QString &);

    void mouseReleaseEvent(QMouseEvent *event) override;

    QString getFaceURL();
    QString getBackURL();

    std::string toString() const;

protected:
    std::string name;
    std::string type;
    int numberOnTheCard;
    int points;
    int indexOfOwner;

    QString faceURL = "" ;
    QString backURL= ":/new/background/assets/cards/Back.png";

signals:
    void clicked();  // Signal for card click

private:

};

#endif // CARD_H
