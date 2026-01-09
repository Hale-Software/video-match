#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <config.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle(QStringLiteral("%1 %2").arg(PRODUCT_NAME).arg(VM_VERSION_STRING));

    //mainTable = new QTableWidget(this);
    //this->setCentralWidget(mainTable);

    createDockWindows();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createStatusBar()
{

}

void MainWindow::createDockWindows()
{
    //dock = new QDockWidget(this);
    //dock->setAllowedAreas(Qt::RightDockWidgetArea);

    //folderListWidget = new FolderListWidget(dock);

    //dock->setWidget(folderListWidget);
}

void MainWindow::createRecentProjects()
{

}

void MainWindow::newProject()
{

}

void MainWindow::openProject()
{

}

void MainWindow::saveProject()
{

}

void MainWindow::recentProject()
{

}

void MainWindow::addFolder()
{

}

void MainWindow::quit()
{

}

void MainWindow::viewFolders()
{

}

void MainWindow::viewAfterScanActions()
{

}

void MainWindow::viewExclusionFilters()
{

}

void MainWindow::viewIgnoreList()
{

}

void MainWindow::viewScan()
{

}

void MainWindow::viewSettings()
{

}

void MainWindow::about()
{

}

void MainWindow::checkForUpdate()
{

}

void MainWindow::help()
{

}

void MainWindow::viewLogs()
{

}
