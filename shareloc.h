#ifndef SHARELOC_H
#define SHARELOC_H

#include <QMainWindow>

namespace Ui {
class ShareLoc;
}

class ShareLoc : public QMainWindow
{
    Q_OBJECT

public:
    explicit ShareLoc(QWidget *parent = nullptr);
    ~ShareLoc();

private:
    Ui::ShareLoc *ui;
};

#endif // SHARELOC_H
