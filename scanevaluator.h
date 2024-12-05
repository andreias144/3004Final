#ifndef SCANEVALUATOR_H
#define SCANEVALUATOR_H

#include "Scan.h"
#include "MeasurementPoint.h"
#include <vector>

class ScanEvaluator {
public:
    // Evaluates a Scan and generates diagnoses for each MeasurementPoint
    void evaluateScan(Scan& scan, const std::vector<MeasurementPoint>& measurementPoints);
};

#endif // SCANEVALUATOR_H
