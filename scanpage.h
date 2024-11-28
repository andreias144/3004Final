#ifndef SCANPAGE_H
#define SCANPAGE_H

#include <QWidget>
#include "defs.h"

namespace Ui {
class ScanPage;
}

class ScanPage : public QWidget
{
    Q_OBJECT

public:
    explicit ScanPage(QWidget *parent = nullptr);
    ~ScanPage();

private:
    Ui::ScanPage *ui;

signals:
    void viewResults();

private slots:
    void resultsButtonClicked();
};

#endif // SCANPAGE_H
