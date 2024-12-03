#include "scanpage.h"
#include "ui_scanpage.h"
#include <QDebug>


//temp
#include <QFile>

ScanPage::ScanPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScanPage)
{
    ui->setupUi(this);

    connect(ui->resultsButton, &QPushButton::released, this, &ScanPage::resultsButtonClicked);
    connect(ui->skinToggleButton, &QPushButton::released, this, &ScanPage::deviceToggled);

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

    // set up image (change this to only run when necessary)
    scene.clear();
    QPixmap pixmap(p.getImagePath());
    QGraphicsPixmapItem *pixmapItem = scene.addPixmap(pixmap);
    ui->imageView->setScene(&scene);
    scene.setSceneRect(pixmapItem->sceneBoundingRect());
    ui->imageView->show();

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
    }

}

void ScanPage::lastPoint() {
    ui->stackedWidget->setCurrentWidget(ui->afterScan);
}


void ScanPage::resultsButtonClicked() {
    emit viewResults();
}
