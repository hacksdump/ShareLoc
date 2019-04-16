#include "backgroundbroadcastreceiver.h"

#include <QtWidgets>
#include <QtNetwork>



BackgroundBroadcastReceiver::BackgroundBroadcastReceiver(QWidget *parent) : QWidget(parent)
{

    udpSocket = new QUdpSocket(this);
    udpSocket->bind(45454, QUdpSocket::ShareAddress);

    connect(udpSocket, SIGNAL(readyRead()),
            this, SLOT(processPendingDatagrams()));
}

void BackgroundBroadcastReceiver::processPendingDatagrams()
{
    QByteArray datagram;
    while(udpSocket->hasPendingDatagrams()) {
        datagram.resize(int(udpSocket->pendingDatagramSize()));
        udpSocket->readDatagram(datagram.data(), datagram.size());
        qDebug() << "Receiver: " << datagram.constData();
    }
}
