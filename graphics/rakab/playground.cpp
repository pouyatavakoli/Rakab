#include "playground.h"
#include "ui_playground.h"
#include "card.h"
#include <QPixmap>
#include <QDebug>
#include <QEvent>
#include <QMouseEvent>

playground::playground(Game &game, const std::string &province, QWidget *parent) :
    QWidget(parent),
    game(game),
    ui(new Ui::playground),
    currentPlayerIndex(0) // Corrected to 0 for indexing
{
    ui->setupUi(this);
    ui->province_label->setText(QString::fromStdString(province));
    playgroundLayout = new QGridLayout(this);
    initializeCardImages();
    game.fillMainDeck();
    game.shuffleDeck();
    game.handCardsToPLayers();
    auto mainDeck = game.getMainDeck();
    setupPlayground(game.getPlayerCount());

    for (int i = 0; i < game.getPlayerCount(); ++i) {
        setupPlayerCards(game.getPlayer(i), i);
    }

    connect(&game, &Game::cardPlayed, this, &playground::onCardPlayed);
    connect(&game, &Game::cardCannotBePlayed, this, &playground::onCardCannotBePlayed);
    connect(&game, &Game::updateUI, this, &playground::onUpdateUI);

    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    // Install event filter
    for (QObject *child : findChildren<QObject*>()) {
            child->installEventFilter(this);
        }
}

playground::~playground() {
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
    numPlayers = qMax(3, qMin(4, numPlayers));

    tableLayout = new QVBoxLayout();
    QWidget *tableWidget = new QWidget();
    tableWidget->setLayout(tableLayout);
    playgroundLayout->addWidget(tableWidget, 1, 1);

    playerLayouts.append(ui->player1_hand);
    playerLayouts.append(ui->player2_hand);
    playerLayouts.append(ui->player3_hand);
    playerLayouts.append(ui->player4_hand);

    if (numPlayers == 3){
        ui->player4_label->setText("empty");
    }
}

void playground::setupPlayerCards(const Player &player, int playerIndex) {
    for (const auto &card : player.getYellowHand()) {
        addCardToPlayer(playerIndex, QString::fromStdString(card->getName()));
    }

    for (const auto &card : player.getPurpleHand()) {
        addCardToPlayer(playerIndex, QString::fromStdString(card->getName()));
    }
}

void playground::handleCardClick(const QString &cardName, int playerIndex , Card *cardLabel ) {
    qDebug() << "Card clicked:" << cardName << "by player" << playerIndex;
    if (cardName.isEmpty()) {
        qDebug() << "Card name is empty!";
        return;
    }

    if (playerIndex < 0 || playerIndex >= playerLayouts.size()) {
        qDebug() << "Invalid player index!";
        return;
    }

    if (game.playCard(playerIndex, cardName.toStdString())) {
        qDebug() << "Card successfully played:" << cardName;
        removeCardFromPlayer(playerIndex, cardLabel);
        addCardToTable(cardName);
    } else {
        qDebug() << "Failed to play card:" << cardName;
    }
}

void playground::onCardPlayed(int playerIndex, const QString &cardName) {
    qDebug() << "Card played by player" << playerIndex << ":" << cardName;
    // Handle UI update for card played
}

void playground::onCardCannotBePlayed(int playerIndex, const QString &cardName) {
    qDebug() << "Card cannot be played by player" << playerIndex << ":" << cardName;
    // Handle UI update for card cannot be played
}

void playground::onUpdateUI() {
    // Update the UI based on the game state
}

// dont make new cards handle all cards in these with pointers and use the main deck
void playground::addCardToTable(const QString &cardName) {
    Card *cardLabel = new Card();
    cardLabel->setText(cardName);  // For example, set card name as text
    cardLabel->setPixmap(QPixmap(cardImages[cardName]));  // Use your card image map

    connect(cardLabel, &CardLabel::clicked, [this, cardName]() {
        handleCardClick(cardName, currentPlayerIndex , cardLabel );  // Handle card click
    });

    // Add cardLabel to layout and update UI...
    playgroundLayout->addWidget(cardLabel);
}

void playground::removeCardFromTable(Card *cardLabel) {
    tableLayout->removeWidget(cardLabel);
    cardLabel->deleteLater();
}

void playground::addCardToPlayer(int playerIndex, const QString &cardName) {
    if (playerIndex < 0 || playerIndex >= playerLayouts.size()) return;

    QString cardPath = cardImages[cardName];
    QLabel *cardLabel = new QLabel(this);

    QPixmap pixmap(cardPath);
    pixmap = pixmap.scaled(50, 75, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    cardLabel->setPixmap(pixmap);

    cardLabel->setObjectName(cardName); // Use cardName for identification
    cardLabel->setProperty("playerIndex", playerIndex); // Store playerIndex as property

    // Install event filter directly on the QLabel
    cardLabel->installEventFilter(this);
    qDebug() << "installEventFilter on player" ;

    playerLayouts[playerIndex]->addWidget(cardLabel);
    cardLabel->show(); // Ensure the label is shown
}


void playground::removeCardFromPlayer(int playerIndex, Card *cardLabel) {
    playerLayouts[playerIndex]->removeWidget(cardLabel);
    cardLabel->deleteLater();
}

bool playground::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::MouseButtonPress) {
        QLabel *label = qobject_cast<QLabel *>(obj);
        if (label) {
            QString cardName = label->property("cardName").toString();
            qDebug() << "Card clicked:" << cardName; // Log the card name
        }
        else {
            qDebug() << "can not click but i know you clicked";
        }

    }
    return QObject::eventFilter(obj, event); // Pass the event on to the parent class
}
