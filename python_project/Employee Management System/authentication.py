#!/usr/bin/python3

from getpass import getpass
from employee_data import employee_list

def user_authentication (ID) :
    ret_value = False
    for employee in employee_list :
        if employee["ID"] == ID :
            for counter in range(1,4) :
                passward = str(getpass("Enter the Passward : "))
                if employee["Passward"] == passward :
                    print("[correct passward]")
                    ret_value = True
                    break
                else :
                    print("[incorrect passward]")
            else :  
                 print("[Wrong passward access denied]")
                 break
            break
    else :
        print("wrong ID")        
    return ret_value          


