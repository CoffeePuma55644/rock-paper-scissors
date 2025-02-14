import tkinter as tk
import random
import time

class Ball:
    def __init__(self, canvas, color, size, x, y, dx, dy):
        self.canvas = canvas
        self.size = size
        self.id = canvas.create_oval(x, y, x + size, y + size, fill=color)
        self.dx = dx
        self.dy = dy

    def move(self):
        coords = self.canvas.coords(self.id)
        if coords[0] <= 0 or coords[2] >= self.canvas.winfo_width():
            self.dx = -self.dx
        if coords[1] <= 0 or coords[3] >= self.canvas.winfo_height():
            self.dy = -self.dy
        self.canvas.move(self.id, self.dx, self.dy)

class Obstacle:
    def __init__(self, canvas, x, y, width, height):
        self.canvas = canvas
        self.id = canvas.create_rectangle(x, y, x + width, y + height, fill='black')

def main():
    root = tk.Tk()
    root.title("Bouncing Balls")
    canvas = tk.Canvas(root, width=800, height=600, bg='white')
    canvas.pack()

    balls = []
    for _ in range(16):
        size = random.randint(20, 50)
        x = random.randint(size, 800 - size)
        y = random.randint(size, 600 - size)
        dx = random.choice([-3, -2, -1, 1, 2, 3])
        dy = random.choice([-3, -2, -1, 1, 2, 3])
        ball = Ball(canvas, 'blue', size, x, y, dx, dy)
        balls.append(ball)

    obstacles = [
        Obstacle(canvas, 200, 150, 100, 20),
        Obstacle(canvas, 400, 300, 20, 100),
        Obstacle(canvas, 600, 450, 100, 20)
    ]

    def update():
        for ball in balls:
            ball.move()
        root.after(16, update)

    update()
    root.mainloop()

if __name__ == "__main__":
    main()