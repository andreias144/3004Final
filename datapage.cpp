#include "datapage.h"
#include "ui_datapage.h"

DataPage::DataPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataPage)
{
    ui->setupUi(this);

    connect(ui->menuButton, &QPushButton::released, this, &DataPage::menuButtonClicked);
    connect(ui->recommendationsButton, &QPushButton::released, this, &DataPage::recommendationsButtonClicked);
    connect(ui->noDataMenuButton, &QPushButton::released, this, &DataPage::menuButtonClicked);
    connect(ui->scanList, &QListView::clicked, this, &DataPage::scanListItemClicked);

    // set default widget
    ui->stackedWidget->setCurrentWidget(ui->noData);

    scanListContent = new QStandardItemModel(this);

    setupLegend();
}

DataPage::~DataPage()
{
    delete ui;
}

void DataPage::menuButtonClicked() {
    emit backToMenu();
}

void DataPage::recommendationsButtonClicked() {
    emit recommendations();
}

void DataPage::setupLegend() {
    ui->aboveAverageIcon->setStyleSheet("color: " + aboveNormalColour.name());
    ui->averageIcon->setStyleSheet("color: "+ normalColour.name());
    ui->belowAverageIcon->setStyleSheet("color: "+ belowNormalColour.name());
}

void DataPage::setupOrganTable(const vector<Organ>& organs) {

    organTableContent = new QStandardItemModel(NUM_ORGANS, 3, this);

    for (int i = 0; i < NUM_ORGANS; i++) {

        // set organ picture
        QPixmap organ(organs[i].getIconPath()); //temp
        QStandardItem* imageItem = new QStandardItem;
        imageItem->setIcon(organ);
        organTableContent->setItem(i, 0, imageItem);

        // set organ text
        QStandardItem* organText = new QStandardItem(organs[i].getName()); //temp
        organTableContent->setItem(i, 1, organText);

    }

    // remove default headers
    ui->organTable->verticalHeader()->setVisible(false);
    ui->organTable->horizontalHeader()->setVisible(false);

    ui->organTable->setModel(organTableContent);
    ui->organTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // set column sizes
    ui->organTable->setColumnWidth(0, 30);
    ui->organTable->setColumnWidth(1, 115);
    ui->organTable->setColumnWidth(2, 50);

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

void DataPage::scanListItemClicked(const QModelIndex& i) {
    QString date = scanListContent->data(i, Qt::DisplayRole).toString();
    loadHeatmap(date);
}

void DataPage::loadHeatmap(QString scanDate) {

    ui->currScanLabel->setText("Showing data for scan taken on <b>" + scanDate + "</b>");

    const std::vector<Diagnosis>& diagnoses = profile->getDiagnosis(scanDate);

    for (int i = 0; i < NUM_ORGANS; i++) {

        QColor bgColour;
        switch (diagnoses[i]) {
            case Diagnosis::BelowNormal:
                bgColour = belowNormalColour;
                break;
            case Diagnosis::Normal:
                bgColour = normalColour;
                break;
            case Diagnosis::AboveNormal:
                bgColour = aboveNormalColour;
                break;
        }

        // Load random colours:
        /*
        if (i % 3 == 0) {
            bgColour = belowNormalColour;
        } else if (i % 3 == 1) {
            bgColour = normalColour;
        } else {
            bgColour = aboveNormalColour;
        }
        */

        // set heatmap
        QStandardItem* heatmapItem = new QStandardItem;
        heatmapItem->setBackground(bgColour);
        organTableContent->setItem(i, 2, heatmapItem);

    }

}
