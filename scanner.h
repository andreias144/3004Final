#ifndef SCANNER_H
#define SCANNER_H

#include "scan.h"
#include "measurementpoint.h"
#include "profile.h"
#include <vector>
#include "global.h"


class Scanner {
public:
    Scanner();

    Scan performScan(const std::vector<MeasurementPoint>& measurementPoints, const Profile& Profile);

private:
    double generateValue(const MeasurementPoint& point, const Profile& Profile);
};

#endif // SCANNER_H

