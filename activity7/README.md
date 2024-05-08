# Graph Analysis and MST Finding with Kruskal's Algorithm

## Objective

The objective of this project is to implement Kruskal's algorithm to find the Minimum Spanning Tree (MST) of a given graph. Additionally, it aims to identify the largest subgraph consisting of three vertices within the MST.

## Problem

In this exercise, we are provided with a set of coordinates representing vertices in a graph. Each vertex is identified by its coordinates (x, y). The task is to read this input and construct a graph using an adjacency list representation. Then, Kruskal's algorithm is applied to find the MST of the graph.

For instance, consider the following input example:

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

The objective is to construct a graph from these vertices, where each vertex is connected to its neighboring vertices based on their Euclidean distance. Then, Kruskal's algorithm is applied to find the MST of this graph. Finally, within the MST, we aim to identify the largest subgraph consisting of three vertices.

Expected Output for the provided input:

```
275 5 6
30
```

This output indicates that the largest subgraph consists of vertices 5, 6, and 275 within the MST, with a total edge weight of 30.

