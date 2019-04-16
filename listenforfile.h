#ifndef LISTENFORFILE_H
#define LISTENFORFILE_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
class QTcpServer;
class QTcpSocket;
QT_END_NAMESPACE

class ListenForFile : public QWidget
{
    Q_OBJECT
public:
    explicit ListenForFile(QWidget *parent = nullptr);

public slots:
    void acceptConnection();

private:
    QTcpServer tcpServer;
    QTcpSocket *tcpServerConnection;
};

#endif // LISTENFORFILE_H
