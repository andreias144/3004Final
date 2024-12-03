<<<<<<< HEAD
<<<<<<< HEAD
#include "scanner.h"
=======
#include "Scanner.h"
>>>>>>> d456991 (basic structure implmented)
=======
#include "scanner.h"
>>>>>>> 5d28de2 (minor bug fixes, removed unused files)
#include <QRandomGenerator>
#include <cmath>

Scanner::Scanner() {}

Scan Scanner::performScan(const std::vector<MeasurementPoint>& measurementPoints, const Profile& Profile) {
    Scan scan;

    for (const auto& point : measurementPoints) {
        double value = generateValue(point, Profile);
        scan.values.push_back(value);
<<<<<<< HEAD
<<<<<<< HEAD


=======
>>>>>>> d456991 (basic structure implmented)
=======


>>>>>>> a63c1e3 (Fixed bug with first image not showing, added battery depletion feature)
    }

    return scan;
}

double Scanner::generateValue(const MeasurementPoint& point, const Profile& Profile) {
 //TO DO


}
