#!/usr/bin/python3

import tkinter
import customtkinter

# Set appearance mode to 'System', 'Dark' or 'Light'
customtkinter.set_appearance_mode("System")
customtkinter.set_default_color_theme("blue")

class App(customtkinter.CTk):
    def _init_(self):
        super()._init_()

        self.title("Login Page")
        self.geometry("300x200")

        # Create login frame
        self.frame = customtkinter.CTkFrame(master=self)
        self.frame.pack(pady=20, padx=60, fill="both", expand=True)

        # Create widgets
        self.label = customtkinter.CTkLabel(master=self.frame, text="Please login", font=("Arial", 16))
        self.label.pack(pady=12, padx=10)

        self.entry_username = customtkinter.CTkEntry(master=self.frame, placeholder_text="Username")
        self.entry_username.pack(pady=12, padx=10)

        self.entry_password = customtkinter.CTkEntry(master=self.frame, placeholder_text="Password", show="*")
        self.entry_password.pack(pady=12, padx=10)

        self.button = customtkinter.CTkButton(master=self.frame, text="Login", command=self.login)
        self.button.pack(pady=12, padx=10)

    def login(self):
        username = self.entry_username.get()
        password = self.entry_password.get()
        print(f"Username: {username}, Password: {password}")



if __name__ == "__main__":
    app = App()
    app.mainloop()