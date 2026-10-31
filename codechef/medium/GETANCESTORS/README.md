# GETANCESTORS

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Get all ancestors

Given a Directed Acyclic Graph (**DAG**) with $N$ nodes numbered from $0$ to $N$ - $1$, print in sorted ascending order of ancestors for the $i^{\text{th}}$ node for each node $0$ to $N$ - $1$.

A node `u` is an ancestor of another node `v` if `u` can reach `v` via a set of edges.

### Input Format
- The first line consists of two space separated integers, N and M, representing the number of nodes and edges.
- Nodes are numbered from 0 to N-1.
- The subsequent M lines describe the edges, each containing two integers, u and v, describing the directed edge between nodes u and v.
- The given graph is a DAG.
### Output Format
- Output N lines, ancestors of each node from $0$ to $N - 1$. In case some node doesn't have any ancestor, keep that line empty.
### Constraints
- $1 \leq N \leq 1000$
- $1 \leq M \leq min(2000, N(N-1))/2$
- $0 \leq u_i, v_i \leq N - 1$
- $u_i \neq v_i$ for each $1 \leq i \leq M$.
### Sample 1:
Input
Output

```
5 6
0 1
1 2
0 2
2 4
1 3
3 4
```

```

0
0 1
0 1
0 1 2 3

```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-31T10:47:49.390Z  

```c_cpp
class Solution {
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[node] = true;
        for (int v : adj[node]) {
            if (!vis[v]) {
                dfs(v, adj, vis);
            }
        }
    }

public:
    vector<set<int>> findAncestors(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e.first].push_back(e.second);
        }
        vector<set<int>> ancestors(n);

        for (int i = 0; i < n; i++) {
            vector<bool> vis(n, false);
            dfs(i, adj, vis);

            for (int j = 0; j < n; j++) {
                if (i != j && vis[j]) {
                    ancestors[j].insert(i);
                }
            }
        }

        return ancestors;
    }
};
```

---

[View on CodeChef](https://www.codechef.com/problems/GETANCESTORS)