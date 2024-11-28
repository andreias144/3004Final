#include "menupage.h"
#include "ui_menupage.h"

MenuPage::MenuPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuPage)
{
    ui->setupUi(this);

    // set up main menu navigation buttons
    connect(ui->addProfileButton, &QPushButton::released, this, &MenuPage::addProfileButtonClicked);
    connect(ui->viewDataButton, &QPushButton::released, this, &MenuPage::dataButtonClicked);
    connect(ui->scanButton, &QPushButton::released, this, &MenuPage::scanButtonClicked);

}

MenuPage::~MenuPage()
{
    delete ui;
}

void MenuPage::addProfileButtonClicked() {
    emit addProfile();
}

void MenuPage::dataButtonClicked() {
    emit viewData();
}

void MenuPage::scanButtonClicked() {
    emit scan();
}
