#include "switchprofilepage.h"
#include "ui_switchprofilepage.h"

SwitchProfilePage::SwitchProfilePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SwitchProfilePage)
{
    ui->setupUi(this);
    connect(ui->doneButton, &QPushButton::released, this, &SwitchProfilePage::doneButtonClicked);
}

SwitchProfilePage::~SwitchProfilePage()
{
    delete ui;
}

void SwitchProfilePage::doneButtonClicked() {
    emit backToMenu();
}
