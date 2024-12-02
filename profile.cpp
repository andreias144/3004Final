#include "Profile.h"
#include <QDateTime>
#include <QRandomGenerator>


Profile::Profile(const QString& userName, int userAge, double userHeight, double userWeight)
    : name(userName), age(userAge), height(userHeight), weight(userWeight) {}


void Profile::addScan(Scan scan) {
    scanHistory.push_back(scan);
}

const std::vector<Scan>& Profile::getScans() const {
    return scanHistory;
}
