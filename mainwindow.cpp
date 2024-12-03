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

    /*bool connectionSuccess = connect(scanPage, &ScanPage::requestScan, this, &MainWindow::startScan);
    qDebug() << "Connection for requestScan to startScan established:" << connectionSuccess;*/
    connect(menuPage,  &MenuPage::scan, scanPage, &ScanPage::scanInit);
    connect(scanPage, &ScanPage::requestScan, this, &MainWindow::startScan);
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
    ui->stackedWidget->setCurrentWidget(scanPage);
    appManager->resetScan();
}

void MainWindow::showSwitchProfilePage() {
    ui->stackedWidget->setCurrentWidget(switchProfilePage);
}



// communication functions
void MainWindow::startScan() {
    if (appManager) {
        qDebug() << "Triggering scan...";
        appManager->triggerScan();
    }
}

void MainWindow::advancePoint() {
    bool isLastPoint = (appManager->advancePoint());
    MeasurementPoint currPoint = appManager->getPointInfo();
    int scanPointIndex = currPoint.getID();
    scanPage->updateUI(currPoint, appManager->getActiveProfile()->getLastScan().getValueAt(scanPointIndex - 1)); // replace 2.0 with point data
    if (isLastPoint) {
        scanPage->lastPoint();
    }
}

void MainWindow::resetScan() {
    appManager->resetScan();
}
void MainWindow::activeProfileChanged() {
    menuPage->updateProfileDisplay();

}

