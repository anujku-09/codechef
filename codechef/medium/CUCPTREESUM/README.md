# CUCPTREESUM

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Village Travel Totals

The  **Ridgepoint district**  has $N$ villages, numbered from $1$ to $N$, joined by $N - 1$ two-way roads. The road network was built so that there is exactly one route between any pair of villages and no route ever loops back on itself — in other words, the villages and roads form a tree.

The  **travel cost**  between two villages is the number of roads on the route between them. The district council wants to know, for every village, how far the postal van would travel in total if it had to visit every other village from there: the sum of the travel costs from that village to all $N - 1$ others.

### Task

For each village $i$, print the sum of the travel costs from village $i$ to every other village.

### Important Requirements
- Every road counts as one unit of cost, in either direction.
- A village's own cost to itself is $0$ and adds nothing to its total.
- The answer for one village can be as large as about $9 \times 10^8$, so a plain $32$-bit accumulator is cutting it fine — prefer a $64$-bit one.
### Input Format

The first line contains a single integer $N$, the number of villages.

Each of the next $N - 1$ lines contains two space-separated integers $u$ and $v$, meaning there is a road between village $u$ and village $v$. When $N = 1$ there are no such lines.

### Output Format

Print $N$ lines. The $i$-th line must contain the sum of the travel costs from village $i$ to all the other villages.

### Constraints
- $1 \le N \le 3 \times 10^4$
- $1 \le u, v \le N$ and $u \ne v$
- The given roads always form a tree.
### Sample 1:
Input
Output

```
6
1 2
1 3
3 4
3 5
3 6

```

```
8
12
6
10
10
10

```

### Sample 2:
Input
Output

```
2
1 2

```

```
1
1

```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-29T10:21:20.607Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> subtree;
vector<long long> ans;
int n;

void dfs1(int u, int parent, int depth) {
    subtree[u] = 1;
    ans[1] += depth;

    for (int v : adj[u]) {
        if (v == parent)
            continue;

        dfs1(v, u, depth + 1);
        subtree[u] += subtree[v];
    }
}

void dfs2(int u, int parent) {
    for (int v : adj[u]) {
        if (v == parent)
            continue;

        ans[v] = ans[u] - subtree[v] + (n - subtree[v]);
        dfs2(v, u);
    }
}

int main() {
    cin >> n;

    adj.resize(n + 1);
    subtree.resize(n + 1);
    ans.resize(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(1, 0, 0);
    dfs2(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}


```

---

[View on CodeChef](https://www.codechef.com/problems/CUCPTREESUM)