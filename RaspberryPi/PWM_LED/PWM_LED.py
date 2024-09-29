import RPi.GPIO as gpio
import time

# Constants
LED = 16  # GPIO pin number for the LED

# GPIO Setup
gpio.setmode(gpio.BOARD)  # Use BOARD pin numbering
gpio.setup(LED, gpio.OUT)  # Set pin 16 as an output for the LED

# PWM Setup
pwm = gpio.PWM(LED, 50)  # Initialize PWM on pin 16 with a frequency of 50Hz
pwm.start(0)  # Start PWM with a duty cycle of 0%

try:
    while True:  # Infinite loop
        # Increasing Brightness
        for i in range(100):  # Duty cycle from 0% to 100%
            pwm.ChangeDutyCycle(i)  # Change brightness
            time.sleep(0.025)  # Short delay for smooth transition
        
        # Decreasing Brightness
        for i in range(100):  # Duty cycle from 100% to 0%
            pwm.ChangeDutyCycle(100 - i)  # Change brightness
            time.sleep(0.025)  # Short delay for smooth transition

except KeyboardInterrupt:  # Handle keyboard interrupt
    gpio.cleanup()  # Clean up GPIO settings
