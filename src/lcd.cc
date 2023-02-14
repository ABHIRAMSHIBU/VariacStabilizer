#include "lcd.hh"

Lcd::Lcd() : lcd{std::make_unique<LiquidCrystal_I2C>(0x27, 16, 2)} {
    lcd->init();
    lcd->backlight();
    lcd->setCursor(0, 0);
}

Lcd::~Lcd() {}

LiquidCrystal_I2C* Lcd::getLcd() { return lcd.get(); }