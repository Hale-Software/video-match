#ifndef VIEW_ABOUT_H
#define VIEW_ABOUT_H

#include <QDialog>

namespace Ui {
class VMAbout;
}

class VMAbout : public QDialog
{
    Q_OBJECT

public:
    explicit VMAbout(QWidget *parent = nullptr);
    ~VMAbout();

private:
    Ui::VMAbout *ui;
};

#endif // VIEW_ABOUT_H
