#ifndef APPMANAGER_H
#define APPMANAGER_H

#include <QObject>
#include "defs.h"
#include "profile.h"
#include "measurementpoint.h"
#include "scanner.h"
#include "scanevaluator.h"
#include <vector>
#include <memory>


class AppManager {
public:
    AppManager();

    void addProfile(const QString& name, int age, double height, double weight);
    void removeProfile(int index);
    void switchActiveProfile(int index);
    bool advancePoint();
    int getCurrPoint();
    void triggerScan();

    Profile* getActiveProfile() const;
    const std::vector<std::unique_ptr<Profile>>& getProfiles() const;

    const std::vector<MeasurementPoint>& getMeasurementPoints() const;
    MeasurementPoint getPointInfo();

private:
    std::vector<std::unique_ptr<Profile>> profiles;
    Profile* activeProfile;

    std::vector<MeasurementPoint> measurementPoints; // only point info
    void initializeMeasurementPoints();

    Scanner scanner;
    ScanEvaluator scanEvaluator;

    int currScanPoint;
};

#endif // APPMANAGER_H

