#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // create instances of all pages
    menuPage = new MenuPage(this);
    dataPage = new DataPage(this);
    profilePage = new ProfilePage(this);
    scanPage = new ScanPage(this, ui->batteryIndicator);
    switchProfilePage = new SwitchProfilePage(this);

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
    connect(scanPage,  &ScanPage::returnToMainWindow, this, &MainWindow::showMenuPage);
    connect(switchProfilePage,  &SwitchProfilePage::backToMenu, this, &MainWindow::showMenuPage);

    // set up other communication functions:
    connect(scanPage,  &ScanPage::nextPoint, this, &MainWindow::advancePoint);
    connect(scanPage,  &ScanPage::scanOver, this, &MainWindow::resetScan);

    // add pages to stackedWidget
    ui->stackedWidget->addWidget(menuPage);
    ui->stackedWidget->addWidget(dataPage);
    ui->stackedWidget->addWidget(profilePage);
    ui->stackedWidget->addWidget(scanPage);
    ui->stackedWidget->addWidget(switchProfilePage);

    // set default
    ui->stackedWidget->setCurrentWidget(menuPage);

    //Set default battery value (100)
    ui->batteryIndicator->display(100);

    // set up appmanager
    appManager = new AppManager();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete menuPage;
    delete dataPage;
    delete scanPage;
    delete profilePage;
    delete switchProfilePage;
    delete appManager;
}

// page navigation

void MainWindow::showProfilePage() {
    ui->stackedWidget->setCurrentWidget(profilePage);
}

void MainWindow::showMenuPage() {
    ui->stackedWidget->setCurrentWidget(menuPage);
}

void MainWindow::showDataPage() {
    ui->stackedWidget->setCurrentWidget(dataPage);
}

void MainWindow::showScanPage() {
    ui->stackedWidget->setCurrentWidget(scanPage);
    appManager->resetScan();
    scanPage->updateUI(appManager->getPointInfo(), 2.0); // replace 2.0 with point data for the first point

}

void MainWindow::showSwitchProfilePage() {
    ui->stackedWidget->setCurrentWidget(switchProfilePage);
}


// communication functions

void MainWindow::advancePoint() {
    bool isLastPoint = (appManager->advancePoint());
    scanPage->updateUI(appManager->getPointInfo(), 2.0); // replace 2.0 with point data
    if (isLastPoint) {
        scanPage->lastPoint();
    }
}

void MainWindow::resetScan() {
    appManager->resetScan();
}

