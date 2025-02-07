import tkinter as tk
from tkinter import ttk
import math
from PIL import Image, ImageTk
import colorsys

class ScientificCalculator:
    def __init__(self, root):
        self.root = root
        self.root.title("Calculatrice Scientifique")
        self.root.geometry("400x600")
        
        # Variables
        self.current = ""
        self.hue = 0.0
        
        # Display
        self.display = tk.Entry(root, font=("Arial", 24), justify="right")
        self.display.grid(row=0, column=0, columnspan=4, padx=5, pady=5, sticky="nsew")
        
        # Buttons configuration
        buttons = [
            ('sin', 'cos', 'tan', '←'),
            ('7', '8', '9', '/'),
            ('4', '5', '6', '*'),
            ('1', '2', '3', '-'),
            ('0', '.', '=', '+'),
            ('√', 'π', '^2', 'C')
        ]
        
        # Create buttons
        for i, row in enumerate(buttons, 1):
            for j, text in enumerate(row):
                button = ttk.Button(root, text=text, padding=10)
                button.grid(row=i, column=j, padx=2, pady=2, sticky="nsew")
                button.configure(command=lambda t=text: self.button_click(t))
        
        # Configure grid
        for i in range(7):
            root.grid_rowconfigure(i, weight=1)
        for i in range(4):
            root.grid_columnconfigure(i, weight=1)
            
        # Start animation
        self.animate_background()

    def button_click(self, value):
        if value == '=':
            try:
                result = eval(self.current.replace('^', '**').replace('π', str(math.pi)))
                self.display.delete(0, tk.END)
                self.display.insert(tk.END, str(result))
                self.current = str(result)
            except:
                self.display.delete(0, tk.END)
                self.display.insert(tk.END, "Error")
                self.current = ""
        elif value == 'C':
            self.display.delete(0, tk.END)
            self.current = ""
        elif value == '←':
            self.current = self.current[:-1]
            self.display.delete(0, tk.END)
            self.display.insert(tk.END, self.current)
        elif value in ['sin', 'cos', 'tan']:
            try:
                num = float(self.current)
                if value == 'sin':
                    result = math.sin(math.radians(num))
                elif value == 'cos':
                    result = math.cos(math.radians(num))
                else:
                    result = math.tan(math.radians(num))
                self.display.delete(0, tk.END)
                self.display.insert(tk.END, str(result))
                self.current = str(result)
            except:
                self.display.delete(0, tk.END)
                self.display.insert(tk.END, "Error")
                self.current = ""
        else:
            self.current += value
            self.display.delete(0, tk.END)
            self.display.insert(tk.END, self.current)

    def animate_background(self):
        # Change background color
        self.hue = (self.hue + 0.001) % 1.0
        rgb = colorsys.hsv_to_rgb(self.hue, 0.1, 1.0)
        color = f'#{int(rgb[0]*255):02x}{int(rgb[1]*255):02x}{int(rgb[2]*255):02x}'
        self.root.configure(bg=color)
        self.root.after(50, self.animate_background)

if __name__ == "__main__":
    root = tk.Tk()
    calculator = ScientificCalculator(root)
    root.mainloop()