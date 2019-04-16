#include "shareloc.h"
#include "backgroundbroadcastsender.h"
#include <QtConcurrent>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BackgroundBroadcastSender sender;
    ShareLoc w;
    w.show();

    return a.exec();
}
