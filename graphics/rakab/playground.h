#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <memory>
#include <vector>

#include "ui_playground.h"
#include "game.hpp"
#include "card.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Playground; }
QT_END_NAMESPACE

class Playground : public QWidget {
    Q_OBJECT

public:
    explicit Playground(Game& game, std::string province, QWidget *parent = nullptr);
    void setupUI();

private:
    Ui::playground *ui;
    Game& game;
    QGridLayout* playgroundLayout;
    QVBoxLayout* tableLayout;
    QVector<QLayout*> playerLayouts;
    int currentPlayerIndex;
    //std::vector<std::shared_ptr<Card>> mainDeck;

    void displayCards();
    void updateUI();

private slots:
    void handleCardClick(Card* card);
};

#endif // PLAYGROUND_H
