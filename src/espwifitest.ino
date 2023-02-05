/* #include "WiFiManager.hh"

String ssid = "WiFi";
String pass = "anme9537";

#ifndef PIO_UNIT_TESTING
void setup() {
    Serial.begin(9600);
    delay(10);

    Serial.println("Connecting to ");
    Serial.println(ssid);

    // WiFiManager wifimanager{WIFI_MODE_AP, ssid, pass, WIFI_WAIT_ENABLED};

    // Serial.println("");
    // if (wifimanager.getStatus()) {
    //     Serial.println("WiFi connected");
    // } else {
    //     Serial.println("WiFi connection failed!");
    // }
}

void loop() {}

#endif */

/* #include <ESP8266WiFi.h>
#include <WiFiUdp.h>

void setup() {
    int retry = 0, config_done = 0;

    // configure WiFi in Station Mode
    WiFi.mode(WIFI_STA);

    // configure serial port baud rate
    Serial.begin(9600);

    // configure on-board LED as output pin
    pinMode(LED_BUILTIN, OUTPUT);

    // turn LED on
    digitalWrite(LED_BUILTIN, LOW);

    // check whether WiFi connection can be established
    Serial.println("Attempt to connect to WiFi network…");
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(500);
        if (retry++ >= 20)  // timeout for connection is 10 seconds
        {
            Serial.println("Connection timeout expired !Start SmartConfig…");
            WiFi.beginSmartConfig();
            // forever loop: exit only when SmartConfig packets have been
            // received
            while (true) {
                delay(500);
                Serial.print(".");
                if (WiFi.smartConfigDone()) {
                    Serial.println("nSmartConfig successfully configured");
                    config_done = 1;
                    break;  // exit from loop
                }
                toggleLED();
            }
            if (config_done == 1) break;
        }
    }
    // turn LED off
    digitalWrite(16, HIGH);

    // wait for IP address assignment
    while (WiFi.status() != WL_CONNECTED) {
        delay(50);
    }
    // show WiFi connection data
    Serial.println("");
    WiFi.printDiag(Serial);

    // show the IP address assigned to our device
    Serial.println(WiFi.localIP());
}

void loop() {
    // nothing to do!
}

void toggleLED() {
    static int pinStatus = LOW;

    if (pinStatus == HIGH)
        pinStatus = LOW;
    else
        pinStatus = HIGH;

    digitalWrite(LED_BUILTIN, pinStatus);
} */

#include <ESP8266WiFi.h>

void setup() {
    // WiFi.begin();
    // WiFi.softAP("VariacStabilizer");
    WiFi.mode(WIFI_STA);
    WiFi.beginSmartConfig();
    Serial.begin(9600);
}

void loop() {
    if (!WiFi.smartConfigDone()) {
        Serial.println("Smart Config Waiting");
        delay(1000);
    } else {
        Serial.println("Smart Config Done!");
        delay(5000);
    }
}
