#include "mapwindow.h"
#include "ui_mapwindow.h"
#include "mainmenu.h"
#include "playground.h"

#include <QPainter>
#include <QLineEdit>
#include <QIntValidator>
#include <QLabel>
#include <QPoint>
#include <QRect>
#include <limits>
#include <cmath>
#include <QResizeEvent>
#include <QMimeData>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QDrag>
#include <QMouseEvent>
#include <QDebug>
#include <iostream>
#include <QDialog>
#include <QHBoxLayout>
#include <QMessageBox>



mapwindow::mapwindow(Game &game ,QWidget *parent) :
    QWidget(parent),
    game(game),
    ui(new Ui::mapwindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());

    // Initialize the background pixmap
    backgroundPixmap = QPixmap(":/new/map/assets/Map.png");

    // Set the stylesheet for the widget to show the background image
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHeightForWidth(true);
    this->setSizePolicy(sizePolicy);

    // Update the paint event to handle resizing
    connect(this, &mapwindow::resized, this, QOverload<>::of(&mapwindow::update));


    dropAreas = {
        QRect(52, 193, 40, 40),
        QRect(251, 37, 40, 40),
        QRect(453, 166, 40, 40),
        QRect(726, 125, 40, 40),
        QRect(726, 183, 40, 40),
        QRect(888, 106, 40, 40),
        QRect(578, 263, 40, 40),
        QRect(1070, 191, 40, 40),
        QRect(530, 453, 40, 40),
        QRect(580, 410, 40, 40),
        QRect(897, 295, 40, 40),
        QRect(911, 464, 40, 40),
        QRect(848, 516, 40, 40),
        QRect(508, 555, 50, 50)
    };
    // Initialize the neshan labels
    initializeLabels();
    initializeNeshanLabels();

    // Enable drag and drop
    setAcceptDrops(true);
    ui->NeshaneJang->setAcceptDrops(true);
    ui->NeshaneSolh->setAcceptDrops(true);

    colorProvinceLabels();
    qDebug() << "getBattleCompleted";
    if(game.getBattleCompleted() == "Yes")
    {
        qDebug() << "Yes";
    }
    else
    {
        qDebug() << "No";
        Playground *pg = new Playground(game, game.getBattleIsOnThis());
        pg->show();
        connect(pg, &Playground::playgroundClosed, this, &mapwindow::checkAndHandleGameWinner);
    }

}

void mapwindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(rect(), backgroundPixmap.scaled(size(), Qt::KeepAspectRatioByExpanding));

    // Highlight drop areas
    QBrush brush(Qt::Dense4Pattern);
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);
    for (const QRect &area : currentDropAreas) {
        painter.drawRect(area);
    }

    QWidget::paintEvent(event); // Call the base class implementation
}

mapwindow::~mapwindow()
{
    delete ui;
}

