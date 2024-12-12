#!/usr/bin/python3

#from math import pi

#def circle_area(redius) :
#    return pi*redius**2

#redius = int(input("Enter the redius : "))

#print(circle_area(redius))

#from getpass import getpass

#passward = getpass("enter")

#print(passward)

import datetime

time = datetime.datetime.now()

file = open("time",'a')
file.write(str(time)+ "\n")








