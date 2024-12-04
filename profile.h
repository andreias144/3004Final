#ifndef PROFILE_H
#define PROFILE_H

#include "scan.h"
#include <vector>
#include <QString>

class Profile {
private:
    QString name;
    int age;
    double height;
    double weight;
    std::vector<Scan> scanHistory;

public:
    explicit Profile(const QString& userName, int userAge, double userHeight, double userWeight);


    QString getName() const;
    int getAge() const;
    double getHeight() const;
    double getWeight() const;

    void setAge(int age);
    void setHeight(double height);
    void setWeight(double weight);


    void addScan(Scan scan);
    const std::vector<Scan>& getScans() const;


};

#endif // PROFILE_H
