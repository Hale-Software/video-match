#include "view-permissions.h"
#include "ui_view-permissions.h"

VMPermissions::VMPermissions(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::VMPermissions)
{
    ui->setupUi(this);
}

VMPermissions::~VMPermissions()
{
    delete ui;
}
