# Activity 2 - Matrices

## Objective

To use the matrix structure for representation and resolution of programming problems.

## Problem

### Drawing Turtle

The [**Logo**](https://pt.wikipedia.org/wiki/Logo) language, particularly popular among personal computer users, made the concept of turtle graphics famous. Imagine a mechanical turtle moving across a room under the control of a program in C. The turtle holds a pen in one of two positions, up or down. When the pen is down, the turtle draws figures as it moves; when the pen is up, the turtle moves freely without drawing anything. In this problem, you will simulate the operation of the turtle and also create a computerized drawing block.

The set of commands for the turtle that your program must process are as follows:

| Command | Meaning         |
|---------|-----------------|
| u       | lift (up) the pen |
| d       | lower (down) the pen |
| r       | turn right (right, change direction clockwise) |
| l       | turn left (left, change direction counterclockwise) |
| w n     | walk in the current direction n steps |
| p       | print the matrix |
| e       | exit the input of commands for the turtle. |

Suppose the turtle is initially in the upper left corner of the 'floor' and facing right. The following "program" would draw and print a 5 by 5 square.

```
w 10 r w 10 d w 5 r w 5 r w 5 r w 5 u p e
```

As the turtle moves with the pen down, set the appropriate elements of the floor matrix to 1s. When the p (print) command is issued, display an asterisk, or another character of your choice, where there is a 1 in the matrix. Whenever there is a zero, display a '.'. Write a program to implement the turtle graphics features described here. Write several turtle graphics programs to draw interesting shapes. Add other commands to increase the potential of your turtle graphics language.

The result of the program for the given data:

```
. . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . .
. . . . . * * * * * . . . . . . . . . .
. . . . . * . . . * . . . . . . . . . .
. . . . . * . . . * . . . . . . . . . .
. . . . . * . . . * . . . . . . . . . .
. . . . . * * * * * . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . .
```

## Description

1. Develop the program as specified with the name `activity2.c`.

2. Use a matrix named "**piso**", 20 by 20, initialized with zeros. Read the input commands. Always control the current position of the turtle, the direction the turtle is facing, and whether the pen is up or down. Assume that the turtle always starts at position 0,0 of the *piso*, with the pen up and facing right.

3. Implement and test the program as requested. Tests should be performed by redirecting input data during program execution. For example, if the executable of the program is named `activity2`, input the data into a file named `data.txt` and call:

```bash
./activity2 < data.txt
```

***
