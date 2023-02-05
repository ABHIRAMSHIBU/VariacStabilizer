#include <Arduino.h>
#include <ESP8266WiFi.h>

#include "Timer.hh"

enum WIFI_MODE_T {
    WIFI_MODE_AP = true,
    WIFI_MODE_STATION = false,
};

enum WIFI_WAIT_T {
    WIFI_WAIT_ENABLED = true,
    WIFI_WAIT_DISABLED = false,
};

class WiFiManager {
    String ssid = "";
    String password = "";
    bool status{};
    bool ap_mode{};

    unsigned long default_timeout = 3000;
    Timer timer{true};

   public:
    WiFiManager(WIFI_MODE_T ap_mode, String ssid, String password,
                WIFI_WAIT_T wait_for_connection = WIFI_WAIT_DISABLED);

    bool waitForConnection();

    bool getStatus();

    bool isAPMode() const;
};