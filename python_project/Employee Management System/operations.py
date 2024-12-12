#!/usr/bin/python3

from employee_data import employee_list

def calculate_bonus (ID):
    for i in employee_list :
        if ID == i["ID"] :
            bonus = i["Salary"] + i["Salary"] * 0.1
            return bonus
        
def calculate_discount (ID):
    for i in employee_list :
        if ID == i["ID"] :
            discount = i["Salary"] + i["Salary"] * 0.05
            return discount

def calculate_holidays (ID):
    legal_holidays = 30
    for i in employee_list :
        if ID == i["ID"] :
            remain = legal_holidays - i["Days of Absence"]
            return remain

