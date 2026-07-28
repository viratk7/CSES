## Problem

Find maximum matching in a tree
Each node can be matched with at max one other adjacent node

---
## Solution

- `dp[node][0]`: node in single
- `dp[node][1]`: node in taken
- `dp[node][0] = sum over all child(max(dp[child][0],dp[child][1]))`
- `dp[node][1]=max(dp[node][1],1+dp[node][0]-max(dp[child][0],dp[child][1])+dp[child][0]);`

---
## Code

```codefile
../Tree_Matching.cpp
```
