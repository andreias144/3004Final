#ifndef MENUPAGE_H
#define MENUPAGE_H

#include <QWidget>
#include "defs.h"

namespace Ui {
class MenuPage;
}

class MenuPage : public QWidget
{
    Q_OBJECT

public:
    explicit MenuPage(QWidget *parent = nullptr);
    ~MenuPage();

private:
    Ui::MenuPage *ui;

signals:
    void addProfile();
    //void switchProfile();
    //void scan();
    //void viewData();

private slots:
    void addProfileButtonClicked();
};

#endif // MENUPAGE_H
