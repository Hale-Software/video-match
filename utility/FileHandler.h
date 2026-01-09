#ifndef VIDEO_MATCH_FILEHANDLER_H
#define VIDEO_MATCH_FILEHANDLER_H

#include <QObject>
#include <QFile>
#include <QDirIterator>
#include <QStringList>
#include <QDebug>


class FileHandler : public QObject
{
    Q_OBJECT

public:
    explicit FileHandler(QObject *parent = nullptr);

public slots:
    void startScan(const QString &directory);

signals:
    void scanFinished(const QStringList &files);
    void scanFailed(const QString &errorMessage);

private:
    QStringList files;

};

#endif //VIDEO_MATCH_FILEHANDLER_H