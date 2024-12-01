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
}

ScanPage::~ScanPage()
{
    delete ui;
}

void ScanPage::resultsButtonClicked() {
    emit viewResults();
}
