#include "CuteWatchDog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CuteWatchDog cwd;
    cwd.watchThenMake("/home/tzx/git/CuteWatchDog");

    return a.exec();
}
