#ifndef VIEW_UPDATE_H
#define VIEW_UPDATE_H

#include <QDialog>

namespace Ui {
class VMUpdate;
}

class VMUpdate : public QDialog
{
    Q_OBJECT

public:
    explicit VMUpdate(QWidget *parent = nullptr);
    ~VMUpdate();

private:
    Ui::VMUpdate *ui;
};

#endif // VIEW_UPDATE_H
