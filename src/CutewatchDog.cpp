#include "CuteWatchDog.h"
#include "DogHouse.h"
#include <QDebug>
#include <QProcess>

void CuteWatchDog::onFileChanged(QString path)
{
    qDebug() << path << " changed";
    if ( !cmd.isEmpty() ) {
        process->start( cmd);
    }
}

void CuteWatchDog::onDirectoryChanged(QString path)
{
    qDebug() << path << " changed";
}

CuteWatchDog::CuteWatchDog()
{
    connect( this, SIGNAL(fileChanged(QString)),
             this, SLOT(onFileChanged(QString)) );
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

void CuteWatchDog::showInfo()
{
    qDebug() << "files are: " << files();
    qDebug() << "directory are: " << directories();
}

void CuteWatchDog::setCallbackFunc(const QString &cb)
{
    cmd = cb;
}

bool CuteWatchDog::setWatchDir(const QString &dir)
{
    addPath( dir );
    showInfo();
    return true;
}

bool CuteWatchDog::setWatchFile(const QString &file)
{
    addPath( file );
    showInfo();
    return true;
}

void CuteWatchDog::watchThenMake(const QString &dir)
{
    cmd = "make";
    addPath( dir );
    qDebug() << "watching dir(" << dir << ") for changes...";
}

void CuteWatchDog::onProcessStarted()
{
}

void CuteWatchDog::onReadyRead()
{
    qDebug() << "\n\n" << process->readAll();
}

void CuteWatchDog::onFinished(int id)
{
}
