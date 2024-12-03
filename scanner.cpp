#include "scanner.h"
#include <QRandomGenerator>
#include <cmath>

Scanner::Scanner() {}

Scan Scanner::performScan(const std::vector<MeasurementPoint>& measurementPoints, const Profile& Profile) {
    Scan scan;

    for (const auto& point : measurementPoints) {
        double value = generateValue(point, Profile);
        scan.values.push_back(value);


    }

    return scan;
}

double Scanner::generateValue(const MeasurementPoint& point, const Profile& Profile) {
 //TO DO


}
