# REMELEM

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Remove Element

You are given an array $A = [A_1, A_2, \ldots, A_N]$ consisting of $N$ positive integers.

You are also given a constant $K$, using which you can perform the following operation on $A$:

- Choose two distinct indices $i$ and $j$ such that $A_i + A_j \le K$, and remove either $A_i$ or $A_j$ from $A$.

Is it possible to obtain an array consisting of only one element using several (possibly, zero) such operations?

### Input Format
- The first line of input contains a single integer $T$, denoting the number of test cases. The description of $T$ test cases follows.
- The first line of each test case contains two space-separated integers $N$ and $K$.
- The second line contains $N$ space-separated integers $A_1, A_2, \ldots, A_N$.
### Output Format

For each test case, print `"YES"` if it is possible to obtain an array consisting of only one element using the given operation, otherwise print `"NO"`.

You may print each character of the string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).

### Constraints
- $1 \leq T \leq 10^3$
- $1 \leq N \leq 10^5$
- $1 \leq A_i, K \leq 10^9$
- Sum of $N$ over all test cases does not exceed $2\cdot 10^5$
### Sample 1:
Input
Output

```
3
1 3
1
3 3
2 2 2
4 7
1 4 3 5

```

```
YES
NO
YES

```

### Explanation:

 **Test case $1$:**  The length of the array is already $1$.

 **Test case $2$:**  There is no way to delete an element from the given array.

 **Test case $3$:**  One possible sequence of operations is:

- Choose $i = 1, j = 4$ and remove $A_j = 5$. Hence the array becomes $[1, 4, 3]$.
- Choose $i = 2, j = 3$ and remove $A_i = 4$. Hence the array becomes $[1, 3]$.
- Choose $i = 1, j = 2$ and remove $A_i = 1$. Hence the array becomes $[3]$, which is of length $1$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-11T17:31:08.070Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << "YES\n";
        return;
    }
    sort(a.begin(), a.end());
    if (a[0] + a[n - 1] <= k){
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

```

---

[View on CodeChef](https://www.codechef.com/problems/REMELEM)