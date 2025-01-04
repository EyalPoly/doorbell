#include <RH_ASK.h>
#include <SPI.h> // Required for RH_ASK.h to compile
#include <LowPower.h>

RH_ASK driver;

#define BUTTON_PIN 3

volatile bool buttonPressed = false;

void buttonInterrupt() {
  buttonPressed = true;
}

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), buttonInterrupt, FALLING);
  
  if (!driver.init()) {
    Serial.begin(9600);
    Serial.println("init failed");
    Serial.end();
  }
}

void loop() {
  if (buttonPressed) {
    buttonPressed = false;

    const char *msg = "a";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(200);
  }

  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF); 
}
