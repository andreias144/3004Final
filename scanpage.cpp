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

    // set up hand

    QPixmap handPixmap(":/images/hand.png");
    QGraphicsPixmapItem *pixmapItem = handScene.addPixmap(handPixmap);

    ui->handView->setScene(&handScene);
    handScene.setSceneRect(pixmapItem->sceneBoundingRect());
    ui->handView->show();


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

void ScanPage::resultsButtonClicked() {
    emit viewResults();
}
