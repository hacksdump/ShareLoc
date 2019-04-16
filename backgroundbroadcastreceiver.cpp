#include "backgroundbroadcastreceiver.h"
#include "shareloc.h"

#include <QtWidgets>
#include <QtNetwork>
#include <QSet>
#include <QFileDialog>

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
    QSet<QString> localIPs;
    const QHostAddress &localhost = QHostAddress(QHostAddress::LocalHost);
    for (const QHostAddress &address: QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != localhost){
            localIPs.insert(address.toString());
        }
    }
    while(udpSocket->hasPendingDatagrams()) {
        datagram.resize(int(udpSocket->pendingDatagramSize()));
        udpSocket->readDatagram(datagram.data(), datagram.size());
        QString IPaddr = datagram.constData();
        QHostAddress address(IPaddr);
        if(QAbstractSocket::IPv4Protocol != address.protocol()){
            continue;
        }
        if(localIPs.contains(IPaddr)){
            continue;
        }
        sharedData::activeIPs.insert(IPaddr);
    }
    emit updatedIPs(sharedData::activeIPs);
}
