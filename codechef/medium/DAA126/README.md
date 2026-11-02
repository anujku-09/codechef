# DAA126

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Single Source Shortest Path

You are given a directed weighted graph with $N$ vertices numbered from $1$ to $N$ and $M$ edges. The cost of traversing an edge is equal to its weight.

Find the minimum total cost of a path from vertex $1$ to every vertex.

Every vertex is reachable from vertex $1$, and the graph contains no negative-weight cycles.

### Input Format
- The first line contains two space-separated integers $N$ and $M$, the number of vertices and edges.
- Each of the next $M$ lines contains three space-separated integers $u_i$, $v_i$, and $w_i$, representing a directed edge from vertex $u_i$ to vertex $v_i$ with weight $w_i$.
### Output Format

Print $N$ space-separated integers on a single line. The $i$-th integer must be the minimum total cost of a path from vertex $1$ to vertex $i$. The distance from vertex $1$ to itself is $0$.

### Constraints
- $1 \leq N \leq 5 \cdot 10^{3}$
- $2 \leq M \leq min(5 \cdot 10^{3}, \frac{N(N-1)}{2})$
- $1 \leq u_i, v_i \leq N$
- $-10^9 \leq w_i \leq 10^9$
- Every vertex is reachable from vertex $1$.
- The graph contains no negative-weight cycles.
- There are no self-loops. Multiple directed edges from the same vertex $u$ to the same vertex $v$ are allowed and may have different weights.
### Sample 1:
Input
Output

```
5 5
1 2 3
2 3 -2
1 3 2
3 4 1
1 5 -1
```

```
0 3 1 2 -1
```

### Explanation:
- Vertex $1$: No edges are traversed, so the cost is $0$.
- Vertex $2$: The path $1 \rightarrow 2$ costs $3$.
- Vertex $3$: The path $1 \rightarrow 2 \rightarrow 3$ costs $3-2=1$.
- Vertex $4$: The path $1 \rightarrow 2 \rightarrow 3 \rightarrow 4$ costs $3-2+1=2$.
- Vertex $5$: The path $1 \rightarrow 5$ costs $-1$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-02T15:16:56.232Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int u[5005], v[5005];
	long long w[5005];
	
	for(int i = 0; i < m; i++) {
	  cin >> u[i] >> v[i] >> w[i];
	}
  
  long long dist[5005];
  for(int i = 1; i <= n; i++) {
    dist[i] = 1e18;
  }
  dist[1] = 0;
  
  for(int i = 1; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(dist[u[j]] != 1e18 && dist[u[j]] + w[j] < dist[v[j]]) {
        dist[v[j]] = dist[u[j]] + w[j];
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    cout << dist[i] << " ";
  }
  cout << endl;
}

```

---

[View on CodeChef](https://www.codechef.com/problems/DAA126)