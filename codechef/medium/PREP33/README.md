# PREP33

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Dynamic Programming - Longest Valid Parentheses

You are given a string $S$ consisting of only $($ and $)$.

Find the length of the  **longest**  substring of $S$ which is a  *valid parentheses*  string.

Note:

- A substring of a string is obtained by deleting some (possibly zero) characters from the beginning and some (possibly zero) characters from the end.
- A valid parentheses string is defined as: Empty string is valid. If $P$ is valid, $(P)$ is also valid. If $P$ and $Q$ are valid, $PQ$ is also valid.
### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- The first and only line of each test case consists of a string $S$, consisting of $($ and $)$ only.
### Output Format

For each test case, output on a new line, the length of the  **longest**  substring of $S$ which is a  *valid parentheses*  string.

### Constraints
- $1 \leq T \leq 2000$
- $1 \leq |S| \leq 10^5$
- $S$ contains $($ and $)$ only.
- The sum of $|S|$ over all test cases won't exceed $2\cdot 10^5$.
### Sample 1:
Input
Output

```
4
(()
)
)(())()
)((

```

```
2
0
6
0

```

### Explanation:

 **Test case $1$:**  The longest valid parentheses substring is $()$ having length $2$.

 **Test case $2$:**  There is no valid parentheses substring in the string.

 **Test case $3$:**  The longest valid parentheses substring is $(())()$ having length $6$.

 **Test case $4$:**  There is no valid parentheses substring in the string.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-22T14:31:31.335Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    
    vector<int> dp(n, 0);
    int mx_len = 0;
    
    for(int i = 0; i < n; i++) {
        if(s[i] == ')') {
            if(s[i - 1] == '(') {
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
            } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] =='(') {
                dp[i] = dp[i - 1] + 2 + ((i - dp[i - 1] >= 2) ? dp[i - dp[i- 1] - 2] : 0);
            }
            mx_len = max(mx_len, dp[i]);
        }
    }
    cout << mx_len << endl;
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

[View on CodeChef](https://www.codechef.com/problems/PREP33)