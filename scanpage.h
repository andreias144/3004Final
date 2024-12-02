#ifndef SCANPAGE_H
#define SCANPAGE_H

#include <QWidget>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "defs.h"
#include "global.h"
#include "measurementpoint.h"

static const QPoint POINT_1(100, 200);
static const QPoint POINT_2(300, 400);
static const QPoint POINT_3(500, 600);

namespace Ui {
class ScanPage;
}

class ScanPage : public QWidget
{
    Q_OBJECT

public:
    explicit ScanPage(QWidget *parent = nullptr);
    ~ScanPage();
    void updateUI(MeasurementPoint, double);
    void lastPoint();

private:
    Ui::ScanPage *ui;
    QGraphicsScene scene;

signals:
    void viewResults();
    void nextPoint();
    void scanOver();

private slots:
    void resultsButtonClicked();
    void deviceToggled();
};

#endif // SCANPAGE_H
