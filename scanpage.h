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
<<<<<<< HEAD
<<<<<<< HEAD
#include "measurementpoint.h"
#include <QLCDNumber>
=======
>>>>>>> 36ca08a (working mid-integration of on/off skin toggle and scan page ui)
=======
#include "measurementpoint.h"
>>>>>>> 10ed055 (working but incomplete ScanPage->updateUI())

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
    explicit ScanPage(QWidget *parent = nullptr, QLCDNumber *batteryIndicator = nullptr);
    ~ScanPage();
    void updateUI(MeasurementPoint, double);
<<<<<<< HEAD
<<<<<<< HEAD
    void lastPoint();
=======
>>>>>>> 10ed055 (working but incomplete ScanPage->updateUI())
=======
    void lastPoint();
>>>>>>> 87d9ca6 (scan loop works but only updates image and dot)

private:
    Ui::ScanPage *ui;
    QGraphicsScene scene;
<<<<<<< HEAD
    QLCDNumber *batteryIndicator;
=======
>>>>>>> 10ed055 (working but incomplete ScanPage->updateUI())

signals:
    void viewResults();
    void nextPoint();
    void scanOver();
<<<<<<< HEAD
    void returnToMainWindow();
=======
>>>>>>> 87d9ca6 (scan loop works but only updates image and dot)

private slots:
    void resultsButtonClicked();
    void deviceToggled();
};

#endif // SCANPAGE_H
