#include "view-about.h"
#include "ui_view-about.h"

VMAbout::VMAbout(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::VMAbout)
{
    ui->setupUi(this);
}

VMAbout::~VMAbout()
{
    delete ui;
}
