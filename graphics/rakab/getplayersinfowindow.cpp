#include <QMainWindow>

#include "getplayersinfowindow.h"
#include "ui_getplayersinfowindow.h"
#include "mainmenu.h"
#include "mapwindow.h"


getPlayersInfoWindow::getPlayersInfoWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::getPlayersInfoWindow)
{
   // ui->setupUi(this);
    mainLayout = new QVBoxLayout;
    playerCountSpinBox = new QSpinBox;
    mainLayout->addWidget(playerCountSpinBox);
    //todo: fix and uncommnet this
    //playerCountSpinBox->setMinimum(3);
    connect(playerCountSpinBox, qOverload<int>(&QSpinBox::valueChanged), this, &getPlayersInfoWindow::updatePlayerNames);
    setCentralWidget(new QWidget);
    centralWidget()->setLayout(mainLayout);
    // submit button
    QPushButton *submitButton = new QPushButton("Submit");
    mainLayout->addWidget(submitButton);
    connect(submitButton, &QPushButton::clicked, this, &getPlayersInfoWindow::handleSubmit);

    // back button
    QPushButton *back_btn = new QPushButton("back");
    mainLayout->addWidget(back_btn);
    connect(back_btn, &QPushButton::clicked, this, &getPlayersInfoWindow::goback);
}

getPlayersInfoWindow::~getPlayersInfoWindow()
{
    delete ui;
}

void getPlayersInfoWindow::on_back_btn_clicked()
{
    mainmenu *menu = new mainmenu();
    menu -> show();
    this -> close();
}

void getPlayersInfoWindow::updatePlayerNames(int count)
{
    // Clear previous line edits and labels
    for (auto* lineEdit : playerNamesLineEdit) {
        delete lineEdit;
    }
    //todo: clear labels
    playerNamesLineEdit.clear();

    // Create new line edits with labels for Name and Age
    for (int i = 0; i < count; ++i) {
        QLabel *nameLabel = new QLabel("Name:");
        QLineEdit *nameLineEdit = new QLineEdit;
        mainLayout->addWidget(nameLabel);
        mainLayout->addWidget(nameLineEdit);
        playerNamesLineEdit.push_back(nameLineEdit);

        QLabel *ageLabel = new QLabel("Age:");
        QLineEdit *ageLineEdit = new QLineEdit;
        mainLayout->addWidget(ageLabel);
        mainLayout->addWidget(ageLineEdit);
        playerNamesLineEdit.push_back(ageLineEdit);
    }


}

void getPlayersInfoWindow::handleSubmit()
{
    mapwindow* map = new mapwindow;
    map->show();
    this->close();
}

void getPlayersInfoWindow::goback()
{
    mainmenu *menu = new mainmenu();
    menu ->show();
    this->close();

}

