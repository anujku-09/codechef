# BSIT

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Beautiful Sets in a Tree

You are given a rooted tree consisting of $N$ nodes, rooted at node $1$.

The tree is represented by the array $parent$, where $parent[i]$ denotes the parent of node $i$, and $parent[1] = 0$.

Each node has a color assigned to it, represented by the array $color$, where $color[i]$ denotes the color of node $i$.

A set of nodes is considered  **beautiful**  if it satisfies both of the following conditions:

- All selected nodes have distinct colors.
- For every pair of selected nodes $(u, v)$, either $u$ is an ancestor of $v$ or $v$ is an ancestor of $u$.

You are given $Q$ queries, represented by the array $queries$, where $queries[i]$ denotes the root of the subtree for the $i^{\text{th}}$ query.

For each query, determine the maximum possible size of a beautiful set that can be formed using only the nodes in the subtree rooted at $queries[i]$.

Find the  **sum of the answers**  modulo $10^9 + 7$.

### Input Format
- The first line contains an integer $N$ — the number of nodes.
- The second line contains $N$ space-separated integers representing the array $parent$, where $parent[i]$ denotes the parent of node $i$. It is guaranteed that $parent[1] = 0$.
- The third line contains $N$ space-separated integers representing the array $color$, where $color[i]$ denotes the color assigned to node $i$.
- The fourth line contains an integer $Q$ — the number of queries.
- The fifth line contains $Q$ space-separated integers representing the array $queries$, where $queries[i]$ denotes the root of the subtree for the $i^{\text{th}}$ query.
### Output Format
- Print a single integer — the sum of the maximum beautiful set sizes for all queries, modulo $10^9 + 7$.
### Constraints
- $1 \le N, Q \le 2 \times 10^5$
- $0 \le parent[i] \le N$
- $parent[1] = 0$
- $1 \le color[i] \le 10^9$
- $1 \le queries[i] \le N$
### Sample 1:
Input
Output

```
5
0 1 2 1 3
4 3 4 3 5
3
4 3 3
```

```
5
```

### Explanation:
- $parent = [0, 1, 2, 1, 3]$
- $color = [4, 3, 4, 3, 5]$
- $queries = [4, 3, 3]$

For the first query, $queries[1] = 4$. The subtree rooted at node $4$ contains only node $4$, so the maximum beautiful set has size $1$.

For the second query, $queries[2] = 3$. The subtree rooted at node $3$ contains nodes $\{3, 5\}$. Both nodes have distinct colors, and node $3$ is an ancestor of node $5$, so the maximum beautiful set has size $2$.

For the third query, $queries[3] = 3$, which is identical to the second query. Hence, the maximum beautiful set again has size $2$.

Therefore, the required sum is $1 + 2 + 2 = 5$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-29T10:13:19.464Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007LL;

struct SegmentTree {
    int n;
    vector<int> mx, lazy;

    SegmentTree(const vector<int>& a) {
        n = (int)a.size();
        mx.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(1, 0, n, a);
    }

    void build(int p, int l, int r, const vector<int>& a) {
        if (r - l == 1) {
            mx[p] = a[l];
            return;
        }

        int m = (l + r) / 2;
        build(p * 2, l, m, a);
        build(p * 2 + 1, m, r, a);
        pull(p);
    }

    void pull(int p) {
        mx[p] = max(mx[p * 2], mx[p * 2 + 1]);
    }

    void apply(int p, int value) {
        mx[p] += value;
        lazy[p] += value;
    }

    void push(int p) {
        if (lazy[p] != 0) {
            apply(p * 2, lazy[p]);
            apply(p * 2 + 1, lazy[p]);
            lazy[p] = 0;
        }
    }

    void add(int p, int l, int r,
             int ql, int qr, int value) {
        if (qr <= l || r <= ql) return;

        if (ql <= l && r <= qr) {
            apply(p, value);
            return;
        }

        push(p);
        int m = (l + r) / 2;

        add(p * 2, l, m, ql, qr, value);
        add(p * 2 + 1, m, r, ql, qr, value);

        pull(p);
    }

