<<<<<<< HEAD
#include "measurementpoint.h"

MeasurementPoint::MeasurementPoint(const int pointID, const QString& desc, const QPoint& pos, const QString& path)
    : id(pointID), description(desc), position(pos), imagePath(path) {}


int MeasurementPoint::getID() {
    return id;
}

QString MeasurementPoint::getDescription() {
    return description;
}

QPoint MeasurementPoint::getPosition() {
    return position;
}

QString MeasurementPoint::getImagePath() {
    return imagePath;
}
=======
#include "MeasurementPoint.h"

MeasurementPoint::MeasurementPoint(const QString& pointID, const QString& desc, const QPointF& pos)
    : id(pointID), description(desc), position(pos) {}
>>>>>>> d456991 (basic structure implmented)
