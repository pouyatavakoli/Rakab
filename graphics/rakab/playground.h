#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QMap>
#include <QVector>

#include "game.hpp"

namespace Ui {
class playground;
}

class playground : public QWidget {
    Q_OBJECT

public:
    explicit playground(Game &game, const std::string &province, QWidget *parent = nullptr);
    ~playground();

private slots:
    void handleCardClick(const QString &cardName, int playerIndex, QLabel *cardLabel);
    void onCardPlayed(int playerIndex, const QString &cardName);
    void onCardCannotBePlayed(int playerIndex, const QString &cardName);
    void onUpdateUI();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    Game &game;
    Ui::playground *ui;
    QGridLayout *playgroundLayout;
    QVBoxLayout *tableLayout;
    QVector<QLayout*> playerLayouts;
    QMap<QString, QString> cardImages;
    int currentPlayerIndex;

    void initializeCardImages();
    void setupPlayground(int numPlayers);
    void addCardToTable(const QString &cardName);
    void removeCardFromTable(QLabel *cardLabel);
    void addCardToPlayer(int playerIndex, const QString &cardName);
    void removeCardFromPlayer(int playerIndex, QLabel *cardLabel);
    void setupPlayerCards(const Player &player, int playerIndex);

};

#endif // PLAYGROUND_H
