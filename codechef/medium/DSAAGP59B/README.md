# DSAAGP59B

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Frequency greater than k

Given a string S and an integer, K. Write a program to print characters with frequency greater than or equal to K in sorted order.

### Input Format
- The first line contains two integers: $N$ and $K$.
- The second line contains the string $S$.
### Output Format

Output the characters with frequency greater than or equal to $K$.

### Constraints
- $2 \leq length(S) \leq 10^5$
- $1 \leq K \leq 10^5$
- S can have both upper and lowercase letters
### Sample 1:
Input
Output

```
10 3
aaabbcdddd
```

```
ad
```

### Sample 2:
Input
Output

```
10 2
aaAbBcdDdD
```

```
Dad
```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-18T17:51:49.893Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    map<char, int> freq;
    for (char c : s) freq[c]++;

    for (auto p : freq) {
        if (p.second >= k) cout << p.first;
    }
}

```

---

[View on CodeChef](https://www.codechef.com/problems/DSAAGP59B)