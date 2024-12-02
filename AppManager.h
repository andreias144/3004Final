#ifndef APPMANAGER_H
#define APPMANAGER_H

<<<<<<< HEAD
<<<<<<< HEAD
#include "profile.h"
#include "measurementpoint.h"
#include "scanner.h"
=======
#include "Profile.h"
#include "measurementpoint.h"#
#include "Scanner.h"
>>>>>>> d456991 (basic structure implmented)
=======
#include "profile.h"
#include "measurementpoint.h"
#include "scanner.h"
>>>>>>> 5d28de2 (minor bug fixes, removed unused files)
#include <vector>
#include <memory>

class AppManager {
public:
    AppManager();

    void addProfile(const QString& name, int age, double height, double weight);
    void removeProfile(int index);
    void switchActiveProfile(int index);
<<<<<<< HEAD
    bool advancePoint();
    int getCurrPoint();
    void resetScan();
=======
>>>>>>> d456991 (basic structure implmented)

    Profile* getActiveProfile() const;
    const std::vector<std::unique_ptr<Profile>>& getProfiles() const;

    const std::vector<MeasurementPoint>& getMeasurementPoints() const;

<<<<<<< HEAD
<<<<<<< HEAD
    MeasurementPoint getPointInfo();

=======
>>>>>>> d456991 (basic structure implmented)
=======
    MeasurementPoint getPointInfo(int);

>>>>>>> 10ed055 (working but incomplete ScanPage->updateUI())
private:
    std::vector<std::unique_ptr<Profile>> profiles;
    Profile* activeProfile;

    std::vector<MeasurementPoint> measurementPoints; // only point info
    void initializeMeasurementPoints();

    Scanner scanner;
<<<<<<< HEAD

    int currScanPoint;
=======
>>>>>>> d456991 (basic structure implmented)
};

#endif // APPMANAGER_H

