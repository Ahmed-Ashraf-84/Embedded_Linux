# LED PWM Brightness Control Using Raspberry Pi GPIO

This project demonstrates how to control the brightness of an LED connected to a Raspberry Pi using Pulse Width Modulation (PWM) on a GPIO pin. The brightness of the LED will smoothly increase and decrease in a loop.

## Description 
### GPIO Setup:

- `gpio.setmode(gpio.BOARD)` specifies that the pin numbering is based on the physical pin layout of the Raspberry Pi. This ensures that pin 16 will be correctly identified regardless of the specific Raspberry Pi model.
- `gpio.setup(LED, gpio.OUT)` configures pin 16 as an output, allowing us to send signals to control the LED.

### PWM Setup:

- PWM (Pulse Width Modulation) is initialized on the LED pin (pin 16) with a frequency of 50Hz using `pwm = gpio.PWM(LED, 50)`.
- The `pwm.start(0)` command starts PWM with a duty cycle of 0%, meaning the LED is initially off.

### Main Loop:

- The script enters an infinite loop using `while 1`, which gradually increases and decreases the brightness of the LED.
- **Increasing Brightness**:
  - A `for` loop increments the PWM duty cycle from 0% to 100%, with each step increasing by 1%. A delay of 0.025 seconds is added after each change to make the change in brightness smooth.
- **Decreasing Brightness**:
  - Another `for` loop decreases the PWM duty cycle from 100% back to 0%, again with a small delay for smooth dimming.

### Handling Interruptions:

- The `try-except` block ensures that the program will clean up the GPIO settings if the user interrupts the script (e.g., with a keyboard interrupt Ctrl+C).
- The `gpio.cleanup()` function is called to reset all GPIO pins to their default state, preventing issues with future GPIO operations.

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
