#include "measurementpoint.h"

MeasurementPoint::MeasurementPoint(const QString& pointID, const QString& desc, const QPointF& pos, const QString& path)
    : id(pointID), description(desc), position(pos), imagePath(path) {}


QString MeasurementPoint::getID() {
    return id;
}

QString MeasurementPoint::getDescription() {
    return description;
}

QPointF MeasurementPoint::getPosition() {
    return position;
}

QString MeasurementPoint::getImagePath() {
    return imagePath;
}
