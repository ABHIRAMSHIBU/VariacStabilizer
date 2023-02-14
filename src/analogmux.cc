#include "analogmux.hh"

AnalogMux::AnalogMux(int S0, int S1, int S2, int S3, int pinEnable = -1)
    : enablePin{pinEnable} {
    S[0] = S0;
    S[1] = S1;
    S[2] = S2;
    S[3] = S3;
}

void AnalogMux::begin() {
    for (int i = 0; i < 4; i++) {
        pinMode(S[i], OUTPUT);
        digitalWrite(S[1], LOW);
    }
    pinMode(enablePin, OUTPUT);
    digitalWrite(enablePin, HIGH);
    pinMode(A0, INPUT);
}

bool AnalogMux::enable() {
    if (enablePin != -1) {
        digitalWrite(enablePin, LOW);
        enabled = true;
        return true;
    }
    return false;
}

bool AnalogMux::disable() {
    if (enablePin != -1) {
        digitalWrite(enablePin, HIGH);
        enabled = false;
        return true;
    }
    return false;
}

bool AnalogMux::select(MUX_NAME_T port) {
    if (port > 15 || port < 0) {
        return false;
    }
    bool bits[4] = {};
    int _port    = port;
    for (int i = 0; i < 4; i++) {
        bits[i] = 0x01 & _port;
        _port   = _port >> 1;
        digitalWrite(S[i], bits[i]);
    }
    // Serial.print("Debug:AnalogMux:");
    // for (int i = 0; i < 4; i++) {
    //     Serial.print(bits[i]);
    //     Serial.print("\t");
    // }
    // Serial.println();
    return true;
}

bool AnalogMux::read() {
    if (enabled || enablePin == -1) {
        value = analogRead(A0);
        return true;
    };
    return false;
}

bool AnalogMux::read(MUX_NAME_T port) {
    if (!select(port)) {
        return false;
    }

    return read();
}

int AnalogMux::getValue() { return value; }

void AnalogMux::setMaxVoltage(float max) { maxVoltage = max; }

float AnalogMux::getVoltage() {
    return ((maxVoltage / (1024 - minValue + 1)) * (value - minValue));
}

void AnalogMux::setMinValue(int min) { minValue = min; }