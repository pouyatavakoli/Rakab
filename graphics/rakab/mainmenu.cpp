#include "mainmenu.h"
#include"savedgamesmenu.h"
#include "ui_mainmenu.h"


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

    // Show the saved games menu window
    savedGamesMenu *sgMenu = new savedGamesMenu();
    sgMenu->show();
    // close the current window
    this->close();


}

