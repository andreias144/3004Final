#ifndef SCAN_H
#define SCAN_H

#include <vector>
#include <QString>
#include "diagnosis.h"

class Scan {
private:
    QString scanDate;
    std::vector<double> values;
    std::vector<Diagnosis> diagnoses;

public:
    Scan();
    std::vector<double>& getValues();
    double getValueAt(int index) const;
    QString getDate() const;

    const std::vector<Diagnosis>& getDiagnoses() const;
    void setDiagnosis(size_t index, Diagnosis diagnosis);
};

#endif // SCAN_H
