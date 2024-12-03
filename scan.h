#ifndef SCAN_H
#define SCAN_H

#include <vector>
#include <QString>

class Scan {
private:
    QString scanDate;
    std::vector<double> values;

public:
    Scan();
    std::vector<double> getValues() const;
    double getValueAt(int index) const;

};

#endif // SCAN_H


