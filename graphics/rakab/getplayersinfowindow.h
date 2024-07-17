

#ifndef GETINFO_H
#define GETINFO_H

#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class getPlayersInfoWindow : public QDialog {
    Q_OBJECT

public:
    getPlayersInfoWindow(QWidget *parent = nullptr);

private slots:
    void submitPlayerCount();
    void submitInfo();

private:
    QVBoxLayout *layout;
    QLabel *playerCountLabel;
    QLineEdit *playerCountInput;
    QPushButton *playerCountSubmitButton;
    QVector<QLabel*> playerNameLabels;
    QVector<QLineEdit*> playerNameInputs;
    QVector<QLabel*> playerAgeLabels;
    QVector<QLineEdit*> playerAgeInputs;
    QPushButton *submitButton;

    void createPlayerFields(int count);
};

#endif
