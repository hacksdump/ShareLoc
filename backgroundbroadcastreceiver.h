#ifndef BACKGROUNDBROADCASTRECEIVER_H
#define BACKGROUNDBROADCASTRECEIVER_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QUdpSocket;
QT_END_NAMESPACE

class BackgroundBroadcastReceiver : public QWidget
{
    Q_OBJECT
public:
    explicit BackgroundBroadcastReceiver(QWidget *parent = nullptr);

private slots:
    void processPendingDatagrams();

signals:
    void updatedIPs(QSet<QString>);

private:
    QUdpSocket *udpSocket = nullptr;
};

#endif
