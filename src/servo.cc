#include "servo.hh"

Servo::Servo(pin_type_t pin) : curr_pin{pin} {
    pinMode(pin, OUTPUT);
    analogWriteFreq(50);
    // analogWriteResolution(16);
    analogWriteRange(2048);
    analogWrite(pin, angle0);
    currAngle = 0;
}

Servo::Servo(pin_type_t pin, int angle180Value, int angle0Value, int angleMax)
    : curr_pin{pin},
      angle180{angle180Value},
      angle0{angle0Value},
      maxAngle{angleMax} {}

int Servo::angleToValue(int angle) {
    return static_cast<int>(
        (((static_cast<float>(angle180) - angle0) / 180) * angle) + angle0);
}

bool Servo::set0DegreeValue(int val) {
    angle0 = val;
    return true;
}

bool Servo::set180DegreeValue(int val) {
    angle180 = val;
    return true;
}

bool Servo::setAngle(int angle) {
    if (angle > maxAngle) {
        return false;
    }
    int write_val = angleToValue(angle);
    Serial.print("Debug ");
    Serial.println(write_val);
    analogWrite(curr_pin, write_val);
    return true;
}

bool Servo::setMaxAngle(int angle) {
    maxAngle  = angle;
    currAngle = angle;
    return true;
}