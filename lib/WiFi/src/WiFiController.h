#ifndef WiFiController_h
#define WiFiController_h

#include "Arduino.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

class WiFiControllerClass {
    public:
        void begin() {
            xTaskCreate(&WiFiControllerClass::initialise, "WiFi Job", 5000, NULL, 1, NULL);
        }

    private:
        static void initialise(void *parameters);
        static void beginWifiAccessPoint();
        static void beginWifiConnection();
        static void beginDNS();
};

extern WiFiControllerClass WiFiController;
#endif