#ifndef SCAN_H
#define SCAN_H

#include <vector>
#include <QString>
#include <map>

class Scan {
private:
    QString scanDate;
    std::vector<double> values;
    std::map<int, std::string> diagnoses;

public:
    Scan();
    std::vector<double>& getValues();
    double getValueAt(int index) const;


    const std::map<int, std::string>& getDiagnoses() const;
    void setDiagnosis(int pointID, const std::string& diagnosis);

};

#endif // SCAN_H


