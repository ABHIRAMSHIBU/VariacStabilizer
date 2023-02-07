#include <Arduino.h>

#include "types.hh"

class Servo {
   private:
    pin_type_t curr_pin = {};

    // Found with exp using a MG995 Servo
    int currAngle = 0;
    int angle180  = 229;
    int angle0    = 36;
    int maxAngle  = 180;

    int angleToValue(int angle);

   public:
    /// @brief     Initialize servo with given pin
    /// @param pin Pin connected to the servo eg D8,D7
    Servo(pin_type_t pin);

    /// @brief               Initialize servo with given pin, and override
    /// default params
    /// @param pin           Pin connected to the servo eg D8,D7
    /// @param angle180Value Value to analogWrite when servo is at 180 degrees
    /// @param angle0Value   Value to analogWrite when servo is at 0 degrees
    /// @param angleMax      Max capable value of servo, to prevent overload.
    Servo(pin_type_t pin, int angle180Value, int angle0Value, int angleMax);

    /// @brief       Set servo to provided angle if possible
    /// @param angle Angle to rotate to
    /// @return True if worked, else False
    bool setAngle(int angle);

    /// @brief     Set 180degree analogWrite value
    /// @param val Value to analogWrite to rotate to 180 degrees
    /// @return True if worked, else False
    bool set180DegreeValue(int val);

    /// @brief     Set 0degree analogWrite value
    /// @param val Value to analogWrite to rotate to 0 degrees
    /// @return True if worked, else False
    bool set0DegreeValue(int val);

    /// @brief       Set max possible angle to prevent overload
    /// @param angle Max turning angle of the servo
    /// @return True if worked, else False
    bool setMaxAngle(int angle);
};