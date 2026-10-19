# VISA09

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Minimum Coins

You are given $N$ coin denominations $C_1, C_2, \ldots, C_N$ and a target sum $S$. You have an unlimited supply of coins of each denomination.

Find the minimum number of coins whose total value is exactly $S$. If no combination forms exactly $S$, print $-1$.

### Input Format
- The first line contains two integers $N$ and $S$: the number of coin denominations and the target sum.
- The second line contains $N$ space-separated integers $C_1, C_2, \ldots, C_N$: the coin denominations.
### Output Format

Print the minimum number of coins needed to form exactly $S$, or $-1$ if it is impossible.

### Constraints
- $1 \le N \le 10^2$
- $1 \le S \le 10^6$
- $N \times S \le 10^6$
- $1 \le C_i \le 10^6$
### Sample 1:
Input
Output

```
3 30
25 10 5
```

```
2

```

### Explanation:

Using $25 + 5 = 30$ requires $2$ coins. No available coin has value $30$, so fewer than $2$ coins cannot form the target.

### Sample 2:
Input
Output

```
4 19
9 6 5 1
```

```
3
```

### Explanation:

Using $9 + 9 + 1 = 19$ requires $3$ coins. No single coin or pair of available coins has a total value of $19$, so the minimum is $3$.

### Sample 3:
Input
Output

```
3 5
4 6 2
```

```
-1
```

### Explanation:

All available denominations are even, so every total formed using them is even. Therefore, the target sum $5$ cannot be formed.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-19T16:29:59.713Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    int c[n];
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector<int> dp(s + 1, 1000000);
    dp[0] = 0;
    for (int i = 1; i <= s; i++){
        for (int j = 0; j < n; j++){
            if (c[j] <= i) {
                dp[i] = min(dp[i],dp[i - c[j]] + 1);
            }
        }
    }
    if(dp[s] == 1000000) {
        cout << -1 << endl;
    } 
    else{
        cout << dp[s] << endl;
    }
}

```

---

[View on CodeChef](https://www.codechef.com/problems/VISA09)