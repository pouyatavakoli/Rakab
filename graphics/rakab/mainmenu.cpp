#include "mainmenu.h"
#include "ui_mainmenu.h"
#include"savedgamesmenu.h"
#include "getplayersinfowindow.h"
#include "save.h"


mainmenu::mainmenu(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::mainmenu)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());

    // background
    setAutoFillBackground(true);
    QPixmap pixmap(":/new/background/assets/background/background.png");
    QSize size = this->size();  // Get the size of the window
    QPixmap scaledPixmap = pixmap.scaled(size, Qt::KeepAspectRatioByExpanding);  // Scale the pixmap to fit the window
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(scaledPixmap));
    this->setPalette(palette); // Set the palette of the widget

    // title
    this->ui->title_lbl->setStyleSheet("color: red");
    checkGameResources();


}


mainmenu::~mainmenu()
{
    delete ui;
}




void mainmenu::on_exit_btn_clicked()
{
    this->close();
}


void mainmenu::on_saved_btn_clicked()
{

    Game *game = new Game();
    savedGamesMenu *sgMenu = new savedGamesMenu(*game);
    sgMenu->show();
    this->close();


}



void mainmenu::on_newgame_btn_clicked()
{
    Game *game = new Game();
    getPlayersInfoWindow *getinfo = new getPlayersInfoWindow(*game);
    getinfo->show();
    this->close();
}

void mainmenu::checkGameResources() {
    qDebug()<< "checking game resources";
    for (int i = 1; i <= 5; ++i) {
        QString fileName = QString("saved_games_%1.txt").arg(i); // Create the filename

        // Check if the file exists
        std::ifstream file(fileName.toStdString());
        if (!file.good()) {
            // Create the file if it doesn't exist
            std::ofstream newFile(fileName.toStdString());
            if (newFile.is_open()) {
                newFile << "empty";
                newFile.close();
                qDebug()<< "created file : " << fileName ;

            } else {
                // Handle file creation error
                qDebug()<< "Error creating file: " << fileName ;
            }
        }
    }
    qDebug()<< "game resources checked";
}


