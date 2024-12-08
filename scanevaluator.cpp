#include "scan.h"
#include "measurementpoint.h"
#include "scanevaluator.h"

void ScanEvaluator::evaluateScan(Scan& scan, const std::vector<MeasurementPoint>& measurementPoints) {
    const auto& values = scan.getValues();

    for (size_t i = 0; i < 6; ++i) {
        // symmetric points for hands
        const auto& leftHandPoint = measurementPoints[i];
        const auto& rightHandPoint = measurementPoints[i + 6];
        double handAvgValue = (values[leftHandPoint.getID() - 1] + values[rightHandPoint.getID() - 1]) / 2.0;

        // diagnosis for hands
        Diagnosis handDiagnosis;
        if (handAvgValue < MeasurementPoint::getNormalMin()) {
            handDiagnosis = Diagnosis::BelowNormal;
        } else if (handAvgValue > MeasurementPoint::getNormalMax()) {
            handDiagnosis = Diagnosis::AboveNormal;
        } else {
            handDiagnosis = Diagnosis::Normal;
        }

        scan.setDiagnosis(i, handDiagnosis);

        // symmetric points for feet
        const auto& leftFootPoint = measurementPoints[i + 12];
        const auto& rightFootPoint = measurementPoints[i + 18];
        double footAvgValue = (values[leftFootPoint.getID() - 1] + values[rightFootPoint.getID() - 1]) / 2.0;

        // diagnosis for feet
        Diagnosis footDiagnosis;
        if (footAvgValue < MeasurementPoint::getNormalMin()) {
            footDiagnosis = Diagnosis::BelowNormal;
        } else if (footAvgValue > MeasurementPoint::getNormalMax()) {
            footDiagnosis = Diagnosis::AboveNormal;
        } else {
            footDiagnosis = Diagnosis::Normal;
        }

        scan.setDiagnosis(i + 6, footDiagnosis);
    }
}

