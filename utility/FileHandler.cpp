#include "FileHandler.h"

FileHandler::FileHandler(QObject *parent) : QObject(parent)
{

}

void FileHandler::startScan(const QString &directory)
{
    QDir rootDir(directory);
    if (!rootDir.exists())
    {
        qDebug() << rootDir.absolutePath() << "does not exist";
        emit scanFailed("Directory does not exist");
        return;
    }

    QDirIterator it(directory, QDir::Files | QDir::NoSymLinks | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);

    while (it.hasNext())
    {
        files.append(it.next());
    }

    qDebug() << "Found " << files.count() << " files";

    emit scanFinished(files);
}
