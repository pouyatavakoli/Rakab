#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include <QWidget>

namespace Ui {
class mapwindow;
}

class mapwindow : public QWidget
{
    Q_OBJECT

public:
    explicit mapwindow(QWidget *parent = nullptr);
    ~mapwindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::mapwindow *ui;
};

#endif // MAPWINDOW_H
