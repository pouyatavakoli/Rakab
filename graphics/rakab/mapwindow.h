#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QMap>
#include <QPixmap>
#include <QVector>

namespace Ui {
class mapwindow;
}

class mapwindow : public QWidget
{
    Q_OBJECT

public:
    explicit mapwindow(QWidget *parent = nullptr);
    ~mapwindow();

protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    bool eventFilter(QObject *obj, QEvent *event) override;
    void mousePressEvent (QMouseEvent*) override ;

signals:
    void resized();

private slots:
    void on_pushButton_clicked();

private:
    Ui::mapwindow *ui;
    QPixmap backgroundPixmap;
    QMap<QString, QString> neshan;
    QVector<QRect> dropAreasSolh;
    QVector<QRect> dropAreasJang;
    QVector<QRect> currentDropAreas;

    void initializeNeshanLabels();
    void highlightDropArea(QPoint pos);
};

#endif // MAPWINDOW_H
