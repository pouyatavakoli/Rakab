#ifndef GETINFO_H
#define GETINFO_H

#include "game.hpp"

#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>


class getPlayersInfoWindow : public QDialog {
    Q_OBJECT

public:
    getPlayersInfoWindow(Game&,QWidget *parent = nullptr);

private slots:
    void submitPlayerCount();
//    void submitInfo();

private:
    Game &game;
    QVBoxLayout *layout;
    QLabel *playerCountLabel;
    QLineEdit *playerCountInput;
    QPushButton *playerCountSubmitButton;

    QVector<QLabel*> playerNameLabels;
    QVector<QLineEdit*> playerNameInputs;
    QVector<QLabel*> playerAgeLabels;
    QVector<QLineEdit*> playerAgeInputs;
    QList<QLabel *> colorLabels;
    QList<QComboBox *> colorCombos;
    QPushButton *submitButton;

    QStringList colors;

    void createPlayerFields(int count);
    void submitPlayerInfo();
    bool validatePlayerInfo();
};

#endif
