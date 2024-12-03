#include "AppManager.h"

AppManager::AppManager() : activeProfile(nullptr) {
    initializeMeasurementPoints();
}

void AppManager::addProfile(const QString& name, int age, double height, double weight) {
    auto newProfile = std::unique_ptr<Profile>(new Profile(name, age, height, weight));

    profiles.push_back(std::move(newProfile));
    activeProfile = profiles.back().get();


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
        {1, "Left Hand, Position 1", QPoint(80, 160), ":/images/imageLH.png"},
        {2, "Right Hand, Position 1", QPoint(90, 160), ":/images/imageRH.png"},
        {3, "Left Hand, Position 2", QPoint(80, 170), ":/images/imageLH.png"},
        {4, "Right Hand, Position 2", QPoint(90, 160), ":/images/imageRH.png"},
        {5, "Left Hand, Position 3", QPoint(10, 60), ":/images/imageLH.png"},
        {6, "Right Hand, Position 3", QPoint(30, 60), ":/images/imageRH.png"},
        {7, "Left Hand, Position 4", QPoint(10, 80), ":/images/imageLH.png"},
        {8, "Right Hand, Position 4", QPoint(30, 80), ":/images/imageRH.png"},
        {9, "Left Hand, Position 5", QPoint(10, 100), ":/images/imageLH.png"},
        {10, "Right Hand, Position 5", QPoint(30, 100), ":/images/imageRH.png"},
        {11, "Left Hand, Position 6", QPoint(10, 120), ":/images/imageLH.png"},
        {12, "Right Hand, Position 6", QPoint(30, 120), ":/images/imageRH.png"},
        {13, "Left Foot, Position 1", QPoint(10, 140), ":/images/imageLF.png"},
        {14, "Right Foot, Position 1", QPoint(30, 140), ":/images/imageRF.png"},
        {15, "Left Foot, Position 2", QPoint(10, 160), ":/images/imageLF.png"},
        {16, "Right Foot, Position 2", QPoint(30, 160), ":/images/imageRF.png"},
        {17, "Left Foot, Position 3", QPoint(10, 180), ":/images/imageLF.png"},
        {18, "Right Foot, Position 3", QPoint(30, 180), ":/images/imageRF.png"},
        {19, "Left Foot, Position 4", QPoint(10, 200), ":/images/imageLF.png"},
        {20, "Right Foot, Position 4", QPoint(30, 200), ":/images/imageRF.png"},
        {21, "Left Foot, Position 5", QPoint(10, 220), ":/images/imageLF.png"},
        {22, "Right Foot, Position 5", QPoint(30, 220), ":/images/imageRF.png"},
        {23, "Left Foot, Position 6", QPoint(10, 240), ":/images/imageLF.png"},
        {24, "Right Foot, Position 6", QPoint(30, 240), ":/images/imageRF.png"}
    };
}

MeasurementPoint AppManager::getPointInfo() {
    return measurementPoints[currScanPoint];
}

void AppManager::triggerScan() {
    currScanPoint = 1;
    std::vector<MeasurementPoint> points = getMeasurementPoints();
    Scan scan = scanner.performScan(points, *activeProfile);
    activeProfile->addScan(scan);
}

bool AppManager::advancePoint() {
    currScanPoint++;
    return (currScanPoint == 23);
}

