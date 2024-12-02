#ifndef SCANNER_H
#define SCANNER_H

<<<<<<< HEAD
<<<<<<< HEAD
#include "scan.h"
#include "measurementpoint.h"
#include "profile.h"
#include <vector>
#include "global.h"
=======
#include "Scan.h"
#include "MeasurementPoint.h"
#include "Profile.h"
=======
#include "scan.h"
#include "measurementpoint.h"
#include "profile.h"
>>>>>>> 5d28de2 (minor bug fixes, removed unused files)
#include <vector>
>>>>>>> d456991 (basic structure implmented)

class Scanner {
public:
    Scanner();

    Scan performScan(const std::vector<MeasurementPoint>& measurementPoints, const Profile& Profile);

private:
    double generateValue(const MeasurementPoint& point, const Profile& Profile);
};

#endif // SCANNER_H

