# CUCPFREQRUN

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Warehouse Stable Run

The scanner above the conveyor belt at the  **Northgate warehouse**  logs one letter for every item that rolls past it. The letter is the item's category code, a lowercase letter from `a` to `z`; two items with the same letter belong to the same category.

The audit team is looking for the longest  **stable run**  in the log. A run is a contiguous stretch of the log, and it counts as stable when  **every category that appears inside that stretch appears at least $K$ times inside it**. A category that never appears in the stretch does not matter at all — only the ones actually present have to clear the threshold.

For example, in the log `aaabb` with $K = 2$ the whole log is stable, because `a` appears $3$ times and `b` appears $2$ times. In the log `ababbc` with $K = 2$ the whole log is  **not**  stable, since `c` appears only once; the longest stable run is `ababb`, of length $5$.

### Task

Find the length of the longest stable run in the log.

### Important Requirements
- The run must be contiguous.
- Every category present in the run must appear at least $K$ times within that run, not in the whole log.
- If no stretch is stable, print $0$.
### Input Format

The first line contains two space-separated integers $N$ and $K$ — the number of scans in the log and the threshold each present category must reach.

The second line contains a string of exactly $N$ lowercase English letters, the category code logged for each scan.

### Output Format

Print a single integer: the length of the longest stable run, or $0$ if there is none.

### Constraints
- $1 \le N \le 10^4$
- $1 \le K \le 10^5$
- The log contains only lowercase English letters.
### Sample 1:
Input
Output

```
5 2
aaabb

```

```
5

```

### Sample 2:
Input
Output

```
6 2
ababbc

```

```
5

```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-17T11:12:07.084Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int solve(string s, int k) {
    if (s.size() < k) return 0;
    int f[26] = {0};
    for (char c : s) f[c - 'a']++;

    for (int i = 0; i < s.size(); i++) {
        if (f[s[i] - 'a'] < k) {
            int j = i + 1;
            while (j < s.size() && f[s[j] - 'a'] < k) j++;
            return max(solve(s.substr(0, i), k), solve(s.substr(j), k));
        }
    }
    return s.size();
}

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    cout << solve(s, k) << "\n";
}
```

---

[View on CodeChef](https://www.codechef.com/problems/CUCPFREQRUN)