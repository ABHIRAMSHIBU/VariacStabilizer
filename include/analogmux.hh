#include <Arduino.h>

enum MUX_NAME_T {
    C0,
    C1,
    C2,
    C3,
    C4,
    C5,
    C6,
    C7,
    C8,
    C9,
    C10,
    C11,
    C12,
    C13,
    C14,
    C15,
};

class AnalogMux {
   private:
    int S[4]         = {};
    int enablePin    = {};
    int value        = {};
    int minValue     = 16;
    float maxVoltage = 3.03;
    bool enabled     = {};

   public:
    AnalogMux(int S0, int S1, int S2, int S3);
    AnalogMux(int S0, int S1, int S2, int S3, int enablePin);

    bool select(MUX_NAME_T port);

    bool read();

    bool read(MUX_NAME_T port);

    void begin();

    bool enable();

    bool disable();

    int getValue();

    float getVoltage();

    void setMaxVoltage(float max);

    void setMinValue(int min);
};