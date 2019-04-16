#include "shareloc.h"
#include "ui_shareloc.h"
#include "backgroundbroadcastsender.h"
#include "backgroundbroadcastreceiver.h"
#include <QDebug>
#include <QFile>
#include <QTcpSocket>

ShareLoc::ShareLoc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ShareLoc)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(updateList()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(sendFileToUser()));
}

ShareLoc::~ShareLoc()
{
    delete ui;
}

void ShareLoc::updateList()
{
    ui->listWidget->clear();
    QSet<QString> IPs;
    IPs = sharedData::activeIPs;
    IPs.insert("localhost");
    foreach (const QString &IP, IPs){
        ui->listWidget->addItem(IP);
    }
}
void ShareLoc::sendFileToUser()
{
    QFile file("/home/hmaurya/Downloads/text.txt");
    file.open(QIODevice::ReadOnly);
    QByteArray fdata = file.readAll();
    qDebug() << fdata;
    file.close();
    QTcpSocket *tcpSocket = new QTcpSocket(this);
    tcpSocket->connectToHost("localhost", 12345);
    tcpSocket->write(fdata);
    tcpSocket->close();
}
