#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "menupage.h"
#include "datapage.h"
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

public slots: // change to private?
    void showAddProfile();
    void showMenu();
    //void showScan();
    //void showData();
};
#endif // MAINWINDOW_H
