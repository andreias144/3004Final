#include "AppManager.h"

AppManager::AppManager() : activeProfile(nullptr) {
    initializeMeasurementPoints();
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
        {"H1L", "Left Hand, Point 1", QPointF(60, 180), ":/images/imageLH.png"},
        {"H1R", "Right Hand, Point 1", QPointF(30, 20), ":/images/imageLH.png"},
        {"H2L", "Left Hand, Point 2", QPointF(10, 40), ":/images/imageLH.png"},
        {"H2R", "Right Hand, Point 2", QPointF(30, 40), ":/images/imageLH.png"},
        {"H3L", "Left Hand, Point 3", QPointF(10, 60), ":/images/imageLH.png"},
        {"H3R", "Right Hand, Point 3", QPointF(30, 60), ":/images/imageLH.png"},
        {"H4L", "Left Hand, Point 4", QPointF(10, 80), ":/images/imageLH.png"},
        {"H4R", "Right Hand, Point 4", QPointF(30, 80), ":/images/imageLH.png"},
        {"H5L", "Left Hand, Point 5", QPointF(10, 100), ":/images/imageLH.png"},
        {"H5R", "Right Hand, Point 5", QPointF(30, 100), ":/images/imageLH.png"},               // I put random values for the Coordinates for now,
        {"H6L", "Left Hand, Point 6", QPointF(10, 120), ":/images/imageLH.png"},                // also i don't really know what a QPoint is so you can change that as well if another way of saving the coordinates is better
        {"H6R", "Right Hand, Point 6", QPointF(30, 120), ":/images/imageLH.png"},
        {"F1L", "Left Foot, Point 1", QPointF(10, 140), ":/images/imageLH.png"},
        {"F1R", "Right Foot, Point 1", QPointF(30, 140), ":/images/imageLH.png"},
        {"F2L", "Left Foot, Point 2", QPointF(10, 160), ":/images/imageLH.png"},
        {"F2R", "Right Foot, Point 2", QPointF(30, 160), ":/images/imageLH.png"},
        {"F3L", "Left Foot, Point 3", QPointF(10, 180), ":/images/imageLH.png"},
        {"F3R", "Right Foot, Point 3", QPointF(30, 180), ":/images/imageLH.png"},
        {"F4L", "Left Foot, Point 4", QPointF(10, 200), ":/images/imageLH.png"},
        {"F4R", "Right Foot, Point 4", QPointF(30, 200), ":/images/imageLH.png"},
        {"F5L", "Left Foot, Point 5", QPointF(10, 220), ":/images/imageLH.png"},
        {"F5R", "Right Foot, Point 5", QPointF(30, 220), ":/images/imageLH.png"},
        {"F6L", "Left Foot, Point 6", QPointF(10, 240), ":/images/imageLH.png"},
        {"F6R", "Right Foot, Point 6", QPointF(30, 240), ":/images/imageLH.png"}
    };

}

MeasurementPoint AppManager::getPointInfo(int index) {
    return measurementPoints[index];
}
