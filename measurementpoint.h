#ifndef MEASUREMENTPOINT_H
#define MEASUREMENTPOINT_H

#include <QString>
#include <QPointF>

class MeasurementPoint {
    public:
        QString id;              // unique ID, e.g "H1L"
        QString description;     // description, e.g. "Left Hand, Point 1"
        QPoint position;        // Coordinates stored as QPoints for now
        QString imagePath;

        //other properties like hand image etc...

        MeasurementPoint(const QString& pointID, const QString& desc, const QPoint& pos, const QString& imagePath);

        QString getID();
        QString getDescription();
        QPoint getPosition();
        QString getImagePath();
};

#endif // MEASUREMENTPOINT_H

