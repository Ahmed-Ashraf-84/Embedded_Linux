# Servo Motor Control Using Raspberry Pi GPIO

This project demonstrates how to control a servo motor connected to a Raspberry Pi using Pulse Width Modulation (PWM) on a GPIO pin. The servo will move to specified angles in a loop.

## Description 
### GPIO Setup:

- `gpio.setmode(gpio.BOARD)` specifies that the pin numbering is based on the physical pin layout of the Raspberry Pi. This ensures that pin 22 will be correctly identified regardless of the specific Raspberry Pi model.
- `gpio.setup(SERVO, gpio.OUT)` configures pin 22 as an output, as we will send signals from this pin to control the servo motor.

### PWM Setup:

- PWM (Pulse Width Modulation) is initialized on the servo pin (pin 22) with a frequency of 50Hz using `pwm = gpio.PWM(SERVO, 50)`.
- The `pwm.start(0)` command starts PWM with a duty cycle of 0%, meaning the servo is initially in a neutral position.

### Main Loop:

- The script defines a `set_angle(angle)` function that calculates the required duty cycle for the specified angle and moves the servo to that position.
- The for loop iterates through angles from 0 to 180 degrees in increments of 45 degrees, calling `set_angle()` for each angle and waiting 2 seconds between movements.

### Handling Interruptions:

- The `gpio.cleanup()` function is called at the end of the script to reset all GPIO pins to their default state, preventing issues with future GPIO operations.

## Requirements

- Raspberry Pi (any model with GPIO pins)
- RPi.GPIO library (can be installed using `pip`)
- A servo motor connected to pin 22 of the Raspberry Pi (BOARD numbering)
- Power supply for the servo motor (if required)

## Circuit Diagram

1. Connect the control wire of the servo motor to GPIO pin 22 on the Raspberry Pi.
2. Connect the power wire (usually red) of the servo to a suitable power source (e.g., 5V).
3. Connect the ground wire (usually black or brown) of the servo to a ground (GND) pin on the Raspberry Pi.

## Software Setup

### Installing the RPi.GPIO library

If you don't have the `RPi.GPIO` library installed, you can install it using:

```bash
sudo pip install RPi.GPIO
