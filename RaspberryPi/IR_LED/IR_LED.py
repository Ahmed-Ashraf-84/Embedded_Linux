import RPi.GPIO as gpio
import time

# Constants
LED = 16  # GPIO pin number for the LED
IR = 18   # GPIO pin number for the IR sensor

# GPIO Setup
gpio.setmode(gpio.BOARD)  # Use BOARD pin numbering
gpio.setup(LED, gpio.OUT)  # Set pin 16 as an output for the LED
gpio.setup(IR, gpio.IN)    # Set pin 18 as an input for the IR sensor

try:
    while True:  # Infinite loop
        if gpio.input(IR):  # Check if the IR sensor is activated
            gpio.output(LED, gpio.HIGH)  # Turn LED on
        else:
            gpio.output(LED, gpio.LOW)  # Turn LED off

except KeyboardInterrupt:  # Handle keyboard interrupt
    gpio.cleanup()  # Clean up GPIO settings
