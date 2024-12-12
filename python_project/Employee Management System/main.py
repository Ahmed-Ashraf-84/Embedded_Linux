#!/usr/bin/python3

import employee_data
import operations
import authentication
import customtkinter

if __name__ == "__main__" :
    
    employee_data.add_employee()
    employee_data.add_employee()
    employee_data.add_employee()
    print(employee_data.employee_list)
    boun = operations.calculate_bonus(100)
    print(boun)
    #id = int(input("Enter your ID : "))
    #correct = authentication.user_authentication(id)
    #if correct == True :
    #    employee_data.add_employee()
    #    print(employee_data.employee_list)
    #else :
    #    pass




