#include "shareloc.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ShareLoc w;
    w.show();

    return a.exec();
}
