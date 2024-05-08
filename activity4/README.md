# Activity 4 - ISBN

## Objective

To use matrices and functions to solve a programming problem.

## Problem

The International Standard Book Number (ISBN) is a code associated with books, which uniquely identifies it. The ISBN consists of a sequence of 10 decimal digits (0,1,2,3,...,9) plus the uppercase letter X, which is used as a tenth digit. Currently, only the first nine digits of an ISBN are used to identify a book. The tenth symbol serves as a check digit to ensure that the preceding nine digits are correct. The check digit is selected such that the computed value, as shown in the table below, is divisible by 11. The character X is used to represent the digit 10. The algorithm used to verify ISBN is relatively simple. Two sums, s1 and s2, are calculated over the digits of the ISBN. s1 is the partial sum of the digits of the ISBN, and s2 is the sum over the partial sums in s1. The ISBN is correct if the value of s2 is divisible by 11. An example will make this procedure clearer. Consider the (correct) ISBN 013162959-X. Calculating the partial sums *s<sub>1</sub>* and *s<sub>2</sub>*, we have:

| Digit| 0   | 1   | 3   | 1   | 6   | 2   | 9   | 5   | 9   | 10  |
|------|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|
| s1   | 0   | 1   | 4   | 5   | 11  | 13  | 22  | 27  | 36  | 46  |
| s2   | 0   | 1   | 5   | 10  | 21  | 34  | 56  | 83  | 119 | 165 |

As can be seen, the total sum is 165, which is divisible by 11.
Your task is to develop a program that implements the function *isbn_dv*. This function should receive a string with the first nine digits of an ISBN number and return the check digit.

## Input

Your program should read the first nine digits of several ISBNs. Each ISBN consists of a single line containing the sequence of digits to be tested. The end is the ISBN 000000000.

## Output

For each ISBN read, your program should write, to the output, the ISBN with the calculated check digit.

## Example

Input

```
089237010
083063637
000000000
```

Output

```
089237010-6
083063637-4
```

## Description

1. Develop the program as specified with the name `activity4.c`.

2. Implement and test the program as requested. Tests should be performed by redirecting input data during program execution. For example, if the executable of the program is named `activity4`, input the data into a file named `data.txt` and call:

```bash
./activity4 < data.txt
```

***
