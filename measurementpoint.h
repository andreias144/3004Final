#ifndef MEASUREMENTPOINT_H
#define MEASUREMENTPOINT_H

#include <QString>
#include <QPointF>

class MeasurementPoint {
<<<<<<< HEAD
<<<<<<< HEAD
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
=======
public:
    QString id;              // unique ID, e.g "H1L"
    QString description;     // description, e.g. "Left Hand, Point 1"
    QPointF position;        // Coordinates stored as QPoints for now
=======
    public:
        int id;              // unique ID, e.g "H1L"
        QString description;     // description, e.g. "Left Hand, Point 1"
        QPoint position;        // Coordinates stored as QPoints
        QString imagePath;
>>>>>>> 10ed055 (working but incomplete ScanPage->updateUI())

        MeasurementPoint(const int pointID, const QString& desc, const QPoint& pos, const QString& imagePath);

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
    MeasurementPoint(const QString& pointID, const QString& desc, const QPointF& pos);
>>>>>>> d456991 (basic structure implmented)
=======
        MeasurementPoint(const QString& pointID, const QString& desc, const QPointF& pos, const QString& imagePath);
=======
        MeasurementPoint(const QString& pointID, const QString& desc, const QPoint& pos, const QString& imagePath);
>>>>>>> 665a168 (added variable dot position)

        QString getID();
=======
        int getID();
>>>>>>> bbbc7df (scan loop working with a few bugs (but it doesn't crash))
        QString getDescription();
        QPoint getPosition();
        QString getImagePath();
>>>>>>> 10ed055 (working but incomplete ScanPage->updateUI())
};

#endif // MEASUREMENTPOINT_H

