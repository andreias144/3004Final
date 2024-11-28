#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // create instances of all winndows
    menuPage = new MenuPage(this);
    dataPage = new DataPage(this);

    // connect
    connect(menuPage,  &MenuPage::addProfile, this, &MainWindow::showAddProfile);
    connect(dataPage,  &DataPage::backToMenu, this, &MainWindow::showMenu);

    // add pages to stackedWidget
    ui->stackedWidget->addWidget(menuPage);
    ui->stackedWidget->addWidget(dataPage);

    // set default
    ui->stackedWidget->setCurrentWidget(menuPage);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete menuPage;
    delete dataPage;
}

void MainWindow::showAddProfile() {
    ui->stackedWidget->setCurrentWidget(dataPage);
}

void MainWindow::showMenu() {
    ui->stackedWidget->setCurrentWidget(menuPage);
}

/*
void MainWindow::showScan() {
    cout << "showing scan";
}

void MainWindow::showData() {
    cout << "showing data";
}
*/

