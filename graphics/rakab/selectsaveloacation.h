#ifndef SELECTSAVELOACATION_H
#define SELECTSAVELOACATION_H

#include <QWidget>
#include <QMessageBox>
#include "game.hpp"
//#include "playground.h"
#include "save.h"
namespace Ui {
class SelectSaveLoacation;
}

class SelectSaveLoacation : public QDialog
{
    Q_OBJECT

public:
    explicit SelectSaveLoacation(Game& game , QWidget *parent = nullptr);
    ~SelectSaveLoacation();

    void updateLabels();
private slots:
    void on_pushButton_2_clicked();

    void on_save1_pb_clicked();

    void on_save2_pb_clicked();

    void on_save3_pb_clicked();

    void on_save4_pb_clicked();


    void on_clear_pb_clicked();

    void on_clear1_clicked();

    void on_clear4_clicked();

    void on_clear2_clicked();

    void on_clear3_clicked();

    void on_clear5_clicked();

    void on_save5_pb_clicked();

private:
    Ui::SelectSaveLoacation *ui;
    Game& game;
    Save* save;
};

#endif // SELECTSAVELOACATION_H
