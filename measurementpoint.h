#ifndef MEASUREMENTPOINT_H
#define MEASUREMENTPOINT_H

#include <QString>
#include <QPointF>

class MeasurementPoint {
public:
    QString id;              // unique ID, e.g "H1L"
    QString description;     // description, e.g. "Left Hand, Point 1"
    QPointF position;        // Coordinates stored as QPoints for now

    //other properties like hand image etc...

    MeasurementPoint(const QString& pointID, const QString& desc, const QPointF& pos);
};

#endif // MEASUREMENTPOINT_H

