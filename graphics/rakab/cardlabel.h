#ifndef CARDLABEL_H
#define CARDLABEL_H

#include <QLabel>

class CardLabel : public QLabel {
    Q_OBJECT
public:
    explicit CardLabel(QWidget *parent = nullptr);

signals:
    void clicked();  // Signal for card click

protected:
    void mouseReleaseEvent(QMouseEvent *event) override;
};

#endif // CARDLABEL_H
