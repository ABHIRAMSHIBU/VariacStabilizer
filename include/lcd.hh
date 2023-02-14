#include <LiquidCrystal_I2C.h>

#include <memory>

class Lcd {
   private:
    std::unique_ptr<LiquidCrystal_I2C> lcd;

   public:
    Lcd();
    ~Lcd();
    LiquidCrystal_I2C* getLcd();
};