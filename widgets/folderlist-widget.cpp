// You may need to build the project (run Qt uic code generator) to get "ui_folderlist-widget.h" resolved

#include "folderlist-widget.h"
#include "ui_folderlist-widget.h"


FolderListWidget::FolderListWidget(QWidget *parent) : QWidget(parent), ui(new Ui::FolderListWidget)
{
    ui->setupUi(this);
}

FolderListWidget::~FolderListWidget()
{
    delete ui;
}