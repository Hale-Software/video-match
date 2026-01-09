#ifndef VIEW_PERMISSIONS_H
#define VIEW_PERMISSIONS_H

#include <QDialog>

namespace Ui {
class VMPermissions;
}

class VMPermissions : public QDialog
{
    Q_OBJECT

public:
    explicit VMPermissions(QWidget *parent = nullptr);
    ~VMPermissions();

private:
    Ui::VMPermissions *ui;
};

#endif // VIEW_PERMISSIONS_H
