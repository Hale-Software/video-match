#ifndef VIDEO_MATCH_FOLDERLIST_WIDGET_H
#define VIDEO_MATCH_FOLDERLIST_WIDGET_H

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui
{
    class FolderListWidget;
}

QT_END_NAMESPACE

class FolderListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FolderListWidget(QWidget *parent = nullptr);

    ~FolderListWidget() override;

private:
    Ui::FolderListWidget *ui;
};


#endif //VIDEO_MATCH_FOLDERLIST_WIDGET_H