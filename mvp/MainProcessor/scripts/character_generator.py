import tkinter
from tkinter import *
from functools import partial

num_cols = 8
num_rows = 8
buttons = [[0 for i in range(num_cols)] for j in range(num_rows)]
values = [["0" for i in range(num_cols)] for j in range(num_rows)]

def change_value(row, col):
    if values[row][col] == "1":
        values[row][col] = "0"
        buttons[row][col].configure(bg="white")
    else:
        values[row][col] = "1"
        buttons[row][col].configure(bg="black")


def convert(event):
    aggregate = []

    for i in range(0, num_cols):
        for j in range(0, num_rows):
            aggregate.append(values[j][i])

    to_output = "{"

    for i in range (0, num_cols*num_rows):
        if i == 0:
            to_output += "0b"
        elif i % num_rows == 0:
            to_output += ", 0b"
        
        to_output += aggregate[i]

    to_output+="},"

    print(to_output)

def clear(event):
    for i in range(0, num_cols):
        for j in range(0, num_rows):
            values[i][j] = "0"
            buttons[i][j].configure(bg="white")


if __name__ == "__main__":


    top_level = tkinter.Tk()
    top_level.bind('<Control-f>', convert)
    top_level.bind('<Control-e>', clear)
    frame = Frame(top_level)

    top_level.title("MAX7219 Custom Character Generator")
    top_level.geometry("400x400")

    Grid.rowconfigure(top_level, 0, weight=1)
    Grid.columnconfigure(top_level, 0, weight=1)

    frame.grid(row=0, column=0, sticky=N+S+E+W)

    grid=Frame(frame)

    grid.grid(sticky=N+S+E+W, column = 0, row=num_rows, columnspan=20)
    Grid.rowconfigure(frame, num_rows, weight=1)
    Grid.columnconfigure(frame, 0, weight=1)

    for i in range(0,num_cols):
        for j in range(0,num_rows):
            buttons[i][j] = tkinter.Button(frame, command= partial(change_value,i,j))
            buttons[i][j].grid(row=i, column=j, sticky=N+S+E+W)
    
    for i in range(0, num_cols):
        Grid.columnconfigure(frame, i, weight=1)

    for i in range(0, num_rows):
        Grid.rowconfigure(frame, i, weight = 1)   

    top_level.mainloop()
