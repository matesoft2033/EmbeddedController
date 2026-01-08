#include <Arduino.h>
#include "Button.h"
#include "LED.h"

// LED connected to pin 8
LED statusLed(8);    
// Button connected to pin 2
Button button1(2);   

void setup() {
    Serial.begin(9600);  // for monitoring in serial monitor
    statusLed.init();    // initialize LED
    button1.init();      // initialize button

    // non-blocking blink 3 times on startup
    statusLed.startBlink(3, 300);

    Serial.println("Setup done! Press button to toggle LED.");
}

void loop() {
    // check button
    if (button1.justPressed()) {  // button pressed once
        statusLed.toggle();       // switch LED on/off
        Serial.print("LED is now ");
        Serial.println(statusLed.isOn() ? "ON" : "OFF");
    }

    // update LED blinking (non-blocking)
    statusLed.update();
}

