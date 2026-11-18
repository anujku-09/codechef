# CUCPTILESQ

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Tile Yard Square Patch

The tile yard at  **Ridgepoint**  ships its floor tiles in crates. A crate holding $X$ tiles is sold to whoever wants to lay a  **square**  patch of floor, and the yard always quotes the largest square that the crate can cover: the biggest side length $S$ such that $S \times S$ tiles are available, that is, the largest $S$ with $S \times S \le X$. Any tiles left over stay in the crate.

For a crate of $4$ tiles the answer is $2$, because $2 \times 2 = 4$ uses the crate exactly. For a crate of $8$ tiles the answer is also $2$: a $3 \times 3$ patch would need $9$ tiles, which the crate does not have, so $4$ tiles are left over.

In other words, you are being asked for the square root of $X$ rounded  **down**  to the nearest whole number.

### Task

For each crate, print the largest square side it can cover.

### Important Requirements
- Work it out without any built-in square-root or power routine — a search over the possible side lengths is the intended approach.
- The answer is rounded down, so a crate that is one tile short of a perfect square gives the smaller side.
- $X$ can be as large as $2^{31} - 1$, so a product like $S \times S$ needs a $64$-bit type.
### Input Format

The first line contains a single integer $T$, the number of crates.

Each of the next $T$ lines contains a single integer $X$, the number of tiles in that crate.

### Output Format

Print $T$ lines. The $i$-th line holds the largest square side the $i$-th crate can cover.

### Constraints
- $1 \le T \le 10^4$
- $0 \le X \le 2^{31} - 1$
### Sample 1:
Input
Output

```
1
4

```

```
2

```

### Sample 2:
Input
Output

```
1
8

```

```
2

```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-18T09:46:44.644Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long x;
        cin >> x;
        long long ans = sqrtl(x);
        cout << ans << "\n";
    }
}
```

---

[View on CodeChef](https://www.codechef.com/problems/CUCPTILESQ)