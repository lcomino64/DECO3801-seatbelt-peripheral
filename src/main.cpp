#include <Arduino.h>
#include <HID-Project.h>
#include <HID-Settings.h>

void seatbeltISR();
void sendKeystroke(char key);

volatile int lastState;
const int seatbeltPin = 2;

void setup() {
    pinMode(seatbeltPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(seatbeltPin), seatbeltISR, CHANGE);
    lastState = digitalRead(seatbeltPin);

    BootKeyboard.begin();

    // Send initial keystroke based on the initial state
    char initialKey = (lastState == LOW) ? 'b' : 'u';
    sendKeystroke(initialKey);
}

void loop() {
    // Empty loop as we are handling everything in ISR
    delay(1000);
}

void seatbeltISR() {
    int currentState = digitalRead(seatbeltPin);
    if (lastState == HIGH && currentState == LOW) {
        sendKeystroke('b');
    } else if (lastState == LOW && currentState == HIGH) {
        sendKeystroke('u');
    }
    lastState = currentState;
}

void sendKeystroke(char key) {
    BootKeyboard.press(key);
    delay(10);
    BootKeyboard.release(key);
}
