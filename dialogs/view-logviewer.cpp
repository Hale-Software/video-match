#include "view-logviewer.h"
#include "ui_view-logviewer.h"

VMLogViewer::VMLogViewer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::VMLogViewer)
{
    ui->setupUi(this);
}

VMLogViewer::~VMLogViewer()
{
    delete ui;
}
