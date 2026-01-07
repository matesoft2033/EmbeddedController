#include <Arduino.h>
#include "Button.h"
#include "LED.h"

// LED connected to pin 8
LED statusLed(8);    
// Button connected to pin 2
Button button1(2);   

void setup() {
    Serial.begin(9600);    // For monitoring in Serial Monitor
    statusLed.init();      // Initialize LED
    button1.init();        // Initialize button

    // Blink LED 3 times on startup as a demo
    statusLed.blink(3, 300);

    Serial.println("Setup done! Press button to toggle LED.");
}

void loop() {
    if (button1.justPressed()) {  // button pressed once
        statusLed.toggle();       // switch LED on/off
        Serial.print("LED is now ");
        Serial.println(statusLed.isOn() ? "ON" : "OFF");
    }
}

