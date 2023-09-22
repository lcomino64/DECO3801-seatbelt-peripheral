# DECO3801 Seatbelt Peripheral

Repo containing the code for the seat-belt peripheral used in our driving simulation project.

## The Design:
The circuit is powered by a Seeeduino Xiao microcontroller which simply detects whether the seatbelt becomes unbuckled (rising-edge interrupt), or when the seatbelt becomes buckled (falling-edge). The microcontroller then sends a keystroke via HID, 'b' for buckled or 'u' for unbuckled.

## Wiring Diagram:
![seatbelt-diagram](https://github.com/lcomino64/DECO3801-seatbelt-peripheral/assets/112602408/213eea4a-42d7-47aa-87c3-578093bdd062)

And just plug in the seeed via the USB-C port.

## Usage:
The code is intended to be a platformio project despite being written in Arduino.

Simply open the project in platformio (vscode plugin), and compile/upload. Platformio will gather dependencies.

## Dependencies:
Uses NicoHood's Arduino HID Project: https://github.com/NicoHood/HID
