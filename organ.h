#ifndef ORGAN_H
#define ORGAN_H

#include <QString>

class Organ {

private:
    QString name;
    QString iconPath;

public:
    Organ(const QString& name, const QString& iconPath);
    QString getName() const;
    QString getIconPath() const;
};

#endif // ORGAN_H
