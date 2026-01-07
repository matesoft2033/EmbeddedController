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
    void blink(int times, int delayMs);
    bool isOn() const { return _state; }

private:
    uint8_t _pin;
    bool _state;
};

#endif


