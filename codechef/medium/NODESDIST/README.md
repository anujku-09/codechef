# NODESDIST

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Distance between two nodes

Given an undirected connected tree with  **N**  nodes, numbered from  **1**  to  **N**, and rooted at node  **1**, and two nodes $u$ and $v$, find the distance between these two nodes. (**Note:**  the distance between two nodes is the no. of edges in the simple path between them.)

For example, in the following tree, the distance between nodes $3$ and $7$ is $4$.

### Input Format
- The first line of the input contains three space separated integers $N$, $u$ and $v$ — the number of nodes, and two given nodes.
- The next $N - 1$ lines describe the edges. The $i$-th of these $N - 1$ lines contains two space-separated integers $u_i$ and $v_i$, denoting a bidirectional edge between $u_i$ and $v_i$.
### Output Format
- Output on the single line, the distance between the nodes $u$ and $v$.
### Constraints
- $1 \leq N \leq 100000$
- $1 \leq u_i, v_i \leq N$
- $1 \leq u, v \leq N$
### Sample 1:
Input
Output

```
7 3 7
1 2
1 4
2 5
2 3
2 6
4 7
```

```
4
```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-05T14:37:43.297Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, u, v;
	cin >> n >> u >> v;
	int st_u = u, st_v = v;
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < n - 1; i++){
	    int a, b;
	    cin >> a >> b;
	    adj[a].push_back(b);
	    adj[b].push_back(a);
	}
	vector<int> par(n + 1, 0);
	vector<int> dep(n + 1, 0);
	queue<int> q;
	q.push(1);
	par[1] = -1;
	while(!q.empty()){
	    int node = q.front();
	    q.pop();
	    for(int neigh : adj[node]){
	        if(neigh == par[node]) continue;
	        par[neigh] = node;
	        dep[neigh] = dep[node] + 1;
	        q.push(neigh);
	    }
	}
	while(dep[u] > dep[v]){
	    u = par[u];
	}
	while(dep[v] > dep[u]){
	    v = par[v];
	}
	while(u != v){
	    u = par[u];
	    v = par[v];
	}
	int lca = u;
	int ans = dep[st_u] + dep[st_v] - 2*dep[lca];
	cout << ans << endl;
	return 0;
}

```

---

[View on CodeChef](https://www.codechef.com/problems/NODESDIST)