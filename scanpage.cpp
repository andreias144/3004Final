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



    // move dot to cordinate:
    // with every iteration of the scan, appmanager will call a function updateui() on scanpage,
    //  which willl pass in  all of the info as parameters. No scan logic is managed in scanpage.
    // the info can all be represented by a measurementpoint object and a double

    // set up stackedWidget
    ui->stackedWidget->setCurrentWidget(ui->duringScan);

    //Set up skin status
    connect(ui->skinToggleButton, &QPushButton::released, this, [this]() {

        //If the device is on the skin after being toggled
        if (device->toggleOnSkin()) {

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
}

ScanPage::~ScanPage()
{
    delete ui;
}


void ScanPage::updateUI(MeasurementPoint p, double data) {

    // set up image (change this to only run when necessary)
    QPixmap pixmap(p.getImagePath());
    QGraphicsPixmapItem *pixmapItem = scene.addPixmap(pixmap);
    ui->imageView->setScene(&scene);
    scene.setSceneRect(pixmapItem->sceneBoundingRect());
    ui->imageView->show();

}


void ScanPage::resultsButtonClicked() {
    emit viewResults();
}
