## Problem

Determine for each node the sum of the distances from the node to all other nodes

---

## Solution
- `sum[node]=sum[parent]-q(# nodes in subtree of node)+k(# nodes in subtree of parent excluding current node)`
- `n=k+q-2`  so `k=n-q-2` so `sum[node]=sum[parent]-2q-2`
- number of nodes in subtree of a node can be calculated in O(1) with preprocessing 
- Run DFS starting from any root to find subtree vector for all nodes
- find sum for root
- run the final DFS call to calc sums

---

## Code

```codefile
../Tree_Distances_II.cpp
```
