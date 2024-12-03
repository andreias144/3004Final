#include "scanpage.h"
#include "ui_scanpage.h"
#include <QMessageBox>

//temp
#include <QFile>

ScanPage::ScanPage(QWidget *parent, QLCDNumber *batteryIndicator) :
    QWidget(parent),
    ui(new Ui::ScanPage)
{
    ui->setupUi(this);

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 87d9ca6 (scan loop works but only updates image and dot)
    connect(ui->resultsButton, &QPushButton::released, this, &ScanPage::resultsButtonClicked);
    //Set up skin status
    connect(ui->skinToggleButton, &QPushButton::released, this, &ScanPage::deviceToggled);

<<<<<<< HEAD
<<<<<<< HEAD
    // set up stackedWidget
    ui->stackedWidget->setCurrentWidget(ui->duringScan);

<<<<<<< HEAD
<<<<<<< HEAD
    this->batteryIndicator = batteryIndicator;

<<<<<<< HEAD
=======
    this->batteryIndicator = batteryIndicator;

>>>>>>> a63c1e3 (Fixed bug with first image not showing, added battery depletion feature)

    // call performScan on Scanner (TODO)
    // this pregenerates the data

    // advance the scan to point 1:
    emit nextPoint();
=======
=======
    // set up image (temp)
    QPixmap handPixmap(":/images/imageLH.png");
    QGraphicsPixmapItem *pixmapItem = handScene.addPixmap(handPixmap);
>>>>>>> 503b51a (added images, minor ui changes, some comments in scanpage.cpp)
    ui->handView->setScene(&handScene);
    handScene.setSceneRect(pixmapItem->sceneBoundingRect());
    ui->handView->show();
=======

>>>>>>> 10ed055 (working but incomplete ScanPage->updateUI())

    // move dot to cordinate:
    // with every iteration of the scan, appmanager will call a function updateui() on scanpage,
    //  which willl pass in  all of the info as parameters. No scan logic is managed in scanpage.
    // the info can all be represented by a measurementpoint object and a double

=======
>>>>>>> 87d9ca6 (scan loop works but only updates image and dot)
=======
>>>>>>> bbbc7df (scan loop working with a few bugs (but it doesn't crash))
    // set up stackedWidget
    ui->stackedWidget->setCurrentWidget(ui->duringScan);

    // call performScan on Scanner (TODO)
    // this pregenerates the data

<<<<<<< HEAD
    // start scan

<<<<<<< HEAD
            ui->skinToggleButton->setText("Remove off skin");
            ui->skinStatus->setText("Current status : On skin");
        }

        //If the device is off the skin after being toggled
        else {

            ui->skinToggleButton->setText("Add on skin");
            ui->skinStatus->setText("Current status : Off skin");
            ui->stackedWidget->setCurrentWidget(ui->afterScan);
        }
    });
>>>>>>> 36ca08a (working mid-integration of on/off skin toggle and scan page ui)
=======
=======
    // advance the scan to point 1:
>>>>>>> bbbc7df (scan loop working with a few bugs (but it doesn't crash))
    emit nextPoint();
>>>>>>> 87d9ca6 (scan loop works but only updates image and dot)
}

ScanPage::~ScanPage()
{
    delete ui;
}


<<<<<<< HEAD
<<<<<<< HEAD
void ScanPage::updateUI(MeasurementPoint p, double data) {


    //Adjust battery value
    this->batteryIndicator->display(device->decreaseBatteryLevel());

    if (device->getBatteryLevel() == 0) {

        QMessageBox::warning(this, "Device out of battery", "The RadoTech device is out of battery. Please charge the device before attempting to scan.");
        emit scanOver();

        //Go to menu
        emit returnToMainWindow();
    }

    else if (device->getBatteryLevel() == 20) {
        QMessageBox::warning(this, "Device battery level low", "The RadoTech device battery level is currently low. Please charge the device.");
    }


    // set up image (change this to only run when necessary)
    scene.clear();
=======
void ScanPage::updateUI(MeasurementPoint p, double data) {

    // set up image (change this to only run when necessary)
<<<<<<< HEAD
>>>>>>> 10ed055 (working but incomplete ScanPage->updateUI())
=======
    scene.clear();
>>>>>>> 87d9ca6 (scan loop works but only updates image and dot)
    QPixmap pixmap(p.getImagePath());
    QGraphicsPixmapItem *pixmapItem = scene.addPixmap(pixmap);
    ui->imageView->setScene(&scene);
    scene.setSceneRect(pixmapItem->sceneBoundingRect());
    ui->imageView->show();

<<<<<<< HEAD
<<<<<<< HEAD
    // change dot position
    ui->dot->move(p.getPosition());

    // update point name
    QString text = "Point " + QString::number(p.getID());
    ui->pointName->setText(text);

}


void ScanPage::deviceToggled() {

    //If the device is on the skin after being toggled
    if (device->toggleOnSkin()) {

        ui->skinToggleButton->setText("Remove off skin");
        ui->skinStatus->setText("Current status : On skin");
    }

    //If the device is off the skin after being toggled
    else {
        ui->skinToggleButton->setText("Add on skin");
        ui->skinStatus->setText("Current status : Off skin");
        emit nextPoint();
<<<<<<< HEAD
    }

}

void ScanPage::lastPoint() {
    ui->stackedWidget->setCurrentWidget(ui->afterScan);
=======
    // change dot position
    ui->dot->move(p.getPosition());

>>>>>>> 665a168 (added variable dot position)
}


<<<<<<< HEAD
=======
void ScanPage::deviceToggled() {

    //If the device is on the skin after being toggled
    if (device->toggleOnSkin()) {

        ui->skinToggleButton->setText("Remove off skin");
        ui->skinStatus->setText("Current status : On skin");
    }

    //If the device is off the skin after being toggled
    else {
        ui->skinToggleButton->setText("Add on skin");
        ui->skinStatus->setText("Current status : Off skin");
        emit nextPoint();
        //ui->stackedWidget->setCurrentWidget(ui->afterScan); // temp
=======
>>>>>>> bbbc7df (scan loop working with a few bugs (but it doesn't crash))
    }

}

void ScanPage::lastPoint() {
    ui->stackedWidget->setCurrentWidget(ui->afterScan);
}


>>>>>>> 87d9ca6 (scan loop works but only updates image and dot)
void ScanPage::resultsButtonClicked() {
    emit scanOver();
    ui->stackedWidget->setCurrentWidget(ui->duringScan); // reset stackedWidget
    emit viewResults();

<<<<<<< HEAD
=======
=======
}


>>>>>>> 10ed055 (working but incomplete ScanPage->updateUI())
void ScanPage::resultsButtonClicked() {
    emit viewResults();
>>>>>>> 503b51a (added images, minor ui changes, some comments in scanpage.cpp)
=======
>>>>>>> 87d9ca6 (scan loop works but only updates image and dot)
}
