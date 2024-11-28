#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "menupage.h"
#include "datapage.h"
#include "profilepage.h"
#include "scanpage.h"
#include "defs.h"

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

private slots: // change to private?
    void showProfilePage();
    void showMenuPage();
    void showDataPage();
    void showScanPage();
};
#endif // MAINWINDOW_H
