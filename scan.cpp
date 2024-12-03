#include "scan.h"
#include <QDateTime>
#include <stdexcept>

Scan::Scan() : scanDate(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss")) {}

std::vector<double> Scan::getValues() const {
    return values;
}

double Scan::getValueAt(int index) const {
    if (index < 0 || index >= static_cast<int>(values.size())) {
        throw std::out_of_range("Index is out of range");
    }
    return values[index];
}
