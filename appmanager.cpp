#include "AppManager.h"

AppManager::AppManager() : activeProfile(nullptr) {
    initializeMeasurementPoints();
    resetScan();
}

void AppManager::addProfile(const QString& name, int age, double height, double weight) {
    auto newProfile = std::unique_ptr<Profile>(new Profile(name, age, height, weight));

    profiles.push_back(std::move(newProfile));

    if (profiles.size() == 1) {
        activeProfile = profiles.front().get();
    }
}

void AppManager::removeProfile(int index) {
    if (index >= 0 && index < profiles.size()) {
        if (profiles[index].get() == activeProfile) {
            activeProfile = nullptr;
        }
        profiles.erase(profiles.begin() + index);

        if (!profiles.empty() && !activeProfile) {
            activeProfile = profiles.front().get();
        }
    }
}

void AppManager::switchActiveProfile(int index) {
    if (index >= 0 && index < profiles.size()) {
        activeProfile = profiles[index].get();
    }
}

Profile* AppManager::getActiveProfile() const {
    return activeProfile;
}

const std::vector<std::unique_ptr<Profile>>& AppManager::getProfiles() const {
    return profiles;
}

const std::vector<MeasurementPoint>& AppManager::getMeasurementPoints() const {
    return measurementPoints;
}

void AppManager::initializeMeasurementPoints() {

    measurementPoints = {
        {"H1L", "Left Hand, Point 1", QPoint(80, 160), ":/images/imageLH.png"},
        {"H1R", "Right Hand, Point 1", QPoint(90, 160), ":/images/imageRH.png"},
        {"H2L", "Left Hand, Point 2", QPoint(80, 170), ":/images/imageLH.png"},
        {"H2R", "Right Hand, Point 2", QPoint(90, 160), ":/images/imageRH.png"},
        {"H3L", "Left Hand, Point 3", QPoint(10, 60), ":/images/imageLH.png"},
        {"H3R", "Right Hand, Point 3", QPoint(30, 60), ":/images/imageRH.png"},
        {"H4L", "Left Hand, Point 4", QPoint(10, 80), ":/images/imageLH.png"},
        {"H4R", "Right Hand, Point 4", QPoint(30, 80), ":/images/imageRH.png"},
        {"H5L", "Left Hand, Point 5", QPoint(10, 100), ":/images/imageLH.png"},
        {"H5R", "Right Hand, Point 5", QPoint(30, 100), ":/images/imageRH.png"},               // I put random values for the Coordinates for now,
        {"H6L", "Left Hand, Point 6", QPoint(10, 120), ":/images/imageLH.png"},                // also i don't really know what a QPoint is so you can change that as well if another way of saving the coordinates is better
        {"H6R", "Right Hand, Point 6", QPoint(30, 120), ":/images/imageRH.png"},
        {"F1L", "Left Foot, Point 1", QPoint(10, 140), ":/images/imageLF.png"},
        {"F1R", "Right Foot, Point 1", QPoint(30, 140), ":/images/imageRF.png"},
        {"F2L", "Left Foot, Point 2", QPoint(10, 160), ":/images/imageLF.png"},
        {"F2R", "Right Foot, Point 2", QPoint(30, 160), ":/images/imageRF.png"},
        {"F3L", "Left Foot, Point 3", QPoint(10, 180), ":/images/imageLF.png"},
        {"F3R", "Right Foot, Point 3", QPoint(30, 180), ":/images/imageRF.png"},
        {"F4L", "Left Foot, Point 4", QPoint(10, 200), ":/images/imageLF.png"},
        {"F4R", "Right Foot, Point 4", QPoint(30, 200), ":/images/imageRF.png"},
        {"F5L", "Left Foot, Point 5", QPoint(10, 220), ":/images/imageLF.png"},
        {"F5R", "Right Foot, Point 5", QPoint(30, 220), ":/images/imageRF.png"},
        {"F6L", "Left Foot, Point 6", QPoint(10, 240), ":/images/imageLF.png"},
        {"F6R", "Right Foot, Point 6", QPoint(30, 240), ":/images/imageRF.png"}
    };

}

MeasurementPoint AppManager::getPointInfo() {
    return measurementPoints[currScanPoint];
}

bool AppManager::advancePoint() {
    currScanPoint++;
    return (currScanPoint == 23);
}

void AppManager::resetScan() {
    currScanPoint = 0;
    // anything else?
}
