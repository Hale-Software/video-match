#ifndef VIEW_LOGVIEWER_H
#define VIEW_LOGVIEWER_H

#include <QDialog>

namespace Ui {
class VMLogViewer;
}

class VMLogViewer : public QDialog
{
    Q_OBJECT

public:
    explicit VMLogViewer(QWidget *parent = nullptr);
    ~VMLogViewer();

private:
    Ui::VMLogViewer *ui;
};

#endif // VIEW_LOGVIEWER_H
