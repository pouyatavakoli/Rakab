#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <QObject>
#include <QWidget>
#include <QString>

class Card {
public:
    QString suit;
    QString rank;
    Card(QString s, QString r) : suit(s), rank(r) {}
};

class Player {
public:
    std::vector<Card> hand;
    void addCard(const Card& card) {
        hand.push_back(card);
    }
    void removeCard(const Card& card) {
        auto it = std::remove_if(hand.begin(), hand.end(), [&card](const Card& c) {
            return c.suit == card.suit && c.rank == card.rank;
        });
        hand.erase(it, hand.end());
    }
};

class Game : public QObject {
    Q_OBJECT
public:
    std::vector<Player> players;
    int currentPlayerIndex;

    Game(int numPlayers, QObject *parent = nullptr) : QObject(parent), currentPlayerIndex(0) {
        for(int i = 0; i < numPlayers; ++i) {
            players.push_back(Player());
        }
    }

    Player& currentPlayer() {
        return players[currentPlayerIndex];
    }

    void nextTurn() {
        currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
        emit turnChanged(currentPlayerIndex);
    }

signals:
    void turnChanged(int playerIndex);
};

#endif // GAME_HPP
