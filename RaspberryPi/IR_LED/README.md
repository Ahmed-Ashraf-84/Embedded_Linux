# IR Sensor LED Control Using Raspberry Pi GPIO

This project demonstrates how to control an LED connected to a Raspberry Pi based on input from an infrared (IR) sensor. The LED will turn on when the IR sensor is activated and turn off when it is not.

## Description 
### GPIO Setup:

- `gpio.setmode(gpio.BOARD)` specifies that the pin numbering is based on the physical pin layout of the Raspberry Pi. This ensures that pin 16 for the LED and pin 18 for the IR sensor will be correctly identified regardless of the specific Raspberry Pi model.
- `gpio.setup(LED, gpio.OUT)` configures pin 16 as an output for the LED.
- `gpio.setup(IR, gpio.IN)` configures pin 18 as an input for the IR sensor.

### Main Loop:

- The script enters an infinite loop using `while 1`, which continuously checks the state of the IR sensor.
- If the IR sensor is activated (`gpio.input(IR)` returns `True`), the LED is turned on.
- If the IR sensor is not activated, the LED is turned off.

### Handling Interruptions:

- The `try-except` block ensures that the program will clean up the GPIO settings if the user interrupts the script (e.g., with a keyboard interrupt Ctrl+C).
- The `gpio.cleanup()` function is called to reset all GPIO pins to their default state, preventing issues with future GPIO operations.

## Requirements

- Raspberry Pi (any model with GPIO pins)
- RPi.GPIO library (can be installed using `pip`)
- An LED connected to pin 16 of the Raspberry Pi (BOARD numbering)
- An IR sensor connected to pin 18 of the Raspberry Pi (BOARD numbering)
- A breadboard and jumper wires

## Circuit Diagram

1. Connect the positive (longer) leg of the LED to GPIO pin 16 on the Raspberry Pi.
2. Connect the negative (shorter) leg of the LED to a resistor, then connect the other end of the resistor to a ground (GND) pin on the Raspberry Pi.
3. Connect the IR sensor's output pin to GPIO pin 18 on the Raspberry Pi.
4. Connect the power and ground pins of the IR sensor to an appropriate power source (typically 5V) and a ground pin on the Raspberry Pi.

## Software Setup

### Installing the RPi.GPIO library

If you don't have the `RPi.GPIO` library installed, you can install it using:

```bash
sudo pip install RPi.GPIO
