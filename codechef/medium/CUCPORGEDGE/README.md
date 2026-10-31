# CUCPORGEDGE

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Extra Reporting Line

 **Northgate Logistics**  keeps its org chart as a list of reporting lines. Each line is written as a pair $u\ v$, meaning  *employee $v$ reports to manager $u$*, and a line points only one way.

A correct chart on $N$ employees looks like this: exactly one employee — the director — reports to nobody, every other employee reports to exactly one manager, and following the reporting lines upwards from anybody always leads to the director. That takes exactly $N - 1$ lines.

The chart in front of you has $N$ lines, one too many: somebody added a single extra reporting line to an otherwise correct chart. That one extra line may have given an employee a second manager, or closed a loop of people reporting to each other, or both.

### Task

Find a reporting line whose removal turns the chart back into a correct one. If more than one line would work, print the one that appears  **last**  in the input.

### Important Requirements
- Reporting lines are directed: $u\ v$ is not the same as $v\ u$.
- The input is always a correct chart plus exactly one extra line, so an answer always exists.
- When several lines would work, the answer is the one listed last.
### Input Format

The first line contains a single integer $N$, the number of employees (and also the number of reporting lines).

Each of the next $N$ lines contains two space-separated integers $u$ and $v$, meaning employee $v$ reports to manager $u$.

### Output Format

Print the reporting line to remove, as two space-separated integers in the same order as it was given: the manager first, then the employee.

### Constraints
- $3 \le N \le 1000$
- $1 \le u, v \le N$ and $u \ne v$
- No reporting line is listed twice.
- The chart is always a correct chart plus one extra line.
### Sample 1:
Input
Output

```
3
1 2
1 3
2 3

```

```
2 3

```

### Sample 2:
Input
Output

```
5
1 2
2 3
3 4
4 1
1 5

```

```
4 1

```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-31T10:16:37.245Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> edges(n);

    for (int i = 0; i < n; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    for (int remove = n - 1; remove >= 0; remove--) {
        vector<int> adj[1005];
        int indegree[1005] = {0};

        for (int i = 0; i < n; i++) {
            if (i == remove)
                continue;

            int u = edges[i].first;
            int v = edges[i].second;

            adj[u].push_back(v);
            indegree[v]++;
        }

        int root = -1;
        int count = 0;
        bool valid = true;

        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                root = i;
                count++;
            }
            else if (indegree[i] != 1) {
                valid = false;
            }
        }

        if (!valid || count != 1)
            continue;

        bool visited[1005] = {false};
        queue<int> q;

        q.push(root);
        visited[root] = true;

        int total = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    total++;
                    q.push(v);
                }
            }
        }

        if (total == n) {
            cout << edges[remove].first << " "
                 << edges[remove].second << endl;
            return 0;
        }
    }

    return 0;
}

```

---

[View on CodeChef](https://www.codechef.com/problems/CUCPORGEDGE)