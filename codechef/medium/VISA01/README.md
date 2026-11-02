# VISA01

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Longest Common Subsequence

You are given two strings $S$ and $R$. Find the length of their longest common subsequence.

A subsequence is obtained by deleting zero or more characters from a string without changing the relative order of the remaining characters. A common subsequence appears in both strings.

For example, `ace` is a common subsequence of `abcde` and `ace`, with length $3$.

### Input Format
- The first line contains an integer $T$, the number of test cases.
- Each test case contains two space-separated strings $S$ and $R$.
### Output Format

For each test case, print the length of the longest common subsequence on a separate line.

### Constraints
- $1 \le T \le 50$
- $1 \le |S|, |R| \le 10^2$
### Sample 1:
Input
Output

```
3
abcde ace
hello world
aa aa
```

```
3
1
2
```

### Explanation:
- Test case $1$: ace is a longest common subsequence, with length $3$.
- Test case $2$: o is a longest common subsequence, with length $1$. No common subsequence of length $2$ exists.
- Test case $3$: Both strings are aa, so their longest common subsequence has length $2$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-02T14:58:34.535Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
	  string s, r;
	  cin >> s >> r;
	  int n = s.length();
	  int m = r.length();
	  
	  int dp[105][105] = {0};
	  
	  for(int i = 1; i <= n; i++) {
	    for(int j = 1; j <= m; j++) {
	      if(s[i - 1] == r[j - 1]) {
	        dp[i][j] = 1 + dp[i - 1][j - 1];
	      } else {
	        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	      }
	    }
	  }
	  cout << dp[n][m] << endl;
	}
}

```

---

[View on CodeChef](https://www.codechef.com/problems/VISA01)