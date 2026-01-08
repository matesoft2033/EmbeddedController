#ifndef LED_H
#define LED_H

#include <Arduino.h>

class LED {
public:
    explicit LED(uint8_t pin);
    void init();
    void on();
    void off();
    void toggle();
    void blink(int times, int delayMs);      // optional legacy
    void startBlink(int times, int intervalMs); // non-blocking
    void update();                             // non-blocking blink handler
    bool isOn() const { return _state; }

private:
    uint8_t _pin;
    bool _state;

    // Non-blocking blink variables
    bool _isBlinking = false;             // is LED currently blinking
    int _blinkTimes = 0;                  // number of toggles left
    int _blinkInterval = 0;               // interval in ms
    unsigned long _lastToggleTime = 0;    // last toggle timestamp
};

#endif

