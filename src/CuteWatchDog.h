#ifndef CUTEWATCHDOG_H
#define CUTEWATCHDOG_H

#include <QWidget>
#include <QFileSystemWatcher>
class QProcess;

class CuteWatchDog : QFileSystemWatcher
{
    Q_OBJECT

private slots:
    void onDirectoryChanged( QString path );
    void onProcessStarted();
    void onReadyRead();
    void onFinished( int );

public:
    CuteWatchDog();
    ~CuteWatchDog();

    void setCallbackFunc( const QString &cb = QString() );
    void setWatchDir( const QString &dir = QString() );
    void watchDirThenRunCmd( const QString &dir, const QString &cmd );

private:
    QString cmd;
    QProcess *process;
};

#endif // CUTEWATCHDOG_H