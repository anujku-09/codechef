# CGOOE

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Count Good Elements

You are given an array $A$ containing $N$ integers.

An element $A_i$ is  **good**  if it is strictly smaller than each of the previous five elements, or all preceding elements if fewer than five exist.

For example, $A_3$ must be smaller than both $A_1$ and $A_2$, while $A_7$ must be smaller than $A_2, A_3, A_4, A_5,$ and $A_6$.

Find the number of  **good**  elements.

### Input Format
- The first line contains an integer $T$, the number of test cases.
- For each test case: The first line contains an integer $N$. The second line contains $N$ space-separated integers $A_1, A_2, \ldots, A_N$.
### Output Format

For each test case, print the number of days with a good price on a separate line.

### Constraints
- $1 \le T \le 100$
- $7 \le N \le 100$
- $350 \le A_i \le 750$
### Sample 1:
Input
Output

```
1
7
400 600 550 500 450 425 410
```

```
2
```

### Explanation:

The good elements are at positions $1$ and $7$.

Positions $2$ through $6$ are not good because each value is greater than $400$, which lies within its comparison range.

At position $7$, the value $410$ is smaller than the previous five values: $600,\ 550,\ 500,\ 450,\ 425$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-19T16:24:06.862Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i <n; i++){
            cin >> a[i];
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            bool good = true;
            for(int j = max(0, i - 5); j < i; j++){
                if(a[i] >= a[j]) {
                    good = false;
                    break;
                }
            }
            if(good){
                cnt++;
            }
        }
        cout << cnt << endl;
    }

}

```

---

[View on CodeChef](https://www.codechef.com/problems/CGOOE)