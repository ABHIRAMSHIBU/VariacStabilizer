#include <Arduino.h>

class Timer {
   private:
    unsigned long (*getTime)(void) = {};
    unsigned long time = {};
    const unsigned long MAX_TIME = -1;
    bool usingMillis = {};

   public:
    ~Timer();

    Timer(bool useMillis);

    bool start();

    unsigned long currentElapsed();

    unsigned long end();

    double toSeconds();
};