//todo : back button
#include "mainmenu.h"
#include "mapwindow.h"
#include "getplayersinfowindow.h"
#include <QMessageBox>

getPlayersInfoWindow::getPlayersInfoWindow(QWidget *parent)
    : QDialog(parent),
      layout(new QVBoxLayout),
      playerCountLabel(new QLabel("Enter the number of players:")),
      playerCountInput(new QLineEdit),
      playerCountSubmitButton(new QPushButton("Submit")),
      submitButton(new QPushButton("Submit"))
{
    setWindowTitle("Player Sign-up Wizard");

    layout->addWidget(playerCountLabel);
    layout->addWidget(playerCountInput);
    layout->addWidget(playerCountSubmitButton);
    setLayout(layout);

    connect(playerCountSubmitButton, &QPushButton::clicked, this, &getPlayersInfoWindow::submitPlayerCount);
    connect(submitButton ,  &QPushButton::clicked, this, &getPlayersInfoWindow::submitInfo );
    };

void getPlayersInfoWindow::submitPlayerCount() {
    bool ok;
    int count = playerCountInput->text().toInt(&ok);
    if (ok && count >= 3 && count <= 6) {
        createPlayerFields(count);
    } else {
        QMessageBox::critical(this, "Invalid Input", "Enter a valid number of players (between 3 and 6).");
    }
}

void getPlayersInfoWindow::submitInfo(){
    mapwindow* map = new mapwindow();
    map ->show();
    this ->close();
}
void getPlayersInfoWindow::createPlayerFields(int count) {
    for (int i = 0; i < count; ++i) {
        QLabel *nameLabel = new QLabel("Enter name for Player " + QString::number(i + 1) + ":");
        QLineEdit *nameInput = new QLineEdit;
        layout->addWidget(nameLabel);
        layout->addWidget(nameInput);
        playerNameLabels.append(nameLabel);
        playerNameInputs.append(nameInput);

        QLabel *ageLabel = new QLabel("Enter age for Player " + QString::number(i + 1) + ":");
        QLineEdit *ageInput = new QLineEdit;
        layout->addWidget(ageLabel);
        layout->addWidget(ageInput);
        playerAgeLabels.append(ageLabel);
        playerAgeInputs.append(ageInput);
    }

    // Remove the previous widgets and add the new ones
    layout->removeWidget(playerCountLabel);
    layout->removeWidget(playerCountInput);
    layout->removeWidget(playerCountSubmitButton);
    playerCountLabel->deleteLater();
    playerCountInput->deleteLater();
    playerCountSubmitButton->deleteLater();

    layout->addWidget(submitButton);
}

