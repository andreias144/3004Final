#include "scan.h"
#include <QDateTime>
#include <stdexcept>

Scan::Scan() : scanDate(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss")) {}

std::vector<double>& Scan::getValues() {
    return values;
}

double Scan::getValueAt(int index) const {
    if (index < 0 || index >= static_cast<int>(values.size())) {
        throw std::out_of_range("Index is out of range");
    }
    return values[index];
}

const std::map<int, std::string>& Scan::getDiagnoses() const {
    return diagnoses;
}

void Scan::setDiagnosis(int pointID, const std::string& diagnosis) {
    diagnoses[pointID] = diagnosis;
}

QString Scan::getDate() const{
    return scanDate;
}
