#ifndef APPMANAGER_H
#define APPMANAGER_H

#include "Profile.h"
#include "measurementpoint.h"#
#include "Scanner.h"
#include <vector>
#include <memory>

class AppManager {
public:
    AppManager();

    void addProfile(const QString& name, int age, double height, double weight);
    void removeProfile(int index);
    void switchActiveProfile(int index);

    Profile* getActiveProfile() const;
    const std::vector<std::unique_ptr<Profile>>& getProfiles() const;

    const std::vector<MeasurementPoint>& getMeasurementPoints() const;

private:
    std::vector<std::unique_ptr<Profile>> profiles;
    Profile* activeProfile;

    std::vector<MeasurementPoint> measurementPoints; // only point info
    void initializeMeasurementPoints();

    Scanner scanner;
};

#endif // APPMANAGER_H

