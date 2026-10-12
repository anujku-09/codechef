# CHEFODD

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Chef Odd

You want to partition the set $S = \{1, 2, \ldots, N\}$ into $K$ sets $S_1, S_2, \ldots, S_K$, such that $|S_i| \ge 2$, and the sum of elements in each $S_i$ is odd.

Is it possible to do so?

 **Note 1:**  Partitioning the set $S = \{1, 2, \ldots, N\}$ into $K$ sets $S_1, S_2, \ldots, S_K$ means that every element of $S$ should be in exactly one of the sets $S_1, S_2, \ldots, S_K$, and $S_i \subseteq S$, for all $1 \leq i \leq K$.

 **Note 2:**  $|A|$ denotes the number of elements in the set $A$.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- The first line and only line of each test case contains two space-separated integers, $N$ and $K$.
### Output Format

For each test case, output `YES` if you can partition the set satisfying the requirements. Otherwise, output `NO`.

You may print each character of `YES` and `NO` in uppercase or lowercase (for example, `yes`, `yEs`, `Yes` will be considered identical).

### Constraints
- $1 \leq T \leq 10^5$
- $2 \leq N \leq 10^{18}$
- $1 \leq K \leq 10^{18}$
### Sample 1:
Input
Output

```
2
5 2
14 5

```

```
NO
YES
```

### Explanation:

 **Test case $1$** : There is no way you can partition $\{1, 2, 3, 4, 5\}$ into $2$ subsets such that each has an odd sum and each subset contains at least $2$ integers.

 **Test case $2$** : One of the ways to partition is $\{1, 4, 6, 12\}, \{2, 5\}, \{3, 14\}, \{7, 10, 11, 13\}, \{9, 8\}$. The sum of elements in each subset is $23, 7, 17, 41, 17$, each of which is odd and each subset contains at least $2$ integers.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-12T17:56:49.867Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n, k;
    cin >> n >> k;
    if(n < 2 * k) {
        cout << "NO\n";
        return;
    }
    long long odds = (n + 1) / 2;
    if(odds >= k && (odds - k) % 2 == 0) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while(t--){
	    solve();
	}
	return 0;
}

```

---

[View on CodeChef](https://www.codechef.com/problems/CHEFODD)