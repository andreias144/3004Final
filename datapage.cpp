#include "datapage.h"
#include "ui_datapage.h"

DataPage::DataPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataPage)
{
    ui->setupUi(this);
    connect(ui->menuButton, &QPushButton::released, this, &DataPage::menuButtonClicked);
}

DataPage::~DataPage()
{
    delete ui;
}

void DataPage::menuButtonClicked() {
    emit backToMenu();
}
