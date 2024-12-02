#include "measurementpoint.h"

MeasurementPoint::MeasurementPoint(const QString& pointID, const QString& desc, const QPointF& pos)
    : id(pointID), description(desc), position(pos) {}
