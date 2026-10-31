# NUMISLAND2

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Number of island 2

You are given a 2D matrix of size $n \times m$, initially filled with water $0$. You are also given $k$ operations. Each operation consists of a coordinate $(r, c)$ which transforms that water cell into an island $1$.

After each operation, you need to determine the total number of distinct islands present in the matrix. An island is a group of connected 1s (horizontal or vertical).

Note: If an operation is performed on a cell that is already marked as land, the grid remains unchanged, and the number of islands also stays the same.

Return an array of size $k$ containing the number of islands after each operation.

### Function Declarations

 **Function Name**  $numOfIslands$ – Determines the total number of distinct islands in an $n \times m$ grid after each land addition operation.

- Parameters $n$ : An integer representing the number of rows in the matrix. $m$ : An integer representing the number of columns in the matrix. $k$ : An integer representing the total number of operations. $operators$ : A 2D integer array of size $k \times 2$, where each element $operations[i]$ is a pair $[r, c]$ representing the row and column coordinates to be transformed from water to land ($1$).
- Return Value Returns an array of integers of size $k$, where the element at index $i$ represents the total number of distinct islands present in the matrix immediately after executing the $i^\text{th}$ operation.
## Constraints:
- $1 \le n, m \le 1000$(Matrix can be up to $1,000,000$ cells)
- $1 \le k \le 10^4$ (Number of operations)
- $0 \le A[i][0] < n$
- $0 \le A[i][1] < m$
- $1 \leq T \leq 100$
- The sum of $n \times m$ over all test cases does not exceed $5 \times 10^6$
- The sum of $k$ over all test cases does not exceed $10^5$

 **The input and output formats provided below are only for testing with custom inputs. You only need to return the value. Printing is handled automatically.** 

### Input Format
- The first line contains an integer $T$ — the number of test cases.
- For each test case: The first line contains three integers: $n$, $m$ (matrix dimensions) and $k$ (number of operations). The next $k$ lines each contain two integers, $r$ and $c$, representing the coordinates of the operation.
### Output Format
- For each test case, output $k$ space-separated integers (or a list) representing the number of islands after each of the $k$ operations.
### Sample 1:
Input
Output

```
1
4 5 4
1 1
0 1
3 3
3 4
```

```
1 1 2 2
```

### Explanation:
- $(1, 1)$ added $\rightarrow$ $1$ island.
- $(0, 1)$ added $\rightarrow$ adjacent to $(1, 1)$, merges $\rightarrow$ $1$ island.
- $(3, 3)$ added $\rightarrow$ separate from others $\rightarrow$ $2$ islands.
- $(3, 4)$ added $\rightarrow$ adjacent to $(3, 3)$, merges $\rightarrow$ $2$ islands.
### Sample 2:
Input
Output

```
1
4 5 12
0 0
0 0
1 1
1 0
0 1
0 3
1 3
0 4
3 2
2 2
1 2
0 2
```

```
1 1 2 1 1 2 2 2 3 3 1 1
```

### Explanation:
- When $(0, 0)$ is added again at the second step, the count remains $1$ because it was already land.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-31T10:51:57.753Z  

```c_cpp
class Solution {
    vector<int> parent, sz;

    int findParent(int node) {
        if (parent[node] == node) {
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    bool unite(int u, int v) {
        u = findParent(u);
        v = findParent(v);

        if (u == v) {
            return false;
        }

        if (sz[u] < sz[v]) {
            swap(u, v);
        }

        parent[v] = u;
        sz[u] += sz[v];

        return true;
    }

public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>>& operators) {
        int total = n * m;

        parent.resize(total);
        sz.assign(total, 1);

        for (int i = 0; i < total; i++) {
            parent[i] = i;
        }

        vector<bool> land(total, false);
        vector<int> ans;

        int islands = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (auto &op : operators) {
            int r = op[0];
            int c = op[1];

            int node = r * m + c;

            if (land[node]) {
                ans.push_back(islands);
                continue;
            }

            land[node] = true;
            islands++;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int adjNode = nr * m + nc;

                    if (land[adjNode]) {
                        if (unite(node, adjNode)) {
                            islands--;
                        }
                    }
                }
            }
            ans.push_back(islands);
        }
        return ans;
    }
};

```

---

[View on CodeChef](https://www.codechef.com/problems/NUMISLAND2)