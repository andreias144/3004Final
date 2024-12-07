#include "datapage.h"
#include "ui_datapage.h"

DataPage::DataPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataPage)
{
    ui->setupUi(this);
    connect(ui->menuButton, &QPushButton::released, this, &DataPage::menuButtonClicked);

    // set default widget (temp for debugging)
    ui->stackedWidget->setCurrentWidget(ui->data);

    setupOrganTable();
    loadHeatmap(); // temp
}

DataPage::~DataPage()
{
    delete ui;
}

void DataPage::menuButtonClicked() {
    emit backToMenu();
}

void DataPage::setupOrganTable() {


    content = new QStandardItemModel(NUM_ORGANS, 3, this);

    for (int i = 0; i < NUM_ORGANS; i++) {

        // set organ picture
        QPixmap organ(":/images/1-lungs.png"); //temp
        QStandardItem* imageItem = new QStandardItem;
        imageItem->setIcon(organ);
        content->setItem(i, 0, imageItem);

        // set organ text
        QStandardItem* organText = new QStandardItem("Lungs"); //temp
        content->setItem(i, 1, organText);

    }

    // remove default headers
    ui->organTable->verticalHeader()->setVisible(false);
    ui->organTable->horizontalHeader()->setVisible(false);

    ui->organTable->setModel(content);
    ui->organTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // set column sizes
    ui->organTable->setColumnWidth(0, 30); // First column width
    ui->organTable->setColumnWidth(1, 100); // Second column width

}

void DataPage::loadForNewProfile(Profile* p) {

}

void DataPage::addScan() {

}

void DataPage::loadHeatmap() {

    for (int i = 0; i < NUM_ORGANS; i++) {

        // set heatmap
        QStandardItem* heatmapItem = new QStandardItem;
        heatmapItem->setBackground(Average); //temp
        content->setItem(i, 2, heatmapItem);

    }

}
