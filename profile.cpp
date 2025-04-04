#include "profile.h"
#include <QDateTime>
#include <QRandomGenerator>


Profile::Profile(const QString& userName, int userAge, double userHeight, double userWeight)
    : name(userName), age(userAge), height(userHeight), weight(userWeight) {}


QString Profile::getName() const { return name; }
int Profile::getAge() const { return age; }
double Profile::getHeight() const { return height; }
double Profile::getWeight() const { return weight; }

void Profile::setAge(int newAge) { age = newAge; }
void Profile::setHeight(double newHeight) { height = newHeight; }
void Profile::setWeight(double newWeight) { weight = newWeight; }

void Profile::addScan(Scan scan) {
    scanHistory.push_back(scan);
}

const std::vector<Scan>& Profile::getScans() const {
    return scanHistory;
}

const Scan& Profile::getLastScan() const {
    if (!scanHistory.empty()) {
        return scanHistory.back();
    }
    throw std::runtime_error("Scan history is empty");
}

const std::vector<Diagnosis>& Profile::getDiagnosis(const QString& date) const {
    for (const auto& scan : scanHistory) {
        if (scan.getDate() == date) {
            return scan.getDiagnoses();
        }
    }
    throw std::invalid_argument("No scan found for the given date: " + date.toStdString());
}




