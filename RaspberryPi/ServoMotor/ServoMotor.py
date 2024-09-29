import RPi.GPIO as gpio
import time

# Constants
SERVO = 22  # GPIO pin number for the servo motor

# GPIO Setup
gpio.setmode(gpio.BOARD)
gpio.setup(SERVO, gpio.OUT)

# PWM Setup
pwm = gpio.PWM(SERVO, 50)  # Initialize PWM on the servo pin with 50Hz frequency
pwm.start(0)  # Start PWM with a duty cycle of 0%

def set_angle(angle):
    duty = 2 + (angle / 18)  # Calculate duty cycle based on angle
    gpio.output(SERVO, True)  # Set the output high
    pwm.ChangeDutyCycle(duty)  # Change duty cycle to move servo
    time.sleep(1)  # Wait for the servo to reach the position
    gpio.output(SERVO, False)  # Set the output low
    pwm.ChangeDutyCycle(0)  # Stop sending PWM signal

# Main Loop
for i in range(0, 200, 45):  # Move servo to angles 0, 45, 90, 135, 180
    set_angle(i)  # Set the servo angle
    time.sleep(2)  # Wait before moving to the next angle

# Cleanup
gpio.cleanup()  # Reset all GPIO pins to their default state
