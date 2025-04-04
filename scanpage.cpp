#include "scanpage.h"
#include "ui_scanpage.h"
#include <QDebug>
#include <QMessageBox>

//temp
#include <QFile>

ScanPage::ScanPage(QWidget *parent, QLCDNumber *batteryIndicator) :
    QWidget(parent),
    ui(new Ui::ScanPage)
{
    ui->setupUi(this);

    connect(ui->resultsButton, &QPushButton::released, this, &ScanPage::resultsButtonClicked);
    connect(ui->skinToggleButton, &QPushButton::released, this, &ScanPage::deviceToggled);

    this->batteryIndicator = batteryIndicator;

}

ScanPage::~ScanPage()
{
    delete ui;
}

void ScanPage::scanInit() {
    // set up stackedWidget
    ui->stackedWidget->setCurrentWidget(ui->duringScan);
}


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
    QPixmap pixmap(p.getImagePath());
    QGraphicsPixmapItem *pixmapItem = scene.addPixmap(pixmap);
    ui->imageView->setScene(&scene);
    scene.setSceneRect(pixmapItem->sceneBoundingRect());
    ui->imageView->show();

    // change dot position
    ui->dot->move(p.getPosition());

    ui->value->setText("");
    // update scan data (this won't be shown until the device is on skin)
    currValue = data;

    // update point name
    QString text = "Point " + QString::number(p.getID());
    ui->pointName->setText(text);

}


void ScanPage::deviceToggled() {

    //If the device is on the skin after being toggled
    if (device->toggleOnSkin()) {
        ui->skinToggleButton->setText("Remove off skin");
        ui->skinStatus->setText("Current status : On skin");
        // show scan data
        ui->value->setText("Result: " + QString::number(currValue));
    }

    //If the device is off the skin after being toggled
    else {
        ui->skinToggleButton->setText("Add on skin");
        ui->skinStatus->setText("Current status : Off skin");
        emit nextPoint();
    }

}

void ScanPage::lastPoint() {
    ui->stackedWidget->setCurrentWidget(ui->afterScan);
}


void ScanPage::resultsButtonClicked() {
    emit viewResults();
}


