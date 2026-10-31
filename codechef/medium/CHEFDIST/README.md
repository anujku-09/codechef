# CHEFDIST

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Minimum Distance Between Two Nodes

Given an undirected and unweighted graph and two nodes $x$ and $y$, find the length of the shortest path between the two nodes. If no path exists, return $-1$.

## Function Declaration
### Function Name

$getMinimumDistance$ – Finds the minimum number of edges required to travel from one node to another in an undirected graph.

### Parameters
- $n$ : An integer representing the number of nodes in the graph.
- $edges$ : A list/vector of pairs where each pair $(u, v)$ represents an undirected edge between nodes $u$ and $v$.
- $x$ : An integer representing the starting node.
- $y$ : An integer representing the destination node.
### Return Value
- Returns an integer — the minimum distance (minimum number of edges) between nodes $x$ and $y$.
- If there is no path between the two nodes, return $-1$.
## Constraints:
- $1 \leq n \leq 200000$ - number of nodes.
- $1 \leq m \leq 200000$ - number of edges.
- $1 \leq u_i, v_i, x, y \leq N$
- $u_i \neq v_i$ for each $1 \leq i \leq m$.
- x and y can never be same in the test cases.

 **The input and output formats provided below are only for testing with custom inputs. You only need to return the value. Printing is handled by the driver code.** 

### Input Format
- The first line consists of two space separated integers, $n$ and $m$, representing the number of nodes and edges.
- Nodes are numbered from $1$ to $n$.
- The subsequent $m$ lines describe the connections, each containing two integers, $u$ and $v$, describing the edges.
- Each edge links two distinct nodes, and at most one edge exists between any two nodes.
- The last line consists of two space separated integers, $x$ and $y$, the given two nodes.
### Output Format
- If there is a path between $x$ and $y$, print the shortest distance (i.e., the minimum no. of edges) between them.
- If no path exist, return $-1$.
### Sample 1:
Input
Output

```
5 6
1 2
2 3
1 3
3 5
2 4
4 5
2 5
```

```
2
```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-31T10:28:37.815Z  

```c_cpp
class Solution {
public:
    int getMinimumDistance(int n, vector<pair<int, int>> edges, int x, int y) {
        vector<vector<int>> adj(n + 1);

        for (const auto& e : edges) {
            int u = e.first;
            int v = e.second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> dist(n + 1, -1);
        queue<int> q;

        q.push(x);
        dist[x] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (u == y) {
                return dist[y];
            }

            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist[y];
    }
};
```

---

[View on CodeChef](https://www.codechef.com/problems/CHEFDIST)