    void add(int l, int r, int value) {
        if (l < r) add(1, 0, n, l, r, value);
    }

    int query(int p, int l, int r,
              int ql, int qr) {
        if (qr <= l || r <= ql) return INT_MIN;

        if (ql <= l && r <= qr) return mx[p];

        push(p);
        int m = (l + r) / 2;

        return max(
            query(p * 2, l, m, ql, qr),
            query(p * 2 + 1, m, r, ql, qr)
        );
    }

    int query(int l, int r) {
        return query(1, 0, n, l, r);
    }
};

struct Frame {
    int u;
    int nextChild;
    int oldLast;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> parent(n + 1);
    vector<vector<int>> child(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> parent[i];
        if (parent[i] != 0)
            child[parent[i]].push_back(i);
    }

    vector<int> color(n + 1);

    for (int i = 1; i <= n; ++i)
        cin >> color[i];

    int q;
    cin >> q;

    vector<int> queries(q);

    for (int i = 0; i < q; ++i)
        cin >> queries[i];

    vector<int> vals(color.begin() + 1, color.end());
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    for (int i = 1; i <= n; ++i) {
        color[i] = lower_bound(
            vals.begin(), vals.end(), color[i]
        ) - vals.begin();
    }

    vector<int> depth(n + 1, 0);
    vector<int> tin(n + 1), tout(n + 1);
    vector<int> distinctPrefix(n + 1, 0);
    vector<int> sameParent(n + 1, 0);
    vector<int> euler(n);

    int timer = 0;
    int maxDepth = 0;
    unordered_map<int, int> lastNode;
    lastNode.reserve(2 * n);
    lastNode.max_load_factor(0.7);

    vector<Frame> dfs;
    dfs.reserve(n);

    tin[1] = timer;
    euler[timer++] = 1;
    distinctPrefix[1] = 1;
    lastNode[color[1]] = 1;

    dfs.push_back({1, 0, 0});

    while (!dfs.empty()) {
        Frame &f = dfs.back();
        int u = f.u;

        if (f.nextChild < (int)child[u].size()) {
            int v = child[u][f.nextChild++];

            depth[v] = depth[u] + 1;
            maxDepth = max(maxDepth, depth[v]);

            int oldLast = 0;
            auto it = lastNode.find(color[v]);

            if (it != lastNode.end())
                oldLast = it->second;

            sameParent[v] = oldLast;
            distinctPrefix[v] =
                distinctPrefix[u] + (oldLast == 0);

            lastNode[color[v]] = v;

            tin[v] = timer;
            euler[timer++] = v;

            dfs.push_back({v, 0, oldLast});
        } else {
            tout[u] = timer;

            int oldLast = f.oldLast;

            if (oldLast == 0)
                lastNode.erase(color[u]);
            else
                lastNode[color[u]] = oldLast;

            dfs.pop_back();
        }
    }
    vector<vector<int>> sameColorChildren(n + 1);

    for (int u = 2; u <= n; ++u) {
        if (sameParent[u] != 0)
            sameColorChildren[sameParent[u]].push_back(u);
    }

    vector<int> initial(n);

    for (int i = 0; i < n; ++i)
        initial[i] = distinctPrefix[euler[i]];

    SegmentTree seg(initial);

    vector<vector<int>> nodesAtDepth(maxDepth + 1);

    for (int u = 1; u <= n; ++u)
        nodesAtDepth[depth[u]].push_back(u);

    vector<int> answer(n + 1, 0);
    for (int d = 0; d <= maxDepth; ++d) {
        for (int u : nodesAtDepth[d]) {
            answer[u] = seg.query(tin[u], tout[u]);
        }


        for (int u : nodesAtDepth[d]) {
            seg.add(tin[u], tout[u], -1);

            for (int v : sameColorChildren[u])
                seg.add(tin[v], tout[v], 1);
        }
    }

    long long result = 0;

    for (int x : queries) {
        result = (result + answer[x]) % MOD;
    }

    cout << result << '\n';

    return 0;
}

```

---

[View on CodeChef](https://www.codechef.com/problems/BSIT)