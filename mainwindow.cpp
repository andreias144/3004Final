#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , appManager(new AppManager())
{
    ui->setupUi(this);

    // create instances of all pages
    menuPage = new MenuPage(appManager, this);
   dataPage = new DataPage(this);
   profilePage = new ProfilePage(appManager, this);
   scanPage = new ScanPage(this);
   switchProfilePage = new SwitchProfilePage(appManager, this);

    // set up page navigation functions:

    // outgoing from menu
    connect(menuPage,  &MenuPage::addProfile, this, &MainWindow::showProfilePage);
    connect(menuPage,  &MenuPage::viewData, this, &MainWindow::showDataPage);
    connect(menuPage,  &MenuPage::scan, this, &MainWindow::showScanPage);
    connect(menuPage,  &MenuPage::switchProfile, this, &MainWindow::showSwitchProfilePage);
    // other navigation
    connect(dataPage,  &DataPage::backToMenu, this, &MainWindow::showMenuPage);
    connect(profilePage,  &ProfilePage::backToMenu, this, &MainWindow::showMenuPage);
    connect(scanPage,  &ScanPage::viewResults, this, &MainWindow::showDataPage);
    connect(switchProfilePage,  &SwitchProfilePage::backToMenu, this, &MainWindow::showMenuPage);

    // set up other communication functions:

    connect(menuPage,  &MenuPage::scan, scanPage, &ScanPage::scanInit);
    connect(scanPage,  &ScanPage::nextPoint, this, &MainWindow::advancePoint);

    // add pages to stackedWidget
    ui->stackedWidget->addWidget(menuPage);
    ui->stackedWidget->addWidget(dataPage);
    ui->stackedWidget->addWidget(profilePage);
    ui->stackedWidget->addWidget(scanPage);
    ui->stackedWidget->addWidget(switchProfilePage);

    // set default
    ui->stackedWidget->setCurrentWidget(profilePage);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete menuPage;
    delete dataPage;
    delete profilePage;
    delete scanPage;
    delete switchProfilePage;
    delete appManager;

}

// page navigation

void MainWindow::showProfilePage() {
    ui->stackedWidget->setCurrentWidget(profilePage);
}

void MainWindow::showMenuPage() {
//     Prevents user from accessing menu if they havent made a profile yet
    if (!appManager->getActiveProfile()) {
        QMessageBox::warning(this, "No Profile", "Create a profile before accessing the menu");
        showProfilePage();
        return;
    }
    menuPage->updateProfileDisplay();
    ui->stackedWidget->setCurrentWidget(menuPage);
}

void MainWindow::showDataPage() {
    ui->stackedWidget->setCurrentWidget(dataPage);
}

void MainWindow::showScanPage() {
    appManager->triggerScan();
    scanPage->scanInit();
    advancePoint();
    ui->stackedWidget->setCurrentWidget(scanPage);
}

void MainWindow::showSwitchProfilePage() {
    ui->stackedWidget->setCurrentWidget(switchProfilePage);
}

void MainWindow::advancePoint() {
    bool isLastPoint = (appManager->advancePoint());
    MeasurementPoint currPoint = appManager->getPointInfo();
    int scanPointIndex = currPoint.getID();
    scanPage->updateUI(currPoint, appManager->getActiveProfile()->getLastScan().getValueAt(scanPointIndex - 1));
    //scanPage->updateUI(currPoint, 2.0);
    if (isLastPoint) {
        scanPage->lastPoint();
    }
}

void MainWindow::activeProfileChanged() {
    menuPage->updateProfileDisplay();

}

