# CUCPPLUSONE

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Depot Gate Counter

The gate at the  **Ridgepoint depot**  counts everyone who walks through it on an old mechanical counter. The counter has a row of digit wheels, each showing a single digit from $0$ to $9$, and the row is read left to right as one large number. The leftmost wheel never shows a $0$ — the only exception is a counter that reads exactly $0$, which is a single wheel showing $0$.

One more person has just walked through the gate, so the counter has to advance by  **one**. The rightmost wheel steps up by one. A wheel that was already showing $9$ rolls over to $0$ and pushes the step onto the wheel to its left, which may in turn roll over, and so on. If every wheel rolls over, a brand new wheel showing $1$ opens up on the left, and the counter becomes one wheel longer.

### Task

Print the digits the counter shows after it advances by one.

### Important Requirements
- The counter may be far too long to fit in any built-in integer type, so work on the digits themselves.
- A roll-over can cascade through several wheels in a row.
- When every wheel rolls over, the answer is one digit longer than the input.
### Input Format

The first line contains a single integer $N$, the number of digit wheels on the counter.

The second line contains $N$ space-separated digits, the value on each wheel from left to right.

### Output Format

Print the digits the counter shows after advancing by one, space-separated on a single line, from left to right.

### Constraints
- $1 \le N \le 100$
- Every digit is between $0$ and $9$.
- The first digit is not $0$, unless the counter reads exactly $0$ on a single wheel.
### Sample 1:
Input
Output

```
3
1 2 3

```

```
1 2 4

```

### Sample 2:
Input
Output

```
4
4 3 2 1

```

```
4 3 2 2

```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-18T09:34:39.296Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];

    for (int i = n - 1; i >= 0; i--) {
        if (d[i] < 9) {
            d[i]++;
            for (int x : d) cout << x << " ";
            return 0;
        }
        d[i] = 0;
    }

    cout << 1 << " ";
    for (int x : d) cout << x << " ";
}
```

---

[View on CodeChef](https://www.codechef.com/problems/CUCPPLUSONE)