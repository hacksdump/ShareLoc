#include "shareloc.h"
#include "backgroundbroadcastsender.h"
#include "backgroundbroadcastreceiver.h"
#include <QtConcurrent>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BackgroundBroadcastSender sender;
    BackgroundBroadcastReceiver receiver;
    ShareLoc w;
    w.show();

    return a.exec();
}
