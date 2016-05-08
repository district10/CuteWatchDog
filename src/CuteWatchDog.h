#ifndef CUTEWATCHDOG_H
#define CUTEWATCHDOG_H

#include <QWidget>
#include <QFileSystemWatcher>
class QProcess;

class CuteWatchDog : QFileSystemWatcher
{
    Q_OBJECT

private slots:
    void onFileChanged( QString path );
    void onDirectoryChanged( QString path );

    void onProcessStarted();
    void onReadyRead();
    void onFinished( int );

public:
    CuteWatchDog();
    ~CuteWatchDog();

    void showInfo();
    void setCallbackFunc( const QString &cb = QString() );
    bool setWatchDir( const QString &dir = QString() );
    bool setWatchFile( const QString &file = QString() );

    void watchThenMake( const QString &dir );

private:
    QString cmd;
    QProcess *process;
};

#endif // CUTEWATCHDOG_H
