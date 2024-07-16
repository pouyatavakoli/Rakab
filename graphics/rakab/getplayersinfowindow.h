#ifndef GETPLAYERSINFOWINDOW_H
#define GETPLAYERSINFOWINDOW_H

#include <QWidget>
#include <QMainWindow>

#include "QVBoxLayout"
#include"QSpinBox"



namespace Ui {
class getPlayersInfoWindow;
}

class getPlayersInfoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit getPlayersInfoWindow(QWidget *parent = nullptr);
    ~getPlayersInfoWindow();

private slots:
    void on_back_btn_clicked();
public slots:
    void updatePlayerNames(int count);
    void handleSubmit();
    void goback();


private:
    Ui::getPlayersInfoWindow *ui;
    QVBoxLayout *mainLayout;
    QSpinBox *playerCountSpinBox;
    QVector<QLineEdit*> playerNamesLineEdit;
};

#endif // GETPLAYERSINFOWINDOW_H
