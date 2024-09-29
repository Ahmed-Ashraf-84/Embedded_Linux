import RPi.GPIO as GPIO
import time 

# GPIO Setup
GPIO.setmode(GPIO.BOARD)  # Use BOARD pin numbering
GPIO.setup(16, GPIO.OUT)  # Set pin 16 as an output

try:
    while True:  # Infinite loop
        GPIO.output(16, GPIO.HIGH)  # Turn LED on
        time.sleep(1)  # Wait for 1 second
        GPIO.output(16, GPIO.LOW)  # Turn LED off
        time.sleep(1)  # Wait for 1 second

except KeyboardInterrupt:  # Handle keyboard interrupt
    GPIO.cleanup()  # Clean up GPIO settings
