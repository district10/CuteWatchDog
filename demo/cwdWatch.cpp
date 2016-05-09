#include "CuteWatchDog.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CuteWatchDog cwd;

    if ( argc == 3 ) {
        cwd.watchDirThenRunCmd( argv[1], argv[2] );
    } else {
        cwd.watchDirThenRunCmd( QApplication::applicationDirPath(), QString() );
    }

    return a.exec();
}