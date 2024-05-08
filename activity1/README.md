# Activity 1 - Repetition and Selection

## Objective

This program aims to review fundamental concepts related to the C programming language, such as variable declaration, input and output, expressions, assignment, selection, and repetition commands.

## Problem

The XYZ company specializes in digital marketing. From a survey, they obtained responses from various users, including: User Identification Code (ID), gender (SEX), and age (AGE). The task is to generate a report with the profile of the surveyed users based on the input data. The report should include the following:

1. The sum of the ages of the surveyed individuals.
2. The total number of people surveyed.
3. The average age of the surveyed individuals.
4. The quantity of male individuals (m or M).
5. The quantity of female individuals (f or F).
6. The quantity of individuals of other genders (different from m, M, f, or F).
7. The highest age among the surveyed individuals.
8. The ID of the oldest person.
9. The lowest age among the surveyed individuals.
10. The ID of the youngest person.

The last input value contains the data `ID = 0`, `SEX = 'x'`, and `AGE = 0`.

For example, for the input data:

```
1001 m 23
1002 f 20
1003 o 20
1004 m 20
1005 f 30
1006 f 40
1007 m 76
0 x 0
```

The program should present the following report:

```
Relatório
+------------------+--------+
| Soma das idades  |   229  |
| Total de pessoas |     7  |
| Media de idades  |  32.7  |
| Homens           |     3  |
| Mulheres         |     3  |
| Outros           |     1  |
| Maior idade      |    76  |
| ID do mais velho |  1007  |
| Menor idade      |    20  |
| ID do mais novo  |  1004  |
+------------------+--------+
```

## Description

1. Develop the program as specified with the name `activity1.c`.

2. Implement and test the program as requested. Tests should be performed by redirecting data input in the program call. For example, if the program executable is named `activity1`, input the data in a file named `data.txt` and call:

```bash
./activity1 < data.txt
```

3. The result should be presented with the report formatting, as shown above (using characters +, |, and -, forming a frame around the values).

4. If there are multiple people with the highest or lowest age, the program should present the last value (highest or lowest) found.

***
