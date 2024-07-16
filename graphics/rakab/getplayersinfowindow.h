#ifndef GETPLAYERSINFOWINDOW_H
#define GETPLAYERSINFOWINDOW_H

#include <QWidget>

namespace Ui {
class getPlayersInfoWindow;
}

class getPlayersInfoWindow : public QWidget
{
    Q_OBJECT

public:
    explicit getPlayersInfoWindow(QWidget *parent = nullptr);
    ~getPlayersInfoWindow();

private slots:
    void on_back_btn_clicked();

private:
    Ui::getPlayersInfoWindow *ui;
};

#endif // GETPLAYERSINFOWINDOW_H
