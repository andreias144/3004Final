#ifndef MENUPAGE_H
#define MENUPAGE_H

#include <QWidget>
#include "defs.h"
#include "AppManager.h"

namespace Ui {
class MenuPage;
}

class MenuPage : public QWidget
{
    Q_OBJECT

public:
    explicit MenuPage(AppManager* appManager, QWidget *parent = nullptr);
    ~MenuPage();
    void updateProfileDisplay();

private:
    Ui::MenuPage *ui;
    AppManager* appManager;

signals:
    void addProfile();
    void viewData();
    void scan();
    void switchProfile();

private slots:
    void addProfileButtonClicked();
    void dataButtonClicked();
    void scanButtonClicked();
    void switchProfileButtonClicked();
};

#endif // MENUPAGE_H
