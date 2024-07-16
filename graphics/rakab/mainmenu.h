#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class mainmenu; }
QT_END_NAMESPACE

class mainmenu : public QMainWindow
{
    Q_OBJECT

public:
    mainmenu(QWidget *parent = nullptr);
    ~mainmenu();

private:
    Ui::mainmenu *ui;
public slots:
    void exitApplication();

};
#endif // MAINMENU_H
