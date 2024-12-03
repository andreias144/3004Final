#include "radotechdevice.h"
#include <QMessageBox>

radoTechDevice::radoTechDevice()
{
    this->batteryLevel = 100;
    this->onSkin = false;

}

int radoTechDevice::getBatteryLevel() {
    return this->batteryLevel;
}

int radoTechDevice::decreaseBatteryLevel() {
<<<<<<< HEAD
<<<<<<< HEAD
    this->batteryLevel -= 2;
=======
    this->batteryLevel -= 20;
>>>>>>> 36ca08a (working mid-integration of on/off skin toggle and scan page ui)
=======
    this->batteryLevel -= 2;
>>>>>>> a63c1e3 (Fixed bug with first image not showing, added battery depletion feature)

    //If device is dead
    if (this->batteryLevel <= 0) {
        this->batteryLevel = 0;
        qInfo("The device is dead. Please recharge");
    }

    //If the device is low
    else if (this->batteryLevel == 20) {
        qInfo("The device is low. Please charge.");
    }
    return this->batteryLevel;
}



bool radoTechDevice::getOnSkin(){
    return this->onSkin;
}

bool radoTechDevice::toggleOnSkin(){
    this->onSkin = !(this->onSkin);
    return this->onSkin;
}

