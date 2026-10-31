# TOPOSORTCS

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Find Course Schedule

You have to complete N courses. There are M requirements of the form "course a has to be completed before course b". Find an order in which you can complete the courses.

### Input Format
- The first line consists of two space separated integers, N and M, representing the number of courses and number of requirements.
- Courses are numbered from 1 to N.
- The subsequent M lines describe the requirements, each containing two integers, a and b, describing the requirements of the form course a has to be completed before course b.
### Output Format
- Output N space separated integers, describing the order of N courses which should be taken in order to complete all of them.
- If it's not possible to complete all the courses, output -1.
### Constraints
- $1 \leq N \leq 10^5$
- $0 \leq M \leq 2 \times 10^5$
- $1 \leq u_i, v_i \leq N$
- $u_i \neq v_i$
### Sample 1:
Input
Output

```
6 6
1 2
1 3
2 4
3 5
5 6
6 3
```

```
-1
```

### Explanation:

Courses 3, 5, and 6 are dependent on each other; hence, it is not possible to complete all the courses.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-31T10:38:59.312Z  

```c_cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);

        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (ans.size() != n) {
        cout << -1 << "\n";
    } else {
        for (int i = 0; i < n; i++) {
            cout << ans[i] << (i + 1 == n ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/TOPOSORTCS)