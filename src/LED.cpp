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
    if (_state) off();
    else on();
}

void LED::startBlink(int times, int intervalMs) {
    _blinkTimes = times * 2;      
    _blinkInterval = intervalMs;
    _isBlinking = true;
    _lastToggleTime = millis();
}


void LED::update() {
    if (!_isBlinking) return;

    unsigned long currentMillis = millis();
    if (currentMillis - _lastToggleTime >= _blinkInterval) {
        toggle();
        _lastToggleTime = currentMillis;
        _blinkTimes--;
        if (_blinkTimes <= 0) {
            _isBlinking = false;
        }
    }
}


void LED::blink(int times, int delayMs) {
    for(int i = 0; i < times; i++) {
        toggle();
        delay(delayMs);
    }
}

