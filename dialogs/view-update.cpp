#include "view-update.h"
#include "ui_view-update.h"

VMUpdate::VMUpdate(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::VMUpdate)
{
    ui->setupUi(this);
}

VMUpdate::~VMUpdate()
{
    delete ui;
}
