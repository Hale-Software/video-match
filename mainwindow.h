#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include <QStringLiteral>
#include <QSettings>
#include <QTableWidget>

#include "widgets/folderlist-widget.h"
#include "utility/FileHandler.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void newProject();
    void openProject();
    void saveProject();
    void recentProject();
    void addFolder();
    void quit();
    void viewFolders();
    void viewAfterScanActions();
    void viewExclusionFilters();
    void viewIgnoreList();
    void viewScan();
    void viewSettings();
    void about();
    void checkForUpdate();
    void help();
    void viewLogs();

private:
    void createStatusBar();
    void createDockWindows();
    void createRecentProjects();

    Ui::MainWindow *ui;
    QDockWidget* dock;
    QTableWidget *mainTable;
    FolderListWidget *folderListWidget;

};
#endif // MAINWINDOW_H
