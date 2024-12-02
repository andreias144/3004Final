#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "menupage.h"
#include "datapage.h"
#include "profilepage.h"
#include "scanpage.h"
#include "switchprofilepage.h"
#include "defs.h"
#include "AppManager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    MenuPage* menuPage;
    DataPage* dataPage;
    ProfilePage* profilePage;
    ScanPage* scanPage;
    SwitchProfilePage* switchProfilePage;
<<<<<<< HEAD

    AppManager* appManager;

    void advancePoint();
    void resetScan();
=======
>>>>>>> ef311ba (added switchprofilepage)

    AppManager* appManager;

    void advancePoint();
    void resetScan();

private slots: // change to private?
    void showProfilePage();
    void showMenuPage();
    void showDataPage();
    void showScanPage();
    void showSwitchProfilePage();
};
#endif // MAINWINDOW_H
