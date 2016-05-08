#ifndef DOGHOUSE_H
#define DOGHOUSE_H

#include <QWidget>

namespace Ui {
    class DogHouse;
}

class CuteWatchDog;

class DogHouse : public QWidget
{
    Q_OBJECT

public:
    explicit DogHouse(QWidget *parent = 0);
    ~DogHouse();

private slots:
    void on_pushButton_watchfile_clicked();
    void on_pushButton_watchdir_clicked();
    void on_pushButton_cmd_clicked();

private:
    Ui::DogHouse *ui;
    CuteWatchDog *dog;
};

#endif // DOGHOUSE_H
