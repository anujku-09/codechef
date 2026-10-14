# DIFFGCD

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Difference is GCD

You are given an integer $N$. Count the number of pairs $(X, Y)$ such that:

- $1 \le X < Y \le N$
- $gcd(X, Y) = |X - Y|$

where $gcd(A, B)$ denotes the greatest common divisor of both $A$ and $B$.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- The first and only line of each test case contains a single integer $N$.
### Output Format

For each test case, output the number of pairs $(X, Y)$ satisfying the conditions.

### Constraints
- $1 \le T \le 100$
- $2 \le N \le 10^9$
### Sample 1:
Input
Output

```
4
2
3
4
10

```

```
1
2
4
17
```

### Explanation:

 **Test Case 1:**  $(1, 2)$ is the only pair.

 **Test Case 2:**  $(1, 2)$ and $(2, 3)$ are valid pairs.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-14T16:27:12.376Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;

    long long max_d = n / 2;
    long long total = 0;

    long long left = 1;
    while (left <= max_d) {
        long long val = n / left;
        long long right = n / val;
        
        if (right > max_d) {
            right = max_d;
        }

        long long count = right - left + 1;
        total += count * (val - 1);

        left = right + 1;
    }

    cout << total << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

```

---

[View on CodeChef](https://www.codechef.com/problems/DIFFGCD)