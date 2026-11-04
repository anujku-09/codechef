# TELEPHN

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Telephone

$N$ friends are sitting around a round table, playing a game of Telephone. Friend $i$ starts with the number $A_i$.
The friends are numbered $1$ to $N$ in clockwise order, so friend $i$ sits between friends $i-1$ and $i+1$; friend $1$ sits between friends $N$ and $2$.

Every second, all the friends call out their numbers at the same time. Each friend hears only the two friends sitting next to them, forgets their own number, and takes the  **larger**  of the two numbers they heard.

Formally, every second, $A_i$ is replaced by $\max(A_{i-1}, A_{i+1})$, where indices are taken cyclically.
This happens for all $1 \le i \le N$  **simultaneously**.

Find the  **minimum**  number of seconds after which all the friends hold the same number, or report that this never happens.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of two lines of input. The first line of each test case contains a single integer $N$ — the number of friends. The second line contains $N$ space-separated integers $A_1, A_2, \ldots, A_N$ — the starting numbers of the friends.
### Output Format

For each test case, output on a new line the minimum number of seconds after which all the friends hold the same number, or $-1$ if this never happens.

### Constraints
- $1 \leq T \leq 10^5$
- $3 \leq N \leq 2 \cdot 10^5$
- $1 \leq A_i \leq 10^9$
- The sum of $N$ over all test cases does not exceed $2 \cdot 10^5$.
### Sample 1:
Input
Output

```
4
6
3 8 2 8 6 1
5
4 2 7 3 5
8
6 9 4 1 7 3 9 2
7
5 9 2 6 9 1 4

```

```
-1
4
3
4

```

### Explanation:

 **Test case 1:**  It can be verified that the numbers will never be all equal.

 **Test case 2:**  The numbers change as follows: $[4, 2, 7, 3, 5] \to [5, 7, 3, 7, 4] \to [7, 5, 7, 4, 7] \to [7, 7, 5, 7, 7] \to [7, 7, 7, 7, 7]$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-04T16:30:04.558Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	  int n; cin >> n;
	  vector<int> a(n);
	  int mx = 0;
	  for(int i = 0; i < n; i++) {
	    cin >> a[i];
	    mx = max(mx, a[i]);
	  }
	  vector<vector<int>> dist (n, vector<int(2, -1));
	  queue<pair<int, int>> q;
	  for(int i = 0; i< n; i++) {
	    if(a[i] == mx) {
	      dist[i][0] = 0;
	      q.push({i, 0});
	    }
	  }
	  while (!q.empty()) {
            int pos = q.front().first;
            int p = q.front().second;
            q.pop();

            int l = (pos - 1 + n) % n;
            int r = (pos + 1) % n;

            if (dist[l][1 - p] == -1) {
                dist[l][1 - p] = dist[pos][p] + 1;
                q.push({l, 1 - p});
            }

            if (dist[r][1 - p] == -1) {
                dist[r][1 - p] = dist[pos][p] + 1;
                q.push({r, 1 - p});
            }
        }

        int even = 0, odd = 0;
        bool e = true, o = true;

        for (int i = 0; i < n; i++) {
            if (dist[i][0] == -1) {
                e = false;
            } else {
                even = max(even, dist[i][0]);
            }

            if (dist[i][1] == -1) {
                o = false;
            } else {
                odd = max(odd, dist[i][1]);
            }
        }

        int ans = INT_MAX;

        if (e) ans = min(ans, even);
        if (o) ans = min(ans, odd);

        if (ans == INT_MAX) {
            cout << -1 << "\n";
        } else {
            cout << ans << "\n";
        }
    }

    return 0;
}
	}
}

```

---

[View on CodeChef](https://www.codechef.com/problems/TELEPHN)