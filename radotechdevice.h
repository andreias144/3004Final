#ifndef RADOTECHDEVICE_H
#define RADOTECHDEVICE_H


class radoTechDevice
{
public:
    radoTechDevice();
    int getBatteryLevel();
    bool getOnSkin();
    bool toggleOnSkin();
    int decreaseBatteryLevel();
private:
    int batteryLevel;
    bool onSkin;


};

#endif // RADOTECHDEVICE_H
