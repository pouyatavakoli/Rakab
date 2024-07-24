#ifndef CARDLABEL_H
#define CARDLABEL_H

#include <QLabel>
#include <QWidget>
#include <QMouseEvent>

class CardLabel : public QLabel
{
    Q_OBJECT

public:
    explicit CardLabel(QWidget *parent = nullptr);

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // CARDLABEL_H
