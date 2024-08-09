//todo : back button
#include "mainmenu.h"
#include "mapwindow.h"
#include "getplayersinfowindow.h"
#include <QMessageBox>
#include <QPushButton>
#include <QComboBox>
#include <set>
#include <algorithm>

getPlayersInfoWindow::getPlayersInfoWindow(Game &game ,QWidget *parent)
    :
      QDialog(parent),
      game(game),
      layout(new QVBoxLayout),
      playerCountLabel(new QLabel("Enter the number of players:")),
      playerCountInput(new QLineEdit),
      playerCountSubmitButton(new QPushButton("Submit")),
      submitButton(new QPushButton("Submit")),
      colors({"Red", "Blue", "Green", "Yellow", "Orange", "Purple"})
{
    setWindowTitle("Player Sign-up Wizard");

    layout->addWidget(playerCountLabel);
    layout->addWidget(playerCountInput);
    layout->addWidget(playerCountSubmitButton);
    setLayout(layout);

    connect(playerCountSubmitButton, &QPushButton::clicked, this, &getPlayersInfoWindow::submitPlayerCount);
//    connect(submitButton ,  &QPushButton::clicked, this, &getPlayersInfoWindow::submitInfo );
    };

void getPlayersInfoWindow::submitPlayerCount() {
    bool ok;
    int count = playerCountInput->text().toInt(&ok);
    if (ok && count >= 3 && count <= 4) {
        createPlayerFields(count);
        game.setPlayersCount(count);
    } else {
        QMessageBox::critical(this, "Invalid Input", "Enter a valid number of players (between 3 and 6).");
    }
}

/*void getPlayersInfoWindow::submitInfo(){
    mapwindow* map = new mapwindow(game);
    map ->show();
    this ->close();
}*/

void getPlayersInfoWindow::createPlayerFields(int count) {
    // Clear any existing player fields
    qDeleteAll(playerNameLabels);
    playerNameLabels.clear();
    qDeleteAll(playerNameInputs);
    playerNameInputs.clear();
    qDeleteAll(playerAgeLabels);
    playerAgeLabels.clear();
    qDeleteAll(playerAgeInputs);
    playerAgeInputs.clear();
    qDeleteAll(colorLabels);
    colorLabels.clear();
    qDeleteAll(colorCombos);
    colorCombos.clear();

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

        QLabel *colorLabel = new QLabel("Choose color for Player " + QString::number(i + 1) + ":");
        QComboBox *colorCombo = new QComboBox;
        colorCombo->addItems(colors);
        layout->addWidget(colorLabel);
        layout->addWidget(colorCombo);
        colorLabels.append(colorLabel);
        colorCombos.append(colorCombo);
    }

    // Remove the previous widgets and add the new ones
    layout->removeWidget(playerCountLabel);
    layout->removeWidget(playerCountInput);
    layout->removeWidget(playerCountSubmitButton);
    playerCountLabel->deleteLater();
    playerCountInput->deleteLater();
    playerCountSubmitButton->deleteLater();

    // Connect the submit button to a slot that will collect the inputs and update the game class
    connect(submitButton, &QPushButton::clicked, this, &getPlayersInfoWindow::submitPlayerInfo);

    layout->addWidget(submitButton);
}

void getPlayersInfoWindow::submitPlayerInfo() {
    if (validatePlayerInfo()) {
        std::vector<std::string> playerNames;
        std::vector<int> playerAges;
        std::vector<std::string> playerColors;

        // Collect names, ages, and colors from the input fields
        for (int i = 0; i < playerNameInputs.size(); ++i) {
            std::string name = playerNameInputs[i]->text().toStdString(); // Convert QString to std::string
            int age = playerAgeInputs[i]->text().toInt(); // Convert age input to integer
            std::string color = colorCombos[i]->currentText().toStdString(); // Convert color to std::string

            playerNames.push_back(name);
            playerAges.push_back(age);
            playerColors.push_back(color);
        }

        // Set the collected names, ages, and colors in the game class
        game.setPlayers(playerNames, playerAges, playerColors);

        // Open the map window and close the current window
        mapwindow *map = new mapwindow(game);
        map->show();
        this->close();
    }
}

bool getPlayersInfoWindow::validatePlayerInfo() {
    std::set<std::string> uniqueColors;
    for (int i = 0; i < colorCombos.size(); ++i) {
        // Check for valid age
        bool ageOk;
        int age = playerAgeInputs[i]->text().toInt(&ageOk);
        if (!ageOk || age <= 0) {
            QMessageBox::critical(this, "Invalid Age", "Age must be a positive number for Player " + QString::number(i + 1) + ".");
            return false;
        }

        // Check for unique colors
        std::string color = colorCombos[i]->currentText().toStdString();
        if (uniqueColors.find(color) != uniqueColors.end()) {
            QMessageBox::critical(this, "Duplicate Color", "Color " + QString::fromStdString(color) + " is already chosen. Please select a different color.");
            return false;
        }
        uniqueColors.insert(color);
    }
    return true;
}



