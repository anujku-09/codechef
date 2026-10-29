# TSIN

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Tree Subtree Intersection

You are given a tree consisting of $N$ nodes, numbered from $1$ to $N$.

The tree is represented by the array $parent$, where $parent[i]$ denotes the parent of node $i$ in an initial rooting of the tree at node $1$. It is guaranteed that $parent[1]=0$. For every $i>1$, there is an undirected edge between nodes $i$ and $parent[i]$.

You are also given two distinct nodes $A$ and $B$.

For two nodes $U$ and $V$, define the beauty of $(U,V)$ as the number of nodes that belong to both:

- The subtree of $U$ when the tree is rooted at $A$.
- The subtree of $V$ when the tree is rooted at $B$.

The subtree of a node includes the node itself.

You are given $Q$ queries, represented by the array $queries$. For $1 \le i \le Q$, $queries[i][1]$ and $queries[i][2]$ denote the two encoded node values of the $i^{\text{th}}$ query.

Process the queries in the given order. Let $K$ be the answer to the previous query, with $K=0$ before the first query.

For the $i^{\text{th}}$ query, obtain the nodes $U$ and $V$ as follows:

$$ U=(queries[i][1]+K-1)\bmod N+1 $$
$$ V=(queries[i][2]+K-1)\bmod N+1 $$

The transformed nodes $U$ and $V$ may be equal.

The answer to the query is the beauty of $(U,V)$. After processing the query, set $K$ equal to its answer.

Find the sum of the answers to all queries modulo $10^9+7$.

### Input Format
- The first line contains an integer $N$.
- The second line contains two space-separated integers $A$ and $B$.
- The third line contains $N$ space-separated integers representing the array $parent$.
- The fourth line contains an integer $Q$.
- Each of the next $Q$ lines contains two space-separated integers $queries[i][1]$ and $queries[i][2]$, representing the two encoded node values of the $i^{\text{th}}$ query.
### Output Format

Print a single integer — the sum of the answers to all queries modulo $10^9+7$.

### Constraints
- $2 \le N \le 10^5$
- $1 \le A,B \le N$
- $A \ne B$
- $parent[1]=0$
- $1 \le parent[i] \le N$ for $2 \le i \le N$
- The array $parent$ represents a valid tree rooted at node $1$.
- $1 \le Q \le 10^5$
- $1 \le queries[i][j] \le N$ for $1 \le i \le Q$ and $1 \le j \le 2$
### Sample 1:
Input
Output

```
2
1 2
0 1
1
1 2
```

```
2
```

### Explanation:

The given arrays are:

- $parent=[0,1]$
- $queries=[[1,2]]$

Initially, $K=0$.

For the first query:

$$ U=(queries[1][1]+K-1)\bmod N+1 $$
$$ U=(1+0-1)\bmod 2+1=1 $$

Similarly,

$$ V=(queries[1][2]+K-1)\bmod N+1 $$
$$ V=(2+0-1)\bmod 2+1=2 $$

Therefore, the transformed query is $(1,2)$.

When the tree is rooted at $A=1$, the subtree of node $1$ contains nodes $\{1,2\}$.

When the tree is rooted at $B=2$, the subtree of node $2$ also contains nodes $\{1,2\}$.

Their intersection contains both nodes, so the answer is $2$.

Therefore, the sum of the answers is $2$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-29T05:29:35.843Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int n, a_node, b_node, q;
vector<vector<int>> adj;
vector<int> tin, tout, sz, parent_A;
vector<int> child_towards_B;
vector<bool> on_path_to_B;
int timer_dfs = 0;

void dfs(int u, int p) {
    tin[u] = ++timer_dfs;
    sz[u] = 1;
    parent_A[u] = p;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
    tout[u] = ++timer_dfs;
}

// Returns true if u is an ancestor of v (or u == v)
bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n)) return 0;
    cin >> a_node >> b_node;

    adj.assign(n + 1, vector<int>());
    for (int i = 1; i <= n; ++i) {
        int p;
        cin >> p;
        if (p != 0) {
            adj[i].push_back(p);
            adj[p].push_back(i);
        }
    }

    tin.resize(n + 1);
    tout.resize(n + 1);
    sz.resize(n + 1);
    parent_A.resize(n + 1);
    child_towards_B.assign(n + 1, 0);
    on_path_to_B.assign(n + 1, false);

    // Root the tree at A
    dfs(a_node, 0);

    // Identify all ancestors of B on the path from B to A
    int curr = b_node;
    while (curr != a_node) {
        int p = parent_A[curr];
        child_towards_B[p] = curr;
        on_path_to_B[p] = true;
        curr = p;
    }

    cin >> q;
    long long total_sum = 0;
    long long last_ans = 0;

    for (int i = 0; i < q; ++i) {
        long long q1, q2;
        cin >> q1 >> q2;

        int u = (q1 + last_ans - 1) % n + 1;
        int v = (q2 + last_ans - 1) % n + 1;

        int ans = 0;

        if (v == b_node) {
            ans = sz[u];
        } else if (on_path_to_B[v]) {
            int c = child_towards_B[v];
            if (is_ancestor(c, u)) {
                ans = 0;
            } else if (is_ancestor(u, c)) {
                ans = sz[u] - sz[c];
            } else {
                ans = sz[u];
            }
        } else {
            if (is_ancestor(u, v)) {
                ans = sz[v];
            } else if (is_ancestor(v, u)) {
                ans = sz[u];
            } else {
                ans = 0;
            }
        }

        last_ans = ans;
        total_sum = (total_sum + ans) % MOD;
    }

    cout << total_sum << "\n";

    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/TSIN)