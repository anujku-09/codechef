# CHEFSCOUNTRY

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Roads Construction in Chefs Country

Chef's country has `N` cities, and `M` roads between them. The goal is to construct new roads so that there is a route between any two cities.

Find out the minimum number of roads required.

### Input Format
- The first line consists of two space separated integers, N and M, representing the number of cities and number of roads between them.
- Cities are numbered from 1 to N.
- The subsequent M lines describe the roads, each containing two integers, u and v, describing a road between city u and city v.
- Each road links two distinct cities, and at most one road exists between any two cities.
### Output Format
- Output the number of minimum roads required to connect all the cities.
### Constraints
- $1 \leq N \leq 200000$
- $1 \leq M \leq N(N-1)/2$
- $1 \leq u_i, v_i \leq N$
- $u_i \neq v_i$ for each $1 \leq i \leq M$.
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
```

```
0
```

### Explanation:

There already exists paths between any two pair of cities and hence no new road needs to be constructed.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-31T10:31:42.422Z  

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
        adj[v].push_back(u);
    }
    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }
    cout << count - 1 << endl;

    return 0;
}

```

---

[View on CodeChef](https://www.codechef.com/problems/CHEFSCOUNTRY)