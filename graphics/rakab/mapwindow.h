#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QPixmap>
#include <QLabel>
#include <QMap>

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
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
    void on_pushButton_clicked();

private:
    Ui::mapwindow *ui;
    QPixmap backgroundPixmap;
    QMap<QString, QString> neshan;
    void initializeNeshanLabels();
};

#endif // MAPWINDOW_H
