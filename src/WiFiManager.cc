#include "WiFiManager.hh"

WiFiManager::WiFiManager(WIFI_MODE_T ap_mode, String ssid, String password,
                         WIFI_WAIT_T wait_for_connection)
    : ssid{ssid}, password{password}, ap_mode{ap_mode} {
    timer.start();
    // mode: true AP Mode, False: Client Mode
    if (isAPMode()) {
        WiFi.begin(ssid, password);
        if (wait_for_connection == WIFI_WAIT_ENABLED) {
            status = waitForConnection();
        }
    } else {
        status = WiFi.softAP(ssid, password);
    }
}

bool WiFiManager::isAPMode() const { return ap_mode == WIFI_MODE_STATION; }

bool WiFiManager::waitForConnection() {
    if (isAPMode()) {
        while (WiFi.status() != WL_CONNECTED) {
            delay(500);
            Serial.print(".");
            if (timer.currentElapsed() > default_timeout) {
                timer.end();
                break;
            }
        }
        if (WiFi.status() != WL_CONNECTED) {
            return false;
        } else {
            return true;
        }
    }

    // else {
    //     while (WiFi.softAPgetStationNum() == 0) {
    //         delay(500);
    //         Serial.print(".");
    //         if (timer.currentElapsed() > default_timeout) {
    //             timer.end();
    //             break;
    //         }
    //     }
    //     if (WiFi.softAPgetStationNum() == 0) {
    //         return false;
    //     } else {
    //         return true;
    //     }
    // }
    return WiFi.status();
}

bool WiFiManager::getStatus() { return status; }