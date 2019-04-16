#ifndef SHARELOC_H
#define SHARELOC_H

#include <QMainWindow>
#include <QSet>
#include <QTimer>

namespace Ui {
class ShareLoc;
}

namespace sharedData {
    static QSet<QString> activeIPs;
}

class ShareLoc : public QMainWindow
{
    Q_OBJECT

public:
    explicit ShareLoc(QWidget *parent = nullptr);
    ~ShareLoc();

private:
    Ui::ShareLoc *ui;
    QTimer timer;

private slots:
    void updateList();
    void sendFileToUser();
};

#endif // SHARELOC_H
