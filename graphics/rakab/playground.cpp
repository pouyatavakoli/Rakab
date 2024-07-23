#include "playground.h"
#include "ui_playground.h"
#include <QPixmap>
#include <QDebug>

playground::playground(Game &game, const std::string province, QWidget *parent) :
    QWidget(parent),
    game(game),  // Ensure this matches the constructor declaration
    ui(new Ui::playground)
{
    ui->setupUi(this);

    // Create the main layout as a grid
    playgroundLayout = new QGridLayout(this);

    // Initialize card images
    initializeCardImages();
    game.fillMainDeck();
    game.shuffleDeck();
    game.handCardsToPLayers();

    // Setup the playground with the players around the table
    setupPlayground(game.getPlayerCount());

    // Setup cards for each player
    for (int i = 0; i < game.getPlayerCount(); ++i) {
        setupPlayerCards(game.getPlayer(i), i);
    }

    // Set the size policy and fixed size for the playground widget
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setFixedSize(800, 600); // Adjust the size as needed
}

playground::~playground()
{
    delete ui;
}

void playground::initializeCardImages() {
    cardImages["RishSefid"] = ":/new/cards/banafsh/assets/cards/banafsh/Rish_Sefid.png";
    cardImages["ShahDokht"] = ":/new/cards/banafsh/assets/cards/banafsh/Shah_Dokht.png";
    cardImages["ShirZan"] = ":/new/cards/banafsh/assets/cards/banafsh/Shir_Zan.png";
    cardImages["Winter"] = ":/new/cards/banafsh/assets/cards/banafsh/Zemestan.png";
    cardImages["Spring"] = ":/new/cards/banafsh/assets/cards/banafsh/Bahar.png";
    cardImages["Matarsak"] = ":/new/cards/banafsh/assets/cards/banafsh/Matarsak.png";
    cardImages["ParchamDar"] = ":/new/cards/banafsh/assets/cards/banafsh/Parcham_Dar.png";
    cardImages["TablZan"] = ":/new/cards/banafsh/assets/cards/banafsh/Tabl_Zan.png";

    cardImages["Yellow1"] = ":/new/cards/zard/assets/cards/zard/001.png";
    cardImages["Yellow2"] = ":/new/cards/zard/assets/cards/zard/002.png";
    cardImages["Yellow3"] = ":/new/cards/zard/assets/cards/zard/003.png";
    cardImages["Yellow4"] = ":/new/cards/zard/assets/cards/zard/004.png";
    cardImages["Yellow5"] = ":/new/cards/zard/assets/cards/zard/005.png";
    cardImages["Yellow6"] = ":/new/cards/zard/assets/cards/zard/006.png";
    cardImages["Yellow10"] = ":/new/cards/zard/assets/cards/zard/010.png";
}

void playground::setupPlayground(int numPlayers) {
    // Ensure number of players is between 3 and 6
    numPlayers = qMax(3, qMin(6, numPlayers));

    // Create the central table layout
    tableLayout = new QVBoxLayout();
    QWidget *tableWidget = new QWidget();
    tableWidget->setLayout(tableLayout);
    playgroundLayout->addWidget(tableWidget, 1, 1); // Center of the grid

    // Create player layouts and position them around the table
    for (int i = 0; i < numPlayers; ++i) {
        QHBoxLayout *playerLayout = new QHBoxLayout();
        playerLayouts.append(playerLayout);

        QWidget *playerWidget = new QWidget();
        playerWidget->setLayout(playerLayout);

        switch (i) {
            case 0:
                playgroundLayout->addWidget(playerWidget, 0, 1); // Top
                break;
            case 1:
                playgroundLayout->addWidget(playerWidget, 1, 2); // Right
                break;
            case 2:
                playgroundLayout->addWidget(playerWidget, 2, 1); // Bottom
                break;
            case 3:
                playgroundLayout->addWidget(playerWidget, 1, 0); // Left
                break;
            case 4:
                playgroundLayout->addWidget(playerWidget, 0, 0); // Top-left
                break;
            case 5:
                playgroundLayout->addWidget(playerWidget, 0, 2); // Top-right
                break;
            default:
                break;
        }
    }
}

void playground::addCardToTable(const QString &cardName) {
    QString cardPath = cardImages[cardName];
    QLabel *cardLabel = new QLabel();
    QPixmap pixmap(cardPath);
    pixmap = pixmap.scaled(100, 150, Qt::KeepAspectRatio); // Set a fixed size for cards
    cardLabel->setPixmap(pixmap);
    tableLayout->addWidget(cardLabel);
}

void playground::removeCardFromTable(QLabel *cardLabel) {
    tableLayout->removeWidget(cardLabel);
    delete cardLabel;
}

void playground::addCardToPlayer(int playerIndex, const QString &cardName) {
    if (playerIndex < 0 || playerIndex >= playerLayouts.size()) return;

    QString cardPath = cardImages[cardName];
    QLabel *cardLabel = new QLabel();
    QPixmap pixmap(cardPath);
    pixmap = pixmap.scaled(100, 150, Qt::KeepAspectRatio); // Set a fixed size for cards
    cardLabel->setPixmap(pixmap);
    playerLayouts[playerIndex]->addWidget(cardLabel);
}

void playground::setupPlayerCards(const Player &player, int playerIndex) {
    // Setup yellow cards in hand
    for (const auto &card : player.getYellowHand()) {
        addCardToPlayer(playerIndex, QString::fromStdString(card->getName()));
    }

    // Setup yellow cards on table
    for (const auto &card : player.getYellowOnTable()) {
        addCardToPlayer(playerIndex, QString::fromStdString(card->getName()));
    }

    // Setup purple cards in hand
    for (const auto &card : player.getPurpleHand()) {
        addCardToPlayer(playerIndex, QString::fromStdString(card->getName()));
    }

    // Setup purple cards on table
    for (const auto &card : player.getPurpleOnTable()) {
        addCardToPlayer(playerIndex, QString::fromStdString(card->getName()));
    }
}
