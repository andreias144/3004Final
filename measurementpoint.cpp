<<<<<<< HEAD
<<<<<<< HEAD
#include "measurementpoint.h"

<<<<<<< HEAD
MeasurementPoint::MeasurementPoint(const int pointID, const QString& desc, const QPoint& pos, const QString& path)
    : id(pointID), description(desc), position(pos), imagePath(path) {}


int MeasurementPoint::getID() {
=======
MeasurementPoint::MeasurementPoint(const QString& pointID, const QString& desc, const QPointF& pos, const QString& path)
    : id(pointID), description(desc), position(pos), imagePath(path) {}


QString MeasurementPoint::getID() {
>>>>>>> 10ed055 (working but incomplete ScanPage->updateUI())
    return id;
}

QString MeasurementPoint::getDescription() {
    return description;
}

<<<<<<< HEAD
QPoint MeasurementPoint::getPosition() {
=======
QPointF MeasurementPoint::getPosition() {
>>>>>>> 10ed055 (working but incomplete ScanPage->updateUI())
    return position;
}

QString MeasurementPoint::getImagePath() {
    return imagePath;
}
<<<<<<< HEAD
=======
#include "MeasurementPoint.h"
=======
#include "measurementpoint.h"
>>>>>>> 5d28de2 (minor bug fixes, removed unused files)

MeasurementPoint::MeasurementPoint(const QString& pointID, const QString& desc, const QPointF& pos)
    : id(pointID), description(desc), position(pos) {}
>>>>>>> d456991 (basic structure implmented)
=======
>>>>>>> 10ed055 (working but incomplete ScanPage->updateUI())
