#include <Arduino.h>
#include "LED.h"

LED statusLed(13);

void setup() {
    statusLed.init();
}

void loop() {
    statusLed.toggle();
    delay(500);
}

