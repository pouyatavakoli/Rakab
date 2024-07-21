#include "playground.h"
#include "ui_playground.h"
#include <QDragEnterEvent>
#include <QMimeData>
#include <QDrag>
#include <QLabel>
#include <QVBoxLayout>
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
        ui->playerHandsLayout->addLayout(playerLayout);
    }
}

playground::~playground() {
    delete ui;
}

void playground::handleTurnChanged(int playerIndex) {
    // Update UI to reflect the current player's turn
    ui->label->setText(QString("Player %1's Turn").arg(playerIndex + 1));
}

void playground::handleCardDropped(int playerIndex, const Card& card) {
    // Handle card drop logic
    if (playerIndex == game->currentPlayerIndex) {
        game->currentPlayer().removeCard(card);
        game->nextTurn();
    } else {
        // Optionally show a message that it's not this player's turn
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
