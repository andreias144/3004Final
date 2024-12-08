#include "datapage.h"
#include "ui_datapage.h"

DataPage::DataPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataPage)
{
    ui->setupUi(this);
    connect(ui->menuButton, &QPushButton::released, this, &DataPage::menuButtonClicked);

    // set default widget
    ui->stackedWidget->setCurrentWidget(ui->noData);

    setupOrganTable();
    scanListContent = new QStandardItemModel(this);
}

DataPage::~DataPage()
{
    delete ui;
}

void DataPage::menuButtonClicked() {
    emit backToMenu();
}

void DataPage::setupOrganTable() {


    organTableContent = new QStandardItemModel(NUM_ORGANS, 3, this);

    for (int i = 0; i < NUM_ORGANS; i++) {

        // set organ picture
        QPixmap organ(":/images/1-lungs.png"); //temp
        QStandardItem* imageItem = new QStandardItem;
        imageItem->setIcon(organ);
        organTableContent->setItem(i, 0, imageItem);

        // set organ text
        QStandardItem* organText = new QStandardItem("Lungs"); //temp
        organTableContent->setItem(i, 1, organText);

    }

    // remove default headers
    ui->organTable->verticalHeader()->setVisible(false);
    ui->organTable->horizontalHeader()->setVisible(false);

    ui->organTable->setModel(organTableContent);
    ui->organTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // set column sizes
    ui->organTable->setColumnWidth(0, 30); // First column width
    ui->organTable->setColumnWidth(2, 45); // Second column width

}

void DataPage::loadForProfile(Profile* p) {

    profile = p;
    try {
        const Scan& scan = profile->getLastScan();
        ui->stackedWidget->setCurrentWidget(ui->data);
        loadHeatmap(scan.getDate());
    } catch (const runtime_error& e) {
        ui->stackedWidget->setCurrentWidget(ui->noData);
        return;
    }

    scanListContent->clear();

    const std::vector<Scan>& scans = profile->getScans(); // storee scans from profile

    // iterate through scans and add them to the scan list content
    for (size_t i = 0; i < scans.size(); i++)  {
        QStandardItem* scanDate = new QStandardItem(scans[i].getDate());
        scanListContent->appendRow(scanDate);
    }

    ui->scanList->setModel(scanListContent);


}

void DataPage::loadHeatmap(QString scanDate) {

    ui->currScanLabel->setText("Showing data for scan taken on <b>" + scanDate + "</b>");
    for (int i = 0; i < NUM_ORGANS; i++) {

        // set heatmap
        QStandardItem* heatmapItem = new QStandardItem;
        heatmapItem->setBackground(Average); //temp
        organTableContent->setItem(i, 2, heatmapItem);

    }


}
