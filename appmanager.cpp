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
        {2, "Left Hand, Position 2", QPoint(100, 140), ":/images/imageLH.png"},
        {3, "Left Hand, Position 3", QPoint(130, 145), ":/images/imageLH.png"},
        {4, "Left Hand, Position 4", QPoint(90, 180), ":/images/imageLH.png"},
        {5, "Left Hand, Position 5", QPoint(110, 160), ":/images/imageLH.png"},
        {6, "Left Hand, Position 6", QPoint(130, 180), ":/images/imageLH.png"},
        {7, "Right Hand, Position 1", QPoint(125, 160), ":/images/imageRH.png"},
        {8, "Right Hand, Position 2", QPoint(105, 140), ":/images/imageRH.png"},
        {9, "Right Hand, Position 3", QPoint(75, 145), ":/images/imageRH.png"},
        {10, "Right Hand, Position 4", QPoint(115, 180), ":/images/imageRH.png"},
        {11, "Right Hand, Position 5", QPoint(95, 160), ":/images/imageRH.png"},
        {12, "Right Hand, Position 6", QPoint(75, 180), ":/images/imageRH.png"},
        {13, "Left Foot, Position 1", QPoint(55, 165), ":/images/imageLF.png"},
        {14, "Left Foot, Position 2", QPoint(60, 130), ":/images/imageLF.png"},
        {15, "Left Foot, Position 3", QPoint(80, 130), ":/images/imageLF.png"},
        {16, "Left Foot, Position 4", QPoint(75, 165), ":/images/imageLF.png"},
        {17, "Left Foot, Position 5", QPoint(100, 150), ":/images/imageLF.png"},
        {18, "Left Foot, Position 6", QPoint(130, 165), ":/images/imageLF.png"},
        {19, "Right Foot, Position 1", QPoint(150, 165), ":/images/imageRF.png"},
        {20, "Right Foot, Position 2", QPoint(145, 130), ":/images/imageRF.png"},
        {21, "Right Foot, Position 3", QPoint(125, 130), ":/images/imageRF.png"},
        {22, "Right Foot, Position 4", QPoint(130, 165), ":/images/imageRF.png"},
        {23, "Right Foot, Position 5", QPoint(105, 150), ":/images/imageRF.png"},
        {24, "Right Foot, Position 6", QPoint(75, 165), ":/images/imageRF.png"}
    };

}

MeasurementPoint AppManager::getPointInfo() {
    return measurementPoints[currScanPoint-1];
}

void AppManager::triggerScan() {
    currScanPoint = 0;
    std::vector<MeasurementPoint> points = getMeasurementPoints();
    Scan scan = scanner.performScan(points, *activeProfile);
    activeProfile->addScan(scan);
}

bool AppManager::advancePoint() {
    currScanPoint++;
    return (currScanPoint == 24);
}

