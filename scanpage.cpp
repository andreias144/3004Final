#include "scanpage.h"
#include "ui_scanpage.h"

//temp
#include <QFile>

ScanPage::ScanPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScanPage)
{
    ui->setupUi(this);

    connect(ui->resultsButton, &QPushButton::released, this, &ScanPage::resultsButtonClicked);
    //Set up skin status
    connect(ui->skinToggleButton, &QPushButton::released, this, &ScanPage::deviceToggled);


    // set up stackedWidget
    ui->stackedWidget->setCurrentWidget(ui->duringScan);

    // call performScan on Scanner (TODO)
    // this pregenerates the data

    // start scan

    emit nextPoint();
}

ScanPage::~ScanPage()
{
    delete ui;
}


void ScanPage::updateUI(MeasurementPoint p, double data) {

    // set up image (change this to only run when necessary)
    scene.clear();
    QPixmap pixmap(p.getImagePath());
    QGraphicsPixmapItem *pixmapItem = scene.addPixmap(pixmap);
    ui->imageView->setScene(&scene);
    scene.setSceneRect(pixmapItem->sceneBoundingRect());
    ui->imageView->show();

    // change dot position
    ui->dot->move(p.getPosition());

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
        //ui->stackedWidget->setCurrentWidget(ui->afterScan); // temp
    }

}

void ScanPage::lastPoint() {
    ui->stackedWidget->setCurrentWidget(ui->afterScan);
}


void ScanPage::resultsButtonClicked() {
    emit scanOver();
    ui->stackedWidget->setCurrentWidget(ui->duringScan); // reset stackedWidget
    emit viewResults();

}
