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
**Submitted:** 2026-10-14T12:48:46.407Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int longestStableRun(const string& s, int left, int right, int k) {
    if (right - left < k) return 0;

    int freq[26] = {0};
    for (int i = left; i < right; i++) {
        freq[s[i] - 'a']++;
    }

    for (int mid = left; mid < right; mid++) {
        if (freq[s[mid] - 'a'] > 0 && freq[s[mid] - 'a'] < k) {
            int next_mid = mid + 1;
            while (next_mid < right && freq[s[next_mid] - 'a'] < k) {
                next_mid++;
            }
            return max(longestStableRun(s, left, mid, k),
                       longestStableRun(s, next_mid, right, k));
        }
    }
    return right - left;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    string s;
    cin >> s;

    cout << longestStableRun(s, 0, n, k) << "\n";

    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/CUCPFREQRUN)