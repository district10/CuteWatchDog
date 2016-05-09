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

    QString cmd = "tzxmakeblog";
    ui->lineEdit_callback->setText( cmd );
    dog->setCallbackFunc( cmd );
}

DogHouse::~DogHouse()
{
    delete ui;
}

void DogHouse::on_pushButton_watchdir_clicked()
{
    QString dir =
        QFileDialog::getExistingDirectory( this, tr("Open <dir> for CuteWatchDog to watch."),
                                           QString(),
                                           QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks );
    dog->setWatchDir( dir );
}

void DogHouse::on_pushButton_cmd_clicked()
{
    dog->setCallbackFunc( ui->lineEdit_callback->text().simplified() );
}