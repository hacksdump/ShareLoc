#include "shareloc.h"
#include "ui_shareloc.h"
#include "backgroundbroadcastsender.h"
#include "backgroundbroadcastreceiver.h"
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QTcpSocket>

ShareLoc::ShareLoc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ShareLoc)
{
    ui->setupUi(this);
    //connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(updateList()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(sendFileToUser()));
    BackgroundBroadcastReceiver *recv = new BackgroundBroadcastReceiver();
    connect(recv, SIGNAL(updatedIPs(QSet<QString>)), this, SLOT(updateList(QSet<QString>)));
}

ShareLoc::~ShareLoc()
{
    delete ui;
}

void ShareLoc::updateList(QSet<QString> IPs)
{
    ui->listWidget->clear();
    foreach (const QString &IP, IPs){
        ui->listWidget->addItem(IP);
    }
}
void ShareLoc::sendFileToUser()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Text"), "/home/", tr("Text Files (*.txt)"));
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    QByteArray fdata = file.readAll();
    file.close();
    QTcpSocket *tcpSocket = new QTcpSocket(this);
    tcpSocket->connectToHost("localhost", 12345);
    tcpSocket->write(fdata);
    tcpSocket->close();
}
