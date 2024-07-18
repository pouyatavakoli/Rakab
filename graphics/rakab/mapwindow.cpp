#include "mapwindow.h"
#include "ui_mapwindow.h"
#include "mainmenu.h"
#include <QPainter>
#include <QResizeEvent>
#include <QMimeData>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QDrag>
#include <QMouseEvent>

mapwindow::mapwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mapwindow)
{
    ui->setupUi(this);

    // Initialize the background pixmap
    backgroundPixmap = QPixmap(":/new/map/assets/Map.png");

    // Set the stylesheet for the widget to show the background image
    this->setStyleSheet("background-image: url(:/new/map/assets/Map.png);"
                        "background-position: center;"
                        "background-repeat: no-repeat;"
                        "background-size: cover;");

    neshan["NeshaneSolh"] = ":/new/symbols/assets/symbols/Pe_Sym.png";
    neshan["NeshaneJang"] = ":/new/symbols/assets/symbols/Wa_Sym.png";

    // Initialize the neshan labels
    initializeNeshanLabels();

    // Enable drag and drop
    setAcceptDrops(true);
}

mapwindow::~mapwindow()
{
    delete ui;
}

void mapwindow::initializeNeshanLabels()
{
    // Get the labels from the UI and set up event filters
    QLabel *label1 = ui->NeshaneSolh; // Assuming label1 is the object name of the first label in the designer
    QLabel *label2 = ui->NeshaneJang; // Assuming label2 is the object name of the second label in the designer

    label1->setPixmap(QPixmap(neshan["NeshaneSolh"]));
    label2->setPixmap(QPixmap(neshan["NeshaneJang"]));

    label1->installEventFilter(this);
    label2->installEventFilter(this);
}

void mapwindow::on_pushButton_clicked()
{
    mainmenu *menu = new mainmenu();
    menu->show();
    this->close();
}

void mapwindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(rect(), backgroundPixmap.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    QWidget::paintEvent(event); // Call the base class implementation
}

// Handle drag enter events
void mapwindow::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();
}

// Handle drop events
void mapwindow::dropEvent(QDropEvent *event)
{
    QLabel *label = qobject_cast<QLabel *>(childAt(event->position().toPoint()));
    if (label && label->objectName().startsWith("Neshane")) {
        label->move(event->position().toPoint() - label->rect().center());
        label->show();
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
