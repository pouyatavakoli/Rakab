#include "playground.h"
#include "ui_playground.h"
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QDrag>
#include "cardlabel.h"

playground::playground(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::playground),
    game(new Game(4, this))  // Example: 4 players
{
    ui->setupUi(this);
    setAcceptDrops(true);

    connect(game, &Game::turnChanged, this, &playground::handleTurnChanged);

    // Initialize players' hands with some cards for demonstration
    game->players[0].addCard(Card("yellow", 1, 10));
    game->players[1].addCard(Card("purple", 2, 5));
    game->players[2].addCard(Card("yellow", 3, 20));
    game->players[3].addCard(Card("purple", 4, 15));

    // Create UI for players' hands
    for (int i = 0; i < game->players.size(); ++i) {
        QVBoxLayout *playerLayout = new QVBoxLayout;
        for (const Card &card : game->players[i].hand) {
            CardLabel *cardLabel = new CardLabel(this);
            cardLabel->setCard(card.color, card.numberOnTheCard, card.score);
            playerLayout->addWidget(cardLabel);
        }
        ui->playerHandsLayout->addLayout(playerLayout);  // Ensure this matches the name in your .ui file
    }

    // Display the current player's turn
    handleTurnChanged(game->currentPlayerIndex);
}

playground::~playground() {
    delete ui;
}

void playground::handleTurnChanged(int playerIndex) {
    // Update UI to reflect the current player's turn
    ui->label->setText(QString("Player %1's Turn").arg(playerIndex + 1));
}

void playground::handleCardDropped(int playerIndex, const Card& card) {
    // Remove the card from the current player's hand and update UI
    auto& hand = game->players[playerIndex].hand;
    auto it = std::remove_if(hand.begin(), hand.end(), [&](const Card& c) {
        return c.color == card.color && c.numberOnTheCard == card.numberOnTheCard && c.score == card.score;
    });

    if (it != hand.end()) {
        hand.erase(it, hand.end());
        updatePlayerHandUI(playerIndex);
        game->nextTurn();
    }
}

void playground::updatePlayerHandUI(int playerIndex) {
    // Clear existing layout for the player
    QLayout *layout = ui->playerHandsLayout->itemAt(playerIndex)->layout();
    QLayoutItem *item;
    while ((item = layout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    // Re-add cards to the layout
    for (const Card &card : game->players[playerIndex].hand) {
        CardLabel *cardLabel = new CardLabel(this);
        cardLabel->setCard(card.color, card.numberOnTheCard, card.score);
        layout->addWidget(cardLabel);
    }
}

void playground::dragEnterEvent(QDragEnterEvent *event) {
    if (event->mimeData()->hasFormat("application/x-card")) {
        event->acceptProposedAction();
    }
}

void playground::dropEvent(QDropEvent *event) {
    QByteArray itemData = event->mimeData()->data("application/x-card");
    QDataStream dataStream(&itemData, QIODevice::ReadOnly);

    QString color;
    int numberOnTheCard;
    int score;
    dataStream >> color >> numberOnTheCard >> score;

    Card card(color, numberOnTheCard, score);
    handleCardDropped(game->currentPlayerIndex, card);

    event->acceptProposedAction();
}
