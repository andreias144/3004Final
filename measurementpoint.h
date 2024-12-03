#ifndef MEASUREMENTPOINT_H
#define MEASUREMENTPOINT_H

#include <QString>
#include <QPointF>

class MeasurementPoint {
    public:
        int id;              // unique ID, e.g "H1L"
        QString description;     // description, e.g. "Left Hand, Point 1"
        QPoint position;        // Coordinates stored as QPoints
        QString imagePath;

        MeasurementPoint(const int pointID, const QString& desc, const QPoint& pos, const QString& imagePath);

        int getID();
        QString getDescription();
        QPoint getPosition();
        QString getImagePath();
};

#endif // MEASUREMENTPOINT_H

