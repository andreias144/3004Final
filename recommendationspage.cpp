#include "recommendationspage.h"
#include "ui_recommendationspage.h"

RecommendationsPage::RecommendationsPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecommendationsPage)
{
    ui->setupUi(this);
    connect(ui->backButton, &QPushButton::released, this, &RecommendationsPage::backButtonClicked);
}

RecommendationsPage::~RecommendationsPage()
{
    delete ui;
}

void RecommendationsPage::backButtonClicked() {
    emit backToData();
}
