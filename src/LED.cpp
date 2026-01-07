#include "LED.h"

LED::LED(uint8_t pin) : _pin(pin), _state(false) {}

void LED::init() {
    pinMode(_pin, OUTPUT);
    off();
}

void LED::on() {
    digitalWrite(_pin, HIGH);
    _state = true;
}

void LED::off() {
    digitalWrite(_pin, LOW);
    _state = false;
}

void LED::toggle() {
    _state ? off() : on();
}

// Blink LED multiple times
void LED::blink(int times, int delayMs) {
    for(int i = 0; i < times; i++) {
        toggle();
        delay(delayMs);
    }
}


