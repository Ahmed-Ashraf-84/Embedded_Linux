# LED Blinking Using Raspberry Pi GPIO

This project demonstrates how to blink an LED connected to a Raspberry Pi using the GPIO pins. The LED will turn on for 1 second and then turn off for 1 second, continuously repeating this cycle.

## Description 
### GPIO Setup:

- `GPIO.setmode(GPIO.BOARD)` specifies that the pin numbering is based on the physical pin layout of the Raspberry Pi. This ensures that pin 16 will be correctly identified regardless of the specific Raspberry Pi model.
- `GPIO.setup(16, GPIO.OUT)` configures pin 16 as an output, allowing us to send signals to control the LED.

### Main Loop:

- The script enters an infinite loop using `while 1`, which alternately turns the LED on and off.
- `GPIO.output(16, GPIO.HIGH)` turns the LED on, and `time.sleep(1)` keeps it on for 1 second.
- `GPIO.output(16, GPIO.LOW)` turns the LED off, and `time.sleep(1)` keeps it off for 1 second.

### Handling Interruptions:

- The `try-except` block ensures that the program will clean up the GPIO settings if the user interrupts the script (e.g., with a keyboard interrupt Ctrl+C).
- The `GPIO.cleanup()` function is called to reset all GPIO pins to their default state, preventing issues with future GPIO operations.

## Requirements

- Raspberry Pi (any model with GPIO pins)
- RPi.GPIO library (can be installed using `pip`)
- An LED connected to pin 16 of the Raspberry Pi (BOARD numbering)
- A 220Ω resistor (optional, to protect the LED)
- Breadboard and jumper wires

## Circuit Diagram

1. Connect the positive (longer) leg of the LED to GPIO pin 16 on the Raspberry Pi.
2. Connect the negative (shorter) leg of the LED to a resistor, then connect the other end of the resistor to a ground (GND) pin on the Raspberry Pi.

## Software Setup

### Installing the RPi.GPIO library

If you don't have the `RPi.GPIO` library installed, you can install it using:

```bash
sudo pip install RPi.GPIO
