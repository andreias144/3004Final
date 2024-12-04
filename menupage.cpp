#include "menupage.h"
#include "ui_menupage.h"

MenuPage::MenuPage(AppManager* appManager, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuPage),
    appManager(appManager)
{
    ui->setupUi(this);

    // set up main menu navigation buttons
    connect(ui->addProfileButton, &QPushButton::released, this, &MenuPage::addProfileButtonClicked);
    connect(ui->viewDataButton, &QPushButton::released, this, &MenuPage::dataButtonClicked);
    connect(ui->scanButton, &QPushButton::released, this, &MenuPage::scanButtonClicked);
    connect(ui->switchProfileButton, &QPushButton::released, this, &MenuPage::switchProfileButtonClicked);

    updateProfileDisplay();
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

void MenuPage::switchProfileButtonClicked() {
    emit switchProfile();
}


void MenuPage::updateProfileDisplay()
{
    Profile* activeProfile = appManager->getActiveProfile();
    if (activeProfile) {
        ui->currentProfileLabel->setText("Current Profile: " + activeProfile->getName());
    } else {
        ui->currentProfileLabel->setText("Current Profile: None");
    }
}
