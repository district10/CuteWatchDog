#include "DogHouse.h"
#include "CuteWatchDog.h"
#include "ui_DogHouse.h"
#include <QDebug>
#include <QFileDialog>

DogHouse::DogHouse(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DogHouse),
    dog(new CuteWatchDog)
{
    ui->setupUi(this);

    ui->lineEdit_callback->setText( "input your command." );

    // QProcess::readAllStandardError()
    // process->setStandardOutputFile( "stdout.txt", QIODevice::Append );
    // process->setStandardErrorFile( "stderr.txt", QIODevice::Append );

    // QProcessEnvironment env;
    // env.insert("PATH", "C:/Users/Administrator/Documents/build-DogHouse-NTFS-Debug");
    // process->setProcessEnvironment(env);


}

DogHouse::~DogHouse()
{
    delete ui;
}

void DogHouse::on_pushButton_watchfile_clicked()
{
    QString file =
        QFileDialog::getOpenFileName( this, tr("Open <file> for CuteWatchDog to watch."),
                                      QString(),
                                      QString(),
                                      new QString,
                                      (QFileDialog::Options)QFileDialog::ExistingFile );
    if ( dog->setWatchFile( file ) ) {
        ui->pushButton_watchdir->setDisabled( true );
        ui->pushButton_watchfile->setDisabled( true );
    }
}

void DogHouse::on_pushButton_watchdir_clicked()
{
    QString dir =
        QFileDialog::getExistingDirectory( this, tr("Open <dir> for CuteWatchDog to watch."),
                                           QString(),
                                           QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks );
    if ( dog->setWatchDir( dir ) ) {
        ui->pushButton_watchdir->setDisabled( true );
        ui->pushButton_watchfile->setDisabled( true );
    }
}

void DogHouse::on_pushButton_cmd_clicked()
{
    dog->setCallbackFunc( ui->lineEdit_callback->text() );
}
