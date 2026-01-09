#include "view-settings.h"
#include "ui_view-settings.h"

VMSettings::VMSettings(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::VMSettings)
{
    ui->setupUi(this);
}

VMSettings::~VMSettings()
{
    delete ui;
}
