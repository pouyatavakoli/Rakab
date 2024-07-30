#include "playground.h"


Playground::Playground(Game &game, const std::string province, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::playground),game(game),
    currentPlayerIndex(0)
{
    ui->setupUi(this);
    //mainDeck  = game.getMainDeck();
    game.fillMainDeck();
    qDebug() << "filled deck";
    game.shuffleDeck();
    qDebug() << "shuffed deck" ;
    game.handCardsToPLayers();
    qDebug() << "handed cards to players ";
    playerLayouts.append(ui->player1_hand);
    playerLayouts.append(ui->player2_hand);
    playerLayouts.append(ui->player3_hand);
    playerLayouts.append(ui->player4_hand);
    qDebug() << "added cards to layouts" ;
    displayCards();
    qDebug() << "called dispaly cards" ;
}

/*
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
*/

void Playground::displayCards() {
    // Clear existing cards from layouts
    qDebug() << "display cards start";

    for (auto& layout : playerLayouts) {
        QLayoutItem* item;
        while ((item = layout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
    }
    /*
    QLayoutItem* item;
    while ((item = tableLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }*/
    qDebug() << "deleted previous";
    // Iterate through each player and display yellow and purple cards
    for (int i = 0; i < game.getPlayerCount(); ++i) {
        std::vector<Card*> player_hand; // Collecting player's cards here

        // Get yellow and purple cards and add them to player_hand
        for (const auto& card : game.getPlayerYellowHand(i)) {
            player_hand.push_back(card.get());
        }

        for (const auto& card : game.getPlayerPurpleHand(i)) {
            player_hand.push_back(card.get());
        }
        qDebug() << "getters called";
        // Now display all cards in player_hand
        for (const auto& cardLabel : player_hand) {
            cardLabel->setParent(this);
            playerLayouts[i]->addWidget(cardLabel);

            connect(cardLabel, &Card::clicked, this, [this, cardLabel]() {
                handleCardClick(cardLabel);
            });
        }
        qDebug() << "displayed hand";
        /*
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
        qDebug() << "displayed table";
        */
    }
    qDebug() << "display cards ended";
}


void Playground::handleCardClick(Card* card) {
    int playerIndex = game.getCurrentPlayerIndex();
    std::string cardName = card->getName();
    qDebug() << "clicked on" << QString::fromStdString(cardName);
    // Tell the game to play the card
    game.playPlayerCard(playerIndex, cardName);

    // Update the UI to reflect the new state
    updateUI();
}

void Playground::updateUI() {
    // Refresh the UI to reflect the new state of the game
    displayCards();
}
