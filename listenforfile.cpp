#include "listenforfile.h"

#include <QtWidgets>
#include <QtNetwork>

ListenForFile::ListenForFile(QWidget *parent) : QWidget(parent)
{
    connect(&tcpServer, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
}

void ListenForFile::acceptConnection()
{
    tcpServerConnection = tcpServer.nextPendingConnection();
}
