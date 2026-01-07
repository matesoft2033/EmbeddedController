#include "Button.h"

// Constructor: store pin and initialize states
Button::Button(uint8_t pin) : _pin(pin), _lastState(false), _currentState(false) {}

// Initialize the button pin
void Button::init() {
    pinMode(_pin, INPUT_PULLUP); // active-low button
    _lastState = digitalRead(_pin);
    _currentState = _lastState;
}

// Check if button is currently pressed
bool Button::isPressed() {
    _currentState = digitalRead(_pin);
    return !_currentState; // LOW = pressed
}

// Detect rising edge (button just pressed)
bool Button::justPressed() {
    _currentState = digitalRead(_pin);
    bool pressedNow = (!_currentState && _lastState);
    if(pressedNow) delay(50); // optional debounce
    _lastState = _currentState;
    return pressedNow;
}

// Detect falling edge (button just released)
bool Button::justReleased() {
    _currentState = digitalRead(_pin);
    bool releasedNow = (_currentState && !_lastState);
    _lastState = _currentState;
    return releasedNow;
}

