#include "playground.h"
#include <QMessageBox>
#include <QDialog>


Playground::Playground(Game &game, const std::string provinceName, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::playground),game(game),province(provinceName)
{
    ui->setupUi(this);

    qDebug() << QString::fromStdString(game.getBattleCompleted());
    if(game.getBattleCompleted() == "Yes")
    {
        game.setBattleCompleted("No");
        game.gameFlusher();
        game.fillMainDeck();
        game.shuffleDeck();
        game.handCardsToPLayers();
    }
    else
    {
        //The saved game will continue
    }

    playerLayouts.append(ui->player1_hand);
    playerLayouts.append(ui->player2_hand);
    playerLayouts.append(ui->player3_hand);
    playerLayouts.append(ui->player4_hand);
    qDebug() << "added card layouts" ;

    tablelayouts.append((ui->player1_table));
    tablelayouts.append((ui->player2_table));
    tablelayouts.append((ui->player3_table));
    tablelayouts.append((ui->player4_table));
    qDebug() << "added table layouts";

    displayCards();
    qDebug() << "called dispaly cards" ;
}

Playground::~Playground()
{   
    qDebug() << "playgroundClosed" ;
    emit playgroundClosed();
}

void Playground::closeEvent(QCloseEvent *event) {
    // Emit signal when the dialog is closed
    game.setBattleCompleted("Yes");
    emit playgroundClosed();
    QDialog::closeEvent(event); // Call the base class implementation to ensure proper dialog closure
}

/*
void Playground::setupUI() {
    playgroundLayout = new QGridLayout(this);
    tableLayout = new QVBoxLayout();
    playerLayouts.resize(4);

    for (int i = 0; i < 4; ++i) {
        playerLayouts[i] = new QVBoxLayout();
        playgroundLayout->addLayout(playerLayouts[i], i / 2, i % 2);
    }

    playgroundLayout->addLayout(tableLayout, 1, 1);
    setLayout(playgroundLayout);
    displayCards();
}
*/
void Playground::clearScreen() {
    qDebug() << "clearing screen";
    /*
    // Clear player layouts
    for (auto& layout : playerLayouts) {
        clearLayout(layout);
    }
    */
    qDebug() << "deleted previous hands";
    /*
    // Clear table layouts
    for (auto& layout : tablelayouts) {
        clearLayout(layout);
    }
    */
    qDebug() << "deleted previous tables";
}

void Playground::clearLayout(QLayout* layout) {
    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
}

void Playground::displayCards() {
    qDebug() << "display cards start";

    // Iterate through each player and display yellow and purple cards from hand
    for (int i = 0; i < game.getPlayerCount(); ++i) {
        std::vector<Card*> player_hand; // Collecting player's cards here

        // Get yellow and purple cards and add them to player_hand
        for (const auto& card : game.getPlayerYellowHand(i)) {
            player_hand.push_back(card.get());
        }

        for (const auto& card : game.getPlayerPurpleHand(i)) {
            player_hand.push_back(card.get());
        }
        // setting cards face and back
        if( i == game.getPlayerIndex()){
            for(auto card : player_hand){
                card->setImage(card->getFaceURL());
            }
        }
        else {
            for (auto card : player_hand){
                card->setImage(card->getBackURL());
            }
        }
        qDebug() << "getters called";

        // Now display all cards in player_hand
        for (const auto& cardLabel : player_hand) {
            cardLabel->setParent(this);
            playerLayouts[i]->addWidget(cardLabel);

            disconnect(cardLabel, &Card::clicked, nullptr, nullptr);
            connect(cardLabel, &Card::clicked, this, [this, cardLabel]() {
                handleCardClick(cardLabel);
            });
        }

        qDebug() << "displayed hand";
    }

    qDebug() << "1111now is turn of player" << game.getPlayerIndex();

    // Now display cards on the table for each player (moved out of player loop)
    for (int i = 0; i < game.getPlayerCount(); ++i) {
        std::vector<Card*> player_table;

        // Get yellow and purple cards and add them to player_table
        for (const auto& card : game.getPlayerYellowOnTable(i)) {
            player_table.push_back(card.get());
        }

        for (const auto& card : game.getPlayerPurpleOnTable(i)) {
            player_table.push_back(card.get());
        }

        // Display all cards on the table for this player
        for (const auto& cardLabel : player_table) {
            cardLabel->setParent(this);
            tablelayouts[i]->addWidget(cardLabel); // Assuming you have a layout for the table
        }
        qDebug() << "displayed table for player" << i + 1;
        qDebug() << "222now is turn of player" << game.getPlayerIndex();
    }

    qDebug() << "display cards ended";
}


