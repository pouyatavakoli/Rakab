#include "playground.h"

Playground::Playground(Game& game,std::string province, QWidget *parent)
    : QWidget(parent), game(game) {
    setupUI();
}

void Playground::setupUI() {
    playgroundLayout = new QGridLayout(this);
    tableLayout = new QVBoxLayout();
    playerLayouts.resize(4);

    for (int i = 0; i < 4; ++i) {
        playerLayouts[i] = new QVBoxLayout();
        playgroundLayout->addLayout(playerLayouts[i], i / 2, i % 2);
    }

    playgroundLayout->addLayout(tableLayout, 1, 1);
    setLayout(playgroundLayout);
    displayCards();
}

void Playground::displayCards() {
    // Clear existing cards from layouts
    for (auto& layout : playerLayouts) {
        QLayoutItem* item;
        while ((item = layout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
    }
    QLayoutItem* item;
    while ((item = tableLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    // Iterate through each player and display their cards
    for (int i = 0; i < game.getPlayerCount(); ++i) {
        for (const auto& card : game.getPlayerYellowHand(i)) {
            Card* cardLabel = card.get();
            cardLabel->setParent(this);
            playerLayouts[i]->addWidget(cardLabel);

            connect(cardLabel, &Card::clicked, this, [this, cardLabel]() {
                handleCardClick(cardLabel);
            });
        }

        for (const auto& card : game.getPlayerPurpleHand(i)) {
            Card* cardLabel = card.get();
            cardLabel->setParent(this);
            playerLayouts[i]->addWidget(cardLabel);

            connect(cardLabel, &Card::clicked, this, [this, cardLabel]() {
                handleCardClick(cardLabel);
            });
        }

        // Display cards on the table for each player
        for (const auto& card : game.getPlayerYellowOnTable(i)) {
            Card* cardLabel = card.get();
            cardLabel->setParent(this);
            tableLayout->addWidget(cardLabel);
        }

        for (const auto& card : game.getPlayerPurpleOnTable(i)) {
            Card* cardLabel = card.get();
            cardLabel->setParent(this);
            tableLayout->addWidget(cardLabel);
        }
    }
}

void Playground::handleCardClick(Card* card) {
    int playerIndex = game.getCurrentPlayerIndex();
    std::string cardName = card->getName();

    // Tell the game to play the card
    game.playPlayerCard(playerIndex, cardName);

    // Update the UI to reflect the new state
    updateUI();
}

void Playground::updateUI() {
    // Refresh the UI to reflect the new state of the game
    displayCards();
}
