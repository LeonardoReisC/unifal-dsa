# Activity 3 - Sudoku

## Objective

To use matrices and functions to solve a programming problem.

## Problem

"[**Sudoku**](https://pt.wikipedia.org/wiki/Sudoku), sometimes written Su Doku, is a logic-based number-placement game. The objective of the game is to fill a 9×9 grid with digits from 1 to 9 in each cell, each row, and each column, consisting of 3×3 subgrids called regions. The puzzle contains some initial clues, which are numbers inserted into some cells, allowing induction or deduction of numbers in empty cells. Each column, row, and region can only have one of each of the numbers 1 to 9. Solving the puzzle requires only logical reasoning and some time. Problems are typically classified based on their completion [...]. It was created by Howard Garns, a 74-year-old retired designer and architect."

Your task is to create a program that reads a value n, n = {2, 3, 4}, which determines the dimension of an n<sup>2</sup> × n<sup>2</sup> square matrix and then reads n<sup>4</sup> values that fill a square matrix representing a solved sudoku game. The matrix can be 4 x 4 (if n = 2), 9 x 9 (if n = 3), or 16 x 16 (if n = 4). With the matrix loaded in memory, your program should evaluate whether the filling is correct or not, indicating the first row and column where the error was found (if any), or the message "Sudoku Ok!". For the Sudoku 16 x 16 game, consider the letters A, B, C, D, E, F, and G to represent the digits 10, 11, 12, 13, 14, 15, and 16, respectively.

For input:

```
3
5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9
```

The program should present the following result:

```
+-------+-------+-------+
| 5 3 4 | 6 7 8 | 9 1 2 |
| 6 7 2 | 1 9 5 | 3 4 8 |
| 1 9 8 | 3 4 2 | 5 6 7 |
+-------+-------+-------+
| 8 5 9 | 7 6 1 | 4 2 3 |
| 4 2 6 | 8 5 3 | 7 9 1 |
| 7 1 3 | 9 2 4 | 8 5 6 |
+-------+-------+-------+
| 9 6 1 | 5 3 7 | 2 8 4 |
| 2 8 7 | 4 1 9 | 6 3 5 |
| 3 4 5 | 2 8 6 | 1 7 9 |
+-------+-------+-------+
Sudoku Ok!
```

## Description

1. Develop the program as specified with the name `activity3.c`.

2. Complete the `sudokuOk` function according to the comments in the source code.

3. Test the program for various input values.

```bash
./activity3 < data.txt
```

***
