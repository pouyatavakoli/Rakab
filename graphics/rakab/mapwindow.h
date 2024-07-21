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
    void openPlayground();

private:
    Ui::mapwindow *ui;
    QPixmap backgroundPixmap;
    QMap<QString, QString> neshan;
    QVector<QRect> dropAreas;
    QVector<QRect> currentDropAreas;
    void askToStartBattle(QWidget *parent , QString);


    void initializeNeshanLabels();
    void highlightDropArea(QPoint pos);
//    double calculateDistanceToRect(const QPoint&, const QPoint&);
    QLabel* findNearestLabel(const QPoint&, const QList<QLabel*>&);
    void initializeLabels();
};

#endif // MAPWINDOW_H
