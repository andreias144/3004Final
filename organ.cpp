#include "organ.h"

Organ::Organ(const QString& name, const QString& iconPath)
    : name(name), iconPath(iconPath) {}

QString Organ::getName() const {
    return name;
}

QString Organ::getIconPath() const {
    return iconPath;
}
