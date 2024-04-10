#include "Arduino.h"
#include "WiFiController.h"
#include "ESPmDNS.h"
#include "Config.h"
#include "WiFi.h"
#include "HttpController.h"

void WiFiControllerClass::initialise(void *parameters) {
    Serial.println("WiFi -> Initializing WiFi Network");
    WiFiControllerClass::beginWifiConnection();
    WiFiControllerClass::beginDNS();
    HttpController::begin();
    vTaskDelete(NULL);
}

void WiFiControllerClass::beginWifiConnection() {
    Serial.print("Connecting to WiFi ");
    WiFi.begin(Config::wifiSSID().c_str(), Config::wifiPassword().c_str());
    int counter = 0;
    while (WiFi.status() != WL_CONNECTED && counter <= 30) {
        vTaskDelay(500 / portTICK_PERIOD_MS);
        Serial.print(".");
        counter++;
    }
    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("");
        Serial.println("WiFi Connected");
        Serial.print("IP: ");
        Serial.println(WiFi.localIP());
    } else {
        WiFiControllerClass::beginWifiAccessPoint();
    }
}

void WiFiControllerClass::beginWifiAccessPoint() {
    Serial.println("Initializing WiFi Access Point");
    WiFi.mode(WIFI_AP);
    std::string ssid = Config::wifiAPName();
    const char *pssid = ssid.c_str();
    std::string password = Config::wifiAPPassword();
    const char *ppassword = password.c_str();
    if (WiFi.softAP(pssid, ppassword)) {
        delay(100);
        WiFi.softAPConfig(IPAddress(192, 168, 0, 1), IPAddress(192, 168, 0, 1), IPAddress(255, 255, 255, 0));
        Serial.println("\t -> WiFi -> WiFi Access Point ready");
        Serial.print("\t\t -> SSID: ");
        Serial.println(pssid);
        Serial.print("\t\t -> PWD: ");
        Serial.println(ppassword);
        Serial.print("\t\t -> IP: ");
        Serial.println(WiFi.softAPIP());
    } else {
        Serial.println("\t -> WiFi -> An ERROR has occurred while initializeing WiFi AP");
    }
}

void WiFiControllerClass::beginDNS() {
    if (!MDNS.begin("matrix")) { //http://esp32.local
        Serial.println("Error setting up MDNS responder!");
    while (1) {
      delay(1000);
    }
  }
}