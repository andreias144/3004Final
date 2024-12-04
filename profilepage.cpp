#include "profilepage.h"
#include "ui_profilepage.h"
#include <QMessageBox>
#include <QSettings>
#include <QIntValidator>
#include <QDoubleValidator>

ProfilePage::ProfilePage(AppManager* appManager, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProfilePage),
    appManager(appManager)
{
    ui->setupUi(this);
    connect(ui->saveButton, &QPushButton::released, this, &ProfilePage::doneButtonClicked);
    connect(ui->cancelButton, &QPushButton::released, this, &ProfilePage::cancelButtonClicked);

    // Valide the data
    ui->ageLineEdit->setValidator(new QIntValidator(1, 150, this));
    ui->weightLineEdit->setValidator(new QDoubleValidator(0.0, 500.0, 2, this));
    ui->heightLineEdit->setValidator(new QDoubleValidator(0.0, 300.0, 2, this));
}

ProfilePage::~ProfilePage()
{
    delete ui;
}

void ProfilePage::doneButtonClicked() {

    QString profileName = ui->nameLineEdit->text().trimmed();
    QString ageText = ui->ageLineEdit->text();
    QString weightText = ui->weightLineEdit->text();
    QString heightText = ui->heightLineEdit->text();

    if (profileName.isEmpty()){
        QMessageBox::warning(this, "Invalid Input", "Please enter a profile name");
        return;
    }

    if (appManager->getProfiles().size() > 4) {
            QMessageBox::warning(this, "Maximum Profiles Reached", "Cannot create more than 5 profiles");
            return;
        }

    //Convert input
    bool ageOk, weightOk, heightOk;
    int age = ageText.toInt(&ageOk);
    double weight = weightText.toDouble(&weightOk);
    double height = heightText.toDouble(&heightOk);

    if (!ageOk || age <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid age");
        return;
    }
    if (!weightOk || weight <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid weight");
        return;
    }
    if (!heightOk || height <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid height");
        return;
    }

    // Verify Uniqeness
    const auto& profiles = appManager->getProfiles();
    for (const auto& profile : profiles) {
        if (profile->getName() == profileName) {
            QMessageBox::warning(this, "Duplicate Profile", "A profile with this name already exists");
            return;
        }
    }

    // Add new profile
    appManager->addProfile(profileName, age, height, weight);

    QMessageBox::information(this, "Profile Saved", "Your profile has been saved successfully.");

    emit backToMenu();
}

void ProfilePage::cancelButtonClicked() {
    emit backToMenu();
}

