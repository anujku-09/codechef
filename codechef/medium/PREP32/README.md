# PREP32

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Dynamic Programming - String Distance

Given two strings $A$ and $B$ consisting of lowercase english characters. Find the  **minimum**  number of operations required to convert $A$ to $B$.

You have the following operations permitted on $A$,

- Insert a character
- Delete a character
- Replace a character

For example,

- $A =$ codechef, now if you insert q at position $5$ then $A =$ codeqchef.
- $A =$ codechef, now if you delete position $6$ then $A =$ codecef.
- $A =$ codechef, now if you replace position $5$ with q then $A =$ codeqhef.
### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- The first line of each test case contains string $A$.
- The second line of each test case contains string $B$.
### Output Format

For each test case, output on a new line the minimum number of operations required to convert $A$ to $B$.

### Constraints
- $1 \leq T \leq 10$
- $1 \leq |A|, |B| \leq 10^5$
### Sample 1:
Input
Output

```
3
codechef
fochf
aa
alq
ab
ab

```

```
4
2
0
```

### Explanation:

 **Test case $1$** : $A =$ `codechef`. You can do following,

- Replace $A_1$ with f. So $A =$ fodechef.
- Delete $A_3$, $A_4$, $A_7$. So $A =$ fochf.

 **Test case $2$** : $A =$ `aa`. You can do following,

- Replace $A_2$ with q. So $A =$ aq.
- Insert l at $A_2$. So $A =$ alq.

 **Test case $3$** : Both strings same.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-22T14:36:27.642Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;
    
    int n = a.size();
    int m = b.size();
    
    vector<int> dp(m + 1);
    for(int j = 0; j <= m; j++) {
        dp[j] = j;
    }
    for(int i = 1; i <= n; i++) {
        int prev = dp[0];
        dp[0] = i;
        
        for(int j = 1; j<= m; j++) {
            int temp = dp[j];
            if(a[i - 1] == b[j - 1]) {
                dp[j] = prev;
            } else {
                dp[j] = 1 + min({dp[j], dp[j - 1], prev});
            }
            prev = temp;
        }
    }
    cout << dp[m] << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    solve();
	}
}

```

---

[View on CodeChef](https://www.codechef.com/problems/PREP32)