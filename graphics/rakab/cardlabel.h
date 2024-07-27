#ifndef CARDLABEL_H
#define CARDLABEL_H

#include <QLabel>
#include <QMouseEvent>

class CardLabel : public QLabel {
    Q_OBJECT
public:
    explicit CardLabel(QWidget *parent = nullptr) : QLabel(parent) {
        setAttribute(Qt::WA_Hover);  // Enable hover events
    }

signals:
    void clicked();  // Signal for card click

protected:
    void mouseReleaseEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) {
            emit clicked();  // Emit clicked signal on mouse release
        }
        QLabel::mouseReleaseEvent(event);  // Call base class handler
    }
};

#endif // CARDLABEL_H
