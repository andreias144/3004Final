#ifndef SCAN_H
#define SCAN_H

#include <vector>
#include <QString>

class Scan {
public:
    QString scanDate;
    std::vector<double> values;

    Scan();
};

#endif // SCAN_H


