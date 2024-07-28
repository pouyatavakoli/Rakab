#ifndef CARDLABEL_H
#define CARDLABEL_H

#include <QLabel>
#include <QMouseEvent>

class CardLabel : public QLabel {
    Q_OBJECT
public:
    explicit CardLabel(QWidget *parent = nullptr);


};

#endif // CARDLABEL_H
