#include "Scan.h"
#include "MeasurementPoint.h"

class ScanEvaluator {
public:
    void evaluateScan(Scan& scan, const std::vector<MeasurementPoint>& measurementPoints) {
        const auto& values = scan.getValues();
        for (size_t i = 0; i < measurementPoints.size(); ++i) {
            const auto& point = measurementPoints[i];
            double value = values[i];

            std::string status;
            if (value < MeasurementPoint::getNormalMin()) {
                status = "Below Normal";
            } else if (value > MeasurementPoint::getNormalMax()) {
                status = "Above Normal";
            } else {
                status = "Normal";
            }
            scan.setDiagnosis(point.getID(), status);
        }
    }
};
