#include "backgroundbroadcastsender.h"
#include <QtNetwork>
#include <QtCore>
#include <QNetworkInterface>

BackgroundBroadcastSender::BackgroundBroadcastSender(QWidget *parent) : QWidget(parent)
{
    udpSocket = new QUdpSocket(this);
    connect(&timer, &QTimer::timeout, this, &BackgroundBroadcastSender::broadcastDatagram);
    BackgroundBroadcastSender::startBroadcasting();
}

void BackgroundBroadcastSender::startBroadcasting()
{
    timer.start(1000);
}

void BackgroundBroadcastSender::broadcastDatagram()
{
    QByteArray datagram;
    const QHostAddress &localhost = QHostAddress(QHostAddress::LocalHost);
    for (const QHostAddress &address: QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != localhost)
             datagram =  address.toString().toUtf8();
             udpSocket->writeDatagram(datagram, QHostAddress::Broadcast, 45454);
    };


}
