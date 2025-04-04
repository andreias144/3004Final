#include "measurementpoint.h"

MeasurementPoint::MeasurementPoint(const int pointID, const QString& desc, const QPoint& pos, const QString& path)
    : id(pointID), description(desc), position(pos), imagePath(path) {}


int MeasurementPoint::getID() const {
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

const Organ* MeasurementPoint::getOrgan() const{
    return organ;
}
