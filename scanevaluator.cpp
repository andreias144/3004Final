#include "scan.h"
#include "measurementpoint.h"
#include "scanevaluator.h"
#include <QDebug>

void ScanEvaluator::evaluateScan(Scan& scan, const std::vector<MeasurementPoint>& measurementPoints) {
    const auto& values = scan.getValues();

    qDebug() << "Starting scan evaluation...";
    qDebug() << "Number of measurement points:" << measurementPoints.size();
    qDebug() << "Number of scan values:" << values.size();

    if (measurementPoints.size() != 24 || values.size() != 24) {
        qDebug() << "Error: Invalid size of measurementPoints or scan values.";
        return;
    }

    for (size_t i = 0; i < 6; ++i) {
        qDebug() << "\nEvaluating point pair for hands, index:" << i;

        // Symmetric points for hands
        const auto& leftHandPoint = measurementPoints[i];
        const auto& rightHandPoint = measurementPoints[i + 6];
        double leftHandValue = values[leftHandPoint.getID() - 1];
        double rightHandValue = values[rightHandPoint.getID() - 1];
        double handAvgValue = (leftHandValue + rightHandValue) / 2.0;

        qDebug() << "Left hand value:" << leftHandValue
                 << "Right hand value:" << rightHandValue
                 << "Average hand value:" << handAvgValue;

        // Diagnosis for hands
        Diagnosis handDiagnosis;
        if (handAvgValue < MeasurementPoint::getNormalMin()) {
            handDiagnosis = Diagnosis::BelowNormal;
            qDebug() << "Diagnosis for hands: Below Normal";
        } else if (handAvgValue > MeasurementPoint::getNormalMax()) {
            handDiagnosis = Diagnosis::AboveNormal;
            qDebug() << "Diagnosis for hands: Above Normal";
        } else {
            handDiagnosis = Diagnosis::Normal;
            qDebug() << "Diagnosis for hands: Normal";
        }

        scan.setDiagnosis(i, handDiagnosis);

        qDebug() << "Diagnosis for hands set in scan at index:" << i;

        // Symmetric points for feet
        qDebug() << "\nEvaluating point pair for feet, index:" << i;
        const auto& leftFootPoint = measurementPoints[i + 12];
        const auto& rightFootPoint = measurementPoints[i + 18];
        double leftFootValue = values[leftFootPoint.getID() - 1];
        double rightFootValue = values[rightFootPoint.getID() - 1];
        double footAvgValue = (leftFootValue + rightFootValue) / 2.0;

        qDebug() << "Left foot value:" << leftFootValue
                 << "Right foot value:" << rightFootValue
                 << "Average foot value:" << footAvgValue;

        // Diagnosis for feet
        Diagnosis footDiagnosis;
        if (footAvgValue < MeasurementPoint::getNormalMin()) {
            footDiagnosis = Diagnosis::BelowNormal;
            qDebug() << "Diagnosis for feet: Below Normal";
        } else if (footAvgValue > MeasurementPoint::getNormalMax()) {
            footDiagnosis = Diagnosis::AboveNormal;
            qDebug() << "Diagnosis for feet: Above Normal";
        } else {
            footDiagnosis = Diagnosis::Normal;
            qDebug() << "Diagnosis for feet: Normal";
        }

        scan.setDiagnosis(i + 6, footDiagnosis);

        qDebug() << "Diagnosis for feet set in scan at index:" << i + 6;
    }

    qDebug() << "\nFinished scan evaluation. Diagnoses in scan:";
    for (size_t i = 0; i < scan.getDiagnoses().size(); ++i) {
        qDebug() << "Index:" << i << "Diagnosis:" << static_cast<int>(scan.getDiagnoses()[i]);
    }
}
