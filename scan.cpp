#include "scan.h"
#include <QDateTime>

Scan::Scan() : scanDate(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss")) {}

