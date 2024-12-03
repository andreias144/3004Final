#ifndef SCANNER_H
#define SCANNER_H

<<<<<<< HEAD
<<<<<<< HEAD
#include "scan.h"
#include "measurementpoint.h"
#include "profile.h"
#include <vector>
#include "global.h"
<<<<<<< HEAD
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
=======
>>>>>>> a63c1e3 (Fixed bug with first image not showing, added battery depletion feature)

class Scanner {
public:
    Scanner();

    Scan performScan(const std::vector<MeasurementPoint>& measurementPoints, const Profile& Profile);

private:
    double generateValue(const MeasurementPoint& point, const Profile& Profile);
};

#endif // SCANNER_H

