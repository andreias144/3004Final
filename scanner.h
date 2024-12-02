#ifndef SCANNER_H
#define SCANNER_H

#include "Scan.h"
#include "MeasurementPoint.h"
#include "Profile.h"
#include <vector>

class Scanner {
public:
    Scanner();

    Scan performScan(const std::vector<MeasurementPoint>& measurementPoints, const Profile& Profile);

private:
    double generateValue(const MeasurementPoint& point, const Profile& Profile);
};

#endif // SCANNER_H

