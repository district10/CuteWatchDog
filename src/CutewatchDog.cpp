#include "CuteWatchDog.h"
#include "DogHouse.h"
#include <QDebug>
#include <QProcess>
#include <iostream>
#include <QDateTime>

static QString now()
{
    QDateTime dt( QDateTime::currentDateTime() );
    return QString().sprintf( "%02d:%02d:%02d.%03d"  // e.g. 01:23:45.678
                              , dt.time().hour()
                              , dt.time().minute()
                              , dt.time().second()
                              , dt.time().msec() );
}

void CuteWatchDog::onDirectoryChanged(QString path)
{
    std::cout << qPrintable(QString("%1, hit dir: %2\n").arg(now()).arg(path));
    if ( !cmd.isEmpty() ) {
        process->start( cmd );
    }
}

CuteWatchDog::CuteWatchDog()
{
    connect( this, SIGNAL(directoryChanged(QString)),
             this, SLOT(onDirectoryChanged(QString)) );

    process = new QProcess( this );
    connect( process, SIGNAL(started()),
             this, SLOT(onProcessStarted()));
    connect( process, SIGNAL(readyRead()),
             this, SLOT(onReadyRead()));
    connect( process, SIGNAL(finished(int)),
             this, SLOT(onFinished(int)));
}

CuteWatchDog::~CuteWatchDog()
{
}

void CuteWatchDog::setCallbackFunc(const QString &cb)
{
    cmd = cb;
    std::cout << "set command to " << qPrintable(cb);
}

void CuteWatchDog::setWatchDir(const QString &dir)
{
    addPath( dir );
    std::cout << qPrintable(QString("Watching %1...\n").arg(dir));
}

void CuteWatchDog::onProcessStarted()
{
}

void CuteWatchDog::onReadyRead()
{
    std::cout << "\n\n\n" << qPrintable(process->readAll()) << "\n\n";
}

void CuteWatchDog::onFinished(int id)
{
}

void CuteWatchDog::watchDirThenRunCmd( const QString &dir, const QString &cmd_ )
{
    setCallbackFunc( cmd_ );
    addPath( dir );
    setWatchDir( dir );
}