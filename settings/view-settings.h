#ifndef VIEW_SETTINGS_H
#define VIEW_SETTINGS_H

#include <QDialog>

namespace Ui {
class VMSettings;
}

class VMSettings : public QDialog
{
    Q_OBJECT

public:
    explicit VMSettings(QWidget *parent = nullptr);
    ~VMSettings();

private:
    Ui::VMSettings *ui;
};

#endif // VIEW_SETTINGS_H
