#include "selectsaveloacation.h"
#include "ui_selectsaveloacation.h"

SelectSaveLoacation::SelectSaveLoacation(Game& game , QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectSaveLoacation), game(game)
{
    ui->setupUi(this);
    updateLabels();
    save = new Save;

    // Make sure the window is not transparent
    //setAttribute(Qt::WA_NoSystemBackground, true);
    //setAttribute(Qt::WA_OpaquePaintEvent, true);

    // position the window
    if (parent) {
        int parentWidth = parent->width();
        int parentHeight = parent->height();
        int x = parent->x() + (parentWidth - width()) / 2;
        int y = parent->y() + (parentHeight - height()) / 3;
        move(x, y);
    }
}

SelectSaveLoacation::~SelectSaveLoacation()
{
    delete ui;
}

void SelectSaveLoacation::on_pushButton_2_clicked()
{
    this->close();
}


void SelectSaveLoacation::on_save1_pb_clicked()
{
    if(save->containsEmptyWord("saved_games_1.txt")){
        game.saveThisGame("saved_games_1.txt");
        this->close();
    }
    else {
        QMessageBox::critical(this, "file not empty","file is not empty \n click clear or select another location");
    }

    updateLabels();
}


void SelectSaveLoacation::on_save2_pb_clicked()
{
    if(save->containsEmptyWord("saved_games_2.txt")){
        game.saveThisGame("saved_games_2.txt");
        this->close();
    }
    else {
        QMessageBox::critical(this, "file not empty","file is not empty \n click clear or select another location");
    }

    updateLabels();
}


void SelectSaveLoacation::on_save3_pb_clicked()
{
    if(save->containsEmptyWord("saved_games_3.txt")){
        game.saveThisGame("saved_games_3.txt");
        this->close();
    }
    else {
        QMessageBox::critical(this, "file not empty","file is not empty \n click clear or select another location");
    }

    updateLabels();
}


void SelectSaveLoacation::on_save4_pb_clicked()
{
    if(save->containsEmptyWord("saved_games_4.txt")){
        game.saveThisGame("saved_games_4.txt");
        this->close();
    }
    else {
        QMessageBox::critical(this, "file not empty","file is not empty \n click clear or select another location");
    }

    updateLabels();
}

void SelectSaveLoacation::on_save5_pb_clicked()
{
    if(save->containsEmptyWord("saved_games_5.txt")){
        game.saveThisGame("saved_games_5.txt");
        this->close();
    }
    else {
        QMessageBox::critical(this, "file not empty","file is not empty \n click clear or select another location");
    }

    updateLabels();
}



void SelectSaveLoacation::on_clear_pb_clicked()
{

    save->writeEmptyToFile("saved_games_1.txt");
    save->writeEmptyToFile("saved_games_2.txt");
    save->writeEmptyToFile("saved_games_3.txt");
    save->writeEmptyToFile("saved_games_4.txt");
    save->writeEmptyToFile("saved_games_5.txt");

    updateLabels();

}


void SelectSaveLoacation::on_clear1_clicked()
{
    save->writeEmptyToFile("saved_games_1.txt");
    updateLabels();
}


void SelectSaveLoacation::on_clear2_clicked()
{
    save->writeEmptyToFile("saved_games_2.txt");
    updateLabels();
}


void SelectSaveLoacation::on_clear3_clicked()
{
    save->writeEmptyToFile("saved_games_3.txt");
    updateLabels();
}


void SelectSaveLoacation::on_clear4_clicked()
{
    save->writeEmptyToFile("saved_games_4.txt");
    updateLabels();
}


void SelectSaveLoacation::on_clear5_clicked()
{
    save->writeEmptyToFile("saved_games_5.txt");
    updateLabels();
}

void SelectSaveLoacation::updateLabels()
{
    for (int i = 1; i <= 5; ++i) {
        QString saveFileName = QString("saved_games_%1.txt").arg(i); // Create the filename
        QLabel* label = nullptr; // Pointer to hold the label

        // Use a switch-case or if-else to assign the correct label based on the index
        switch (i) {
            case 1: label = ui->save1_lbl; break;
            case 2: label = ui->save2_lbl; break;
            case 3: label = ui->save3_lbl; break;
            case 4: label = ui->save4_lbl; break;
            case 5: label = ui->save5_lbl; break;
        }

        // Check if the save file contains an empty word and update the label text accordingly
        if (save->containsEmptyWord(saveFileName.toStdString())) {
            label->setText("available");
        } else {
            label->setText("filled");
        }
    }
}





