#ifndef PROFILEPAGE_H
#define PROFILEPAGE_H

#include "AppManager.h"
#include <QWidget>
#include <QString>

namespace Ui {
class ProfilePage;
}

class ProfilePage : public QWidget
{
    Q_OBJECT

public:
    explicit ProfilePage(AppManager* appManager, QWidget *parent = nullptr);
    ~ProfilePage();

private:
    Ui::ProfilePage *ui;
    AppManager* appManager;

signals:
    void backToMenu();

private slots:
    void doneButtonClicked();
    void cancelButtonClicked();

};

#endif // PROFILEPAGE_H
