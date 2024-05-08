# Heuristic Optimization for Graph TSP

## Objective

The objective of this project is to implement a heuristic optimization algorithm for the Traveling Salesman Problem (TSP) on graphs. The algorithm aims to find an approximate solution to the TSP by iteratively improving an initial solution through local search and randomization techniques.

## Problem

The Traveling Salesman Problem (TSP) is a classic optimization problem where the goal is to find the shortest possible route that visits each city exactly once and returns to the original city. Given a graph representing cities and the distances between them, the problem is to find a tour that minimizes the total distance traveled.

The input consists of a text file containing information about the cities and their coordinates, as well as the time limit for the optimization algorithm. The coordinates represent the positions of the cities in a two-dimensional space. The algorithm then constructs a graph based on this information.

The algorithm implemented in `main.cpp` reads the input file, constructs the graph, and applies a heuristic optimization approach to find an approximate solution to the TSP. It starts with an initial solution generated by a heuristic method (`heuristics.h`), then improves this solution through local search and randomization techniques.

The output consists of the filename, the sequence of cities representing the tour, and the total distance traveled. The algorithm attempts to optimize the solution within the specified time limit and outputs the best solution found within that time frame.

For example, consider the following input:

`files/a28.txt`
```
1 288 149
2 288 129
3 270 133
4 256 141
5 256 157
...
280 280 133
```

Each line represents a vertex, where the first value is the vertex number, and the subsequent two values are the x and y coordinates, respectively. These coordinates represent the positions of the vertices in a two-dimensional space.

After applying the heuristic optimization algorithm, a possible solution for this input example could be:

```
11 78 96 113 125 
1189
```

This output indicates the following:
- The sequence of cities visited in the tour is: 11, 78, 96, 113, and 125.
- The total distance traveled in the tour is 1189 units.

***
