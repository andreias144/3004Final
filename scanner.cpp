#include "scanner.h"
#include "measurementpoint.h"
#include <QRandomGenerator>
#include <QDebug>
#include <cmath>
#include <map>


double Scanner::generateValue(const Profile& profile) {
    // base value inside of normal bounds
    double lower = MeasurementPoint::getNormalMin();
    double upper = MeasurementPoint::getNormalMax();
    double baseValue = lower + QRandomGenerator::global()->generateDouble() * (upper - lower);

    // calculate bmi
    double bmi = profile.getWeight() / std::pow(profile.getHeight() / 100.0, 2); // Höhe in Metern

    // calculate age and bmi deviation
    double deviationFactor = 1.0;

    if (bmi < 18.5 || bmi > 25.0) {
        deviationFactor += 0.2 * std::abs(bmi - 22.0);
    }

    if (profile.getAge() > 50) {
        deviationFactor += 0.1 * (profile.getAge() - 50) / 10.0; // additional deviation per 10 years over 50
    }

    // simulate deviation
    double range = MeasurementPoint::getMaxValue() - MeasurementPoint::getMinValue();
    double deviation = QRandomGenerator::global()->generateDouble() * (range * 0.4) - (range * 0.2); // [-20%, +20%]
    baseValue += deviation * deviationFactor;

    // respect bounds
    if (baseValue > MeasurementPoint::getMaxValue()) baseValue = MeasurementPoint::getMaxValue();
    if (baseValue < MeasurementPoint::getMinValue()) baseValue = MeasurementPoint::getMinValue();
    qDebug() << "Generated value:" << baseValue;


    return baseValue;
}

Scan Scanner::performScan(const std::vector<MeasurementPoint>& points, const Profile& profile) {
    qDebug() << "Number of points:" << points.size();

    Scan scan;
    std::map<int, double> symmetricValues;

    for (const auto& point : points) {
        // handling symmetric points
        int symmetricID = getSymmetricID(point.getID());
        if (symmetricValues.find(symmetricID) != symmetricValues.end()) {
            // symmetrical values have a lower variance
            double symmetricValue = symmetricValues[symmetricID];
            double variance = QRandomGenerator::global()->generateDouble() * 10.0 - 5.0; // [-5, +5]
            symmetricValue += variance;
            scan.getValues().push_back(symmetricValue);
        } else {
            // generate new values
            double value = generateValue(profile);
            scan.getValues().push_back(value);
            symmetricValues[point.getID()] = value;
        }
    }
    qDebug() << "Scan values:";
    for (const double value : scan.getValues()) {
        qDebug() << value;
    }
    return scan;
}

int Scanner::getSymmetricID(int id) {
    if (id % 2 == 0) {
        return id - 1;
    }
    else {
        return id + 1;
    }
}
