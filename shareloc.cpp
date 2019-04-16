#include "shareloc.h"
#include "ui_shareloc.h"
#include "backgroundbroadcastsender.h"

ShareLoc::ShareLoc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ShareLoc)
{
    ui->setupUi(this);
}

ShareLoc::~ShareLoc()
{
    delete ui;
}
