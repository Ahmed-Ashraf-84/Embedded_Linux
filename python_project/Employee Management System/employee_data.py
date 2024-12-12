#!/usr/bin/python3

employee_list = []

#x = {"ID" : 200 ,
#    "Name" : "Ahmed" ,
#    "Department" : "IT" ,
#    "Salary" : 1000 ,
#    "Passward" : "A1234" ,
#    "Days of Absence" : 4}



def add_employee () :
    ID = int(input("Enter the ID : "))
    for i in employee_list :
        if i["ID"] == ID :
            print(f"conflict in Employee ID [ID : {ID}]")
            break
    else :
        Name = input("Enter the Name : ")
        Department = input("Enter the Department : ")
        Salary = float(input("Enter the Salary : "))
        Passward = input("Enter the Passward : ")
        Days_of_Absence = int(input("Enter the Days of Absence : "))
        dic = {"ID" : ID ,
            "Name" : Name ,
            "Department" : Department ,
            "Salary" : Salary ,
            "Passward" : Passward ,
            "Days of Absence" : Days_of_Absence}
        employee_list.append(dic)


def remove_employee() :
    ID = int(input("Enter the ID to remove employee: "))
    for i in employee_list :
        if i["ID"] == ID :
            employee_list.remove(i)
            break
    else :
        print(f"The Employee with [ID : {ID}] doesn't exist")    

def update_employee () :
    ID = int(input("Enter the ID to update employee: "))
    counter = 0
    ID_New = int(input("Enter the ID : "))
    Name = input("Enter the Name : ")
    Department = input("Enter the Department : ")
    Salary = float(input("Enter the Salary : "))
    Passward = input("Enter the Passward : ")
    Days_of_Absence = int(input("Enter the Days of Absence : "))
    dic = {"ID" : ID_New ,
            "Name" : Name ,
            "Department" : Department ,
            "Salary" : Salary ,
            "Passward" : Passward ,
            "Days of Absence" : Days_of_Absence}
    for i in employee_list :
        if i["ID"] == ID :
            employee_list[counter].update(dic)
            break
        counter +=1    
    else :
        print(f"The Employee with [ID : {ID}] doesn't exist") 

#print("here")

#add_employee()
#print(employee_list)
#add_employee()
#print(employee_list)




