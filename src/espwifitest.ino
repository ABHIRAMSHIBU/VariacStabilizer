// #include "servo.hh"
#include "analogmux.hh"
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

// Smart Config Working
/*
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
*/

/*
#include <Arduino.h>
#include <Servo.h>

Servo MG995_Servo;

void setup() {
    MG995_Servo.attach(D8);
    Serial.begin(9600);
}

void loop() {
    for (float i = 1000; i <= 4000; i+=10) {
        MG995_Servo.writeMicroseconds(i);
        Serial.println(i);
        delay(100);
    }
    for (int i = 4000; i >= 1000; i-=10) {
        MG995_Servo.writeMicroseconds(i);
        Serial.println(i);
        delay(100);
    }
}

*/

#include <Arduino.h>
// Servo servo(D8);
AnalogMux analogMux(D0, D1, D2, D3, D4);

/*
    For 0-255
    0degree = 5
    180 degree = 33
*/
void setup() {
    Serial.begin(9600);
    analogMux.begin();
    // analogMux.select(0);
    // servo.setMaxAngle(216);
    // Serial.begin(9600);
    // pinMode(D8, OUTPUT);
    // analogWriteFreq(50);
    // analogWriteResolution(16);
    // analogWriteRange(2048);
    // analogWrite(D8, 40);
    // Serial.println("Waiting!");
    // delay(5000);
    // Serial.println("Starting!");
}

void loop() {
    /*
        2048 steps
        266 end
        36 begin
    */
    // for (int i = 40; i > 0 ; i--) {
    //     analogWrite(D8, i);
    //     Serial.println(i);
    //     delay(1000);
    // }

    // for (int i = 5; i < 33; i++) {
    // for (int i = 36; i < 266; i++) {
    //     analogWrite(D8, i);
    //     Serial.println(i);
    //     delay(10);
    // }
    // delay(1000);
    // // for (int i = 32;  i >= 4;  i--) {
    // for (int i = 266; i > 36; i--) {
    //     analogWrite(D8, i);
    //     Serial.println(i);
    //     delay(10);
    // }
    // delay(1000);

    // Serial.print("Enter Value:\n");
    // String s;
    // while (s.indexOf("\n") == -1) {
    //     s += Serial.readString();
    // }
    // // String s = Serial.readString();
    // int val = s.toInt();
    // Serial.print("Applying ");
    // Serial.println(val);
    // servo.setAngle(val);

    // for (int i = 0; i < 216; i += 1) {
    //     servo.setAngle(i);
    //     Serial.println(i);
    //     delay(10);
    // }

    // for (int i = 216; i > 0; i -= 1) {
    //     servo.setAngle(i);
    //     Serial.println(i);
    //     delay(10);
    // }
    float values[16];
    analogMux.enable();
    for (int i = C0; i < C15 + 1; i++) {
        analogMux.read((MUX_NAME_T)i);
        values[i] = analogMux.getVoltage();
    }
    analogMux.disable();
    Serial.println("");
    Serial.print("Values: ");
    for (int i = 0; i < 16; i++) {
        Serial.print(i);
        Serial.print("->");
        Serial.print(values[i]);
        Serial.print("\t");
    }
    Serial.println("");
    delay(500);
}