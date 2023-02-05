#include <gtest/gtest.h>

#include "WiFiManager.hh"
TEST(WiFiManagerTest, Instantiation) {
    WiFiManager wifimanager{true, "WifiVariac", "password", false};
    ASSERT_TRUE(true);
}

void setup() {
    Serial.begin(9600);
    // delay(1000);
    testing::InitGoogleTest();
}
void loop() {  // Run tests
    if (RUN_ALL_TESTS())
        ;

    // sleep 1 sec
    delay(1000);
}