#include "switchprofilepage.h"
#include "ui_switchprofilepage.h"


SwitchProfilePage::SwitchProfilePage(AppManager* appManager, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SwitchProfilePage),
    appManager(appManager)
{
    ui->setupUi(this);
    connect(ui->doneButton, &QPushButton::released, this, &SwitchProfilePage::doneButtonClicked);
    connect(ui->switchButton, &QPushButton::clicked, this, &SwitchProfilePage::switchButtonClicked);

    ui->switchButton->setEnabled(false);

    loadProfiles();

    connect(ui->profileListWidget, &QListWidget::currentItemChanged, this, &SwitchProfilePage::profileSelectionChanged);

}

SwitchProfilePage::~SwitchProfilePage()
{
    delete ui;
}

void SwitchProfilePage::doneButtonClicked() {
    emit backToMenu();
}



void SwitchProfilePage::loadProfiles()
{
    // Clear any prev input from past profile
    ui->profileListWidget->clear();

    const auto& profiles = appManager->getProfiles();
    for (size_t i = 0; i < profiles.size(); ++i) {
        QListWidgetItem* item = new QListWidgetItem(profiles[i]->getName());
        item->setData(Qt::UserRole, static_cast<int>(i));
        ui->profileListWidget->addItem(item);
    }
}

void SwitchProfilePage::profileSelectionChanged()
{
    QListWidgetItem* selectedItem = ui->profileListWidget->currentItem();
    ui->switchButton->setEnabled(selectedItem != nullptr);
}

void SwitchProfilePage::switchButtonClicked()
{
    QListWidgetItem* selectedItem = ui->profileListWidget->currentItem();
    if (selectedItem) {
        int index = selectedItem->data(Qt::UserRole).toInt();
        appManager->switchActiveProfile(index);
        emit profileSwitched();
        emit backToMenu();
    }
}

// This function refreshes the page everytime its displayed
void SwitchProfilePage::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
    loadProfiles();
}

