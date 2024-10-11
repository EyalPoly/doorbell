#include <RH_ASK.h>
#include <SPI.h> // Not actually used but RH_ASK.h needs it to compile

RH_ASK driver;

#define BUTTON_PIN 5

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  if (!driver.init()) {
    Serial.println("init failed");
  }
}

void loop() {
  if (digitalRead(BUTTON_PIN)==LOW) {
    const char *msg = "a";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(200);
  }
}
