<<<<<<< HEAD
<<<<<<< HEAD
#include "measurementpoint.h"

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
MeasurementPoint::MeasurementPoint(const int pointID, const QString& desc, const QPoint& pos, const QString& path)
    : id(pointID), description(desc), position(pos), imagePath(path) {}


int MeasurementPoint::getID() {
=======
MeasurementPoint::MeasurementPoint(const QString& pointID, const QString& desc, const QPointF& pos, const QString& path)
=======
MeasurementPoint::MeasurementPoint(const QString& pointID, const QString& desc, const QPoint& pos, const QString& path)
>>>>>>> 665a168 (added variable dot position)
    : id(pointID), description(desc), position(pos), imagePath(path) {}


QString MeasurementPoint::getID() {
>>>>>>> 10ed055 (working but incomplete ScanPage->updateUI())
=======
MeasurementPoint::MeasurementPoint(const int pointID, const QString& desc, const QPoint& pos, const QString& path)
    : id(pointID), description(desc), position(pos), imagePath(path) {}


int MeasurementPoint::getID() {
>>>>>>> bbbc7df (scan loop working with a few bugs (but it doesn't crash))
    return id;
}

QString MeasurementPoint::getDescription() {
    return description;
}

<<<<<<< HEAD
<<<<<<< HEAD
QPoint MeasurementPoint::getPosition() {
=======
QPointF MeasurementPoint::getPosition() {
>>>>>>> 10ed055 (working but incomplete ScanPage->updateUI())
=======
QPoint MeasurementPoint::getPosition() {
>>>>>>> 665a168 (added variable dot position)
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
