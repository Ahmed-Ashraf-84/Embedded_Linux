#!/usr/bin/python3

import customtkinter

customtkinter.set_appearance_mode("System")  # Modes: system (default), light, dark
customtkinter.set_default_color_theme("blue")  # Themes: blue (default), dark-blue, green

app = customtkinter.CTk()  # create CTk window like you do with the Tk window
app.geometry("800x640")
app.title("Empoyee Management System")

#frame = customtkinter.CTkFrame(master=app, width=200, height=200)
label = customtkinter.CTkLabel(app ,text="User Name",fg_color="transparent",width=250,height=50)
label.place(relx=0.35, rely=0.4, anchor=customtkinter.CENTER)

label1 = customtkinter.CTkLabel(app ,text="Passward",fg_color="transparent",width=250,height=50)
label1.place(relx=0.35, rely=0.4, anchor=customtkinter.CENTER)

input1 = customtkinter.CTkTextbox(app ,fg_color="transparent",width=250,height=50,text_color="white",border_color=("white"),corner_radius=30,border_spacing=5,border_width=3)
input1.place(relx=0.65, rely=0.4, anchor=customtkinter.CENTER)

input2 = customtkinter.CTkTextbox(app ,fg_color="transparent",width=250,height=50,text_color="white",border_color=("white"),corner_radius=30,border_spacing=5,border_width=3)
input2.place(relx=0.65, rely=0.6, anchor=customtkinter.CENTER)



#app.frame.pack(pady=20, padx=60, fill="both", expand=True)
def button_function():
    print("button pressed")

# Use CTkButton instead of tkinter Button
#button = customtkinter.CTkButton(master=app, text="CTkButton", command=button_function)
#button.place(relx=0.5, rely=0.5, anchor=customtkinter.CENTER)

app.mainloop()