#include "mapwindow.h"
#include "ui_mapwindow.h"
#include "mainmenu.h"
#include <QPainter>
#include <QResizeEvent>
#include <QMimeData>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QDrag>
#include <QMouseEvent>
#include <QDebug>
#include <iostream>

mapwindow::mapwindow(QWidget *parent) :
    QWidget(parent),
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

    //neshan["NeshaneSolh"] = ":/new/symbols/assets/symbols/Pe_Sym.png";
    //neshan["NeshaneJang"] = ":/new/symbols/assets/symbols/Wa_Sym.png";

    // Define drop areas for Solh and Jang symbols

    /*
    struct Area {
        QString name;
        QRect rect;
    };

    QMap<QString, QRect> dropAreasSolh = {
        { "ELINA", QRect(52, 193, 40, 40) },
        { "ROLLO", QRect(251, 37, 40, 40) },
        { "TALMONE", QRect(453, 166, 40, 40) },
        { "PLADACI", QRect(726, 125, 40, 40) },
        { "BORGE" , QRect(726 , 183 , 40 , 40)},
        { "BELLA", QRect(888, 106, 40, 40) },
        { "MORINA", QRect(578, 263, 40, 40) },
        { "CALINE", QRect(1070, 191, 40, 40) },
        { "ARMENTO", QRect(530, 453, 40, 40) },
        { "OLIVADI", QRect(580, 410, 40, 40) },
        { "ENNA", QRect(897, 295, 40, 40) },
        { "ATELA", QRect(911, 464, 40, 40) },
        { "DIMASE", QRect(848, 516, 40, 40) },
        { "LIA", QRect(508, 555, 50, 50) }
    };
    */
    dropAreasSolh = {
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
    initializeNeshanLabels();

    // Enable drag and drop
    setAcceptDrops(true);
    ui->NeshaneJang->setAcceptDrops(true);
    ui->NeshaneSolh->setAcceptDrops(true);
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
    for (const QRect &area : dropAreasSolh + dropAreasJang) {
        if (area.contains(pos)) {
            currentDropAreas.append(area);
            break;
        }
    }
    update();
}

// Handle drop events
void mapwindow::dropEvent(QDropEvent *event)
{
    QLabel *label = qobject_cast<QLabel *>(childAt(event->position().toPoint()));

    if (label && label->objectName().startsWith("Neshane")) {
        QPoint dropPosition = event->position().toPoint();

        QVector<QRect> *targetAreas = nullptr;
        if (label->objectName() == "NeshaneSolh") {
            targetAreas = &dropAreasSolh;
            qDebug() << "solh";
        } else if (label->objectName() == "NeshaneJang") {
            targetAreas = &dropAreasJang;
            qDebug() << "jang";
        }

        if (targetAreas) {
            for (int i = 0; i < targetAreas->size(); ++i) {
                if (targetAreas->at(i).contains(dropPosition)) {
                    QRect area = targetAreas->at(i);
                    label->move(area.topLeft());
                    label->resize(area.size());
                    label->setPixmap(QPixmap(neshan[label->objectName()]).scaled(area.size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
                    QString areaName = (i == 0) ? "a" : (i == 1) ? "b" : "c";
                    qDebug() << "Dropped in area:" << areaName;
                    break;
                }
            }
        }
    }
    currentDropAreas.clear();
    update();
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
