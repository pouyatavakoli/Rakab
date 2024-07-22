#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <QWidget>

namespace Ui {
class playground;
}

class playground : public QWidget
{
    Q_OBJECT

public:
    explicit playground(QWidget *parent = nullptr);
    ~playground();

private:
    Ui::playground *ui;
};

#endif // PLAYGROUND_H
