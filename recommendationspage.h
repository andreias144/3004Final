#ifndef RECOMMENDATIONSPAGE_H
#define RECOMMENDATIONSPAGE_H

#include <QWidget>

namespace Ui {
class RecommendationsPage;
}

class RecommendationsPage : public QWidget
{
    Q_OBJECT

public:
    explicit RecommendationsPage(QWidget *parent = nullptr);
    ~RecommendationsPage();

private:
    Ui::RecommendationsPage *ui;

signals:
    void backToData();

private slots:
    void backButtonClicked();
};

#endif // RECOMMENDATIONSPAGE_H
