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
        {"H1L", "Left Hand, Point 1", QPointF(10, 20)},
        {"H1R", "Right Hand, Point 1", QPointF(30, 20)},
        {"H2L", "Left Hand, Point 2", QPointF(10, 40)},
        {"H2R", "Right Hand, Point 2", QPointF(30, 40)},
        {"H3L", "Left Hand, Point 3", QPointF(10, 60)},
        {"H3R", "Right Hand, Point 3", QPointF(30, 60)},
        {"H4L", "Left Hand, Point 4", QPointF(10, 80)},
        {"H4R", "Right Hand, Point 4", QPointF(30, 80)},
        {"H5L", "Left Hand, Point 5", QPointF(10, 100)},
        {"H5R", "Right Hand, Point 5", QPointF(30, 100)},               // I put random values for the Coordinates for now,
        {"H6L", "Left Hand, Point 6", QPointF(10, 120)},                // also i don't really know what a QPoint is so you can change that as well if another way of saving the coordinates is better
        {"H6R", "Right Hand, Point 6", QPointF(30, 120)},
        {"F1L", "Left Foot, Point 1", QPointF(10, 140)},
        {"F1R", "Right Foot, Point 1", QPointF(30, 140)},
        {"F2L", "Left Foot, Point 2", QPointF(10, 160)},
        {"F2R", "Right Foot, Point 2", QPointF(30, 160)},
        {"F3L", "Left Foot, Point 3", QPointF(10, 180)},
        {"F3R", "Right Foot, Point 3", QPointF(30, 180)},
        {"F4L", "Left Foot, Point 4", QPointF(10, 200)},
        {"F4R", "Right Foot, Point 4", QPointF(30, 200)},
        {"F5L", "Left Foot, Point 5", QPointF(10, 220)},
        {"F5R", "Right Foot, Point 5", QPointF(30, 220)},
        {"F6L", "Left Foot, Point 6", QPointF(10, 240)},
        {"F6R", "Right Foot, Point 6", QPointF(30, 240)}
    };
}
