## Problem

Given an undirected tree, find the diameter of the tree

---

## Solution
- Run BFS from any point and find point at maximum distance to it(say u1)
- From u1 run same BFS loop to find max distance point (say u2)
- distance b/w u1 and u2 is the diameter
- Also, maximum distance from any node to another node is `D[v]=max(dist[u1,v],dist[u2,v])`

---

## Code

```codefile
../Tree_Diameter.cpp
```
