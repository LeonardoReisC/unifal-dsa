# Graph Analysis with Dijkstra's Algorithm

## Objective

The objective of this project is to implement Dijkstra's algorithm to find the shortest path in a weighted graph. Additionally, it aims to identify the diameter of the graph, which is the longest shortest path between any two vertices.

## Problem

The problem involves reading a graph from a text file, where each line represents an edge in the graph. The input file contains the number of vertices followed by lines representing edges with their corresponding weights. The task is to construct the graph from this input and apply Dijkstra's algorithm to find the shortest path from a specified root vertex to all other vertices. Then, the diameter of the graph, which represents the longest shortest path, is identified.

For example, consider the following input:

`files/n25.txt`
```
25
0 5 13
0 3 1
0 24 5
...
24 17 4
```

Here, the first line indicates that there are 25 vertices in the graph. The subsequent lines represent edges between vertices with their weights. 

After applying Dijkstra's algorithm, the output for this input example is:

```
n25
23 20 13 4 12 
36
```

This output indicates the following:
- The graph is named "25".
- The longest shortest path (diameter) in the graph is from vertex 23 to vertex 12, passing through vertices 20, 13 and 4, with a total weight of 36.

***
