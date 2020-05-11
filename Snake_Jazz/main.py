from tkinter import *
import random

WIDTH = 800
HEIGHT = 600
SEG_SIZE = 20
IN_GAME = True

def create_block():
    '''Create a fruit to eat snake'''
    global BLOCK
    posx = SEG_SIZE * random.randint(1, (WIDTH-SEG_SIZE) / SEG_SIZE)
    posy = SEG_SIZE * random.randint(1, (HEIGHT-SEG_SIZE) / SEG_SIZE)
    BLOCK = c.create_oval(posx, posy, posx + SEG_SIZE, posy + SEG_SIZE, fill = "red")

class Segment(object):
    def __init__(self, x, y):
        self.instance = c.create_rectangle(x,y, x+SEG_SIZE, y+SEG_SIZE, fill="white")

class Snake(object):
    def __init__(self, segments):
        self.segments = segments

        self.mapping = {"Down": (0, 1), "Up": (0,-1), "Left": (-1, 0), "Reight": (1, 0) }

        self.vector = self.mapping["Right"]

    def move(self):
        ''' Move the snake '''

        for index in range(len(self.segments)-1):
            segment = self.segments[index].instance
            x1, y1, x2, y2 = c.coords(self.segments[index+1].instance)

            c.coords(segment, x1, y1, x2, y2)

        x1, y1, x2, y2 = c.coords(self.segments[-2].instance)

        c.coords(self.segments[-1].instance,
                 x1 + self.vector[0]*SEG_SIZE,
                 y1 + self.vector[1]*SEG_SIZE,
                 x2 + self.vector[0]*SEG_SIZE,
                 y2 + self.vector[1]*SEG_SIZE)

        def change_direction(self,event):
            '''Change direction'''

            if event.keysym in self.mapping:
                self.vector = self.mapping[event.keysym]

        def add_segment(self):
            '''Add by segment snake'''

            last_seg = c.coords(self.segments[0].instance)

            x = last_seg[2] - SEG_SIZE
            y = last_seg[3] - SEG_SIZE

            self.segments.insert(0, Segment(x,y))



#s = Snake(segments)

def start_game():
    global s
    create_block()
    s = create_snake()
    c.bind("<KeyPress>", s.change_direction)
    #main()

def create_snake():
    segments = [Segment(SEG_SIZE, SEG_SIZE),
                Segment(SEG_SIZE * 2, SEG_SIZE),
                Segment(SEG_SIZE * 3, SEG_SIZE)]
    return Snake(segments)

root = Tk()
root.title("Snake")

c = Canvas(root, width=WIDTH, height=HEIGHT, bg="#003300")
c.grid()
c.focus_set()


start_game()
root.mainloop()