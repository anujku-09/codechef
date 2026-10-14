# CUCPWINMED

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Seismograph Median Filter

The  **Ridgepoint seismograph**  writes down the ground displacement it measures once per tick. Tick $i$ recorded the value $level_i$, which is negative whenever the ground moved the other way.

Raw seismograph data is noisy, so the analysts never look at it directly — they smooth it with a  **median filter**. The filter walks a window of exactly $K$ consecutive ticks across the log, one tick at a time, and reports the median of the $K$ readings sitting inside the window.

The median of $K$ readings is the value in the middle once they are sorted. When $K$ is odd, that is a single reading. When $K$ is even, there are two readings in the middle and the median is their average, which may end in $.5$.

### Task

Report the median of every window of $K$ consecutive ticks, from the window that starts at the first tick through to the window that ends at the last one.

### Important Requirements
- The windows slide one tick at a time, so a log of $N$ ticks produces exactly $N - K + 1$ medians.
- Every window holds exactly $K$ readings — the shorter stretches at the ends are not reported.
- Repeated values each count separately: a window of $K$ readings always has $K$ values in it, duplicates included.
### Input Format

The first line contains two space-separated integers $N$ and $K$ — the number of ticks in the log and the size of the window.

The second line contains $N$ space-separated integers $level_1, level_2, \ldots, level_N$, the displacement recorded at each tick.

### Output Format

Print $N - K + 1$ lines. The $i$-th line holds the median of the window that starts at tick $i$, printed with  **exactly one digit after the decimal point**  (every median is either a whole number or ends in $.5$).

### Constraints
- $1 \le K \le N \le 10^5$
- $-10^9 \le level_i \le 10^9$
### Sample 1:
Input
Output

```
8 3
1 3 -1 -3 5 3 6 7

```

```
1.0
-1.0
-1.0
3.0
5.0
6.0

```

### Sample 2:
Input
Output

```
5 4
1 2 3 4 2

```

```
2.5
2.5

```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-14T12:49:51.785Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

multiset<long long> low, high;

void balance() {
    while (low.size() > high.size() + 1) {
        auto it = prev(low.end());
        high.insert(*it);
        low.erase(it);
    }
    while (low.size() < high.size()) {
        auto it = high.begin();
        low.insert(*it);
        high.erase(it);
    }
}

void add(long long val) {
    if (low.empty() || val <= *low.rbegin()) {
        low.insert(val);
    } else {
        high.insert(val);
    }
    balance();
}

void remove_val(long long val) {
    auto it = low.find(val);
    if (it != low.end()) {
        low.erase(it);
    } else {
        it = high.find(val);
        if (it != high.end()) {
            high.erase(it);
        }
    }
    balance();
}

double get_median(int k) {
    if (k % 2 != 0) {
        return (double)*low.rbegin();
    } else {
        return ((double)*low.rbegin() + (double)*high.begin()) / 2.0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < k; i++) {
        add(a[i]);
    }

    cout << fixed << setprecision(1);
    cout << get_median(k) << "\n";

    for (int i = k; i < n; i++) {
        add(a[i]);
        remove_val(a[i - k]);
        cout << get_median(k) << "\n";
    }

    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/CUCPWINMED)