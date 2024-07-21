#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <QWidget>
#include "game.hpp"

namespace Ui {
class playground;
}

class playground : public QWidget {
    Q_OBJECT

public:
    explicit playground(QWidget *parent = nullptr);
    ~playground();

private:
    Ui::playground *ui;
    Game *game;

private slots:
    void handleTurnChanged(int playerIndex);
    void handleCardDropped(int playerIndex, const Card& card);
    void updatePlayerHandUI(int playerIndex);

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
};

#endif // PLAYGROUND_H
