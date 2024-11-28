#include "scanpage.h"
#include "ui_scanpage.h"

ScanPage::ScanPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScanPage)
{
    ui->setupUi(this);
    connect(ui->resultsButton, &QPushButton::released, this, &ScanPage::resultsButtonClicked);
}

ScanPage::~ScanPage()
{
    delete ui;
}

void ScanPage::resultsButtonClicked() {
    emit viewResults();
}
