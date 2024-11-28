#include "menupage.h"
#include "ui_menupage.h"

MenuPage::MenuPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuPage)
{
    ui->setupUi(this);

    // connect
    connect(ui->addProfileButton, &QPushButton::released, this, &MenuPage::addProfileButtonClicked);
    /*
    connect(ui->switchProfileButton, &QPushButton::released, this, &MenuPage::switchProfile);
    connect(ui->scanButton, &QPushButton::released, this, &MenuPage::scan);
    connect(ui->viewDataButton, &QPushButton::released, this, &MenuPage::viewData);
    */
}

MenuPage::~MenuPage()
{
    delete ui;
}

void MenuPage::addProfileButtonClicked() {
    emit addProfile(); // signal to  MainWindow
}

/*
void MenuPage::switchProfile() {

}


void MenuPage::scan() {

}


void MenuPage::viewData() {

}
*/
