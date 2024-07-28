#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <memory>
#include <vector>
#include "game.hpp"
#include "card.h"

class Playground : public QWidget {
    Q_OBJECT

public:
    explicit Playground(Game& game,std::string province, QWidget *parent = nullptr);
    void setupUI();

private:
    Game& game;
    QGridLayout* playgroundLayout;
    QVBoxLayout* tableLayout;
    QVector<QVBoxLayout*> playerLayouts;

    void displayCards();
    void updateUI();

private slots:
    void handleCardClick(Card* card);
};

#endif // PLAYGROUND_H
