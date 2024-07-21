// this is temp game class to make sure playground works properly
#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <QObject>
#include <QWidget>

class Card {
public:
    QString color; // "yellow" or "purple"
    int numberOnTheCard;
    int score;
    Card(QString c, int n, int s) : color(c), numberOnTheCard(n), score(s) {}
};

class Player {
public:
    std::vector<Card> hand;
    void addCard(const Card& card) {
        hand.push_back(card);
    }
    void removeCard(const Card& card) {
        auto it = std::remove_if(hand.begin(), hand.end(), [&card](const Card& c) {
            return c.color == card.color && c.numberOnTheCard == card.numberOnTheCard && c.score == card.score;
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
