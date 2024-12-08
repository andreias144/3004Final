#ifndef MEASUREMENTPOINT_H
#define MEASUREMENTPOINT_H

#include <QString>
#include <QPointF>
#include "organ.h"

class MeasurementPoint {
    private:
        int id;              // 1 through 24
        QString description;
        QPoint position;        // coordinates of the red dot
        QString imagePath;

        const Organ* organ;

        static constexpr double minValue = 5.0;
        static constexpr double maxValue = 180.0;
        static constexpr double normalMin = 45.0;
        static constexpr double normalMax = 70.0;

public:
        MeasurementPoint(const int pointID, const QString& desc, const QPoint& pos, const QString& imagePath);

        int getID() const;
        QString getDescription();
        QPoint getPosition();
        QString getImagePath();

        const Organ* getOrgan() const;

        static double getMinValue() { return minValue; }
        static double getMaxValue() { return maxValue; }
        static double getNormalMin() { return normalMin; }
        static double getNormalMax() { return normalMax; }
};

#endif // MEASUREMENTPOINT_H

