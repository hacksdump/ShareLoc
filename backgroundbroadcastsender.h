#ifndef BACKGROUNDBROADCASTSENDER_H
#define BACKGROUNDBROADCASTSENDER_H

#include <QTimer>
#include <QWidget>

QT_BEGIN_NAMESPACE
class QUdpSocket;
QT_END_NAMESPACE

class BackgroundBroadcastSender : public QWidget
{
public:
    explicit BackgroundBroadcastSender(QWidget *parent = nullptr);

private slots:
    void startBroadcasting();
    void broadcastDatagram();

private:
    QUdpSocket *udpSocket = nullptr;
    QTimer timer;
};

#endif
