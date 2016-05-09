#include "DogHouse.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DogHouse w;
    w.show();

    return a.exec();
}
