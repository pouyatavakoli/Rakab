#ifndef CARDLABEL_H
#define CARDLABEL_H

#include <QLabel>
#include <QDrag>
#include <QMimeData>

class CardLabel : public QLabel {
    Q_OBJECT

public:
    explicit CardLabel(QWidget *parent = nullptr);
    void setCard(const QString &color, int numberOnTheCard, int score);
    QString getColor() const { return color; }
    int getNumberOnTheCard() const { return numberOnTheCard; }
    int getScore() const { return score; }

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    QString color;
    int numberOnTheCard;
    int score;

    QString getCardImagePath() const;
};

#endif // CARDLABEL_H
