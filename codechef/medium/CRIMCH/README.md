# CRIMCH

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Cricket Match

There are $N$ people numbered from $1$ to $N$ and they want to play a cricket match between them by forming two teams that may not be of the same size. There are $M$ pairs of peoples and for each pair of peoples, they can not be in the same team. Now Chef wants to know if there is any way to split them into two teams such that Chef can organize the cricket match between two teams. If possible then print `"YES"` (without quotes), otherwise print `"NO"` (without quotes).

### Input
- The first line of the input contains a single integer $T$ denoting the number of test cases. The description of $T$ test cases follows.
- The first line of each test case contains two space-separated integers $N$ and $M$.
- Each of the following $M$ lines follows. Each line has two space-separated numbers $u$ and $v$.
### Output

For each test case, output in a single line the answer to the problem.

### Constraints
- $1 \leq T \leq 10$
- $1 \leq N \leq 2000$
- $1 \leq M \leq 10000$
- $1 \leq u < v \leq N$
### Sample 1:
Input
Output

```
2
3 3
1 2
1 3
2 3
4 2
1 4
2 3
```

```
NO
YES
```

### Explanation:

 **Example case 1:**  It's impossible to divide them into two teams.

 **Example case 2:**  Both the teams will look like $[1, 2]$ and $[3, 4]$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-31T10:10:20.795Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> adj[2005];

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int color[2005];

        for (int i = 1; i <= n; i++) {
            color[i] = -1;
        }

        bool possible = true;

        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 0;

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();

                    for (int v : adj[u]) {

                        if (color[v] == -1) {
                            color[v] = 1 - color[u];
                            q.push(v);
                        }
                        else if (color[v] == color[u]) {
                            possible = false;
                            break;
                        }
                    }
                    if (!possible)
                        break;
                }
            }
            if (!possible)
                break;
        }
        if (possible)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}

```

---

[View on CodeChef](https://www.codechef.com/problems/CRIMCH)