void mapwindow::initializeNeshanLabels()
{
    // Get the labels from the UI and set up event filters
    QLabel *NeshaneSolh = ui->NeshaneSolh;
    QLabel *NeshaneJang = ui->NeshaneJang;

    // Set the pixmap without cropping and scale to fit the label
    NeshaneSolh->setPixmap(QPixmap(":/new/symbols/assets/symbols/Pe_Sym.png").scaled(NeshaneSolh->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    NeshaneJang->setPixmap(QPixmap(":/new/symbols/assets/symbols/Wa_Sym.png").scaled(NeshaneJang->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    NeshaneSolh->installEventFilter(this);
    NeshaneJang->installEventFilter(this);
}


// Handle drag enter events
void mapwindow::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();
}

// Handle drag move events
void mapwindow::dragMoveEvent(QDragMoveEvent *event)
{
    highlightDropArea(event->position().toPoint());
    event->acceptProposedAction();
}

// Highlight the appropriate drop area
void mapwindow::highlightDropArea(QPoint pos)
{
    currentDropAreas.clear();
    for (const QRect &area : dropAreas) {
        if (area.contains(pos)) {
            currentDropAreas.append(area);
            break;
        }
    }
    update();
}

// Function to calculate the Euclidean distance between two points
double calculateDistance(const QPoint& p1, const QPoint& p2) {
    return std::sqrt(std::pow(p1.x() - p2.x(), 2) + std::pow(p1.y() - p2.y(), 2));
}

// Function to find the nearest QLabel to the drop position
QLabel* mapwindow::findNearestLabel(const QPoint& dropPosition, const QList<QLabel*>& labels) {
    QLabel* nearestLabel = nullptr;
    double minDistance = std::numeric_limits<double>::max();

    for (QLabel* label : labels) {
        QRect labelRect = label->geometry();
        QPoint labelCenter = labelRect.center();
        double distance = calculateDistance(dropPosition, labelCenter);


        if (distance < minDistance) {
            minDistance = distance;
            nearestLabel = label;
        }
    }

    return nearestLabel;
}

void mapwindow::dropEvent(QDropEvent *event)
{
    bool isDroppedInArea = false;
    QPoint dropPosition = event->position().toPoint();
    QString provinceLabelName = event->mimeData()->text();
    qDebug() << "Drop event detected at position:" << dropPosition;

    // Collect all QLabel widgets
    QList<QLabel*> labels;
    foreach (QWidget *child, this->findChildren<QWidget*>()) {
        QLabel *label = qobject_cast<QLabel *>(child);
        if (label) {
            labels.append(label);
        }
    }


    QLabel* nearestLabel = findNearestLabel(dropPosition, labels);
    if (nearestLabel) {
        qDebug() << "Nearest label detected:" << nearestLabel->objectName();

        // Check if the drop position is within any of the drop areas
        isDroppedInArea = false;
        for (int i = 0; i < dropAreas.size(); ++i) {
            if (dropAreas[i].contains(dropPosition)) {
                QRect area = dropAreas[i];
                nearestLabel->move(area.topLeft());
                nearestLabel->resize(area.size());

                // Ensure the pixmap is valid before setting it
                QString labelName = nearestLabel->objectName();
                std::string labelNameStd = labelName.toStdString();
                QPixmap pixmap = QPixmap(neshan[labelName]);
                if (pixmap.isNull()) {
                    qWarning() << "Pixmap for" << labelName << "is null. Check the path or pixmap loading.";
                } else {
                    nearestLabel->setPixmap(pixmap.scaled(area.size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
                }

                qDebug() << "Dropped in area:" << labelName;
                // ask to start battle in area if available
                if (provinceLabelName == "NeshaneSolh")
                {
                    if (checkAvailable(labelName) && game.getNeshaneSolhProvince() == "None")
                    {
                        game.setNeshaneSolhProvince(labelNameStd);
                        qDebug() << "neshan solh province was set : " << QString::fromStdString(labelNameStd) ;
                        isDroppedInArea = true;
                        break;
                    }
                    else {
                        qDebug() << "province can't be played" ;
                        QDialog *provinceTaken = new QDialog(this);

                        // Set text for the dialog
                        QLabel *provinceTaken_lbl = new QLabel("this province is not available try onother one");
                        provinceTaken_lbl->setAlignment(Qt::AlignCenter); // Optionally set alignment

                        // Set layout for the dialog
                        QVBoxLayout *mainLayout = new QVBoxLayout(provinceTaken);

                        // Add the message label to the main layoutmessageLabel
                        mainLayout->addWidget(provinceTaken_lbl);

                        // Create buttons
                        QPushButton *okButton = new QPushButton("OK", provinceTaken);
                        // Create layout for buttons
                        QHBoxLayout *buttonLayout = new QHBoxLayout;
                        buttonLayout->addWidget(okButton);
                        mainLayout->addLayout(buttonLayout);

                        QObject::connect(okButton, &QPushButton::clicked, provinceTaken , &QDialog::accept);

                        provinceTaken->show();
                        continue;
                    }
                }
                else if(provinceLabelName == "NeshaneJang")
                {
                    if (checkAvailable(labelName)){
                        qDebug() <<  labelName << "was available";
                        if (askToStartBattle(this , labelName))
                        {
                            if (game.getIsFirstRound() == true)
                            {
                                qDebug() << "First battle started, setting starter";

                                try {
                                    auto &smallestPlayer = game.findSmallestPlayer();
                                    qDebug() << "Smallest player found:" << QString::fromStdString(smallestPlayer.getName());
                                    game.setBattleStarter(smallestPlayer);
                                    qDebug() << "Battle starter set";
                                } catch (const std::length_error& e) {
                                    qDebug() << "Caught a length_error during smallest player search or battle starter set:" << e.what();
                                    // return;
                                    continue;
                                } catch (const std::exception& e) {
                                    qDebug() << "Caught an exception during smallest player search or battle starter set:" << e.what();
                                    // return;
                                    continue;
                                }

                                qDebug() << "Creating Playground object";
                                try {
                                    Playground *pg = new Playground(game, labelNameStd);
                                    askForTwoNumbers(game , this);
                                    game.setBattleIsOnThis(labelNameStd);
                                    qDebug() << "Playground object created";
                                    pg->show();
                                    qDebug() << "Playground shown";
                                    connect(pg, &Playground::playgroundClosed, this, &mapwindow::checkAndHandleGameWinner);
                                } catch (const std::length_error& e) {
                                    qDebug() << "Caught a length_error during Playground creation or show:" << e.what();
                                    return; // Early exit or appropriate error handling
                                } catch (const std::exception& e) {
                                    qDebug() << "Caught an exception during Playground creation or show:" << e.what();
                                    return; // Early exit or appropriate error handling
                                }


                                isDroppedInArea = true;
                                game.setIsFirstRound(false);
                                break;
                            }

                            else
                            {
                                qDebug() << "Battle started but it's not the first round";
                                game.setNeshaneJangOwner();
                                qDebug() << "setNeshaneJangOwner";
                                game.setBattleStarter(game.getPlayerWhoShouldStart());
                                //                            game.setBattleStarter(game.getPlayer(0));
                                qDebug() << "Battle started setNeshaneJangOwner";

                                try {
                                    qDebug() << "Creating Playground object for subsequent round";
                                    askForTwoNumbers(game , this);
                                    Playground *pg = new Playground(game, labelNameStd);
                                    game.setBattleIsOnThis(labelNameStd);
                                    qDebug() << "Playground object created for subsequent round";
                                    pg->show();
                                    qDebug() << "Playground shown for subsequent round";
                                    connect(pg, &Playground::playgroundClosed, this, &mapwindow::checkAndHandleGameWinner);
                                } catch (const std::exception& e) {
                                    qDebug() << "Caught an exception during Playground creation or show in subsequent round:" << e.what();
                                    return; // Handle the error or decide how to proceed
                                }

                                isDroppedInArea = true;
                                break;
                            }
                        }

                    }
                    else {
                        qDebug() << "province can't be played" ;
                        QDialog *provinceTaken = new QDialog(this);

                        // Set text for the dialog
                        QLabel *provinceTaken_lbl = new QLabel("this province is taken try onother one");
                        provinceTaken_lbl->setAlignment(Qt::AlignCenter); // Optionally set alignment

                        // Set layout for the dialog
                        QVBoxLayout *mainLayout = new QVBoxLayout(provinceTaken);

                        // Add the message label to the main layoutmessageLabel
                        mainLayout->addWidget(provinceTaken_lbl);

                        // Create buttons
                        QPushButton *okButton = new QPushButton("OK", provinceTaken);
                        // Create layout for buttons
                        QHBoxLayout *buttonLayout = new QHBoxLayout;
                        buttonLayout->addWidget(okButton);
                        mainLayout->addLayout(buttonLayout);

                        QObject::connect(okButton, &QPushButton::clicked, provinceTaken , &QDialog::accept);

                        provinceTaken->show();
                        continue;
                    }
                }
            }
        }

        if (!isDroppedInArea) {
            qDebug() << "Drop position is not within any defined drop areas.";
        }
        else {
            qDebug() << "No nearest label found";
        }

        currentDropAreas.clear();
        update();
    }
}

void mapwindow::checkAndHandleGameWinner() {
    // Call the function to check for the game winner
    colorProvinceLabels();
    qDebug() << "checkForGameWinner started";
    if (game.winGame1() || game.winGame2())
    {
        try {
            QString winnerName = QString::fromStdString(game.findWinner()); // Example getter for winner's name

            // Display the winner
            QString message = "The winner of the game is: " + winnerName;
            QMessageBox::information(this, "Game Over", message);

            // Close the MapWindow
            mainmenu *menu = new mainmenu();
            menu->show();
            this->close();
        }
        catch (const std::runtime_error& e) {
            qWarning() << "Error determining winner:" << e.what();
            // Handle or log the error as needed, maybe prompt a message or take another action
        }
        catch (const std::exception& e) {
            qWarning() << "Unexpected error:" << e.what();
            // Handle or log the error as needed
        }
    }
}

void mapwindow::mousePressEvent(QMouseEvent *event)
{
    QLabel *label = qobject_cast<QLabel *>(childAt(event->pos()));

    try {
        if (event->button() == Qt::LeftButton) {
            if (label && label->objectName().startsWith("Neshane")) {
                qDebug() << "Left mouse button clicked on a Neshane label!";
            }
        }
    } catch (const std::exception &e) {
        qDebug() << "An exception occurred: " << e.what();
    }
}



bool mapwindow::eventFilter(QObject *obj, QEvent *event)
{
    QLabel *label = qobject_cast<QLabel *>(obj);
    if (label) {
        if(label->objectName() == "NeshaneSolh") {
            if (game.getNeshaneSolhOwner() == nullptr) {
                return true; // Prevent drag if there is no owner
            } else if (game.getNeshaneSolhProvince() != "None") {
                return true; // Prevent dragging if NeshaneSolh has already been dropped
            }
        }

        if (label->objectName() == "NeshaneJang") {
            if (game.getNeshaneSolhOwner() != nullptr && game.getNeshaneSolhProvince() == "None") {
                return true; // Block drag if NeshaneSolh is not dropped
            }
        }

        if (event->type() == QEvent::MouseButtonPress) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
            if (mouseEvent->button() == Qt::LeftButton) {
                QDrag *drag = new QDrag(this);
                QMimeData *mimeData = new QMimeData;
                mimeData->setText(label->objectName());
                drag->setMimeData(mimeData);

                // Set the pixmap and resize it to match the label size
                QPixmap scaledPixmap = label->pixmap().scaled(label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                drag->setPixmap(scaledPixmap);

                // Set the hotSpot to be the cursor's position within the label
                drag->setHotSpot(mouseEvent->pos());

                drag->exec(Qt::MoveAction);
                return true;
            }
        }
    }
    return QWidget::eventFilter(obj, event);
}

void mapwindow::resizeEvent(QResizeEvent *event)
{
    emit resized();
    QWidget::resizeEvent(event); // Call the base class implementation
}

void mapwindow::on_pushButton_clicked()
{
    mainmenu *menu = new mainmenu();
    menu->show();
    this->close();
}

void mapwindow::openPlayground()
{
    Playground *pg = new Playground(game ,"BELLA");
    pg->show();
    this->close();
}

void mapwindow::initializeLabels()
{
    // Create and position labels directly
    for (int i = 0; i < dropAreas.size(); ++i) {
        QLabel *label = new QLabel(this);
        switch (i)
        {
        case 0:
            label->setObjectName(QString("ELINIA"));
            break;
        case 1:
            label->setObjectName(QString("ROLLO"));
            break;
        case 2:
            label->setObjectName(QString("TALMONE"));
            break;
        case 3:
            label->setObjectName(QString("PLADACI"));
            break;
        case 4:
            label->setObjectName(QString("BORGE"));
            break;
        case 5:
            label->setObjectName(QString("BELLA"));
            break;
        case 6:
            label->setObjectName(QString("MORINA"));
            break;
        case 7:
            label->setObjectName(QString("CALINE"));
            break;
        case 8:
            label->setObjectName(QString("ARMENTO"));
            break;
        case 9:
            label->setObjectName(QString("OLIVADI"));
            break;
        case 10:
            label->setObjectName(QString("LIA"));
            break;
        case 11:
            label->setObjectName(QString("ATELA"));
            break;
        case 12:
            label->setObjectName(QString("DISMASE"));
            break;
        case 13:
            label->setObjectName(QString("ENNA"));
            break;
        }
        label->setGeometry(dropAreas[i]);
        label->setStyleSheet("background-color: white; border: 1px solid black;");
        // For visibility
        label->setText(label->objectName()); // Set text with the label number
        label->setAlignment(Qt::AlignCenter); // Center-align text
        label->show(); // Ensure the label is visible
    }
}

bool mapwindow::checkAvailable(QString province) {
    qDebug() << "checking availability";

    if (province == QString::fromStdString(game.getNeshaneSolhProvince())) {
        return false;
    }


    std::vector<std::vector<std::string>> captured;

    try {
        for (int i = 0; i < game.getPlayerCount(); ++i) {
            qDebug() << "getplayer and get provinces will be called after this";
            try {
                captured.push_back(game.getPlayer(i).getOwnedProvinces());
            } catch (const std::runtime_error& e) {
                qDebug() << "Player" << i << "error:" << e.what();
                // Handle the error appropriately, for example by pushing an empty vector
                captured.push_back(std::vector<std::string>());
            }
        }
    } catch (const std::exception& e) {
        qDebug() << "Caught an exception:" << e.what();
        // Handle other exceptions if necessary
        return true; // Returning true to indicate province is available as a fallback
    } catch (...) {
        qDebug() << "Caught an unknown exception.";
        // Handle any other unknown exceptions
        return true; // Returning true to indicate province is available as a fallback
    }

    for (size_t j = 0; j < captured.size(); ++j) {
        for (const auto& iterator : captured[j]) {
            if (QString::fromStdString(iterator) == province) {
                return false; // Province is owned
            }
        }
    }

    return true; // Province is available
}


bool mapwindow::askToStartBattle(QWidget *parent, QString provinceName) {
    // Create dialog
    QDialog *askToStartBattle = new QDialog(parent);

    // Set text for the dialog
    QLabel *messageLabel = new QLabel("Do you want to start a battle on " + provinceName + " province?", askToStartBattle);
    messageLabel->setAlignment(Qt::AlignCenter); // Optionally set alignment

    // Set layout for the dialog
    QVBoxLayout *mainLayout = new QVBoxLayout(askToStartBattle);

    // Add the message label to the main layout
    mainLayout->addWidget(messageLabel);

    // Create buttons
    QPushButton *okButton = new QPushButton("OK", askToStartBattle);
    QPushButton *cancelButton = new QPushButton("Cancel", askToStartBattle);

    // Create layout for buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);


    mainLayout->addLayout(buttonLayout);

    // Connect button signals to slots
    QObject::connect(okButton, &QPushButton::clicked, askToStartBattle, &QDialog::accept);
    QObject::connect(cancelButton, &QPushButton::clicked, askToStartBattle, &QDialog::reject);

    // Wait for user input
    int result = askToStartBattle->exec();

    // Handle button presses
    if (result == QDialog::Accepted) {
        // OK button pressed
        // Handle OK button press here (open playground)
        connect(askToStartBattle , &QDialog::accepted, this, &mapwindow::openPlayground);
        return true ;
    }
    // clicked cancel
    return false ;

    delete askToStartBattle;
}

void mapwindow::colorProvinceLabels()
{
    for (int playerIndex = 0; playerIndex < game.getPlayerCount(); ++playerIndex)
    {
        Player& player = game.getPlayer(playerIndex);  // Assuming getPlayer returns a reference, not a pointer
        QString playerColor = QString::fromStdString(player.getColor());  // Convert std::string to QString
        std::vector<std::string> ownedProvincesStd = player.getOwnedProvinces();  // Assuming getOwnedProvinces returns std::vector<std::string>

        QVector<QString> ownedProvinces;
        for (const auto& province : ownedProvincesStd)
        {
            ownedProvinces.append(QString::fromStdString(province));  // Convert and append each std::string to QVector<QString>
        }

        // Iterate through each province owned by the player
        for (const QString& province : ownedProvinces)
        {
            QLabel* label = findChild<QLabel*>(province);
            if (label)
            {
                label->setStyleSheet("background-color: " + playerColor + "; border: 1px solid black;");
            }
        }
    }
}

void mapwindow::on_pushButton_2_clicked()
{
    game.setBattleCompleted("Yes");
    SelectSaveLoacation* ssl = new SelectSaveLoacation(game , this);
    ssl->show();
}

void mapwindow::askForTwoNumbers(Game &game, QWidget *parent = nullptr)
{
    QDialog dialog(parent);
    QVBoxLayout *layout = new QVBoxLayout(&dialog);

    QLabel *firstNumberLabel = new QLabel("Enter the LUCKY number (between 10 and 99):");
    QLineEdit *firstNumberInput = new QLineEdit;
    firstNumberInput->setValidator(new QIntValidator(10, 99, firstNumberInput));
    layout->addWidget(firstNumberLabel);
    layout->addWidget(firstNumberInput);

    QLabel *secondNumberLabel = new QLabel("Enter the UnLUCKY number (between 10 and 99):");
    QLineEdit *secondNumberInput = new QLineEdit;
    secondNumberInput->setValidator(new QIntValidator(10, 99, secondNumberInput));
    layout->addWidget(secondNumberLabel);
    layout->addWidget(secondNumberInput);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    QPushButton *okButton = new QPushButton("OK");
    QPushButton *cancelButton = new QPushButton("Cancel");
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);
    layout->addLayout(buttonLayout);

    // Connect buttons to dialog actions
    connect(okButton, &QPushButton::clicked, &dialog, [&]() {
        int firstNumber = firstNumberInput->text().toInt();
        int secondNumber = secondNumberInput->text().toInt();

        // Check if the numbers are within the valid range
        if (firstNumber < 10 || firstNumber > 99 || secondNumber < 10 || secondNumber > 99) {
            QMessageBox::critical(&dialog, "Invalid Input", "Both numbers must be between 10 and 99.");
        } else {
            game.setLuckyNumber(firstNumber);    // Call setLuckyNumber with the first number
            game.setUnLuckyNumber(secondNumber); // Call setUnLuckyNumber with the second number
            dialog.accept();  // Close the dialog if input is valid
        }
    });

    connect(cancelButton, &QPushButton::clicked, &dialog, &QDialog::reject);

    dialog.exec();  // Execute the dialog
}


