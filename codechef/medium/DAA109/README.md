# DAA109

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Check Reachability

You are given a graph of $N$ vertices - numbered from $1$ to $N$ and $M$ edges between them.
The $i^{th}$ edge connects the $A_i$ node to $B_i$. The edges are directed.

You live at the vertex $1$, output all the vertices that you can visit. You can travel using the given edges.

### Input Format
- The first line of input will contain a two integers $N$ and $M$, denoting the number of vertices and edges.
- Next $M$ lines describes the edges. $i-th$ of these $M$ lines contains two space-separated integers $A_i$ and $B_i$ denoting there exists a directed edge from $A_i$ to $B_i$.
### Output Format

Output all the nodes you can visit from the node 1, in increasing order of their index.

### Constraints
- $2 \leq N, M \leq 2 \cdot 10^5$
- $1 \leq A_i, B_i \leq N$
### Sample 1:
Input
Output

```
5 6
1 3
4 3
3 2
2 4
5 4
3 1

```

```
1 2 3 4 
```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-31T10:20:53.108Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
bool visited[200005];

void dfs(int node) {
    visited[node] = true;

    for (int v : adj[node]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        if (visited[i]) {
            cout << i << " ";
        }
    }

    return 0;
}

```

---

[View on CodeChef](https://www.codechef.com/problems/DAA109)