void Playground::updateUi()
{
    //    clearScreen();
    displayCards();
    // todo : update scores
}


void Playground::handleCardClick(Card* card) {
    int playerIndex = game.getPlayerIndex();
    qDebug() << "is turn of in handleCardClick :" << playerIndex;
    std::string cardName = card->getName();
    qDebug() << "clicked on" << QString::fromStdString(cardName);
    // Tell the game to play the card

    if (matarsakEffectActive) {
            handleMatarsakEffect(card);
            return;
        }

    if(playerIndex == card->getindexOfOwner())
    {
        int situation = game.playPlayerCard(playerIndex, cardName);
        if (situation == -1) {
            // Move to the next player's turn   TODO:it should be pass

        }
        else if (situation == 0) { // was not found so we are not going next player.

            QString message = QString::fromStdString(cardName) + " was not found. Please pick a card or pass.";
            QMessageBox::warning(this, "Invalid Move", message);
        }
        else if (situation == 1){ // Successfully played a card
            if (cardName == "Matarsak") {
                matarsakEffectActive = true;
                QMessageBox::information(this, "Matarsak", "Select a card from the table to return to your hand.");
            }


        }
        else if (situation == 2){ // It is a season

        }
        else if (situation == 4) //Can not be Played.
        {
            QString message = QString::fromStdString(cardName) + " cannot be played. Please pick a card or pass.";
            QMessageBox::warning(this, "Invalid Move", message);
        }
        else if (situation == 5) // It is RishSefid
        {

        }
        else if (situation == 6) // It is ParchamDar
        {

        }
        game.updateTotalScore();
        updateUi();
        if(situation == 11)
        {
            int winstat = game.checkThisBattleWinner(province);
            if(winstat == 0)
            {
                QString message = " The game has no winner, it's a tie.";
                QMessageBox::information(this, "Status", message);
            }
            else if(winstat == 1)
            {
                QString message = " We have a winner.";
                game.setBattleCompleted("Yes");
                QMessageBox::information(nullptr, "Winner", message);
            }
            else if (winstat == 2)
            {
                QString message = "No winner could be determined.";
                QMessageBox::information(nullptr, "Status", message);

            }
            close();

        }
    }

    // Update the UI to reflect the new state

}





void Playground::handleMatarsakEffect(Card* card) {
    std::string cardName = card->getName();
    qDebug() << "Matarsak effect active, clicked on" << QString::fromStdString(cardName);

    int result = game.handleMatarsakEffect(game.getPlayerIndex(), cardName);

    if (result == 1) { // Success
        qDebug() << QString::fromStdString(cardName) << " has been picked up from the table and returned to the hand!";
        matarsakEffectActive = false;
    }
    else { // Card not found on the table
        QMessageBox::warning(this, "Invalid Move", QString::fromStdString(cardName) + " not found on the table. Please try again.");
    }

    updateUi();
}


void Playground::on_pushButton_clicked()
{
    game.setLastPlayerWhoPassed(game.getPlayerIndex());
    game.updatePlayersEligibility(game.getPlayerIndex());
    game.updateAnyPlayerCanPlay();
    if(game.getAnyPlayerCanPlay() == true)
    {
        game.nextTurn();
        updateUi();
    }
    else
    {
        game.updateTotalScore();
        int winstat = game.checkThisBattleWinner(province);
        if(winstat == 0)
        {

            QString message = " The game has no winner, it's a tie.";
            QMessageBox::information(this, "Status", message);
        }
        else if(winstat == 1)
        {

            QString message = " We have a winner.";
            QMessageBox::information(nullptr, "Winner", message);
        }
        else if (winstat == 2)
        {
            QString message = "No winner could be determined.";
            QMessageBox::information(nullptr, "Status", message);

        }
        close();
    }
}


void Playground::on_save_pb_clicked()
{
    game.setBattleCompleted("No");
    SelectSaveLoacation* ssl = new SelectSaveLoacation(game , this);
    ssl->show();
}

