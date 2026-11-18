# CUCPROTMIN

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Rotated Shelf Smallest

The archive room at  **Ridgepoint**  keeps its boxes on one long shelf. The boxes were originally placed in order of their label, smallest to largest, but the shelf sits on a turntable and somebody has spun it: the run of labels has been  **rotated**  by some number of places, so the shelf now reads like the tail of the sorted order followed by its head.

For example, the sorted run $[0, 1, 2, 2, 2]$ spun by $3$ places reads $[2, 2, 2, 0, 1]$.

Labels are  **not**  unique — plenty of boxes carry the same label, which is exactly what makes the turning point hard to pin down.

### Task

For each shelf, print the  **smallest**  label on it.

### Important Requirements
- The shelf is a sorted run rotated by some number of places; a rotation of $0$ places (an ordinary sorted run) is allowed.
- Labels may repeat. When the label in the middle of the range ties with the label at its end, neither side can be ruled out on that comparison alone — narrow the range some other way rather than guessing.
- A shelf may hold a single box.
### Input Format

The first line contains a single integer $T$, the number of shelves.

Each shelf is given on two lines. The first contains a single integer $N$, the number of boxes. The second contains $N$ space-separated integers, the labels as they read along the shelf.

### Output Format

Print $T$ lines. The $i$-th line holds the smallest label on the $i$-th shelf.

### Constraints
- $1 \le T \le 100$
- $1 \le N \le 5000$
- $-5000 \le$ every label $\le 5000$
- Every shelf is a sorted run rotated by some number of places.
### Sample 1:
Input
Output

```
1
5
2 2 2 0 1

```

```
0

```

### Sample 2:
Input
Output

```
1
3
1 3 5

```

```
1

```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-18T09:50:03.421Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        cout << *min_element(a.begin(), a.end()) << "\n";
    }
}
```

---

[View on CodeChef](https://www.codechef.com/problems/CUCPROTMIN)