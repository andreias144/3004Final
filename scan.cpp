#include "scan.h"
#include <QDateTime>

Scan::Scan() : scanDate(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss")),
               diagnoses(12, Diagnosis::Normal) {}

std::vector<double>& Scan::getValues() {
    return values;
}

double Scan::getValueAt(int index) const {
    if (index < 0 || index >= static_cast<int>(values.size())) {
        throw std::out_of_range("Index is out of range");
    }
    return values[index];
}

QString Scan::getDate() const {
    return scanDate;
}

const std::vector<Diagnosis>& Scan::getDiagnoses() const {
    return diagnoses;
}

void Scan::setDiagnosis(size_t index, Diagnosis diagnosis) {
    if (index >= diagnoses.size()) {
        throw std::out_of_range("Diagnosis index is out of range");
    }
    diagnoses[index] = diagnosis;
}
