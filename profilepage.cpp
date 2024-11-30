#include "profilepage.h"
#include "ui_profilepage.h"
#include <QMessageBox>
#include <QSettings>
#include <QIntValidator>
#include <QDoubleValidator>

ProfilePage::ProfilePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProfilePage)
{
    ui->setupUi(this);
    connect(ui->saveButton, &QPushButton::released, this, &ProfilePage::doneButtonClicked);

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

    if (getProfileCount() >= 5) {
        QMessageBox::warning(this, "Maximum Profiles Reached", "You cannot create more than 5 profiles");
        return;
        }

    bool ageOk;
        int age = ageText.toInt(&ageOk);
        if (!ageOk || age <= 0) {
            QMessageBox::warning(this, "Invalid Input", "Please enter a valid age");
            return;
        }

    bool weightOk;
        double weight = weightText.toDouble(&weightOk);
        if (!weightOk || weight <= 0) {
            QMessageBox::warning(this, "Invalid Input", "Please enter a valid weight");
            return;
        }

    bool heightOk;
        double height = heightText.toDouble(&heightOk);
        if (!heightOk || height <= 0) {
            QMessageBox::warning(this, "Invalid Input", "Please enter a valid height");
            return;
        }

    saveProfileData(profileName, age, weight, height);

    QMessageBox::information(this, "Profile Saved", "Your profile has been saved successfully.");

    emit backToMenu();
}


void ProfilePage::saveProfileData(const QString& profileName, int age, double weight, double height) {
    // Create qsettings object, provides storage for application
    QSettings settings("RadoTech", "OurApp");

    // Keys will be stored under userporfile group
    settings.beginGroup("UserProfile");
    settings.beginGroup(profileName);
    settings.setValue("Age", age);
    settings.setValue("Weight", weight);
    settings.setValue("Height", height);
    settings.endGroup();
    settings.endGroup();
}

/* To access values stored, use the following code:
 * QSettings settings("RadoTech", "OurApp");
    settings.beginGroup("UserProfile");
    settings.beginGroup(profileName);
    int age = settings.value("Age").toInt();
    double weight = settings.value("Weight").toDouble();
    double height = settings.value("Height").toDouble();
    settings.endGroup();
    settings.endGroup();
*/



bool ProfilePage::isProfileNameUnique(const QString& profileName) {
    QSettings settings("RadoTech", "OurApp");
    settings.beginGroup("UserProfiles");
    bool exists = settings.childGroups().contains(profileName);
    settings.endGroup();

    // Returns true if it is unique
    return !exists;
}


int ProfilePage::getProfileCount() {
    QSettings settings("RadoTech", "OurApp");
    settings.beginGroup("UserProfiles");
    int count = settings.childGroups().size();
    settings.endGroup();
    return count;
}
