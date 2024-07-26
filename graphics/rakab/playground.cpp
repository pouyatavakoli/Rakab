#include "playground.h"
#include "ui_playground.h"
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

    playgroundLayout = new QGridLayout(this);
    initializeCardImages();
    game.fillMainDeck();
    game.shuffleDeck();
    game.handCardsToPLayers();
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
}

void playground::setupPlayerCards(const Player &player, int playerIndex) {
    for (const auto &card : player.getYellowHand()) {
        addCardToPlayer(playerIndex, QString::fromStdString(card->getName()));
    }

    for (const auto &card : player.getPurpleHand()) {
        addCardToPlayer(playerIndex, QString::fromStdString(card->getName()));
    }
}

void playground::handleCardClick(const QString &cardName, int playerIndex, QLabel *cardLabel) {
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

void playground::addCardToTable(const QString &cardName) {
    QString cardPath = cardImages[cardName];
    QLabel *cardLabel = new QLabel(this); // Use QLabel directly
    QPixmap pixmap(cardPath);
    pixmap = pixmap.scaled(100, 150, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    cardLabel->setPixmap(pixmap);
    cardLabel->setFixedSize(pixmap.size());
    tableLayout->addWidget(cardLabel);
}

void playground::removeCardFromTable(QLabel *cardLabel) {
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
    qDebug() << "installEventFilter";

    playerLayouts[playerIndex]->addWidget(cardLabel);
    cardLabel->show(); // Ensure the label is shown
}


void playground::removeCardFromPlayer(int playerIndex, QLabel *cardLabel) {
    playerLayouts[playerIndex]->removeWidget(cardLabel);
    cardLabel->deleteLater();
}

bool playground::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::MouseButtonRelease) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent->button() == Qt::LeftButton) {
            qDebug() << "Object type:" << obj->metaObject()->className(); // Log the type of the object
            QLabel *label = qobject_cast<QLabel*>(obj);
            if (label) {
                QString cardName = label->objectName();
                int playerIndex = label->property("playerIndex").toInt();
                qDebug() << "Event filter detected click on card:" << cardName << "from player" << playerIndex;
                handleCardClick(cardName, playerIndex, label);
                return true; // Event handled
            } else {
                qDebug() << "Not a QLabel!";
            }
        }
    }
    return QWidget::eventFilter(obj, event); // Pass the event to the base class
}
