#include "Arduino.h"
#include "Config.h"

#define WIFI_AP_NAME "Matrix_Display"
#define WIFI_AP_PASSWORD "1234567890"
#define WIFI_SSID "YOUR_WIFI_SSID"
#define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"

std::string Config::wifiAPName() {
    String name(WIFI_AP_NAME);
    std::string result = std::string(name.c_str());
    return result;
}

std::string Config::wifiAPPassword() {
    String name(WIFI_AP_PASSWORD);
    std::string result = std::string(name.c_str());
    return result;
}

std::string Config::wifiSSID() {
    std::string password = std::string(WIFI_SSID);
    return password;
}

std::string Config::wifiPassword() {
    std::string password = std::string(WIFI_PASSWORD);
    return password;
}